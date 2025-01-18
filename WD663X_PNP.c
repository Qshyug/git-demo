#include "asynctmr.h"
#include <utility.h>
#include <formatio.h>
#include <ansi_c.h>
#include <cvirte.h>		
#include <userint.h>
#include "WD663X_PNP.h"
#include "WD663X.h"
//每个通道发送间隔  CVI环境下只能动态分配16个Timer 
int (CVICALLBACK  TxChTimerCallbackPtr0) (int reserved, int timerId, int event, void *callbackData, int eventData1, int eventData2);
int (CVICALLBACK  TxChTimerCallbackPtr1) (int reserved, int timerId, int event, void *callbackData, int eventData1, int eventData2);
int (CVICALLBACK  TxChTimerCallbackPtr2) (int reserved, int timerId, int event, void *callbackData, int eventData1, int eventData2);
int (CVICALLBACK  TxChTimerCallbackPtr3) (int reserved, int timerId, int event, void *callbackData, int eventData1, int eventData2);
int (CVICALLBACK  TxChTimerCallbackPtr4) (int reserved, int timerId, int event, void *callbackData, int eventData1, int eventData2);
int (CVICALLBACK  TxChTimerCallbackPtr5) (int reserved, int timerId, int event, void *callbackData, int eventData1, int eventData2);
int (CVICALLBACK  TxChTimerCallbackPtr6) (int reserved, int timerId, int event, void *callbackData, int eventData1, int eventData2);
int (CVICALLBACK  TxChTimerCallbackPtr7) (int reserved, int timerId, int event, void *callbackData, int eventData1, int eventData2);
int	NewTimer[8];
void SetTimer(void);


ViUInt16	MaxChnum=24;//模块最大通道号    
static int PnlHandle,PnlChSet,PnlCh,PnlChTR,PnlSys,PnlFinDev,panelload,panelabout;//面板句柄
ViInt32 _stdcall demo_Data_watch_function(ViUInt32 cardnum,struct api_int_fifo_rs *sIntFIFO); // 中断
void SetChFunc(void);//更新通道设置界面
void monitorL(void);// 查询接收数据   
void monitorL2(void);// 查询接收数据2 测试用
ViUInt32	cardnum,hr;//模块ID，函数返回值 
int			chnum=0,alltxnum,allrxnum;  //全局通道号
ViUInt32    monitorLFlag=0;//查询接收标志 
int			RxMode=0;	   //接收方式
static API_INT_FIFO_RS sIntFIFO1;  
int 		SaveHandle=0; //保存文件句柄
ViUInt8 	DataCk[4096];
ViUInt8		DataTemp=0xff;
int SoftRuning=0;
static 	PCI_SOURCE	findPCI_SOURCE[10]={0};  
int  SaveFileStartAddr[24]={0};
int SaveFileEndAddr[24]={0};

char OpenCh[32]={0}; 
int ErFlag=0;
ViUInt8		preTempData[32]={0},preData[32]={0}; 
void ErFunction(ViUInt8* datablock,int datacount,int ch)
{
	   int a=0,i=0,j=0;
	   char msg[5000]={0};
	   char msg1[200]={0}; 
	   
	   if((datacount==0)||(datablock==NULL))  return ;
	   if(OpenCh[ch]==0) return ; //未打开通道不进行误码率测试
	   
	  // msg=(char*)malloc(sizeof(char)*datacount*4);
	   for (i=0;i<datacount;i++)
	   {
	   		preTempData[ch] = (datablock[i] & 0xffff) - preData[ch];	
			if(	preTempData[ch]!=1)  
			{
				sprintf(msg1, "xxxx--Ch:%ds predata: %.2x  curdata: %.2x \n", ch,preData[ch],datablock[i]);
				strcat(msg,msg1);
				InsertTextBoxLine (PnlHandle, PANEL_RXDATA, -1, msg); 
				sprintf(msg,"");
			} 
			if((datablock[i]&0xffff)==255)
				preData[ch]=-1;
			else
				preData[ch] =  datablock[i]&0xffff;
	  	}
	  	//free(msg);
}
typedef struct Global_ptr 
{ 
   ViUInt16		Rate;		 //通道波特率
   ViUInt16		Parity;		 //通道校验位
   ViUInt16		Bitcount;	 //通道数据位
   ViUInt16		Stopbit;	 //通道停止位
   ViUInt32		Mode;		 //通道模式
   ViUInt32		TxCount;	 //通道发送数据个数
   ViUInt8		*TxData;	 //通道发送数据
   int 			ResetData;	 //输入框读数标志
   int 			TxFile;		 //如果发送文件，发送完毕后停止
   int  		fileHandle;	 //通道发送文件句柄
   int			TxMode;		 //通道发送模式，软件自定义，Hex发送或Char发送
   int			TxPer;		 //通道发送周期
   
} Global_ptr;
Global_ptr *G_PTR;



int main (int argc, char *argv[])
{
	int i;
	if (InitCVIRTE (0, argv, 0) == 0)
		return -1;	/* out of memory */
	if ((PnlHandle = LoadPanel (0, "WD663X_PNP.uir", PANEL)) < 0)  //主界面
		return -1;
	if ((PnlFinDev = LoadPanel (PnlCh, "WD663X_PNP.uir", FINDDEVICE)) < 0) //模块选择界面
		return -1;
	if ((PnlSys = LoadPanel (PnlHandle, "WD663X_PNP.uir", PANEL_SYS)) < 0)   // 选中通道界面
		return -1;	
	if ((PnlCh = LoadPanel (PnlHandle, "WD663X_PNP.uir", PANEL_CH)) < 0)   // 选中通道界面
		return -1;
	if ((PnlChTR = LoadPanel (PnlHandle, "WD663X_PNP.uir", PANEL_TR)) < 0) //通道发送/接收使能界面
		return -1;  
	if ((PnlChSet = LoadPanel (PnlCh, "WD663X_PNP.uir", PANEL_CHS)) < 0) //通道设置界面
		return -1;
	if ((panelload = LoadPanel (0, "WD663X_PNP.uir", LOAD)) < 0)
		return -1;
	if ((panelabout = LoadPanel (0, "WD663X_PNP.uir", ABOUT)) < 0)
		return -1;
		
	DisplayPanel (panelload); 
	Delay(1);
	DiscardPanel(panelload) ;    
	
	//分配通道变量，初始化通道全局结构
	G_PTR = malloc(sizeof(Global_ptr)*MaxChnum);	
	memset(G_PTR,0,sizeof(Global_ptr)*MaxChnum);
	
	//初始化通道选择和通道打开界面，将支持的通道按钮释放
	for(i=0;i<MaxChnum;i++)
	{
		// 通道设置
		SetCtrlAttribute (PnlCh, PANEL_CH_CHSET0+i, ATTR_DIMMED,0);
		//发送通道使能
		SetCtrlAttribute (PnlChTR, PANEL_TR_TXCH0+i, ATTR_DIMMED, 0);
 
	}
	// 初始化发送Timer 并禁止Timer
	i=0;
	NewTimer[i] = NewAsyncTimer (1.0, -1, 1, TxChTimerCallbackPtr0, 0);
	SetAsyncTimerAttribute (NewTimer[i], ASYNC_ATTR_ENABLED, 0);
	i++ ;
	NewTimer[i] = NewAsyncTimer (1.0, -1, 1, TxChTimerCallbackPtr1, 0);
	SetAsyncTimerAttribute (NewTimer[i], ASYNC_ATTR_ENABLED, 0);
	i++ ;
	NewTimer[i] = NewAsyncTimer (1.0, -1, 1, TxChTimerCallbackPtr2, 0);
	SetAsyncTimerAttribute (NewTimer[i], ASYNC_ATTR_ENABLED, 0);
	i++ ;
	NewTimer[i] = NewAsyncTimer (1.0, -1, 1, TxChTimerCallbackPtr3, 0);
	SetAsyncTimerAttribute (NewTimer[i], ASYNC_ATTR_ENABLED, 0);
	i++ ;
	NewTimer[i] = NewAsyncTimer (1.0, -1, 1, TxChTimerCallbackPtr4, 0);
	SetAsyncTimerAttribute (NewTimer[i], ASYNC_ATTR_ENABLED, 0);
	i++ ;
	NewTimer[i] = NewAsyncTimer (1.0, -1, 1, TxChTimerCallbackPtr5, 0);
	SetAsyncTimerAttribute (NewTimer[i], ASYNC_ATTR_ENABLED, 0);
	i++ ;
	NewTimer[i] = NewAsyncTimer (1.0, -1, 1, TxChTimerCallbackPtr6, 0);
	SetAsyncTimerAttribute (NewTimer[i], ASYNC_ATTR_ENABLED, 0);
	i++ ;
	NewTimer[i] = NewAsyncTimer (1.0, -1, 1, TxChTimerCallbackPtr7, 0);
	SetAsyncTimerAttribute (NewTimer[i], ASYNC_ATTR_ENABLED, 0);
	memset(DataCk,0,sizeof(ViUInt8)*4096);
	
	for(i=0;i<24;i++)
	{
		SaveFileStartAddr[i]=i*1024;
		SaveFileEndAddr[i]=SaveFileStartAddr[i];
	}
	DisplayPanel (PnlHandle);
	RunUserInterface ();
	DiscardPanel (PnlHandle);
	return 0;
}

int CVICALLBACK OnConnect_Auto (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	int i;
	ViUInt32  SF_VER,HW_VER=0;
	char msg[50]={0},SoftVersion[50]={0},DevVersion[50]={0};
	switch (event)
		{
		case EVENT_COMMIT:
			// 自动连接，连接失败显示相应提示
			hr = WDSerial_AutoConnectFirst(&cardnum);
			if ((hr)||(!cardnum)) //函数返回值不等于0或者模块句柄等于0表示连接失败
			{
				MessagePopup("WD6632","Connect is failed!");
				SetCtrlVal(PnlHandle,PANEL_CONNECT_LED,0);
				SetCtrlAttribute(PnlHandle,PANEL_CONNECT_AUTO,ATTR_DIMMED,0);
				SetCtrlAttribute(PnlHandle,PANEL_CONNECT_BUS,ATTR_DIMMED,0);
				return 0;
			}																								  
			else
			{
			
				SetCtrlVal(PnlHandle,PANEL_CONNECT_LED,1);
				SetCtrlAttribute(PnlHandle,PANEL_CONNECT_AUTO,ATTR_DIMMED,1);
				SetCtrlAttribute(PnlHandle,PANEL_CONNECT_BUS,ATTR_DIMMED,1);
				//连接成功，初始化模块
				hr = WDSerial_Reset(cardnum); 
				hr=WDSerial_GetRevision(cardnum,&HW_VER,&SF_VER);
				
				sprintf(msg,"连接状态：已连接");
				SetCtrlVal(PnlHandle,PANEL_CON_TXT,msg);
				
				sprintf(DevVersion,"硬件版本号：%X-V%x.%.2x ",(HW_VER>>12)&0xF,(HW_VER>>8)&0xF, HW_VER&0xFF);   
				SetCtrlVal(PnlHandle, PANEL_DEV_VERSION,DevVersion);      
				
				sprintf(SoftVersion,"软件版本号：：%X-V%x.%.2x ",(SF_VER>>12)&0xF,(SF_VER>>8)&0xF, SF_VER&0xFF);  
				SetCtrlVal(PnlHandle, PANEL_SOFT_VERSION,SoftVersion);   
			}
			break;
		}
	return 0;
}

int CVICALLBACK OnConnect_Bus (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	ViUInt16	FindNum=0;
	char        msg[255];
	int i=0;
	switch (event)
		{
		case EVENT_COMMIT:
		
			hr=WDSerial_DeviceFind_PCI(
   				10,
   				findPCI_SOURCE,
   				&FindNum);	
			
	   		ClearListCtrl (PnlFinDev, FINDDEVICE_LISTBOX);
	   		InstallPopup(PnlFinDev);	
	   		for (i=0;i<FindNum;i++)
	   		{
				sprintf(msg, "PCI板卡-Bus Number: %d, Slot Number: %d, VendorId: %X ,  DeviceId: %X",findPCI_SOURCE[i].BusNumber,findPCI_SOURCE[i].SlotNumber,findPCI_SOURCE[i].VendorId,findPCI_SOURCE[i].DeviceId);
				InsertListItem(PnlFinDev, FINDDEVICE_LISTBOX, i, msg, 0);       			
			}
			break;
		}
	return 0;
}

int CVICALLBACK OnQuitSoft (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	int i;
	switch (event)
		{
		case EVENT_COMMIT:
			//退出前 注销中断
			if (cardnum)
			{
				hr = WDSerial_RegisterFunction(
								cardnum, 
								&sIntFIFO1,
								0);
				hr = WDSerial_Close(cardnum);
			}
			monitorLFlag=1;
			//退出前，释放每通道数据
			for(i=0;i<MaxChnum;i++)
			{
				free(G_PTR[i].TxData);
			}
			//退出前 关闭文件
			if(SaveHandle) 
			{
				CloseFile(SaveHandle); 
				SaveHandle=0;
			}
			//退出前，关闭Timer
			for(i=0;i<8;i++)
			{
				if(NewTimer[i])
					DiscardAsyncTimer (NewTimer[i]);	
			}
			//释放全局变量
			free(G_PTR);
			exit(0);
			break;
		}
	return 0;
}
int CVICALLBACK OnGoToSetCh (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
		{
		case EVENT_COMMIT:
			InstallPopup(PnlCh);
			break;
		}
	return 0;
}



int CVICALLBACK OnChSetClose (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
		{
		case EVENT_COMMIT:
			RemovePopup(PnlCh);                                                                     
			break;
		}
	return 0;
}
int CVICALLBACK OnCHSCLOSE (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
		{
		case EVENT_COMMIT:
			RemovePopup(0);            
			break;
		}
	return 0;
}
void SetChFunc(void)
{
		char msg[3073],msgx[6],msgtemp[2];
		int i;
		
		ViUInt16    EN;
		ViUInt16    Frame_Len;
		ViUInt16    Frame_Frq;
		ViUInt16    BuffB;
	
		if(!cardnum)
		{
			MessagePopup("WD6632","模块尚未初始化");
		}
		SetCtrlAttribute(PnlCh,PANEL_CH_CHSET0+chnum,ATTR_CMD_BUTTON_COLOR,0xff0064);
		SetCtrlAttribute(PnlCh,PANEL_CH_CHSET0+chnum,ATTR_LABEL_COLOR,0xff0064);
		//获取通道设置参数，并更新面板
		hr = WDSerial_GetCh(
					cardnum,  
					chnum,  
					&G_PTR[chnum].Rate,
					&G_PTR[chnum].Parity,
					&G_PTR[chnum].Bitcount,
					&G_PTR[chnum].Stopbit);
		//获取通道模式，并更新面板
		hr = WDSerial_GetChMode(
					cardnum,
					chnum,
					&G_PTR[chnum].Mode);
		memset(msgx,0,sizeof(char)*6);
		memset(msgtemp,0,sizeof(char)*2); 
		memset(msg,0,sizeof(char)*3073);
		//更新通道已经设置的发送数据
		if(G_PTR[chnum].TxMode==0)
		{
			for (i=0;i<G_PTR[chnum].TxCount;i++)
			{
				sprintf(msgx,"%.2x ",G_PTR[chnum].TxData[i]);
				strcat(msg,msgx);  	
			}
		}
		else
		{
			for (i=0;i<G_PTR[chnum].TxCount;i++)
			{
				memset(msgtemp,0,sizeof(char)*2);
				msgtemp[0]=G_PTR[chnum].TxData[i];
				strcat(msg,msgtemp);
			}
		}  

		//更新通道功能系数	
		SetCtrlVal(PnlChSet,PANEL_CHS_RATE,G_PTR[chnum].Rate);
		SetCtrlVal(PnlChSet,PANEL_CHS_PARITY,G_PTR[chnum].Parity); 
		SetCtrlVal(PnlChSet,PANEL_CHS_BITCOUNT,G_PTR[chnum].Bitcount); 
		SetCtrlVal(PnlChSet,PANEL_CHS_STOPBIT,G_PTR[chnum].Stopbit);
		SetCtrlVal(PnlChSet,PANEL_CHS_HEXTX,!G_PTR[chnum].TxMode);
		SetCtrlVal(PnlChSet,PANEL_CHS_CHARTX,G_PTR[chnum].TxMode);
		OnHEXTX (PnlChSet,PANEL_CHS_CHARTX,EVENT_COMMIT,0,0,0) ;
		
		SetCtrlVal(PnlChSet, PANEL_CHS_TXPER, G_PTR[chnum].TxPer);
		
		
		//更新通道模式
		SetCtrlVal(PnlChSet,PANEL_CHS_MODE,G_PTR[chnum].Mode); 
		//更新通道发送数据
		ResetTextBox(PnlChSet,PANEL_CHS_TXDATA,""); 
		SetCtrlVal(PnlChSet,PANEL_CHS_TXDATA,msg);  
		//更新界面标题
		sprintf(msg,"通道%d设置",chnum);
		SetPanelAttribute(PnlChSet,ATTR_TITLE,msg);
		
	
			WDSerial_GetConfigTxFrame(
			   	cardnum,  // (i) base address of memory area
		 	  	chnum,  // (i) base address of memory area
		  	 	&EN,  // (i) base address of memory area
		  	 	&Frame_Len,  // (i) base address of memory area
		  	 	&Frame_Frq,
		 	  	&BuffB);		
		if(chnum<=7&&chnum>=0)  
		{
						
			SetCtrlAttribute(PnlChSet,PANEL_CHS_BINARYSWITCH_2,ATTR_DIMMED,0);
			SetCtrlAttribute(PnlChSet,PANEL_CHS_DATANUM_2,ATTR_DIMMED,0);
			SetCtrlAttribute(PnlChSet,PANEL_CHS_DATANUM_3,ATTR_DIMMED,0);
			SetCtrlAttribute(PnlChSet,PANEL_CHS_TEXTMSG ,ATTR_DIMMED,0);
			SetCtrlAttribute(PnlChSet,PANEL_CHS_DATANUM_4,ATTR_DIMMED,0);  
			SetCtrlAttribute(PnlChSet,PANEL_CHS_TEXTMSG_2,ATTR_DIMMED,0); 
		
			SetCtrlVal(PnlChSet,PANEL_CHS_BINARYSWITCH_2,EN);
			SetCtrlVal(PnlChSet,PANEL_CHS_DATANUM_2,Frame_Frq);	
			SetCtrlVal(PnlChSet,PANEL_CHS_DATANUM_3,Frame_Len);	

		}
		else  if(chnum >= 8)
		{
			SetCtrlAttribute(PnlChSet,PANEL_CHS_BINARYSWITCH_2,ATTR_DIMMED,1);
			SetCtrlAttribute(PnlChSet,PANEL_CHS_DATANUM_2,ATTR_DIMMED,1);
			SetCtrlAttribute(PnlChSet,PANEL_CHS_DATANUM_3,ATTR_DIMMED,1);
			SetCtrlAttribute(PnlChSet,PANEL_CHS_TEXTMSG ,ATTR_DIMMED,1);
			SetCtrlAttribute(PnlChSet,PANEL_CHS_DATANUM_4,ATTR_DIMMED,1);
			SetCtrlAttribute(PnlChSet,PANEL_CHS_TEXTMSG_2,ATTR_DIMMED,1);
		}
		InstallPopup(PnlChSet); 
}
int CVICALLBACK OnCHSET0 (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
		{
		case EVENT_COMMIT:
			chnum=0;
			SetChFunc();  
			break;
		}
	return 0;
}


int CVICALLBACK OnCHSET1 (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
		{
		case EVENT_COMMIT:
			chnum=1;
			SetChFunc();  
			break;
		}
	return 0;
}

int CVICALLBACK OnCHSET2 (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
		{
		case EVENT_COMMIT:
			chnum=2;
			SetChFunc();  
			break;
		}
	return 0;
}

int CVICALLBACK OnCHSET3 (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
		{
		case EVENT_COMMIT:
			chnum=3;
			SetChFunc();  
			break;
		}
	return 0;
}

int CVICALLBACK OnCHSET4 (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
		{
		case EVENT_COMMIT:
			chnum=4;
			SetChFunc();  
			break;
		}
	return 0;
}

int CVICALLBACK OnCHSET5 (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
		{
		case EVENT_COMMIT:
			chnum=5;
			SetChFunc();  
			break;
		}
	return 0;
}
int CVICALLBACK OnCHSET6 (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
		{
		case EVENT_COMMIT:
			chnum=6;
			SetChFunc();  
			break;
		}
	return 0;
}

int CVICALLBACK OnCHSET7 (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
		{
		case EVENT_COMMIT:
			chnum=7;
			SetChFunc();  
			break;
		}
	return 0;
}

int CVICALLBACK OnCHSET8 (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
		{
		case EVENT_COMMIT:
			chnum=8;
			SetChFunc();  
			break;
		}
	return 0;
}

int CVICALLBACK OnCHSET9 (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
		{
		case EVENT_COMMIT:
			chnum=9;
			SetChFunc();  
			break;
		}
	return 0;
}

int CVICALLBACK OnCHSET10 (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
		{
		case EVENT_COMMIT:
			chnum=10;
			SetChFunc();  
			break;
		}
	return 0;
}
int CVICALLBACK OnCHSET11 (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
		{
		case EVENT_COMMIT:
			chnum=11;
			SetChFunc();  
			break;
		}
	return 0;
}

int CVICALLBACK OnCHSET12 (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
		{
		case EVENT_COMMIT:
			chnum=12;
			SetChFunc();  
			break;
		}
	return 0;
}

int CVICALLBACK OnCHSET13 (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
		{
		case EVENT_COMMIT:
			chnum=13;
			SetChFunc();  
			break;
		}
	return 0;
}

int CVICALLBACK OnCHSET14 (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
		{
		case EVENT_COMMIT:
			chnum=14;
			SetChFunc();  
			break;
		}
	return 0;
}

int CVICALLBACK OnCHSET15 (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
		{
		case EVENT_COMMIT:
			chnum=15;
			SetChFunc();  
			break;
		}
	return 0;
}
int CVICALLBACK OnCHSET16 (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
		{
		case EVENT_COMMIT:
			chnum=16;
			SetChFunc();  
			break;
		}
	return 0;
}

int CVICALLBACK OnCHSET17 (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
		{
		case EVENT_COMMIT:
			chnum=17;
			SetChFunc();  
			break;
		}
	return 0;
}

int CVICALLBACK OnCHSET18 (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
		{
		case EVENT_COMMIT:
			chnum=18;
			SetChFunc();  
			break;
		}
	return 0;
}
int CVICALLBACK OnCHSET19 (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
		{
		case EVENT_COMMIT:
			chnum=19;
			SetChFunc();  
			break;
		}
	return 0;
}

int CVICALLBACK OnCHSET20 (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
		{
		case EVENT_COMMIT:
			chnum=20;
			SetChFunc();  
			break;
		}
	return 0;
}

int CVICALLBACK OnCHSET21 (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
		{
		case EVENT_COMMIT:
			chnum=21;
			SetChFunc();  
			break;
		}
	return 0;
}

int CVICALLBACK OnCHSET22 (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
		{
		case EVENT_COMMIT:
			chnum=22;
			SetChFunc();  
			break;
		}
	return 0;
}

int CVICALLBACK OnCHSET23 (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
		{
		case EVENT_COMMIT:
			chnum=23;
			SetChFunc();  
			break;
		}
	return 0;
}

int CVICALLBACK OnSetCh (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	char *msg,msg1[3];
	int i,NumSend=0;
	switch (event)
		{
		case EVENT_COMMIT:
			
			GetCtrlVal(PnlChSet,PANEL_CHS_RATE,&G_PTR[chnum].Rate);	
			GetCtrlVal(PnlChSet,PANEL_CHS_PARITY,&G_PTR[chnum].Parity);	
			GetCtrlVal(PnlChSet,PANEL_CHS_BITCOUNT,&G_PTR[chnum].Bitcount);	
			GetCtrlVal(PnlChSet,PANEL_CHS_STOPBIT,&G_PTR[chnum].Stopbit);
			
			GetCtrlVal(PnlChSet, PANEL_CHS_TXPER,&G_PTR[chnum].TxPer);
			
			GetCtrlVal(PnlChSet,PANEL_CHS_MODE,&G_PTR[chnum].Mode);
			
			
			//设置通道参数
			hr = WDSerial_SetCh(
						cardnum,  // (i) base address of memory area
						chnum,  // (i) base address of memory area
						G_PTR[chnum].Rate,
						G_PTR[chnum].Parity,
						G_PTR[chnum].Bitcount,
						G_PTR[chnum].Stopbit);
			//设置通道模式
			hr = WDSerial_SetChMode(
						cardnum,
						chnum,
						G_PTR[chnum].Mode);
			if(G_PTR[chnum].ResetData==1)
			{
				GetCtrlAttribute (PnlChSet, PANEL_CHS_TXDATA, ATTR_STRING_TEXT_LENGTH,&NumSend);
				msg = malloc(sizeof(char)*NumSend+1);
				memset(msg,0,sizeof(char)*NumSend+1);
				memset(msg1,0,sizeof(char)*3);
				GetCtrlVal(PnlChSet,PANEL_CHS_TXDATA,msg);
			
				if (strlen(msg)==0)
					G_PTR[chnum].TxCount=0;
				G_PTR[chnum].TxCount = strlen(msg);	
				G_PTR[chnum].TxData=malloc(sizeof(ViUInt8)*G_PTR[chnum].TxCount);
				NumSend=0;
				//加载通道数据			
				if (G_PTR[chnum].TxMode==0)			 //Hex发送
				{
					for (i=0;i<(strlen(msg));i++)
					{
						if ((i%3)==0)
							msg1[0]=msg[i];
						else if((i%3)==1)
						{
							msg1[1]=msg[i];
							G_PTR[chnum].TxData[NumSend]= strtol(msg1,NULL,16);
							NumSend++;
						}
					}
				}
				else if ((G_PTR[chnum].TxMode==1))	  // char发送
				{
					for (i=0;i<(strlen(msg));i++)
					{
						msg1[0]=msg[i];
						G_PTR[chnum].TxData[NumSend]=msg1[0]; //strtoul(msg1,NULL,Hex);
						NumSend++;
						sprintf(msg1,"");
					}
				}
				G_PTR[chnum].TxCount=NumSend;  
			}
			
			
			{
				ViUInt16 LOOPEN=0;
				ViUInt16 Freq=0;
				ViUInt8  start_data=0;
				ViUInt16  length_data=0;
				
				ViUInt8	  *pData=NULL;
				int i=0;
				
				
				GetCtrlVal(PnlChSet,PANEL_CHS_BINARYSWITCH_2,&LOOPEN);
				GetCtrlVal(PnlChSet,PANEL_CHS_DATANUM_2,&Freq);	
			
				GetCtrlVal(PnlChSet,PANEL_CHS_DATANUM_4,&start_data);
				GetCtrlVal(PnlChSet,PANEL_CHS_DATANUM_3,&length_data);				
			
			
			
				WDSerial_ConfigTxFrame(
				   cardnum,  // (i) base address of memory area
				   chnum,  // (i) base address of memory area
				   LOOPEN,  // (i) base address of memory area
				   length_data,  // (i) base address of memory area
				   Freq,
				   0);
			   

				pData=malloc(length_data);
				for  (i=0;i<length_data;i++)
					pData[i]=start_data+i;	
				
				WDSerial_UpdataFrameData(
				   cardnum,  // (i) base address of memory area
				   chnum,  // (i) base address of memory area
				   0,  // (i) base address of memory area
				   pData,  // (i) base address of memory area
				   length_data);
				   
				 free(pData);
			
			
			}
			
			
			RemovePopup(0); 
			break;
		}
	return 0;
}

int CVICALLBACK OnAddTxData (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	int a=1,BegData=0,Dtanum=0,i=0;
	char *msg,msgtemp[6];
	
	switch (event)
		{
		case EVENT_COMMIT:
			GetCtrlVal(PnlChSet,PANEL_CHS_BEGDATA,&BegData);
			GetCtrlVal(PnlChSet,PANEL_CHS_DATANUM,&Dtanum);
			G_PTR[chnum].TxCount = Dtanum;
			
			msg=malloc(sizeof(char)*Dtanum*4);
			memset(msg,0,sizeof(char)*Dtanum*4);
			memset(msgtemp,0,sizeof(char)*6);
			G_PTR[chnum].TxData = malloc(sizeof(ViUInt8)*G_PTR[chnum].TxCount);
			
			ResetTextBox(PnlChSet,PANEL_CHS_TXDATA,"");   
			for(i=0;i< G_PTR[chnum].TxCount;i++)
			{
				G_PTR[chnum].TxData[i]=(BegData+i)&0xff;  
				sprintf(msgtemp,"%.2x ",G_PTR[chnum].TxData[i]);
				strcat(msg,msgtemp);
				if(a % 256 == 0)
				{
					InsertTextBoxLine (PnlChSet,PANEL_CHS_TXDATA, -1, msg);
					sprintf(msg,"");
				}
				a++;
			}
			if(strlen(msg) > 0)
				InsertTextBoxLine (PnlChSet,PANEL_CHS_TXDATA, -1, msg);             
			/*
			if(G_PTR[chnum].TxMode!=0)
			{
				ResetTextBox(PnlChSet,PANEL_CHS_TXDATA,""); 
				SetCtrlVal(PnlChSet,PANEL_CHS_TXDATA,msg);
			} 
			for (i=0;i<G_PTR[chnum].TxCount;i++)
			{
				G_PTR[chnum].TxData[i]=(BegData+i)&0xff;
			}
			*/
	
			
			break;
		}
	return 0;
}

int CVICALLBACK OnADDTXDATA2 (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	char msg[1000],msg1[3];
	int i,NumSend=0;			
	switch (event)
		{
		case EVENT_COMMIT:
			memset(msg,0,sizeof(char)*1000);
			memset(msg1,0,sizeof(char)*3);
			G_PTR[chnum].TxData = malloc(sizeof(ViUInt8)*26);
			if (G_PTR[chnum].TxMode==0)			 //Hex发送
			{
				sprintf(msg,"00 11 22 33 44 55 66 77 88 99 aa bb cc dd ee ff 1f 2f 3f 4f 5f 6f 7f 8f f0");
				for (i=0;i<(strlen(msg));i++)
				{
					if ((i%3)==0)
						msg1[0]=msg[i];
					else if((i%3)==1)
					{
						msg1[1]=msg[i];
						G_PTR[chnum].TxData[NumSend]= strtol(msg1,NULL,16);
						NumSend++;
					}
					else
					sprintf(msg1,"");
				}
			}
			else if ((G_PTR[chnum].TxMode==1))	  // char发送
			{
				sprintf(msg,"Welcome to YS Serial ! ");
				for (i=0;i<(strlen(msg));i++)
				{
					msg1[0]=msg[i];
					G_PTR[chnum].TxData[NumSend]=msg1[0]; //strtoul(msg1,NULL,Hex);
					NumSend++;
					sprintf(msg1,"");
				}
			}
			G_PTR[chnum].TxCount=NumSend;  
			ResetTextBox(PnlChSet,PANEL_CHS_TXDATA,""); 
			SetCtrlVal(PnlChSet,PANEL_CHS_TXDATA,msg);
			break;
		}
	return 0;
}
int CVICALLBACK OnAddDataFile (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{   
	char  pathName[500];
	
	int length,i,count,k;
	char *databuf,msg1[3];
	int filetype;
	char *msg;
	switch (event)
		{
		case EVENT_COMMIT:
			GetCtrlVal(PnlChSet,PANEL_CHS_BINARYSWITCH,&filetype); 
			G_PTR[chnum].TxFile=1;
			if (filetype==0)//文本
			{
				//文件提取发送数据
				GetDir (pathName);
				
				if (FileSelectPopup ("", ".TxData", "*.*", "", VAL_LOAD_BUTTON, 0, 0, 1, 0, pathName) >0)
				{
					if (strlen(pathName))
						G_PTR[chnum].fileHandle = OpenFile (pathName, VAL_READ_ONLY, VAL_OPEN_AS_IS,VAL_BINARY);

					if(G_PTR[chnum].fileHandle<0) 
						MessagePopup("Err","提取文件错误!");
					else
					{
					
						GetFileInfo (pathName, &length);
						G_PTR[chnum].TxCount = length;
				   
						databuf = malloc(sizeof(char)*length+1);
						msg = malloc(sizeof(char)*length*2+1);
						memset(databuf,0,sizeof(char)*length+1);

						ReadFile(G_PTR[chnum].fileHandle, databuf, sizeof(char)*length);
						ResetTextBox(PnlChSet,PANEL_CHS_TXDATA,""); 
						SetCtrlVal(PnlChSet,PANEL_CHS_TXDATA,databuf);
						G_PTR[chnum].TxCount = strlen(databuf);
						G_PTR[chnum].TxData = malloc(sizeof(ViUInt8)*G_PTR[chnum].TxCount) ;
						for (i=0;i<(strlen(databuf));i++)
						{
							msg1[0]=databuf[i];
							G_PTR[chnum].TxData[i]=msg1[0]; //strtoul(msg1,NULL,Hex);
							sprintf(msg1,"");
						}	   
						CloseFile(G_PTR[chnum].fileHandle);
						G_PTR[chnum].fileHandle = 0;
						free(databuf);
						free(msg); 
					}
				}
			}
			else //二进制文件
			{
				//文件提取发送数据
				GetDir (pathName);
				
				if (FileSelectPopup ("", ".TxData", "*.*", "", VAL_LOAD_BUTTON, 0, 0, 1, 0, pathName) >0)
				{
					if (strlen(pathName))
						G_PTR[chnum].fileHandle = OpenFile (pathName, VAL_READ_WRITE, VAL_OPEN_AS_IS, VAL_ASCII);

					if(G_PTR[chnum].fileHandle<0) 
						MessagePopup("Err","提取文件错误!");
					else
					{
					
						GetFileInfo (pathName, &length);
						G_PTR[chnum].TxCount = length;  
						
						databuf = malloc(sizeof(char)*length+1);
						msg = malloc(sizeof(char)*length*2+1); 
						memset(databuf,0,sizeof(char)*length+1);

						ReadFile(G_PTR[chnum].fileHandle, databuf, sizeof(char)*length);
						ResetTextBox(PnlChSet,PANEL_CHS_TXDATA,""); 
						SetCtrlVal(PnlChSet,PANEL_CHS_TXDATA,databuf);
						G_PTR[chnum].TxData = malloc(sizeof(ViUInt8)*G_PTR[chnum].TxCount) ;
						for (i=0;i<G_PTR[chnum].TxCount;i++)
						{
							msg1[0]=databuf[i];
							G_PTR[chnum].TxData[i]=msg1[0]; //strtoul(msg1,NULL,Hex);
							sprintf(msg1,"");
						}
						sprintf(msg,"");
						for (i=0;i<G_PTR[chnum].TxCount;i++)
						{
							sprintf(msg1,"%.2x",G_PTR[chnum].TxData[i]);
							strcat(msg,msg1) ;
						}
						ResetTextBox(PnlChSet,PANEL_CHS_TXDATA,""); 
						SetCtrlVal(PnlChSet,PANEL_CHS_TXDATA,msg);
						CloseFile(G_PTR[chnum].fileHandle);
						G_PTR[chnum].fileHandle = 0;
						free(databuf);
						free(msg); 
					}
				}
			}
			//从文件加载 都是字符串发送
			SetCtrlVal(PnlChSet,PANEL_CHS_HEXTX,0);
			OnHEXTX ( PnlChSet,PANEL_CHS_HEXTX, EVENT_COMMIT, 0, 0, 0) ;
			
			break;
		}
	return 0;
}

int CVICALLBACK OnGOTOOPENCH (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
		{
		case EVENT_COMMIT:
			InstallPopup(PnlChTR);
			break;
		}
	return 0;
}

int CVICALLBACK OnChTxClose (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	int flag,i;
	int Leng;
	int CHEN=0;
	
	switch (event)
		{
		case EVENT_COMMIT:
			

			GetCtrlVal(PnlSys,PANEL_SYS_RXMODE,&RxMode);
			GetCtrlVal(PnlSys,PANEL_SYS_LENGTH,&Leng);
			//当接收通道允许，为每个接收通道设置不同的中断条件
			
			for(i=0;i<MaxChnum;i++) 
			{
			  GetCtrlVal(PnlChTR,PANEL_TR_TXCH0+i,&CHEN);  
			  OpenCh[i]=CHEN;
			  WDSerial_ChannelEn(
					cardnum,
					i,
					CHEN);
			}
			
			
			if (RxMode==1)  
			{
				for(i=0;i<MaxChnum;i++) 
				{
					hr = WDSerial_SetChInterupt(
								cardnum,  
								i,  //通道号
								1,	//字长中断使能
								0,  //字符中断使能
								Leng, //字长长度
								0x5a); //字符
				}			 
			} 
			SetTimer();
			RemovePopup(PnlChTR);
			break;
		}
	return 0;
}


int  StartModule = 0;

int CVICALLBACK OnTX_STARTSTOP (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	int flag,i;
	unsigned char  pData[10]={0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,0xaa};
	
	switch (event)
		{
		case EVENT_COMMIT:
			GetCtrlVal(PnlHandle, control, &flag);
			if(!cardnum)
			{
				MessagePopup("WD6632","模块尚未初始化");
			}
			
			if(flag)
			{
			
				if(StartModule == 0)
					hr = WDSerial_StartStop(cardnum,flag,0); 
				StartModule++;           
			}
			else
			{
				if(StartModule == 1)
					hr = WDSerial_StartStop(cardnum,flag,0); 
				StartModule--;
				if(StartModule < 0)
					StartModule = 0;
			}
			SetTimer();      
			break;
		}
	return 0;
}
int CVICALLBACK OnRX_STARTSTOP (int panel, int control, int event,
								void *callbackData, int eventData1, int eventData2)
{
	int flag,i;
	unsigned char  pData[10]={0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,0xaa};
	
	switch (event)
		{
		case EVENT_COMMIT:
			GetCtrlVal(PnlHandle, control, &flag);
			if(!cardnum)
			{
				MessagePopup("WD6632","模块尚未初始化");
			}
			
			if(flag)
			{
			
				if(StartModule == 0)
					hr = WDSerial_StartStop(cardnum,flag,0); 
				StartModule++;  
				if (RxMode==0)
				{
					monitorLFlag=0;
					monitorL();
				}
				else
					monitorLFlag=1; 
			}
			else
			{
				      
				if(StartModule == 1)
					hr = WDSerial_StartStop(cardnum,flag,0); 
				StartModule--;
				if(StartModule < 0)
					StartModule = 0;
				monitorLFlag=1;  
			}
			SoftRuning = flag;
			break;
		}
	return 0;
}

//查询接收
void monitorL(void)
{  
	ViUInt8	  	datablock[1024];
	ViUInt32  	rxcount,i=0;
	char      	msg[1024],msgx[2049],msgtemp[2]; 
	int 		hr=0;
	int 		k=0,ch; 
	int         SHowData=0;
	int 		receivemask[24];
	int saveflag;
	int showflag;
	
	ViUInt8		preTempData=0,preData=0;
	char		strMsg[255];
	int temcnt=0;
	char temdata1111[1024]={0};
	int fileptr[24]={0};
	if(cardnum == 0) return ;
	while(!monitorLFlag)
	{ 
		GetCtrlVal(PnlHandle,PANEL_BINARYSWITCH,&showflag);
		GetCtrlVal(PnlHandle,PANEL_SAVEFILE,&saveflag); 
		GetCtrlVal(PnlHandle,PANEL_CHECKBOX_2, &SHowData);
		//查询所有通道上的数据
		for (ch=0;ch<MaxChnum;ch++)  
		{
			memset(msg,0,sizeof(char)*1024);
			memset(msgx,0,sizeof(char)*2049);
			//当通道允许接收时，查询	

				hr=WDSerial_ReceiveBlockFIFO(
					   cardnum,  // (i) base address of memory area
					   ch,  // (i) base address of memory area
					   1024,  // (i) base address of memory area
					   datablock,
					   &rxcount);
				if (rxcount > 0)//该通道成功接收数据
				{ 		   
					if ((saveflag)&&(SaveHandle))//保存接收文件    
					{
						fileptr[ch]=SaveFileEndAddr[ch];
						SaveFileEndAddr[ch] += rxcount;
						if(SaveFileEndAddr[ch]>SaveFileStartAddr[ch+1])
						{
							temcnt=SaveFileEndAddr[ch]-SaveFileStartAddr[ch+1];
							SetFilePtr(SaveHandle,fileptr[ch],0);
						    WriteFile(SaveHandle,(char*)(datablock),rxcount-temcnt); 
						    memcpy(&datablock[rxcount-temcnt],temdata1111,temcnt);
						    fileptr[ch]= SaveFileStartAddr[ch];
						    SetFilePtr(SaveHandle,fileptr[ch],0);   
							WriteFile(SaveHandle,temdata1111,temcnt);																														
							SaveFileEndAddr[ch]=temcnt;
						}
						else 
						{
							SetFilePtr(SaveHandle,fileptr[ch],0) ;  
							WriteFile(SaveHandle,(char*)(datablock),rxcount);
						}
				   	}	   
					   
					if (showflag==1)//Hex 发送/接收
					{				
				
						   	allrxnum +=rxcount;
					   		SetCtrlVal (PnlHandle, PANEL_RXNUM, rxcount);
					   		SetCtrlVal (PnlHandle, PANEL_ALLRXNUM, allrxnum);
				   			if(ErFlag==0)
				   			{
								if(SHowData == 1)
								{
									sprintf(msgx,"\nch%.2d ",ch);   
									for (i=0;i<rxcount;i++)
									{   
										sprintf(msg,"%.2x ",datablock[i]);
										strcat(msgx,msg);
										if(strlen(msgx) >= 100)
										{
											InsertTextBoxLine (PnlHandle,PANEL_RXDATA, -1, msgx);
											sprintf(msgx,"");
										}
									}  
									if(strlen(msgx) >= 2)
									{
										InsertTextBoxLine (PnlHandle,PANEL_RXDATA, -1, msgx);
										sprintf(msgx,"");
									}
								}
							}
							else
							{
								ErFunction(datablock,rxcount,ch);
							}
					
					}// end hex 
					else if (showflag==0)// CHAR 发送/接收
					{				
					
							memset(msgtemp,0,sizeof(char)*2);
							memset(msgx,0,sizeof(msgx));
							sprintf(msgx,"");
						   	sprintf(msgx,"\nch%.2d ",ch); 
						   	allrxnum +=rxcount;
					   		SetCtrlVal (PnlHandle, PANEL_RXNUM, rxcount);
					   		SetCtrlVal (PnlHandle, PANEL_ALLRXNUM, allrxnum);
							if(SHowData == 1)
							{
								for (i=0;i<rxcount;i++)
								{
									msgtemp[0]=datablock[i]; 
									strcat(msgx,msgtemp); 
									if(strlen(msgx) >= 100)
									{
										InsertTextBoxLine (PnlHandle,PANEL_RXDATA, -1, msgx);
										sprintf(msgx,"");
									}
								}  
								if(strlen(msgx) >= 2)
								{
									InsertTextBoxLine (PnlHandle,PANEL_RXDATA, -1, msgx);
									sprintf(msgx,"");
								}
							}
					}
			
				}
			}
			ProcessSystemEvents ();  
		}
		
}			 
//中断方式读数据
ViInt32 _stdcall demo_Data_watch_function(ViUInt32 cardnum,struct api_int_fifo_rs *sIntFIFO)
{
	ViUInt16 	ch;
	ViInt32 	tail=0, wordcount; 
	ViUInt8		datablock[4096];
	ViUInt32	rxcount=0,i=0,len; 
	char        msg[1024],msgx[2049],msgtemp[2];
	int RxEnable;
	int saveflag;
	int rxflag;
	int showflag;
	int temcnt=0;
	char temdata1111[1024]={0};
		int fileptr[24]={0};         
	if  (!monitorLFlag)	   //软件设置查询接收时，产生中断后不使用中断读数据。
		return 0;
    GetCtrlVal(PnlHandle,PANEL_SAVEFILE,&saveflag);
	GetCtrlVal(PnlHandle,PANEL_TX_STARTSTOP,&rxflag);
	GetCtrlVal(PnlHandle,PANEL_BINARYSWITCH,&showflag);  
	if(!rxflag)
	return 0;
		tail = sIntFIFO->tail_index; //尾地址 
		while ( tail != sIntFIFO->head_index )  
		{  
			ch  = sIntFIFO->fifo[tail].chnum;
			wordcount = sIntFIFO->fifo[tail].wordcount;

			hr = WDSerial_GetFiFoLen(
				      cardnum,  // (i) base address of memory area
				      ch,  // (i) base address of memory area
				      &len);   
			memset(datablock,0,sizeof(datablock));
			memset(msgx,0,sizeof(msgx));
			//读取接收数据
			{
				WDSerial_ReceiveBlockFIFO(
								   cardnum,  // (i) base address of memory area
								   ch,  // (i) base address of memory area
								   wordcount,  // (i) base address of memory area
								   datablock,
								   &rxcount);
				if (rxcount > 0)//该通道成功接收数据
				{ 	
				
						if ((saveflag)&&(SaveHandle))//保存接收文件    
					{
						fileptr[ch]=SaveFileEndAddr[ch];
						SaveFileEndAddr[ch] += rxcount;
						if(SaveFileEndAddr[ch]>SaveFileStartAddr[ch+1])
						{
							temcnt=SaveFileEndAddr[ch]-SaveFileStartAddr[ch+1];
							SetFilePtr(SaveHandle,fileptr[ch],0) ;
						    WriteFile(SaveHandle,(char*)(datablock),rxcount-temcnt); 
						    memcpy(&datablock[rxcount-temcnt],temdata1111,temcnt);
						    fileptr[ch]= SaveFileStartAddr[ch];
						    SetFilePtr(SaveHandle,fileptr[ch],0) ;  
							WriteFile(SaveHandle,temdata1111,temcnt);
							SaveFileEndAddr[ch]=temcnt;
						}
						else 
						{
							SetFilePtr(SaveHandle,fileptr[ch],0);   
							WriteFile(SaveHandle,(char*)(datablock),rxcount);
						}
				   	}
			   	
					if (showflag==1)//Hex 发送/接收
					{				
					    if(ErFlag==0)
			   			{
						    sprintf(msgx,"\nch%.2d ",ch); 
						   	allrxnum +=rxcount;
					   		SetCtrlVal (PnlHandle, PANEL_RXNUM, rxcount);
					   		SetCtrlVal (PnlHandle, PANEL_ALLRXNUM, allrxnum);
							for (i=0;i<rxcount;i++)
							{   
								sprintf(msg,"%.2x ",datablock[i]);
								strcat(msgx,msg);
							 	if(strlen(msgx) >= 100)
								{
									InsertTextBoxLine (PnlHandle,PANEL_RXDATA, -1, msgx);
									sprintf(msgx,"");
								}
							}  
							if(strlen(msgx) >= 2)
							{
								InsertTextBoxLine (PnlHandle,PANEL_RXDATA, -1, msgx);
								sprintf(msgx,"");
							}
						 }
						else
							ErFunction(datablock,rxcount,ch);
					
					}// end hex 
					else if (showflag==0)// CHAR 发送/接收
					{				
						
							memset(msgtemp,0,sizeof(char)*2);
							memset(msgx,0,sizeof(msgx));
							sprintf(msgx,"");
							sprintf(msgx,"\nch%.2d ",ch); 
						   	allrxnum +=rxcount;
					   		SetCtrlVal (PnlHandle, PANEL_RXNUM, rxcount);
					   		SetCtrlVal (PnlHandle, PANEL_ALLRXNUM, allrxnum);
							for (i=0;i<rxcount;i++)
							{
								msgtemp[0]=datablock[i]; 
								strcat(msgx,msgtemp); 
								if(strlen(msgx) >= 100)
								{
									InsertTextBoxLine (PnlHandle,PANEL_RXDATA, -1, msgx);
									sprintf(msgx,"");
								}
							}  
							if(strlen(msgx) >= 2)
							{
								InsertTextBoxLine (PnlHandle,PANEL_RXDATA, -1, msgx);
								sprintf(msgx,"");
							}
					}
				}
			}
			tail++;                         // Next entry  
			tail&=sIntFIFO->mask_index;
		    sIntFIFO->tail_index = tail;    // Save the index
	
		} 
	return 0;


}

int CVICALLBACK SetRxMode (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	int i;
	switch (event)
		{
		case EVENT_COMMIT:
			GetCtrlVal(PnlSys,PANEL_SYS_RXMODE,&RxMode);
			if(RxMode)
			{
				SetCtrlAttribute (PnlSys,PANEL_SYS_RXMODE, ATTR_DIMMED, 1); 
				SetCtrlAttribute (PnlSys, PANEL_SYS_LENGTH, ATTR_DIMMED, 0);
				SetCtrlAttribute (PnlSys, PANEL_SYS_WORD, ATTR_DIMMED, 1);
				SetCtrlAttribute (PnlSys, PANEL_SYS_LENGTH_F, ATTR_DIMMED, 1);
				SetCtrlAttribute (PnlSys, PANEL_SYS_WORD_F, ATTR_DIMMED, 1);
				SetCtrlVal(PnlSys, PANEL_SYS_LENGTH_F,1);
				SetCtrlVal(PnlSys, PANEL_SYS_WORD_F,0);
				//注册中断
				sIntFIFO1.function = demo_Data_watch_function;
				sIntFIFO1.iPriority = THREAD_PRIORITY_ABOVE_NORMAL;
				sIntFIFO1.dwMilliseconds = 0;
				sIntFIFO1.iNotification = 0; // Dont care about startup or shutdown
				sIntFIFO1.mask_index=0xFFFFFFFF;	
	
				hr = WDSerial_RegisterFunction(
								cardnum, 
								&sIntFIFO1,
								1);
								
								
				WDSerial_EnableBoardInterrupt(cardnum);							
				
				Delay(0.1);								
								
				monitorLFlag=1;
				OnLENGTH (panel, PANEL_SYS_LENGTH, EVENT_COMMIT,NULL,NULL,NULL) ; 
			}
		/*	else
			{
				hr = WDSerial_RegisterFunction(
								cardnum, 
								&sIntFIFO1,
								0);
				SetCtrlAttribute (PnlSys, PANEL_SYS_LENGTH, ATTR_DIMMED, 1);
				SetCtrlAttribute (PnlSys, PANEL_SYS_WORD, ATTR_DIMMED, 1);
				SetCtrlAttribute (PnlSys, PANEL_SYS_LENGTH_F, ATTR_DIMMED, 1);
				SetCtrlAttribute (PnlSys, PANEL_SYS_WORD_F, ATTR_DIMMED, 1);
				monitorLFlag=0;
			
			}	 */
			break;
		}
	return 0;
}

int CVICALLBACK OnLENGTH_F (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	int flag,i;
	switch (event)
		{
		case EVENT_COMMIT:
			// 24通道还不支持字符中断，当支持后，释放以下代码
		/*	GetCtrlVal(PnlSys,PANEL_SYS_LENGTH_F,&flag);
			SetCtrlAttribute (PnlSys, PANEL_SYS_LENGTH_F, ATTR_DIMMED, 1); 
			if(flag)
			{
				
				SetCtrlAttribute (PnlSys, PANEL_SYS_LENGTH, ATTR_DIMMED, 0);
				SetCtrlAttribute (PnlSys, PANEL_SYS_WORD, ATTR_DIMMED, 1);
				SetCtrlAttribute (PnlSys, PANEL_SYS_LENGTH_F, ATTR_DIMMED, 0);
				SetCtrlAttribute (PnlSys, PANEL_SYS_WORD_F, ATTR_DIMMED, 1);
				SetCtrlVal(PnlSys, PANEL_SYS_WORD_F,0);
				OnLENGTH (panel, PANEL_SYS_LENGTH, EVENT_COMMIT,NULL,NULL,NULL) ;
			}
			else
			{
				SetCtrlAttribute (PnlSys, PANEL_SYS_LENGTH, ATTR_DIMMED, 1);
				SetCtrlAttribute (PnlSys, PANEL_SYS_WORD, ATTR_DIMMED, 0);
				SetCtrlAttribute (PnlSys, PANEL_SYS_LENGTH_F, ATTR_DIMMED, 1);
				SetCtrlAttribute (PnlSys, PANEL_SYS_WORD_F, ATTR_DIMMED, 0);
				SetCtrlVal(PnlSys, PANEL_SYS_WORD_F,1);
				OnWORD (panel,PANEL_SYS_WORD,EVENT_COMMIT,NULL,NULL,NULL) ;         
			}
		*/	
			break;
		}
	return 0;
}

int CVICALLBACK OnWORD_F (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	int flag;
	switch (event)
		{
		case EVENT_COMMIT:
			// 24通道还不支持字符中断，当支持后，释放以下代码 
			GetCtrlVal(PnlSys,PANEL_SYS_WORD_F,&flag);
			if(flag)
			{
				SetCtrlAttribute (PnlSys, PANEL_SYS_LENGTH, ATTR_DIMMED, 1);
				SetCtrlAttribute (PnlSys, PANEL_SYS_WORD, ATTR_DIMMED, 0);
				SetCtrlAttribute (PnlSys, PANEL_SYS_LENGTH_F, ATTR_DIMMED, 1);
				SetCtrlAttribute (PnlSys, PANEL_SYS_WORD_F, ATTR_DIMMED, 0);
				SetCtrlVal(PnlSys, PANEL_SYS_LENGTH_F,0);
				OnWORD (panel,PANEL_SYS_WORD,EVENT_COMMIT,NULL,NULL,NULL) ;
			}
			else
			{
				SetCtrlAttribute (PnlSys, PANEL_SYS_LENGTH, ATTR_DIMMED, 0);
				SetCtrlAttribute (PnlSys, PANEL_SYS_WORD, ATTR_DIMMED, 1);
				SetCtrlAttribute (PnlSys, PANEL_SYS_LENGTH_F, ATTR_DIMMED, 0);
				SetCtrlAttribute (PnlSys, PANEL_SYS_WORD_F, ATTR_DIMMED, 1);
				SetCtrlVal(PnlSys, PANEL_SYS_LENGTH_F,1);
				OnLENGTH (panel, PANEL_SYS_LENGTH, EVENT_COMMIT,NULL,NULL,NULL) ; 
			}
			break;
		}
	return 0;
}

int CVICALLBACK OnSysSet (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{

	switch (event)
		{
		case EVENT_COMMIT:
			if(!cardnum)
			{
				MessagePopup("WD6632","模块尚未初始化");
			}
			if(SoftRuning)
			{
				MessagePopup("WD6632","模块发送/接收正在运行，请停止后操作");
				return 0;
			}
			InstallPopup(PnlSys);  
			break;
		}
	return 0;
}

int CVICALLBACK OnSysClose (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	int i;
	double tim[8];
	switch (event)
		{
		case EVENT_COMMIT:
			for (i=0;i<8;i++) 
			{
				GetCtrlVal(PnlSys,PANEL_SYS_TXPER0+i,&tim[i]);
				if(tim[i]!=0)
				//设置每个Timer的间隔
				SetAsyncTimerAttribute (NewTimer[i], ASYNC_ATTR_INTERVAL, tim[i]);
			}
			RemovePopup(PnlSys); 
			break;
		}
	return 0;
}

int CVICALLBACK OnLENGTH (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	int Leng,i;
	switch (event)
		{
		case EVENT_COMMIT:
			GetCtrlVal(PnlSys,PANEL_SYS_RXMODE,&RxMode);
			GetCtrlVal(PnlSys,PANEL_SYS_LENGTH,&Leng);
			//为每个接收通道设置不同的中断条件
			if (RxMode==1)  
			{
				for(i=0;i<MaxChnum;i++) 
				{
						hr = WDSerial_SetChInterupt(
								cardnum,  
								i,  //通道号
								1,	//字长中断使能
								0,  //字符中断使能
								Leng, //字长长度
								0x5a); //字符
				}			 
			}
			break;
		}
	return 0;
}

int CVICALLBACK OnWORD (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	int Word,i;
	switch (event)
		{
		case EVENT_COMMIT:
		/*
			GetCtrlVal(PnlSys,PANEL_SYS_WORD,&Word);
			GetCtrlVal(PnlSys,PANEL_SYS_RXMODE,&RxMode);
			//为每个接收通道设置不同的中断条件
			if (RxMode==1)  
			{
				for(i=0;i<MaxChnum;i++) 
				{
					if (G_PTR[i].RxEn==1)
						hr = WDSerial_SetChInterupt(
								cardnum,  
								i,  //通道号
								0,	//字长中断使能
								1,  //字符中断使能
								0, //字长长度
								Word); //字符
				}			 
			}		*/
			break;
		}
	return 0;
}

int CVICALLBACK OnCLEAR (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
		{
		case EVENT_COMMIT:
			ResetTextBox(PnlHandle,PANEL_RXDATA,""); 
			SetCtrlVal(PnlHandle,PANEL_TXNUM,0);
			SetCtrlVal(PnlHandle,PANEL_ALLTXNUM,0);
			SetCtrlVal(PnlHandle,PANEL_RXNUM,0);
			SetCtrlVal(PnlHandle,PANEL_ALLRXNUM,0);
			alltxnum=0;
			allrxnum=0;
			break;
		}
	return 0;
}

int CVICALLBACK TIMER_CLEAR (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
		{
		case EVENT_TIMER_TICK:
			ResetTextBox(PnlHandle,PANEL_RXDATA,""); 
			break;
		}
	return 0;
}

int CVICALLBACK AutoClear (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	int flag;
	switch (event)
		{
		case EVENT_COMMIT:
			GetCtrlVal(PnlHandle,PANEL_AUTOCLEAR,&flag);
			SetCtrlAttribute (PnlHandle, PANEL_TIMER_CLEAR, ATTR_ENABLED, flag);
			break;
		}
	return 0;
}

int CVICALLBACK OnSaveFile (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	int flag;
	char pathName[500];
	char msg[20];
	switch (event)
		{
		case EVENT_COMMIT:
			//保存文件
			GetCtrlVal(PnlHandle,PANEL_SAVEFILE,&flag);
			if (flag)
			{  
				GetDir (pathName);
				if (FileSelectPopup ("", ".RxData", "*.*", "", VAL_SAVE_BUTTON, 0, 0, 1, 0, pathName) >0)
				{
					if (strlen(pathName))			 
						SaveHandle = OpenFile (pathName, VAL_READ_WRITE, VAL_OPEN_AS_IS, VAL_BINARY);
					if(SaveHandle<0) 
						MessagePopup("Err","保存文件错误!");
	
				}
			}
			else
			{
				CloseFile(SaveHandle);
				SaveHandle = 0;	
			}
			break;
		}
	return 0;
}

int CVICALLBACK OnCLEARTXDATA (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
		{
		case EVENT_COMMIT:
			ResetTextBox(PnlChSet,PANEL_CHS_TXDATA,"");  
			G_PTR[chnum].TxCount=0;
			break;
		}
	return 0;
}



int CVICALLBACK OnHEXTX (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	int flag;
	switch (event)
		{
		case EVENT_COMMIT:
			GetCtrlVal(PnlChSet,PANEL_CHS_HEXTX,&flag);
			if(flag)// HEX发送
			{
				
				SetCtrlAttribute(PnlChSet,PANEL_CHS_BEGDATA,ATTR_VISIBLE,1); 
				SetCtrlAttribute(PnlChSet,PANEL_CHS_DATANUM,ATTR_VISIBLE,1);
				SetCtrlAttribute(PnlChSet,PANEL_CHS_ADDTXDATA,ATTR_VISIBLE,1);
				SetCtrlVal(PnlChSet,PANEL_CHS_CHARTX,0);
			}
			else
			{
				
				SetCtrlAttribute(PnlChSet,PANEL_CHS_BEGDATA,ATTR_VISIBLE,0); 
				SetCtrlAttribute(PnlChSet,PANEL_CHS_DATANUM,ATTR_VISIBLE,0); 	
				SetCtrlAttribute(PnlChSet,PANEL_CHS_ADDTXDATA,ATTR_VISIBLE,0);
				SetCtrlVal(PnlChSet,PANEL_CHS_CHARTX,1);
			}
			GetCtrlVal(PnlChSet,PANEL_CHS_CHARTX,&G_PTR[chnum].TxMode);  
			break;
		}
	return 0;
}

int CVICALLBACK OnCHARTX (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	int flag;
	switch (event)
		{
		case EVENT_COMMIT:
			GetCtrlVal(PnlChSet,PANEL_CHS_CHARTX,&flag);
			if(flag)// HEX发送
			{
				SetCtrlAttribute(PnlChSet,PANEL_CHS_BEGDATA,ATTR_VISIBLE,0); 
				SetCtrlAttribute(PnlChSet,PANEL_CHS_DATANUM,ATTR_VISIBLE,0);
				SetCtrlAttribute(PnlChSet,PANEL_CHS_ADDTXDATA,ATTR_VISIBLE,0);
				SetCtrlVal(PnlChSet,PANEL_CHS_HEXTX,0);
			}
			else
			{
				SetCtrlAttribute(PnlChSet,PANEL_CHS_BEGDATA,ATTR_VISIBLE,1); 
				SetCtrlAttribute(PnlChSet,PANEL_CHS_DATANUM,ATTR_VISIBLE,1);
				SetCtrlAttribute(PnlChSet,PANEL_CHS_ADDTXDATA,ATTR_VISIBLE,1);
				SetCtrlVal(PnlChSet,PANEL_CHS_HEXTX,1);
			}
			GetCtrlVal(PnlChSet,PANEL_CHS_CHARTX,&G_PTR[chnum].TxMode);  
			break;
		}
	return 0;
}

int CVICALLBACK OnALLOWTX (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	int i,flag;
	switch (event)
		{
		case EVENT_COMMIT:
			GetCtrlVal(PnlChTR,PANEL_TR_ALLOWTX,&flag);
			for (i=0;i<MaxChnum;i++)
			{
				SetCtrlVal(PnlChTR,PANEL_TR_TXCH0+i,flag);
			}
			break;
		}
	return 0;
}


void SetTimer(void)
{
	int flag,i=0;;
		
		GetCtrlVal(PnlHandle, PANEL_TX_STARTSTOP, &flag);
		//当发送通道允许，为每个通道创建线程并允许发送
		for(i=0;i<8;i++)
			SetAsyncTimerAttribute (NewTimer[i], ASYNC_ATTR_ENABLED, flag);
}
											
int (CVICALLBACK  TxChTimerCallbackPtr0) (int reserved, int timerId, int event, void *callbackData, int eventData1, int eventData2)
{
	int i,ch=0,ThisNum=0;
	int txcount=0;
	ViUInt8 txdata[1024];
	char	databuf[1024];
	int  ErrorTestFlag=0;
	switch (event)
		{
		case EVENT_TIMER_TICK:
		//
			GetCtrlVal(PnlHandle,PANEL_CHECKBOX,&ErrorTestFlag); 
			
			for (ch=0;ch<MaxChnum;ch++)
			{
			
				if (((G_PTR[ch].TxCount!=0))&&(G_PTR[ch].TxPer==0)&&(OpenCh[ch] == 1))
				{
					hr = WDSerial_TransmitFIFOBlock(
								cardnum,  
								ch,  
								G_PTR[ch].TxCount,  
								G_PTR[ch].TxData);
							
					alltxnum +=G_PTR[ch].TxCount;
					ThisNum = G_PTR[ch].TxCount;
		
					SetCtrlVal(PnlHandle,PANEL_TXNUM,ThisNum);
					SetCtrlVal(PnlHandle,PANEL_ALLTXNUM,alltxnum); 
				}
			}
			break;
		}
	return 0;  
}
int (CVICALLBACK  TxChTimerCallbackPtr1) (int reserved, int timerId, int event, void *callbackData, int eventData1, int eventData2)
{
	int i,ch=1,ThisNum=0;
	switch (event)
		{
		case EVENT_TIMER_TICK:
			for (ch=0;ch<MaxChnum;ch++)
			{
				if (((G_PTR[ch].TxCount!=0))&&(G_PTR[ch].TxPer==1)&&(OpenCh[ch] == 1))
				{
					hr = WDSerial_TransmitFIFOBlock(
								cardnum,  
								ch,  
								G_PTR[ch].TxCount,  
								G_PTR[ch].TxData);
							
					alltxnum +=G_PTR[ch].TxCount;
					ThisNum = G_PTR[ch].TxCount;
		
					SetCtrlVal(PnlHandle,PANEL_TXNUM,ThisNum);
					SetCtrlVal(PnlHandle,PANEL_ALLTXNUM,alltxnum); 
				}
			}
			
			break;
		}
	return 0;  
}
int (CVICALLBACK  TxChTimerCallbackPtr2) (int reserved, int timerId, int event, void *callbackData, int eventData1, int eventData2)
{
	int i,ch=2,ThisNum=0;
	switch (event)
		{
		case EVENT_TIMER_TICK:
			for (ch=0;ch<MaxChnum;ch++)
			{
				if (((G_PTR[ch].TxCount!=0))&&(G_PTR[ch].TxPer==2)&&(OpenCh[ch] == 1))
				{
					hr = WDSerial_TransmitFIFOBlock(
								cardnum,  
								ch,  
								G_PTR[ch].TxCount,  
								G_PTR[ch].TxData);
							
					alltxnum +=G_PTR[ch].TxCount;
					ThisNum = G_PTR[ch].TxCount;
		
					SetCtrlVal(PnlHandle,PANEL_TXNUM,ThisNum);
					SetCtrlVal(PnlHandle,PANEL_ALLTXNUM,alltxnum); 
				}
			}
			break;
		}
	return 0;  
}
int (CVICALLBACK  TxChTimerCallbackPtr3) (int reserved, int timerId, int event, void *callbackData, int eventData1, int eventData2)
{
	int i,ch=3,ThisNum=0;
	switch (event)
		{
		case EVENT_TIMER_TICK:
			for (ch=0;ch<MaxChnum;ch++)
			{
				if (((G_PTR[ch].TxCount!=0))&&(G_PTR[ch].TxPer==3)&&(OpenCh[ch] == 1))
				{
					hr = WDSerial_TransmitFIFOBlock(
								cardnum,  
								ch,  
								G_PTR[ch].TxCount,  
								G_PTR[ch].TxData);
							
					alltxnum +=G_PTR[ch].TxCount;
					ThisNum = G_PTR[ch].TxCount;
		
					SetCtrlVal(PnlHandle,PANEL_TXNUM,ThisNum);
					SetCtrlVal(PnlHandle,PANEL_ALLTXNUM,alltxnum); 
				}
			}
			break;
		}
	return 0;  
}
int (CVICALLBACK  TxChTimerCallbackPtr4) (int reserved, int timerId, int event, void *callbackData, int eventData1, int eventData2)
{
	int i,ch=4,ThisNum=0;
	switch (event)
		{
		case EVENT_TIMER_TICK:
			for (ch=0;ch<MaxChnum;ch++)
			{
				if (((G_PTR[ch].TxCount!=0))&&(G_PTR[ch].TxPer==4)&&(OpenCh[ch] == 1))
				{
					hr = WDSerial_TransmitFIFOBlock(
								cardnum,  
								ch,  
								G_PTR[ch].TxCount,  
								G_PTR[ch].TxData);
							
					alltxnum +=G_PTR[ch].TxCount;
					ThisNum = G_PTR[ch].TxCount;
		
					SetCtrlVal(PnlHandle,PANEL_TXNUM,ThisNum);
					SetCtrlVal(PnlHandle,PANEL_ALLTXNUM,alltxnum); 
				}
			}
			break;
		}
	return 0;  
}
int (CVICALLBACK  TxChTimerCallbackPtr5) (int reserved, int timerId, int event, void *callbackData, int eventData1, int eventData2)
{
	int i,ch=5,ThisNum=0;
	switch (event)
		{
		case EVENT_TIMER_TICK:
			for (ch=0;ch<MaxChnum;ch++)
			{
				if (((G_PTR[ch].TxCount!=0))&&(G_PTR[ch].TxPer==5)&&(OpenCh[ch] == 1))
				{
					hr = WDSerial_TransmitFIFOBlock(
								cardnum,  
								ch,  
								G_PTR[ch].TxCount,  
								G_PTR[ch].TxData);
							
					alltxnum +=G_PTR[ch].TxCount;
					ThisNum = G_PTR[ch].TxCount;
		
					SetCtrlVal(PnlHandle,PANEL_TXNUM,ThisNum);
					SetCtrlVal(PnlHandle,PANEL_ALLTXNUM,alltxnum); 
				}
			}
			
			break;
		}
	return 0;  
}
int (CVICALLBACK  TxChTimerCallbackPtr6) (int reserved, int timerId, int event, void *callbackData, int eventData1, int eventData2)
{
	int i,ch=6,ThisNum=0;
	switch (event)
		{
		case EVENT_TIMER_TICK:
			for (ch=0;ch<MaxChnum;ch++)
			{
				if (((G_PTR[ch].TxCount!=0))&&(G_PTR[ch].TxPer==6)&&(OpenCh[ch] == 1))
				{
					hr = WDSerial_TransmitFIFOBlock(
								cardnum,  
								ch,  
								G_PTR[ch].TxCount,  
								G_PTR[ch].TxData);
							
					alltxnum +=G_PTR[ch].TxCount;
					ThisNum = G_PTR[ch].TxCount;
		
					SetCtrlVal(PnlHandle,PANEL_TXNUM,ThisNum);
					SetCtrlVal(PnlHandle,PANEL_ALLTXNUM,alltxnum); 
				}
			}
			break;
		}
	return 0;  
}
int (CVICALLBACK  TxChTimerCallbackPtr7) (int reserved, int timerId, int event, void *callbackData, int eventData1, int eventData2)
{
	int i,ch=7,ThisNum=0;
	switch (event)
		{
		case EVENT_TIMER_TICK:
			for (ch=0;ch<MaxChnum;ch++)
			{
				if (((G_PTR[ch].TxCount!=0))&&(G_PTR[ch].TxPer==7)&&(OpenCh[ch] == 1))
				{
					hr = WDSerial_TransmitFIFOBlock(
								cardnum,  
								ch,  
								G_PTR[ch].TxCount,  
								G_PTR[ch].TxData);
							
					alltxnum +=G_PTR[ch].TxCount;
					ThisNum = G_PTR[ch].TxCount;
		
					SetCtrlVal(PnlHandle,PANEL_TXNUM,ThisNum);
					SetCtrlVal(PnlHandle,PANEL_ALLTXNUM,alltxnum); 
				}
			}
			break;
		}
	return 0;  
}

int CVICALLBACK RESETDATA (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
		{
		case EVENT_COMMIT:
			G_PTR[chnum].ResetData=1;
			break;
		}
	return 0;
}

int CVICALLBACK ConnectFindDevice1 (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
   int itemIndex=0;
    ViUInt32  SF_VER,HW_VER=0; 
	char msg[50]={0},SoftVersion[100]={0},DevVersion[100]={0}; 
	switch (event)
		{
		case EVENT_COMMIT:
		
			GetCtrlIndex (PnlFinDev, FINDDEVICE_LISTBOX, &itemIndex);
			
			if (itemIndex>=10)  break;
			
			hr=WDSerial_Init(
			   findPCI_SOURCE[itemIndex].BusNumber,
			   findPCI_SOURCE[itemIndex].SlotNumber,
			   &cardnum);  // (i) base address of memory area			
			   
			if(hr == 0)
			{
				SetCtrlVal(PnlHandle,PANEL_CONNECT_LED,1);
				SetCtrlAttribute(PnlHandle,PANEL_CONNECT_AUTO,ATTR_DIMMED,1);
				SetCtrlAttribute(PnlHandle,PANEL_CONNECT_BUS,ATTR_DIMMED,1);
				hr = WDSerial_Reset(cardnum); 
				hr=WDSerial_GetRevision(cardnum,&HW_VER,&SF_VER);
				
				sprintf(msg,"连接状态：连接中");
				SetCtrlVal(PnlHandle,PANEL_CON_TXT,msg);
				
				sprintf(DevVersion,"硬件版本号：%X-V%x.%.2x ",(HW_VER>>12)&0xF,(HW_VER>>8)&0xF, HW_VER&0xFF);   
				SetCtrlVal(PnlHandle, PANEL_DEV_VERSION,DevVersion);      
				
				sprintf(SoftVersion,"软件版本号：：%X-V%x.%.2x ",(SF_VER>>12)&0xF,(SF_VER>>8)&0xF, SF_VER&0xFF);  
				SetCtrlVal(PnlHandle, PANEL_SOFT_VERSION,SoftVersion);  
			}
			else
			{
				MessagePopup("WD6632","Connect is failed!");
				SetCtrlVal(PnlHandle,PANEL_CONNECT_LED,0);
				SetCtrlAttribute(PnlHandle,PANEL_CONNECT_AUTO,ATTR_DIMMED,0);
				SetCtrlAttribute(PnlHandle,PANEL_CONNECT_BUS,ATTR_DIMMED,0);
				return 0;			   
			}	

			RemovePopup(PnlFinDev);     

			break;
		}
	return 0;
}

int CVICALLBACK CloseDeviceFind1 (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
		{
		case EVENT_COMMIT:
				RemovePopup(PnlFinDev);
			break;
		}
	return 0;
}

int CVICALLBACK QuitAbout (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
		{
		case EVENT_COMMIT:
			DiscardPanel(panelabout) ; 
			break;
		}
	return 0;
}

int CVICALLBACK ErrorTestFunction (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	int  ErrorTestFlag=0;
	int  i=0,j=0;
	int  ch=0;
	switch (event)
		{
		case EVENT_COMMIT:
			GetCtrlVal(PnlHandle,PANEL_CHECKBOX,&ErrorTestFlag); 
			if(ErrorTestFlag==1)
			{
				ErFlag=1;
				for(j=0;j<24;j++)
				{
					if(OpenCh[j] == 1)
					{
						G_PTR[j].TxCount=0;
						if(G_PTR[j].TxData != NULL)
							free(G_PTR[j].TxData);
						G_PTR[j].TxData=malloc(sizeof(ViUInt8)*1024);
						for(i=0;i<256;i++)
						{
							G_PTR[j].TxData[i]=i;
							G_PTR[j].TxCount++;
						}
					}
				}
			}
			else 
			{
				ErFlag=0;
			}
			break;
		}
	return 0;
}



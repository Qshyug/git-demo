/*============================================================================*
 * FILE:                      	ep-h6273 . H
 * Date:						2003 12 5
 * company:						enpht
 *===========================================================================*
 *
 * FUNCTION:    Header file for ep-h6273 API structures.  This is the file
 *              which users should include in their programs.
 *
 *===========================================================================*/

#include "visatype.h" 


#ifndef _WDSerial_H_
#define _WDSerial_H_


typedef ViUInt8 LabelType;


#define MAX_FIFO_LEN_RS   (64)

#define NOFRAMEDATA    (0xFFFFFFF4)


typedef struct api_int_fifo_rs
{
	ViInt32 (_stdcall *function)(ViUInt32 cardnum, struct api_int_fifo_rs *pFIFO);
	// Function should return API_SUCCESS if thread is to
	// continue operation, any other value will cause
	// the thread and event object to be destroyed.
	// User-requested thread priority:
	int iPriority; // THREAD_PRIORITY_* as defined for Windows function
	// SetThreadPriority() or zero for normal priority.
	ViUInt32 dwMilliseconds;// Thread time-out interval in milliseconds or INFINITE
	// Mask to request startup and shutdown notification:
	ViInt32 iNotification; // CALL_STARTUP if function to be called at creation
	// of thread, CALL_SHUTDOWN if function is to be
	// called upon destruction of thread. ¡°OR¡± both
	// together to enable notification on both events.
	// See ¡°bForceShutdown¡± and ¡°bForceStartup¡± below.
	// User variables; not referenced by the API:
	int nUser[8]; // Spare variables for use by the user.
	void *pUser[8]; // Spare variables for use by the user.
	//**************************************************************************
	// Event filter structure. A one ¡°1' enables the specified event; when
	// detected the API will place it in the FIFO and call the user function.
	//**************************************************************************
	// Top Level Notification Event Mask:
	ViInt32 FilterType; // One or more EVENT_ definitions, ¡°or'ed¡± together.
	// Event filter mask array.
	// rt tr sa
	ViUInt32 cardnum; // Card number associated with this thread. (RO) $
	ViInt32 head_index; // Index of element being added to queue (0->63) (RO) $
	ViInt32 tail_index; // Index of element to be removed from queue (RW) $
	ViInt32 mask_index; // Mask for wrapping head and tail pointers (RO) $


	int bForceShutdown;// 1 - Thread is being shutdown, -1 complete (RO) $
	int bForceStartup; // 1 - Thread is being started, 0 complete (RO) $
	int nPtrIndex; // Index into API pointer table (RO) $

	ViUInt32 numEvents; // Total number of events, including overflows (RW) $
	ViUInt32 queue_oflow; // Count incremented by API when FIFO overflows (RW) $
	void* hEvent; // Handle to event object (RO) $
	//HANDLE hkEvent; // Kernel mode handle to event object (RO) $
	void* hThread; // Handle to thread (RO) $
	ViUInt32 lThreadId; // ID of new user interrupt thread. (RO) $

	struct BT_FIFO_RS // FIFO structure: events for user to process. $
	{
		ViUInt16 chnum;
		// unless mode code (then indicates mode code number)
		ViInt32 wordcount; // Word count of message; 0-31; 0 indicates 32 words
		ViInt32 reserved2; // Reserved for API.
	}
	fifo[MAX_FIFO_LEN_RS]; // FIFO has exactly 64 entries.
}
API_INT_FIFO_RS;



#ifndef _PCI_SOURCE_
#define _PCI_SOURCE_
typedef struct pci_source
   {
    ViUInt32 BusNumber;
    ViUInt32 SlotNumber;
    ViUInt32 VendorId;
    ViUInt32 DeviceId;
   }
PCI_SOURCE;
#endif


#ifdef __cplusplus
extern "C" {
#endif

ViStatus _VI_FUNC WDSerial_DeviceFind_PCI(
   ViUInt16		MaxNum,
   PCI_SOURCE*	PCI_SOURCE,
   ViUInt16*	FindNum);
   
ViStatus _VI_FUNC WDSerial_AutoConnectFirst(
   ViUInt32    *cardnum);

ViStatus _VI_FUNC WDSerial_Init(
   ViUInt16	   BusNumber,
   ViUInt16	   SlotNumber,
   ViUInt32	   *cardnum); // (i) base address of memory area

ViStatus _VI_FUNC WDSerial_Reset(
   ViUInt32    cardnum);

ViStatus _VI_FUNC WDSerial_Close(
   ViUInt32    cardnum);

ViStatus _VI_FUNC WDSerial_GetRevision(
   ViUInt32    cardnum,         // (i) card number (0 - based)
   ViUInt32    *ucode_rev, // (o) microcode revision of card
   ViUInt32    *api_rev);  // (o) API revision number

ViStatus _VI_FUNC WDSerial_StatusGetString(
   char *      message,	
   ViInt32     status);          // (i) Eph6273 error status

ViStatus _VI_FUNC WDSerial_ReceiveBlockFIFO(
   ViUInt32	   cardnum,  // (i) base address of memory area
   ViUInt16	   ch,  // (i) base address of memory area
   ViUInt16	   maxcount,  // (i) base address of memory area
   ViUInt8	   *datablock,
   ViUInt32	   *rxcount);

ViStatus _VI_FUNC WDSerial_SetCh(
   ViUInt32    cardnum,  // (i) base address of memory area
   ViUInt16    ch,  // (i) base address of memory area
   ViUInt16	   rate,
   ViUInt16	   parity,
   ViUInt16	   bitcount,
   ViUInt16	   stopbit);

ViStatus _VI_FUNC WDSerial_GetCh(
   ViUInt32   cardnum,  // (i) base address of memory area
   ViUInt16   ch,  // (i) base address of memory area
   ViUInt16	  *rate,
   ViUInt16	  *parity,
   ViUInt16	  *bitcount,
   ViUInt16	  *stopbit);

ViStatus _VI_FUNC WDSerial_SetChMode(
   ViUInt32   cardnum,  // (i) base address of memory area
   ViUInt16   ch,  // (i) base address of memory area
   ViUInt32	  type422);

ViStatus _VI_FUNC WDSerial_GetChMode(
   ViUInt32   cardnum,  // (i) base address of memory area
   ViUInt16   ch,  // (i) base address of memory area
   ViUInt32	  *type422);

ViStatus _VI_FUNC WDSerial_StartStop(
   ViUInt32   cardnum,
   ViUInt32   flag,
   ViUInt32   ExtTrg);

ViStatus _VI_FUNC WDSerial_ChannelEn(
	ViUInt32  cardnum,
	ViUInt16  Ch,
	ViUInt16  Enable);


ViStatus _VI_FUNC WDSerial_TransmitFIFOBlock(
   ViUInt32   cardnum,  // (i) base address of memory area
   ViUInt16   ch,  // (i) base address of memory area
   ViUInt16   count,  // (i) base address of memory area
   ViUInt8	  *datablock);

///////////////////////////////////
ViStatus _VI_FUNC WDSerial_GetFiFoLen(
   ViUInt32   cardnum,  // (i) base address of memory area
   ViUInt16   ch,  // (i) base address of memory area
   ViUInt32   *len);  // (i) base address of memory area


ViStatus _VI_FUNC WDSerial_SetChInterupt(
   ViUInt32   cardnum,  // (i) base address of memory area
   ViUInt16   ch,  // (i) base address of memory area
   ViUInt16	  masklength_int,
   ViUInt16	  maskchar_int,
   ViUInt16	  intlength,
   ViUInt8	  intchar);

ViStatus _VI_FUNC WDSerial_RegisterFunction(
   ViUInt32		cardnum, 
   API_INT_FIFO_RS *sIntFIFO1,
   ViUInt32		flag);

ViStatus _VI_FUNC WDSerial_EnableBoardInterrupt(
   ViUInt32	  cardnum);


ViStatus _VI_FUNC WDSerial_DisableBoardInterrupt(
   ViUInt32	  cardnum);

ViStatus _VI_FUNC WDSerial_TxFIFOReset(
   ViUInt32   cardnum ,
   ViUInt16   ch);

ViStatus _VI_FUNC WDSerial_RxFIFOReset(
   ViUInt32   cardnum ,
   ViUInt16   ch );

ViStatus _VI_FUNC WDSerial_ConfigTxFrame(
   ViUInt32   cardnum,  // (i) base address of memory area
   ViUInt16   Ch,  // (i) base address of memory area
   ViUInt16   EN,  // (i) base address of memory area
   ViUInt16   Frame_Len,  // (i) base address of memory area
   ViUInt16	  Frame_Frq,
   ViUInt16	  BuffB);

ViStatus _VI_FUNC WDSerial_GetConfigTxFrame(
   ViUInt32   cardnum,  // (i) base address of memory area
   ViUInt16   Ch,  // (i) base address of memory area
   ViUInt16   *EN,  // (i) base address of memory area
   ViUInt16   *Frame_Len,  // (i) base address of memory area
   ViUInt16	  *Frame_Frq,
   ViUInt16	  *BuffB);

ViStatus _VI_FUNC WDSerial_UpdataFrameData(
   ViUInt32   cardnum,  // (i) base address of memory area
   ViUInt16   Ch,  // (i) base address of memory area
   ViUInt16	  BuffB,  // (i) base address of memory area
   ViUInt8    *pData,  // (i) base address of memory area
   ViUInt16	  Len);



#ifdef __cplusplus
}
#endif

#endif  // #ifndef _EPH6273_H_

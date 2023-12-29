#define _Use64bit_xLnum       0
#if _Use64bit_xLnum
#define _xLnum(pNum,Size) ((Size==1? (*((uint8_t*)(pNum))):((Size==2? (*((uint16_t*)(pNum))):((Size==4? (*((uint32_t*)(pNum))):((Size==8? (*((uint64_t*)(pNum))):(~0x00)))))))))
#else
#define _xLnum(pNum,Size) ((Size==1? (*((uint8_t*)(pNum))):((Size==2? (*((uint16_t*)(pNum))):(*((uint32_t*)(pNum)))))))//将指针pNum，向后的Size个字节视作一个数读出
#endif


#define AcquireFlashMutex
#define ReleaseFlashMutex

#define FlashRead(pdata,ADDR,counter)
#define FlashWrite(pdata,ADDR,counter)
#define FlashEraseSector(Sector_Num)

#define GetHoleNumUp(Num,HoleNum)   ((Num + (HoleNum - 1))&(~(HoleNum - 1)))
#define GetHoleNumDown(Num,HoleNum) ((Num)&(~(HoleNum - 1)))


typedef signed char        int8_t;
typedef short              int16_t;
typedef int                int32_t;
typedef long long          int64_t;
typedef unsigned char      uint8_t;
typedef unsigned short     uint16_t;
typedef unsigned int       uint32_t;
typedef unsigned long long uint64_t;


typedef struct
{
  uint32_t  IndexStartADDR;
  uint32_t  IndexSpaceSize;
  uint32_t  IndexCellSize;

  uint32_t  DataStartADDR;
  uint32_t  DataSpaceSize;
  uint32_t  DataCellSize;

  uint32_t  MaxCellNum;
}ComItemIO_PartTab_Def;



static int Check00orFF(void* pdata,uint32_t Size);

#ifndef  _xLnum(pNum,Size)
#if _Use64bit_xLnum
  static uint64_t _xLnum(void* pNum,int Size);
#else
  static uint32_t _xLnum(void* pNum,int Size);
#endif
#endif
int32_t ComItemIO_Format(uint32_t  StartADDR, uint32_t Size, uint32_t  CellSize);




/********************************************************/
int32_t ComItemIO_Add(ComItemIO_PartTab_Def*  ComItemIO_PartTab,void* pData);
int32_t ComItemIO_Delete(ComItemIO_PartTab_Def*  ComItemIO_PartTab,uint32_t* DelNumList,uint32_t ListLength);
int32_t ComItemIO_Find(ComItemIO_PartTab_Def*  ComItemIO_PartTab,uint32_t DataNum,void* pData);
int32_t ComItemIO_GetNum(ComItemIO_PartTab_Def*  ComItemIO_PartTab);

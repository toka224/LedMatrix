/**********************************************************/
/* Author    : Toka Medhat                                */
/* Date      : 26 NOV 2020                                */
/* Version   : V01                                        */
/**********************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "RCC_interface.h"
#include "STK_interface.h"

#include "LEDMRX_interface.h"

void NameDisplay(u8 * Copy_u8DataArray ,u8 Copy_u8DataArrayIndex);
void PlayFootBall(u8 * Copy_u8Play1 , u8 * Copy_u8Play2);

u8 DataArrayIndex =27;
u8 DataArray[27]={0, 2, 30, 2, 0, 12, 18, 18, 12, 0, 30, 12, 18, 0, 28, 10, 10, 28 ,0 };
u8 index =0 ;
u8 LedMatrixIndex =8;
u8 PlayerAcc1[8]={0, 0, 214, 126, 214, 0, 128, 0};
u8 PlayerAcc2[8]={0, 0, 214, 126, 86, 96, 4, 0};

void main(void)
{
	RCC_voidInitSysClock();
    RCC_voidEnableClock(RCC_APB2, 2);
	RCC_voidEnableClock(RCC_APB2, 3);

	MSTK_voidInit();

	HLEDMRX_VoidInit();


	//HLEDMRX_VoidDisplay(DataArray);

	for(u8 DataIndex= DataArrayIndex-LedMatrixIndex ; DataIndex< DataArrayIndex ; DataIndex++)
	{
		DataArray[DataIndex]=DataArray[index];
		index++;
	}
	while(1)
	{

		NameDisplay(DataArray, DataArrayIndex);
		MSTK_voidSetBusyWait( 1000000 );
		PlayFootBall(PlayerAcc1 , PlayerAcc2);


	}

}


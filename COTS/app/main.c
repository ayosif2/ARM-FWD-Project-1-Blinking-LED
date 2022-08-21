#include "Port.h"
#include "bit_math.h"	
#include "Nvic.h"
#include "Timer.h"
#include "LED.h"
	
	int main(){
	NVIC_int();
	Port_Init ();	
	systick_init();
	LED_Blink(6000,6000);

	}


#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void buzzer(void) {
	for(int i = 0; i < 3; i++) {
		BuzzerSet(120, 200);
		BuzzerStart();
		Wait(400);
		BuzzerStop();
		Wait(400);
	}

	BuzzerSet(142, 200);
	BuzzerStart();
	Wait(1000);
	BuzzerStop();
	Wait(1000);

	for (int i = 0; i < 3; i++) {
		BuzzerSet(134, 200);
		BuzzerStart();
		Wait(400);
		BuzzerStop();
		Wait(400);
	}

	BuzzerSet(160, 200);
	BuzzerStart();
	Wait(1000);
	BuzzerStop();
	Wait(1000);
}

int main(void) {
	const unsigned short MainCycle = 60;
	Init(MainCycle);
	buzzer();

	return 0;
}

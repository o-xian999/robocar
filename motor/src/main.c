#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

// No Good!
void run(void) {
  Mtr_Run_lv(20000, 20000, 0, 0, 0, 0);
  // (motor, another motor)
  Wait(3000);
  Mtr_Run_lv(0, 0, 0, 0, 0, 0);
}

void motor(short left, short right) {
	Mtr_Run_lv(right, -left, 0, 0, 0, 0);
}

void stop() {
	motor(0, 0);
}

void one() {
	Wait(90);
}

void step(int n) {
	for(int i = 0; i < n; i++) {
		one();
	}
}

int main(void) {
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	LED(3);
	motor(20000, 20000);
	// 3cm
	// Wait(90); // robocar 15
	step(3);
	stop();
	LED(0);


	return 0;
}

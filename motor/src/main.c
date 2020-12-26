#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void run(void) {
	Mtr_Run_lv(20000, 20000, 0, 0, 0, 0);
	Wait(3000);
	Mtr_Run_lv(0, 0, 0, 0, 0, 0);
}

void motor(short left, short right) {
	Mtr_Run_lv(right, -left, 0, 0, 0, 0);
}

void stop(void) {
	motor(0, 0); // モーター停止
	Wait(1000); // 1秒待機
}

// task1
void one(void) {
	motor(20000, 20000);
	Wait(90);
}

// task2
void step(int n) {
    // 指定された長さだけone()をループ
	for (int i = 0; i < n; i++) {
		one();
	}
}

// task3
void right(int degree) {
	motor(20000, -20000);
	Wait((int)(600 * (1.0 * degree / 360))); //一周の回転にかかる時間×角度の割合
}

// task4, 5, 6
void go_and_turn(int n) {
	motor(20000, 20000);
	// n辺分繰り返す
	for (int i = 0; i < n; i++) {
		step(30); // 30cm進む
		Wait(100);
		right(360 / n); // 正n角形内の一つの角度の分だけ回転
		Wait(100);
	}
	stop();
}

void coming_and_going() {
	go_and_turn(2);
}

void triangle(void) {
	go_and_turn(3);
}

void square(void) {
	go_and_turn(4);
}

int main(void) {
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	LED(3); // main関数動作確認

	// ここから関数
	coming_and_going();
	triangle();
	square();
	// ここまで関数

	LED(0); // main関数終了確認
	return 0;
}

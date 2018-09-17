/*
 * main.c
 *
 *  Created on: 16/09/2018
 *      Author: Emerson Souza
 */

#include<system.h>;
#include<io.h>;

#define MAXPOS 2 // Define max number of leds

int calculateNewPosition (int position);

int main () {
	unsigned int btn1, btn2, out1;
	int nextPosition = 0;

	while (1) {
		btn1 = IORD(BUTTON_1_BASE, 0);
		btn2 = IORD(BUTTON_2_BASE, 0);

		if (btn1) {
			nextPosition = calculateNewPosition(nextPosition);
		} else if (btn2) {
			nextPosition = 0;
		}

		IOWR(OUTPUT_Y_BASE, 0, out1);
	}
}

int calculateNewPosition (int position) {
	int nextPosition = position + 1;
	if (MAXPOS < nextPosition) return 0;
	return position + 1;
}

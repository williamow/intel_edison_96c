#include<time.h>

#include "mraa/aio.h"

void delay(int milliseconds);

int main() {
	mraa_aio_context adc_a0;

	adc_a0 = mraa_aio_init(0);
	if (adc_a0 == NULL) {
		return 1;
	}
	int data[1000];
	for (int q = 0; q < 1000; q = q+1) {
		data[q] = mraa_aio_read(adc_a0);
		//delay(500);
	}
	for (int q = 0; q < 1000; q = q + 1) {
		fprintf(stdout, "%d\n", data[q]);
		//delay(500);
	}
	mraa_aio_close(adc_a0);
	return MRAA_SUCCESS;
}
void delay(int milliseconds)

{

	long pause;

	clock_t now, then;

	pause = milliseconds*(CLOCKS_PER_SEC / 1000);

	now = then = clock();

	while ((now - then) < pause)

		now = clock();

}
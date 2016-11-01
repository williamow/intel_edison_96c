#include<time.h>

#include "mraa/aio.h"

void delay(int milliseconds);

int main() {
	mraa_aio_context adc_a0;
	uint16_t adc_value = 0;
	float adc_value_float = 0.0;

	adc_a0 = mraa_aio_init(0);
	if (adc_a0 == NULL) {
		return 1;
	}

	for (int q = 0; q < 1000; q = q+1) {
		adc_value = mraa_aio_read(adc_a0);
		adc_value_float = mraa_aio_read_float(adc_a0);
		fprintf(stdout, "%d\n", adc_value);
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
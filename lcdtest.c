#include <stdio.h>
#include <mraa/i2c.h>

#define REG_RED         0x04        // pwm2
#define REG_GREEN       0x03        // pwm1
#define REG_BLUE        0x02        // pwm0

int main(){
	printf("Starting...");
	mraa_init();
	mraa_i2c_context i2c;
	i2c = mraa_i2c_init(0);
	mraa_i2c_address(i2c, 2);
	mraa_i2c_write_byte(i2c, 0xc4>>1);
	mraa_i2c_write_byte_data(255, REG_RED);
	mraa_i2c_write_byte_data(255, REG_GREEN);
	mraa_i2c_write_byte_data(255, REG_BLUE);
	printf("Set screen color...");
	sleep(5);
}

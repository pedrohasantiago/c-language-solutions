/* Print the corresponding Celsius to Fahrenheit table */ 
#include <stdio.h>

main() {
	float fahr, celsius;
	float lower, upper, step;

	lower = -20;   /* Lower limit fo temp scale */
	upper = 150; /* Upper limit */
	step = 20;   /* Step size */

	celsius = lower;
	printf("    °C  °F\n");
	while (celsius <= upper) {
		fahr = 9.0 * celsius /5.0 +32.0;
		printf("%6.1f %3.0f\n", celsius, fahr);
		celsius = celsius + step;
	}
}

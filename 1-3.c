/* Temperature conversion program with heading above the table */

#include <stdio.h>

main() {
	float fahr, celsius;
	float lower, upper, step;

	lower = 0;   /* Lower limit fo temp scale */
	upper = 300; /* Upper limit */
	step = 20;   /* Step size */

	fahr = lower;
	printf(" °F     °C\n");
	while (fahr <= upper) {
		celsius = (5.0/9.0) * (fahr-32.0);
		printf("%3.0f %6.1f\n", fahr, celsius);
		fahr = fahr + step;
	}
}

/* Temperature conversion program with heading above the table and using functions */

#include <stdio.h>

float fahr_to_celsius(float fahr);

main() {
	float fahr, celsius;
	float lower, upper, step;

	lower = 0;   /* Lower limit fo temp scale */
	upper = 300; /* Upper limit */
	step = 20;   /* Step size */

	fahr = lower;
	printf(" °F     °C\n");
	while (fahr <= upper) {
		celsius = fahr_to_celsius(fahr); 
		printf("%3.0f %6.1f\n", fahr, celsius);
		fahr = fahr + step;
	}
}

float fahr_to_celsius(float fahr) {
	return (5.0/9.0) * (fahr-32.0);
}

#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define LDR_PIN 29  // GPIO 27
#define R_PIN   23  // GPIO 13 | Red Led pin
#define Y_PIN   24  // GPIO 19 | Yellow Led pin
#define G_PIN   25  // GPIO 26 | Green Led pin
	
uint32_t lightLevel (int pin) {
	uint32_t reading = 0;
	pinMode (LDR_PIN, OUTPUT);
	digitalWrite (LDR_PIN, LOW);
	delay (1000);
	
	pinMode (LDR_PIN, INPUT);
	
	while (digitalRead (LDR_PIN) == LOW) {
		reading++;
	}
    return reading;
}

int main (void) {

    if (wiringPiSetup () == -1) {
        exit (1);
    }

    pinMode (R_PIN, OUTPUT);
    pinMode (Y_PIN, OUTPUT);
    pinMode (G_PIN, OUTPUT);

    uint32_t reading;
    while (TRUE) {
        reading = lightLevel(LDR_PIN);
        if (reading < 1000) {
            digitalWrite (G_PIN, HIGH);
            digitalWrite (R_PIN, LOW);
            digitalWrite (Y_PIN, LOW);
        }
        else if (reading > 8000) {
            digitalWrite (G_PIN, LOW);
            digitalWrite (R_PIN, LOW);
            digitalWrite (Y_PIN, HIGH);
        }
        else {
            digitalWrite (G_PIN, LOW);
            digitalWrite (R_PIN, HIGH);
            digitalWrite (Y_PIN, LOW);
        }
        printf ("%u\n", reading);
    }
    return 0;
}

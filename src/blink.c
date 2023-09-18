// device = atmega328
/*
 * The following program just keeps toggling pin 0 of port B
 */

#include <avr/io.h>     // Standard include for AVR
#include <util/delay.h> // Delay functions

#define F_CPU 16000000UL // Crystal frequency required for delay functions

/* _BV(a) is a macro which returns the value corresponding to 2 to the power
 * 'a'. Thus _BV(PX3) would be 0x08 or 0b00001000. */

int main()
{
  DDRB = 0xff;  // PORTB as OUTPUT
  PORTB = 0x00; // All pins of PORTB LOW

  while (1) // Infinite loop
  {
    _delay_ms(1000);   // Delay for 500 ms
    PORTB ^= _BV(PB0); // toggle bit - using bitwise XOR operator
  }

  return 0;
}

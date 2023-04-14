/**
 * @file
 * @author Mariusz Chilmon <mariusz.chilmon@ctm.gdynia.pl>
 * @date 2023
 * 
 * Pętla główna.
 */

#include "lcd.hpp"
#include "timer.hpp"

#include <stdlib.h>

/**
 * Alfabet fonetyczny NATO.
 */
const char* NATO_PHONETIC_ALPHABET[] = {
	"Alfa", "Bravo", "Charlie", "Delta", "Echo", "Foxtrot", "Golf", "Hotel",
	"India", "Juliett", "Kilo", "Lima", "Mike", "November", "Oscar", "Papa",
	"Quebec", "Romeo", "Sierra", "Tango", "Uniform", "Victor", "Whiskey",
	"Xray", "Yankee", "Zulu",
};

/**
 * Wyświetlenie komunikatu powitalnego.
 */
static void lcdSplash(const Lcd& lcd)
{
	lcd.clear();
	lcd.goTo(0, 0);
	lcd.write("AMW Embedded Lab");
}

/**
 * Wyświetlanie kolejnych słów z alfatu fonetycznego.
 */
static void lcdRefresh(const Lcd& lcd)
{
	static uint8_t code;

	lcd.goTo(1, 0);
	lcd.write(NATO_PHONETIC_ALPHABET[code]);

	if (++code >= sizeof(NATO_PHONETIC_ALPHABET) / sizeof(NATO_PHONETIC_ALPHABET[0])) {
		code = 0;
	}
}

/**
 * Funkcja główna.
 */
int main()
{
	const Lcd lcd;
	const SystemTick tick;

	lcd.init();
	tick.init();
	lcdSplash(lcd);

	while (true) {
		if (tick.checkAndClear()) {
			lcdRefresh(lcd);
		}
	}

	return EXIT_SUCCESS;
}
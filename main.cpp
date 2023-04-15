/**
 * @file
 * @author Mariusz Chilmon <mariusz.chilmon@ctm.gdynia.pl>
 * @date 2023
 * 
 * Pętla główna.
 */

#include "lcd.hpp"
#include "timer.hpp"
#include "thermometer.hpp"

#include <stdlib.h>

/**
 * Wyświetlenie komunikatu powitalnego.
 */
static void lcdSplash(const Lcd& lcd)
{
	lcd.clear();
	lcd.write("Initializing...");
}

/**
 * Wyświetlanie kolejnych słów z alfatu fonetycznego.
 */
static void lcdRefresh(const Lcd& lcd)
{
	const Thermometer thermometer{};

	lcd.goTo(0, 0);

	if (!thermometer.detect()) {
		lcd.write("1-Wire Error :( ");
		return;
	}

	lcd.write("Thermometer OK  ");
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
/**
 * @file
 * @author Mariusz Chilmon <mariusz.chilmon@ctm.gdynia.pl>
 * @date 2023
 *
 * Sterownik termometru.
 */

#pragma once

/**
 * Sterownik termometru.
 */
struct Thermometer {
	/**
	 * Sprawdza, czy wykryto jakieś urządzenie na magistrali.
	 * 
	 * @return Czy wykryto jakiekolwiek urządzenie?
	 */
	bool detect() const;
};

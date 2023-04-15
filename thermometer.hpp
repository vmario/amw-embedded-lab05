/**
 * @file
 * @author Mariusz Chilmon <mariusz.chilmon@ctm.gdynia.pl>
 * @date 2023
 *
 * Sterownik termometru.
 */

#pragma once

#include <stdint.h>

/**
 * Unikalny identyfikator termometru.
 */
struct RomCode {
	uint8_t familyCode; ///< Kod rodziny DS18B20 (0x28).
	uint8_t serialNumber[6]; ///< Numer seryjny.
	uint8_t crc; ///< Suma kontrolna.
};

/**
 * Sterownik termometru.
 */
struct Thermometer {
	/**
	 * Resetuje magistralę komunikacyjną.
	 * 
	 * @return Czy wykryto jakiekolwiek urządzenie?
	 */
	bool reset() const;
	
	/**
	 * Odczytuje identyfikator.
	 * 
	 * @return Odczytana ramka identyfikatora.
	 */
	RomCode romCode() const;
};

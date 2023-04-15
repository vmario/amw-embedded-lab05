/**
 * @file
 * @author Mariusz Chilmon <mariusz.chilmon@ctm.gdynia.pl>
 * @date 2023
 *
 * Sterownik magistrali 1-Wire.
 */

#pragma once

/**
 * Sterownik magistrali 1-Wire.
 */
struct Wire1 {
	/**
	 * Wystawia bit na magistrali.
	 * 
	 * @param bit Bit "0" lub "1".
	 */
	void writeBit(bool bit) const;
	
	/**
	 * Odczytuje bit z magistrali.
	 * 
	 * @return Odczytany bit.
	 */
	bool readBit() const;
	
	/**
	 * Resetuje magistralę.
	 * 
	 * @return Czy ktokolwiek potwierdził reset?
	 */
	bool reset() const;
};

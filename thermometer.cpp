/**
 * @file
 * @author Mariusz Chilmon <mariusz.chilmon@ctm.gdynia.pl>
 * @date 2023
 *
 * Implementacja sterownika termometru.
 */

#include "thermometer.hpp"

#include "1wire.hpp"

bool Thermometer::detect() const
{
	return Wire1{}.reset();
}

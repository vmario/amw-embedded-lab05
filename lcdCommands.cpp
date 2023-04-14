/**
 * @file
 * @author Mariusz Chilmon <mariusz.chilmon@ctm.gdynia.pl>
 * @date 2023
 * 
 * Implementacja komend sterujących wyświetlaczem.
 */

#include "lcdCommands.hpp"

void CommandClear::write() const
{
	command.write();
}

void CommandEntryMode::write() const
{
	command.write();
}

void CommandDisplayControl::write() const
{
	command.write();
}

void CommandFunctionSet::write() const
{
	command.write();
}

void CommandSetDdramAddress::write() const
{
	command.write();
}

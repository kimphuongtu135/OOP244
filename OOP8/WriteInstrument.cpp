#include "WriteInstrument.h"

sdds::WriteInstrument::~WriteInstrument()
{
}

void sdds::WriteInstrument::write(const char*)
{
}

void sdds::WriteInstrument::refill(int)
{
}

bool sdds::WriteInstrument::filled() const
{
	return false;
}

ostream& sdds::WriteInstrument::display(ostream& os) const
{
	// TODO: insert return statement here
	return os;
}

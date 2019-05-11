#include "pch.h"
#include "Out.h"

Out::Out(const string& filename)
{
	out.open(filename);
}

Out::~Out()
{
	out.close();
}

Out &Out::operator<<(ostream &(*pfun)(ostream &)) {
	pfun(out);
	pfun(cout);

	return *this;
}

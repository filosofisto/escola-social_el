#pragma once

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Out
{
public:
	explicit Out(const string& filename);
	virtual ~Out();

	Out& operator<<(ostream& (*pfun)(ostream&));

	ofstream out;
};

template <class T>
inline Out& operator<<(Out& stream, T val)
{
	cout << val;
	stream.out << val;

	return stream;
}


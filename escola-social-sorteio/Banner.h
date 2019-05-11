#pragma once

#include <iostream>
#include "Out.h"

using namespace std;

class Banner
{
public:
	Banner(Out& out);
	~Banner();

	void show() const;
private:
	Out& out;
};


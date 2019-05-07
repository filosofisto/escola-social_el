#pragma once

#include "ParamsValidationException.h"
#include "FileNotFoundException.h"
#include "IOHelper.h"

class ParamsValidator
{
public:
	ParamsValidator();
	virtual ~ParamsValidator();

	void valid(int argc, char **argv) const;
};


#include "pch.h"
#include "ParamsValidator.h"


ParamsValidator::ParamsValidator()
{

}


ParamsValidator::~ParamsValidator()
{

}

void ParamsValidator::valid(int argc, char ** argv) const
{
	if (argc != 2) {
		throw ParamsValidationException();
	}

	if (!IOHelper::exist(argv[1])) {
		throw FileNotFoundException();
	}
}

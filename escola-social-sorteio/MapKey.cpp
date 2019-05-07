#include "pch.h"
#include "MapKey.h"


MapKey::MapKey(const string & categoria, const string & areaCapacitacao):
	categoria(categoria), areaCapacitacao(areaCapacitacao)
{
}

MapKey::~MapKey()
{
}

string MapKey::toString() const
{
	stringstream ss;
	ss << categoria << "_" << areaCapacitacao;
	
	return ss.str();
}

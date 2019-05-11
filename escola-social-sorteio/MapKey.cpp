#include "pch.h"
#include "MapKey.h"


MapKey::MapKey(const string& capacitacao, const string& categoria):
	capacitacao(capacitacao), categoria(categoria)
{
}

MapKey::~MapKey()
{
}

string MapKey::toString() const
{
	stringstream ss;
	ss << capacitacao << "/" << categoria;
	
	return ss.str();
}

string MapKey::getCapacitacao() const
{
	return capacitacao;
}

string MapKey::getCategoria() const
{
	return categoria;
}

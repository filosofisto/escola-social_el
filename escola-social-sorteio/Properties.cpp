#include "pch.h"
#include "Properties.h"

Properties::Properties(const string& filename): filename(filename)
{
}

Properties::Properties(const Properties& orig): filename(orig.filename)
{
}

Properties::~Properties()
{
}

void Properties::load()
{
	if (!IOHelper::exist(filename.c_str())) {
		char msg[2048];
		snprintf(msg, 2048, "Arquivo %s nao encontrado", filename.c_str());
		string s_msg(msg);
		throw IOException(s_msg.c_str());
	}

	string line;
	char *key;
	char *value;

	ifstream is(filename.c_str());

	while (getline(is, line)) {
		key = strtok_s(const_cast<char*>(line.c_str()), "= \t\n", nullptr);
		value = strtok_s(NULL, "= \t\n", nullptr);

		// Commented line starts with #
		if (key != NULL && strlen(key) > 0 && string(key).substr(0, 1) != "#") {
			values.insert(pair<string, string>(string(key), string(value)));
		}
	}

	is.close();
}

string Properties::get(const string & key) const
{
	map<string, string>::const_iterator it = values.find(key);
	if (it != values.end()) {
		return (*it).second;
	}

	return string();
}

bool Properties::has(const string & key) const
{
	map<string, string>::const_iterator it = values.find(key);

	return it != values.end();
}

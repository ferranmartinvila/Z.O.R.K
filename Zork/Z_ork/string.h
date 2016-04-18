#ifndef _string_
#define _string_
#include "dinamic_array.h"
class string{

public:
	char* STR = nullptr;
	unsigned int max_capacity;
	string();
	string(const char*cadena);
	string(const string& copy);
	~string();


	unsigned int lenght()const;
	const char*c_str()const;
	bool empty()const;
	bool operator ==(const string& string);
	bool operator ==(const char* string);
	void operator +=(const char*string);//es suma a si mateix amb una cadena
	void operator +=(const string& string);//es suma a si mateix amb una class cadena
	char* operator +(const char*string)const;//resultat now sumant cadena 
	char* operator +(const string& string)const;//resultat now sumant class cadena
	void operator =(const char*string);//operator = //es modifica igualant a class cadena
	void operator =(const string& string);//es modifica igualnt a class cadena
	bool operator!=(const char* string);
	bool operator !=(const string&string);

	void memory_size(unsigned int);
};
vector<string> tokenize(char*);//separa l'ordre
#endif
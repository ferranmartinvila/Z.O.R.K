#include"dinamic_array.h"
#ifndef _cadena_
#define _cadena_
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
	
	void memory_size(unsigned int);
};
vector<string> tokenize(char*);//separa l'ordre
#endif
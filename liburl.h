#ifndef	liburl
#define liburl
#define CURL_STATICLIB
#include <iostream>
#include <fstream>
#include <string>
#include <curl/curl.h>
#include "json.hpp"
#include <vector>

using json = nlohmann::json;
static size_t getResponsetoString(void* contents, size_t size, size_t nmemb, void* userp);
class Massiv
{
	std::string Name;
	int Epoch;
	std::string Version;
	std::string Release;
	std::string Arch;
	std::string Disttag;
	int Buildtime;
	std::string Source;
public:
	Massiv(const std::string &name,
	int epoch, 
	const std::string &version,
	const std::string &release,
	const std::string &arch,
	const std::string &disttag,
	int buildtime,
	const std::string &source);
	Massiv(const Massiv& x);
	void putdata();
	bool operator==(const Massiv&m);
	bool Ifsmall(const Massiv& s);
};
void Jonson(std::string& str, std::vector<Massiv*>& m, int &t);
void Curl(std::string& str);
void Fortemp(std::string& sstr, int& t);
void Pars1(std::vector<Massiv*>&d1,std::vector<Massiv*>&d2,std::vector<Massiv*>&res1);
void Pars2(std::vector<Massiv*>&d11,std::vector<Massiv*>&d22,std::vector<Massiv*>&res2);
void ParsBigger(std::vector<Massiv*>&d1,std::vector<Massiv*>&d2,std::vector<Massiv*>&res3);
#endif
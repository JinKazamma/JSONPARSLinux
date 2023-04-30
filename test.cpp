#define CURL_STATICLIB
#include <iostream>
#include <fstream>
#include <string>
#include <curl/curl.h>
#include "json.hpp"
#include <vector>
using namespace std;
static size_t getResponsetoString(void* contents, size_t size, size_t nmemb, void* userp)
{
	((string*)userp)->append((char*)contents, size * nmemb);
	return size * nmemb;
}
int main()
{
string str;
char adress[500];
	static int stat = 1;
	CURL* curl;
	CURLcode response;
	//cout << "vvedite adress " << stat << " "; cin >> adress;
	curl = curl_easy_init();
	curl_easy_setopt(curl, CURLOPT_URL, "https://rdb.altlinux.org/api/export/branch_binary_packages/p9"); //
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, getResponsetoString);
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, &str);
	response = curl_easy_perform(curl);
	curl_easy_cleanup(curl);
    //if (str.empty())
	if (response)  cout << str << endl;
    else cout << curl_easy_strerror(response) << endl;
return 0;
}
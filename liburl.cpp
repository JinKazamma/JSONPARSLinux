#include "liburl.h"

using json = nlohmann::json;
static size_t getResponsetoString(void* contents, size_t size, size_t nmemb, void* userp)
{
	((std::string*)userp)->append((char*)contents, size * nmemb);
	return size * nmemb;
}
Massiv::Massiv(const std::string &name,
	int epoch, 
	const std::string &version,
	const std::string &release,
	const std::string &arch,
	const std::string &disttag,
	int buildtime,
	const std::string &source) :
		Name(name),
		Epoch(epoch), 
		Version(version), 
		Release(release), 
		Arch(arch), 
		Disttag(disttag), 
		Buildtime(buildtime), 
		Source(source) {};
Massiv::Massiv(const Massiv& x)
{
	Name = x.Name;
	Epoch = x.Epoch;
	Version = x.Version;
	Release = x.Release;
	Arch = x.Arch;
	Disttag = x.Disttag;
	Buildtime = x.Buildtime;
	Source = x.Source;
};
void Massiv::putdata()
{
	std::cout << "{\"name\": "<<"\""<< Name <<"\", "
				<< "\"epoch\": " << "\""<<Epoch<<"\", "
				<< "\"tversion\": "<< "\""<<Version<<"\", "
				<< "\"release\" "<< "\""<<Release <<"\", "
				<< "\"arch\" " <<"\""<<Arch <<"\", "
				<< "\"disttag\" "<<"\""<<Disttag<<"\", "
				<< "\"buildtime\" " << "\""<<Buildtime <<"\", "
				<< "\"source\" " << "\""<<Source<<"\"}, " << std::endl;
};
bool Massiv::operator==(const Massiv& m)
{
	return (Name == m.Name && Epoch == m.Epoch && Version == m.Version && Release == m.Release && Arch == m.Arch && Disttag == m.Disttag && Buildtime == m.Buildtime && Source == m.Source);
};
bool Massiv::Ifbig(const Massiv&s)
{
	return (Version > s.Version && Release > s.Release);
}
bool Massiv::Ifsmall(const Massiv& s)
{
	return (Version < s.Version && Release < s.Release);
}
void Jonson(std::string& str, std::vector<Massiv*>& m, int t)
{
	json responseJson = json::parse(str);
	json object = responseJson["packages"];

	for (int i = 0; i < t - 2; i++)
	{
		m.push_back(new Massiv(object[i]["name"], object[i]["epoch"], object[i]["version"], object[i]["release"], object[i]["arch"], object[i]["disttag"], object[i]["buildtime"], object[i]["source"]));
	};
}
void Curl(std::string& str)
{
	char adress[500];
	static int stat = 1;
	CURL* curl;
	CURLcode response;
	std::cout << "vvedite adress " << stat << " "; std::cin >> adress;
	curl = curl_easy_init();
	curl_easy_setopt(curl, CURLOPT_URL, adress);
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, getResponsetoString);
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, &str);
	response = curl_easy_perform(curl);
	curl_easy_cleanup(curl);
	stat++;
}
void Fortemp(std::string& sstr, int& t)
{
	for (int u = 0; u < sstr.size() - 1; u++)
	{
		if (sstr[u] == '{')
		{
			t++;
		}
	}
}
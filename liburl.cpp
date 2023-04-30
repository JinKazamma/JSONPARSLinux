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
	std::cout 	<< "{\"name\": "		<< "\""<<Name		<<"\", "
				<< "\"epoch\": " 		<< "\""<<Epoch		<<"\", "
				<< "\"version\": "		<< "\""<<Version	<<"\", "
				<< "\"release\": "		<< "\""<<Release 	<<"\", "
				<< "\"arch\": " 		<< "\""<<Arch		<<"\", "
				<< "\"disttag\": "		<< "\""<<Disttag	<<"\", "
				<< "\"buildtime\": " 	<< "\""<<Buildtime	<<"\", "
				<< "\"source\": " 		<< "\""<<Source		<<"\"}";
};
bool Massiv::operator==(const Massiv& m)
{
	return (Name == m.Name && Epoch == m.Epoch && Version == m.Version && Release == m.Release && Arch == m.Arch && Disttag == m.Disttag && Buildtime == m.Buildtime && Source == m.Source);
};

bool Massiv::Ifsmall(const Massiv& s)
{
	return (Version <= s.Version && Release <= s.Release);
}
void Jonson(std::string& str, std::vector<Massiv*>& m, int &t)
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
	std::string count[2]={"первый","второй"};
	char adress[500];
	static int stat = 0;
	CURL* curl;
	CURLcode response;
	std::cout << "Введите " <<count[stat]<< " адресс "; std::cin >> adress;
	curl = curl_easy_init();
	curl_easy_setopt(curl, CURLOPT_URL, adress);
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, getResponsetoString);
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, &str);
	response = curl_easy_perform(curl);
	curl_easy_cleanup(curl);
	stat++;
	if (str.empty())
	{
		std::cout<< "ОШИБКА! Адресс не считался!"<<std::endl;
		exit(EXIT_FAILURE);
	}
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
void Pars1(std::vector<Massiv*>&d1,std::vector<Massiv*>&d2,std::vector<Massiv*>&res1)
{
	for (int i = 0; i < d1.size(); i++)
	{
		for (int j = 0; j < d2.size(); j++)
		{
			if (*d1[i] == *d2[j])
			{
				break;
			}
			if (j == d2.size() - 1)
			{
				res1.push_back(new Massiv(*d1[i]));
			}
		}
	}
}
void Pars2(std::vector<Massiv*>&d11,std::vector<Massiv*>&d22,std::vector<Massiv*>&res2)
{
	for (int i = 0; i < d22.size(); i++)
	{
		for (int j = 0; j < d11.size(); j++)
		{
			if (*d22[i] == *d11[j])
			{
				break;
			}
			if (j == d11.size() - 1)
			{
				res2.push_back(new Massiv(*d22[i]));
			}
		}
	}
}
void ParsBigger(std::vector<Massiv*>&d111,std::vector<Massiv*>&d222,std::vector<Massiv*>&res3)
{
	for (int i = 0; i < d111.size(); i++)
	{
		for (int j = 0; j < d222.size(); j++)
		{
			if (d111[i]->Ifsmall(*d222[j]))
			{
				break;
			}		
			if (j == d222.size() - 1)
			{
				res3.push_back(new Massiv(*d111[i]));
			}
		}
	}
}

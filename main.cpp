#include "liburl.h"
using namespace std;
int main()
{
	string adress;
	string adress2;
	int kolichestvoElementov = 0;
	int kolichestvoElementov2 = 0;
	vector <Massiv*> objectDannyh1;
	vector <Massiv*> objectDannyh2;
	vector <Massiv*> dannie1NoNet2;
	vector <Massiv*> dannie2NoNet1;
	vector <Massiv*> versionReleasEstV1bolshe2;
	Curl(adress);
	Curl(adress2);
	Fortemp(adress, kolichestvoElementov);
	Fortemp(adress2, kolichestvoElementov2);
	Jonson(adress, objectDannyh1, kolichestvoElementov);
	Jonson(adress2, objectDannyh2, kolichestvoElementov2);
	for (int i = 0; i < objectDannyh1.size(); i++)
	{
		for (int j = 0; j < objectDannyh2.size(); j++)
		{
			if (*objectDannyh1[i] == *objectDannyh2[j])
			{
				break;
			}
			if (j == objectDannyh2.size() - 1)
			{
				dannie1NoNet2.push_back(new Massiv(*objectDannyh1[i]));
			}
		}
	}
	for (int i = 0; i < objectDannyh2.size(); i++)
	{
		for (int j = 0; j < objectDannyh1.size(); j++)
		{
			if (*objectDannyh2[i] == *objectDannyh1[j])
			{
				break;
			}
			if (j == objectDannyh1.size() - 1)
			{
				dannie2NoNet1.push_back(new Massiv(*objectDannyh2[i]));
			}
		}
	}
	for (int i = 0; i < objectDannyh1.size(); i++)
	{
		for (int j = 0; j < objectDannyh2.size(); j++)
		{
			if (objectDannyh1[i]->Ifsmall(*objectDannyh2[j]))
			{
				break;
			}		
			if (j == objectDannyh2.size() - 1)
			{
				versionReleasEstV1bolshe2.push_back(new Massiv(*objectDannyh1[i]));
			}
		}
	}
	cout<<"{\"Packeg 1 has\":[";
	for (int i = 0; i < dannie1NoNet2.size(); i++)
	{
		dannie1NoNet2[i]->putdata();
		if (i!=dannie1NoNet2.size()-1)
		cout<<", ";
	}cout<<"]}";
	cout<<"{\"Packeg 2 has\":[";
	for (int i = 0; i < dannie2NoNet1.size(); i++)
	{
		dannie2NoNet1[i]->putdata();
		if (i!=dannie2NoNet1.size()-1)
		cout<<", ";
	}cout<<"]}";
	cout<<"{\"version releas 1 bigger\":[";
	for (int i = 0; i < versionReleasEstV1bolshe2.size(); i++)
	{
		versionReleasEstV1bolshe2[i]->putdata();
		if (i!=versionReleasEstV1bolshe2.size()-1)
		cout<<", ";
	}cout<<"]}"<<endl;


	return 0;
}
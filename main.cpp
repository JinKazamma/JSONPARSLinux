#include "liburl.h"
using namespace std;
int main()
{
	string adress;
	string adress2;
	int counterForNumberOfElements = 0;
	int counterForNumberOfElements2 = 0;
	vector <Massiv*> DataFor1stObject;
	vector <Massiv*> DataFor2ndObject;
	vector <Massiv*> DataHas1ObjectNotHas2;
	vector <Massiv*> DataHas2ObjectNotHas1;
	vector <Massiv*> versionReleasEstIn1biggerThan2;
	Curl(adress);
	Curl(adress2);
	Fortemp(adress, counterForNumberOfElements);
	Fortemp(adress2, counterForNumberOfElements2);
	Jonson(adress, DataFor1stObject, counterForNumberOfElements);
	Jonson(adress2, DataFor2ndObject, counterForNumberOfElements2);
	for (int i = 0; i < DataFor1stObject.size(); i++)
	{
		for (int j = 0; j < DataFor2ndObject.size(); j++)
		{
			if (*DataFor1stObject[i] == *DataFor2ndObject[j])
			{
				break;
			}
			if (j == DataFor2ndObject.size() - 1)
			{
				DataHas1ObjectNotHas2.push_back(new Massiv(*DataFor1stObject[i]));
			}
		}
	}
	for (int i = 0; i < DataFor2ndObject.size(); i++)
	{
		for (int j = 0; j < DataFor1stObject.size(); j++)
		{
			if (*DataFor2ndObject[i] == *DataFor1stObject[j])
			{
				break;
			}
			if (j == DataFor1stObject.size() - 1)
			{
				DataHas2ObjectNotHas1.push_back(new Massiv(*DataFor2ndObject[i]));
			}
		}
	}
	for (int i = 0; i < DataFor1stObject.size(); i++)
	{
		for (int j = 0; j < DataFor2ndObject.size(); j++)
		{
			if (DataFor1stObject[i]->Ifsmall(*DataFor2ndObject[j]))
			{
				break;
			}		
			if (j == DataFor2ndObject.size() - 1)
			{
				versionReleasEstIn1biggerThan2.push_back(new Massiv(*DataFor1stObject[i]));
			}
		}
	}
	cout<<"{\"Packeg 1 has\":[";
	for (int i = 0; i < DataHas1ObjectNotHas2.size(); i++)
	{
		DataHas1ObjectNotHas2[i]->putdata();
		if (i!=DataHas1ObjectNotHas2.size()-1)
		cout<<", ";
	}cout<<"]}";
	cout<<"{\"Packeg 2 has\":[";
	for (int i = 0; i < DataHas2ObjectNotHas1.size(); i++)
	{
		DataHas2ObjectNotHas1[i]->putdata();
		if (i!=DataHas2ObjectNotHas1.size()-1)
		cout<<", ";
	}cout<<"]}";
	cout<<"{\"version releas 1 bigger\":[";
	for (int i = 0; i < versionReleasEstIn1biggerThan2.size(); i++)
	{
		versionReleasEstIn1biggerThan2[i]->putdata();
		if (i!=versionReleasEstIn1biggerThan2.size()-1)
		cout<<", ";
	}cout<<"]}"<<endl;


	return 0;
}
#include "liburl.h"
#include <thread>
using namespace std;
void showObjData(vector<Massiv*>&obj)
{
for (int i = 0; i < obj.size(); i++)
	{
		obj[i]->putdata();
		if (i!=obj.size()-1)
		cout<<", ";
	}
}
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
	vector <Massiv*> versionReleasIn1biggerThan2;
	Curl(adress);
	Curl(adress2);
	Fortemp(adress, counterForNumberOfElements);
	Fortemp(adress2, counterForNumberOfElements2);
	Jonson(adress, DataFor1stObject, counterForNumberOfElements);
	Jonson(adress2, DataFor2ndObject, counterForNumberOfElements2);
	auto start = chrono::high_resolution_clock::now();
	thread t1(Pars1,::ref(DataFor1stObject),::ref(DataFor2ndObject),::ref(DataHas1ObjectNotHas2));
	thread t2(Pars2,::ref(DataFor1stObject),::ref(DataFor2ndObject),::ref(DataHas2ObjectNotHas1));
	thread t3(ParsBigger,::ref(DataFor1stObject),::ref(DataFor2ndObject),::ref(versionReleasIn1biggerThan2));
	t1.join();
	t2.join();
	t3.join();
	// Pars1(DataFor1stObject,DataFor2ndObject,DataHas1ObjectNotHas2);
	// Pars2(DataFor1stObject,DataFor2ndObject,DataHas2ObjectNotHas1);
	// ParsBigger(DataFor1stObject,DataFor2ndObject,versionReleasIn1biggerThan2);
	cout<<"{\"Packeg 1 has\":["; showObjData(DataHas1ObjectNotHas2);cout<<"]}";
	cout<<"{\"Packeg 2 has\":["; showObjData(DataHas2ObjectNotHas1);cout<<"]}";
	cout<<"{\"version release 1 bigger\":[";showObjData(versionReleasIn1biggerThan2);cout<<"]}"<<endl;
	auto end = chrono::high_resolution_clock::now();
	chrono::duration<float> duration = end - start;
	cout<<"duration "<<duration.count()<<endl;
	return 0;
}
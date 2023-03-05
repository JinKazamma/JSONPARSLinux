#include "liburl.h"
using namespace std;
int main()
{
	string stroka;
	string stroka2;
	int temp = 0;
	int temp2 = 0;
	vector <Massiv*> mass1;
	vector <Massiv*> mass2;
	vector <Massiv*> mass3;
	vector <Massiv*> mass4;
	vector <Massiv*> mass5;
	Curl(stroka);
	Curl(stroka2);
	Fortemp(stroka, temp);
	Fortemp(stroka2, temp2);
	Jonson(stroka, mass1, temp);
	Jonson(stroka2, mass2, temp2);
	cout << temp << endl;
	cout << temp2 << endl;
	for (int i = 0; i < mass1.size(); i++)
	{
		for (int j = 0; j < mass2.size(); j++)
		{
			if (*mass1[i] == *mass2[j])
			{
				break;
			}
			if (j == mass2.size() - 1)
			{
				mass3.push_back(new Massiv(*mass1[i]));
			}
		}
	}
	for (int i = 0; i < mass2.size(); i++)
	{
		for (int j = 0; j < mass1.size(); j++)
		{
			if (*mass2[i] == *mass1[j])
			{
				break;
			}
			if (j == mass1.size() - 1)
			{
				mass4.push_back(new Massiv(*mass2[i]));
			}
		}
	}
	bool flag = false;
	for (int i = 0; i < mass1.size(); i++)
	{
		for (int j = 0; j < mass2.size(); j++)
		{
			if (mass1[i]->Ifsmall(*mass2[j]))
			{
				break;
			}
			if (mass1[i]->Ifbig(*mass2[j]))
			{
				flag = true;
			}
			else 
				flag = false;
		
			if (j == mass2.size() - 1 && flag == true)
			{
				mass5.push_back(new Massiv(*mass1[i]));
			}
		}
	}
	cout<<"{\"Packeg 1 has\":[";
	for (int i = 0; i < mass3.size(); i++)
	{
		mass3[i]->putdata();
		if (i!=mass3.size()-1)
		cout<<", ";
	}cout<<"]}";
	cout<<"{\"Packeg 2 has\":[";
	for (int i = 0; i < mass4.size(); i++)
	{
		mass4[i]->putdata();
		if (i!=mass3.size()-1)
		cout<<", ";
	}cout<<"]}";
	cout<<"{\"version releas 1 bigger\":[";
	for (int i = 0; i < mass5.size(); i++)
	{
		mass5[i]->putdata();
		if (i!=mass3.size()-1)
		cout<<", ";
	}
	return 0;cout<<"]}";
}
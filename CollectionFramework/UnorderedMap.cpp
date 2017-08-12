#include<iostream>
#include<conio.h>
#include<string>
#include<unordered_map> 

using namespace std;

void display(unordered_map<string,int> &tm)
{
	for (auto key : tm)
	{
		cout << "Key: "<<key.first <<"\tValue : " << tm[key.first] << endl;
	}
	cout << endl;
}

int main() 
{
	// Create a hash map.
	unordered_map<string,int> hm;
	// Put elements into the map
	hm["Mason"] = 55;
	hm["Jacob"] = 77;
	hm["William"] = 99;
	hm["Alexander"] = 80;
	hm["Michael"] = 50;
	hm["Emma"] = 65;
	hm["Olivia"] = 77;
	hm["Sophia"] = 88;
	hm["Emily"] = 99;
	hm["Isabella"] = 100;
	
	cout << "Total number of students in class: " << hm.size() << endl;
	display(hm);
	/*
	for (auto key : hm)
	{
		cout << "Key: "<<key.first << ("\tValue: ") << hm[key.first] << endl;
	}
	*/
	/*
	auto temp = hm.find("Emma") != hm.end();
	cout << "Emma present in class: " << temp << endl;
	auto result = hm.find("John") != hm.end();
	cout <<"John present in class: " << result << endl;
	*/
	
	return 0; 
}

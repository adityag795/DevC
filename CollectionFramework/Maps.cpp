#include<iostream>
#include<conio.h>
#include<string>
#include<map>

using namespace std;

void display(map<string,int> &tm)
{
	for (auto key : tm)
	{
		cout << "Key: "<<key.first <<"\tValue : " << tm[key.first] << endl;
	}
	cout << endl;
}

int main() 
{
	map<string,int> bar;
	bar["AA"]=11;
	bar["BB"]=22;
	bar["CC"]=33;

	// Create a hash map.
	map<string,int> tm;
	// Create an iterator.
	map<string,int>::iterator it;
	// Put elements into the map
	string key;
	int val;

	tm["Mason"] = 55; 
	tm["Jacob"] = 77; 
	tm["Jacob"] = 77; 
	tm["William"] = 99;
	tm["Alexander"] = 80;
	tm["Michael"] = 50;
	tm["Emma"] = 65;
	tm["Olivia"] = 77;
	tm["Sophia"] = 88;
	tm["Emily"] = 99;
	tm["Isabella"] = 100;
	
	cout <<"\nTotal number of students in class : " << tm.size() << endl;
	
	cout<<"1. Insert\n";
	cout<<"2. Erase\n";
	cout<<"3. Swap\n";
	cout<<"4. Clear\n";
	cout<<"5. Emplace\n";
	cout<<"6. Find\n";
	cout<<"7. Check if a key is an element of Dictionary/Map\n";
	cout<<"8. Display Dictionary/Map\n";
	cout<<"9. Find number of elements\n";

	int ch;
	cout<<"\nEnter your choice: ";
	cin>>ch;
	switch(ch)
	{
		case 1:
			cout<<"\nEnter the Key: ";
			cin>>key;
			cout<<"\nEnter the value: ";
			cin>>val;
			tm[key] = val;
			display(tm);
			break;
		case 2:
			cout<<"\nEnter the corresponding key of value which has to be erased?";
			cin>>key;
			it = tm.find(key);
			tm.erase(it);
			cout<<"\nAfter erasing, values in Dictionary are: "<<endl;
			display(tm);
			break;
		case 3:
			tm.swap(bar);
			cout<<"\nAfter swapping, values in Dictionary are: "<<endl;
			display(tm);
			break;
		case 4:
			tm.clear();
			cout<<"\nAfter clear, values in Dictionary are: ";
			display(tm);
			break;
		case 5:
			cout<<"\nEnter the Key: ";
			cin>>key;
			cout<<"\nEnter the value: ";
			cin>>val;
			tm.emplace(key,val);
			cout<<"\nAfter emplace, values in Dictionary are: "<<endl;
			display(tm);
			break;
		case 6:
			cout<<"\nEnter the Key: ";
			cin>>key;
			it = tm.find(key);
			if (it != tm.end())
				cout<<"Key: "<<it->first<<"\tValue: "<<it->second;
			else
				cout<<"Key not found.";
			break;
		case 7:
			cout<<"\nEnter the Key: ";
			cin>>key;
			if (tm.count(key)>0)
				cout<<endl<<key<<" is an element of Map/Dictionary.";
			else
				cout<<endl<<key<<" is not an element of Map/Dictionary.";
			break;
		case 8:
			cout<<"\nValues in Dictionary are: "<<endl;
			display(tm);
			break;
		case 9:
			cout<<"\nSize of Dictionary is "<<tm.size();
			break;
		default:cout<<"\nEnter correct choice: ";
	}

	/*
	auto temp = tm.find("Emma") != tm.end();
	cout << "\nEmma present in class : " << temp << endl;
	auto result = tm.find("John") != tm.end();
	cout << "\nJohn present in class : " << result << endl;
	*/	
	return 0;
}

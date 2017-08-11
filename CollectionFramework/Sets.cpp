#include<iostream>
#include<conio.h>
#include<string>
#include<set> 

using namespace std;

void display(set<string> &ts)
{
	for each (auto var in ts)
	{
		cout << var << " ";
	}
	cout << endl;
}

int main() 
{
	string str;
	// Create a hash set. 
	set<string> ts;
	set<string> gt;
	set<string>::iterator it;
	it = ts.begin();
	int pos;

	// Add elements to the hash set.
	ts.insert("India");
	ts.insert("USA");
	ts.insert("Brazil");
	ts.insert("Canada");
	ts.insert("UK");
	ts.insert("China");
	ts.insert("France");
	ts.insert("Spain");
	ts.insert("Italy");
	
	// Add elements to the hash set.
	gt.insert("Toronto");
	gt.insert("Quebec");
	gt.insert("Singapore");
	gt.insert("Shanghai");
	gt.insert("Stockholm");
	gt.insert("Pune");
	gt.insert("Paris");
	gt.insert("Montreal");

	// cout << endl;
	// cout << "Hash Table contains USA : " << (find(ts.begin(), ts.end(), "USA") != ts.end()) << endl;
	// cout << "Hash Table contains Russia : " << (find(ts.begin(), ts.end(), "Russia") != ts.end()) << endl;
	// ts.erase("USA");
	// for each (auto var in ts)
	// {
	// 	cout << var << " ";
	// }
	// cout << endl;
	// cout << "Hash Table contains USA : " << (find(ts.begin(),ts.end(),"USA") != ts.end()) << endl;
	
	cout<<"1. Insert\n";
	cout<<"2. Erase\n";
	cout<<"3. Swap\n";
	cout<<"4. Clear\n";
	cout<<"5. Emplace\n";
	cout<<"6. Display Set\n";

	int ch;
	cout<<"\nEnter your choice: ";
	cin>>ch;
	switch(ch)
	{
		case 1:
			cout<<"\nEnter any country's name: ";
			cin>>str;
			ts.insert(str);
			cout<<"\nValues in set after insertion: ";
			display(ts);
			break;
		case 2:
			cout<<"\nEnter the country's name to be removed: ";
			cin>>str;
			it = ts.find(str);
			if (it != ts.end()) // If iterator can't find value, it returns an iterator to set::end.
			{
				ts.erase(it);
				cout<<"After erasing "<<str<<", valuse in set are: ";
				display(ts);
			}
			else
			{
				cout<<endl<<str<<" is not present in the set.";
			}
			break;
		case 3:
			ts.swap(gt);
			cout<<"\nAfter swapping: ";
			display(ts);
			break;
		case 4:
			ts.clear();
			cout<<"\nAfter clear operation, values in set are: ";
			display(ts);
			break;
		case 5:
			cout<<"\nEnter any country's name: ";
			cin>>str;
			ts.emplace(str);
			cout<<"\nValues in set after emplace: ";
			display(ts);
			break;
		case 6:
			cout<<"\nSet contains: ";
			display(ts);
			break;
		default:cout<<"\nEnter correct choice: ";
	}

	return 0; 
}

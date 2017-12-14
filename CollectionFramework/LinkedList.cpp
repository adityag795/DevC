#include<iostream>
#include<conio.h>
#include<list> 

using namespace std;

void display(list<int>& ll)
{
    cout<< "Contents of Linked List: ";
	for(auto var:ll) 
		cout<< var << " ";
	cout<<endl;
}

int main() 
{
	int num,pos;
	int x = 0, y = 0;

	list<int> ll;
    list<int>::iterator it, it1, it2;
	it = it1 = it2 = ll.begin();
	
	list<int> eva;
	
	ll.push_front(1);
	ll.push_back(11);
	ll.push_front(2);
	ll.push_back(21);
	ll.push_front(3);
	ll.push_back(31);
	
	cout<<"1. Display ALL elements.\n";
    cout<<"2. Display FIRST element.\n";
    cout<<"3. Display LAST element.\n";
    cout<<"4. Add element at the end.\n";
    cout<<"5. Add element at the front.\n";
	cout<<"6. Delete last element.\n";
	cout<<"7. Delete first element.\n";
    cout<<"8. Insert\n";
    cout<<"9. Erase\n";
    cout<<"10. Swap\n";
	cout<<"11. Reverse\n";
    cout<<"12. Clear\n";
    cout<<"\nEnter your choice(1-9): ";
    
	int ch;
    cin>>ch;
    switch (ch)
    {
		case 1:
			display(ll);
			break;
		case 2:
			cout<<"Element at front: "<<ll.front();
			break;
		case 3:
			cout<<"Element at back: "<<ll.back();
			break;
		case 4:
			cout<<"Enter the value to be inserted: ";
            cin>>num;
            ll.push_back(num);
            display(ll);
			break;
		case 5:
			cout<<"Enter the value to be inserted: ";
            cin>>num;
            ll.push_front(num);
            display(ll);
			break;
		case 6:
			ll.pop_back();
            display(ll);
			break;
		case 7:
			ll.pop_front();
            display(ll);
			break;
		case 8:
			cout<<"\nEnter the value to be inserted: ";
            cin>>num;
            cout<<"\nEnter the position at which you want to insert: ";
            cin>>pos;
            
			while(x<pos)
			{
				it++;x++;				
			}
			ll.insert(it,num);
            display(ll);
		
			break;
		case 9:
			cout<<"\n1. Erase one element.";
            cout<<"\n2. Erase over a range.";
            cout<<"\nEnter choice(1,2): ";
            int er;
            cin>>er;
            switch(er)
            {
                case 1:
                    int pos;
                    cout<<"\nEnter the position at which value to be deleted: ";
                    cin>>pos;
					while(x<pos)
					{
						it++;x++;				
					}
					it = ll.erase(it);
                    display(ll);
                    break;
                case 2:
                    int l,r;
                    cout<<"\nEnter the range [x,y): ";
                    cin>> l>> r;
                    
					while(x<l)
					{
						it1++;x++;				
					}

					while(y<r)
					{
						it2++;y++;				
					}
					
					ll.erase(it1,it2);
                    display(ll);
                    break;
                default:cout<<"\nPlease enter correct choice(1,2): ";
            }
		
			break;
		case 10:
			for(int i = 90; i < 100; i++)
            {
                eva.push_back(i);    // Add element at the end
            }     
            eva.swap(ll);
            display(ll);
		
			break;
		case 11:
			ll.reverse();
			display(ll);
			break;
		case 12:
			ll.clear();
            display(ll);

			break;
		default:cout<<"\nPlease enter correct choice(1-9): ";
	}
	
	return 0; 
}
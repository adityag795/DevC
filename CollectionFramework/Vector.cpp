#include<iostream>
#include<conio.h>
#include<vector>
using namespace std;

void display(vector<int> &vec)
{
    int count = vec.size();  // Return size
    cout<<"\nValues stored are: ";
    for(int i = 0; i < count; i++)
    {
        cout<<" "<<vec[i];
    } 
}

int main()
{
    vector<int> vec;
    vector<int> eva;
    int num,pos;
    for(int i = 0; i < 10; i++)
    {
        vec.push_back(i);    // Add element at the end
    }
    vector<int>::iterator it;
    it = vec.begin();
    cout<<"1. Display ALL elements.\n";
    cout<<"2. Display FIRST element.\n";
    cout<<"3. Display LAST element.\n";
    cout<<"4. Add element at the end.\n";
    cout<<"5. Delete last element.\n";
    cout<<"6. Insert\n";
    cout<<"7. Erase\n";
    cout<<"8. Swap\n";
    cout<<"9. Clear\n";
    cout<<"\nEnter your choice(1-9): ";
    int ch;
    cin>>ch;
    switch (ch)
    {
        case 1:
            display(vec);
            break;
        case 2:
            cout<<"Element at front: "<<vec.front();
            break;
        case 3:
            cout<<"Element at back: "<<vec.back();
            break;
        case 4:
            cout<<"Enter the value to be inserted: ";
            cin>>num;
            vec.push_back(num);
            display(vec);
            break;
        case 5:
            vec.pop_back();
            display(vec);
            break;
        case 6:            
            cout<<"\nEnter the value to be inserted: ";
            cin>>num;
            cout<<"\nEnter the position at which you want to insert: ";
            cin>>pos;
            vec.insert(it+pos,num);
            display(vec);
            break;
        case 7:
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
                    vec.erase(vec.begin()+pos);
                    display(vec);
                    break;
                case 2:
                    int l,r;
                    cout<<"\nEnter the range [x,y): ";
                    cin>> l>> r;
                    vec.erase(vec.begin()+l,vec.begin()+r);
                    display(vec);
                    break;
                default:cout<<"\nPlease enter correct choice(1,2): ";
            }
            break;
        case 8:
            for(int i = 90; i < 100; i++)
            {
                eva.push_back(i);    // Add element at the end
            }     
            eva.swap(vec);
            display(vec);
            break;
        case 9:
            vec.clear();
            display(vec);
            break;
        default:cout<<"\nPlease enter correct choice(1-9): ";
    }

    return 0;
}

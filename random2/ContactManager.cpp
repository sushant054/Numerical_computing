#include "ContactManager.hpp"
using namespace std;

ContactManager::ContactManager(){
    cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++";
cout<<"\n Welcome to Contact Manager";
cout<<"\n Author : Sushant";
cout<<"\n Version : vo.1";
cout<<"\n Release date: 24 feb. 2024\n";
    cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++";

}

void ContactManager::add(ulong number,string email, string title, string name)
{
    info temp;
    temp.name=name;
    temp.number=number;
    temp.email=email;
    temp.title=title;
    data.push_back(temp);
}
void ContactManager::list()
{
for (int i=0; i < data.size(); i++)

cout <<"\ntitle:"<<data[i].title<< "\nName::"<< data[i].name<<"\nPhone Number::"<<data[i].number<<"\nemail::"<<data[i].email <<endl;
}
/**
 * @brief//function to edit contact info...
 * 
*/
void ContactManager::edit()
{
//show list users in the sys
list();

//ask user to select which users is to be edited
cout<<"\n select user to edit::";

int id;
cin>>id;

//ask details
cout<<"\n Enter New Name ::";
cin>>data[id-1].name;
cout<<"\n Enter New Number ::";
cin>>data[id-1].number;
cout<<"\n Enter New Email ::";
cin>>data[id-1].name;
cout<<"\n Enter New Title ::";
cin>>data[id-1].title;

cout<<"Edited list:";

list();
}


void ContactManager::editPhoneNumber()
{
list();
//ask user to select which user's number..to be edited
cout<<"\n select user to edit phone number::";
int id;
cin>>id;
cout<<"\n Enter New Number ::";
cin>>data[id-1].number;
cout<<"Edited list::";
list();
}

void ContactManager::editName()
{
    list();
//ask user to select which user's number..to be edited
cout<<"\n select user to edit Name::";
int id;
cin>>id;
cout<<"\n Enter New Name ::";
cin>>data[id-1].name;
cout<<"Edited list::";
list();
}

void ContactManager::editEmail()
{
list();
//ask user to select which user's number..to be edited
cout<<"\n select user to edit Name::";
int id;
cin>>id;
cout<<"\n Enter New Email ::";
cin>>data[id-1].email;
cout<<"Edited list::";
list();
}


void ContactManager::removeUser()
{
    list();  
    int id;
    cout << "Enter the ID of the user you want to remove: ";
    cin >> id;
    // Erase the user from the vector
    data.erase(data.begin() + id - 1);
    cout << "User removed!!!!\n";
    cout<<"now remaining list is :";
    list();

}

void ContactManager::removeUserName()
{
  
}



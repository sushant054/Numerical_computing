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
list();
//ask user to select which user's number..to be edited
cout<<"\n select user to remove Name::";
int id;
cin>>id;
data[id-1].name=" ";
cout<<"user name removed succes...";
cout<<"Edited list::";
list();
}

void ContactManager::removeUserNumber()
{
list();
//ask user to select which user's number..to be edited
cout<<"\n select user to remove Number::";
int id;
cin>>id;
data[id-1].number= 0;
cout<<"user number removed succes...";
cout<<"Edited list::";
list();
}

void ContactManager::removeUserEmail()
{
list();
//ask user to select which user's number..to be edited
cout<<"\n select user to remove Email::";
int id;
cin>>id;
data[id-1].email=" ";
cout<<"user email removed succes...";
cout<<"Edited list::";
list();
}


void ContactManager::searchName()
{
    cout << "Enter the name you want to search for: ";
    string searchName;
    cin >> searchName;

    bool found = false;
    for (size_t i = 0; i < data.size(); ++i) {
        if (data[i].name == searchName) {
            found = true;
            cout << "\nTitle: " << data[i].title << "\nName: " << data[i].name << "\nPhone Number: " << data[i].number << "\nEmail: " << data[i].email << endl;
        }
    }

    if (!found) {
        cout << "No name found!!!.\n";
    }
}

void ContactManager::searchEmail()
{
    cout << "Enter the number you want to search for: ";
    string searchEmail;
    cin >> searchEmail;

    bool found = false;
    for (size_t i = 0; i < data.size(); ++i) {
        if (data[i].email == searchEmail) {
            found = true;
            cout << "\nTitle: " << data[i].title << "\nName: " << data[i].name << "\nPhone Number: " << data[i].number << "\nEmail: " << data[i].email << endl;
        }
    }

    if (!found) {
        cout << "No Email found!!!.\n";
    }
}


void ContactManager::backUp()
{
    ofstream outFile("backup.txt");
     if (outFile.is_open()) 
     {
        for (const auto& entry : data) 
        {
            outFile << entry.title << "," << entry.name << "," << entry.number << "," << entry.email << endl;
        }
        outFile.close();
        cout << "Backup created successfully!\n";
    } else 
    {
        cout << "Unable to create backup file!\n";
    }
}

void ContactManager::restore()
{
    

}






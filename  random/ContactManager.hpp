#include<bits/stdc++.h>//it contains all other hedder files
using namespace std;
struct data
{
    string firstName;
    string lastName;
    string email;
    //unsigned long;
    ulong number;
};
class ContactManager
{
public:
    ContactManager();
    ContactManager(string , string, ulong, string);
   // ContactManager(std::string,std::string,ulong,std::string);
    //memve function to add,edit,list,delete
    void Add(string ,string , ulong ,string );
    void ListAllContacts();
    //void Display();
    //struct data info;
    vector<struct data> info;//vector is similar to a array...(array int arr[])incase of vector(vector<datatype>arr)....
 
   
};
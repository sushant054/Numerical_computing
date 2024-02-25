#include"ContactManager.hpp"
using namespace std;
ContactManager::ContactManager()
{
//     cout<<"\n in Default const..\n";
//     firstName="";
//     lastName="";
//     number =0;
//     email="";

}
// ContactManager::ContactManager(string firstName,string lastName,ulong number,string email)
// {
//     this->firstName =firstName;
//     // firstName = fN;
//      this->lastName=lastName;;
//       this->number=number;
//        this->email=email;
// }
// void ContactManager::Display(){
//     cout<<"first Name::"<<firstName<<endl<<"\t lastName::"<<lastName<<endl<<"\t number::"<<number<<endl
//     <<"\t email::"<<email<<endl;
// }
// void ContactManager::Display(){


// }
 
void ContactManager::Add(string fName,string lName, ulong number,string email){
    struct data tmp;
    tmp.firstName=fName;
      tmp.lastName=lName;
        tmp.number=number;
          tmp.email=email;
        info.push_back(tmp);
}

void ContactManager::ListAllContacts()
{
    for(int i=0;i<info.size();++i)
    {
        cout<<"First Name::"<<info[i].firstName<<endl<<"\t Last Name::"<<info[i].lastName<<endl<<"number::"<<info[i].number<<endl<<"email::"<<info[i].email<<endl;
    }
}
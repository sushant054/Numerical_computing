#include"ContactManager.hpp"
using namespace std;
int main()
{
    ContactManager cm;
    cm.add(1234567890,"sushh@gmail.com","Mr.","sushh");
    cm.add(1234567890,"goooo@gmail.com","Mr.","go");
    cm.list();
    cm.edit();
    cm.editPhoneNumber();
    cm.editName();
    cm.editEmail();
    cm.removeUser();
    cm.removeUserName();
    cm.removeUserNumber();
    cm.removeUserEmail();
    cm.searchName();
    cm.searchNumber();
    cm.searchEmail();
    cm.backUp();
    return 0;
}
 

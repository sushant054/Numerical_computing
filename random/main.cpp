#include"ContactManager.hpp"
using namespace std;
int main()
{
// ContactManager c;//default constructor
// //param. const
// ContactManager c1("sushh","nalage",1234567890,"sushh@gmail.com");

// c.Display();
// c1.Display();
ContactManager CM;
CM.Add("sushh","nalage",1234567890,"sushh@mail");
CM.Add("dfg","nde",1234567890,"dffghh@mail");
CM.Add("fg","sfge",1234567890,"sdg@mail");
CM.ListAllContacts();
return 0;
}

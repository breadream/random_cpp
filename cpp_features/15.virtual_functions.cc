/* A virtual function; a member function declared within base class
 * and is re-defined by derived class. */
#include<iostream>
using namespace std;

class base
{
public:
    virtual void print ()
    { cout<< "print base class" <<endl; }

    void show ()
    { cout<< "show base class" <<endl; }
};

class derived:public base
{
public:
    void print ()
    { cout<< "print derived class" <<endl; }

    void show ()
    { cout<< "show derived class" <<endl; }
};

int main()
{
    base *bptr;
    derived d;
    bptr = &d;

    //virtual function, binded at runtime
    bptr->print();
	//since print() function is declared with virtual keyword so it will be binded at run-time

    // Non-virtual function, binded at compile time
    bptr->show();
}


// if a class contains a virtual funcito then compiler itself does two things
// 1. if an object is created, then a virtual pointer (VPTR) is inserted as a data member
// of the class to point to VTABLE of that class. 
// -> for each new object is created, a new VPTR is inserted as a data member of that class
// 2. Regardless of the existence of object, a static array of cuntion pointer (VTABLE)
// where each cell contains the address of each virtual function contained in that class 

// A friend class can access private and protected members of other class
// in which it is declared as friend.



class Node
{
private:
  int key;
  Node *next;
  /* Other members of Node Class */

  friend class LinkedList; // Now class  LinkedList can
                           // access private members of Node
};




#include <iostream>

class A
{
    int a;
public:
    A() {a = 0;}
    friend void showA(A&); // global friend function
};

void showA(A& x) {
    // Since showA() is a friend, it can access
    // private members of A
    std::cout << "A::a=" << x.a;
}

int main()
{
    A a;
    showA(a);
    return 0;
}


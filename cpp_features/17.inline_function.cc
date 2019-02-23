/* Inline Function is used to reduce the overhead of the function
 * 
 * When the program executes the function call instruction the CPU 
 * stores the memory address of the instruction following the function call, 
 * copies the arguments of the function on the stack and finally transfers 
 * control to the specified function. 
 * The CPU then executes the function code, stores the function return value 
 * in a predefined memory location/register and returns control to the calling function. 
 *
 * This can become "overhead" if the 'execution time of function' is LESS than 
 * 'the switching time' from the caller function to called function (callee)
 * */

#include <iostream> 
using namespace std; 
class operation 
{ 
    int a,b,add,sub,mul; 
    float div; 
public: 
    void get(); 
    void sum(); 
    void difference(); 
    void product(); 
    void division(); 
}; 
inline void operation :: get() 
{ 
    cout << "Enter first value:"; 
    cin >> a; 
    cout << "Enter second value:"; 
    cin >> b; 
} 
  
inline void operation :: sum() 
{ 
    add = a+b; 
    cout << "Addition of two numbers: " << a+b << "\n"; 
} 
  
inline void operation :: difference() 
{ 
    sub = a-b; 
    cout << "Difference of two numbers: " << a-b << "\n"; 
} 
  
inline void operation :: product() 
{ 
    mul = a*b; 
    cout << "Product of two numbers: " << a*b << "\n"; 
} 
  
inline void operation ::division() 
{ 
    div=a/b; 
    cout<<"Division of two numbers: "<<a/b<<"\n" ; 
} 
  
int main() 
{ 
    cout << "Program using inline function\n"; 
    operation s; 
    s.get(); 
    s.sum(); 
    s.difference(); 
    s.product(); 
    s.division(); 
    return 0; 
}

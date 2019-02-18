/* Overloading -> achieved at compile time 
 * - multiple definitions of the function by changing 
 *   its parameters' number or datatype */ 
void test(int);
void test(float);
void test(int, float);

// Method 1
void test(int var)
{
    cout << "Integer number: " << var << endl;
}

// Method 2
void test(float var)
{
    cout << "Float number: "<< var << endl;
}

// Method 3
void test(int var1, float var2)
{
    cout << "Integer number: " << var1;
    cout << " and float number:" << var2;
}



/* Overriding -> achieved at run time
 * same signature e.g. return type and parameters */

Class a
{
public:
      virtual void display(){ cout << "hello"; }
}

Class b:public a
{
public:
       void display(){ cout << "bye";};
}


/* Overloading VS Overriding 
 * 1. Inheritance; Overriding occurs when one class is inherited from another class 
 * 					-> this is why it is achieved at run time
 * 				   Overloading occurs w/o inheritance 
 *
 * 2. Function Signature; Overloaded functions must differ in function signatures 
 * 						  Overrided functions must have the same function signatures
 *
 * 3. Scope of functions: Overriden functions -> in different scopes
 * 						  Overloaded functions -> same scope
 *
 * 4. Behavior of functions: Overriding is needed when derived class function has to do
 * 							 different job than the base class function
 * 							 Overloading is used to have same name functions which behave
 * 							 differently depending upon parameters passed to them
 *
 * 						  */


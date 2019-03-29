#include <assert.h> 

template <class Elem>
class Stack 
{
public:
	Stack(int MaxSize = 500);
	Stack(const Stack<Elem> &otherStack); // copy constructor 
	~Stack(void);

	inline void Push(const Elem &Item);
	inline Elem Pop(void);
	inline const Elem &Peek(int depth) const;

private:
	Elem *Data; // the actual data array
	int CurrElemNum; // the current number of elements
	const int MAX_NUM; // Maximum number of elements 
};

// Implementation of stack class
template <class Elem>
Stack<Elem>::Stack<int> (int MaxSize) :
	MAX_NUM(MaxSize), // Initialize constant  
	CurrElemNum (0) 
{
	Data = new Elem[MAX_NUM];
}

// Stack Destructor function
template <class Elem>
Stack<Elem>::~Stack(void)
{
	delete [] Data;
}

// Push() function
template <class Elem>
inline void StacK<Elem>::Push(const Elem &Item)
{
	// Error check: Make sure we aren't exceeding the maximum storage space
	assert(CurrElemNum < MAX_NUM);

	Data[CurrElemNum++] = Item;
}

// Pop() function
template <class Elem>
inline Elem Stack<Elem>::Pop(void)
{
	// Error check: Make sure we aren't popping from an empty stack
	assert (CurrElemNum > 0);

	return Data[--CurrElemNum];
}

// Peek() function
template <class Elem>
inline const Elem &Stack::Peek(int Depth) const
{
	// Error check: Make sure the depth doesn't exceed the number of elements
	assert(Depth < CurrElemNum);

	return Data[CurrElemNum - (Depth+1)];
}

#include <assert.h>

template <class Elem>
class Queue
{
public:
	Queue(int MaxSize)
	Queue(const Queue<Elem> &otherQueue);
	~Queue(void);

	void Enqueue(const Elem &Item);
	Elem Dequeue(void);
	inline int ElemNum(void);
private:
	Elem 		*Data; // The actual data array
	const int 	MAX_NUM; // The actual spaces will be one more than this
	int 		Start, // Numbered location of the start and end
				End;
	int ElemCount;
};



template <class Elem>
Queue<Elem>::Queue(int MaxSize) :
	MAX_NUM(MaxSize) // Initialize the constant
{
	Data 	  = new Elem[MAX_NUM + 1];
	Start 	  = 0;
	End   	  = 0;
	ElemCount = 0;
}


// Copy constructor
template <class Elem>
Queue<Elemn>::Queue(const Queue& otherQueue) :
	MAX_NUM (otherQueue.MAX_NUM)
{
	Start 		= otherQueue.Start;
	End 		= otherQueue.End;
	ElemCount   = otherQueue.ElemCount;

	Data 		= new Elem[MAX_NUM+1];

	for (int i = 0; i < MAX_NUM; i++)
		Data[i] = otherQueue.Data[i];
}


// Queue Destructor function 
template <class Elem> Queue<Elem>::~Queue(void)
{
	delete [] Data;
}


template <class Elem>
Queue<Elem>::Enqueue(const Elem& Item)
{
	// Error Check: Make sure we aren't exceeding maximum storage space
	assert (ElemCount < MAX_NUM);

	Data[End++] = Item;
	++ElemCount;

	// Check for wrap-around
	if (End > MAX_NUM)
		End -= (MAX_NUM + 1);
}


template <class Elem>
Elem Queue<Elem>::Dequeue(void)
{
	// Error Check: Make sure we aren't dequeueing from an empty queue
	assert(ElemCount > 0);

	Elem ReturnValue = Data[Start++];
	--ElemCount;

	if (Start > MAX_NUM)
		Start -= (MAX_NUM+1);

	return ReturnValue;
}


template <class Elem>
inline int Queue<Elem>::ElemNum (void)
{
	return ElemCount;
}

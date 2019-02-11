/* from https://m.blog.naver.com/sorkelf/220825930008 
 * in advance, use emplace_back 
 * in C++0x instead of unncessary copy, we can move within memory 
 * by R-value reference
 * L-value -> an object that persists beyond a single expression 
 * R-value -> temporary value that does not persists beyond the expression that uses it 
 * Reference using '&' is technically L-value reference 
 * R-value reference uses '&&' */


// L-Reference should reference L-value
// R-Reference should reference R-value
int nCount;
int& LrefVal1 = nCount; // okay
int& LrefVal2 = 10; 	// error

int&& RrefVal1 = 10; 	// okay
int&& RrefVal2 = nCount;// error


/* if we use move constructor, we can 'move' an object from other object
 * if it is not implemented, copy constructor and assignment operator have
 * higher priority. 
 * Move semantics are applied to all STL in C++0x 
 * */

class Car 
{
public:
	// copy Contructor 
	Car (const Car& car) : name(new char[car.nameLen]), nameLen(car.nameLen)
	{
		memcpy(name, car.name, car.NameLen);
	}

	// copy assignment contructor 
	Car& operator=(const Car& car)
	{
		if (this != &car) // this pointer accesses its (object) own address 
		{
			if (nameLen < car.nameLen)
			{
				// secure the buffer
			}
			nameLen = car.nameLen;
			memcpy(name, car.name, nameLen);
		}
		return *this;
	}
	
	// move contructor
	Car(Car&& car) : name(car.name), nameLen (car.nameLen)
	{
		car.name = nullptr;
		car.nameLen = 0;
	}
	
	// move assignment constructor 
	Car& operator=(Car&& car)
	{
		if (this != &car)
		{
			delete name;
			name = car.name;
			nameLen = car.nameLen;
			car.name = nullptr;
			car.nameLen = 0;
		}
		return *this;
	}

private:
	char* name;
	int nameLen;

}

/* why there would be performance improvement
 * move semantics 'move' on memory instead of copying */

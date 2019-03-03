#pragma once 
template<typename T, typename U>
class MyPair
{
public:
	const T& GetFirst() const;
	const U& GetSecond() const;
	MyPair (const T& first, const U& second);

private:
	T mFirst;
	U mSecond;
};

template<typename T, typename U>
const T& MyPair<T, U>::GetFirst() const
{
	return mFirst;
}

template<typename T, typename U>
const T& MyPair<T, U>::GetSecond() const
{
	return mSecond;
}

template<typename T, typename U>
MyPair<T, U>::MyPair(const T& first, const U& second)
	: mFirst(first)
	, mSecond(second)
{
}


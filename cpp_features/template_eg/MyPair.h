template<typename T>
class MyPair
{
public:
	const T& GetFirst() const;
	const T& GetSecond() const;
	MyPair (const T& first, const T& second);

private:
	T mFirst;
	T mSecond;
};

template<typename T>
const T& MyPair<T>::GetFirst() const
{
	return mFirst;
}

template<typename T>
const T& MyPair<T>::GetSecond() const
{
	return mSecond;
}

template<typename T>
MyPair<T>::MyPair(const T& first, const T& second)
	: mFirst(first)
	, mSecond(second)
{
}


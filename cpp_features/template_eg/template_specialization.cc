template <typename V, typename EXP>
V Power (const V, EXP e)
{
	V result = 1;
	while (e-- > 0)
		result *= V;
	return result;
}

template<>
float Power (float value, float exp)
{
	return std::powf(value, exp);
}

int main()
{
	int powerResultInt = Power (10, 2);
	int powerResultFloat = Power (10.f, 5.f);
}

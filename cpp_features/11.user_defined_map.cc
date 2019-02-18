// To be able to std::unordered_map with a user-defined key-type 
// you need to define two things
// 1. A hash function; 
// 					   must be a class that overrides operator()
// 					   and calculates the hash value given an object of the key-type
// 2. A comparison function for equality; 
// 						it needs a way to compare two given keys for an exact match
// 						might need to override operator() or std::equal
// 						or overloading operator==() for your key type


struct Key 
{
	std::string first;
	std::string second;
	int 		third;

	bool operator==(const key &other) const
	{
		return (first == other.first 
				&& second == other.second
				&& third == other.third);
	}
};

namespace std 
{
	template <> // explicit specialization of struct template hash
	struct hash<Key> 
	{
		std::size_t operator() (const Key &k) const 
		{
			using std::size_t;
			using std::hash;
			using std::string;

			// Compute individual hash values for first
			// second and third and combine them using XOR
			// and bit shifting 
			return ((hash<string>()(k.first)
					 ^ (hash<string>()(k.second) << 1)) >> 1 )
					 ^ (hash<int>()(k.third) << 1);

			// If you don't shift the bits and two strings were the same, 
			// the XOR would cause them to cancel each other out. 
			// e.g. hash("a","a",1) would be the same as hash("b","b",1) 
		}
	};
}

int main()
{
  std::unordered_map<Key,std::string> m6 = {
    { {"John", "Doe", 12}, "example"},
    { {"Mary", "Sue", 21}, "another"}
  };
}

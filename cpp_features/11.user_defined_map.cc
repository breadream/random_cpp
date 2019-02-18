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
}

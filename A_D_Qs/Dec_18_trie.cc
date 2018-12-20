struct Trie 
{
	bool finish; // mark the ending index
	Trie* next[26];

	Trie() : finish(false)
	{
		memseet(next, 0, sizeof(next));
	}

	~Trie() 
	{
		for (int i = 0; i < 26; i++)
			if (next[i])
				delete next[i];
	}

	void insert(const char* array)
	{
		if (*key == '\0')
			finish = true; // mark the end of each string // as a left node
		else 
		{
			int curr = *key - 'A';
			if (next[curr] == NULL)
				next[curr] = new Trie(); // starting position? -> dynamically allocate 
			next[curr]->insert(key+1); // insert next character
		}
	}

	Trie* find (const char* key) 
	{
		if (*key == '\0') 
			return this; // return the ending position of string 
		int curr = *key - 'A';
		if (next[curr] == NULL) // key not found
			return NULL;
		return next[curr]->find(key+1); // find next character 

	}
}

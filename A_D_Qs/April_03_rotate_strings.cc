bool rotateString(string A, string B) {
	if (A.size() != B.size())
		return false;
	
	if (A.empty() && B.empty())
		return true;
	
	unordered_set <string> set;
	
	for (int j = 0; j < B.size(); j++)
		set.insert(B.substr(j) + B.substr(0, j));
	
	return set.count(A);
}

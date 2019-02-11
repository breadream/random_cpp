/* https://plzrun.tistory.com/entry/ 
 * Suffix Array; An array of suffix sorted by their lexicographical order 
 * e.g. the suffix of "Apple" 
 * [0] = Apple
 * [1] = pple
 * [2] = ple
 * [3] = le
 * [4] = e
 * 
 * The suffix array for "apple"
 * [0] = Apple
 * [4] = e
 * [3] = le
 * [2] = ple
 * [1] = pple
 *
 * */
// Naive approach to find the suffix array is just to sort suffix in array 
// bruteforce O(N^2 * lg N)
#include <string>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair <string, int> psi;
vector<int> getSuffix(const string & s) 
{
	int n = s.size();
	vector<psi> v;  // vector of string, int pair
	for (int i = 0; i < n; i++)
		v.emplace_back(psi(s.substr(i), i));
	sort(v.begin(), b.end()); // sorted by v[i].first as the default 
	// but if you want to sort it by its v[i].second
	/*
	 * sort(v.begin(), v.end(),
	 * 		[](const pair<string, int> & a, const pair<string, int> & b) -> bool
	 * 		{
	 * 			return a.second < b.second;
	 * 		});
	 * 	or make a bool function and put it as the last element in sort()
	 * 		*/
	vector<int> ans;
	for (int i = 0; i < n; i++)
		ans.emplace_back(v[i].second);
}

int main ()
{
	ios::sync_with_stdio(false); // speed up by turning off synchronization between cin and stdio
	// Tied streams ensure that one stream is flushed automatically before each I/O operation on the other stream.
	cin.tie(0); // unties cin from cout, 
	string s;
	cin >> s;
	vector<int> suffix = getSuffix(s);
	for (auto x : suffix)
		cout << x << " ";
	return 0;
}

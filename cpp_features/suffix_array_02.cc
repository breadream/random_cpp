/* Suffix Array in O (N * lg N * lg N)
 * it can be done by checking the string in 1, 2, 4, 8, 16...
 * to get its Suffix Array 
 * 
 * Let's groupify string s = "mississipi" by length 1
 * -------------------------------------
 * index	0  1  2  3  4  5  6  7  8  9
 * s[index] m  i  s  s  i  s  s  i  p  i
 * g[index] 2  1  4  4  1  4  4  1  3  1
 * -------------------------------------
 *
 * g[index] is the lexicographic order of each character 
 * e.g. i = 1, m = 2, p = 3, s = 4
 *
 * Let's find g[index] by s.length 2
 * -------------------------------------
 * index	0  1  2  3  4  5  6  7  8  9
 * s[index] m  i  s  s  i  s  s  i  p  i
 * g[index] 4  3  7  6  3  7  6  2  5  1
 * -------------------------------------
 * e.g. 
 * [0]: s[0..1] = mi
 * [1]: s[1..2] = is
 * [2]: s[2..3] = ss 
 * [3]: s[3..4] = si
 * [4]: s[4..5] = is
 * [5]: s[5..6] = ss
 * [6]: s[6..7] = si
 * [7]: s[7..8] = ip
 * [8]: s[8..9] = pi 
 * [9]: s[9..10] = i* (* is the dummy value)
 *
 * [9]: s[9..10] = i* -> first 
 * [7]: s[7..8] = ip  -> second
 * [1]: s[1..2] = is  -> third
 * [4]: s[4..5] = is  -> third
 * [0]: s[0..1] = mi  -> 4th
 * [8]: s[8..9] = pi  -> 5th 
 * [3]: s[3..4] = si  -> 6th
 * [6]: s[6..7] = si  -> 6th
 * [2]: s[2..3] = ss  -> 7th
 * [5]: s[5..6] = ss  -> 7th
 *
 * so.. how can we find the order for substrings of length 4 ?? 
 * let's just see g[index] by s.length 4
 * -------------------------------------
 * index	0  1  2  3  4  5  6  7  8  9
 * s[index] m  i  s  s  i  s  s  i  p  i
 * g[index] 4  3  9  7  3  8  6  2  5  1
 * -------------------------------------
 *
 *
 * In substring length of 2, [2] and [5] have the same substring, 
 * resulting in having same g[index] = 7, g[2] = g[5], since they
 * are the same, in order to determine the order in the substring group
 * of length 4, we need to compare last 2 substring in each substing of 4, 
 * when comparing strings " ss'is' " and " ss'ip' ", we just need to compare
 * already calculated g[index]
 * so if g[x] == g[y] and there's already g[index] for length t,
 * we can simply compare g[x+t] = g[y+t]
 *
 * */
 
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;
//g = group number, new_g = new group number
vector<int> suffix, g, ng;

vector<int> getSuffix(const string &s)
{
	int n = s.size();
	suffix.resize(n); g.resize(n+1); ng.resize(n+1);
	for (int i = 0; i < n; i++)
	{
		suffix[i] = i;
		g[i] = s[i];
	}
	g[n] = -1;

	for (int t = 1; t < n; t <<= 1)
	{
		auto cmp = [&] (int i, int j) {
			if (g[i] == g[j])
				return g[i+t] < g[j+t];
			else 
				return g[i] < g[j];
		};
		sort(suffix.begin(), suffix.end(), cmp);
		new_g[suffix[0]];
		new_g[n] = 1;
		for (int i = 1; i < n; i++)
		{
			if (cmp(suffix[i-1], suffix[i])) 
				new_g[suffix[i]] = ng[suffix[i-1]]+1;
			else
				new_g[suffix[i]] = ng[suffix[i-1]];
		}
		g = ng;
	}
	return suffix;
}

int main()
{
	ios::syn_with_stdio(false);
	cin.tie(0);
	string s;
	cin >> s;
	vector<int> suffix = getSuffix(s);
	for (int i = 0; i < suffix.size(); i++)
		printf("%d ", suffix[i]);
	return 0;
}


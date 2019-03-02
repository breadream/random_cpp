/* Counting sort 
 * O(n+k), where k is the largest value in input array
 * there's no comparison and it's stable
 * but needs extra memory and 
 * is sensitive to the largest number in input array 
 * Counting sort usually is used in getting Suffix Array,
 * which is composed of 26 alphabets */

// Not stable version
//#include <cstdio>
//using namespace std;
//int cnt[6];
//int main() {
//    int n; 
//	scanf("%d", &n);
//    for(int i=1; i<=n; i++) 
//	{
//        int x; 
//		scanf("%d", &x);
//        cnt[x]++;
//    }
//
//    for(int i=1; i<=n; i++) 
//        while(cnt[i]--) 
//			printf("%d ", i);
//    
//    return 0;
//}


/* make cnt array itself also have the meaning of index */
#include <cstdio>
#include <vector>
#include <cassert>
typedef pair<int, int> pii;
vector<int> sort (const vector<int>& v)
{
	int n = v.size();
	vector<int> cumulCnt (n+1, 0);
}
vector<pii> sort (const vector<pii> &v)
{
	int n = v.size();
	vector<pii> ans(n);
	vector<int> cnt(n+1, 0);
	vector<int> idx(n, 0);

	for (int i = 0; i < n; i++) // count the number of v[i].second 
		cnt[v[i].second]++;
	for (int i = 1; i <= n; i++) // accumulate the sum
		cnt[i] += cnt[i-1];
	for (int i = n-1; i >= 0; i--) 
		idx[--cnt[v[i].second]] = i; // store the indices before being sorted 
	// if we want to sort based on v[i].second, then it should be 
	// ans[--cnt[v[i].second]] = v[i].second;

	cnt.clear();
	cnt.resize(n+1, 0);
	for (int i = 0; i < n; i++)
		cnt[v[i].first]++;
	for (int i = 0; i <= i++)
		cnt[i] += cnt[i-1];
	for (int i = n-1; i >= 0; i--)
		ans[--cnt[v[idx[i]].first]] = v[idx[i]]; // sort it based on first

	return ans;
}

int main ()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		assert(x >=1 && x <= n && y >= 1 && y <= n)
		v.push_back(pii(x, y));
	}

	puts("\nAns: ");
	vector<pii> ans = sort(v);
	for (auto &it : ans)
		printf("%d %d\n", it.first, it.second);
	return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

bool search(int n, int num, vector<int>& nlist)
{
	int mid;
	int start = 0;
	int	end = n - 1;
	while(start <= end)
	{
		mid = (start + end) / 2;
		if (num > nlist[mid])
		{
			start = mid + 1;
		}
		else if (num < nlist[mid])
		{
			end = mid - 1;
		}
		else
		{
			return true;
		}
	}
	return false;
}
int main(void)
{
	FastIO;
	int n;
	cin >> n;

	vector<int> nlist(n);
	for (int i = 0; i < n; i++)
		cin >> nlist[i];
	sort(nlist.begin(), nlist.end());

	int m;
	cin >> m;

	int num;
	int start, end, mid;
	
	for (int i = 0; i < m; i++)
	{
		cin >> num;
		if (search(n, num, nlist))
			cout << 1 << "\n";
		else
			cout << 0 << "\n";
	}
}
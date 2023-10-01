#include <iostream>
#include <algorithm>
#include <vector>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

int cutTree(int n, int m, int maxi, vector<int>& treeLen)
{
	unsigned int start = 0;
	unsigned int end = maxi;
	unsigned int mid, sum;

	while (start <= end)
	{
		mid = (start + end) / 2;
		sum = 0;
		for (int i = 0; i < n; i++)
		{
			if (treeLen[i] >= mid)
				sum += (treeLen[i] - mid);
		}

		if (sum < m)
			end = mid - 1;
		else if (sum > m)
			start = mid + 1;
		else
			return mid;
	}
	return 0;
}

int main(void)
{
	FastIO;

	int n, m;
	cin >> n >> m;

	vector<int> treeLen(n);
	for (int i = 0; i < n; i++)
		cin >> treeLen[i];
	int maxi = *max_element(treeLen.begin(), treeLen.end());

	int res = cutTree(n, m, maxi, treeLen);
	cout << res;
}
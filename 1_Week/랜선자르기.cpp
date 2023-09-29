#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define INT_MAX 2147483647
using namespace std;

int GetLan(int l, vector<int>& lan)
{
	int sum = 0;
	for (int i = 0; i < lan.size() - 1; i++)
	{
		sum += lan[i];
	}
	cout << sum << "\n";
	return (sum / l);
}

int PS(int n, int k, vector<int>& lan)
{
	int res = 0;
	int start = 0;
	int end = INT_MAX;

	while (start <= end)
	{
		int mid = (start + end) / 2;
		int cntLan = GetLan(mid, lan);

		if (cntLan < k)
			end = mid - 1;
		else if (cntLan >= k)
		{
			start = mid + 1;	
			res = max(res, start);
		}
	}
	return res;
}
int main(void)
{
	FastIO;

	int n, k;
	cin >> n >> k;

	int sum = 0;
	vector<int> lan(n);
	for (int i = 0; i < n; i++)
	{
		cin >> lan[i];
	}
	int res = PS(n, k, lan);
	cout << res;
}
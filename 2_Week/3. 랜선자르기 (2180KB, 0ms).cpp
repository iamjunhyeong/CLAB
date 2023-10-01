#include <iostream>
#include <algorithm>
#include <vector>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define INT_MAX 2147483647
using namespace std;

int GetLan(int l, vector<int>& lan)
{
	int sum = 0;
	for (int i = 0; i < lan.size(); i++)
	{
		sum += (lan[i] / l);
	}
	return sum;
}

int PS(int n, vector<int>& lan)
{
	unsigned int res = 0;
	unsigned int start = 0;
	unsigned int end = INT_MAX;

	while (start <= end)
	{
		unsigned int mid = (start + end) / 2;
		unsigned int cntLan = GetLan(mid, lan);

		if (cntLan < n)
			end = mid - 1;
		else
		{
			start = mid + 1;	
			res = max(res, mid);
		}
	}
	return res;
}

int main(void)
{
	FastIO;

	int k, n;
	cin >> k >> n;

	int sum = 0;
	vector<int> lan(k);
	for (int i = 0; i < k; i++)
	{
		cin >> lan[i];
	}
	int res = PS(n, lan);
	cout << res;
}
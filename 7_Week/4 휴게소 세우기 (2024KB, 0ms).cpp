#include <algorithm>
#include <iostream>
#include <vector>
#define FastIO                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(nullptr);                 \
	cout.tie(nullptr)
using namespace std;

int n, m, l;
vector<int> v;

void input()
{
	cin >> n >> m >> l;
	v.push_back(0);
	v.push_back(l);
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
}

bool check(int mid)
{
	int cnt = 0;
	for (int i = 1; i < v.size(); i++)
	{
		int dst = v[i] - v[i - 1];
		cnt += dst / mid;
		if (dst % mid == 0)
			cnt--;
	}
	return cnt > m;
}

void solution()
{
	int st = 1, en = l;
	int mid, res;
	while (st <= en)
	{
		mid = (st + en) / 2;
		if (check(mid))
			st = mid + 1;
		else
		{
			res = mid;
			en = mid - 1;
		}
	}
	cout << res;
}

int main()
{
	FastIO;
	input();
	solution();
}

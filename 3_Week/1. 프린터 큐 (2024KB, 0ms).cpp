#include <iostream>
#include <algorithm>
#include <queue>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

int main(void)
{
	FastIO;
	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;

		queue<pair<int, int>> qu;
		priority_queue<int> pqu;
		for (int i = 0; i < n; i++)
		{
			int num;
			cin >> num;
			qu.push(make_pair(num, i));
			pqu.push(num);
		}

		int cnt = 0;
		int maxi = pqu.top();
		while (!qu.empty())
		{
			int val = qu.front().first;
			int ind = qu.front().second;
			qu.pop();
			if (val == maxi)
			{
				cnt++;
				if (ind == m)
					break;
				pqu.pop();
				maxi = pqu.top();
			}
			else
				qu.push(make_pair(val, ind));
		}
		cout << cnt << "\n";
	} 
}
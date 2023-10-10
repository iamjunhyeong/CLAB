#include <iostream>
#include <algorithm>
#include <queue>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

int main(void)
{
	FastIO;
	int n, k;
	cin >> n >> k;

	queue<int> qu;
	for (int i = 0; i < n; i++)
		qu.push(i + 1);
	cout << "<";
	while (qu.size() != 1)
	{
		for (int i = 0; i < k - 1; i++)
		{
			int num = qu.front();
			qu.pop();
			qu.push(num);
		}
		int res = qu.front();
		qu.pop();
		cout << res << ", ";
	}
	cout << qu.front() << ">";
}
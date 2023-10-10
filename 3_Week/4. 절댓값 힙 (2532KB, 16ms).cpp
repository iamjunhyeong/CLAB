#include <iostream>
#include <algorithm>
#include <queue>
#include <cstdlib>
#include <list>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

struct cmp
{
	bool operator()(int a, int b)
	{
		if (abs(a) == abs(b))
			return a > b;
		else
			return abs(a) > abs(b);
	}
};

int main(void)
{
	FastIO;
	int n; cin >> n;

	priority_queue< int, vector<int>, cmp > minH;
	while (n--)
	{
		int s; cin >> s;
		if (s == 0)
		{
			if (minH.empty())
				cout << 0 << "\n";
			else
			{
				cout << minH.top() << "\n";
				minH.pop();
			}
		}
		else
		{
			minH.push(s);
		}
	}
}
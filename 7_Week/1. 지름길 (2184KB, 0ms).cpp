#include <iostream>
#include <vector>
#include <algorithm>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

int n, d;
vector<int> road(10001, 0);

void func(vector<vector<int>>& fastroad)
{
	for (int a = 0; a < n; a++) {
		int start = fastroad[a][0], end = fastroad[a][1], len = fastroad[a][2];

		if (start > d || end > d) continue;

		if (len + road[start] < road[end])
		{
			road[end] = len + road[start];
			for (int i = 1; i + end <= d; i++) {
				road[end + i] = min(road[end + i], road[end] + i);
			}
		}
	}
}

int main()
{
	FastIO;

	cin >> n >> d;
	for (int i = 1; i <= d; i++)
		road[i] = i;
	
	vector<vector<int>> fastroad(n, vector<int>(3));	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> fastroad[i][j];
		}
	}
	sort(fastroad.begin(), fastroad.end());
	func(fastroad);

	cout << road[d];
}


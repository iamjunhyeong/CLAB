#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <utility>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main(void)
{
	FastIO;
	int m, n;
	int a;
	queue<pair<int, int>> qu;

	cin >> m >> n;
	vector<vector<int>> box(n,vector<int>(m,0));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a;
			box[i][j] = a;
		}
	}

	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++) {
			if (box[i][j] == 1)
				qu.push(make_pair(i,j));
		}
	}

	int dx[4] = {1, -1, 0, 0}; 
	int dy[4] = {0, 0, 1, -1};
	int x, y, nx, ny;
	// BFS
	while (!qu.empty())
	{
		x = qu.front().first;
		y = qu.front().second;
		qu.pop();
		for (int i = 0; i < 4; i++)
		{
			nx = x + dx[i];
			ny = y + dy[i];
			if (0 <= ny && ny < m && 0 <= nx && nx < n && box[nx][ny] == 0)
			{
				box[nx][ny] = box[x][y] + 1;
				qu.push(make_pair(nx, ny));
			}
		}
	}
	
	int maxi = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++){
			if (box[i][j] == 0)
			{
				cout << "-1";
				exit(0);
			}
			if (maxi < box[i][j])
				maxi = box[i][j];
		}
	}
	cout << maxi - 1;
}
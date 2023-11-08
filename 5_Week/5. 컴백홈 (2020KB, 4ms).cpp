#include <iostream>
#include <vector>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

// 제껀 왜 4ms가 나올까요,,

int r, c, k;
int cnt = 0;
vector<vector<char>> map(5, vector<char>(5));
vector<vector<bool>> visited(5, vector<bool>(5, false));
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void input()
{
	cin >> r >> c >> k;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> map[i][j];
		}
	}
}

void dfs(int row, int col, int dep)
{
	if (dep == k && row == 0 && col == c - 1) {
		cnt++;
		return;
	}

	for (int i = 0; i < 4; i++) {
		int nx = row + dx[i];
		int ny = col + dy[i];

		if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
		if (map[nx][ny] == 'T') continue;
		if (visited[nx][ny]) continue;
		visited[nx][ny] = true;
		dfs(nx, ny, dep + 1);
		visited[nx][ny] = false;
	}
}

int main() 
{
	FastIO;
	input();
	visited[r - 1][0] = 1;
	dfs(r - 1, 0, 1);
	cout << cnt;
}
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

int n, m;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
void groundInput(vector<vector<int>>& ground, int& x, int& y) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> ground[i][j];
			if (ground[i][j] == 2) {
					x = i;
					y = j;
			}
		}
	}
}

void output(vector<vector<int>>& distanceGround, vector<vector<int>>& inputGround) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (inputGround[i][j] == 0 ) cout << "0 ";
			else cout << distanceGround[i][j] << " ";
		}
		cout << "\n";
	}
}

void bfs(vector<vector<int>>& inputGround, vector<vector<int>>& distanceGround, int x, int y)  {
	queue<pair<int, int>> qu;
	qu.push(make_pair(x, y));
	distanceGround[x][y] = 0;

	while (!qu.empty()) {
		int xx = qu.front().first;
		int yy = qu.front().second;
		qu.pop();

		for (int i = 0; i < 4; i++) {
			int nx = xx + dx[i];
			int ny = yy + dy[i];
			if (0 > nx || nx >= n || 0 > ny || ny >= m) continue;
			if (inputGround[nx][ny] == 0) continue;
			if (distanceGround[nx][ny] != -1) continue;
			distanceGround[nx][ny] = distanceGround[xx][yy] + 1;
			qu.push(make_pair(nx, ny));	
		}
	}
}

int main() {
	FastIO;
	cin >> n >> m;

	vector<vector<int>> inputGround(1001, vector<int>(1001));
	vector<vector<int>> distanceGround(1001, vector<int>(1001, -1));
	int x, y;
	groundInput(inputGround, x, y);
	bfs(inputGround, distanceGround, x, y);
	output(distanceGround, inputGround);
}
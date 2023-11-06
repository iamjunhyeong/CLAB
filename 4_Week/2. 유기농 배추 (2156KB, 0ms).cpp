#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

int m, n, k;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void plantCabbage(vector<vector<int>>& farm, vector<pair<int, int>>& cabbage) {
	for (int i = 0; i < k; i++) {
		int a, b; 
		cin >> b >> a;

		farm[a][b] = 1;
		cabbage.push_back(make_pair(a, b));
	}
}

void bfs(vector<vector<int>>& farm, int a, int b) {
	queue<pair<int, int>> qu;
	qu.push(make_pair(a, b));
	farm[a][b] = 0;

	while (!qu.empty()) {
		int x = qu.front().first;
		int y = qu.front().second;
		qu.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx < n && 0 <= ny && ny < m) {
				if (farm[nx][ny]) {
					qu.push(make_pair(nx, ny));
					farm[nx][ny] = 0;
				}
			}
		}
	}
}

int main() {
	FastIO
	int t; cin >> t;
	while (t--) {
		int cnt = 0;
		cin >> m >> n >> k;
		vector<vector<int>> farm(n, vector<int>(m, 0));
		// for (int i = 0; i < n; i++) {
		// 	for (int j : farm[i])
		// 		co;ut << j << " ";
		// 	cout << "\n";
		// }
		vector<pair<int, int>> cabbage;

		plantCabbage(farm, cabbage);
		for (int i = 0; i < cabbage.size(); i++) {
			int a = cabbage[i].first;
			int b = cabbage[i].second;
			if (farm[a][b]) {
				bfs(farm, a, b);
				cnt++;
			}
		}
		cout << cnt << "\n";
	}
}
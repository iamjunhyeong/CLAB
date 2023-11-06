#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

int n, m;
void input(vector<vector<int>>& linkCpu) {
	for (int i = 0; i < m; i++) {
		int a, b; 
		cin >> a >> b;
		linkCpu[b].push_back(a);
	}
}

int bfs(int s, vector<vector<int>>& linkCpu) {
	queue<int> qu;
	vector<int> visited(n + 1, 0);
	int cnt = 0;
	qu.push(s);
	visited[s] = 1;

	while (!qu.empty()) {
		int a = qu.front();
		qu.pop();
		for (int i : linkCpu[a]) {
			if (!visited[i]) {
				qu.push(i);
				visited[i] = 1;
				cnt++;
			}
		}
	}
	return cnt;
}

int main() {
	FastIO;
	cin >> n >> m;

	vector<vector<int>> linkCpu(n + 1);
	vector<int> hacking(n + 1, 0);
	input(linkCpu);
	for (int i = 1; i <= n; i++) {
		hacking[i] = bfs(i, linkCpu);
	}
	int maxi = *max_element(hacking.begin(), hacking.end());
	for (int i = 1; i <= n; i++)
		if (hacking[i] == maxi)
			cout << i << " ";
}
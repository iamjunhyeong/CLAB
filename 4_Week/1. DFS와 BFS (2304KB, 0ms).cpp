#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

vector<int> stVisited(1001, 0);
void dfs(vector<vector<int>>& graph, int node)
{
	stVisited[node] = 1;
	cout << node << " ";

	sort(graph[node].begin(), graph[node].end());
	for (int i : graph[node]) {
		if (!stVisited[i]) {
			dfs(graph, i);
		}
	}
}

void bfs(vector<vector<int>>& graph, int start, int n)
{
	queue<int> qu;
	qu.push(start);
	vector<int> visited(n + 1, 0);

	visited[start] = 1;
	cout << start << " ";

	while (!qu.empty()) {
		int a = qu.front();
		qu.pop();
		sort(graph[a].begin(), graph[a].end());
		for (int i : graph[a]) {
			if (!visited[i]) {
				qu.push(i);
				cout << i << " ";
				visited[i] = 1;
			}
		}
	}
}

int main(void)
{
	FastIO;
	int n, m, v;
	cin >> n >> m >> v;
	vector<vector<int>> graph(n + 1);

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;

		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	dfs(graph, v);
	cout << "\n";
	bfs(graph, v, n);
}


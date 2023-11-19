#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 20001
#define INF 2147483647
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

int v, e;
int s;
vector<pair<int, int>> graph[MAX];
vector<int> dist(MAX, INF);
void func()
{
	priority_queue<pair<int, int>> qu;
	qu.push(make_pair(0, s));
	while (!qu.empty())
	{
		int cost = qu.top().first;
		int cur = qu.top().second;
		qu.pop();

		for(int i = 0; i < graph[cur].size(); i++) {
			int next = graph[cur][i].first;
			int ncost = graph[cur][i].second;

			if (dist[next] > cost + ncost) {
				dist[next] = cost + ncost;
				qu.push(make_pair(dist[next], next));
			}
		}
	}
}

int main()
{
	FastIO;
	cin >> v >> e;
	cin >> s;

	dist[s] = 0;
	for (int i = 0; i < e; i++) {
		int a, b, w; cin >> a >> b >> w;
		graph[a].push_back(make_pair(b, w));
	}
	func();

	for (int i = 1; i <= v; i++) {
		if (dist[i] == INF) cout << "INF" << "\n";
		else cout << dist[i] << "\n";
	}
}

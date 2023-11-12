#include <iostream>
#include <vector>
#include <algorithm>
#define INTMAX 2147483647
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

int n, m;
vector<int> buf(9, INTMAX);
vector<int> arr(9, 0);
vector<bool> visited(10001, false);
void printVector() {
	for (int i = 0; i < m; i++)
		cout << arr[i] << " ";
	cout << "\n";
}

void dfs(int dep) {
	if (dep == m) {
		printVector();
		return;
	}
	for (int i = 0; i < n; i++) {
		if (visited[buf[i]]) continue;
		visited[buf[i]] = true;
		arr[dep] = buf[i];
		dfs(dep + 1);
		visited[buf[i]] = false;
	}
}		

int main() 
{
	FastIO;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> buf[i];
	sort(buf.begin(), buf.end());
	dfs(0);
}
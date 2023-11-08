#include <iostream>
#include <vector>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

int n, m;
vector<int> arr(9, 0);
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
	for (int i = 1; i <= n; i++) {
		arr[dep] = i;
		dfs(dep + 1);
	}
}		

int main() 
{
	FastIO;
	cin >> n >> m;
	dfs(0);
}
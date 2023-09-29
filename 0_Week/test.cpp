#include <iostream>
#include <vector>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main(void)
{
	FastIO;

	int n;	
	int res = 0;
	int mini;
	cin >> n;
	vector<int> graph(n, 0);
	vector<int> dp(n,0);

	cin >> graph[0];
	dp[0] = graph[0];
	mini = graph[0];
	for (int i = 1; i < n; i++)
	{
		cin >> graph[i];
		if (graph[i - 1] <= graph[i])
		{
			dp[i] = max(graph[i], res);
			dp[i] = max(dp[i], dp[i - 1] + mini);
			res = dp[i];
		}
		else
		{
			dp[i] = max(dp[i - 1], graph[i]);
			mini = graph[i];
		}
	}
	for (int i = 0; i < n; i++)
		cout << i << ":" << dp[i] << "\n";
}
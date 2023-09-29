#include <iostream>
#include <vector>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main(void)
{
	FastIO;
	
	int n;
	int sum = 0;
	int cnt = 0;

	cin >> n;
	vector<int> prime(n + 1, 1);
	vector<int> st;

	prime[0] = 0;
	prime[1] = 0; 
	for (int i = 2; i * i <= n; i++)
	{
		if (prime[i] == 0)
			continue;
		
		for (int j = i + i; j <= n; j += i)
			prime[j] = 0;
	}
	
	int j = 0;
	int flag = 0;
	for (int i = 2; i <= n; i++)
	{
		if (prime[i] == 1)
		{
			flag = 1;
			sum += i;
			st.push_back(i);
		}

		// 보다 커지면 낮은수부터 제거
		while (sum > n)
		{
			flag = 1;
			if (j == st.size())
				break;
			sum -= st[j];
			j++;
		}
		
		if (sum == n && flag == 1)
		{
			cnt++;
			flag = 0;
		}
	}

	cout << cnt;
}
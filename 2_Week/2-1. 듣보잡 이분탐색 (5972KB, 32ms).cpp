#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool search(int n, string num, vector<string>& hear)
{
	int mid;
	int start = 0;
	int	end = n - 1;
	while(start <= end)
	{
		mid = (start + end) / 2;
		if (num > hear[mid])
			start = mid + 1;
		else if (num < hear[mid])
			end = mid - 1;
		else
			return true;
	}
	return false;
}

int main(void)
{
	FastIO;

	int n, m;
	cin >> n >> m;

	vector<string> hear(n);
	for (int i = 0; i < n; ++i)
		cin >> hear[i];
	sort(hear.begin(), hear.end());

	string s;
	vector<string> hearAndWatch;
	for (int i = 0; i < m; i++)
	{
		cin >> s;
		if (search(n,s,hear))
			hearAndWatch.push_back(s);
	}

	sort(hearAndWatch.begin(), hearAndWatch.end());
	cout << hearAndWatch.size() << "\n";
	for (int i = 0; i < hearAndWatch.size(); ++i)
		cout << hearAndWatch[i] << "\n";
}
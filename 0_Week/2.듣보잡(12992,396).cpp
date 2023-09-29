#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main(void)
{
	FastIO;

	int n, m;
	map<string, int> hear;
	map<string, int>::iterator it;
	vector<string> hearAndWatch;
	string s;

	cin >> n >> m;
	for (int i = 0; i < n + m; ++i)
	{
		cin >> s;
		hear[s]++;
	}
	for (it = hear.begin(); it != hear.end(); it++)
	{
		if (it->second > 1)
			hearAndWatch.push_back(it->first);
	}

	sort(hearAndWatch.begin(), hearAndWatch.end());
	cout << hearAndWatch.size() << endl;
	for (int i = 0; i < hearAndWatch.size(); ++i)
		cout << hearAndWatch[i] << endl;
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main(void)
{
	FastIO;

	int n, m;
	cin >> n >> m;

	string s;
	unordered_map<string, int> hear;
	for (int i = 0; i < n; ++i)
	{
		cin >> s;
		hear.insert(make_pair(s,1));
	}	
		
	vector<string> hearAndWatch;
	for (int i = 0; i < m; i++)
	{
		cin >> s;
		if (hear.find(s) != hear.end())
			hearAndWatch.push_back(s);
	}

	sort(hearAndWatch.begin(), hearAndWatch.end());
	cout << hearAndWatch.size() << "\n";
	for (int i = 0; i < hearAndWatch.size(); ++i)
		cout << hearAndWatch[i] << "\n";
}
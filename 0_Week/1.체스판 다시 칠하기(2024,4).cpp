#include <iostream>
#include<vector>
#include<string>
#include<algorithm>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

int WB_check(string s, int j)
{
	FastIO;
	int cnt = 0;
	for (int y = j; y < j + 8; ++y) {
		if (y % 2 == 0) {
			if (s[y] != 'W')
				++cnt;
		} 
		else {
			if (s[y] != 'B')
				++cnt;
		}
	}
	return cnt;
}

int BW_check(string s, int j)
{
	int cnt = 0;
	for (int y = j; y < j + 8; ++y) {
		if (y % 2 == 0) {
			if (s[y] != 'B')
				++cnt;
		} 
		else {
			if (s[y] != 'W')
				++cnt;
		}
	}
	return cnt;
}

int main(void)
{
	int n, m;
	string s;
	vector <string> sv;

	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		cin >> s;
		sv.push_back(s);
	}

	int mincnt = n * m;
	int cnt;
	int cntt;

	for (int i = 0; i <= n - 8; ++i) {
		for (int j = 0; j <= m - 8; ++j) {
			cnt = 0;		
			for (int x = i; x < i + 8; ++x) {
				if (x % 2 == 0)
					cnt += WB_check(sv[x], j);
				else 
					cnt += BW_check(sv[x], j);
			}

			cntt = 0;
			for (int x = i; x < i + 8; ++x) {
				if (x % 2 == 0)
					cntt += BW_check(sv[x], j);
				else 
					cntt += WB_check(sv[x], j);
			}

			if (mincnt > min(cnt, cntt))
				mincnt = min(cnt, cntt);
		}
	}
	
	cout << mincnt << endl;
}
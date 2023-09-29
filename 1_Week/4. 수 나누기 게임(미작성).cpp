#include <iostream>
#include <vector>
#include <set>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

int main(void)
{
	FastIO;

	int n, a; 
	cin >> n;

	vector<int> score(n, 0);
	vector<int> plist(n);
	set<int, greater<int>> player;
	for (int i = 0; i < n; i++)
		{
			cin >> a;
			plist[i] = a;
			player.insert(a);
		}
	
	set<int>::iterator iter;
	for (int i = 0; i < n; i++) {
		for (iter = player.begin(); iter != player.end() && *iter <= plist[i]; ++iter)	{
			if (*iter % plist[i] == 0)
				score[i]++;
		}	
	}

	for (int num : score)
		cout << num << " ";
}
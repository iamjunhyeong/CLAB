#include <iostream>
#include <unordered_map>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
	FastIO;	
	int n;
	cin >> n;

	unordered_map<int, int> nlist;
	int num;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		nlist.insert(make_pair(num, 1));
	}

	int m;
	cin >> m;
	unordered_map<int,int>::iterator iter;
	for (int i = 0; i < m; i++)
	{
		cin >> num;
		if(nlist.find(num) == nlist.end())
			cout << "0\n";
		else
			cout << "1\n";
	}
}
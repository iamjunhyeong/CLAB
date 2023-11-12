#include <iostream>
#include <vector>
#include <algorithm>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

int n, m;
vector<char> arr(9, 0);
vector<char> buf;
void printVector() {
	for (int i = 0; i < m; i++)
		cout << arr[i];
	cout << "\n";
}

bool check_aeiou(){
	char sep[] = {'a', 'i', 'u', 'e', 'o'};
	int sepCnt = 0;
	int otherCnt = 0;

	for (char c : sep){
		if(find(arr.begin(), arr.end(), c) != arr.end())
			sepCnt++;
		else
			otherCnt++;
	}

	if (sepCnt >= 1 && otherCnt >= 2)
		return true;
	return false;
}

void dfs(int dep, int idx) {
	if (dep == m && check_aeiou()) {
		printVector();
		return;
	}
	
	for (int i = idx; i < n; i++) {
		arr[dep] = buf[i];
		dfs(dep + 1, i + 1);
	}
}

int main() 
{
	FastIO;
	cin >> m >> n;

	for (int i = 0; i < n; i++)
	{
		char a; cin >> a;
		buf.push_back(a);
	}
	sort(buf.begin(), buf.end());
	dfs(0, 0);
}
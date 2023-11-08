#include <iostream>
#include <vector>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

int n, s, cnt = 0;
vector<int> arr(20, 0);

void input() 
{
	for (int i = 0; i < n; i++)
		cin >> arr[i];
}

void func(int idx, int temp)
{
	if (idx == n) return;
	if (temp + arr[idx] == s) cnt++;
 	
	func(idx + 1, temp);
	func(idx + 1, temp + arr[idx]);
}

int main() 
{
	FastIO;
	cin >> n >> s;
	input();
	func(0, 0);
	cout << cnt;
}
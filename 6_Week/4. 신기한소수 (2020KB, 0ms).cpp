#include <iostream>
#include <vector>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

int n;
vector<int> arr(9, 0);
void printVector() {
	for (int i = 0; i < n; i++)
		cout << arr[i];
	cout << "\n";
}

bool isPrime(int num)
{
	if (num <= 1)
		return false;
	if (num == 2)
		return true;
		
	for (int i = 2; i * i <= num + 1; i++) {
		if (num % i == 0)
			return false;
	}
	return true;
}

void dfs(int dep, int sum) {
	if (dep == n) {
		printVector();
		return;
	}

	for (int i = 1; i <= 9; i++) {
		if (isPrime(sum * 10 + i) == false) continue;
		arr[dep] = i;
		dfs(dep + 1, sum * 10 + i);
	}
}		

int main() 
{
	FastIO;
	cin >> n;
	arr[0] = 2;
	dfs(1, 2);
	arr[0] = 3;
	dfs(1, 3);
	arr[0] = 5;
	dfs(1, 5);
	arr[0] = 7;
	dfs(1, 7);
}
#include <iostream>
#include <vector>
#define MAX 100001
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

// 1308ms,,,,, 다음에 꼭 다시 풀어보겠습니다

void setCheck(vector<bool>& Check, vector<int>& arr)
{
	Check[0] = false;
	Check[1] = false;
	for (int i = 2; i * i <= MAX; i++) {
		if (!Check[i]) continue;
		arr[i] = 1;
		for (int j = 2; i * j <= MAX; j++) {
			Check[i * j] = false;
		}
	}
}

int main() 
{
	FastIO;
	int cnt = 0;
	int a, b;
	cin >> a >> b;

	vector<bool> Check(MAX, true);	// prime
	vector<int> arr(MAX, 0);
	setCheck(Check, arr);
	// dp
	for (int i = 2; i <= b; i++){
		if (arr[i] != 0) continue;
		for (int j = 2; ; j++) {
			if (i % j == 0) {
				arr[i] = arr[i / j] + 1;
				break;
			}
		}
	}

	for (int i = a; i <= b; i++) {
		if (Check[arr[i]]) cnt ++;
	}
	cout << cnt;
}
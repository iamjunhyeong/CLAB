#include <iostream>
#include <vector>
#include <algorithm>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

bool IsPrime(int num)
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

int main(void)
{
	for (int num = 1; num <= 100; num++) {
		cout << num << ' ' << (IsPrime(num) ? "Y" : "N") << '\n';
	}
}
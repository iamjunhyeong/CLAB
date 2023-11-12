#include <iostream>
#include <vector>
#include <algorithm>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;
#define SIZE 100
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

int main(void)
{
	FastIO;
	vector<bool> isPrime(SIZE +1,true);
	for (int i = 2; i <= 100; i++) {
		for (int j = 2; i * j <= SIZE; j++) 
			isPrime[i * j] = false
	}
}
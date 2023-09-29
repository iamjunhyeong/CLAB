#include <iostream>
#include <vector>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main(void)
{
	FastIO;
	int N, F;

	cin >> N;
	cin >> F;

	N = (N / 100) * 100;
	for (int i = 0; i < 100; i += F)
	{
		if ((N+i) % F == 0)
		{
			printf("%02d", i);
			break;
		}
	}
}
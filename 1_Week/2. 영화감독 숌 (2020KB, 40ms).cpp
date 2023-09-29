#include <iostream>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

int main(void)
{
	FastIO;
	int n, temp, i = 1, num = 666, six;
	cin >> n;

	while (i < n)
	{
		six = 0;
		num++;
		temp = num;
		while (temp != 0)
		{
			if (temp % 10 == 6)
				six++;
			else
				six = 0;

			if (six == 3)
			{
				i++;
				break;
			}
			temp /= 10;
		}
	}
	
	cout << num;
}
#include <iostream>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

int main(void)
{
	FastIO;

	int n, temp;
	int flag;

	cin >> n;
	for (int i = n; i >= 0; i--)
	{
		temp = i;
		flag = 0;
		while (temp != 0)
		{
			if (temp % 10 != 4 && temp % 10 != 7)
			{
				flag = 1;
				break;
			}
			else
				temp /= 10;
		}
		if (flag == 0)
		{
			cout << i;
			break;
		}
	}
}
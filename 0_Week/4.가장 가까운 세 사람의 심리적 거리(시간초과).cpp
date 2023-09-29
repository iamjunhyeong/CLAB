#include <iostream>
#include <vector>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int check_mbti(string a, string b, string c)
{
	int cnt = 0;

	for (int i = 0; i < 4; i++)
	{
		if (a[i] != b[i])
			cnt++;
	}
	for (int i = 0; i < 4; i++)
	{
		if (a[i] != c[i])
			cnt++;
	}
	for (int i = 0; i < 4; i++)
	{
		if (c[i] != b[i])
			cnt++;
	}
	return cnt;
}

int main(void)
{
	FastIO;
	int T, N, cnt, min;
	string str;
	vector<string> mbti;

	cin >> T;
	for (int t = 0; t < T; t++)
	{
		cin >> N;
		mbti.clear();
		min = 100;

		for (int i = 0; i < N; i++)
		{
			cin >> str;
			mbti.push_back(str);
		}
		if (N > 32)
			cout << 0 << "\n";
		else
		{
			for (int i = 0; i < N - 1; i++) {
				for (int j = i + 1; j < N; j++) {
					for (int k = j + 1; k < N; k++) {
						cnt = check_mbti(mbti[i], mbti[j], mbti[k]);
						if (cnt < min)
							min = cnt;
					}
				}
			}
			cout << min << "\n";
		}
	}
}
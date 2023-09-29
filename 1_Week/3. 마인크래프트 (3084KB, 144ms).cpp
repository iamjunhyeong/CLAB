#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define MAX 2147483647;
using namespace std;

int main(void)
{
	FastIO;

	int res_sec = MAX;
	int min = 256;
	int res_height;
	int N, M, B;
	cin >> N >> M >> B;
	
	vector<vector<int>> board(N, vector<int>(M,0));
	set<int> memo;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)	{
			cin >> board[i][j];
			memo.insert(board[i][j]);
			if (min > board[i][j])
				min = board[i][j];
		}
	}
	// 시간, 블록
	int sec, block; 

	// 기준 높이 = level
	for (int level = min; level < 256 + 1; level++) {
		sec = 0; block = B;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++)	{
				// 기준보다 높다면
				if (board[i][j] > level)
				{
					sec += 2 * (board[i][j] - level);
					block += board[i][j] - level;
				}
				// 기준보다 낮다면
				else if (board[i][j] < level)
				{
					sec += (level - board[i][j]);
					block -= (level - board[i][j]);
				}
			}
		}

		if (block >= 0 && res_sec >= sec)
		{
			if (res_sec == sec)
				res_height = max(res_height, level);
			else
			{
				res_sec = sec;
				res_height = level;
			}
		}
	}
	cout << res_sec << " " << res_height;
}
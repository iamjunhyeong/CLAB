#include <algorithm>
#include <iostream>
#include <queue>
#define FastIO                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(nullptr);                 \
	cout.tie(nullptr)
#define MAX 201
#define INF 2147483647

using namespace std;

// 1. 처음 bfs로 말 능력안썼을경우 경로를 계산한다.
// 2. 그리고 horst_bfs 함수를 돌려서 능력을 사용했을 경우 거리를 하니씩 다시 구한다. (함수내에 bfs를 다시 호출)
// 3. 더 작은 값이 나올때마다 갱신시켜서 실행 도착지점 값 출력.
// Outofbounds..?
vector<vector<int>> board(MAX, vector<int>(MAX));
int dh[] = {0, 0, 1, -1};
int dw[] = {1, -1, 0, 0};
int hh[] = {2, 2, 1, 1, -2 - 2, -1 - 1};
int hw[] = {-1, 1, -2, 2, -1, 1, -2, 2};

int k, w, h;
int abilityUseCnt = 0;

void input()
{
	cin >> k >> w >> h;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			int a;
			cin >> a;
			if (a == 0)
				board[i][j] = INF;
			else
				board[i][j] = -1;
		}
	}
	board[0][0] = 0;
}

void bfs(int a, int b)
{
	queue<pair<int, int>> qu;
	qu.push(make_pair(a, b));

	while (!qu.empty())
	{
		int y = qu.front().first;
		int x = qu.front().second;
		qu.pop();

		for (int i = 0; i < 4; i++)
		{
			int nh = y + dh[i];
			int nw = x + dw[i];

			if (nh < 0 || nh >= h || nw < 0 || nw >= w)
				continue;
			if (board[nh][nw] == -1 || board[nh][nw] == 0)
				continue;
			if (board[nh][nw] <= board[y][x] + 1)
				continue;
			board[nh][nw] = board[y][x] + 1;
			qu.push(make_pair(nh, nw));
		}
	}
}

void horst_bfs()
{
	queue<pair<int, int>> qu;
	qu.push(make_pair(0, 0));
	board[0][0] = 0;

	while (!qu.empty())
	{
		int y = qu.front().first;
		int x = qu.front().second;
		qu.pop();

		for (int i = 0; i < 8; i++)
		{
			int nhh = y + hh[i];
			int nww = x + hw[i];

			if (nhh < 0 || nhh >= h || nww < 0 || nww >= w)
				continue;
			if (board[nhh][nww] == -1 || board[nhh][nww] == 0)
				continue;
			if (board[nhh][nww] <= board[y][x] + 1)
				continue;
			board[nhh][nww] = board[y][x] + 1;
			if (++abilityUseCnt < k)
				qu.push(make_pair(nhh, nww));
			bfs(nhh, nww);
		}
	}
}

void result()
{
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			if (board[i][j] == INF)
			{
				cout << -1;
				return;
			}
		}
	}
	cout << board[h - 1][w - 1];
}

int main()
{
	FastIO;

	input();
	bfs(0, 0);
	horst_bfs();
	result();
}
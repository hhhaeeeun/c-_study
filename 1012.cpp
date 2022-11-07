#include<bits/stdc++.h>
using namespace std;

int m, n, k;

int z[101][101];
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0, 1,0,-1 };
int visited[101][101];

void paint(int a, int b, int c, int d)
{
	for (int i = 0; i < (c - a); i++)
	{
		for (int j = 0; j < (d - b); j++)
		{
			if (z[a+i][b+j] == 0)
				z[a + i][b + j] = 1;

		}
	}
}
void dfs(int y, int x, int &area)
{
	visited[y][x] = 1;
	area++;

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= n || nx < 0 || nx >= m)continue;
		if (visited[ny][nx] == 0 && z[ny][nx] == 0)
			dfs(ny, nx,area);
	}
}
int main()
{
	int point[4];
	cin >> m >> n >> k;
	for (int v = 0; v < k; v++)
	{
		for (int i = 0; i < 4; i++)
			cin >> point[i];
		paint(point[0], point[1], point[2], point[3]);
	}
	int ret = 0;
	vector<int> res;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (z[i][j] == 0 && visited[i][j] == 0)
			{
				ret++;
				int area=0;
				dfs(i, j, area);
				res.push_back(area);
			}
		}
	}
	cout << ret << endl;
	sort(res.begin(), res.end());
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << ' ';
}

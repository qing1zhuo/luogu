#include<stdio.h>
using namespace std;
int n, m;
int cell[110][110];
int dx[5] = { 0,0,1,0,-1 };
int dy[5] = { 0,1,0,-1,0 };
int num = 0;
int list[10010][3];

void clean(int, int);

int main()
{
	scanf("%d%d",&n,&m);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			scanf("%1d", &cell[i][j]);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (cell[i][j]!=0)
			{
				cell[i][j]=0;
				list[1][1] = i; list[1][2] = j;
				clean(i, j);num++;
				
			}
		}
	}
	printf("%d",num);
	return 0;
}

void clean(int u, int v)
{
	int head = 1; int tail = 1;
	while (head <= tail)
	{
		for (int i = 1; i <= 4; i++)
		{
			int tx = list[head][1] + dx[i]; int ty = list[head][2] + dy[i];
			if (tx >= 1 && tx <= n && ty >= 1 && ty <= m &&cell[tx][ty]!=0)
			{
				tail++;
				list[tail][1] = tx; list[tail][2] = ty;
				cell[tx][ty] = 0;
			}
		}
		head++;
	}
}
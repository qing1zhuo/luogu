#include<stdio.h>

char map[110][110];
int n,m;
char space;
int list[100010][3];
int dx[9]={0,0,1,1,1,0,-1,-1,-1};
int dy[9]={0,1,1,0,-1,-1,-1,0,1};
int num=0;

void print();
void clean(int,int);

int main()
{
    scanf("%d%d",&n,&m);
    scanf("%c",&space);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            scanf("%c",&map[i][j]);
        }
        scanf("%c",&space);
    }
    //print();

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(map[i][j]=='W')
            {
                num++;
                map[i][j]='.';
                list[1][1]=i;list[1][2]=j;
                clean(i,j);
            }
        }
    }
    printf("%d",num);
    
    return 0;
}

void clean(int u,int v)
{
    int head=1;int tail=1;
    while(head<=tail)
    {
        for(int i=1;i<=8;i++)
        {
            int tx=list[head][1]+dx[i];
            int ty=list[head][2]+dy[i];
            if(tx>=1&&tx<=n&&ty>=1&&ty<=m&&map[tx][ty]=='W')
            {
                tail++;
                list[tail][1]=tx;list[tail][2]=ty;
                map[tx][ty]='.';
            }
        }
        head++;
    }
}
void print()
{
    printf("\n");
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            printf("%c ",map[i][j]);
        }
        printf("#\n");
    }
}
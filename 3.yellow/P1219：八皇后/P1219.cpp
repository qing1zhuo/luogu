#include<stdio.h>
int n=0;
int qipan[14]={0};//qi[i]=j表示第i行放棋子的是第j列
int total=0;

void search(int);
int column_check(int,int);
int parallel_check(int,int);
int incline_check(int,int);
void print();

int main()
{
    scanf("%d",&n);
    search(1);//从第1行开始放
    printf("%d",total);
    return 0;
}

void search(int k)//第k行怎么放
{
    for(int i=1;i<=n;i++)//对k行的每一列
    {
        if(column_check(k,i)&&parallel_check(k,i)&&incline_check(k,i))
        {
            qipan[k]=i;
            if(k==n)
            {
                print();
            }
            else
            {
                search(k+1);
            }
            qipan[k]=0;
        }
    }
}

int column_check(int k,int i)//列检查
{
    for(int j=1;j<k;j++)
    {
        if(qipan[j]==i)
        {
            return 0;
        }
    }
    return 1;
}

int parallel_check(int k,int i)//平行的斜线检查
{
    int divi=k-i;
    for(int j=1;j<k;j++)
    {
        if(j-qipan[j]==divi)
        {
            return 0;
        }
    }
    return 1;
}


int incline_check(int k,int i)//相交的斜线检查
{
    int sum=k+i;
    for(int j=1;j<k;j++)
    {
        if((j+qipan[j])==sum)
        {
            return 0;
        }
    }
    return 1;
}

void print()
{
    total++;
    if(total<=3)
    {
        for(int m=1;m<=n;m++)
        {
            printf("%d ",qipan[m]);
        }
        printf("\n");
    }
}
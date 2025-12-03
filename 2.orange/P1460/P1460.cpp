#include<iostream>
using namespace std;
#include<climits>

int v,g;
int s[30];//存放维他命最小量
int cur[30];//存放当前维他命和
int cow[20][30];//存放每种饲料的各维他命数量
int cate[30];//存放所需饲料编号，cate[0]为当前饲料总数
int path[30];//标记该饲料是否被选过
int ans[30];//存放答案

void bfs(int);
void sum(int);
void sub(int);
int check();
void upload();

int main()
{
    cin>>v;
    for(int i=1;i<=v;i++)
    {
        cin>>s[i];
    }
    cin>>g;
    for(int i=1;i<=g;i++)
    {
        for(int j=1;j<=v;j++)
        {
            cin>>cow[i][j];
        }
    }
    ans[0]=INT_MAX;
    bfs(1);
    for(int i=0;i<=ans[0];i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}

void bfs(int k)
{
    if(check())
    {
        upload();
    }
    else
    {
        for(int i=cate[k-1];i<=g;i++)
        {
            if(path[i]==0)//若该饲料未被选过
            {
                path[i]=1;//标记该饲料选过
                cate[0]++;//选过的饲料数量加一
                cate[cate[0]]=i;//将该饲料编号放入
                sum(i);//将该饲料加入当前总营养
                bfs(k+1);//往下一层搜索
                //回溯
                path[i]=0;
                cate[0]--;
                cate[k]=0;
                sub(i);
            }
        }
    }

}

void sum(int k)//把k饲料营养值加入当前和
{
    for(int i=1;i<=v;i++)
    {
        cur[i]+=cow[k][i];
    }
}

void sub(int k)//把k饲料营养值减去当前和
{
    for(int i=1;i<=v;i++)
    {
        cur[i]-=cow[k][i];
    }
}

int check()//检查当前饲料和是否满足
{
    for(int i=1;i<=v;i++)
    {
        if(cur[i]<s[i])return 0;//该种维他命目前总和小于标准，则返回0
    }
    return 1;
}

void upload()//检查当前所得序列是否比当前答案更优，若是，则更新
{
    if(ans[0]>cate[0]){
        ans[0]=cate[0];
        for(int i=1;i<=v;i++){
            ans[i]=cate[i];
        }
    }
}
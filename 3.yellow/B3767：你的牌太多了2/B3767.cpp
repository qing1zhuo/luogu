#include<iostream>
#include<string.h>
using namespace std;
int card1[105][3];
int card2[105][3];
void my_scanf(int n);
void work();
int cmp(const void*ptr1,const void*ptr2);

int main()
{
    int t;
    cin>>t;
    while(t--){
        work();
        if(t){
            memset(card1,0,sizeof(card1));
            memset(card2,0,sizeof(card2));
        }
    }
    return 0;
}
int cmp(const void*ptr1,const void*ptr2)//排序函数
{
    int*p1=(int*)ptr1;int*p2=(int*)ptr2;
    if(p1[2]!=p2[2])return p1[2]-p2[2];
    else return p1[1]-p2[1];
}
void work(){//工作函数
    int n,m,r,s;
    cin>>n>>m>>r>>s;
    int num1=n,num2=n;
    my_scanf(n);

    //标记谁先
    int sign;
    if(s==1)sign=1;
    else sign=-1;
    
    //整理牌堆
    qsort(card1,n+1,sizeof(card1[0]),cmp);
    qsort(card2,n+1,sizeof(card2[0]),cmp);

    int cur_f=0,cur_p=0;
    while(num1>0&&num2>0){

        if(sign==1){//扶苏先出牌
            int t=0;//假定扶苏没牌出
            sign*=-1;
            if(cur_p==0){//若是第一个
                for(int i=1;i<=n;i++){
                    if(card1[i][0]==0)
                    {
                        card1[i][0]=1;
                        cur_f=card1[i][1];
                        cur_p=card1[i][2];
                        t=1;num1--;
                        break;
                    }
                }
            }
            else{
                for(int i=1;i<=n;i++){
                    if(card1[i][0]==0&&card1[i][2]>cur_p&&card1[i][1]==cur_f)
                    {
                        card1[i][0]=1;
                        cur_p=card1[i][2];
                        t=1;num1--;
                        break;
                    }
                }
            }
            if(t==0){cur_f=0;cur_p=0;}
        }

        else{
            int t=0;
            sign*=-1;
            if(cur_p==0){
                for(int i=1;i<=n;i++){
                    if(card2[i][0]==0)
                    {
                        card2[i][0]=1;
                        cur_f=card2[i][1];
                        cur_p=card2[i][2];
                        t=1;num2--;
                        break;
                    }
                }
            }
            else{
                for(int i=1;i<=n;i++){
                    if(card2[i][0]==0&&card2[i][2]>cur_p&&card2[i][1]==cur_f)
                    {
                        card2[i][0]=1;
                        cur_p=card2[i][2];
                        t=1;num2--;
                        break;
                    }
                }
            }
            if(t==0){cur_f=0;cur_p=0;}
        }
    
    }
    if(num1==0)printf("FS wins!\n");
    else printf("FR wins!\n");
}
void my_scanf(int n){//读取模块
    for(int i=1;i<=n;i++)
    {
        int f;cin>>f;
        card1[i][1]=f;
    }
    for(int i=1;i<=n;i++)
    {
        int d;cin>>d;
        card1[i][2]=d;
    }
    for(int i=1;i<=n;i++)
    {
        int f;cin>>f;
        card2[i][1]=f;
    }
    for(int i=1;i<=n;i++)
    {
        int d;cin>>d;
        card2[i][2]=d;
    }
}
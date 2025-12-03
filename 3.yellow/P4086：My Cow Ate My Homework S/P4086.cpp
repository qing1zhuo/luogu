#include<stdio.h>
typedef unsigned long long llu;
int score[100005];
llu pre[100005];
int minn[100005];
double ans[100005][3];
int n;
void print();
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&score[i]);
        pre[i]=pre[i-1]+score[i];
    }

    int temp=0x7fffffff;
    for(int i=n;i>=1;i--)
    {
        if(score[i]<temp){
            temp=score[i];
            minn[i]=temp;
        }
        else{
            minn[i]=minn[i+1];
        }
    }

    double max=0;
    for(int i=1;i<=n-2;i++)
    {
        ans[i][1]=i;
        ans[i][2]=(pre[n]-pre[i]-minn[i+1])/(double)(n-i-1);
        if(max<ans[i][2]){
            max=ans[i][2];
        }
    }
    
    //print();
    for(int i=1;i<=n-2;i++)
    {
        if(ans[i][2]==max){
            printf("%d\n",(int)ans[i][1]);
        }
    }   
    return 0;
}

void print()
{
    for(int i=1;i<=n;i++){
        printf("%d ",score[i]);
    }
    printf("\n");
    for(int i=1;i<=n;i++){
        printf("%llu ",pre[i]);
    }
    printf("\n");
    for(int i=1;i<=n;i++){
        printf("%d ",minn[i]);
    }
    printf("\n");
    for(int i=1;i<=n-2;i++){
        printf("%d %.6f\n",(int)ans[i][1],ans[i][2]);
    }
    printf("\n");
}
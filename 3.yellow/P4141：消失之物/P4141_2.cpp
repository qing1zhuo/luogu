#include<stdio.h>
int n,m;
int w[2005],f[2005],g[2005];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&w[i]);
    for(int i=1;i<=n;i++){
        f[0]=1;
        for(int j=m;j>=w[i];j--){
            f[j]=(f[j]+f[j-w[i]])%10;
        }
    }
    for(int i=1;i<=n;i++){
        g[0]=1;
        for(int j=1;j<=m;j++){
            if(j<w[i])g[j]=f[j];
            else g[j]=(f[j]-g[j-w[i]]+10)%10;
            printf("%d",g[j]%10);
        }
        printf("\n");
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

const long long mod=1000000007;

int n;
char a[1000010]={};
int la;
int next[1000010]={};
long long num1[1000010]={};
int j;

void kmp()
{
	j=0;
	for(int i=1;i<la;i++)
	{
		while(j&&a[j]!=a[i])  j=next[j];
		if(a[j]==a[i])  j++;
		next[i+1]=j;num1[i+1]=num1[j]+1;
	}
}

int main()
{
	scanf("%d",&n);
	while(n--)
	{
//		memset(num1,0,sizeof(num1));
		memset(next,0,sizeof(next));
//		memset(a,0,sizeof(a));//翻车现场
		scanf("%s",a);
		la=strlen(a);
		num1[0]=0;
		num1[1]=1;
		kmp();
		j=0;
		long long ans=1;
		for(int i=1;i<la;i++)
		{
			while(a[j]!=a[i]&&j) j=next[j];
			if(a[i]==a[j]) j++;
			while((j<<1)>i+1)   j=next[j];
			ans*=(num1[j]+1);
			ans%=mod;
		}
		printf("%lld\n",ans);
	}
	return 0;
}

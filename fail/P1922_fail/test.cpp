#include<iostream>
#include<cstdio>
using namespace std;

const int M=1e5+5;

int n,tot=0,in[M],ans[M],first[M];
struct Egde{
	int nxt,to;
}e[M<<1];

int read(){
	int x=0,y=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') y=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*y;
}

void add(int x,int y){
	tot++;
	e[tot].nxt=first[x];
	first[x]=tot;
	e[tot].to=y;
}

void dfs(int u,int fa){
	int sum=1;//记录剩余节点个数 
	for(int i=first[u];i;i=e[i].nxt){
		int v=e[i].to;
		if(v==fa) continue;
		dfs(v,u);
		if(in[v]==1) sum++;
		else ans[u]+=ans[v];
	}
	ans[u]+=sum/2;
}

int main(){
	n=read();
	for(int i=1;i<=n-1;i++){
		int x=read(),y=read();
		add(x,y),add(y,x);
		in[x]++,in[y]++;//利用入度来判断是否为叶子节点 
	}
	dfs(1,0);
	printf("%d\n",ans[1]);
}

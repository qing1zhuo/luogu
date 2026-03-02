#include<bits/stdc++.h>

using namespace std;
struct node{
	int w,c,d;
};
priority_queue<node>q;
int n,a[200011]={0},is[200011]={0},cnt=0,ans1[200011]={0},ans2[200011]={0},f[200011]={0},g[200011]={0},flag=1;
bool operator<(node a,node b){
	if(a.w==b.w)return a.c>b.c;
	else return a.w>b.w;
}
string s;
int main(){
	cin>>n;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	s+='H';
	for(int i=1;i<n;i++){
		if(s[i-1]!=s[i])q.push((node){abs(a[i]-a[i+1]),i,i+1});
	}
	for(int i=1;i<=n;i++){
		f[i]=i+1;
		g[i]=i-1;
	}
	while(q.empty()==0){
		node t=q.top();
        q.pop();
		int x=t.c,y=t.d;
		if(is[x]==0&&is[y]==0){
			f[g[x]]=f[y];
			g[f[y]]=g[x];
			cnt+=1;
			ans1[cnt]=x,ans2[cnt]=y;
			is[x]=1,is[y]=1;
			if(is[g[x]]==0&&is[f[y]]==0){
				if((s[g[x]-1]+s[f[y]-1])==('G'+'B')){
                    q.push((node){abs(a[g[x]]-a[f[y]]),g[x],f[y]});
                }
			}
		}
	}
	cout<<cnt<<endl;
	for(int i=1;i<=cnt;i++){
		cout<<ans1[i]<<" "<<ans2[i]<<endl;
	}
	return 0;
}

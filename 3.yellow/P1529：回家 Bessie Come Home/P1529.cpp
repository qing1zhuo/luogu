#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;
#define inf INT_MAX
int trans(char ch)
{
    if(ch=='Z')return 0;
    if(ch>='A'&&ch<='Y')return ch-'A'+1;
    if(ch>='a'&&ch<='z')return ch-'a'+26;
}
struct Edge
{
    int u,v;
    int w;
};
Edge edge[200001];
int num_edge;
int dist[52];
int main()
{
    int p;cin>>p;
    while(p--){
        char uletter,vletter;int w;
        cin>>uletter>>vletter>>w;
        int u=trans(uletter);int v=trans(vletter);
       
        num_edge++;
        edge[num_edge].u=u;
        edge[num_edge].v=v;
        edge[num_edge].w=w;

        num_edge++;
        edge[num_edge].v=u;
        edge[num_edge].u=v;
        edge[num_edge].w=w;
    }
    for(int i=1;i<=51;i++){
        dist[i]=inf;
    }
    for(int i=1;i<=51;i++){
        bool flag=false;
        for(int j=1;j<=num_edge;j++){
            int u=edge[j].u;
            int v=edge[j].v;
            int w=edge[j].w;
            if(dist[u]!=INT_MAX&&dist[v]>dist[u]+w){
                dist[v]=dist[u]+w;
                flag=true;
            }
        }
        if(!flag)break;
    }

    int minDist = INT_MAX;
    char minChar;
    for (char c = 'A'; c <= 'Y'; c++) {
        int id = trans(c);
        if (dist[id] < minDist) {
            minDist = dist[id];
            minChar = c;
        }
    }
    cout<<minChar<<" "<<minDist;
    return 0;
}
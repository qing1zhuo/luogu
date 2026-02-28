#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int n,c[200010],ans=0,righ[200010];
const int N=200010;
void add(int x,int y)
{
        for(;x<=N;x+=(x&-x))
            c[x]+=y;
}
int ask(int x)
{
        int as=0;
        for(;x;x-=(x&-x))
            as+=c[x];
        return as;
}
int main()
{
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            char temp;
            cin>>temp;
            if(temp=='A')
            {
                int st,ed,anss=0;
                cin>>st>>ed;			
                while(1)
                {
                    int l=0,r=ed;
                    while(l<r)
                    {
                        int mid=(l+r)>>1;
                        if(ask(mid)<ask(ed))
                            l=mid+1;
                        else
                            r=mid;
                    }
                    if(righ[l]>=st)
                    {
                        add(l,-1);
                        anss++;
                        ans--;
                    }
                    else
                        break;
                }
                add(st,1);
                righ[st]=ed,ans++;
                cout<<anss<<endl;
            }
            else
                cout<<ans<<endl;
        }	
        return 0;
}

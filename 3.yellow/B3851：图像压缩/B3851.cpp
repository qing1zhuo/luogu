#include<iostream>
#include<string.h>
using namespace std;
int a[25][45];
char b[25][45];
int c[256][3];
int func(char s1,char s2)
{
    int res=0;
    if(s1>='A'&&s1<='F')
    {
        res+=s1-65+10;
        res*=16;
    }
    else{
        res+=s1-'0';
        res*=16;
    }
    if(s2>='A'&&s2<='F')
    {
        res+=s2-65+10;
    }
    else{
        res+=s2-'0';
    }
    return res;
}
int cmp(const void*ptr1,const void*ptr2)
{
    int*p1=(int*)ptr1;int*p2=(int*)ptr2;
    if(p2[2]!=p1[2])return p2[2]-p1[2];
    else return p1[1]-p2[1];
}
void print(int num)
{
    int x=num/16;
    if(x>=10)printf("%c",x-10+65);
    else printf("%c",x+'0');
    x=num%16;
    if(x>=10)printf("%c",x-10+65);
    else printf("%c",x+'0');
}
void print_t(int x)
{
    if(x>=10)printf("%c",x-10+65);
    else printf("%c",x+'0');
}
int main()
{
    int n;cin>>n;
    for(int i=1;i<=n;i++)
    {
        scanf("%s",b[i]);
    }
    int len=strlen(b[1]);

    //把十六进制转化为十进制
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=len/2;j++)
        {
            a[i][j]=func(b[i][2*j-2],b[i][2*j-1]);
        }
    }

    for(int i=0;i<=255;i++)c[i][1]=i;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=len/2;j++){
            c[a[i][j]][2]++;
        }
    }
    
    qsort(c,256,sizeof(c[0]),cmp);

    for(int i=0;i<16;i++){
        print(c[i][1]);
    }
    cout<<endl;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=len/2;j++)
        {
            int cur=a[i][j];//该像素值为cur
            int minn=1000000;
            for(int p=0;p<16;p++){
                int delta=cur-c[p][1];
                if(delta<0)delta=-delta;

                if(delta==0){a[i][j]=p;break;}
                else{
                    if(minn>delta){
                        minn=delta;
                        a[i][j]=p;
                    }
                }
            }
            print_t(a[i][j]);
        }
        cout<<endl;
    }
    return 0;
}
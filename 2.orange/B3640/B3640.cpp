#include<iostream>
#include<string>
#include<cstring>
using namespace std;
string str;
void swap(int before,int after);
void trans(int start,int end);
void print(int start,int end);
int main()
{
    getline(cin,str);
    int len=str.size();
    int start=0;int end=0;
    for(int i=0;i<len;i++)
    {
        if(str[i]==' '){end=i-1;trans(start,end);start=i+1;}
        if(i==len-1){end=i;trans(start,end);}
    }
    start=len-1;end=len-1;
    for(int i=len-1;i>=0;i--){
        if(str[i]==' '){
            start=i+1;
            print(start,end);
            cout<<" ";
            end=i-1;
        }
        if(i==0){
            start=0;
            print(start,end);
        }
    }
    return 0;
}
void print(int start,int end)
{
    for(int i=start;i<=end;i++)cout<<str[i];
}
void trans(int start,int end)
{
    if(str[start]>='A'&&str[start]<='Z'){
        for(int i=start;i<=end;i++){
            str[i]+=32;
        }
    }
    else if(str[start]>='a'&&str[start]<='z'){
        for(int i=start;i<=end;i++){
            str[i]-=32;
        }
    }
    else if(str[start]>='0'&&str[start]<='9')
    {
        int len=end-start+1;
        int sum=start+end;
        for(int i=start;i<=start+len/2-1;i++)
        {
            swap(i,sum-i);
        }
    }
}
void swap(int before,int after)
{
    char mid=str[before];
    str[before]=str[after];
    str[after]=mid;
}
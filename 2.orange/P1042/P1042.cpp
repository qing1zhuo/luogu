#include<iostream>
using namespace std;
char a[30*3000];
int len=0;
int main()
{
    char ch;
    cin.get(ch);
    while(ch!='E'){
        if(ch=='W'||ch=='L')
        {
            len++;
            a[len]=ch;
        }
        cin.get(ch);
    }

    int one=0;int two=0;

    /*11分制*/for(int i=1;i<=len;i++){
        if(a[i]=='W')one++;
        else if(a[i]=='L')two++;
        if((one>=11||two>=11)&&(one-two>=2||two-one>=2)){
            cout<<one<<":"<<two<<endl;
            one=two=0;
        }
        if(i==len){
            cout<<one<<":"<<two<<endl;
            one=two=0;
        }
    }
    if(len)cout<<endl;
    /*21分制*/for(int i=1;i<=len;i++){
        if(a[i]=='W')one++;
        else if(a[i]=='L')two++;
        if((one>=21||two>=21)&&(one-two>=2||two-one>=2)){
            cout<<one<<":"<<two<<endl;
            one=two=0;
        }
        if(i==len){
            cout<<one<<":"<<two<<endl;
            one=two=0;
        }
    }

    if(len==0)cout<<"0:0\n\n0:0";
    return 0;
}
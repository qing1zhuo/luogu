 #include<iostream>
 #include<string.h>
 using namespace std;

 int main()
 {
    int n;cin>>n;
    unsigned long long bag[4005];
    memset(bag,0,sizeof(bag));
    bag[0]=1;
    for(int i=1;i<=n-1;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(j>=i)
            bag[j]=bag[j]+bag[j-i];
        }
    }
    cout<<bag[n]%2147483648;
    return 0;
 }
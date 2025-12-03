#include<iostream>
#include<string>
#include<stack>
using namespace std;

string str;
int str_len;
int max_len;
int max_index;
int left_index;int right_index;
int check(int l);

int main()
{
    cin>>str;
    str_len=str.size();
    for(int i=0;i<str_len;i++){
        int cur=check(i);
        if(cur>i){
            int cur_len=cur-i+1;
            if(cur_len>max_len){
                max_len=cur_len;
                max_index=i;
            }
        }
        i=cur;
    }
    for(int i=max_index;i<=max_index+max_len-1;i++)cout<<str[i];
    return 0;
}

int check(int l)
{
    int max_right=l;
    char record[1000001];
    int point=0;
    for(int i=l;i<str_len;i++)
    {
        if(str[i]=='('){
            point++;
            record[point]='(';
        }
        else if(str[i]=='['){
            point++;
            record[point]='[';
        }
        else if(str[i]==')'){
            if(point){
                if(record[point]=='('){
                    record[point]='0';
                    point--;
                }
                else break;
            }
            else break;
        }
        else if(str[i]==']'){
            if(point){
                if(record[point]=='['){
                    record[point]='0';
                    point--;
                }
                else break;
            }
            else break;
        }
        if(point==0)max_right=i;
    }
    return max_right;
}

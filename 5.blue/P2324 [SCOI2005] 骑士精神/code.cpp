#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;

class node
{
public:
    int f,g;
    vector<int>state;
    bool operator<(const node&other)const
    {
        if(f!=other.f)return f>other.f;
        else return g>other.g;
    }
};

void work();
vector<int> my_input();
string state2str(vector<int>&state);
vector<int>change(vector<int>&init,int op);
int check(vector<int>& cur,vector<int>& target);
vector<int>target={13,1,1,1,1,1,0,1,1,1,1,0,0,2,1,1,0,0,0,0,1,0,0,0,0,0};


int main()
{
    int T;
    cin>>T;
    while(T--){
        work();
    }
    return 0;
}
//工作函数
void work()
{
    vector<int>initial_state=my_input();
    string initial_str=state2str(initial_state);
    int initial_h=check(initial_state,target);

    unordered_map<string,int>min_g;
    priority_queue<node>pq;

    pq.push({initial_h+0,0,initial_state});

    while(!pq.empty())
    {
        node cur=pq.top();pq.pop();
        vector<int>cur_state=cur.state;
        string cur_str=state2str(cur_state);
        int cur_g=cur.g;

        if(min_g.count(cur_str) && min_g[cur_str] < cur_g){
            continue;
        }
        if(cur_g<=15&&check(cur_state,target)==0){
            cout<<cur_g<<endl;
            return;
        }

        for(int i=1;i<=8;i++){
            vector<int>next_state=change(cur_state,i);
            if(next_state==cur_state)continue;
            string next_str=state2str(next_state);

            int next_g=cur_g+1;
            if(next_g>15)continue;
            if(min_g.count(next_str) && min_g[next_str] < next_g){
                continue;
            }
            int next_h=check(next_state,target);
            int next_f=next_g+next_h;
            if(next_f>16)continue;

            if(min_g.count(next_str)==0||min_g[next_str]>next_g)
            {
                pq.push({next_f,next_g,next_state});
                min_g[next_str]=next_g;
            }
        }
    }
    cout<<-1<<endl;
    return;
}
//读入函数,返回一个vector
vector<int> my_input()
{
    vector<int>res;
    res.push_back(10000);//填充0号位

    char ch;
    for(int i=1;i<=25;i++){
        cin>>ch;
        if(ch=='1')res.push_back(1);//黑马
        else if(ch=='0')res.push_back(0);//白马
        else{
            res.push_back(2);//空格
            res[0]=i;//第0位存储空格所在位置
        }
    }

    return res;
}
//状态向量转字符串
string state2str(vector<int>&state)
{
    string res;
    for(int i=1;i<=25;i++)res+=to_string(state[i])+",";
    return res;
}
//移动函数
vector<int>change(vector<int>&init,int op)
{
    vector<int>res=init;
    int space_index=init[0];
    if(op==1)//右上竖
    {
        if(space_index%5==0||space_index<=10)return init;
        else{
            res[space_index]=res[space_index-9];
            res[space_index-9]=2;
            res[0]=space_index-9;
            return res;
        }
    }
    else if(op==2)//右上横
    {
        if(space_index<=5||space_index%5==4||space_index%5==0)return init;
        else{
            res[space_index]=res[space_index-3];
            res[space_index-3]=2;
            res[0]=space_index-3;
            return res;
        }
    }
    else if(op==3)//右下竖
    {
        if(space_index>15||space_index%5==0)return init;
        else{
            res[space_index]=res[space_index+11];
            res[space_index+11]=2;
            res[0]=space_index+11;
            return res;
        }
    }
    else if(op==4)//右下横
    {
        if(space_index>20||space_index%5==4||space_index%5==0)return init;
        else{
            res[space_index]=res[space_index+7];
            res[space_index+7]=2;
            res[0]=space_index+7;
            return res;
        }
    }
    else if(op==5)//左下竖
    {
        if(space_index>15||space_index%5==1)return init;
        else{
            res[space_index]=res[space_index+9];
            res[space_index+9]=2;
            res[0]=space_index+9;
            return res;
        }
    }
    else if(op==6)//左下横
    {
        if(space_index>20||space_index%5==1||space_index%5==2)return init;
        else{
            res[space_index]=res[space_index+3];
            res[space_index+3]=2;
            res[0]=space_index+3;
            return res;
        }
    }
    else if(op==7)//左上竖
    {
        if(space_index<=10||space_index%5==1)return init;
        else{
            res[space_index]=res[space_index-11];
            res[space_index-11]=2;
            res[0]=space_index-11;
            return res;
        }
    }
    else if(op==8)//左上横
    {
        if(space_index<=5||space_index%5==1||space_index%5==2)return init;
        else{
            res[space_index]=res[space_index-7];
            res[space_index-7]=2;
            res[0]=space_index-7;
            return res;
        }
    }
}
//差异检查函数
int check(vector<int>& cur,vector<int>& target)
{
    int res=0;
    for(int i=1;i<=25;i++){
        if(cur[i]!=target[i])res++;
    }
    return res;
}
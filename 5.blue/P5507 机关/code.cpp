#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
#include<vector>
#include<unordered_map>
using namespace std;

int a[13][5];

class node
{
public:
    int f,g;
    vector<int>state;
    //将priority_queue从大顶堆反转为小顶堆
    bool operator<(const node& other)const{
        if(f!=other.f)return f>other.f;
        else return g>other.g;
    }
};

string state_to_str(const vector<int>&state)
{
    string s;
    for(int i=1;i<=12;i++){
        s+=to_string(state[i])+",";
    }
    return s;
}

int cal_h(const vector<int>&state)
{
    int h=0;
    for(int i=1;i<=12;i++)
    {
        switch (state[i])
        {
        case 1:
            h+=0;
            break;
        case 2:
            h+=3;
            break;
        case 3:
            h+=2;
            break;
        case 4:
            h+=1;
            break;
        }
    }
    return h;
}

vector<int> dfs(vector<int>& initial_state)
{
    //查询最小g的哈希表
    unordered_map<string,int>min_g;
    //查询前驱状态与前驱旋转按钮
    unordered_map<string,string>prev_state;
    unordered_map<string,int>prev_knob;
    //优先队列，优先查询g较小的状态
    priority_queue<node>pq;
    //初始化
    string initial_str=state_to_str(initial_state);
    int init_h=cal_h(initial_state);
    pq.push({init_h,0,initial_state});
    min_g[initial_str]=0;
    //目标结果
    vector<int>target_state(13,1);
    string target_str=state_to_str(target_state);

    //开始搜索
    while(!pq.empty()){
        node cur=pq.top();
        string cur_str=state_to_str(cur.state);
        pq.pop();
        //如果这个状态大于已记录的该状态的g值，则continue
        if(min_g.count(cur_str)&&cur.g>min_g[cur_str])continue;
        //找到目标状态
        if(cur_str==target_str){
            vector<int>path;
            string now_str=target_str;
            while(now_str!=initial_str){
                path.push_back(prev_knob[now_str]);
                now_str=prev_state[now_str];
            }
            reverse(path.begin(),path.end());
            return path;
        }

        for(int i=1;i<=12;i++){
            vector<int>new_state=cur.state;
            int cur_knob_state=new_state[i];
            //根据该旋钮的状态进行更新
            if(cur_knob_state==4)new_state[i]=1;
            else new_state[i]++;
            //找下一个旋钮
            int next_knob=a[i][cur_knob_state];
            if(new_state[next_knob]==4)new_state[next_knob]=1;
            else new_state[next_knob]++;

            //更新状态的f,g,h值
            int new_h=cal_h(new_state);
            int new_g=cur.g+1;
            int new_f=new_g+new_h;
            string new_str=state_to_str(new_state);

            //考虑是否入队:如果没记录 或 当前g更小
            if(min_g.count(new_str)==0||min_g[new_str]>new_g){
                pq.push({new_f,new_g,new_state});
                min_g[new_str]=new_g;
                prev_knob[new_str]=i;
                prev_state[new_str]=cur_str;
            }
        }
    }
    return {};
}
int main()
{
    vector<int>init(13);
    for(int i=1;i<=12;i++){
        cin>>init[i];
        for(int j=1;j<=4;j++){
            cin>>a[i][j];
        }
    }
    vector<int>ans=dfs(init);
    
    int len=ans.size();
    cout<<len<<endl;
    for(int i=0;i<len;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
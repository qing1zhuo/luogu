#include<iostream>
#include<algorithm>
using namespace std;

class Positive_Trie
{
private:
    struct Node
    {
        bool isEnd;
        int cnt;
        Node*children[2];
        Node():isEnd(false),cnt(0){children[0]=children[1]=nullptr;}
    };
    void destroy(Node*node){
        if(node==nullptr)return;
        destroy(node->children[0]),destroy(node->children[1]);
        delete node;
    }
    int sum;
    Node*root;
public:
    int psum(){return sum;}
    Positive_Trie(){root=new Node;sum=0;}
    ~Positive_Trie(){destroy(root);}
    //opt1:插入数字
    void insert(int x)
    {
        sum++;
        Node*cur=root;
        for(int i=30;i>=0;i--){
            int indx=(x>>i)&1;
            if(cur->children[indx]==nullptr){
                cur->children[indx]=new Node;
            }
            cur=cur->children[indx];
            cur->cnt++;
        }
    }
    //opt2:删除数字
    void delete_num(int x){
        sum--;
        Node*cur=root;
        for(int i=30;i>=0;i--){
            int indx=(x>>i)&1;
            cur->children[indx]->cnt--;
            if(cur->children[indx]->cnt==0){
                destroy(cur->children[indx]);
                cur->children[indx]=nullptr;
                break;
            }
            cur=cur->children[indx];
        }
    }
    //opt3:已知数字，查询rank，若有多个相同数字，则取这些数字的最前
    int search_rank(int x){
        int res=0;
        Node*cur=root;
        for(int i=30;i>=0;i--){
            int indx=(x>>i)&1;
            //如果这一位是1
            if(indx==1){
                //如果孩子0存在，则加到res
                if(cur->children[0]){
                    res+=cur->children[0]->cnt;
                }

                //若孩子1存在，往下走
                if(cur->children[1]){
                    cur=cur->children[1];
                }
                //若孩子1不存在，则不会再有大于等于x的数字了，直接返回
                else{
                    return res+1;
                }
            }
            //如果这一位为0
            else if(indx==0){
                //如果孩子0存在，往下走
                if(cur->children[0]){
                    cur=cur->children[0];
                }
                //如果孩子0不存在，则后面全部大于x，则当前的res已经累计了所有小于x的数量，直接返回
                else{
                    return res+1;
                }
            }
        }
        return res+1;
    }
    //opt4:已知rank，求对应数字
    int search_digit(int rk){
        Node*cur=root;
        int res=0;
        for(int i=30;i>=0;i--){
            //如果孩子0存在
            if(cur->children[0]){
                //孩子0的数量大于rk，则往孩子0走
                if(cur->children[0]->cnt>=rk){
                    cur=cur->children[0];
                }
                //孩子0数量小于rk，则减掉孩子0数量，往另外一边走
                else{
                    rk-=cur->children[0]->cnt;
                    cur=cur->children[1];
                    res|=(1<<i);
                }
            }
            //如果孩子0不存在
            else{
                cur=cur->children[1];
                res|=(1<<i);
            }
        }
        return res;
    }
};
//对于一个负数，我们将他转为正数放进Negative_Trie中，在查询排名时，数值越大的数实则越小，即实则排名越靠前，因此将Positive_Trie的0和1交换位置，就能完成构造
class Negative_Trie
{
private:
    struct Node
    {
        bool isEnd;
        int cnt;
        Node*children[2];
        Node():isEnd(false),cnt(0){children[0]=children[1]=nullptr;}
    };
    void destroy(Node*node){
        if(node==nullptr)return;
        destroy(node->children[0]),destroy(node->children[1]);
        delete node;
    }
    int sum;
    Node*root;
public:
    int nsum(){return sum;}
    Negative_Trie(){root=new Node;sum=0;}
    ~Negative_Trie(){destroy(root);}
    //opt1:插入数字
    void insert(int x)
    {
        x=-x;
        sum++;
        Node*cur=root;
        for(int i=30;i>=0;i--){
            int indx=(x>>i)&1;
            if(cur->children[indx]==nullptr){
                cur->children[indx]=new Node;
            }
            cur=cur->children[indx];
            cur->cnt++;
        }
    }
    //opt2:删除数字
    void delete_num(int x){
        x=-x;
        sum--;
        Node*cur=root;
        for(int i=30;i>=0;i--){
            int indx=(x>>i)&1;
            cur->children[indx]->cnt--;
            if(cur->children[indx]->cnt==0){
                destroy(cur->children[indx]);
                cur->children[indx]=nullptr;
                break;
            }
            cur=cur->children[indx];
        }
    }
    //opt3:已知数字，查询rank，若有多个相同数字，则取这些数字的最前
    int search_rank(int x){
        x=-x;
        int res=0;
        Node*cur=root;
        for(int i=30;i>=0;i--){
            int indx=(x>>i)&1;
            //如果这一位是0
            if(indx==0){
                //如果孩子1存在，则加到res
                if(cur->children[1]){
                    res+=cur->children[1]->cnt;
                }

                //若孩子0存在，往下走
                if(cur->children[0]){
                    cur=cur->children[0];
                }
                //若孩子0不存在，则不会再有小于等于x的数字了，直接返回
                else{
                    return res+1;
                }
            }
            //如果这一位为0
            else if(indx==1){
                //如果孩子1存在，往下走
                if(cur->children[1]){
                    cur=cur->children[1];
                }
                //如果孩子1不存在，则后面全部小于x，则当前的res已经累计了所有大于x的数量，直接返回
                else{
                    return res+1;
                }
            }
        }
        return res+1;
    }
    //opt4:已知rank，求对应数字
    int search_digit(int rk){
        Node*cur=root;
        int res=0;
        for(int i=30;i>=0;i--){
            //如果孩子1存在
            if(cur->children[1]){
                //孩子1的数量大于rk，则往孩子1走
                if(cur->children[1]->cnt>=rk){
                    cur=cur->children[1];
                    res|=(1<<i);
                }
                //孩子1数量小于rk，则减掉孩子1数量，往另外一边走
                else{
                    rk-=cur->children[1]->cnt;
                    cur=cur->children[0];
                }
            }
            //如果孩子1不存在
            else{
                cur=cur->children[0];
            }
        }
        return -res;
    }
};
Positive_Trie pt;
Negative_Trie nt;

void opt1(int x){
    if(x>=0)pt.insert(x);
    else nt.insert(x);
}
void opt2(int x){
    if(x>0)pt.delete_num(x);
    else nt.delete_num(x);
}
int opt3(int x){
    if(x>=0)return nt.nsum()+pt.search_rank(x);
    else return nt.search_rank(x);
}
int opt4(int rk){
    if(rk>nt.nsum())return pt.search_digit(rk-nt.nsum());
    else return nt.search_digit(rk);
}
int opt5(int x){
    int x_min_rank=opt3(x);
    return opt4(x_min_rank-1);
}
int opt6(int x){
    int x_max_rank=opt3(x+1)-1;
    return opt4(x_max_rank+1);
}

int main()
{
    int n;cin>>n;
    int op,x;
    while(n--){cin>>op;
        if(op==1){
            cin>>x;
            opt1(x);
        }
        else if(op==2){
            cin>>x;
            opt2(x);
        }
        else if(op==3){
            cin>>x;
            cout<<opt3(x)<<endl;
        }
        else if(op==4){
            cin>>x;
            cout<<opt4(x)<<endl;
        }
        else if(op==5){
            cin>>x;
            cout<<opt5(x)<<endl;
        }
        else if(op==6){
            cin>>x;
            cout<<opt6(x)<<endl;
        }
    }
    return 0;
}
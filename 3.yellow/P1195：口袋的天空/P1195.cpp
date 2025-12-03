#include<iostream>
using namespace std;

struct edge
{
    int u,v;
    int w;
    bool f=false;
};
edge E[10001];
int parent[1001];
int my_rank[1001];

int getPivot(int left, int right);
void insertSort(int left, int right);
void my_sort(int left,int right);
void swap(edge& a,edge& b);
void init(int n);
int find(int x);
bool unionn(int x,int y);


int main()
{
    int ans=0;
    int n,m,k;cin>>n>>m>>k;
    if(n<k)//云朵数量少于棉花糖数量
    {
        cout<<"No Answer"<<endl;
        return 0;
    }
    if(n==k)//云朵数量等于棉花糖数量
    {
        cout<<0<<endl;
        return 0;
    }
    for(int i=1;i<=m;i++)//读取边
    {
        cin>>E[i].u>>E[i].v>>E[i].w;
    }
    init(n);//初始化
    my_sort(1,m);//排序边
    for(int i=1;i<=m;i++)
    {
        int u=E[i].u;
        int v=E[i].v;
        int w=E[i].w;
        if(unionn(u,v))
        {
            ans+=w;
            n--;
        }
        if(n==k)break;
    }
    if(n>k)
    {
        cout<<"No Answer"<<endl;
    }
    else
    {
        cout<<ans<<endl;
    }
    return 0;
}

bool unionn(int x,int y)
{
    int fx=find(x);int fy=find(y);
    if(fx==fy)return false;
    else
    {
        if(my_rank[fy]<my_rank[fx])
        {
            parent[fy]=fx;
            my_rank[fy]=my_rank[fx]-1;
        }
        else if(my_rank[fy]>my_rank[fx])
        {
            parent[fx]=fy;
            my_rank[fx]=my_rank[fy]-1;
        }
        else
        {
            parent[fy]=fx;
            my_rank[fx]=my_rank[fy]+1;
        }
        return true;
    }
}
int find(int x)
{
    if(parent[x]!=x)parent[x]=find(parent[x]);
    return parent[x];
}

void init(int n)
{
    for(int i=1;i<=n;i++)
    {
        parent[i]=i;
        my_rank[i]=0;
    }
}

/*排序算法*/
// 三数取中选择枢轴，并将枢轴元素调整到中间位置
int getPivot(int left, int right) 
{
    int mid = (left + right) / 2;
    // 比较左、中、右三个位置的w，将中间值调整到mid位置
    if (E[left].w > E[mid].w) swap(E[left], E[mid]);
    if (E[left].w > E[right].w) swap(E[left], E[right]);
    if (E[mid].w > E[right].w) swap(E[mid], E[right]);
    // 此时mid位置的元素是中间值，将其作为枢轴
    swap(E[mid], E[(left + right) / 2]);
    return E[(left + right) / 2].w;
}
// 插入排序实现
void insertSort(int left, int right) 
{
    for (int i = left + 1; i <= right; ++i) {
        edge temp = E[i];
        int j = i - 1;
        // 按w从小到大插入
        while (j >= left && E[j].w > temp.w) {
            E[j + 1] = E[j];
            j--;
        }
        E[j + 1] = temp;
    }
}
void my_sort(int left, int right) 
{
    // 小数组切换为插入排序
    if (right - left + 1 < 10) {
        insertSort(left, right);
        return;
    }

    int i = left, j = right;
    // 三数取中选择枢轴
    int key = getPivot(left, right);

    while (true) {
        // 找左半部分大于等于key的元素
        while (E[i].w < key) i++;
        // 找右半部分小于等于key的元素
        while (E[j].w > key) j--;
        if (i >= j) break;
        // 交换并继续分割
        swap(E[i], E[j]);
        i++;
        j--;
    }

    // 递归处理左右子数组
    if (left < j) my_sort(left, j);
    if (i < right) my_sort(i, right);
}
void swap(edge& a,edge& b)
{
    edge tmp=a;
    a=b;
    b=tmp;
}
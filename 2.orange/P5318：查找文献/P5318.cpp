#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int n, m;

// 用结构体包装原来的int[3]，支持赋值和交换
struct Link {
    int data[3]; // data[1]对应原link[i][1]，data[2]对应原link[i][2]
};

Link link[1000001]; // 结构体数组，替代原int link[1000001][3]
int Index[100001][3]; // Index[i][1]和Index[i][2]含义不变
short mark[100001];
int path[100001];
int head, tail;

void dfs(int);
void bfs();
// 比较函数：参数改为结构体引用，比较对应的数据
bool compare(const Link& x, const Link& y) {
    if (x.data[1] != y.data[1]) {
        return x.data[1] < y.data[1]; // 按data[1]升序
    } else {
        return x.data[2] < y.data[2]; // 相同则按data[2]升序
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        Index[i][1] = 10000000;
        Index[i][2] = 0;
    }
    for (int i = 1; i <= m; i++) {
        int p1, p2;
        cin >> p1 >> p2;
        link[i].data[1] = p1; // 赋值给结构体中的data[1]
        link[i].data[2] = p2; // 赋值给结构体中的data[2]
    }

    // 对结构体数组排序，此时支持交换操作
    sort(link + 1, link + 1 + m, compare);

    for (int i = 1; i <= m; i++) {
        int p1 = link[i].data[1]; // 访问结构体中的data[1]
        if (Index[p1][1] > i) Index[p1][1] = i;
        if (Index[p1][2] < i) Index[p1][2] = i;
    }
    
    mark[1] = 1;
    cout << 1 << " ";
    dfs(1);
    cout << endl;

    memset(mark + 1, 0, n * sizeof(short));
    cout << 1 << " ";
    mark[1] = 1;
    head++; tail++;
    path[head] = 1;
    bfs();
    return 0;
}

void bfs() {
    while (head <= tail) {
        int cur = path[head];
        for (int i = Index[cur][1]; i <= Index[cur][2]; i++) {
            int next = link[i].data[2]; // 访问结构体中的data[2]
            if (!mark[next]) {
                mark[next] = 1;
                path[++tail] = next;
                cout << next << " ";
            }
        }
        head++;
    }
}

void dfs(int k) {
    for (int i = Index[k][1]; i <= Index[k][2]; i++) {
        int next = link[i].data[2]; // 访问结构体中的data[2]
        if (!mark[next]) {
            mark[next] = 1;
            cout << next << " ";
            dfs(next);
        }
    }
}

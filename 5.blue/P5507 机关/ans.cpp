#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

// 常量定义
const int KNOB_CNT = 12;       // 旋钮数量
const int MAX_CODE = 1 << 24;  // 4^12=16777216=2^24，状态编码最大值
const int TARGET_CODE = 0;     // 目标状态（所有旋钮为1，编码后为0）

// A*节点：f=g+h，g是已走步数，code是状态编码
struct Node {
    int f, g;
    unsigned int code;
    // 优先级队列默认大顶堆，重载<使f小的优先（f相同则g小的优先）
    bool operator<(const Node& other) const {
        if (f != other.f) return f > other.f;
        return g > other.g;
    }
};

// 全局数组（避免栈溢出）
int a[13][5];                  // a[k][j]：旋钮k在状态j时触发的旋钮（1-12）
int visited[MAX_CODE];         // 记录每个状态的最小g值（-1表示未访问）
unsigned int prev_code[MAX_CODE]; // 记录每个状态的前驱状态
int prev_knob[MAX_CODE];       // 记录到达该状态的最后一个旋转旋钮

// 解码：将状态编码转为旋钮状态数组（st[1-12]，值为0-3）
void decode(unsigned int code, int st[]) {
    for (int i = KNOB_CNT; i >= 1; --i) {
        st[i] = code & 3;      // 取最后2位（0-3）
        code >>= 2;            // 右移2位，处理下一个旋钮
    }
}

// 编码：将旋钮状态数组（0-3）转为状态编码
unsigned int encode(int st[]) {
    unsigned int code = 0;
    for (int i = 1; i <= KNOB_CNT; ++i) {
        code = (code << 2) | st[i]; // 左移2位，拼接当前旋钮状态
    }
    return code;
}

// 计算启发代价h(n)：每个旋钮到目标的最少旋转次数之和
int cal_h(unsigned int code) {
    int h = 0;
    int st[13];
    decode(code, st);
    for (int i = 1; i <= KNOB_CNT; ++i) {
        // 目标状态是0，当前是st[i]，需要(0 - st[i] + 4) %4次旋转
        h += (4 - st[i]) % 4;
    }
    return h;
}

// A*搜索核心函数
vector<int> a_star_search(unsigned int initial_code) {
    // 初始化
    memset(visited, -1, sizeof(visited));
    memset(prev_code, 0, sizeof(prev_code));
    memset(prev_knob, 0, sizeof(prev_knob));
    
    priority_queue<Node> pq;
    int initial_h = cal_h(initial_code);
    pq.push({initial_h, 0, initial_code});
    visited[initial_code] = 0;

    while (!pq.empty()) {
        // 取出f最小的节点
        Node cur = pq.top();
        pq.pop();

        // 找到目标状态，回溯路径
        if (cur.code == TARGET_CODE) {
            vector<int> path;
            unsigned int now = cur.code;
            while (now != initial_code) {
                path.push_back(prev_knob[now]);
                now = prev_code[now];
            }
            reverse(path.begin(), path.end()); // 回溯的路径是逆序，反转
            return path;
        }

        // 剪枝：如果当前节点的g值大于已记录的最小g值，跳过
        if (cur.g > visited[cur.code]) continue;

        // 遍历所有可能旋转的旋钮（1-12）
        for (int k = 1; k <= KNOB_CNT; ++k) {
            int st[13];
            decode(cur.code, st); // 解码当前状态

            // 模拟旋转旋钮k的过程
            int old_st_k = st[k]; // 旋转前k的状态（0-3，对应题目j=old_st_k+1）
            st[k] = (st[k] + 1) % 4; // 旋转k（顺时针）
            int t = a[k][old_st_k + 1]; // 触发的旋钮（j=old_st_k+1对应题目输入）
            st[t] = (st[t] + 1) % 4; // 旋转触发的旋钮t

            // 计算新状态的编码和代价
            unsigned int new_code = encode(st);
            int new_g = cur.g + 1;
            int new_h = cal_h(new_code);
            int new_f = new_g + new_h;

            // 如果新状态未访问，或有更优的g值，更新并加入队列
            if (visited[new_code] == -1 || new_g < visited[new_code]) {
                visited[new_code] = new_g;
                prev_code[new_code] = cur.code;
                prev_knob[new_code] = k;
                pq.push({new_f, new_g, new_code});
            }
        }
    }
    return {}; // 题目保证有解，此处不会执行
}

int main() {
    // 输入处理
    int st[13]; // 初始状态数组（0-3）
    for (int i = 1; i <= KNOB_CNT; ++i) {
        int s_i;
        cin >> s_i;
        st[i] = s_i - 1; // 1→0, 2→1, 3→2, 4→3
        for (int j = 1; j <= 4; ++j) {
            cin >> a[i][j];
        }
    }

    // 初始状态编码
    unsigned int initial_code = encode(st);

    // A*搜索
    vector<int> path = a_star_search(initial_code);

    // 输出结果
    cout << path.size() << endl;
    for (int i = 0; i < path.size(); ++i) {
        if (i > 0) cout << " ";
        cout << path[i];
    }
    cout << endl;

    return 0;
}
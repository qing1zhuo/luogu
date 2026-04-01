#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

#define VERSION_MAX 600010 // 版本数上限（N+M）
int s[VERSION_MAX]; // 前缀异或和

// 节点结构：增加cnt计数
struct Node {
    int cnt;
    Node* next[2];
    Node() : cnt(0) { next[0] = next[1] = nullptr; }
}* root[VERSION_MAX];

// 插入：完整复制旧节点+维护cnt
Node* insert(Node* pre, int x) {
    Node* cur = new Node();
    Node* res = cur;
    Node* p = pre;
    for (int i = 31; i >= 0; i--) {
        int bit = (x >> i) & 1;
        // 复制旧版本的节点（包括cnt）
        if (p) {
            cur->next[0] = p->next[0];
            cur->next[1] = p->next[1];
            cur->cnt = p->cnt;
        }
        cur->cnt++;
        // 新建当前bit的节点（确保非空）
        if (!cur->next[bit]) {
            cur->next[bit] = new Node();
        }
        // 移动指针
        cur = cur->next[bit];
        if (p) {
            p = p->next[bit];
        }
    }
    cur->cnt++; // 叶子节点计数+1
    return res;
}

// 查询：通过cnt判断区间是否有该路径
int query(Node* L_root, Node* R_root, int target) {
    int ans = 0;
    Node* cur_L = L_root;
    Node* cur_R = R_root;
    for (int i = 31; i >= 0; i--) {
        if (!cur_R) break; // 无路径，直接退出
        int bit = (target >> i) & 1;
        // 计算[L, R]区间内!bit路径的节点数
        int cnt_R = cur_R->next[!bit] ? cur_R->next[!bit]->cnt : 0;
        int cnt_L = cur_L ? (cur_L->next[!bit] ? cur_L->next[!bit]->cnt : 0) : 0;
        // 优先走相反位（异或最大化）
        if (cnt_R - cnt_L > 0) {
            ans |= (1 << i);
            cur_L = cur_L ? cur_L->next[!bit] : nullptr;
            cur_R = cur_R->next[!bit];
        } else {
            // 走相同位
            cur_L = cur_L ? cur_L->next[bit] : nullptr;
            cur_R = cur_R->next[bit];
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;

    // 初始化版本0：s[0]=0
    root[0] = new Node();
    s[0] = 0;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        s[i] = s[i - 1] ^ x;
        root[i] = insert(root[i - 1], s[i]);
    }

    int cnt = n;
    while (m--) {
        char op;
        cin >> op;
        if (op == 'A') {
            int x;
            cin >> x;
            cnt++;
            s[cnt] = s[cnt - 1] ^ x;
            root[cnt] = insert(root[cnt - 1], s[cnt]);
        } else {
            int l, r, x;
            cin >> l >> r >> x;
            int L = l - 1, R = r - 1;
            int target = s[cnt] ^ x;
            // 处理L-1 < 0的边界
            Node* L_node = (L - 1 >= 0) ? root[L - 1] : nullptr;
            int ans = query(L_node, root[R], target);
            cout << ans << '\n';
        }
    }

    // OJ中无需手动销毁节点，注释即可
    // for (int i = 0; i <= cnt; i++) destroy(root[i]);
    return 0;
}
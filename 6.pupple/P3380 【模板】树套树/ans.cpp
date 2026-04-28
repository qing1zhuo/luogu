/*
    P3380 树套树（BIT 套动态开点权值线段树）

    思路：
      1. 把所有出现过的数（含初始数组和操作 3 的修改值）一起离散化。
      2. 树状数组 BIT，下标 i 存第 i 棵权值线段树 root[i]，
         维护 a[i-lowbit(i)+1..i] 这段的值频次。
      3. 单点修改 -> 树状数组式更新 O(log n) 棵线段树。
         区间 [l,r] 的频次 = BIT 前缀差分（r 的链 - (l-1) 的链）。

    各操作：
      1) k 在 [l,r] 的排名         -> count(<k) + 1
      2) [l,r] 第 k 小             -> 多树同步往下走
      3) 单点修改                  -> 先删旧值，再插新值
      4) [l,r] 中 k 的前驱(<k 最大)-> rk = count(<k); 取第 rk 小
      5) [l,r] 中 k 的后继(>k 最小)-> gt = count(>k); 取第 (tot-gt+1) 小

    原代码主要错在 query_less_tree / query_more_tree 的迭代写法，
    在叶子边界（x = cnt+1 或 x = -1）会漏算最右/最左叶子的 sum。
    这里改成递归版本，逻辑清晰且不会漏算。
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 50005;
const int MAXV = 100005;
const int MAX_NODES = 10000000;
const int INF = 2147483647;

int lc[MAX_NODES], rc[MAX_NODES], sm[MAX_NODES];
int tot_node = 0;

int n, m, cnt;
int a[MAXN];
int b[MAXV];
int c[MAXN];
int rt[MAXN];

struct Query {
    int opt, l, r, pos, k;
} q[MAXN];

vector<int> all_num;

inline int low_bit(int x) { return x & -x; }

void update(int& cur, int L, int R, int idx, int val) {
    if (!cur) cur = ++tot_node;
    sm[cur] += val;
    if (L == R) return;
    int M = (L + R) >> 1;
    if (idx <= M) update(lc[cur], L, M, idx, val);
    else update(rc[cur], M + 1, R, idx, val);
}

void update_root(int pos, int val) {
    int idx = c[pos];
    for (int i = pos; i <= n; i += low_bit(i)) {
        update(rt[i], 1, cnt, idx, val);
    }
}

int query_less(int cur, int L, int R, int x) {
    if (!cur || L >= x) return 0;
    if (R < x) return sm[cur];
    int M = (L + R) >> 1;
    return query_less(lc[cur], L, M, x) + query_less(rc[cur], M + 1, R, x);
}

int query_greater(int cur, int L, int R, int x) {
    if (!cur || R <= x) return 0;
    if (L > x) return sm[cur];
    int M = (L + R) >> 1;
    return query_greater(lc[cur], L, M, x) + query_greater(rc[cur], M + 1, R, x);
}

int rs[20], ls[20];
int rs_n, ls_n;

int kth(int l, int r, int k) {
    rs_n = ls_n = 0;
    for (int i = r; i; i -= low_bit(i)) rs[rs_n++] = rt[i];
    for (int i = l - 1; i; i -= low_bit(i)) ls[ls_n++] = rt[i];
    int L = 1, R = cnt;
    while (L < R) {
        int sl = 0;
        for (int i = 0; i < rs_n; i++) sl += sm[lc[rs[i]]];
        for (int i = 0; i < ls_n; i++) sl -= sm[lc[ls[i]]];
        int M = (L + R) >> 1;
        if (k <= sl) {
            for (int i = 0; i < rs_n; i++) rs[i] = lc[rs[i]];
            for (int i = 0; i < ls_n; i++) ls[i] = lc[ls[i]];
            R = M;
        } else {
            k -= sl;
            for (int i = 0; i < rs_n; i++) rs[i] = rc[rs[i]];
            for (int i = 0; i < ls_n; i++) ls[i] = rc[ls[i]];
            L = M + 1;
        }
    }
    return L;
}

int count_less(int l, int r, int x) {
    int ans = 0;
    for (int i = r; i; i -= low_bit(i)) ans += query_less(rt[i], 1, cnt, x);
    for (int i = l - 1; i; i -= low_bit(i)) ans -= query_less(rt[i], 1, cnt, x);
    return ans;
}

int count_greater(int l, int r, int x) {
    int ans = 0;
    for (int i = r; i; i -= low_bit(i)) ans += query_greater(rt[i], 1, cnt, x);
    for (int i = l - 1; i; i -= low_bit(i)) ans -= query_greater(rt[i], 1, cnt, x);
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        all_num.push_back(a[i]);
    }
    for (int i = 1; i <= m; i++) {
        cin >> q[i].opt;
        if (q[i].opt == 3) {
            cin >> q[i].pos >> q[i].k;
            all_num.push_back(q[i].k);
        } else {
            cin >> q[i].l >> q[i].r >> q[i].k;
        }
    }

    sort(all_num.begin(), all_num.end());
    all_num.erase(unique(all_num.begin(), all_num.end()), all_num.end());
    cnt = (int)all_num.size();
    for (int i = 1; i <= cnt; i++) b[i] = all_num[i - 1];

    for (int i = 1; i <= n; i++) {
        c[i] = (int)(lower_bound(b + 1, b + 1 + cnt, a[i]) - b);
        update_root(i, 1);
    }

    for (int i = 1; i <= m; i++) {
        if (q[i].opt == 1) {
            int idx = (int)(lower_bound(b + 1, b + 1 + cnt, q[i].k) - b);
            cout << count_less(q[i].l, q[i].r, idx) + 1 << '\n';
        } else if (q[i].opt == 2) {
            int idx = kth(q[i].l, q[i].r, q[i].k);
            cout << b[idx] << '\n';
        } else if (q[i].opt == 3) {
            int pos = q[i].pos, k = q[i].k;
            update_root(pos, -1);
            a[pos] = k;
            c[pos] = (int)(lower_bound(b + 1, b + 1 + cnt, k) - b);
            update_root(pos, 1);
        } else if (q[i].opt == 4) {
            int idx = (int)(lower_bound(b + 1, b + 1 + cnt, q[i].k) - b);
            int rk = count_less(q[i].l, q[i].r, idx);
            if (rk == 0) cout << -INF << '\n';
            else cout << b[kth(q[i].l, q[i].r, rk)] << '\n';
        } else {
            int idx = (int)(upper_bound(b + 1, b + 1 + cnt, q[i].k) - b - 1);
            int gt = count_greater(q[i].l, q[i].r, idx);
            if (gt == 0) cout << INF << '\n';
            else {
                int tot = q[i].r - q[i].l + 1;
                cout << b[kth(q[i].l, q[i].r, tot - gt + 1)] << '\n';
            }
        }
    }
    return 0;
}

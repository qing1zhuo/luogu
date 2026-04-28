# P3380 【模板】树套树

## 题目描述

您需要写一种数据结构（可参考题目标题），来维护一个有序数列，其中需要提供以下操作：

1. 查询 $k$ 在区间内的排名；
2. 查询区间内排名为 $k$ 的值；
3. 修改某一位置上的数值；
4. 查询 $k$ 在区间内的前驱（前驱定义为严格小于 $x$，且最大的数，**若不存在输出 `-2147483647`**）；
5. 查询 $k$ 在区间内的后继（后继定义为严格大于 $x$，且最小的数，**若不存在输出 `2147483647`**）。

对于一组元素，一个数的排名被定义为严格比它小的元素个数加一，而排名为 $k$ 的数被定义为“将元素从小到大排序后排在第 $k$ 位的元素值”。

## 输入格式

第一行两个数 $n,m$，表示长度为 $n$ 的有序序列和 $m$ 个操作。

第二行有 $n$ 个数，表示有序序列。

下面有 $m$ 行，$opt$ 表示操作标号。

若 $opt=1$，则为操作 $1$，之后有三个数 $l~r~k$，表示查询 $k$ 在区间 $[l,r]$ 的排名。

若 $opt=2$，则为操作 $2$，之后有三个数 $l~r~k$，表示查询区间 $[l,r]$ 内排名为    $k$ 的数。

若 $opt=3$，则为操作 $3$，之后有两个数 $pos~k$，表示将 $pos$ 位置的数修改为 $k$。

若 $opt=4$，则为操作 $4$，之后有三个数 $l~r~k$，表示查询区间 $[l,r]$ 内 $k$ 的前驱。

若 $opt=5$，则为操作 $5$，之后有三个数 $l~r~k$，表示查询区间 $[l,r]$ 内 $k$ 的后继。

## 输出格式

对于操作 $1,2,4,5$，各输出一行，表示查询结果。

## 输入输出样例 #1

### 输入 #1

```
9 6
4 2 2 1 9 4 0 1 1
2 1 4 3
3 4 10
2 1 4 3
1 2 5 9
4 3 9 5
5 2 8 5
```

### 输出 #1

```
2
4
3
4
9
```

## 说明/提示

$1\le n,m\le5\times 10^4$，序列中的值在任何时刻 $\in[0,10^8]$。

题目来源：bzoj3196 / Tyvj1730，在此鸣谢。

此数据为洛谷原创。**（特别提醒：此数据不保证操作 4、5 一定存在，故请务必考虑不存在的情况。）**


# `code.cpp` 时间/空间复杂度分析

## 记号

设 $n$ 为序列长度，$m$ 为操作数，$V$ 为离散化后的值域大小。由于离散化集合包含初始值与所有 opt 3 的修改值，故 $V \le n + m$。下文使用 $\log n$、$\log V$，且 $\log V = O(\log n)$。

## 各函数单元复杂度

| 函数 | 复杂度 | 说明 |
|------|--------|------|
| `update_tree` | $O(\log V)$ | 动态开点单点修改，从根到叶 |
| `query_less_tree` | $O(\log V)$ | 单链下行（修复后包含叶子判断） |
| `query_more_tree` | $O(\log V)$ | 同上 |
| `query_sum_tree` | $O(\log V)$ | 线段树区间求和 |
| `my_binary_down` | $O(\log V)$ | 在 `b[]` 上二分 |

## BIT × 线段树 组合复杂度

- `update_root`：BIT 走 $\log n$ 个节点，每个 `update_tree` 是 $\log V$  
  $\Rightarrow O(\log n \cdot \log V)$

- `opt1`（区间小于 $k$ 的个数）：BIT 前缀差分各 $\log n$ 棵，每棵 `query_less_tree` 为 $\log V$  
  $\Rightarrow O(\log n \cdot \log V)$

- `query_sum_root`：$\log n$ 棵 × `query_sum_tree`($\log V$)  
  $\Rightarrow O(\log n \cdot \log V)$

- **`opt2`（区间第 $k$ 小）：值域二分外套 `query_sum_root`**  
  外层 $\log V$ 次二分，每次调用两次 `query_sum_root`  
  $\Rightarrow O(\log n \cdot \log^2 V)$  ← 这是单次操作里**最贵**的部分

- opt 5 里 `more` 的统计：BIT 前缀差分 × `query_more_tree`  
  $\Rightarrow O(\log n \cdot \log V)$

## 各类操作的复杂度

| 操作 | 单次复杂度 |
|------|-----------|
| opt 1（区间排名） | $O(\log n \cdot \log V)$ |
| opt 2（区间第 $k$ 小） | $O(\log n \cdot \log^2 V)$ |
| opt 3（单点修改） | $O(\log n \cdot \log V)$（一次 -1 + 一次 +1） |
| opt 4（前驱）= opt1 + opt2 | $O(\log n \cdot \log^2 V)$ |
| opt 5（后继）= count_more + opt2 | $O(\log n \cdot \log^2 V)$ |

## 主流程总复杂度

- **离散化**：$O((n+m)\log(n+m))$
- **初始化 BIT**：$n$ 次 `update_root`，$O(n \log n \log V)$
- **$m$ 次操作**：最坏全是 opt 2/4/5，$O(m \log n \log^2 V)$

合并后总时间复杂度：

$$
T(n,m) = O\bigl((n+m)\,\log n \,\log^2 V\bigr) \;=\; O\bigl((n+m)\log^3 n\bigr)
$$

代入 $n=m=5\times 10^4$，$\log n\approx 16$，$\log V\approx 17$：

$$
10^5 \times 16 \times 17^2 \approx 2.3\times 10^8
$$

理论上能过，但常数偏大（动态开点 `new` + 递归 + opt2 的二分套二分），实际很容易卡到 $5\times 10^8$ 量级，**容易 TLE**。

## 空间复杂度

每次 `update_root` 调 $\log n$ 棵线段树，每棵最多新建 $\log V$ 个节点。

- 初始建：$\sum_{j=1}^n \text{lowbit}(j)\cdot \log V = O(n\log n \log V)$ 上界（因 $\sum \text{lowbit}(j)=\Theta(n\log n)$）。  
- opt 3 的修改：$O(m\log n\log V)$ 上界。

总节点数（上界）：

$$
S = O\bigl((n+m)\,\log n \,\log V\bigr)
$$

代入：$10^5\times 16\times 17 \approx 2.7\times 10^7$ 节点。  
每个 `Node` 在 64 位下大约 32 字节（`l,r,sum` 各 4 字节 + 两个指针 8 字节 + 对齐），上界约 **860 MB**。

> 由于段树路径共享，**实际节点数远小于该上界**（通常约 $5\times 10^6 \sim 1\times 10^7$，即 150 MB 左右），但仍是这份代码相对题目内存最紧张的部分。

## 主要瓶颈

`opt2` 中"**值域二分 × 树状数组 × 段树区间查询**"的三层嵌套，把单次 opt 2/4/5 推到了 $O(\log n \log^2 V)$。  
若把 `opt2` 改为「**多棵线段树同步往下走**」（即 `kth` 风格），可降到 $O(\log n \log V)$，整体退化为 $O((n+m)\log^2 n)$，常数也更小（这是 `ans.cpp` 中所采用的方案）。
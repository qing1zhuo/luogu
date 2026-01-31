# P2345 [USACO04OPEN] MooFest G

## 题目背景

[P5094 [USACO04OPEN] MooFest G Enhanced Edition](https://www.luogu.com.cn/problem/P5094)

## 题目描述

John’s $n$ cows attend “MooFest” every year.

MooFest is a grand event in the cow world. There are many activities at the gathering, such as stacking hay, jumping over fences, and patting cowboys on the butt.

When they participate in activities, they gather together. The $i$-th cow is located at coordinate $x_i$, and no two cows share the same coordinate.

The cows are very loud. When the $i$-th and $j$-th cows communicate, they produce a volume of $\max\{v_i, v_j\} \times |x_i - x_j|$, where $v_i$ and $v_j$ are the hearing abilities of cows $i$ and $j$, respectively.

Assume that every pair of cows is talking at the same time. Please compute the sum of the volume produced by all cows.

## 输入格式

- The first line: a single integer $n$, $1 \le n \le 2 \times 10^4$.
- Lines $2$ to $n + 1$: the $(i + 1)$-th line contains two integers $v_i$ and $x_i$ ($1 \le v_i, x_i \le 2 \times 10^4$).

## 输出格式

A single integer: the total volume produced by all cows.

## 输入输出样例 #1

### 输入 #1

```
4
3 1
2 5
2 6
4 3
```

### 输出 #1

```
57
```

## 说明/提示

Translated by ChatGPT 5
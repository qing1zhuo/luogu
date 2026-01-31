# P1257 Closest Pair of Points in the Plane

## 题目描述

Given $n$ points in the plane, find the distance between a pair of points such that among all pairs of these $n$ points, this distance is the smallest.

## 输入格式

The first line contains an integer $n$, denoting the number of points.
The next $n$ lines each contain two integers $x,y$, representing the $x$ and $y$ coordinates of a point.

## 输出格式

Output a single line containing a real number, which is the shortest distance, rounded to $4$ decimal places.

## 输入输出样例 #1

### 输入 #1

```
3
1 1
1 2
2 2

```

### 输出 #1

```
1.0000

```

## 说明/提示

#### Constraints

For $100\%$ of the testdata, it is guaranteed that $2 \leq n \leq 10^4$, $0 \leq x, y \leq 10^9$.

Translated by ChatGPT 5
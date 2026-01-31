# P1228 Carpet Tiling Problem

## 题目背景

# Description

It is said that in an ancient Arabian country, there was a palace. Inside the palace, there was a square grid maze. The king’s method for choosing a prince consort was very special and simple: the princess stood on one grid cell, and whoever could cover every other cell with carpets, except the one where the princess stood, would win the beautiful, elegant, and intelligent princess. The princess’s cell must not be covered, and the carpet shape is restricted to four options only (see the figure):

![](https://cdn.luogu.com.cn/upload/image_hosting/cik5fiow.png)

Each grid cell may be covered by at most one layer of carpet. The maze is a square of size $2^k\times 2^k$. The time limit is $1$ second.

## 题目描述

无

## 输入格式

无

## 输出格式

Output a complete tiling plan: each placement (one line) is $x\ y\ c$ ($x, y$ are the row and column of the carpet’s corner cell, and $c$ is the carpet’s shape; see Figure $1$ above. The four shapes are represented by $1, 2, 3, 4$. Separate $x, y, c$ with a single space).

## 输入输出样例 #1

### 输入 #1

```
3                          
3 3   
```

### 输出 #1

```
5 5 1
2 2 4
1 1 4
1 4 3
4 1 2
4 4 1
2 7 3
1 5 4
1 8 3
3 6 3
4 8 1
7 2 2
5 1 4
6 3 2
8 1 2
8 4 1
7 7 1
6 6 1
5 8 3
8 5 2
8 8 1

```

## 说明/提示

Explanation of SPJ error codes:

1. $c$ is out of range.
2. $x, y$ are out of range.
3. The position $(x, y)$ has already been covered.
4. The position $(x, y)$ was never covered.

$\text{upd 2023.8.19}$: Added sample explanation.

### Sample Explanation

![](https://cdn.luogu.com.cn/upload/image_hosting/r9j8r452.png)

Translated by ChatGPT 5
# P1966 [NOIP 2013 Senior] Matchsticks Lineup

## 题目背景

NOIP 2013 Senior D1T2.

## 题目描述

Hanhan has two boxes of matches, each containing $n$ matches. Every match has a height. Now arrange the matches from each box into a column. Within the same column, all heights are distinct. Define the distance between the two columns as $ \sum (a_i-b_i)^2$.

Here $a_i$ is the height of the $i$-th match in the first column, and $b_i$ is the height of the $i$-th match in the second column.

You may swap adjacent matches within each column. Please minimize the distance between the two columns by swapping. What is the minimum number of swaps needed to achieve this minimum distance? If this number is too large, output the result of this minimum number of swaps modulo $10^8-3$.

## 输入格式

There are three lines in total. The first line contains an integer $n$, the number of matches in each box.

The second line contains $n$ integers separated by single spaces, representing the heights of the matches in the first column.

The third line contains $n$ integers separated by single spaces, representing the heights of the matches in the second column.

## 输出格式

Output a single integer: the minimum number of swaps modulo $10^8-3$.

## 输入输出样例 #1

### 输入 #1

```
4
2 3 1 4
3 2 1 4

```

### 输出 #1

```
1
```

## 输入输出样例 #2

### 输入 #2

```
4
1 3 4 2
1 7 2 4
```

### 输出 #2

```
2
```

## 说明/提示

Explanation for Sample 1:

The minimum distance is $ 0$; the minimum number of swaps is $1$. For example, swap the first $ 2$ matches in column $1$, or swap the first $2 $ matches in column $2$.

Explanation for Sample 2:

The minimum distance is $10$; the minimum number of swaps is $2$. For example, swap the middle $2$ matches in column $1$, and then swap the last $2$ matches in column $2$.

Constraints

- For $10\%$ of the testdata, $1 \leq n \leq 10$.
- For $30\%$ of the testdata, $1 \leq n \leq 100$.
- For $60\%$ of the testdata, $1 \leq n \leq 10^3$.
- For $100\%$ of the testdata, $1 \leq n \leq 10^5$, $0 \leq a_i,b_i < 2^{31}$, and for any $1 \le i < j \le n$, $a_i \neq a_j$, $b_i \neq b_j$.

Translated by ChatGPT 5
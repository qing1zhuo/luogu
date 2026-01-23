# P4552 [Poetize6] IncDec Sequence

## 题目描述

Given a sequence of length $n$, ${a_1,a_2,\cdots,a_n}$, in each operation you may choose an interval $[l, r]$ and either add $1$ to every number in this interval or subtract $1$ from every number in this interval.
  
What is the minimum number of operations needed to make all numbers in the sequence equal, and under this minimum, how many different final sequences are possible?

## 输入格式

The first line contains a positive integer $n$.
Then $n$ lines follow; the integer on the $(i+1)$-th line is $a_i$.

## 输出格式

Output the minimum number of operations on the first line.
Output the number of possible final sequences on the second line.

## 输入输出样例 #1

### 输入 #1

```
4
1
1
2
2
```

### 输出 #1

```
1
2
```

## 说明/提示

Constraints: For $100\%$ of the testdata, $n \le 100000$, $0 \le a_i \le 2^{31}$.

Translated by ChatGPT 5
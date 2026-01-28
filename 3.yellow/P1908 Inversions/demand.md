# P1908 Inversions

## 题目描述

Cat TOM and mouse JERRY are competing again. But since they are adults now, they no longer enjoy playing chase games; these days, they like counting.

Recently, old cat TOM read about something humans call “inversions,” defined as follows: for a given sequence of positive integers, an inversion is an ordered pair where $a_i > a_j$ and $i < j$. After learning this concept, they compete to see who can first compute the number of inversions in a given sequence of positive integers. Note that the sequence may contain duplicate numbers.

**Update: testdata has been strengthened.**

## 输入格式

The first line contains an integer $n$, indicating that the sequence has $n$ numbers.

The second line contains $n$ integers, representing the given sequence. Each number is at most $10^9$.

## 输出格式

Output the number of inversions in the sequence.

## 输入输出样例 #1

### 输入 #1

```
6
5 4 2 6 3 1

```

### 输出 #1

```
11
```

## 说明/提示

For 25% of the testdata, $n \leq 2500$.

For 50% of the testdata, $n \leq 4 \times 10^4$.

For all testdata, $1 \leq n \leq 5 \times 10^5$.

No one should pass $O(n^2)$ on 500,000, right — 2018.8 chen_zhe.

Translated by ChatGPT 5
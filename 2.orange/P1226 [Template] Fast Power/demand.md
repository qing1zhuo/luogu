# P1226 [Template] Fast Power

## 题目描述

Given three integers $a$, $b$, $p$, compute $a^b \bmod p$.

## 输入格式

The input contains a single line with three integers representing $a$, $b$, $p$.

## 输出格式

Output one line with the string `a^b mod p=s`, where $a$, $b$, $p$ are the given values and $s$ is the result.

## 输入输出样例 #1

### 输入 #1

```
2 10 9

```

### 输出 #1

```
2^10 mod 9=7

```

## 说明/提示

Sample Explanation:

$2^{10} = 1024$，$1024 \bmod 9 = 7$.

Constraints:

For $100\%$ of the testdata, it is guaranteed that $0 \leq a, b < 2^{31}$, $a + b > 0$, $2 \leq p \lt 2^{31}$.

Translated by ChatGPT 5
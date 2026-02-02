# P5094 [USACO04OPEN] MooFest G Enhanced Version

## 题目描述

Every year, John’s $N$ cows take part in the MooFest, a big festival for cows all over the world. The festival has many fun activities, such as haystack piling contests and cow-pen jumping contests. Sometimes the cows also poke each other for fun. Of course, they will line up and moo loudly to celebrate their holiday.

The cows’ moos are so noisy that each cow’s hearing is damaged to a different degree. Now you are given cow $i$’s hearing level $v_i$. This means that if cow $j$ wants to say something that cow $i$ can hear, cow $j$ must use a volume greater than $v_i \times dis(i,j)$. Therefore, if cows $i$ and $j$ want to talk to each other, their volume must be at least $\max(v_i, v_j) \times dis(i,j)$, where $dis(i,j)$ is the distance between them.

Now the $N$ cows are standing on a straight line, and each cow has a coordinate $x_i$. If every pair of cows is talking, and each pair uses the minimum required volume, what is the sum of the volumes over all $N(N-1)/2$ pairs?

## 输入格式

The first line contains an integer $N$.

The next $N$ lines each contain two numbers $v_i$ and $x_i$, representing the $i$-th cow’s hearing level and coordinate, respectively.

## 输出格式

Output one number, which is the sum of the volumes when these $N(N-1)/2$ pairs of cows talk.

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

### Constraints

Since an $O(N^2)$ algorithm can pass under the original data, some additional enhanced testdata has been added.

The original data is Subtask $1$, and the newly added data is Subtask $2$.

- Subtask $1$ ($1$ point): $1 \leq N, V_i, x_i \leq 2 \times 10^4$.
- Subtask $2$ ($99$ points): $1 \leq N, V_i, x_i \leq 5 \times 10^4$.

Translated by ChatGPT 5
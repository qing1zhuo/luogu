/*函数递归*/

#include <stdio.h>

#define MAX_N 5001  // 最大包数量，根据题目限制设定

// 存储依赖关系：dep[i]存储第i个包的所有依赖
int dep[MAX_N][MAX_N];
// 每个包的依赖数量
int dep_count[MAX_N];
// 访问标记：0表示未访问，1表示已访问
int visited[MAX_N];

// 递归计算包及其所有依赖的总数
int count_packages(int package) {
    // 已访问过，直接返回0
    if (visited[package]) {
        return 0;
    }
    
    // 标记为已访问
    visited[package] = 1;
    int total = 1;  // 当前包本身
    
    // 递归计算所有依赖包
    for (int i = 0; i < dep_count[package]; i++) 
    {
        total += count_packages(dep[package][i]);
    }
    
    return total;
}

int main() {
    int n;
    scanf("%d", &n);
    
    // 初始化数组
    for (int i = 1; i <= n; i++) {
        dep_count[i] = 0;
        visited[i] = 0;
    }
    
    // 读取每个包的依赖关系
    for (int i = 1; i <= n; i++) {
        scanf("%d", &dep_count[i]);
        for (int j = 0; j < dep_count[i]; j++) {
            scanf("%d", &dep[i][j]);
        }
    }
    
    // 计算安装1号包所需的总数量
    printf("%d\n", count_packages(1));
    
    return 0;
}
    
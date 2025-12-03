#include<stdio.h>
int line[110][4]; // line[i][1]：身高；line[i][2]：以i为终点的LIS长度；line[i][3]：以i为终点的LDS长度
int n;
int ans = 0;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        
    {
        scanf("%d", &line[i][1]);
        line[i][2] = 1; // 初始LIS：只有自己，长度1
        line[i][3] = 1; // 初始LDS：只有自己，长度1
    }

    // 1. 计算以每个i为终点的LIS（左→右遍历，看左边比i矮的）
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            if (line[j][1] < line[i][1] && line[j][2] + 1 > line[i][2])
            {
                line[i][2] = line[j][2] + 1;
            }
        }
    }

    // 2. 计算以每个i为终点的LDS（右→左遍历，看右边比i矮的）
    for (int i = n - 1; i >= 1; i--)
    {
        for (int j = n; j > i; j--)
        {
            if (line[j][1] < line[i][1] && line[j][3] + 1 > line[i][3])
            {
                line[i][3] = line[j][3] + 1;
            }
        }
    }

    // 3. 找最长合唱队形长度（去重），计算最少出列人数
    for (int i = 1; i <= n; i++)
    {
        int current = line[i][2] + line[i][3] - 1; // 关键：减1去重
        if (current > ans)
            ans = current;
    }
    printf("%d", n - ans); // 总人数 - 最长队形长度 = 最少出列人数

    return 0;
}
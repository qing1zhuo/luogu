#include<stdio.h>
typedef unsigned long long llu;

int examine(int origin, int p)//检查是否属于该进制
{
    if(origin == 0) 
        return 1;//0在任何进制下都合法
    while(origin)
    {
        int cur = origin % 10;
        if (cur >= p)
            return 0;//未通过进制检查返回0
        origin /= 10;
    }
    return 1;//通过检查返回1
}

llu trans(int origin, int p)//进制转换函数
{
    if(origin == 0) 
        return 0;//0在任何进制下都为0
    int digit = 0;
    llu dest = 0;
    int rever[20] = {0};//存储反转后的数字
    while(origin)
    {
        rever[digit] = origin%10;
        origin /= 10;digit++;
    }
    for(int i=digit-1;i>=0;i--)
    {
        dest = dest * p + rever[i];
    }
    return dest;
}
int main()
{
    int p, q, r;
    scanf("%d%d%d", &p, &q, &r);
    for (int i = 2; i <= 16; i++)
    {
        if(!examine(p, i) || !examine(q, i) || !examine(r, i))
            continue;//未通过进制检查则跳过
        llu p2 = trans(p, i);
        llu q2 = trans(q, i);
        llu r2 = trans(r, i);
        if ((p2 * q2) == r2)
        {
            printf("%d", i);
            return 0;
        }
    }
    printf("%d", 0);
    return 0;
}
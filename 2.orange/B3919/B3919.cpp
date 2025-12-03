#include<stdio.h>

int main()
{
    unsigned long long n;
    int q;
    scanf("%d%d", &n, &q);
    unsigned long long sum = 0;
    for (int i = 1; i <= q; i++)
    {
        int k = 0;
        scanf("%d", &k);
        if (n & (1ll << (k - 1)))//若第k位为1
            ;
        else
        {
            unsigned long long p = 1ll << (k - 1);//第k位为1的数
            unsigned long long x=p-(n%p);
            n += x;
            sum += x;
        }
    }
    printf("%d\n", sum);
    return 0;
}
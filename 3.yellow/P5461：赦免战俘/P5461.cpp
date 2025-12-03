#include<stdio.h>
int a[1050][1050] = { 1 };
void sacri(int a[][1050], int x1, int y1, int x2, int y2)
{
    int wide = x2 - x1 + 1;
    int high = y2 - y1 + 1;
    if (x1 == x2 && y1 == y2) {
        a[x1][y1]=1;
        return;
    }
    for (int i = x1; i < x1 + wide / 2; i++)
    {
        for (int j = y1; j < y1 + high / 2; j++)
        {
            a[i][j] = 0;
        }
    }

    sacri(a, x1, y1 + high / 2, x2 - wide / 2, y2);
    sacri(a, x1 + wide / 2, y1, x2, y2 - high / 2);
    sacri(a, x1 + wide / 2, y1 + high / 2, x2, y2);
}
int trans(int n)
{
    int obi = 1;
    for (int i = 1; i <= n; i++)
    {
        obi = obi * 2;
    }
    return obi;
}
int main()
{
    int n;
    scanf("%d", &n);
    int n_t = trans(n);
    sacri(a, 1, 1, n_t, n_t);
    for (int i = 1; i <= n_t; i++)
    {
        for (int j = 1; j <= n_t; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}

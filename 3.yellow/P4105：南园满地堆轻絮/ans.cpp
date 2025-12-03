#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <climits>
using namespace std;
typedef long long ll;

const int MAXN = 5e6 + 7;
ll SA, SB, SC, SD, HA;
ll a[MAXN], n, b[MAXN];

ll F(ll x) {
    return ((x * x % HA * x % HA * SA % HA) + (x * x % HA * SB % HA) + (x * SC % HA) + SD) % HA;
}

bool check(ll k) {
    memcpy(b, a, sizeof a);//把a拷贝到b数组
    b[1] = max(0ll, b[1] - k);
    for (int i = 2; i <= n; i++) {
        b[i] = max(b[i - 1], b[i] - k);
        if (abs(a[i] - b[i]) > k) return false;
    }
    return true;
}

int main(int argc, char *argv[]) {
    ll l = 0, r = INT_MIN;
    scanf("%lld %lld %lld %lld %lld %lld %lld", &n, &SA, &SB, &SC, &SD, a + 1, &HA);
    r = max(r, a[1]);//此时r等于a[1]
    for (int i = 2; i <= n; i++) {
        a[i] = (F(a[i - 1]) + F(a[i - 2]) + HA) % HA;//a数组生成
        r = max(r, a[i]);//r变为a数组最大值
    }
    ll ans = r;
    while (l <= r) {
        ll mid = l + r >> 1ll;//除以2
        if (check(mid)) ans = mid, r = mid - 1;
        else l = mid + 1;
    }
    printf("%lld\n", ans);
    return 0;
}

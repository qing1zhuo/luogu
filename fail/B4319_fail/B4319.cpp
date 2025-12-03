#include<iostream>
using namespace std;

typedef struct aivity
{
    int type;

    int year;
    bool leap_year;

    int month;
    int monthday;

    int day;

    int time;
}aivity;
aivity a[5005];
void my_read(int i);
bool cmp_time(int i,int j);
bool leap_year(int year);
int month_day(int i);
void add_day(int i);
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        my_read(i);
        a[i].leap_year=leap_year(a[i].year);
        a[i].monthday=month_day(i);
    }

        for (int i = 1; i <= n; ++i) {
        bool has_conflict;
        do {
            has_conflict = false;
            // 检查所有活动对 (x, y)，x < y（确保先到先得逻辑）
            for (int x = 1; x <= i; ++x) {
                for (int y = x + 1; y <= i; ++y) {
                    if (cmp_time(x, y)) {  // 发现冲突
                        has_conflict = true;
                        // 根据规则调整冲突活动
                        if (a[x].type != a[y].type) {
                            // 不同类型：优先级低的后移
                            if (a[x].type < a[y].type) {  // x优先级高，y后移
                                add_day(y);
                            } else {  // x优先级低，x后移
                                add_day(x);
                            }
                        } else {  // 同类型：后到的（y）后移
                            add_day(y);
                        }
                        // 调整后需重新检查所有冲突，跳出当前循环
                        goto restart_check;
                    }
                }
            }
            restart_check:;  // 跳转标签，用于调整后重新检查
        } while (has_conflict);  // 直到无冲突为止
    }

    for(int i=1;i<=n;i++)
    {
        printf("%d",a[i].year);
        printf("%02d",a[i].month);
        printf("%02d",a[i].day);
        cout<<endl;
    }
    return 0;
}

void add_day(int i)//时间累加函数
{
    a[i].day++;
    if(a[i].day>a[i].monthday)
    {
        a[i].day=1;
        a[i].month++;
        a[i].monthday=month_day(a[i].month);
    }
    if(a[i].month>12)
    {
        a[i].month=1;
        a[i].monthday=month_day(a[i].month);
        a[i].year++;
        a[i].leap_year=leap_year(a[i].year);
    }
}
int month_day(int i)//月份日期计算函数
{
    if(a[i].month==2){
        if(a[i].leap_year)return 29;
        else return 28;
    }
    else if((a[i].month<=7&&a[i].month%2==1)||(a[i].month>=8&&a[i].month%2==0))return 31;
    else return 30;
}
bool leap_year(int year)//闰年判断函数
{
    if(year%4==0&&year%100!=0)return true;
    else if(year%400==0)return true;
    else return false;
}
bool cmp_time(int i,int j)//时间比较函数
{
    if(a[i].year==a[j].year&&a[i].month==a[j].month&&a[i].day==a[j].day&&a[i].time==a[j].time)return true;
    else return false;
}
void my_read(int i)
{
    char _type;long long _date;char _time;
    cin>>_type>>_date>>_time;

    if(_type=='O')a[i].type=1;
    else if(_type=='C')a[i].type=2;
    else if(_type=='P')a[i].type=3;

    a[i].day=_date%100;
    _date/=100;
    a[i].month=_date%100;
    _date/=100;
    a[i].year=_date;

    if(_time=='M')a[i].time=1;
    else if(_time=='A')a[i].time=2;
    else if(_time=='E')a[i].time=3;
}
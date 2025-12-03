#include<stdio.h>
double a,b,c,d;
double func(double);
double find(double,double);

int main()
{
    scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
    for(double i=-100;i<=99;i++)
    {
        double u=func(i);double v=func(i+1);
        if(u==0)printf("%.2lf ",i);
        else if(u*v<0)
        {
            double ans=find(i,i+1);
            printf("%.2lf ",ans);
        }
    }
}

double find(double left,double right)
{
    double mid=(left+right)/2;
    double mid_func=func(mid);double left_func=func(left);

    if(mid_func==0)return mid;
    if((right-left)<=0.001)return left;
    if(left_func*mid_func<0)return find(left,mid);
    else return find(mid,right);
}

double func(double x)
{
    double y=a*x*x*x+b*x*x+c*x+d;
    return y;
}
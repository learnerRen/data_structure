#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;
double df(double x,double y)
{
	return 42*pow(x,6)+54*pow(x,5)+15*pow(x,2)+4*x-y;
}
double cal(int iteration,double xl,double xr,double x,double y)
{
	double r;
	while(iteration)
	{
		if(df(x,y)*df(xl,y)<0)
		{
			xr=x;
			x=(xl+xr)/2;
		}
		if(df(x,y)*df(xr,y)<0)
		{
			xl=x;
			x=(xl+xr)/2;
		}
		if(df(x,y)==0)
			break;
		if(df(xl,y)==0)
		{
			x=xl;
			break;
		}
		if(df(xr,y)==0)
		{
			x=xr;
			break;
		}
		--iteration;
	}
	/*cout<<"x:"<<x<<endl;
	cout<<"xl:"<<xl<<endl;
	cout<<"xr:"<<xr<<endl;
	cout<<"rl:"<<42*pow(xl,6)+54*pow(xl,5)+15*pow(xl,2)+4*xl-y<<endl;
	cout<<"rr:"<<42*pow(xr,6)+54*pow(xr,5)+15*pow(xr,2)+4*xr-y<<endl;
	cout<<"rx:"<<42*pow(x,6)+54*pow(x,5)+15*pow(x,2)+4*x-y<<endl;*/
	r=6*pow(x,7)+9*pow(x,6)+5*pow(x,3)+2*x*x-y*x;
	return r;
}
int main()
{
	int n;
	cin>>n;
	while(n)
	{
		double y;
		cin>>y;
		int iteration=200;
		double xl=0,xr=200;
		double x=0;
		double r=0;
		if(df(xl,y)>0)
		{
			x=xl;
			r=6*pow(x,7)+9*pow(x,6)+5*pow(x,3)+2*x*x-y*x;
		}
		else
		{
			x=(xr+xl)/2;
			r=cal(iteration,xl,xr,x,y);
		}
		cout<<setiosflags(ios::fixed)<<setprecision(4)<<r<<endl;
		--n;
	}
}

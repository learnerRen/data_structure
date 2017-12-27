#include <iostream>
#include <algorithm>
using namespace std;
int n;
int main()
{
	cin>>n;
	while(n)
	{
		int s;
		cin>>s;
		int data[s];
		int e=0;
		for(int i=0;i<s;++i)
		{
			cin>>data[i];
		}
		for(int i=0;i<s-1;++i)
		{
			sort(data,data+s);
			e=e+data[i]+data[i+1];
			data[i+1]=data[i]+data[i+1];
			data[i]=-1;
		}
		cout<<e<<endl;
		--n;
	}
}

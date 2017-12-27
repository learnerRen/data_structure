#include <iostream>
#include <algorithm>
using namespace std;
bool large(int a, int b)
{
	return a>b;
}
int main()
{
	int S,Q,n;
	cin>>n;
	while(n)
	{
		cin>>S>>Q;
		int data[S],datas[S];
		for(int i=0;i<S;++i)
		{
			int brightness;
			cin>>brightness;
			data[i]=brightness;
			datas[i]=brightness;
		}
		sort(datas,datas+S,large);
		for(int i=0;i<Q;++i)
		{
			int p;
			cin>>p;
			int v=data[p-1];
			int p2=0;
			for(int j=0;j<S;++j)
			{
				if(v==datas[j])
					p2=j+1;
			}
			cout<<p2<<endl;
		}
		--n;
	}
}

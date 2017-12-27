#include <iostream>
using namespace std;
int main()
{
	int m,n;
	while(cin>>m>>n)
	{
		cout<<"+";
		for(int i=2;i<m;++i)
		{
			cout<<"-";
		}
		cout<<"+"<<endl;
		for(int i=2;i<n;++i)
		{
			cout<<"|";
			for(int j=2;j<m;++j)
				cout<<'a';
			cout<<"|"<<endl;;
		}cout<<"+";
		for(int i=2;i<m;++i)
		{
			cout<<"-";
		}
		cout<<"+"<<endl;
		
	}
}

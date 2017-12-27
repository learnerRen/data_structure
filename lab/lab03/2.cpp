#include <iostream>
#include <queue>
using namespace std;
int main()
{
	int t,n;
	while(cin>>t)
	{
		cin>>n;
		queue<int> q;
		for(int i=0;i<n;++i)
			q.push(i+1);
		while(!q.empty())
		{
			int flag=0;
			for(int i=0;i<t-1;++i)
			{
				if(q.empty())
				{
					flag=1;
					break;
				}
				q.push(q.front());
				q.pop();
			}
			cout<<q.front()<<" ";
			q.pop();
		}
		cout<<endl;
	}
}

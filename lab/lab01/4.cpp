#include<iostream>
#include <string>
using namespace std;
int l[26];
int main()
{
	string s;
	while(getline(cin,s))
	{
		for(int i=0;i<26;++i)
			l[i]=0;
		for(int i=0;i<s.length();++i)
	{
		if(((int)s[i]>=65&&(int)s[i]<=90))
			++l[(int)s[i]-65];
		if((int)s[i]>=97&&(int)s[i]<=122)
			++l[(int)s[i]-97];
	}
	for(int i=0;i<26;++i)
	{
		if(l[i]!=0)
		{
			cout<<char(65+i)<<" "<<l[i]<<endl;
		}
	 } 
	}
	
}

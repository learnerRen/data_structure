#include <iostream>
#include <vector>
#include <string> 
using namespace std;
struct customer
{
	int start,last;
	string name;
}cus[1000],wait[100];
int main()
{
	int n;
	cin>>n;
	int a;
	cin>>a;
	int count=0,final=0;
	for(;a!=-1;++count)
	{
		cus[count].start=a;
		cin>>cus[count].name>>cus[count].last;
		--cus[count].last;
		cin>>a;
		if((cus[count].last+cus[count].start)>final)
			final=cus[count].last+cus[count].start;
	}
	struct customer tell[n];
	int count1=0;
	int count2=0;
	for(int i=0;i<n;++i)
	{
		tell[i].name="NULL";
		tell[i].start=1000;
		tell[i].last=1000; 
	} 
		
	for(int i=1;i<=final-1;++i)
	{
		cout<<i<<":"<<endl;
		for(int j=count2;j<count;++j)
		{
			if(cus[j].start<=i&&(cus[j].last+cus[j].start)>=i)
				{
					wait[count1++]=cus[j];
					++count2;	
				}
		}
		for(int j=0;j<n&&count1>0;++j)
		{
			if(tell[j].name=="NULL")
			{
				tell[j]=wait[0];
				--count1;
				for(int k=0;k<count1;++k)
					wait[k]=wait[k+1];
			}
		}
		for(int j=0;j<count1;++j)
		{
			++wait[j].start;
			if(final<(wait[j].start+wait[j].last))
					final=wait[j].start+wait[j].last;
		}
		for(int j=0;j<n;++j)
		{
			cout<<"Teller"<<j+1<<": "<<tell[j].name<<endl; 
		}
		if(count1==0)
			cout<<"Waiting: NULL"<<endl;
		else
		{
			cout<<"Waiting: ";
			for(int j=0;j<count1-1;++j)
			{
				cout<<wait[j].name<<" "; 
			}
			for(int j=count1-1;j<count1;++j)
			{
				cout<<wait[j].name; 
			}
			cout<<endl;
		}
		for(int j=0;j<n;++j)
		{
			if((tell[j].start+tell[j].last)<=i)
			{
				tell[j].name="NULL";
				tell[j].start=1000;
				tell[j].last=1000; 
			}
		} 
		cout<<endl;
	}
	for(int i=final;i<=final;++i)
	{
		cout<<i<<":"<<endl;
		for(int j=count2;j<count;++j)
		{
			if(cus[j].start<=i&&(cus[j].last+cus[j].start)>=i)
				{
					wait[count1++]=cus[j];
					++count2;	
				}
		}
		for(int j=0;j<n&&count1>0;++j)
		{
			if(tell[j].name=="NULL")
			{
				tell[j]=wait[0];
				--count1;
				for(int k=0;k<count1;++k)
					wait[k]=wait[k+1];
			}
		}
		for(int j=0;j<count1;++j)
		{
			++wait[j].start;
			if(final<(wait[j].start+wait[j].last))
					final=wait[j].start+wait[j].last;
		}
		for(int j=0;j<n;++j)
		{
			cout<<"Teller"<<j+1<<": "<<tell[j].name<<endl; 
		}
		if(count1==0)
			cout<<"Waiting: NULL"<<endl;
		else
		{
			cout<<"Waiting: ";
			for(int j=0;j<count1-1;++j)
			{
				cout<<wait[j].name<<" "; 
			}
			for(int j=count1-1;j<count1;++j)
			{
				cout<<wait[j].name; 
			}
			cout<<endl;
		}
		for(int j=0;j<n;++j)
		{
			if((tell[j].start+tell[j].last)<=i)
			{
				tell[j].name="NULL";
				tell[j].start=1000;
				tell[j].last=1000; 
			}
		}
	}
}

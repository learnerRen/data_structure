#include <iostream>
#include <string>
#include<iomanip> 
using namespace std;
struct student{
	string name;
	int ID;
	int subject1;
	int subject2;
	int subject3;
};
int main()
{
	int N;
	while(cin>>N)
	{
		student stu[N];
		int total[N];
		for(int i=0;i<N;++i)
		{
			cin>>stu[i].name>>stu[i].ID>>stu[i].subject1>>stu[i].subject2>>stu[i].subject3;
			total[i]=stu[i].subject1+stu[i].subject2+stu[i].subject3;
		}
		for(int i=0;i<N;++i)
		{
			for(int j=0;j<N-1;++j)
			{
				if(total[j]<total[j+1])
				{
					int tmp=total[j];
					total[j]=total[j+1];
					total[j+1]=tmp;
					student temp1=stu[j];
					stu[j]=stu[j+1];
					stu[j+1]=temp1;
				}
				if(total[j]==total[j+1]&&stu[j].ID>stu[j+1].ID)
				{
					int tmp=total[j];
					total[j]=total[j+1];
					total[j+1]=tmp;
					student temp1=stu[j];
					stu[j]=stu[j+1];
					stu[j+1]=temp1;
				}
			}
		}
		for(int i=0;i<N;++i)
		{
			cout<<stu[i].name<<" "<<setfill('0')<<setw(6)<<stu[i].ID<<" "<<
			stu[i].subject1<<" "<<stu[i].subject2<<" "<<stu[i].subject3<<endl;
		}
	}
}

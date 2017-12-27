#include <iostream>
#include <string>
using namespace std;
class Link
{
public:
	int element;
	Link *next;
	Link(int elemval,Link *nextval=NULL)
	{
		element=elemval;
		next=nextval;
	}
	Link(Link *nextval=NULL)
	{
		next=nextval;
	}
};

class LList : public Link
{
public:
	Link *head;
	Link *tail;
	Link *fence;
	int left;
	int right;
	void initial()
	{
		head=new Link();
		fence=head;
		tail=head;
		left=0;
		right=0;
	}
	bool insert(int);
	int remove();
	void rshow();
	void show();
	bool delete1(int);
};
bool LList::insert(int n)
{
	for(int i=0;i<n;++i)
	{
		int item;
		cin>>item;
		fence->next=new Link(item,fence->next);
		if(tail==fence)
			tail=tail->next;
		++right;
		fence=fence->next;
	}
	return true;
}
bool LList::delete1(int item)
{
	Link *temp=head;
	if(temp->next==NULL) return false;
	for(;temp->next!=NULL;temp=temp->next)
	{
		if(temp->next->element==item)
		{
			temp->next=temp->next->next;
			--right;
		}
	}
}
int LList::remove()
{
	if(fence->next==NULL) return false;
	int it=fence->next->element;
	Link *litem=fence->next;
	fence->next=litem->next;
	if(tail==fence)
		tail = fence->next;
	int a=litem->element;
	delete litem;
	--right;
	return a;
}

void LList::show()
{
	Link *temp=head;
	while(temp!=fence)
	{
		cout<<temp->next->element<<" ";
		temp=temp->next;
	}
	while(temp->next!=NULL)
	{
		cout<<temp->next->element<<" ";
		temp=temp->next;
	}
	cout<<endl;
}
void LList::rshow()
{
	Link *temp=head;
	for(int i=left+right;i>0;--i)
	{
		for(int j=0;j<i;++j)
			temp=temp->next;
		cout<<temp->element<<" ";
		temp=head;
	}
	cout<<endl;
}
int main()
{
	LList L;
	L.initial();
	string a;
	while(cin>>a)
	{
		if(a=="insert")
		{
			int b;
			cin>>b;
			L.insert(b);
		}
		if(a=="show")
			L.show();
		if(a=="rshow")
			L.rshow();
		if(a=="delete")
		{
			int b;
			cin>>b;
			L.delete1(b);	
		}
		if(a=="END")
			break;
	} 
	/*cout<<"insert"<<endl;
	int n;
	cin>>n;
	L.insert(n);
	cout<<"show"<<endl;
	L.show();
	cout<<"insert"<<endl;
	cin>>n;
	L.insert(n);
	cout<<"delete"<<endl;
	cin>>n;
	L.delete1(n);
	cout<<"show"<<endl;
	L.show();
	cout<<"rshow"<<endl;
	L.rshow();
	cout<<"END";*/ 
} 

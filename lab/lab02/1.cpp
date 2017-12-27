#include <iostream>
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
		fence=new Link();
		tail=fence;
		head=fence;
		left=0;
		right=0;
	}
	bool insert(int);
	int remove();
	bool setpos(int);
	void print();
};
bool LList::insert(int item)
{
	fence->next=new Link(item,fence->next);
	if(tail==fence)
		tail=tail->next;
	++right;
	return true;
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
bool LList::setpos(int pos)
{
	if((pos<0)||(pos>right+left)) return false;
	fence=head;
	for(int i=0;i<pos;++i)
		fence=fence->next;
	right=right+left-pos;
	left=pos;
	return true;
}
void LList::print()
{
	Link *temp=head;
	while(temp!=fence)
	{
		cout<<temp->next->element<<" ";
		temp=temp->next;
	}
	cout<<"|";
	while(temp->next!=NULL)
	{
		cout<<temp->next->element<<" ";
		temp=temp->next;
	}
}
int main()
{
	LList L;
	L.initial();
	cout<<"insert10"<<endl;
	L.insert(10);
	cout<<"insert20"<<endl;
	L.insert(20);
	cout<<"insert30"<<endl;
	L.insert(30);
	cout<<"print:";L.print();cout<<endl;
	cout<<"setpos(2)"<<endl;
	L.setpos(2);
	cout<<"remove:"<<L.remove()<<endl;
 } 

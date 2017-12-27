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
class LStack : public Link
{
public:
	Link *top;
	int size;
	LStrack(int sz=0)
	{
		top=NULL;
		size=sz;
	}
	int pop();
	bool push(int);
};
int LStack::pop()
{
	if(size==0) return false;
	int val=top->element;
	Link *temp=top->next;
	top=temp;
	--size;
	return val;
}
bool LStack::push(int val)
{
	Link *temp=top;
	top=new Link(val,temp);
	++size;
	return true;
}
int main()
{
	LStack L;
	cout<<"push(10)"<<endl;
	cout<<"push(20)"<<endl;
	L.push(10);
	L.push(20);
	cout<<"pop:"<<L.pop()<<endl;
	cout<<"pop:"<<L.pop()<<endl;
 } 

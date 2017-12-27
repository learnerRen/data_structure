#include<iostream>
#include<stack>
#include<string>
using namespace std;
int edge[27][27];
int used[27];
int visited[27];
int n,m;
stack<int> s;
stack<int> result;
bool checked(int v);
bool Inconsistency();
void p();
void DFS(int v);
bool solve();

int main()
{
    while(cin>>n>>m)
    {
        int inconsistency=0;
        int number=0;
        if(n==0&&m==0)
        {
            return 0;
        }
        for(int i=0;i<m;i++)
        {

            char f;
            char a;
            char l;
            cin>>f>>a>>l;
            edge[(int)f -65][(int)l -65]=1;
            if(Inconsistency())
            {
                if(inconsistency==0) 
					inconsistency=i+1;
            }
            else if(solve())
            {
                if(number==0) number=i+1;
            }
        }
        if(inconsistency!=0)
        {
            cout<<"Inconsistency found after "<<inconsistency<<" relations."<<endl;
        }
        else if(number>0)
        {
            cout<<"Sorted sequence determined after "<<number<<" relations: ";
            p();
            cout<<"."<<endl;//¿ÓµùµÄ . 
        }
        else  cout<<"Sorted sequence cannot be determined."<<endl;
        for(int i=0;i<n;i++)
        {
            used[i]=0;
            for(int w=0;w<n;w++)
            {
                edge[i][w]=0;
            }
        }
    }
}
bool checked(int v)
{
    for(int i=0;i<n;i++)
    {
        visited[i]=0;
    }
    stack<int> Q;
    visited[v]=false;
    Q.push(v);
    while(!Q.empty())
    {
        int i,j;
        i=Q.top();
        for(j=0;j<n;j++)
        {
            if(edge[i][j]!=0&&visited[j]==false)
            {
                visited[j]=true;
                Q.push(j);
                break;
            }
        }
        if(j==n)
            Q.pop();
    }
    if(visited[v]==1) 
		return true;
    else 
		return false;
}

bool Inconsistency()
{
    for(int i=0;i<n;i++)
    {
        if(checked(i)) 
			return true;
    }
    return false;
}

void p()
{

    while(!s.empty())
    {
        result.push(s.top());
        s.pop();
    }
    while(!result.empty())
    {
        int a=result.top();
        a=a+65;
        cout<<(char)a;
        result.pop();
    }
}

void DFS(int v)
{
        int j;
        if(used[v] == 1)
        {
            return;
        }
        s.push(v);
        used[v] =1;
        for(j=0;j<n;j++)
        {
            if(edge[v][j]==1)
            {

                DFS(j);
            }
        }
        for(int i=0;i<n;i++)
        {
            if(used[i]==0)
            {
                used[v]=0;
                s.pop();
                break;
            }
        }
}
bool solve()
{
    for(int v=0;v<n;v++)
    {
        DFS(v);
        int all=1;
        for(int i=0;i<n;i++)
        {
            if(used[i]==0) all=0;
        }
        if(all==1) return true;
    }
    return false;
}

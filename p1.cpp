#include<iostream>
using namespace std;
void calWt(int wt[],vector<int>v,int at[],int bt[])
{
	int x=0,c=0;
	int allo[v.size()]={0};
	for(auto it=v.begin();it!=v.end();it++)
	{
		if(it!=v.end()-1)
		{
			if(*it!=*(it+1))
			{
				if(c==0)
				{
					wt[*it]=at[*it];
					allo[c]=w[*it]+bt[*it]+2;
					c++;
				}
				else
				{
					wt[*it]=allo[c-1]-at[*it];
					allo[c]=allo[c-1]+bt[*it];
				}
			}
			
		}
	}
}
int main()
{
	int n;
	cout<<"Enter the no. of the processess-:";
	cin<<n;
	int p[n+1];
	for(int i=1;i<=n;i++)
	p[i]=i;
	int at[n+1];
	int bt[n+1];
	int wt[n+1]={0};
	cout<<"Enter the arrival time and burst time of the processess-:\n";
	for(int i=1;i<=n;i++)
	{
		cin>>at[i]>>bt[i];
	}
	for(int i=1;i<n+1;i++)
	{
		for(j=1;j<n-i;j++)
		{
			if(at[j]>=at[j+1])
			{
				int c=at[j];
				at[j]=at[j+1];
				at[j+1]=c;
				c=bt[j];
				bt[j]=bt[j+1];
				bt[j+1]=c;
				c=p[j];
				p[j]=p[j+1];
				p[j+1]=c;
			}
		}
	}
	
	vector<int>v;
	for(i=1;i<=n;i++)
	{
		if(at[i]!=0)
		v.push_back(i);
	}
	calWt(wt,v,at,bt);
}

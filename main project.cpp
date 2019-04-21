#include<bits/stdc++.h>
#include<windows.h>
#define max 10000000
using namespace std;
int main()
{
	int n,a,b,c,temp,temp2,total,count=0,avgW=0,avgT=0;
	cout<<"***************************************************************"<<endl;
	cout<<"\t\tWELCOME IN OPERATING SYSTEM PROJECT"<<endl;
	cout<<"\t\t\tMADE BY SAURAV DAS"<<endl;
	cout<<"***************************************************************"<<endl;
	cout<<"PLEASE ENTER THE NUMBER OF THE PROCESS-: "<<endl<<endl;
	cin>>n;
	int p[n],at[n],bt[n];
	int wt[n+1]={0};
	int tt[n+1]={0};
	int r[n]={0};
	cout<<"\t\tPLEASE ENTER THE ARRIVAL TIME-:\n";
	for(a=0;a<n;a++)
	{
		cout<<"\tP"<<a+1<<"\t";
		cin>>at[a];
		p[a]=a+1;
	}
	cout<<"\t\tPLEASE ENTER THE BURST TIME-:\n";
		for(a=0;a<n;a++)
	{
		cout<<"\tP"<<a+1<<"\t";
		cin>>bt[a];
		p[a]=a+1;
	}
	cout<<"***************************************************************"<<endl;
	for(a=0;a<n-1;a++)
	{
		for(b=0;b<n-a-1;b++)
		{
			if(at[b]>at[b+1])
			{
				int x=at[b];
				at[b]=at[b+1];
				at[b+1]=x;
				x=bt[b];
				bt[b]=bt[b+1];
				bt[b+1]=x;
				x=p[b];
				p[b]=p[b+1];
				p[b+1]=x;
			}
		}
	}
	for(a=0;a<n;a++)
	{ 
		Sleep(2500);
		if(at[a]==0)
		{
			cout<<"DISCARD P"<<p[a]<<endl<<endl;
		}
		else
		{
			
			cout<<"\tP"<<p[a]<<"\t-->\t";
			
		}
	}
	cout<<endl;
	cout<<"***************************************************************"<<endl;
	cout<<"PROCESS\tARRIVAL TIME\tBURST TIME"<<endl<<endl;
	
	for(a=0;a<n;a++)
	{
		Sleep(1500);
		cout<<"P"<<p[a]<<"\t"<<at[a]<<"\t\t"<<bt[a]<<endl<<endl;;
	}
	
	
	for(a=0;a<n;a++)
	{
		if(at[a]!=0)
		break;
		wt[p[a]]=-1;
		count++;
	}
	c=count;
	for(total=1;n-count>0;)
	{
		for(a=c;a<n;a++)
		{
			if(at[a]>total)
			{
				total++;
				a=a-1;
				continue;
			}
			temp=max;temp2=a;
			for(b=a;b<n && at[b]<=total;b++)
			{
				if(bt[b]<temp&&r[b]!=1)
				{
					temp=bt[b];
					temp2=b;
				}
			}
			wt[p[temp2]]=total-at[temp2];
			tt[p[temp2]]=wt[p[temp2]]+temp;
			total=total+bt[temp2]+2;
			r[temp2]=1;
			count++;
			break;
		}
	}
	
	cout<<"PROCESS\tWAITING TIME\t TURNAROUND TIME\n\n";
	
	for(a=1;a<=n;a++)
	{
		if(wt[a]==-1)
		cout<<"P"<<a<<"\t"<<"DISCARD"<<"\t\t"<<"DISCARD"<<endl<<endl;
		else
		{
			cout<<"P"<<a<<"\t"<<wt[a]<<"\t\t"<<tt[a]<<endl<<endl;;
			avgW+=wt[a];avgT+=tt[a];
		}
		
	}
	cout<<"***************************************************************"<<endl;
	cout<<"\tTHE AVERAGE WAITING TIME IS-:\t";
	cout<<(avgW*1.0)/(n-c)<<endl<<endl;
	cout<<"***************************************************************"<<endl;
	
	cout<<"\tTHE AVERAGE TURNAROUNG TIME IS-:\t";
	cout<<(avgT*1.0/(n-c))<<endl;
	cout<<"***************************************************************"<<endl;
	return 0;
}

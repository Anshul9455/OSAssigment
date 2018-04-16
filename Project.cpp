#include<iostream>
#include<conio.h>
#include<stdio.h>

using namespace std;

void getValue(int n,int at[],int bt[])
{
	int i;
	for(i=0; i<n; i++)
	{
		cout<<"Enter Arrival Time or AT for "<<(i+1)<<": ";
		cin>>at[i];
		cout<<"Enter Brust Time or BT for "<<(i+1)<<": ";
		cin>>bt[i];
	}
}

void findWaitingtime(int processes[], int n, int bt[], int wt[],int tat[])
{
	for(int i=0; i<n; i++)
	{
		wt[i]= tat[i]-bt[i];
	}
}

void findTurnAroundTime(int processes[], int n, int ct[], int tat[], int at[])
{
	for(int i=0; i<n; i++)
	{
		tat[i]= ct[i]- at[i];
	}
}

void findCompleteTime(int processes[], int n, int at[], int bt[], int ct[], int pri[])
{
	int pos, i,j,K=0,count=0,g;
	for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(at[j]<at[pos])
                pos=j;
		}
		ct[i]=K+bt[pos];
		K=ct[i];
		count=count+1;
		for(g=0;g<n;g++) 
		{
			int newbt=0;
			for(int s=0;s<count;s++)
			{
				newbt = newbt + bt[s];
			}
			pri[g]=( 1+(float)(newbt/bt[g]) );
		}
	}
}

void findavgTime(int processes[], int n, int bt[], int at[])
{
	int wt[n], tat[n], ct[n], p[n], pri[n];
	findCompleteTime(processes, n, at, bt, ct, pri);
	findTurnAroundTime(processes, n, ct, tat, at);
	findWaitingtime(processes, n, bt, wt, tat);
	cout<<"Processes	"<<"Brust Time	"<<"Arrival Time	"<<"Waiting Time	"<<"Turn Around Time"<<"    Completion Time	"<<"    Priority\n";
	int total_wt=0,total_tat=0;
	for(int i=0; i<n; i++)
	{
		total_wt=total_wt+wt[i];
		total_tat=total_tat+tat[i];
		int compl_time=tat[i]+at[i];
		cout<<""<<i+1<<"\t\t"<<bt[i]<<"\t\t"<<at[i]<<"\t\t"<<wt[i]<<"\t\t"<<tat[i]<<"\t\t\t"<<ct[i]<<"\t\t\t"<<pri[i]<<endl;
	}
	cout<<"Average waiting Time="<<(float)total_wt/(float)n;
	cout<<"Average Turn Around Time="<<(float)total_tat/(float)n;
}

int main()
{
	int n;
	int i;
	int bt[i];
	int at[i];
	int processes[n];
	cout<<"Enter the quantity of Processes: ";
	cin>>n;
	cout<<"Enter the elements of Processes.\n";
	getValue(n,at,bt);
	system("cls");
	findavgTime(processes, n, bt, at);
	return 0;
}

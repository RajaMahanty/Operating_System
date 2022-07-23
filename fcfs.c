#include <stdio.h>
#include <stdlib.h>
int i,n;

void print_gantt_chart(int p[n],int ct[n])
{
	printf("\n\tGantt's Chart\n\n\t|");
	for(i=0;i<n;i++)
	{
		printf(" P%d |",p[i]);
	}
	printf("\n\t0");
	for(i=0;i<n;i++)
	{
		printf("    %d",ct[i]);
	}
	printf("\n\n");
}

void print_table(int p[n],int at[n],int bt[n],int ct[n],int tat[n],int wt[n])
{
	printf("\nProcesses: \t\t ");
	for(i=0;i<n;i++)
	{
		printf("  P%d",p[i]);
	}
	printf("\n\n");
	printf("Arrival Time: \t\t ");
	for(i=0;i<n;i++)
	{
		printf("   %d",at[i]);
	}
	printf("\n\n");
	printf("Burst Time: \t\t ");
	for(i=0;i<n;i++)
	{
		printf("   %d",bt[i]);
	}
	printf("\n\n");
	printf("Completion Time:      \t");
	for(i=0;i<n;i++)
	{
		printf("   %d",ct[i]);
	}
	printf("\n\n");
	printf("Turn Around Time:\t ");
	for(i=0;i<n;i++)
	{
		printf("   %d",tat[i]);
	}
	printf("\n\n");
	printf("Waiting Time: \t\t ");
	for(i=0;i<n;i++)
	{
		printf("   %d",bt[i]);
	}
	printf("\n\nEnter any key to exit...");
	getch();
}
void rearranging_table_again(int p[n],int at[n],int bt[n],int ct[n],int tat[n],int wt[n])
{
	int i,j,temp,count;
	for(i=0;i<(n-1);i++)
	{
		count=0;
		for(j = 0;j<(n-1-i);j++)
		{
			if(p[j] > p[j+1])
			{
				count=1;
				temp = at[j];
				at[j] = at[j+1];
				at[j+1] = temp;
				temp = bt[j];
				bt[j] = bt[j+1];
				bt[j+1] = temp;
				temp = p[j];
				p[j] = p[j+1];
				p[j+1] = temp;
				temp = ct[j];
				ct[j] = p[j+1];
				ct[j+1] = temp;
				temp = tat[j];
				tat[j] = tat[j+1];
				tat[j+1] = temp;
				temp = wt[j];
				wt[j] = wt[j+1];
				wt[j+1] = temp;
			}
		}
		if(count == 0)
		break;
	}
}
void calculating_wt(int tat[n],int bt[n],int wt[n])
{
	for(i=0;i<n;i++)
	{
		wt[i]=tat[i]-bt[i];
	}
}
void calculating_tat(int at[n],int ct[n],int tat[n])
{
	for(i=0;i<n;i++)
	{
		tat[i]=ct[i]-at[i];
	}
}
void calculating_ct(int p[n],int at[n],int bt[n],int ct[n])
{
	ct[0]=bt[0];
	for(i=1;i<n;i++)
	{
		ct[i]=ct[i-1]+bt[i];
	}
}
void rearranging_table(int p[n],int at[n],int bt[n])
{
	int i,j,temp,count;
	for(i=0;i<(n-1);i++)
	{
		count=0;
		for(j = 0;j<(n-1-i);j++)
		{
			if(at[j] > at[j+1])
			{
				count=1;
				temp = at[j];
				at[j] = at[j+1];
				at[j+1] = temp;
				temp = bt[j];
				bt[j] = bt[j+1];
				bt[j+1] = temp;
				temp = p[j];
				p[j] = p[j+1];
				p[j+1] = temp;
			}
		}
		if(count == 0)
		break;
	}
}
void print_question_table(int p[n],int at[n],int bt[n])
{
	printf("\nProcesses: ");
	for(i=0;i<n;i++)
	{
		printf("\tP%d",p[i]);
	}
	printf("\n\n");
	printf("Arrival Time: ");
	for(i=0;i<n;i++)
	{
		printf("\t%d",at[i]);
	}
	printf("\n\n");
	printf("Burst Time: ");
	for(i=0;i<n;i++)
	{
		printf("\t%d",bt[i]);
	}
	printf("\n\nEnter any key to continue...");
	getch();
	printf("\n\n\n");
}

int main()
{
	printf("Enter the number of processes: ");
	scanf("%d",&n);
	int p[n],at[n],bt[n],ct[n],tat[n],wt[n];
	float avgtat,avgwt;
	printf("Enter %d processes: ",n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&p[i]);
	}
	for(i=0;i<n;i++)
	{
		printf("Enter arrival time of Process %d: ",p[i],n);
		scanf("%d",&at[i]);
	}
	for(i=0;i<n;i++)
	{
		printf("Enter burst time of Process %d: ",p[i],n);
		scanf("%d",&bt[i]);
	}
	system("cls");
	printf("You have entered the below inputs: ");
	print_question_table(p,at,bt);
	rearranging_table(p,at,bt);
	calculating_ct(p,at,bt,ct);
	calculating_tat(at,ct,tat);
	calculating_wt(tat,bt,wt);
	rearranging_table_again(p,at,bt,ct,tat,wt);
	print_gantt_chart(p,ct);
	print_table(p,at,bt,ct,tat,wt);
	return 0;
}

#include<stdio.h>
//#include<iostream>
using namespace std;
//Creating structure of process which have it's attributes.
struct process
{
    int pro_name; // process name eg-1,2 int type
    int arrT; // arriving time
	int  wtT; // wating time
	int turnT; // turnaroundnd time
	int pri; // priority
	int  busTc; // burst time
	int busT; // 
}q1[10],q2[10]; // declaring two queue 1st for fixed priority priamtive scheduling 2nd round robin
int main()
{
	struct process temp; //temporary  queue for storing the info of proccess
    int i,time=0,t1,t2,bu_t=0;
	int largest,totalProcess,count=0,k,pf2=0,totalProcess2,n,pos,j,flag=0,y;
    float wait_time=0,turnaround_time= 0,average_waiting_time,average_turnaround_time;
    printf("\n Enter Total Number of Processes:\t");
    scanf("%d", &totalProcess);
    n=totalProcess;
    for(i=0;i<totalProcess;i++)
    {	fflush(stdin);
    	printf("\nEnter Process name-");
    	
        scanf("%d",&q1[i].pro_name);
        printf("\nEnter Details For processor %d-\n",q1[i].pro_name);
        printf("Enter Arrival Time:-\n");
        scanf("%d",&q1[i].arrT);
        printf("Enter Burst Time-\n");
        scanf("%d",&q1[i].busT);
        q1[i].busTc=q1[i].busT;
        printf("Enter Priority-\n");
        scanf("%d",&q1[i].pri);
    }
    printf("\nEnter Time Quantum for Fixed priority queue-");
    scanf("%d",&t1);
    printf("\nEnter Time Quantum for Round Robin queue-");
    scanf("%d",&t2);
    printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n");
    for(i=0;i<totalProcess;i++)
    {
        pos=i;
        for(j=i+1;j<totalProcess;j++)
        {		//cout<<q1[j].arrT<<"Arpit Sharma";
            if(q1[j].arrT<q1[pos].arrT)
                pos=j;
        }
        temp=q1[i];
        q1[i]=q1[pos];
        q1[pos]=temp;
    }
    time=q1[0].arrT;
    for(i=0;totalProcess!=0;i++)
    {
    	while(count!=t1)
    	{
    		count++;
    		if(q1[i].arrT<=time)
    		{
    			for(j=i+1;j<totalProcess;j++)
    			{
    				if(q1[j].arrT==time && q1[j].pri<q1[i].pri)
    				{
    					q2[pf2]=q1[i]; //putting process in second queue
						pf2++;
    					for(k=i; k<totalProcess-1;k++)
    						q1[k]=q1[k+1];
    					totalProcess--;
						count=0;
    					i=j-1;
    					j--;
					}
				}
			}
			time++;
			q1[i].busT--;
			if(q1[i].busT==0)
			{
				q1[i].turnT=time-q1[i].arrT;
				q1[i].wtT=q1[i].turnT-q1[i].busTc;
				printf("%d\t|\t%d\t|\t%d\n",q1[i].pro_name,q1[i].turnT,q1[i].wtT);
				wait_time+=time-q1[i].wtT; 
    			turnaround_time+=time-q1[i].turnT;
    			for(k=i;k<totalProcess-1;k++)
    				q1[k]=q1[k+1];i--;
    			totalProcess--;
				count=t1;break;
			}
		}
		count=0;
		if(q1[i].busT!=0)
		{
			q2[pf2]=q1[i];
			pf2++;
			for(k=i;k<totalProcess-1;k++)
    			q1[k]=q1[k+1];
    		totalProcess--;
		}
			if(i==totalProcess-1)
				i=-1;
	}
	
	totalProcess2=pf2;
	for(count=0;totalProcess2!=0;) 
	{ 
		if(q2[count].busT<=t2&&q2[count].busT>0) 
    	{ 
    		time+=q2[count].busT; 
    		q2[count].busT=0; 
    		flag=1; 
    	} 
    	else if(q2[count].busT>0) 
    	{ 
    		q2[count].busT-=t2; 
    		time+=t2; 
    	} 
    	if(q2[count].busT==0&&flag==1) 
    	{ 
    		totalProcess2--; 
    		q2[count].turnT=time-q2[count].arrT;
			q2[count].wtT=q2[count].turnT-q2[count].busTc; 
			printf("%d\t|\t%d\t|\t%d\n",q2[count].pro_name,q2[count].turnT,q2[count].wtT); 
    		turnaround_time+=time-q2[count].arrT; 
    		wait_time+=time-q2[count].arrT-q2[count].busTc;
    		for(k=count; k<totalProcess2;k++)
    			q2[k]=q2[k+1];count--;
    		flag=0; 
    	} 

    	if(count==totalProcess2-1) 
      		count=0; 
    	else 
    		count++; 
    }
    printf("\n Average Waiting Time= %f\n", wait_time/n); 
    printf("Avg Turnaround Time = %f" ,turnaround_time/n);
	return 39;   
}

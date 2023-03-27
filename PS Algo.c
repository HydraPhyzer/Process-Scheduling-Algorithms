#include<stdio.h>
#include<stdlib.h>
struct Data
{
	int PID;
	int Burst;
	int Priority;
	int WT;
	int TAT;	
};
void Gantt_Chart(struct Data P[], int n)
{
    int i, j;
    //Print Upper
    printf("-");
    for(i=0; i<n; i++)
	{
        for(j=0; j<P[i].Burst; j++)
        {
			printf("--");
		}
        printf("-");
    }
    printf("\n|");
    //Printing PID
    for(i=0; i<n; i++)
	{
        for(j=0; j<P[i].Burst - 1; j++)
		{
			printf(" ");
		}
			
        printf("P%d", P[i].PID);
        for(j=0; j<P[i].Burst - 1; j++)
        {
			printf(" ");
		}
        printf("|");
    }
    printf("\n");
    //Print Bottom
    for(i=0; i<n; i++)
	{
        for(j=0; j<P[i].Burst; j++)
		{
			printf("--");
		}
        printf("-");
    }
    printf("-");
    printf("\n");
    //Print TAT
    printf("0");
    for(i=0; i<n; i++)
	{
        for(j=0; j<P[i].Burst; j++)
		{
			printf("  ");
		}
		//Removing Backspace
        if(P[i].TAT > 9)
		printf("\b");
        printf("%d", P[i].TAT);
    }
    printf("\n");
}
void FindWT(struct Data PS[] , int N)
{
	PS[0].WT=0;
	for(int i=0 ; i<N ; i++)
	{
		PS[i+1].WT=PS[i].WT+PS[i].Burst;
	}
	for(int i=0 ; i<N ; i++)
	{
		PS[i].TAT=PS[i].WT+PS[i].Burst;
	}
	
	float ATAT=0 , AWT=0;
	for(int i=0 ; i<N ; i++)
	{
		ATAT+=PS[i].TAT;
		AWT+=PS[i].WT;
	}
	ATAT/=N;
	AWT/=N;
	
	printf("\n");
	printf("PROCESS \tBURST TIME \tWAITING TIME \tPRIORITY \n");
	for(int i=0 ; i<N ; i++)
	{
		printf("%d\t        %d\t        %d\t        %d\t           " , PS[i].PID  , PS[i].Burst , PS[i].WT , PS[i].Priority);
		printf("\n");
	}
	printf("\n");
	
	printf("AVERAGE WT IS %f  : " , AWT);
	printf("AVERAGE TAT IS %f : " , ATAT);
}
int main()
{
	printf("ENTER THE TOTAL PROCESS : ");
	int N;
	scanf("%d" , &N);
	struct Data *PS=malloc(sizeof(struct Data) *N);
	
	for(int i=0 ; i<N ; i++)
	{
		PS[i].PID=i;
	}
	
	printf("\n");
	
	for(int i=0 ; i<N ; i++)
	{
		printf("BURST TIME FOR P[%d] : " , i);
		scanf("%d" , &PS[i].Burst);
		
		printf("PRIORITY   FOR P[%d] : " , i);
		scanf("%d" , &PS[i].Priority);
		
		printf("\n");
	}
	
	for (int j=0; j < N-1; j++)
	{
    	for(int i = 0; i < N-j-1; ++i) 
		{
      		if(PS[i].Priority>PS[i+1].Priority)
			{
		        int Temp=PS[i].Priority;
		        PS[i].Priority=PS[i + 1].Priority;
		        PS[i+1].Priority=Temp;
		        
		        int Tid=PS[i].Burst;
		        PS[i].Burst=PS[i+1].Burst;
		        PS[i+1].Burst=Tid;
		        
		        int Ti=PS[i].PID;
		        PS[i].PID=PS[i+1].PID;
		        PS[i+1].PID=Ti;
      		}
    	}
  	}
  	
  	FindWT(PS , N);
  	
  	printf("\n");
  	printf("\n");
  	
  	Gantt_Chart(PS , N);
}

#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include <sys/time.h>
struct Info
{
	int PID;
	int Burst;
	int TAT;
	int WT;	
};
void Gantt_Chart(struct Info P[], int n)
{
    int i, j;
    //Print Upper
    printf("+");
    for(i=0; i<n; i++)
	{
        for(j=0; j<P[i].Burst; j++)
        {
			printf("++");
		}
        printf("+");
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
			printf("++");
		}
        printf("+");
    }
    printf("+");
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
int main()
{
	float AWT=0;
	float ATAT=0;
	printf("ENTER THE TOTAL PROCESS : ");
	int N;
	scanf("%d" , &N);
	
	struct Info *PR=malloc(sizeof(struct Info) *N);
	
	printf("\n");
	//Get Burst Time
	for(int i=0 ; i<N ; i++)
	{
		printf("BURST TIME FOR %d : " , i+1);
		scanf("%d" , &PR[i].Burst);
	}
	//Assign PID
	for(int j=0 ; j<N ; j++)
	{
		PR[j].PID=j;
	}
	
	PR[0].WT=0;
	//Calc WT
	for(int i=0 ; i<N ; i++)
	{
		PR[i+1].WT=PR[i].WT+PR[i].Burst;
	}
	//Calc TAT
	for(int i=0 ; i<N ; i++)
	{
		PR[i].TAT=PR[i].WT+PR[i].Burst;
	}
	int x=0;
	//Finding Averages
	for(int i=0 ; i<N ; i++)
	{
		AWT+=PR[i].WT;
		ATAT+=PR[i].TAT;
	}
	AWT/=N;
	ATAT/=N;
	
	printf("\n");
	printf("PROCESS \tBURST TIME \tWAITING TIME \n");
	for(int i=0 ; i<N ; i++)
	{
		printf("%d\t        %d\t        %d\t           " , PR[i].PID  , PR[i].Burst , PR[i].WT);
		printf("\n");
	}
	printf("\n");
	printf("AVERAGE TAT    TIME : %f " , ATAT);
	printf("\n");
	printf("AVERAGE WATING TIME : %f " , AWT);
	printf("\n");
	printf("\n");
	
	Gantt_Chart(PR , N);
}
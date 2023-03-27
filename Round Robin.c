#include<stdio.h>
#include<stdbool.h>
void FindWT(int Pr , int Burst[] , int Qn , int WT[])
{
	int Time=0;
	int Rem[Pr];
	
	for(int i=0 ; i<Pr ; i++)
	{
		Rem[i]=Burst[i];
	}
	while(1)
	{
		bool Dn=true;
		for(int i=0 ; i<Pr ; i++)
		{
			if(Rem[i]>0)
			{
				Dn=false;
				printf("%d" , Time);
				if(Rem[i]>Qn)
				{
					Time+=Qn;
					Rem[i]-=Qn;
				}
				else
				{
					Time+=Rem[i];
					WT[i]=Time-Burst[i];
					Rem[i]=0;
				}
				printf("->P[%d]  " , i+1);
			}
		}
		if(Dn==true)
		{
			break;
		}
	}
}
void FindTAT(int WT[] , int BT[] , int TAT[] , int Pr)
{
	for(int i=0 ; i<Pr ; i++)
	{
		TAT[i]=WT[i]+BT[i];
	}
}
void Checker(int Pr , int Burst[] , int Qn)
{
	int TtlWT , TtlTAT;
	int WT[Pr] , TAT[Pr];
	
	FindWT(Pr , Burst, Qn , WT);
	FindTAT(WT , Burst , TAT , Pr);
	
	float AB=0;
	float CD=0;
	for(int i=0 ; i<Pr ; i++)
	{
		AB+=WT[i];
		CD+=TAT[i];
	}
	AB/=Pr;
	CD/=Pr;
	printf("\n");
	printf("\n");
	printf("THE AVERAGE WAITING TIME IS     : %f\n" , AB);
	printf("THE AVERAGE TURN AROUND TIME IS : %f\n" , CD);
}
int main()
{
	int Proc;
	printf("ENTER TOTAL PROCESS : ");
	scanf("%d" , &Proc);
	
	printf("\n");
	
	int Process[Proc];

	int Burst[Proc];
	
	for(int i=0 ; i<Proc ; i++)
	{
		printf("BURST TIME FOR P[%d] : " , i+1);
		scanf("%d" , &Burst[i]);
	}
	
	printf("\n");
	printf("ENTER QUANTAM TIME  : ");
	int Quan;
	scanf("%d" , &Quan);
	printf("\n");
	
	Checker(Proc , Burst , Quan);	
}
#include<stdio.h>
void getEnergy(int [],int);
void getToxicity(int [],int);
void swap(int *,int *);
int main()
{
	int testCases;
	scanf("%d",&testCases);
	int x[testCases],y=0;
		
	while(y != testCases)
	{
		int j,geraltEnergy=100,geraltToxicity=0,N,timeReq,energyReq,noOfMonsters=0,i,balEnergy=0;
		scanf("%d",&energyReq);
		scanf("%d",&timeReq);
		scanf("%d",&N);
		if((10<=energyReq&&energyReq<=80)&&(timeReq<=100)&&(1<=N&&N<=8))
		{
			int potions[2][N];
			
			getEnergy(potions[0],N);
			getToxicity(potions[1],N);
			for(i=0;i<N-1;i++)//Bubble sort for arranging in ascending order
			{
				int a;
				for(j=0;j<N-i-1;j++)
				if(potions[0][j]>potions[0][j+1])
				{
					swap(&potions[0][j],&potions[0][j+1]);
					swap(&potions[1][j],&potions[1][j+1]);
				}
			}
			for(i=0;i<N-1;i++)//Bubble sort for arranging toxicity levels if energy is equal
			{
				for(j=0;j<N-i-1;j++)
				if(potions[0][j]==potions[0][j+1])
				{
					if(potions[1][j]<potions[1][j+1])
					{
						swap(&potions[1][j],&potions[1][j+1]);
					}
				}		
			}
		
			while(N>=0)
			{
				while(geraltEnergy>energyReq)
				{
					geraltEnergy=geraltEnergy-energyReq;
					noOfMonsters++;
					geraltToxicity=geraltToxicity-timeReq;
					if(geraltToxicity<0)
					{
						geraltToxicity=0;
					}
					
			}
					
				if((potions[1][N-1]+geraltToxicity)>=100)
				{
					if(balEnergy!=0)
					{
						geraltEnergy=geraltEnergy+balEnergy;
						balEnergy=0;
						if(geraltEnergy>energyReq)
						continue;
					}
				
					N--;
				}
		
				geraltEnergy=geraltEnergy+potions[0][N-1];
				if(geraltEnergy>100)
				{
					balEnergy=geraltEnergy-100;
					geraltEnergy=geraltEnergy-balEnergy;
				}
				geraltToxicity=geraltToxicity+potions[1][N-1];
			
				N--;
				
			}	
			//printf("%d",noOfMonsters);
			x[y]=noOfMonsters;
			y++;
		}
		else
		{
			printf("Enter correct energy and time required to kill one monster and no. of potions\n");
			main();
		}
	}
	for(y=0;y<testCases;y++)
		printf("%d\n",x[y]);
	return 0;
}


void swap(int *x,int *y)
{
	int temp=*x;
	*x=*y;
	*y=temp;
}

void getEnergy(int potions[],int n)
{
	for(int i=0;i<n;i++)
	{
		scanf("%d",potions+i);
	}
}
void getToxicity(int potions[],int n)
{
	for(int i=0;i<n;i++)
	{
		scanf("%d",potions+i);
	}
}
	

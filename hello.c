#include<stdio.h>
  #include <stdlib.h>
  int C[4][3],A[4][3],RQ[4][3],V[3],R[3],K[4],sum=0,np,nr;
void fun();
void  main()
  {
  void fun();
  int i,j,count=0,pcount=0;
  clrscr();

  printf("\nEnter the total number of resources : ");
  scanf("\n%d",&nr);

  for(i=0;i<nr;i++)
   {
   printf("\nEnter the no of resources int R%d : ",i+1);
   scanf("%d",&R[i]);
   }

  printf("\nEnter the no of processes to be executed : ");
  scanf("%d",&np);

  printf("\nEnter the claim matrix:\n");
  for(i=0;i<np;i++)
  for(j=0;j<nr;j++)
  scanf("%d",&C[i][j]);

  printf("\nEnter the allocation matrix:\n");
  for(i=0;i<np;i++)
  for(j=0;j<nr;j++)
  scanf("%d",&A[i][j]);

  for(i=0;i<np;i++)
  for(j=0;j<nr;j++)
  RQ[i][j] = C[i][j] - A[i][j];   /* FINDING THE REQUIRED
  RESOURCES MATRIX(i.e., C-A) */
  fun();
  for(i=0;i<np;i++)
  {
  count=0;
  if(K[i] == i+1)
  continue;    /*  FOR SKIPPING THE PROCESSES(i.e., ROWS) WHICH
		  WERE ALREADY EXECUTED */
  for(j=0;j<nr;j++)
  {
  if(V[j] >= RQ[i][j])
  count++;
    }
   if(count == nr)
  {
   K[i] = i+1;
   for(j=0;j<nr;j++)
          C[i][j] = A[i][j] = RQ[i][j] = 0;
        pcount++;
        count = 0;
        i=-1;
        fun();
       }
     }

   if(pcount == np)
    printf("\nThere is no chance of deadlock.\nIt is a safe state.");
   else
 printf("\nThere is a chance of deadlock.\nIt isn't a safe state.");
   getch();}
   void fun()
   {
   int i1,j1;
   for(i1=0;i1<nr;i1++)
   {
    for(j1=0;j1<np;j1++)
   {
    sum = sum + A[j1][i1];
    }
    V[i1] = R[i1] - sum;
    sum = 0;
    }
    }






























































































































































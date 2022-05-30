#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#define n 4

int main()
{
   int mat[n][n],k,s,count = 0,choise = 0;
   bool game;
   srand(time(NULL));
   for (int i = 0; i < n; i++)
    for (int ii = 0; ii < n; ii++)
	{
 	    mat[i][ii] = 0;
        }
    for (int i = 0; i < n; i++)
       {
	printf("\n\n");
    for (int ii = 0; ii < n; ii++)
	{
 	    printf("%d\t",mat[i][ii]);
        }
   	}
    game = true;
 while (game) 
  {
   count = 0;
   printf("\n\n-------------------------");
 	while (count != 1)
	{
		k = rand()%n;
		s = rand()%n;
		if ( mat[k][s] == 0)
		{
		mat[k][s] = 2;
		count++;
		}
	} 
    for (int i = 0; i < n; i++)
       {
	printf("\n\n");
    for (int ii = 0; ii < n; ii++)
	{
 	    printf("%d\t",mat[i][ii]);
        }
   	}
		printf("\nchoise: ");
		scanf("%d",&choise);
		if (choise == 0)
		break;
		switch(choise)
		{
			case 1:
				{
				  for (int i = 0; i < n; i++)
					{
				        int pop = 1;
					    while ( pop == 1 )
					     {
							 int pos = 0;
						for (int ii = 0; ii<n-1; ii++)
						 {
						   if (mat[n-i-1][ii] == 0 && mat[n-i-1][ii+1] != 0)
							{
							   mat[n-i-1][ii] += mat[n-i-1][ii+1];
							   mat[n-i-1][ii+1] = 0;
							   pos = 1;
							}
						 }
						if (pos == 1)
						  {
						    pop = 1;
						  }
						else
						  pop = 0;
					     }
					  for (int o = 0; o < n -1; o++)
						for (int ii = o; ii<n-1; ii++)
							{
								if (mat[n-i-1][ii] == mat[n-i-1][ii+1] || mat[n-i-1][ii] == 0)
							     {
							       mat[n-i-1][ii] += mat[n-i-1][ii+1];
							       mat[n-i-1][ii+1] = 0;
						         }
								 else
								 	{
									  o++;
									 }
							}	
					}
				}
			break;
		    case 5:
				{
					for (int i = 0; i < n; i++)
					{
				        int pop = 1;
					    while ( pop == 1 )
					     {
							 int pos = 0;
						for (int ii = 0; ii<n-1; ii++)
						 {
						   if (mat[ii][i] == 0 && mat[ii+1][i] != 0)
							{
							   mat[ii][i] += mat[ii+1][i];
							   mat[ii+1][i] = 0;
							   pos = 1;
							}
						 }
						if (pos == 1)
						  {
						    pop = 1;
						  }
						else
						  pop = 0;
					     }
					  for (int o = 0; o < n -1; o++)
						for (int ii = o; ii<n-1; ii++)
							{
								if (mat[ii][i] == mat[ii+1][i] || mat[ii][i] == 0)
							     {
							       mat[ii][i] += mat[ii+1][i];
							       mat[ii+1][i] = 0;
						         }
								 else
								 	{
									  o++;
									 }
							}	
					}
				}
		   break;
		   case 3:
				{
				  for (int i = 0; i < n; i++)
					{
				        int pop = 1;
					    while ( pop == 1 )
					     {
							 int pos = 0;
						for (int ii = 0; ii<n-1; ii++)
						 {
						   if (mat[i][n-1-ii] == 0 && mat[i][n-2-ii] != 0)
							{
							   mat[i][n-1-ii] += mat[i][n-2-ii];
							   mat[i][n-2-ii] = 0;
							   pos = 1;
							}
						 }
						if (pos == 1)
						  {
						    pop = 1;
						  }
						else
						  pop = 0;
					     }
					  for (int o = 0; o < n -1; o++)
						for (int ii = o; ii<n-1; ii++)
							{
								if (mat[i][n-1-ii] == mat[i][n-2-ii] || mat[i][n-1-ii] == 0)
							     {
							       mat[i][n-1-ii] += mat[i][n-2-ii];
							       mat[i][n-2-ii] = 0;
						         }
								 else
								 	{
									  o++;
									 }
							}	
					}
				}
			break;
			case 2:
				{
					for (int i = 0; i < n; i++)
					{
				        int pop = 1;
					    while ( pop == 1 )
					     {
							 int pos = 0;
						for (int ii = 0; ii<n-1; ii++)
						 {
						   if (mat[n-1-ii][i] == 0 && mat[n-2-ii][i] != 0)
							{
							   mat[n-1-ii][i] += mat[n-2-ii][i];
							   mat[n-2-ii][i] = 0;
							   pos = 1;
							}
						 }
						if (pos == 1)
						  {
						    pop = 1;
						  }
						else
						  pop = 0;
					     }
					  for (int o = 0; o < n -1; o++)
						for (int ii = o; ii<n-1; ii++)
							{
								if (mat[n-1-ii][i] == mat[n-2-ii][i] || mat[n-1-ii][i] == 0)
							     {
							       mat[n-1-ii][i] += mat[n-2-ii][i];
							       mat[n-2-ii][i] = 0;
						         }
								 else
								 	{
									  o++;
									 }
							}	
					}
				}
		   break;
		}
	}
}

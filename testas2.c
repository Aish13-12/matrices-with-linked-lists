#include <stdio.h>
#include <stdlib.h>
#include "ass2matrix.h"

void main()
{
	int j;
	while(1)
	{
		printf("\nMENU\n");
		printf("1. Create matrix\n");
		printf("2. Display matrix\n");
		printf("3. Determining whether it is a square matrix or not\n");
		printf("4. Determining whether it is a symmetric matrix or not\n");
		printf("5. Multipliying two matrices\n");
		printf("6. Quit\n");
		printf("Enter your choice:\n");
		scanf("%d",&j);
		switch(j)
		{
			case 1: creatematrix1();
			         break;
			  
			case 2: displaymatrix();
			         break;
			case 3: detsq();
			         break;
			case 4: detsym();
			         break;
			case 5: multiply1();
			         break;
			    
			case 6: exit(EXIT_SUCCESS);
			
			default: printf("Invalid input given\n");
		}
	}					
		
		
	
}	 

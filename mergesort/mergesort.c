#include <stdio.h>
#include <math.h>

void mergesort(int E[], int left, int count);

int main(int argc, char* argv[])
{

	printf("Welcome to mergesort.\n");
	int a[10] = {3,2,6,1,7,9,10,8,5,4};

	mergesort(a, 0, 10);
	
	printf("The new sorted array: \n\n");

	printf("{");
	int b = 0;

	while(b < 10)
	{
		if(b+1 == 10)
		{	
			printf("%i", a[b]);
		}else{
			printf("%i,", a[b]);
		}
		b = b+1;
	}
	
	printf("}\n\n");
	printf("That was mergesort. Thx for watching!\n\n");
	return 0;
}

void mergesort(int E[] , int left, int count)
{
	//base case
	if (count == 1) 
	{
	
		printf("We have reached the base case!\n");
	
		return;

	}else{

		int middle = floor((count)/2) + left ;
	
		int counter = left ;
		printf("left part of the array:\n");
		while(counter < middle)
		{
			if( counter + 1 == middle)
			{
				printf("%i", E[counter]);
			}else{
				printf("%i,", E[counter]);
			}
			counter = counter +1;	
		}

		printf("\n\nright part of the array:\n");

		while(counter < left+count)
		{
			if(counter + 1 == left+count){
				printf("%i", E[counter]);
			}else{
				printf("%i,", E[counter]);
			}
			counter = counter + 1;
		}
		printf("\n\n");
		
		mergesort(E, left , floor(count/2));
		mergesort(E, middle,count-floor(count/2));
	
		printf("\nWe need to combine two arrays\n");	
		int combine[count];

		int i = left;
		int j = middle;

		int a = 0;

		while( a < count)
		{
		
				if(E[i] > E[j] && j < (left+count) && i < middle)
				{
					printf("E[i] > E[j] (with i:%i and j:%i and count: %i) => %i > %i\n",i,j,count, E[i], E[j]);
					combine[a] = E[j];
					j=j+1;
				}else if(E[i] <= E[j] && i < middle && j < (left+count)){
					printf("E[i] < E[j] =(with i:%i and j:%i and count: %i) => %i < %i\n",i,j,count, E[i], E[j]);

					combine[a] = E[i];
					i=i+1;
				}else if( i == middle){
					printf("i reached the end point so the rest comes from j.\n");	
					combine[a] = E[j];
					j = j+1;
				}else if( j == (left+count)){
					printf("j reached the end point so the rest comes from i.\n");
					combine[a] = E[i];
					i = i+1;
				}	

			a = a+1;
		}

		

		int b = 0;
		while(b < count )
		{
			printf("%i,", combine[b]);
			b = b+1;
		}
		printf("\n\n");
		int c = left;
		int f	= 0;
		while( c < count+left)
		{
			printf("Lets insert combine[%i] = %i into E[%i].\n", f, combine[f], c);
			E[c] = combine[f];
			c = c+1;
			f = f+1;
		}
		printf("\n\n");	
	} 

	
}


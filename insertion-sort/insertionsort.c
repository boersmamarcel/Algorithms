#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/**
*  Function declaration for futher use in the class
*/
void insertionsort( int *array, int count);

int main(int argc, char* argv[])
{

	if(argc == 1)
	{
		printf("\nWelcome to the insertion-sort algorithm example!\n");
		printf("--------------------------------------------------\n\n");
		printf("It works as follows:\n");
		printf("You can let your array be sorted ascending.\nGive an array to insertion sort like this insertion-sort {4,2,6,7,2,4,9} ( 0 not allowed ) and we will show you how we sort it.\n\n");
	}else if(argc > 1){
		printf("\nHi there! We will show you how insertion sort works... thx for watching.\n\n");
		
		bool valid_arguments = true;
		int numbers[argc - 1];	
		while(argc-- && valid_arguments == true)
		{
			if(argc > 0)
			{
				//all the arguments other than the running command must be a number in order to sort it, atoi returns 0 incase it isn't a numbers
				if(atoi(argv[argc]) == 0)
				{
					printf("Whoops, you didn't use insertion sort correctly try to run the program again with the correct arguments.\n\n");
					valid_arguments = false;
				}else{
					// insert the number on postion argc - 1 (we do not save argement 1 so the we have one argument less to save than argc counts
					numbers[argc - 1] = atoi(argv[argc]);
				}
			}
		}	
		
		if (valid_arguments == false){
			return 1;//end the program with an error
		}
	
		//no errors found we have an array with numbers to do insertion sort on so let's get started with sorting!!!!
		insertionsort(numbers, sizeof(numbers)/sizeof(int));	
		printf("\n\nFinished insertion sort, hope you liked it!:)\n\n");	
	}


	return 0;

}

void insertionsort( int *array, int count )
{
		int i = 1;

		while(i < count)		
		{
			int key = array[i]; //get the value to compare to
			int j = i - 1; //the element before the key
		
			printf("Order key : %i at position %i => \n", key, i);	
			//check for every value before the key if it is smaller or bigger than the key, if it is smaller move the value one position to the right. If not insert the key there.
			while( j >= 0 && array[j] > key)
			{
				printf("Yeah, indeed array[j] : %i > key : %i so move array[j] to array[j+1]\n", array[j], key);
				array[j+1] = array[j]; //the value at array[j] is bigger than the key so move it one position to the right
				j--;
			}	
				
			array[j+1] = key; //insert the key the right position			
			int a = 0;
			printf("The array at this stage is : [");
			while(a < count)
			{
				if( a + 1 == count)
					printf("%i", array[a]);
				else
					printf("%i,", array[a]);
			
				a++;	
			}	
			printf("]\n\n");


			i++;	
		}
}

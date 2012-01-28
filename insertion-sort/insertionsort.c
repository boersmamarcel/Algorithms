#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{

	if(argc == 1)
	{
		printf("\nWelcome to the insertion-sort algorithm example!\n");
		printf("--------------------------------------------------\n\n");
		printf("It works as follows:\n");
		printf("You can let your array be sorted ascending.\nGive an array to insertion sort like this insertion-sort {4,2,6,7,2,4,9} ( 0 not allowed ) and we will show you how we sort it.\n\n");
	}else if(argc > 1){
		printf("\n Hi there! We will show you how insertion sort works... thx for watching.\n\n");
		
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
		//TODO: sort function call

	}


	return 0;

}

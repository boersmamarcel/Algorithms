/******************************************************************************************************
*
*					Find the maximum subarray by Marcel Boersma 2/12/2012													
*
*					This algorithm will find the maximum subarray for a given array
*
******************************************************************************************************/

#include <stdlib.h>
#include <stdio.h>

typedef struct maximum_subarray{
	int left;
	int right;
	int sum;
} max_subarray;

typedef struct stock{
	/* Days are as follows monday = 0, tuesday = 1, wednesday = 2, thursday = 3, friday = 4, saturday = 5, sunday = 7 */
	int day;
	int price;
} stock_day;


stock_day** create_stock_days(int amount);
max_subarray find_maximum_subarray(int left, int right, int sum);
void display_array(stock_day** days);

int main(int argc, char * argv[])
{

	printf("\n\nWelcome the the maximum subarray algorithm by Marcel Boersma.\n\n");	
	printf("------------------------------------------------------------\n");
	printf("First we will create an array with dummy elements to play with.\n");

	/* Generate a random array with n elements*/
	stock_day** stock_days = create_stock_days(20);	
	
	printf("The random array generation has finished.\n\n");

	/* Print the current array */
	display_array(stock_days);

	

	return 0;
}


max_subarray find_maximum_subarray(int left,int right,int sum)
{



}

void display_array(stock_day** days)
{
	printf("##############################################################\n");

	if(sizeof(days) == 0){
		printf("There are no elements in this array");
	}else{
		/* Calculate the size of the array divided by the size of an element, so we now know how many elements the array holds */
		int size = sizeof(days)/sizeof(stock_day*);
		printf("Size of array:%lu\n", sizeof(days));
		printf("Size of element: %lu\n", sizeof(stock_day*));
		printf("This array has %i elements", size);

	}

}

stock_day** create_stock_days(int amount)
{
	printf("\n\n ########################################################\n");	
	printf("\n\nStart generating an array:\n\n");

	unsigned long array_size = sizeof(stock_day*)*amount;
	printf("Array memory size:%lu\n", array_size);	
	//Create enough memory for all the pointers to a stock day to be saved in the memory	
	stock_day** stock_days = (stock_day**)malloc(array_size);
	if(stock_days == NULL) return NULL;	
	printf("size of stock_days %lu\n\n", sizeof(stock_days));
	int i = 0;

	for(;i<amount;i++)
	{
		//create a stock_day and add them to the array
		stock_days[i] = (stock_day*)malloc(sizeof(stock_day));
		stock_days[i]->day = 0;
		stock_days[i]->price = 100;
		
		printf("Add an stock_day to the array as element number: %i\n", i);
		printf("Value in memory cell of the array %p\n", stock_days[i]);		
		printf("size of memory cell %lu \n\n", sizeof(stock_days[i]));	
	}
	
	printf("size of array: %lu\n", sizeof(stock_days));
	printf("size of element: %lu\n", sizeof(stock_day*));

	printf("\n########################################################\n\n");
	
	return stock_days;
}

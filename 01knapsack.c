#include<stdio.h>
int max(int a,int b)
{
	int c=a>b?a:b;

	return c;
}
int knapsack(int p[],int w[],int n,int mw)
{
	if(n==0||mw==0)
	{
		return 0;
	}
	if(w[n-1]<=mw)
	{
		return max(p[n-1]+knapsack(p,w,n-1,mw-w[n-1]),knapsack(p,w,n-1,mw));
	}
	else
	{
		return knapsack(p,w,n-1,mw);
	}
}
int main()
{
	int w[20];
	int p[20];
	int i,W,n;
	int profit;
	
	printf("Enter the total number of items\n");
	scanf("%d",&n);
	
	printf("Enter the weight of the items\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&w[i]);
	}
	printf("Enter the profits of the items\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&p[i]);
	}
	
	printf("Enter the maximum weight\n");
	scanf("%d",&W);
	profit=knapsack(p,w,n,W);
	printf("The maximum profit is %d",profit);
	return 0;
}


/*

Algorithm for the above code

Start by declaring and initializing necessary variables and arrays.
Read the maximum weight (mw) and the total number of items (n) from the user.
Read the weights of the items (w[i]) using a loop that runs from 0 to n-1.
Read the profits of the items (p[i]) using a similar loop.
Calculate the value density (vd[i]) for each item by dividing its profit by its weight.
Sort the items in descending order based on their value density, using a bubble sort algorithm.
Iterate through the sorted items and add them to the knapsack as long as the total weight (tw) does not exceed the maximum weight (mw).
If adding the current item would exceed mw, continue to the next item.
Otherwise, add the item's weight to tw and its profit to the total benefit (benefit).
Print the calculated benefit.
End the program.
*/

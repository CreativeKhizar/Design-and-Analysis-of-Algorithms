#include <stdio.h>

#define MAX_SIZE 100

// Function to find a subset with the given sum
int findSubset(int set[], int n, int sum, int subset[], int subsetSize)
{
    // Base cases
    if (sum == 0)
    {
        // Print the subset
        printf("{ ");
        for (int i = 0; i < subsetSize; i++)
        {
            printf("%d ", subset[i]);
        }
        printf("}\n");
        return 1;
    }

    if (n == 0 || sum < 0)
    {
        return 0;
    }

    // Include the current element in the subset
    subset[subsetSize] = set[n - 1];
    int include = findSubset(set, n - 1, sum - set[n - 1], subset, subsetSize + 1);

    // Exclude the current element from the subset
    int exclude = findSubset(set, n - 1, sum, subset, subsetSize);

    return include || exclude;
}

// Function to check if a subset exists with the given sum
void checkSubset(int set[], int n, int sum)
{
    int subset[MAX_SIZE];
    int subsetSize = 0;

    int found = findSubset(set, n, sum, subset, subsetSize);

    if (!found)
    {
        printf("No subset found with the given sum.\n");
    }
}

// Main function
int main()
{
    int set[] = {2, 3, 5, 7, 8};
    int n = sizeof(set) / sizeof(set[0]);

    int targetSum = 10;

    printf("Subsets with sum %d:\n", targetSum);
    checkSubset(set, n, targetSum);

    return 0;
}

/* Algorithm

Start with the main function. It declares variables and arrays required for the program.

Define a macro MAX_SIZE to specify the maximum size of the set and subsets.

Implement the findSubset function:

This recursive function takes the set, the size of the set (n), the target sum (sum), the subset array, and the current subset size as input parameters.
The function has base cases to handle the following scenarios:
If the target sum is 0, it means a subset with the target sum is found. Print the subset and return 1 to indicate success.
If n becomes 0 (no more elements in the set) or if the target sum becomes negative, it means a subset with the target sum is not possible. Return 0 to indicate failure.
If the base cases are not met, the function proceeds to two recursive calls:
Include the current element (set[n-1]) in the subset and recursively call findSubset with n-1, sum - set[n-1], the updated subset, and the increased subset size.
Exclude the current element from the subset and recursively call findSubset with n-1, sum, the subset, and the same subset size.
Return the logical OR of the results of the two recursive calls.
Implement the checkSubset function:

This function takes the set, the size of the set (n), and the target sum (sum) as input parameters.
It declares an array subset and a variable subsetSize to keep track of the current subset.
It calls the findSubset function with the provided parameters and stores the result in the found variable.
If no subset is found with the given sum, it prints a corresponding message.
In the main function:

Declare the set of numbers and initialize it.
Calculate the size of the set (n) using the sizeof operator.
Define the target sum (targetSum) as 10.
Print a message indicating the target sum.
Call the checkSubset function with the set, n, and the target sum.
End the program by returning 0 from the main function.

*/

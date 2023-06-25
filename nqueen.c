#include<stdio.h>
#include<math.h>

int board[20],count;

int main()
{
int n,i,j;
void queen(int row,int n);

printf(" - N Queens Problem Using Backtracking -");
printf("\n\nEnter number of Queens:");
scanf("%d",&n);
queen(1,n);
return 0;
}

//function for printing the solution
void print(int n)
{
int i,j;
printf("\n\nSolution %d:\n\n",++count);

for(i=1;i<=n;++i)
  printf("\t%d",i);

for(i=1;i<=n;++i)
{
  printf("\n\n%d",i);
  for(j=1;j<=n;++j) //for nxn board
  {
   if(board[i]==j)
    printf("\tQ"); //queen at i,j position
   else
    printf("\t-"); //empty slot
  }
}
}

/*funtion to check conflicts
If no conflict for desired postion returns 1 otherwise returns 0*/
int place(int row,int column)
{
int i;
for(i=1;i<=row-1;++i)
{
  //checking column and digonal conflicts
  if(board[i]==column)
   return 0;
  else
   if(abs(board[i]-column)==abs(i-row))
    return 0;
}

return 1; //no conflicts
}

//function to check for proper positioning of queen
void queen(int row,int n)
{
int column;
for(column=1;column<=n;++column)
{
  if(place(row,column))
  {
   board[row]=column; //no conflicts so place queen
   if(row==n) //dead end
    print(n); //printing the board configuration
   else //try queen with next position
    queen(row+1,n);
  }
}
}

/* Algorithm

Start with the main function. It declares variables and the board array to represent the positions of the queens on the chessboard.

Define the print function:

This function takes the size of the board (n) as a parameter.
It prints the current configuration of the board, showing the positions of the queens.
The function iterates over the rows and columns of the board and prints the appropriate symbols ("-": empty slot, "Q": queen) based on the positions stored in the board array.
Define the place function:

This function takes the current row (row) and column (column) as parameters.
It checks for conflicts with previously placed queens.
The function iterates over the rows before the current row and checks for conflicts in the same column or along diagonals.
If a conflict is found, the function returns 0 to indicate that the position is not valid.
If no conflict is found, the function returns 1 to indicate that the position is valid.
Define the queen function:

This recursive function takes the current row (row) and the size of the board (n) as parameters.
It tries to place a queen in each column of the current row and then recursively calls itself for the next row.
If a valid position is found for the current row, the position is stored in the board array.
If the current row is the last row (row == n), it means a solution is found, and the print function is called to print the board configuration.
If the current row is not the last row, the queen function is recursively called for the next row.
In the main function:

It prompts the user to enter the number of queens (n).
It calls the queen function with the initial row (1) and the size of the board (n).
The program ends by returning 0 from the main function.

*/

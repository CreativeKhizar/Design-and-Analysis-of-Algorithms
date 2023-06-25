#include <stdio.h>
#include <stdlib.h>
void floydWarshall(int **graph, int n)
{
    int i, j, k;
    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (graph[i][j] > graph[i][k] + graph[k][j])
                    graph[i][j] = graph[i][k] + graph[k][j];
            }
        }
    }
}

int main(void)
{
    int n, i, j;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    int **graph = (int **)malloc((long unsigned) n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        graph[i] = (int *)malloc((long unsigned) n * sizeof(int));
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i == j)
                graph[i][j] = 0;
            else
                graph[i][j] = 100;
        }
    }
    printf("Enter the edges: \n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("[%d][%d]: ", i, j);
            scanf("%d", &graph[i][j]);
        }
    }
    printf("The original graph is:\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
    floydWarshall(graph, n);
    printf("The shortest path matrix is:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
    return 0;
}

/* Algorithm

Start with the main function. It declares variables and allocates memory for a 2D array to represent the graph.

Prompt the user to enter the number of vertices in the graph (n).

Allocate memory for the graph as a 2D array with dimensions nxn.

Initialize the graph matrix with initial values:

Set diagonal elements (graph[i][i]) to 0.
Set non-diagonal elements to a large value (100 in this case) to represent infinity or absence of edges.
Prompt the user to enter the weights of the edges in the graph.

Read the weights entered by the user and store them in the graph matrix.

Print the original graph matrix.

Call the floydWarshall function, passing the graph matrix and the number of vertices n.

Inside the floydWarshall function:
a. Use three nested loops (k, i, j) to perform the Floyd-Warshall algorithm.
b. Check if the shortest path from vertex i to j can be improved by going through vertex k. If so, update the value in the graph matrix.
c. Repeat this process for all vertices.

Return to the main function.

Print the resulting shortest path matrix.

End the program by returning 0 from the main function.


*/

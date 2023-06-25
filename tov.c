#include<stdio.h>
#include<stdlib.h>

int s[100], j, res[100]; /*GLOBAL VARIABLES */

void AdjacencyMatrix(int a[][100], int n) { //To generate adjacency matrix for given nodes

    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j <= n; j++) {
            a[i][j] = 0;
        }
    }
    for (i = 1; i < n; i++) {
        for (j = 0; j < i; j++) {
            a[i][j] = rand() % 2;
            a[j][i] = 0;
        }
    }
}

void dfs(int u, int n, int a[][100]) { /* DFS */

    int v;
    s[u] = 1;
    for (v = 0; v < n - 1; v++) {
        if (a[u][v] == 1 && s[v] == 0) {
            dfs(v, n, a);
        }
    }
    j += 1;
    res[j] = u;
}

void topological_order(int n, int a[][100]) { /* TO FIND TOPOLOGICAL ORDER*/

    int i, u;
    for (i = 0; i < n; i++) {
        s[i] = 0;
    }
    j = 0;
    for (u = 0; u < n; u++) {
        if (s[u] == 0) {
            dfs(u, n, a);
        }
    }
    return;
}

int main() {
    int a[100][100], n, i, j;

    printf("Enter number of vertices\n"); /* READ NUMBER OF VERTICES */
    scanf("%d", &n);

    AdjacencyMatrix(a, n); /*GENERATE ADJACENCY MATRIX */

    printf("\t\tAdjacency Matrix of the graph\n"); /* PRINT ADJACENCY MATRIX */
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("\t%d", a[i][j]);
        }
        printf("\n");
    }
    printf("\nTopological order:\n");

    topological_order(n, a);

    for (i = n; i >= 1; i--) {
        printf("-->%d", res[i]);
    }
    return 0;
}


/* Algorithm

Start with the main function. It declares variables and arrays required for the program.

Prompt the user to enter the number of vertices in the graph (n).

Call the AdjacencyMatrix function, passing the 2D array a and the number of vertices n. This function generates a random adjacency matrix for the graph.

Print the generated adjacency matrix.

Call the topological_order function, passing the number of vertices n and the adjacency matrix a. This function performs a topological sorting of the graph.

Inside the topological_order function:
a. Initialize an array s to keep track of visited vertices.
b. Initialize a variable j to 0.
c. Iterate over each vertex u from 0 to n-1.
- If vertex u has not been visited (s[u] == 0), call the dfs function with u as the starting vertex.
d. Return to the main function.

Inside the dfs function:
a. Mark the vertex u as visited by setting s[u] to 1.
b. Iterate over each adjacent vertex v of u from 0 to n-1.
- If there is an edge between u and v (a[u][v] == 1) and v has not been visited (s[v] == 0), recursively call the dfs function with v as the new starting vertex.
c. Increment j by 1.
d. Set the j-th element of the res array to u, storing the vertices in reverse order of their finishing times.

Return to the topological_order function.

Print the topological order of the vertices by iterating over the res array in reverse order from n to 1.

End the program by returning 0 from the main function

*/

#include <stdio.h>
#define MAX 5

// Function to perform Depth-First Search using a stack
void depth_first_search(int adj[][MAX], int visited[], int start)
{
    int stack[MAX];
    int top = -1, i;

    printf("%c ", start + 65); // Print starting node (A = 65)
    visited[start] = 1;
    stack[++top] = start;

    while (top != -1)
    {
        start = stack[top]; // Peek at the top of the stack

        for (i = 0; i < MAX; i++)
        {
            if (adj[start][i] == 1 && visited[i] == 0)
            {
                stack[++top] = i;    // Push neighbor onto stack
                printf("%c ", i + 65); // Print node
                visited[i] = 1;
                break; // Go deeper (DFS characteristic)
            }
        }

        if (i == MAX)
            top--; // Pop if no unvisited neighbors
    }
}

int main()
{
    int adj[MAX][MAX], visited[MAX] = {0};
    int i, j;
    int start;

    printf("Enter the %dx%d adjacency matrix (0 or 1):\n", MAX, MAX);
    for (i = 0; i < MAX; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            scanf("%d", &adj[i][j]);
        }
    }

    printf("Enter the starting node (0 for A, 1 for B, ..., %d for %c): ", MAX - 1, MAX - 1 + 65);
    scanf("%d", &start);

    printf("\nDFS Traversal starting from node %c:\n", start + 65);
    depth_first_search(adj, visited, start);
    printf("\n");

    return 0;
}


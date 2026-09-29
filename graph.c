#include <stdio.h>
#include <stdlib.h>

#define N 6

char vertices[N] = {'A', 'B', 'C', 'D', 'E', 'F'};

int matrix[N][N] = {0};

struct Node {
    int vertex;
    struct Node *next;
};

struct Node *adjList[N] = {NULL};

int visited[N];

// Convert vertex label to index
int getIndex(char v) {
    for (int i = 0; i < N; i++) {
        if (vertices[i] == v)
            return i;
    }
    return -1;
}

// Add vertex to adjacency list in sorted order
void insertSorted(int u, int v) {
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;

    struct Node **current = &adjList[u];

    while (*current != NULL && (*current)->vertex < v) {
        current = &((*current)->next);
    }

    newNode->next = *current;
    *current = newNode;
}

// Add an undirected edge
void addEdge(int u, int v) {
    matrix[u][v] = 1;
    matrix[v][u] = 1;

    insertSorted(u, v);
    insertSorted(v, u);
}

// Display adjacency matrix
void displayMatrix() {
    printf("\nAdjacency Matrix:\n   ");

    for (int i = 0; i < N; i++)
        printf("%c ", vertices[i]);

    printf("\n");

    for (int i = 0; i < N; i++) {
        printf("%c  ", vertices[i]);

        for (int j = 0; j < N; j++)
            printf("%d ", matrix[i][j]);

        printf("\n");
    }
}

// Display adjacency list
void displayList() {
    printf("\nAdjacency List:\n");

    for (int i = 0; i < N; i++) {
        printf("%c -> ", vertices[i]);

        struct Node *temp = adjList[i];

        while (temp != NULL) {
            printf("%c -> ", vertices[temp->vertex]);
            temp = temp->next;
        }

        printf("NULL\n");
    }
}

// BFS using adjacency matrix
void bfsMatrix(int start) {
    int queue[N], front = 0, rear = 0;
    int seen[N] = {0};

    queue[rear++] = start;
    seen[start] = 1;

    printf("BFS (Matrix): ");

    while (front < rear) {
        int u = queue[front++];
        printf("%c ", vertices[u]);

        for (int v = 0; v < N; v++) {
            if (matrix[u][v] && !seen[v]) {
                seen[v] = 1;
                queue[rear++] = v;
            }
        }
    }

    printf("\n");
}

// DFS using adjacency matrix
void dfsMatrix(int u) {
    visited[u] = 1;
    printf("%c ", vertices[u]);

    for (int v = 0; v < N; v++) {
        if (matrix[u][v] && !visited[v])
            dfsMatrix(v);
    }
}

// BFS using adjacency list
void bfsList(int start) {
    int queue[N], front = 0, rear = 0;
    int seen[N] = {0};

    queue[rear++] = start;
    seen[start] = 1;

    printf("BFS (List): ");

    while (front < rear) {
        int u = queue[front++];
        printf("%c ", vertices[u]);

        struct Node *temp = adjList[u];

        while (temp != NULL) {
            int v = temp->vertex;

            if (!seen[v]) {
                seen[v] = 1;
                queue[rear++] = v;
            }

            temp = temp->next;
        }
    }

    printf("\n");
}

// DFS using adjacency list
void dfsList(int u) {
    visited[u] = 1;
    printf("%c ", vertices[u]);

    struct Node *temp = adjList[u];

    while (temp != NULL) {
        int v = temp->vertex;

        if (!visited[v])
            dfsList(v);

        temp = temp->next;
    }
}

// Search for a vertex label
int searchVertex(char key, int *count) {
    *count = 0;

    for (int i = 0; i < N; i++) {
        (*count)++;

        if (vertices[i] == key)
            return i;
    }

    return -1;
}

// Free allocated memory
void freeList() {
    for (int i = 0; i < N; i++) {
        struct Node *temp = adjList[i];

        while (temp != NULL) {
            struct Node *next = temp->next;
            free(temp);
            temp = next;
        }
    }
}

int main() {
    int count, result;

    // Create graph
    addEdge(0, 1); // A-B
    addEdge(0, 2); // A-C
    addEdge(1, 3); // B-D
    addEdge(1, 4); // B-E
    addEdge(2, 5); // C-F
    addEdge(4, 5); // E-F

    displayMatrix();
    displayList();

    printf("\nGraph Traversal:\n");

    bfsMatrix(0);

    for (int i = 0; i < N; i++)
        visited[i] = 0;

    printf("DFS (Matrix): ");
    dfsMatrix(0);
    printf("\n");

    bfsList(0);

    for (int i = 0; i < N; i++)
        visited[i] = 0;

    printf("DFS (List): ");
    dfsList(0);
    printf("\n");

    // Search for vertex E
    result = searchVertex('E', &count);

    printf("\nSearch for vertex E:\n");

    if (result != -1)
        printf("Vertex E found at index %d\n", result);
    else
        printf("Vertex E not found\n");

    printf("Comparisons required: %d\n", count);

    freeList();

    return 0;
}

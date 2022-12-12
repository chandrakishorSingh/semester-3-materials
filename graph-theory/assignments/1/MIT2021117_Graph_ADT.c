#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <sys/stat.h>


//Global Variable
int n;

// helper dfs method
void dfs(int node, int* size, int **adj, int *visited) {
    visited[node] = 1;

    for(int i=1; i<=n; i++) {
        if(adj[node][i]>0 && visited[i]==0) {
            (*size) = ((*size) + 1);
            dfs(i, size, adj, visited);
        }
    }

}

int NoOfConnConf(int **adj) {
    int *visited = (int*) malloc((n+1)*sizeof(int));
    for(int i=0; i<=n; i++) {
        visited[i] = 0;
    }
    int component=0;
    int maxSize=0;
    for(int i=1; i<=n; i++) {
        if(visited[i]==0) {
            component++;
            int size=0;
            dfs(i, &size, adj, visited);
            if(size>maxSize) maxSize = size;
        }
    }
    return component;
}

int isConnected(int **adj) {
    int component = NoOfConnConf(adj);
    if(component>1) return 0;
    return 1;
}

int SizeOfLargestComp(int** adj) {
    int *visited = (int*) malloc((n+1)*sizeof(int));
    for(int i=0; i<=n; i++) {
        visited[i] = 0;
    }
    int maxSize=0;
    for(int i=1; i<=n; i++) {
        if(visited[i]==0) {
            int size=0;
            dfs(i, &size, adj, visited);
            if(size>maxSize) maxSize = size;
        }
    }
    return maxSize;
}

int CreateGraph(int **adj, char *fileName) {
    
    char *file_contents = malloc(sizeof(char)*10);
    FILE *fp = fopen(fileName, "r");
    if(!fp) {
        printf("Error in reading file\n");
        return 0;
    }

    //Skip size, Weight and probability
    fscanf(fp, "%[^\n ] ", file_contents);
    fscanf(fp, "%[^\n ] ", file_contents);
    fscanf(fp, "%[^\n ] ", file_contents);

    while (fscanf(fp, "%[^\n ] ", file_contents) != EOF) {
        int u = atoi(file_contents);
        fscanf(fp, "%[^\n ] ", file_contents);
        int v = atoi(file_contents);
        fscanf(fp, "%[^\n ] ", file_contents);
        int w = atoi(file_contents);
        adj[u][v] = w;
        adj[v][u] = w;
    }

    fclose(fp);
    free(file_contents);
    return 1;

}

void main(int argc, char *argv[]) {
    if(argc!=2) {
        printf("\n\n\n*********************************************************************************\n");
        printf("Run the program as below: \n");
        printf("./<exetable file> <graph input file>\n");
        printf("*********************************************************************************\n\n\n");
        return;
    }

    char *fileName = argv[1];
    FILE *fp = fopen(fileName, "r");
    char *file_contents = malloc(sizeof(char)*10);

    //Get Number of nodes
    fscanf(fp, "%[^\n ] ", file_contents);
    n = atoi(file_contents);
    fclose(fp);
    free(file_contents);

    //Initialize adjacency matrix
    int *adj[n+1];
    for(int i=0; i<=n; i++) {
        adj[i] = (int*) malloc((n+1)*sizeof(int));
    }

    for(int i=0; i<=n; i++) {
        for(int j=0; j<=n; j++) {
            adj[i][j] = 0;
        }
    }

    int success = CreateGraph(adj, fileName);
    if(success == 0) return;
    

    int component = NoOfConnConf(adj);
    printf("Number of connected component = %d\n", component);
    printf("Maximum size of a component = %d\n", SizeOfLargestComp(adj));

    for(int i=0; i<n; i++) free(adj[i]);
}

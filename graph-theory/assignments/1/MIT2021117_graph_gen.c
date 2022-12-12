#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <sys/stat.h>
// #include <cstdlib.h>

int main(int argc, char* argv[]) {
  
  // check if all 4 arguments are provided or not.
  if (argc != 5) {
    printf("Run the program as follows\n");
    printf("./<executable_name> <number_of_nodes> <probability> <maximum_weight> <output_file_name>\n");
    exit(1);
  }

  // extract all the arguments
  int n = atoi(argv[1]);
  float probability = atof(argv[2]);
  int maxWeight = atoi(argv[3]);
  char* outputFileName = argv[4];

  // printf("%f\n", probability);

  // printf("%d\n",n);

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

  // generate adjacency matrix
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i == j)
        continue;
      
      int isEdgePresent = ((float)rand() / (float)RAND_MAX) <= probability ? 1 : 0;

      if (isEdgePresent) {
        int weight = (rand() % maxWeight) + 1;
        adj[i][j] = weight;
        adj[j][i] = weight;
      }
    }
  }

  // print the adjacency matrix
  printf("The adjacency matrix of generated graph is follows\n");
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      printf("%d ", adj[i][j]);
    }
    printf("\n");
  }

  // open file
  FILE* fp = fopen(outputFileName, "w");
  if (!fp) {
    printf("Error while opening the output file!\n");
    exit(1);
  }

  char* fileContents = malloc(sizeof(char) * 10);
  
  fprintf(fp, "%d\n", n);
  fprintf(fp, "%f\n", probability);
  fprintf(fp, "%d\n", maxWeight);

  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (adj[i][j] != 0) {
        fprintf(fp, "%d %d %d\n", i, j, adj[i][j]);
      }
    }
  }

  return 0;                                 
}

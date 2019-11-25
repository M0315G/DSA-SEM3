#include<stdio.h>
#include<stdlib.h>
void D_detectLoop(int **graph,int vertices){
    int degree;
    int *visited= (int *)calloc(vertices,sizeof(int));
    visited[0]++;
    for(int i=0;i<vertices;i++){
        for(int j=0;j<vertices;j++){
            if(graph[i][j]>0){
                if(visited[j]>0){
                    printf("Cycle found. i:- %d j:-%d  %d\n",i,j,graph[i][j]);
                    int k=0;
                    while(k<vertices){
                        printf("%d\t",visited[k]);
                        k++;
                    }
                    
                    return;
                }
                visited[j]++;
            }
        }
    }

    printf("There is no cycle");

    
}

void main(){
    int vertices;
    printf("Enter the no of vertices:-");
    scanf("%d",&vertices);

    int **graph = (int **)calloc(vertices,sizeof(int*));

    printf("\nEnter the adjancency matrix:-\n");
    for(int i=0;i<vertices;i++){
        graph[i]=(int *)calloc(vertices,sizeof(int));
        for(int j=0;j<vertices;j++){
            scanf("%d",&graph[i][j]);
        }
    }

    for(int i=0;i<vertices;i++){
        for(int j=0;j<vertices;j++){
            printf("%d\t",graph[i][j]);
        }printf("\n");
    }

    D_detectLoop(graph,vertices);


}
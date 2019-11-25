#include<stdio.h>
#include<stdlib.h>

int isFull(int *visited_vertices,int vertices){
    for(int i=0;i<vertices;i++){
        if(visited_vertices[i]==0){
            return 0;
        }
    }

    return 1;
}

void buildMST(int **matrix,int vertices){
    for(int i=0;i<vertices;i++){
        for(int j=0;j<vertices;j++){
            if(matrix[i][j]==0)
                matrix[i][j]=INT_MAX;
        }
    }

    int *visited_vertices= (int *)calloc(vertices,sizeof(int));
    int min,src,des;

    while(!isFull(visited_vertices,vertices)){
        min=matrix[0][0];

        for(int i=0;i<vertices;i++){
            for(int j=i;j<vertices;j++){
                if(matrix[i][j]<min){
                    min=matrix[i][j];
                    src=i;
                    des=j;
                }
            }
        }

        if(visited_vertices[src]!=0 && visited_vertices[des]!=0){
            matrix[src][des]=INT_MAX;
            continue;
        }

        printf("\nEdge Taken between %d & %d with weight %d",src+1,des+1,min);

        matrix[src][des]=INT_MAX;
        matrix[des][src]=INT_MAX;

        visited_vertices[src]++;
        visited_vertices[des]++;

    }

}

void main(){
    int vertices;
    printf("Enter the no of vertices:-");
    scanf("%d",&vertices);

    int **matrix= (int **)calloc(vertices,sizeof(int *));

    printf("\nEnter the adjancency matrix:-\n");
    for(int i=0;i<vertices;i++){
        matrix[i]=calloc(vertices,sizeof(int));
        for(int j=0;j<vertices;j++){
            scanf("%d",&matrix[i][j]);
        }
    }

    buildMST(matrix,vertices);
}

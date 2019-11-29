#include<stdio.h>

void buildMSt(int **matrix,int vertices){

    
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
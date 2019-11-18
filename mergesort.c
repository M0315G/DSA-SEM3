#include<stdio.h>
#include<stdlib.h>

void mergersort(){
    
}
void main(){
    int size;
    printf("Enter the size of the array:-");
    scanf("%d",&size);
    int *array= malloc(size*sizeof(int));
    for(int i=0;i<size;i++){
        printf("Enter an element into array:-");
        scanf("%d",&*(array+i));
    }

    mergesort(array,0,size-1);

    printf("The sorted array is:-");
    for(int i=0;i<size-1;i++){
        printf("%d",*(array+i));
    }
    
}
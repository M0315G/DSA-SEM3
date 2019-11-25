#include<stdio.h>
#include<stdlib.h>


//This function swaps the values at the index passed into it.
void swap(int *a,int *b){
  int temp=*a;
  *a=*b;
  *b=temp;  
}

//This function is used to dynamically partition the array such that all the elements on the left side of the middle element are smaller
//than itself and on the right are bigger than itself. 
int partitions(int *array,int low,int high){
    int pivot=*(array+high);
    int i=low-1;
    for(int j=low;j<=high-1;j++){
        if(*(array+j)<pivot){
            i++;
            swap(&array[i],&array[j]);
        }
    }
    swap(&array[i+1],&array[high]);
    return i+1;
}

//This function is the recursive function to sort the given array using quicksort algorithm.
void quicksort(int *array,int low,int high){
    if(low<high){
        int mid= partitions(array,low,high);
        quicksort(array,low,mid-1);
        quicksort(array,mid+1,high);
    }
}


void main(){
    int size;
    printf("\nEnter size of the array:-");
    scanf("%d",&size);
    int *arr= malloc(size*sizeof(int));

    for(int i=0;i<size;i++){
        printf("\nEnter %d elemt of array:-",i+1);
        scanf("%d",&*(arr+i));
    }

    quicksort(arr,0,size-1);

    printf("\nThe sorted array is:-\n");
    for(int i=0;i<size;i++){
        printf("\t\t%d",arr[i]);
    }
}
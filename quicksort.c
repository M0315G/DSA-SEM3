#include<stdio.h>
#include<stdlib.h>

//Function to swap two given elements of an array.
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

//Function to arrange app the elements smaller than pivot in it's left and that greater than it in it's right. It untimately returns the mid point for further division of array. 
int partitions(int *arr,int low,int high){
    int pivot=*(arr+high);
    int i=low-1;
    for(int j=low;j<=high-1;j++){
        if(*(arr+j)<pivot){
            i++;
            swap((arr+i),(arr+j));
        }
    }
    swap((arr+i+1),(arr+high));
    return (i+1);
}

//This funtion is called recursively to sort the given array 
void quicksort(int *arr,int low,int high){
    if(low<high){
        int mid=partitions(arr,low,high);
        quicksort(arr,low,mid-1);
        quicksort(arr,mid+1,high);
    }
}

//Main method
void main(){
    int size;
    printf("Enter the size of the array:-");
    scanf("%d",&size);
    int *array= malloc(size*sizeof(int));
    for(int i=0;i<size;i++){
        printf("Enter the element in the array:-");
        scanf("%d",&*(array+i));
    }
    quicksort(array,0,size-1);
    printf("The sorted array is:-");
    for(int i=0;i<size;i++){
        printf(" %d",*(array+i));
    }
}
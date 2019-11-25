#include<stdio.h>
#include<stdlib.h>

void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void heapify(int *array,int size,int i){
    int largest=i;
    int l=2*i+1;
    int r=2*i+2;

    if(l<size){
        if(array[l]>array[largest])
            largest=l;
    }
    if(r<size){
        if(array[r]>array[largest])
            largest=r;
    }

    if(largest!=i){
        //Swapping the largest number in the postition of root.
        swap(&array[i],&array[largest]);

        //Calling heapify again to heapify the affected node.
        heapify(array,size,largest);
    }
}

void heapsort(int *arr,int n){

    //Building a max heap by heapifying each node.
    for(int i=n/2;i>=0;i--){
        heapify(arr,n+1,i);
    }

    for(int i=n;i>=0;i--){

        //Swap the fisrt root of the heap with the last element of the array.
        swap(&arr[i],&arr[0]);

        //Again build the max heap for array from 0 to n-1;
        heapify(arr,i,0);
    }
}

void main(){

    int size;
    printf("Enter size of the array:-");
    scanf("%d",&size);

    int *array= malloc(size*sizeof(int));
    
    printf("%d",size);

    for(int i=0;i<size;i++){
        printf("\nEnter %d element of array:-",i+1);
        scanf("%d",&array[i]);
    }

    heapsort(array,size-1);

    printf("\nThe sorted array is:-\n");
    for(int i=0;i<size;i++){
        printf("%d\t\t",array[i]);
    }

}
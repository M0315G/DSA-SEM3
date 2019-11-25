#include<stdio.h>
#include<stdlib.h>

void merge(int *array,int left,int mid,int right){
    
    //Calculating the size of Left subarray and right sub array.
    int n1=mid-left+1;
    int n2=right-mid;

    //Declaring left subarray and right subarray.
    int L[n1],R[n2];

    //Copying the values of the array into the subarrays.
    for(int i=0;i<n1;i++){
        L[i]=array[left+i];
    }
    for(int i=0;i<n2;i++){
        R[i]=array[mid+1+i];
    }

    //Applying merge operation 
    int i=0,j=0,k=left;

    while(i<n1&&j<n2){
        //The shortest of both L & R gets copied to the main array so that the resultant array is always in ascending order.
        if(L[i]<=R[j]){
            array[k]=L[i];
            i++;
        }else{
            array[k]=R[j];
            j++;
        }
        k++;
    }

    //Copying all the elements of Left Subarray if it's not empty.
    while(i<n1){
        array[k]=L[i];
        k++; i++;
    }

    //Copying all the elements of Right Subarray if it's not empty.
    while(j<n2){
        array[k]=R[j];
        k++; j++;
    }

}

void mergesort(int *array,int l,int r){
    //Recursion condition.
    if(l<r){

        //Calculting the middle of the array.
        int mid= l+(r-l)/2;
        //Recursively calling mergetsort.
        mergesort(array,l,mid);
        mergesort(array,mid+1,r);

        //Performing merge operation on the two sub arrays.
        merge(array,l,mid,r);
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

    mergesort(array,0,size-1);

    printf("\nThe sorted array is:-\n");
    for(int i=0;i<size;i++){
        printf("%d\t\t",array[i]);
    }

}
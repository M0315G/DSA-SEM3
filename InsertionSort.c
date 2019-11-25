#include<stdio.h>

void insertionSort(int a[],int size){

    int i,j,key;
    for(int i=1;i<size;i++){
        key=a[i];
        j=i-1;

        while(j>=0 && a[j]>=key){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
}

void main(){
    int array[]={3,6,1,8,9,22,5,0};
    int size= sizeof(array)/sizeof(array[0]);

    insertionSort(array,size);

    for(int i=0;i<size;i++){
        printf("%d\t",array[i]);
    }
}
#include<stdio.h>

void heapsort(int a[]){
    
} 

void main(){
    int n;
    printf("Enter the size of the array:-");
    scanf("%d",&n);
    int a[]=malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        printf("Enter an element into the array:-");
        scanf("%d",&a[i]);
    }

    printf("Applying heap sort on the array!");
    heapsort(a);
}
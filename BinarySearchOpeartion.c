

#include<stdio.h>
void main()
{
   int i,j,temp, first, last, middle, n, search, A[100];

   printf("Enter no. of elements\n");
   scanf("%d",&n);
   printf("Enter %d integers\n", n);
   for (i=0;i<n;i++)
      scanf("%d",&A[i]);
   printf("Enter value to find\n");
   scanf("%d", &search);
   first=0;
   last=n-1;
   middle=(first+last)/2;
   for(i=0;i<n;i++)
   {
       for(j=i;j<n-1;j++)
       {
           if(A[j]>A[j+1])
           {
               temp=A[j];
               A[j]=A[j+1];
               A[j+1]=temp;
           }
       }
   }

   while (first<=last)
    {
      if (A[middle]<search)
         first=middle+1;
      else if(A[middle]==search)
      {
         printf("%d found at location %d.\n", search, middle+1);
         break;
      }
      else
         last=middle-1;
      middle=(first+last)/2;
   }
   if (first>last)
      printf("\n%d isn't present in the list.\n", search);

}

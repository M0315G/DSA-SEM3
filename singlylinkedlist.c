#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
}*first=NULL;

void insert(){
    int choice,num;
    struct node *new=(struct node*)malloc(sizeof(struct node*));
    new->next=NULL;
    printf("Enter the no you want to insert.");
    scanf("%d",&num);
    new->data=num;
    printf("Enter 1 for Insert from front.\n2 for Insert from last.\n3 for Insert in-between.");
    scanf("%d",&choice);
    switch(choice){
        case 1:
            if(first==NULL){
                first=new;
            }else{
                new->next=first;
                first=new;
            }printf("Node added successfully\n");
            break;
        case 2:
            if(first==NULL){
                first=new;
            }else if(first->next==NULL){
                first->next=new;
            }else{
                struct node *temp=first;
                while(temp->next!=NULL){
                    temp=temp->next;
                }temp->next=new;
            }printf("Node added successfully\n");
            break;
        case 3:
            if(first==NULL){
                first=new;
            }else if(first->next==NULL){
                first->next=new;
            }else{
                int n1;
                struct node *temp1=first;
                printf("\nData elements present in Linked List\n");
                while (temp1->next!=NULL)
                {
                    printf("%d\n",temp1->data);
                    temp1=temp1->next;
                }printf("%d\n",temp1->data);
                
                printf("Enter after which data element you want to insert.");
                scanf("%d",&n1);
                struct node *temp=first;
                while(temp->data!=n1){
                    temp=temp->next;
                }
                new->next=temp->next;
                temp->next=new;
            }printf("Node added successfully\n");
            break;
        default:
            printf("Provide a valid input\n");
    }

}
void delete(){
    int choice;
    printf("Enter 1 to Delete from front.\n2 to Delete from last.\n3 to Delete in-between.");
    scanf("%d",&choice);
    switch(choice){
        case 1:
            if(first==NULL){
                printf("There are no elements in Linked List to delete.\n");
            }else if(first->next==NULL){
                struct node *temp=first;
                first=NULL;
                free(temp);
            }else{
                struct node *temp=first;
                first=first->next;
                free(temp);
            }printf("Element deleted successfully\n");
            break;
        case 2:
            if(first==NULL){
                printf("There are no elements in Linked List to delete.\n");
            }else if(first->next==NULL){
                struct node *temp=first;
                first=NULL;
                free(temp);
            }else{
                struct node *temp=first;
                while(temp->next->next!=NULL){
                    temp=temp->next;
                }temp->next=NULL;
            }printf("Element deleted successfully\n");
            break;
        case 3:
            if(first==NULL){
                printf("There are no elements in Linked List to delete.");
            }else if(first->next==NULL){
                struct node *temp=first;
                first=NULL;
                free(temp);
            }else{
                int n1;
                struct node *temp1=first;
                printf("\nData elements present in Linked List\n");
                while (temp1->next!=NULL)
                {
                    printf("%d\n",temp1->data);
                    temp1=temp1->next;
                }printf("%d\n",temp1->data);
                printf("Enter data element you want to delete.");
                scanf("%d",&n1);

                struct node *temp=first;
                while(temp->next->data!=n1){
                    temp=temp->next;
                }temp->next=temp->next->next;
            }printf("Element deleted successfully\n");
            break;
            
    }
}

void traversal(){
    struct node *temp=first;
    printf("The data elements in the Linked List are:\n");
    while(temp->next!=NULL){
        printf("%d\n",temp->data);
        temp=temp->next;
    }printf("%d\n",temp->data);
}


void main(){
    int choice;
label:    printf("Enter your choice:\n1 for Insert.\n2 for Delete.\n3 for Traversal\n4 to Exit.");
    scanf("%d",&choice);
    switch(choice){
        case 1:
            insert();
            goto label;
            break;
        case 2:
            delete();
            goto label;
            break;
        case 3:
            traversal();
            goto label;
            break;
        case 4:
            break;
        default:
            printf("Enter a valid choice.");
            goto label;
            break;
    }
}
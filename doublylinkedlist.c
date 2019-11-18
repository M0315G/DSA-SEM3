#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node *prev;
    int info;
    struct node *next;
}*first=NULL;

void insert(){
    int input,data,num;
    printf("\nEnter the info you want to insert.");
    scanf("%d",&data);
    printf("\nWhere do you want to insert?\n1 for First.\n2 for Last.\n3 for In-between.");
    scanf("%d",&input);
    struct node *new= (struct node*)malloc(sizeof(struct node*));
    new->next=NULL;
    new->prev=NULL;
    new->info=data;

    if(first==NULL){
        first=new;
        first->info=data;
    }else{
        switch(input){
        case 1:
            {
                first->prev=new;
                new->next=first;
                first=new;
            
            printf("\nNode added Successfullt in front.");
            break;
            }
        case 2:
            if(first->next==NULL){
                first->next=new;
                new->prev=first;
            }else{
                struct node *temp= first;
                while(temp->next!=NULL){
                    temp=temp->next;
                }
                temp->next=new;
                new->prev=temp;
            }
            printf("\nNode added successfully in the back");
            break;
        case 3:
            {
                struct node *temp=first;
                printf("\nThe element present in the list are:");
                while(temp!=NULL){
                    printf("\n%d",temp->info);
                    temp=temp->next;
                }
                //printf("\n%d",temp->next);
                printf("\nEnter the no after which you want to insert.");
                scanf("%d",&num);
                temp=first;
                while(temp->info!=num&&temp->next!=NULL){
                    temp=temp->next;
                }
                printf("\n1");
                if(temp->info!=num){
                    printf("\nThe no entered doesn't exist in the link");
                    break;
                }else{
                    new->next=temp->next;
                    new->prev=temp;
                    temp->next->prev=new;
                    temp->next=new;
                    printf("\nNode added sucessfully in between.");    
                }
                break;
            }
            default:
                printf("\nEnter a valid choice.");
                break;
        }
    }
    
}

void delete(){
    int data,num;
    printf("\nWhere do you want to delete?\n1 for First.\n2 for Last.\n3 for In-between.");
    scanf("%d",&data);
    if(first==NULL){
        printf("\nThere is no node to delete.The list is empty.");
    }else if(first->next==NULL){
        struct node *temp1=first;
        first=NULL;
        free(temp1);
    }else{
        switch(data){
        case 1:
        {    struct node *temp;
            temp=first;
            first=temp->next;
            first->prev=NULL;
            free(temp);
            printf("\nNode deleted successfullt from front.");
            break;
            }
        case 2:
        {   struct node *temp=first;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->prev->next=NULL;
            free(temp);
            printf("\nNode deleted successfullt from last.");
            break;
            }
        case 3:
        {   struct node *temp=first;
            printf("The elements present in the list are:");
            while(temp!=NULL){
                printf("\n%d",temp->info);
                temp=temp->next;
            }//printf("%d",temp->info);
            printf("\nEnter the no you want to delete.");
            scanf("%d",&num);
            temp=first;
            while(temp->info!=num&&temp->next!=NULL){
                temp=temp->next;
            }
            if(temp->info!=num){
                printf("\nThe no you entered is not in the list.");
                break;
            }else{
                if(temp->prev==NULL){
                    first=temp->next;
                    temp->next->prev=NULL;
                    free(temp);
                }else{
                    temp=temp->prev;
                    temp->next->next->prev=temp;
                    temp->next=temp->next->next;
                    temp=temp->next;
                    free(temp);
                }
                
                printf("\nNode deleted successsfully.");
            }
            break;
            }
        }
    }
    

}

void traversal(){
    struct node *temp=first;
    printf("\nThe elements present in the list are:");
    while(temp!=NULL){
        printf("\n%d",temp->info);
        temp=temp->next;
    }
}

void main(){
    int choice;
    printf("Welcome User.\n");
menu:printf("Enter your choice.\n1 for Insert.\n2 for Delete.\n3 for traversal.\n4 to exit.");
    scanf("%d",&choice);

    switch(choice){
        case 1:
            insert();
            goto menu;
            break;
        case 2:
            delete();
            goto menu;
            break;
        case 3:
            traversal();
            goto menu;
            break;
        case 4:
            break;
        default:
            printf("Enter a valid choice");
            break;
    }

}
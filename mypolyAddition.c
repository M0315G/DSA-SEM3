#include<stdio.h>
#include<stdlib.h>

struct node{
    int pow;
    float coeff;
    struct node *next;
};

struct node* createNewNode(float coeff,int exp){
    struct node *new= (struct node*)malloc(sizeof(struct node));
    new->coeff=coeff;
    new->pow=exp;
    new->next=NULL;
    return new;
}

struct node* insert(struct node *t1,float coeff,int exp){
    if(t1==NULL){
        return createNewNode(coeff,exp);
    }else{
        if(t1->pow>exp){
            struct node *new=createNewNode(coeff,exp);
            new->next=t1;
            return new;
        }else if(t1->pow<exp){
            t1->next=insert(t1->next,coeff,exp);
        }else if(t1->pow==exp){
            t1->coeff+=coeff;
        }
        return t1;
            
    }
}

void display(struct node*t){
    struct node *temp=t;
    printf("\n");
    while(temp!=NULL){
        printf("%.2f x^ %d\t",temp->coeff,temp->pow);
        temp=temp->next;
    }
}

struct node* add(struct node *t1,struct node *t2,struct node *t3){
    struct node *ptr1,*ptr2,*ptr3;
    ptr1=t1; ptr2=t2;

    if(ptr1->pow==ptr2->pow){
        t3=createNewNode(ptr1->coeff+ptr2->coeff,ptr1->pow);
        ptr2=ptr2->next;
        ptr1=ptr1->next;
    }else if(ptr1->pow<ptr2->pow){
        ptr3=createNewNode(ptr1->coeff,ptr1->pow);
        ptr1=ptr1->next;
    }else if(ptr1->pow>ptr2->pow){
        ptr3=createNewNode(ptr2->coeff,ptr2->pow);
        ptr2=ptr2->next;
    }

    ptr3=t3;

    while(ptr1!=NULL&&ptr2!=NULL){
        if(ptr1->pow==ptr2->pow){
            ptr3->next=createNewNode(ptr1->coeff+ptr2->coeff,ptr1->pow);
            ptr2=ptr2->next;
            ptr1=ptr1->next;
        }else if(ptr1->pow<ptr2->pow){
            ptr3->next=createNewNode(ptr1->coeff,ptr1->pow);
            ptr1=ptr1->next;
        }else if(ptr1->pow>ptr2->pow){
            ptr3->next=createNewNode(ptr2->coeff,ptr2->pow);
            ptr2=ptr2->next;
        }
        ptr3=ptr3->next;
    }
    if(ptr1==NULL){
        while(ptr2!=NULL){
            ptr3->next=createNewNode(ptr2->coeff,ptr2->pow);
            ptr3=ptr3->next;
            ptr2=ptr2->next;
        }
    }else if(ptr2==NULL){
        while(ptr1!=NULL){
            ptr3->next=createNewNode(ptr1->coeff,ptr1->pow);
            ptr3=ptr3->next;
            ptr1=ptr1->next;
        }
    }

    return t3;
}

void main(){
    struct node *p1=NULL,*p2=NULL,*p3=NULL;
    printf("\nEnter the elements of 1st polynomial:-");
    float coeff;
    int exp;
    int ans=1;
    while(1){
        printf("\nEnter coefficient:-");
        scanf("%f",&coeff);
        printf("\nEnter the exponent:-");
        scanf("%d",&exp);
        p1=insert(p1,coeff,exp);
        printf("\nEnter 1 to continue entering terms for 1st polynomial, 0 to stop.");
        scanf("%d",&ans);
        if(ans!=1){
            break;
        }
    }
    display(p1);

    printf("\nEnter the elements of 2nd polynomial:-");
    while(1){
        printf("\nEnter coefficient:-");
        scanf("%f",&coeff);
        printf("\nEnter the exponent:-");
        scanf("%d",&exp);
        p2=insert(p2,coeff,exp);
        printf("\nEnter 1 to continue entering terms for 2nd polynomial, 0 to stop.");
        scanf("%d",&ans);
        if(ans!=1){
            break;
        }
    }
    display(p2);

    p3=add(p1,p2,p3);

    printf("\nThe result of addition of both the polynomial is:-");
    display(p3);
}
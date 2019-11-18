#include<stdio.h>
#include<stdlib.h>

struct node{
    int power;
    float coeff;
    struct node *next;
}*p1=NULL,*p2=NULL,*p3=NULL;

struct node* insert(int p,float c, int a){
    struct node *temp,*head=NULL;
    if(a==1){
        temp=p1;
    }else if(a==2){
        temp=p2;
    }
    struct node *new = (struct node*)malloc(sizeof(struct node));
    new->coeff=c;
    new->power=p;
    new->next=NULL;
    head=temp;
    if(temp==NULL){
        temp=new;
        head=temp;
    }else if(head->power>new->power){
        new->next=head;
        head=new;
        
    }else{
        while(temp->next!=NULL&&temp->next->power<=new->power){
            temp=temp->next;
        }
        if(temp->power==new->power){
            temp->coeff+=new->coeff;
        }else{
            new->next=temp->next;
            temp->next=new;
        }
        
    }
    return head;
}

void traversal(struct node *head){
    struct node *temp=head;
    while(temp!=NULL){
        printf("%.0fx^%d ",temp->coeff,temp->power);
        temp=temp->next;
    }
}

struct node* add(struct node *h1,struct node*h2,struct node *h3){
    struct node *t1=h1,*t2=h2,*t3=h3,*a,*head;
    struct node *new = (struct node*)malloc(sizeof(struct node));
    new->next=NULL;
    head=t3;
    
        while(t1!=NULL&&t2!=NULL){
            if(head==NULL){
                if(t1->power>t2->power){
                    new=t2;
                    t2=t2->next;
                }else if(t1->power<t2->power){
                    new=t1;
                    t1=t1->next;
                }else if(t1->power==t2->power){
                    new->power=t1->power;
                    new->coeff=t1->coeff+t2->coeff;
                    t1=t1->next;
                    t2=t2->next;
                }
                head=new;
                t3=head;
                //t3=t3->next;
        
            }else{
                struct node *t= (struct node*)malloc(sizeof(struct node));
                t->next=NULL;
                if(t1->power>t2->power){
                    t=t2;
                    t2=t2->next;
                }else if(t1->power<t2->power){
                    t=t1;
                    t1=t1->next;
                }else if(t1->power==t2->power){
                    t->power=t1->power;
                    t->coeff=t1->coeff+t2->coeff;
                    t1=t1->next;
                    t2=t2->next;
                }
                t3->next=t;
                t3=t3->next;
            }
        }

        if(t1==NULL){
            a=t2;
        }else if(t2==NULL){
            a=t1;
        }
        while(a!=NULL){
            new=a;
            a=a->next;
            t3->next=new;
            t3=t3->next;
            
        }
    

    return head;

}

void main(){
    int ans,p;
    float c;
    printf("\nWelcome user!");
    printf("\nType 1 to start entering terms for 1st polynomial.");
    scanf("%d",&ans);
    
    while(ans==1){
        printf("\nEnter coefficent:");
        scanf("%f",&c);
        printf("\nEnter power:");
        scanf("%d",&p);
        p1=insert(p,c,1);
        printf("\nContinue? 1 for YES. -1 for NO");
        scanf("%d",&ans);
    }

    traversal(p1);

    printf("\nType 1 to start entering terms for 2nd polynomial.");
    scanf("%d",&ans);

    while(ans==1){
        printf("\nEnter coefficent:");
        scanf("%f",&c);
        printf("\nEnter power:");
        scanf("%d",&p);
        p2=insert(p,c,2);
        printf("\nContinue? 1 for YES. -1 for NO");
        scanf("%d",&ans);
    }

    traversal(p2);

    p3=add(p1,p2,p3);
    printf("\nPerforming addition operation on both the polynomial we get:");
    traversal(p3);

}
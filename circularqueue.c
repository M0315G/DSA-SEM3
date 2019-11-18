//#include<stdio.h>
int circqueue[5];
int front, rear;
//rear=front=-1;

void insert(){
    int element;
    if((rear==4&&front==0)||(rear=front-1)){
        printf("Queue overflow");
    }else{
        printf("Enter the no you want to insert.");
        scanf("%d",&element);
        if(rear==4){
            rear=0;
            circqueue[rear]=element;
        }else if(rear==-1&&front==-1){
            front=rear=0;
            circqueue[rear]=element;
        }else {
            rear += 1;
            circqueue[rear]=element;
        }
    }
}

void delete(){
    if(front==-1){
        printf("Queue is underflow");
    }else {
        if(rear==front){
            rear=front=-1;
        }else if(front==4){
            front=0;
        }else
            front +=1;
    }
}

void display(){
    if(rear!=-1&&front!=-1){
        for(int i=front;i<=rear;i++){
        printf("%d\n",circqueue[i]);
        }
    }else{
        printf("There are no elements in queue to print");
    }
    
}
void main(){
    char choice;
    printf("Enter your choice!\n I for insert.\nD for delete.\nX for display");
    scanf("%c",&choice);
    switch(choice){
        case 'I':
            insert();
            break;
        case 'D':
            delete();
            break;
        case 'X':
            display();
            break;
        default:
            printf("Please enter a valid choice");
    }
}
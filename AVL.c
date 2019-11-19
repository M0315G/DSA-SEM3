#include<stdio.h>


struct node{
    int info;
    struct node *left;
    struct node *right;
    int height;
};

struct node* create_new_node(int info){
    struct node *temp= (struct node*)malloc(sizeof(struct node));
    temp->height=1;
    temp->info=info;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

int max(int a, int b){
    return a>b?a:b;
}

int height(struct node *t1){
    if(t1==NULL){
        return 0;
    }else{
        return t1->height;
    }
}

struct node *rightRotate(struct node *y) 
{ 
    struct node *x = y->left; 
    struct node *T2 = x->right; 
  
    // Perform rotation 
    x->right = y; 
    y->left = T2; 
    printf("Right Rotation");
    // Update heights 
    y->height = max(height(y->left), height(y->right))+1; 
    x->height = max(height(x->left), height(x->right))+1; 
  
    // Return new root 
    return x; 
} 
  

struct node *leftRotate(struct node *x) 
{ 
    struct node *y = x->right; 
    struct node *T2 = y->left; 
  
    // Perform rotation 
    y->left = x; 
    x->right = T2; 
    printf("Left Rotation");
    //  Update heights 
    x->height = max(height(x->left), height(x->right))+1; 
    y->height = max(height(y->left), height(y->right))+1; 
  
    // Return new root 
    return y; 
} 
int balance_factor(struct node *temp){
    if(temp==NULL){
        return 0;
    }else{
        return height(temp->left)-height(temp->right);
    }
}
struct node* insert(struct node *root,int info){
    if(root==NULL){
        root=create_new_node(info);
        return root;
    }else if(info>root->info){
        root->right=insert(root->right,info);
    }else if(info<root->info){
        root->left= insert(root->left,info);
    }

    root->height= 1+max(height(root->left),height(root->right));

    int balance = balance_factor(root);
    
    if(balance>1 && info<root->left->info){
        // Left Left Case
        return rightRotate(root);

    }else if(balance<-1 && info>root->right->info){
        // Right Right Case
        return leftRotate(root);

    }else if(balance>1 && info>root->left->info){
        // Left Right Case
        root->left=leftRotate(root->left);
        return rightRotate(root);

    }else if(balance<-1 && info<root->right->info){
        // Right Left Case
        root->right=rightRotate(root->right);
        return leftRotate(root);

    }

     return root;
}

void preordertraversal(struct node *root){
    if(root==NULL){
        return;
    }else{
        printf("\t%d",root->info);
        preordertraversal(root->left);
        preordertraversal(root->right);
        return;
    }
}

void main(){
    int choice;
    struct node *root=NULL;
        while(choice!=-1){
            printf("!----------------------------------------------------------------------------------------!");
            printf("\nEnter your choice:-\n1 for Insertion.\n2 for Deletion.\n3 for Traversal.\n-1 to Exit.");
            printf("!----------------------------------------------------------------------------------------!");
            scanf("%d",&choice);
            switch(choice){
                case 1:
                    //Calling Insert function which will insert according to BST.
                    int info;
                    printf("Enter the number you want to insert.");
                    scanf("%d",&info);
                    root=insert(root,info);
                    break;
                case 2:
                    //Calling delete function which will delete according to BST.
                    break;
                case 3:
                    //Traversing function to print all the elements of the tree.
                    preordertraversal(root);
                    break;
                case -1:
                    //Exit the program.
                    printf("Exiting...");
                    break;
                default:
                    printf("Enter a valid Input.");
            }
        }
}
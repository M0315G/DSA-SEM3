#include<stdio.h>
#include<stdlib.h>

struct node {
    struct node *left;
    int data;
    struct node *right;
}*root=NULL;

struct node* addtotree(int num){
    //struct node *temp=root;
    struct node *head=root;
    struct node *new=(struct node*)malloc(sizeof(struct node));
    new->left=NULL;
    new->right=NULL;
    new->data=num;
    if(head==NULL){
        head=new;
        //temp=head;
        return head;
    }else{
        struct node *t1=head;
        //head=t1;
        //struct node *new= (struct node*)malloc(sizeof(struct node));
        while(t1->left!=NULL||t1->right!=NULL){
            if(t1->data>num){
                if(t1->left==NULL){
                    break;
                }else{
                    t1=t1->left;
                }
                
            }else if(t1->data<num){
                if(t1->right==NULL){
                    break;
                }else{
                    t1=t1->right;
                }
            }
        }
        if(num<t1->data){
            if(t1->left==NULL)
                t1->left=new;
        }else if(num>t1->data){
            if(t1->right==NULL)
                t1->right=new;
        }
        //t1=new;
        return head;
    }
}
struct node * minValueNode(struct node* node) 
{ 
    struct node* current = node; 
  
    /* loop down to find the leftmost leaf */
    while (current && current->left != NULL) 
        current = current->left; 
  
    return current; 
} 
  

struct node* deleteNode(struct node* root, int key) 
{ 
    // base case 
    if (root == NULL) return root; 
  
    
    if (key < root->data) 
        root->left = deleteNode(root->left, key); 

    else if (key > root->data) 
        root->right = deleteNode(root->right, key); 
   
    else
    { 
        // node with only one child or no child 
        if (root->left == NULL) 
        { 
            struct node *temp = root->right; 
            free(root); 
            return temp; 
        } 
        else if (root->right == NULL) 
        { 
            struct node *temp = root->left; 
            free(root); 
            return temp; 
        } 
  
        // node with two children: Get the inorder successor (smallest 
        // in the right subtree) 
        struct node* temp = minValueNode(root->right); 
  
        // Copy the inorder successor's content to this node 
        root->data = temp->data; 
  
        // Delete the inorder successor 
        root->right = deleteNode(root->right, temp->data); 
    } 
    return root; 
} 


void postordertraversal(struct node* t1){
    if(t1==NULL){
        return;
    }else{
        postordertraversal(t1->left);
        postordertraversal(t1->right);
        printf("  %d",t1->data);
    }
}
void inordertraversal(struct node *t1){
    if(t1==NULL){
        return;
    }else{
        inordertraversal(t1->left);
        printf("  %d",t1->data);
        inordertraversal(t1->right);
    }
}
void preordertraversal(struct node *t1){
    if(t1==NULL){
        return;
    }else{
        printf("  %d",t1->data);
        preordertraversal(t1->left);
        preordertraversal(t1->right);
    }
    
}
void main(){
    int num,ans;
    while(ans!=-1){
        printf("\nEnter your choice.\n1.Insert.\n2.Delete.\n3.Traversal.\n-1 to Exit.");
        scanf("%d",&ans);
        if(ans!=-1){
            if(ans==1){
                printf("\nEnter a digit to enter into a Binary Search Tree.");
                scanf("%d",&num);
                root=addtotree(num);
            }else if(ans==3){
                printf("\nThe POST order traversal of the BST is:");
                postordertraversal(root);
                printf("\nThe INORDER traversal of the BST is:");
                inordertraversal(root);
                printf("\nThe PRE order traversal of the BST is:");
                preordertraversal(root);
            }else if(ans==2){
                printf("\nEnter the no you want to delete:");
                scanf("%d",&num);
                root=deleteNode(root,num);
            }else{
                printf("Enter a valid choice");
            }
        }
    }
    printf("\nExiting...");
    
    
}
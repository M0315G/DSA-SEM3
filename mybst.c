#include<stdio.h>
#include<stdlib.h>
struct node{
    int info;
    struct node *left,*right;
};

struct node* create_new_node(int data){
    struct node *new= (struct node*)malloc(sizeof(struct node));
    new->info=data;
    new->left=NULL;
    new->right=NULL;
    return new;
}

struct node* insert(struct node* node,int info){
    if(node==NULL){
        return create_new_node(info);
    }else{
        if(info>node->info){
            node->right=insert(node->right,info);
        }else if(info<node->info){
            node->left=insert(node->left,info);
        }
        return node;
    }
}

struct node* find_predasor(struct node* temp){
    if(temp->right==NULL){
        return temp;
    }else{
        struct node*t1=temp;
        while(t1->right!=NULL){
            t1=t1->right;
        }
        return t1;
    }
}

struct node* delete(struct node* node,int data){
    if(node==NULL){
        printf("\nThe BST is already empty. Try inserting some elements first!");
        return node;
    }else{
        if(data==node->info){
            //check for the no of children the node has!
            if(node->left==NULL&&node->right==NULL){//Node with no children i.e. Leaf Node.
                printf("\n%d has been found! It is being Deleted now!",data);
                free(node);
                return NULL;
            }else if(node->left==NULL||node->right==NULL){//Node with only one children.
                if(node->left!=NULL){
                    printf("\n%d has been found! It is being Deleted now!",data);
                    return node->left;
                }else if(node->right!=NULL){
                    printf("\n%d has been found! It is being Deleted now!",data);
                    return node->right;
                }
            }else{//Node with two children. Here we first find the Inorder Predassor of the element then replace it's contents and ultimately delete the predassor
                struct node *predasor=find_predasor(node->left);
                node->info=predasor->info;
                node->left=delete(node->left,predasor->info);
            }
        }else if(data>node->info){
            if(node->right!=NULL){
                node->right=delete(node->right,data);
            }else{
                printf("The specified element doesnot exist in the BST.");
            }
        }else if(data<node->info){
            if(node->left!=NULL){
                node->left=delete(node->left,data);
            }else{
                printf("The specified element doesnot exist in the BST.");
            }
        }

        return node;
    }
}

void inorder_traversal(struct node*t1){
    if(t1==NULL){
        return;
    }else{
        inorder_traversal(t1->left);
        printf("%d\t",t1->info);
        inorder_traversal(t1->right);
        return;
    }
}

void preorder_traversal(struct node*t1){
    if(t1==NULL){
        return;
    }else{
        printf("%d\t",t1->info);
        preorder_traversal(t1->left);
        preorder_traversal(t1->right);
        return;
    }
}

void postorder_traversal(struct node*t1){
    if(t1==NULL){
        return;
    }else{
        postorder_traversal(t1->left);
        postorder_traversal(t1->right);
        printf("%d\t",t1->info);
        return;
    }
}
void traversal(struct  node* temp){
    printf("\nThe Inorder Traversal is :-");
    inorder_traversal(temp);
    printf("\nThe Postorder Traversal is :-");
    postorder_traversal(temp);
    printf("\nThe Preorder Traversal is :-");
    preorder_traversal(temp);
}

void main(){
    struct node *root=NULL;
    int c=-1;
    int info;
    while(c!=0){
        printf("\nEnter your choice:-\n1. To insert inot BST.\n2. To delete from BST.\n3. To traverse the BST.\n0. To Exit.");
        scanf("%d",&c);
        switch(c){
            case 1:
                //calling of the insert function of BST.
                printf("Enter the number you want to Insert into BST.");
                scanf("%d",&info);
                root=insert(root,info);
                break;
            case 2:
                //calling of the delete function of BST.
                printf("Enter the number you want to delete from BST.");
                scanf("%d",&info);
                root=delete(root,info);
                break;
            case 3:
                //calling of the traversal function of BST.
                traversal(root);
                break;
            case 0:
                printf("Visit Again!");
                break;
            default:
                printf("Please enter a valid choice!");
        }

    }
}
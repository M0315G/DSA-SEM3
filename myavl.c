#include<stdio.h>
#include<stdlib.h>

struct node{
    int info;
    struct node *left,*right;
    int height;
};

struct node* createNewNode(int info){
    struct node* new= (struct node*)malloc(sizeof(struct node));
    new->info=info;
    new->left=NULL;
    new->right=NULL;
    new->height=1;
    return new;
}

int max(int a,int b){
    return a>=b?a:b;
}

int height(struct node *t1){
    if(t1==NULL){
        return 0;
    }else{
        return t1->height;
    }
}

struct node* RightRotation(struct node*t1){
    struct node *temp=t1->left;

    //Swapping the subtrees to make the AVL Tree balanced.
    t1->left=temp->right;
    temp->right=t1;

    //Adjusting the Heights of both the nodes which are swapped.
    temp->height=1+max(height(temp->left),height(temp->right));
    t1->height=1+max(height(t1->left),height(t1->right));

    //Returning the node.
    return temp;
}

struct node* LeftRotation(struct node*t1){
    struct node *temp=t1->right;

    //Swapping thew subtrees to make the AVL Tree Balanced.
    t1->right=temp->left;
    temp->left=t1;

    //Adjusting the Heights of both the nodes which are swapped.
    temp->height=1+max(height(temp->left),height(temp->right));
    t1->height=1+max(height(t1->left),height(t1->right));

    return temp;
}

int checkBalanceFactor(struct node *t1){
    return (height(t1->left) - height(t1->right));
}

struct node* insert(struct node* temp,int data){
    if(temp==NULL){
        return createNewNode(data);
    }else{
        if(data>temp->info){
            temp->right=insert(temp->right,data);
        }else if(data<temp->info){
            temp->left=insert(temp->left,data);
        }

        temp->height=1+max(height(temp->left),height(temp->right));
        //Checking of the Tree is Unbalanced.
        int bf=checkBalanceFactor(temp);

        //Checking each case.
        if(bf==2&&checkBalanceFactor(temp->left)==1){
            //Rotate Right Once.
            printf("Doing LL Rotation");
            temp=RightRotation(temp);
        }else if(bf==3&&checkBalanceFactor(temp->left)==-2){
            //Rotate Left once then rotate Right.
            printf("Doing LR Rotation");
            temp->left=LeftRotation(temp->left);
            temp=RightRotation(temp);
        }else if(bf==-3&&checkBalanceFactor(temp->right)==-2){
            //Rotate Left once.
            printf("Doing RR Rotation");
            temp=LeftRotation(temp);
        }else if(bf==-3&&checkBalanceFactor(temp->right)==2){
            //Rotate Right once then do Left Rotation.
            printf("Doing RL Rotation");
            temp->right=RightRotation(temp->right);
            temp=LeftRotation(temp);
        }
        return temp;
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
                predasor->info=data;
                node->left=delete(node->left,data);
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

        node->height=1+max(height(node->left),height(node->right));
        //Checking of the Tree is Unbalanced.
        int bf=checkBalanceFactor(node);

        //Checking each case.
        if(bf==2&&checkBalanceFactor(node->left)==1){
            //Rotate Right Once.
            printf("Doing LL Rotation");
            node=RightRotation(node);
        }else if(bf==2&&checkBalanceFactor(node->left)==-1){
            //Rotate Left once then rotate Right.
            printf("Doing LR Rotation");
            node->left=LeftRotation(node->left);
            node=RightRotation(node);
        }else if(bf==-2&&checkBalanceFactor(node->right)==-1){
            //Rotate Left once.
            printf("Doing RR Rotation");
            node=LeftRotation(node);
        }else if(bf==-2&&checkBalanceFactor(node->right)==1){
            //Rotate Right once then do Left Rotation.
            printf("Doing RL Rotation");
            node->right=RightRotation(node->right);
            node=LeftRotation(node);
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
        printf("\nEnter your choice:-\n1. To insert into AVL Tree.\n2. To delete from AVL Tree.\n3. To traverse the AVL Tree.\n0. To Exit.");
        scanf("%d",&c);
        switch(c){
            case 1:
                //calling of the insert function of AVL Tree.
                printf("Enter the number you want to Insert into AVL Tree.");
                scanf("%d",&info);
                root=insert(root,info);
                break;
            case 2:
                //calling of the delete function of AVL Tree.
                printf("Enter the number you want to delete from AVL Tree.");
                scanf("%d",&info);
                root=delete(root,info);
                break;
            case 3:
                //calling of the traversal function of AVL Tree.
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
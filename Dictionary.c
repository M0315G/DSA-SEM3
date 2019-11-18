#include <stdio.h>
  #include <stdlib.h>
  #include <string.h>

  struct BSTnode {
        char word[128], meaning[400];
        struct BSTnode *left, *right;
  };

  struct BSTnode *root = NULL;

  struct BSTnode * createNode(char *word, char *meaning) {
        struct BSTnode *newnode;
        newnode = (struct BSTnode *)malloc(sizeof(struct BSTnode));
        strcpy(newnode->word, word);
        strcpy(newnode->meaning, meaning);
        newnode->left = newnode->right = NULL;
        return newnode;
  }

  void insert(char *word, char *meaning) {
        struct BSTnode *parent = NULL, *current = NULL, *newnode = NULL;
        int res = 0;
        if (!root) {
                root = createNode(word, meaning);
                return;
        }
        for (current = root; current !=NULL;
           current = (res > 0) ? current->right : current->left) {
                res = strcasecmp(word, current->word);
                parent = current;
        }
        newnode = createNode(word, meaning);
        res > 0 ? (parent->right = newnode) : (parent->left = newnode);
        return;
  }

  

  void findElement(char *str) {
        struct BSTnode *temp = NULL;
        int flag = 0, res = 0;
        if (root == NULL) {
                printf("Binary Search Tree is out of station!!\n");
                return;
        }
        temp = root;
        while (temp) {
                if ((res = strcasecmp(temp->word, str)) == 0) {
                        printf("!!-----------------------------------------------------------------------------!!");
                        printf("\nWord   : %s", str);
                        printf("\nMeaning: %s", temp->meaning);
                        printf("\n!!-----------------------------------------------------------------------------!!");
                        flag = 1;
                        break;
                }
                temp = (res > 0) ? temp->left : temp->right;
        }
        if (!flag)
                printf("\nSearch Element not found in Binary Search Tree");
        return;
  }

  void inorderTraversal(struct BSTnode *myNode) {
        if (myNode) {
                inorderTraversal(myNode->left);
                printf("\nWord    : %s", myNode->word);
                printf("\nMeaning : %s", myNode->meaning);
                printf("\n");
                inorderTraversal(myNode->right);
        }
        return;
  }

  int main() {
        int ch;
        char word[128],meaning[400];
        char search_word[128],extra[100];
        int c=1,choice;
        FILE *f1;
        f1=fopen("Dictionary.txt","r");
        while(fgets(word,128,f1)!=NULL){
            if(fgets(meaning,400,f1)!=NULL){
                insert(word,meaning);
                fgets(extra,100,f1);
            }

        }
        while(c==1){
            printf("\n!!-------------------------------------------------------------------!!");
            printf("\nWhat do you want to do?\n1-Search a word.\n2-Exit.\n3-Verify the BST.");
            printf("\n!!-------------------------------------------------------------------!!");
            scanf("%d",&choice);
            switch(choice){
                case 1:
                    printf("!!-------------------------------------------------------------------!!");
                    printf("\nEnter the word whose meaning you want to search:-");
                    fgets(search_word,128,stdin);
                    fgets(search_word,128,stdin);
                    findElement(search_word);
                    break;
                case 2:
                    printf("Exitting the program...");
                    c=0;
                    break;
                case 3:
                    inorderTraversal(root);
                    break;

            }

        }
        
        // while (1) {
        //         printf("\n1. Insertion\t2. Deletion\n");
        //         printf("3. Searching\t4. Traversal\n");
        //         printf("5. Exit\nEnter ur choice:");
        //         scanf("%d", &ch);
        //         getchar();
        //         switch (ch) {
        //                 case 1:
        //                 case 2:
        //                         printf("Enter the word to delete:");
        //                         //fgets(str, 100, stdin);
        //                         //deleteNode(str);
        //                         break;
        //                 case 3:
        //                         printf("Enter the search word:");
        //                         //fgets(str, 100, stdin);
        //                         //findElement(str);
        //                         break;
        //                 case 4:
        //                         inorderTraversal(root);
        //                         break;
        //                 case 5:
        //                         exit(0);
        //                 default:
        //                         printf("You have entered wrong option\n");
        //                         break;
        //         }
        // }
        return 0;
  }
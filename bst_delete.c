#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *left;
    struct node *right;
};
struct node *parent=NULL;
struct node *cur=NULL;
struct node *root=NULL;
struct node *temp;
struct node *new_node;
struct node *create(struct node *root,int key){
    new_node=(struct node*)malloc(sizeof(struct node*));
    if(root==NULL){
        new_node->data=key;
        new_node->left=NULL;
        new_node->right=NULL;
        root=new_node;
    }
    else{
        printf("Tree has already been created.");
    }
    return root;
}
struct node *insert(struct node *root,int key){
    if(root==NULL){
        return create(root,key);
    }
    else if(root->data< key){
        root->right=insert(root->right,key);
    }
    else if(root->data >key){
        root->left=insert(root->left,key);
    }
    
    return root;
}
struct node *search(struct node *root, int x){
    if(root!=NULL){
        search(root->left,x);
        if(root->data==x){
            printf("Node is present in tree\n");
            return root;
        }
        else{
            printf("Node is not present in tree\n");
        }
        search(root->right,x);
    }
    return root;
}
struct node *inorder(struct node* root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d  ",root->data);
        inorder(root->right);
    }
}
int right(struct node *root)
{
    temp = root;
    while(temp->left != NULL){
         temp = temp->left;
        }
    return temp->data;
}
struct node *delete_(struct node *root,int x){
    
    if(root == NULL)
        return NULL;
    if(root->data < x)
        root->right = delete_(root->right,x);
    else if(root->data > x)
        root->left = delete_(root->left,x);
    else
    {
        if(root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }
        else if(root->left == NULL)
        {
            temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL)
        {
            temp = root->left;
            free(root);
            return temp;
        }
        else
        {
            int r = right(root->right);
            root->data = r;
            root->right = delete_(root->right,r);
        }
    }
    return root;

}

int main(){
    int ch,key,x,del;
    do{
    printf("Menu\n");
    printf("Press 2 to insert a node\n");
    printf("Press 3 to search a node in the tree\n");
    printf("Press 4 to delete node\n");
    printf("Press 5 to traverse through BST using Inorder\n");
    printf("Press 6 to exit.\n");
    printf("Enter your choice:- ");
    scanf("%d",&ch);
    switch(ch){
        case 1:{
            printf("Enter the value of 1st root node:- ");
            scanf("%d",&key);
            root=create(root,key);
            break;
        }
        case 2:{
            printf("Enter the value of node to be inserted:- ");
            scanf("%d",&key);
            root=insert(root,key);
            printf("Node inserted!!\n");
            break;
        }
        case 3:{
            printf("Enter the node to be searched:- ");
            scanf("%d",&x);
            root=search(root,x);
            break;
        }
        case 4:{
            printf("Enter node to be deleted:-");
            scanf("%d",&del);
            root=delete_(root,del);
            printf("Node deleted from BST\n");
            break;
        }
        case 5:{
            inorder(root);
            break;
        }
        default:
        printf("Invalid input");

    }
    }while(ch!=6);
}
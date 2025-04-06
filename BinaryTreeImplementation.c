#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node{
    int data;
    struct node* right;
    struct node* left;
};
struct node* create();
void inorder(struct node*);
void preorder(struct node*);    
void postorder(struct node*);   
int main(){
    struct node* root;
    root=NULL;
    root=create();
    return 0;
}
struct node* create(){
    int x;
    struct node* newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter value to be inserted in node( Enter -1 to stop!)");
    scanf("%d",&x);
    if(x==-1){
        return 0;
    }
    newnode->data=x;
    printf("Enter left child of %d",x);
    newnode->left=create();
    printf("Enter right child of %d",x);
    newnode->right=create();
    return newnode;
}
void inorder(struct node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    printf("%d",root->data);
    inorder(root->right);
}
void preorder(struct node* root){
    if(root==NULL){
        return;
    }
    printf("%d",root->data);
    preorder(root->left);
    preorder(root->right);
}
void postorder(struct node* root){
    if(root==NULL){
        return;
    }
    postorde(root->left);
    postorder(root->right);
    printf("%d",root->data);
}
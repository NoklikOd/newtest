//implement node as single connected list
//implement push and print functions
//use c language
#include <stdlib.h>
#include <stdio.h>
typedef struct node node;
typedef struct node{
    node* next;
    int data;
};

void print(node* n){
    while(n){
        printf("%d\n",n->data);
        n=n->next;
    }
}
void push(node** n,int d){
    if(*n==NULL){
        *n=malloc(sizeof(node));
        (*n)->data=d;
        (*n)->next=NULL;
    }
    else{
        push(&(*n)->next,d);
    }
}

int main(){
    node* n = NULL;

    push(&n,1);
    push(&n,2);
    push(&n,3);
    push(&n,4);
    push(&n,5);

    print(n);
    return 0;
}
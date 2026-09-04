#include<stdio.h>
#include<stdlib.h>
struct node{
  int info;
  struct node *next;
};
struct node *head=NULL;
struct node *create(struct node *head);
struct node *display(struct node *head);
struct node *insertatbeg(struct node *head);
struct node *insertatend(struct node *head);
struct node *insertatpos(struct node *head);
struct node *deleteatbeg(struct node *head);
struct node *deleteatend(struct node *head);
struct node *deleteatpos(struct node *head);


int main(){
  int ch;
  do{
    printf("\n1.create 2.display 3.insetatbeg 4.insertatend 5.insertatpos 6.deleteatbeg 7.deleteatend 8.deleteatpos  0.exit\n");
    printf("enter choice\n");
    scanf("%d",&ch);
    switch(ch){
      case 1:head=create(head);break;
      case 2:head=display(head);break;
      case 3:head=insertatbeg(head);break;
      case 4:head=insertatend(head);break;
      case 5:head=insertatpos(head);break;
      case 6:head=deleteatbeg(head);break;
      case 7:head=deleteatend(head);break;
      case 8:head=deleteatpos(head);break;
      case 0:exit(1);break;
    }
    
  }
  while(1);
  return 0;
}
struct node *create(struct node *head){
    struct node *ptr=head;
    int inf;
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    printf("enter the information to be stored");
    scanf("%d",&inf);
    temp->info=inf;
    temp->next=NULL;
    if(head==NULL){
        head=temp;
    }
    else{
        while(ptr->next!=NULL){
            ptr=ptr->next;
        }
        ptr->next=temp;
    }
    printf("node added successfully");
    return head;
}
struct node *display(struct node *ptr){
    ptr=head;
    if(head==NULL){
        printf("linked list is empty\n");
        return head;
    }
    printf("LINKED LIST IS BELOW\n");
    while(ptr!=NULL){
        printf("%d ",ptr->info);
        ptr=ptr->next;
    }
    return head;
}
struct node *insertatbeg(struct node *ptr){
    ptr=head;
    int inf;
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    printf("enter the information to be stored");
    scanf("%d",&inf);
    temp->info=inf;
    if(head==NULL){
        head=temp;
    }
    else{
        head=temp;
        temp->next=ptr;
    }
    printf("Node added in begining");
    return head;
}

struct node *insertatend(struct node *ptr){
    
    ptr=head;
    int inf;
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    printf("enter the information to be stored");
    scanf("%d",&inf);
    temp->info=inf;
    temp->next=NULL;
    if(head==NULL){
        head=temp;
    }
    else{
        while(ptr->next!=NULL){
            ptr=ptr->next;
        }
        ptr->next=temp;
    }
    printf("node added in last\n");
    return head;
}

struct node *insertatpos(struct node *ptr){
    ptr=head;
    int pos;
    int inf;
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    printf("enter the information to be stored");
    scanf("%d",&inf);
    temp->info=inf;
    temp->next=NULL;
    printf("Enter the posiion in which to be insertatend\n");
    scanf("%d",&pos);
    int i=1;
    while(i<pos-1){
        ptr=ptr->next;
        i++;
    }
    temp->next=ptr->next;
    ptr->next=temp;
    printf("Element added at pos \n");
    return head;
}

struct node *deleteatbeg(struct node *ptr){
    ptr=head;
    head=ptr->next;
    free(ptr);
    printf("node deleted from front");
    return head;
}

struct node *deleteatend(struct node *ptr){
    ptr=head;
    struct node *preptr=head;
    ptr=ptr->next;
    while(ptr->next!=NULL){
        preptr=preptr->next;
        ptr=ptr->next;
    }
    preptr->next=NULL;
    free(ptr);
    printf("node deleted from end\n");
    return head;
}

struct node *deleteatpos(struct node *ptr){
    ptr=head;
    int pos;
    struct node *preptr=head;
    ptr=ptr->next;
    printf("enter the position to be delted");
    scanf("%d",&pos);
    int i=1;
    while(i<pos-1){
        ptr=ptr->next;
        preptr=preptr->next;
        i++;
    }
    preptr->next=ptr->next;
    free(ptr);
    printf("node deleted from position");
    return head;
}
    





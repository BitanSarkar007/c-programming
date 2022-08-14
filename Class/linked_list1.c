#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct htptr{
    struct node* head;
    struct node* tail;
};

struct htptr* create(struct htptr *ptrs){
    int value;
    struct node* new_node;
    while(1){
        if(ptrs->head == NULL){
            printf("enter the value for first node\n");
            scanf("%d",&value);
            new_node = (struct node*)malloc(sizeof(struct node));
            new_node->data = value;
            new_node->next = NULL;
            ptrs->head = ptrs->tail = new_node;
        }
        else{
            printf("enter value for next node\n");
            scanf("%d",&value);
            if(value  == -9999){
                break;
            }
            else{
                new_node = (struct node*)malloc(sizeof(struct node));
                new_node->data = value;
                new_node->next = NULL;
                ptrs->tail->next = new_node;
                ptrs->tail = new_node;
            }
        }
    }
    return ptrs;
}

struct htptr* insert_at_beg(struct htptr* ptrs,int new){
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->next = ptrs->head;
    new_node->data = new;
    ptrs->head = new_node;
    return ptrs;
}

struct htptr* insert_at_end(struct htptr* ptrs,int new){
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    ptrs->tail->next = new_node;
    new_node->next = NULL;
    new_node->data = new;
    ptrs->tail = new_node;
    return ptrs;
}

struct htptr* insert_before(struct htptr* ptrs,int nd, int new){
    struct node* p = ptrs->head;
    struct node* q = p->next;
    if(p->data == nd){
        insert_at_beg(ptrs,new);
    }
    else{
        while(q->data != nd && p->next != NULL){
        p = p->next;
        q = q->next;
    }
    if(q->next == NULL && q->data != nd){
        printf("element not found in the list\n");
    }
    else{
        struct node* new_node = (struct node*)malloc(sizeof(struct node));
        new_node->next = p->next;
        p->next = new_node;
        new_node->data = new;
    }
    }
    return ptrs;
}

struct htptr* insert_after(struct htptr* ptrs,int nd, int new){
    struct node* p = ptrs->head;
    struct node* q = p->next;
    while(p->data != nd && p->next != NULL){
        p = p->next;
        q = p->next;
    }
    if(p->next == NULL){
        printf("element not found in the list\n");
    }
    else{
        struct node* new_node = (struct node*)malloc(sizeof(struct node));
        new_node->next = p->next;
        p->next = new_node;
        new_node->data = new;
    }
    return ptrs;
}

struct htptr* delete_at_beg(struct htptr* ptrs){
    struct node* p = ptrs->head;
    struct node* q = p->next;
    ptrs->head = q;
    free(p);
    return ptrs;
}

struct htptr* delete_at_end(struct htptr* ptrs){
    struct node* p = ptrs->tail;
    struct node* q = ptrs->head;
    while(q->next != p){
        q = q->next;
    }
    q->next = NULL;
    ptrs->tail = q;
    free(p);
    return ptrs;
}

struct htptr* delete_before(struct htptr* ptrs,int nd){
    struct node* p = ptrs->head;
    struct node* d = p->next;
    struct node* q = p->next->next;
    while(q->data != nd && q->next != NULL){
        p = p->next;
        q = p->next;
    }
    if(q->next == NULL){
        printf("element to be deleted not found in the list\n");
    }
    else{
        p->next = q;
        free(d);
    }
    return ptrs;
}

struct htptr* delete_after(struct htptr* ptrs,int nd){
    struct node* p = ptrs->head;
    struct node* q = p->next;
    while(p->data != nd && p->next != NULL){
        p = p->next;
        q = p->next;
    }
    if(p->next == NULL){
        printf("element to be deleted not found in the list\n");
    }
    else{
        p->next = q->next;
        free(q);
    }
    return ptrs;
}

void print(struct htptr* ptrs){
    int count = 0;
    printf("elements of the linked list are:\n");
    struct node* n = ptrs->head;
    if(ptrs->head == NULL){
        printf("empty linked list\n");
    }
    else{
        while(n!=NULL){
            printf("%d->",n->data);
            n = n->next;
            count++;
        }
        printf("x\n");
        printf("number of nodes: %d\n",count);
    }
}

int search(struct htptr* ptrs, int key){
    struct node* p = ptrs->head;
    int count = 1;
    while(p->data != key && p->next != NULL){
        p = p->next;
        count++;
    }
    if(p->next == NULL && p->data != key){
        return -1; //sentinel
    }
    else{
        return count;
    }
}


struct htptr* reverse(struct htptr* ptrs){
    struct node* p,*c,*n;
    c = ptrs->head;
    p = NULL;
    while(c!=NULL){
        n = c->next;
        c->next = p;
        p = c;
        c = n;
    }
    ptrs->head = p;
    return ptrs;
}

int main(){
    int choice;
    struct htptr *ht = (struct htptr*)malloc(sizeof(struct htptr));
    ht->head = ht->tail = NULL;
    int entry,pos,key,ans;
    while(1){
        printf("\noptions:\n");
        printf("1. create a linked list\n");
        printf("2. insert at the beginning of list\n");
        printf("3. insert before a node\n");
        printf("4. insert after a node\n");
        printf("5. insert at end\n");
        printf("6. delete at the beginning of list\n");
        printf("7. delete before a node\n");
        printf("8. delete after a node\n");
        printf("9. delete at end\n");
        printf("10. search for an element\n");
        printf("11. reverse the linked list\n");
        printf("12. display\n");
        printf("0. exit\n");

        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            ht = create(ht);
            break;
        case 2:
            printf("enter the value:\n");
            scanf("%d",&entry);
            insert_at_beg(ht,entry);
            print(ht);
            break;
        case 3:
            printf("enter the value and node\n");
            scanf("%d %d",&entry,&pos);
            insert_before(ht,pos,entry);
            print(ht);
            break;
        case 4:
            printf("enter the value and node\n");
            scanf("%d %d",&entry,&pos);
            insert_after(ht,pos,entry);
            print(ht);
            break;
        case 5:
            printf("enter the value\n");
            scanf("%d",&entry);
            insert_at_end(ht,entry);
            print(ht);
            break;
        case 6:
            delete_at_beg(ht);
            print(ht);
            break;
        case 7:
            printf("enter the node\n");
            scanf("%d",&pos);
            delete_before(ht,pos);
            print(ht);
            break;
        case 8:
            printf("enter the node\n");
            scanf("%d",&pos);
            delete_after(ht,pos);
            print(ht);
            break;
        case 9:
            delete_at_end(ht);
            print(ht);
            break;
        case 10:
            printf("enter the element to be searched\n");
            scanf("%d",&key);
            int ans = search(ht,key);
            if(ans == -1){
                printf("element not found\n");
            }
            else{
                printf("the element is at node %d\n",ans);
            }
            break;
        case 11:
            reverse(ht);
            printf("linked list after reversal:\n");
            print(ht);
            break;
        case 12:
            print(ht);
            break;
        case 0:
            return 0;               
        default:
            printf("invalid choice\n");
        }
    }
    return 0;
}
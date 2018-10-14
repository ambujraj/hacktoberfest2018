#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct cell{
    int content;
    struct cell * next;

};
typedef struct cell cell;
cell *cell_create(int content){
    cell*a=(cell*)malloc(sizeof(cell));
    if(a==NULL){
        printf("heap alaninda yer ayrilamadi");

    }
    a->content=content;
    a->next=NULL;
    return a;

}
void list_end_add(int content,cell**list_head){
    cell*a=cell_create(content);
    if(*list_head==NULL){
        a->next=*list_head;
        *list_head=a;
    }
    else{
        cell*x=*list_head;
        while(x->next!=NULL){
            x=x->next;

        }
        x->next=a;
    }
}
void list_write(cell*list_head){
    if(list_head!=NULL){
        printf("%4d",list_head->content);
        list_write(list_head->next);

    }
    else
        printf("\n");
}



void erase (int index,cell**list){
    int i=1;
    cell*a;
    cell*b=*list;
    if(i==index){
        a=*list;
        *list=(*list)->next;
        free(a);



    }
    else{
        while(i!=index-1){
            b=b->next;
            i++;
        }
        a=b->next;
        b->next=a->next;
        free(a);
    }
    return *list;

}
int main()
{
    cell*list=NULL;


    list_end_add(1,&list);
    list_end_add(2,&list);
    list_end_add(3,&list);
    list_end_add(6,&list);
    list_write(list);
    erase(1,&list);
    list_write(list);



    return 0;
}

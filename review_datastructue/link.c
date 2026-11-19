#include <stdio.h>
#include<stdbool.h>
#include<stdlib.h>
typedef struct Node
{
    int data;
    struct Node*next;

}Node;
typedef struct{
    int length;
    Node* header;

}Linklist;
void ini_linklist(Linklist*list){
    list->length=0;
    list->header=NULL;
    

}
void destroy_list(Linklist*list){
    Node* current_node=list->header;
    while (current_node!=NULL)
    {
        Node* free_node=current_node;
       current_node=current_node->next;
       free(free_node);
    }
    list->header=NULL;
    list->length=0;
    
    

}
size_t get_len(Linklist*list)
{
    return list->length;
}
Node* finde_pre_node(Linklist*list,size_t index){

    Node* pre=list->header;
    for (size_t i = 1; i < index; i++)
    {
        pre=pre->next;
    }
    
    return pre;
    
    
}
void insert_at(Linklist*list,size_t index, int element){
    if (index>list->length)
    {
        return;
    }
    
    Node* node=(Node*)malloc(sizeof(Node));
    if (index==0)
    {
        node->next=list->header;
        list->header=node;
    }
    else{
        Node*pre=finde_pre_node(list,index);
       node->next= pre->next;
       pre->next=node;
    }
    node->data=element;
    list->length++;
    


}
void insert_end(Linklist*list,int element){
    insert_at(list,list->length,element);
}
bool del_element(Linklist*list,size_t index,int*del_element){
    if (index>=list->length)
    {
        return false;
    }
    Node*del_elements=NULL;
    if (index==0)
    {
        del_elements=list->header;
        list->header=list->header->next;
    }else{
        Node*pre=finde_pre_node(list,index);
        del_elements=pre->next;
        pre->next=pre->next->next;
    }
    *del_element=del_elements->data;
    free(del_elements);
    del_elements=NULL;

    


    list->length--;
    return true;
    
    

    

}
bool del_end(Linklist*l,int*element){
    return del_element(l,l->length-1,element);

}
void get_v(Linklist*l,size_t index,int *element){
    if (index>=l->length)
    {
        return;
    }
    if (index!=0)
    {
        Node*pre=finde_pre_node(l,index);
        *element=pre->next->data;
        return;

    }
    *element=l->header->data;



    
    
    

}
bool edit_data(Linklist*l,size_t index,int element){
    if (index>=l->length)
    {
        return false;
    }
    if (index!=0)
    {
        Node*pre=finde_pre_node(l,index);
        pre->next->data=element;
        return element;
    }
    l->header->data=element;
    return true;
    

}
void printf_list(Linklist*list){
    if (list->length == 0)
        return;
    Node*node=list->header;
    while (node!=NULL)
    {
        printf("%d->",node->data);
        node=node->next;
    }
    printf("\n");
    


}
int main(int argc, char const *argv[])
{
    Linklist list;
    ini_linklist(&list);
    insert_at(&list,0,1);
    insert_at(&list,0,2);
     insert_at(&list,0,3);
    printf_list(&list);

    return 0;
}

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node*next;
}Node;
typedef struct{
    size_t length;
    Node* header;

}Linklist;
void init_link(Linklist*list){
    list->length=0;
    list->header=NULL;


}
void destroy_list(Linklist*list){
    Node* current_node=list->header;
    while (current_node!=NULL)
    {
        Node*need_free=current_node;
        current_node=current_node->next;
        free(need_free);
    }
    list->header=NULL;
    list->length=0;
    // free(list->header);
    // list->header=NULL;
    // list->length=0;

}
size_t get_lenght(Linklist*list){
    return list->length;


}
void *find_pre_node(Linklist *list,size_t index){
    Node*pre=list->header;
    for (int i = 1; i < index; i++)
    {
        pre=pre->next;
        
    }
    return pre;
    
}

void insert_end(Linklist*list,int element){
    insert_at(list,list->length,element);

}
bool delete_at(Linklist*list,size_t index,int*element){
    if (index>=list->length)
    {
        return false;
    }
    Node *del_node=NULL;
    if (index==0)
    {
        del_node=list->header;
        list->header->next=list->header;
    }else{
       Node*pre= find_pre_node(list,index);
       del_node=pre->next;
       pre->next=pre->next->next;

    }
    *element=del_node->data;
    free(del_node);
    del_node=NULL;
    list->length--;
    return true;

    
    

}
bool delete_end(Linklist*list,int*element){
    return delete_at(list,list->length,element);

}
void get_value(Linklist*list,int index,int *element){
    if (index>=list->length)
    {
        return;
    }
    if (list!=0)
    {
        Node*pre=find_pre_node(list,index);
        *element =pre->next->data;
        return;

    }
    *element=list->header->data;
    
    

}
bool edit_value(Linklist*list,size_t index,int value){
    if (index>=list->length)
    {
        return false;
    }else{
        Node* pre=find_pre_node(list,index);
        pre->next->data=value;
        
    }

    list->header->data=value;
    return true;

}
void printf_list(Linklist*list){
    if (list->length==0)
    {
        return ;
    }
    Node* current_node=list->header;
    while (current_node!=NULL)
    {
        printf("%d",current_node->data);
        current_node=current_node->next;
    }
    printf("\n");
    
    

}
void insert_at(Linklist*list,size_t index,int element){
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
        Node*pre=find_pre_node(list,index);
       node->next= pre->next;
       pre->next=node;
    }
    node->data=element;
    list->length++;
    
}

int main(int argc, char const *argv[])
{
    Linklist list;
    init_link(&list);
    insert_at(&list,0,1);
    insert_at(&list,0,2);
    insert_at(&list,0,3);
    insert_at(&list,0,4);
    printf_list(&list);

    return 0;
}

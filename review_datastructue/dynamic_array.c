#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
typedef struct{
    int *arr;
    size_t capacity;
    size_t length;
}Dynamiv_array;
void ini_dynamic_array(Dynamiv_array*array,size_t new_capacity){
    array->arr=(int *)malloc(sizeof(int)*new_capacity);
    array->capacity=new_capacity;
    array->length=0;


}
void resize_dynamic_array(Dynamiv_array*array,size_t resize_capacity){
    array->arr=(int *)realloc(array->arr,sizeof(int)*resize_capacity);
    array->capacity=resize_capacity;
}
void destroy_array(Dynamiv_array*array){
    free(array->arr);
    array->arr=NULL;
    array->capacity=0;
    array->length=0;

}
int get_array(Dynamiv_array*array){
    return array->length;


}
void insert_array_at(Dynamiv_array*array,int element,size_t index){
    if (array->length==array->capacity)
    {
        resize_dynamic_array(array,array->capacity*2);
    }
    if (index>array->length)
    {
        return;
    }
    for (int i = array->length; i > index; i--)
    {
        array[i]=array[i-1];

    }
    array->arr[index]=element;
    array->length++;
}
void insert_end(Dynamiv_array*array,int element){
    insert_array_at(array,element,array->length);

}
bool delete_array_at(Dynamiv_array*array,size_t index,int *element){
    if (index>array->length)
    {
        return false;

    }
    *element=array->arr[index];
    for (int i = index; i < array->length-1; i++)
    {
       array[i]=array[i+1];
    //    return true;
    }
    array->length--;
    return true;
    
    


}
bool delete_at_end(Dynamiv_array*array,int *del_element){
    return delete_array_at(array,array->length-1,del_element);
}
void printf_array(Dynamiv_array*array){
    if (array->length==0)
    {
        return ;
    }
    for (int i = 0; i <array->length; i++)
    {
        printf("%d",array->arr[i]);
    }
    printf("\n");
    



}
int main(int argc, char const *argv[])
{
    Dynamiv_array array;
    ini_dynamic_array(&array,3);
    insert_array_at(&array,1,0);
    insert_array_at(&array,2,0);
    insert_array_at(&array,3,0);
    insert_array_at(&array,4,0);
    int element=0;

    delete_array_at(&array,0,&element);
    printf_array(&array);
    destroy_array(&array);


    
    return 0;
}

#include <stdio.h>
#include<stdbool.h>
#include <stdlib.h>
typedef struct{
    int *data;
    size_t capacity;
    size_t length;

}Array;
void init_array(Array*arr,size_t capacity){
    arr->data=(int*)malloc(sizeof(int)*capacity);
    arr->length=0;
    arr->capacity=capacity;


}
void resize_array(Array*Array,size_t new){
    Array->data=(int*)realloc(Array->data,sizeof(int)*new);
    Array->capacity=new;

}
void destroy(Array*array){
    free(array->data);
    array->data=NULL;
    array->length=0;
    array->capacity=0;

}
size_t get_length(Array*arr){
    return arr->length;

}
void insert_array(Array*arr,size_t index,int element){
    if (arr->capacity==arr->length)
    {
        resize_array(arr,arr->capacity*2);
    }
    for (int i = arr->length; i > index; i--)
    {
        arr->data[i]=arr->data[i-1];

    }
    arr->data[index]=element;
    arr->length++;

}
void insert_end(Array*arr,int element){
    insert_array(arr,arr->length-1,element);
}

bool del_array(Array*arr,size_t index,int *element)
{
    if (arr->length<=index)
    {
       return false;
    }
    *element=arr->data[index];
    for (int i = index; i < arr->length-1; i++)
    {
        arr->data[i]=arr->data[i+1];
    }
    arr->length--;
    return true;
    
}
bool delete_end(Array*arr,int *element){
    del_array(arr,arr->length-1,element);

}
void printf_array(Array*arr){
    if (arr->length==0)
    {
        return;
        
    }
    for (int i = 0; i < arr->length; i++)
    {
        printf("%d",arr->data[i]);
    }
    printf("\n");
    
    

}
int main(int argc, char const *argv[])
{
    Array a;
    init_array(&a,3);
    insert_array(&a,0,1);
    insert_array(&a,0,2);
    insert_array(&a,0,3);
    printf_array(&a);
    printf("%zu",get_length(&a));
    int del_number=0;
    del_array(&a,2,&del_number);
    printf_array(&a);
    printf("%zu",get_length(&a));
    destroy(&a);



    return 0;
}

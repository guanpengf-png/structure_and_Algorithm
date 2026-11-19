#include <stdio.h>
void swap(int*a,int*b){
    int tem=*a;
    *a=*b;
    *b=tem;

}
void bubble_sort(int *arr,int len){
    for (int i = 0; i < len-1; i++)
    {
        for (int j = 0; j<len-1-i; j++)
        {
            if (arr[j]>arr[j+1])
            {
                swap(&arr[j],&arr[j+1]);
            }
            
        }
        
    }
    

}
void printf_bubble_sort(int *arr,int len){
    for (int i = 0; i < len; i++)
    {
        printf("%d",arr[i]);

    }
    printf("\n");
    

}
int main(int argc, char const *argv[])
{
    int nums[]={30, 50, 200, 90, 10, 80, 60, 70};
    int len=sizeof(nums)/sizeof(nums[0]);
    bubble_sort(nums, len);
    printf_bubble_sort(nums,len);
    
    return 0;
}

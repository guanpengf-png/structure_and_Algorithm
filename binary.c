#include<stdio.h>
int binary(int *arr,int len,int target){
    int start =0, end=len-1, mid=0;
    while (start<=end)
    {
        mid=(start+(end-start)/2);
        if (target>arr[mid])
        {
            start=mid+1;
        }else if (target<arr[mid])
        {
            end=mid-1;
        }else{
            return mid;
        }
        return -1;
        

    }
    


}
int main(int argc, char const *argv[])
{
    int nums[]={312,32432,12321,43,5,343,3,24,234};
    int target=5;
    int len=sizeof(nums)/sizeof(nums[0]);
    int index=binary(nums,len,target);
    printf("%d",index);
    
    return 0;
}

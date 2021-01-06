#include<stdio.h>

int bsearch(int arr[],int find,int beg,int end){

    if(end >= beg){
        int mid = (beg + end)/2;

        if(arr[beg]>arr[end]){
            printf("Unsorted\n");
            return -1;
        }
        if(arr[mid] == find){
            printf("Found at positon %d",mid);
            return 0;
        }
        if(find > arr[mid]){
            return bsearch(arr,find,mid+1,end);}
        
            return bsearch(arr,find,beg,mid-1);

    }
    return -2;
  
}

int main(){
    int arr[5];
    int find;
    printf("To search for an element in an array of 5 elements,enter the elements in ascending order\n");

    for(int i=0;i<5;i++){
        printf("Enter the element at index %d:",i);
        scanf("%d",&arr[i]);
    }
    printf("\n");
    printf("Enter the element you want to look for");
    scanf("%d",&find);

    int pos = bsearch(arr,find,0,4);

    if(pos == -2){
        printf("Elemen not found");
    }
    return 0;

}
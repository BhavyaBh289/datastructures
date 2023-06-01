#include<stdio.h>
int arr[100];
int linearSearch(int arr[], int n, int d) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == d) {
            return i+1;
        }
    }
    return 0;
}
void insertionsort(int arr[],int n){
    int j,key;
    for(int i=1;i<n;i++){
        key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=key;
    }
}
int main(){
    int n,d;
    printf("enter the no. of elements\n");
    scanf("%d",&n);
    printf("enter the elements of array\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    insertionsort(arr,n);
    printf("\narray after sorted\n");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\nenter the element whose no. of occurences is required");
    scanf("%d",&d);

    int q=linearSearch(arr,n,d);
    if(q==0){
        printf("no element found\n");
    }
    else{
        printf("%d",q);
    }
}

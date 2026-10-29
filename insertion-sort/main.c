#include <stdio.h>
#include <stdlib.h>

void insertionsort(int arr[],int boyut){
int i,eklenen,yer;
for(i=1;i<boyut;i++){
    eklenen=arr[i];
    yer=i;
    while(yer>0&&arr[yer-1]>eklenen){
        arr[yer]=arr[yer-1];
        yer--;
    }
    arr[yer]=eklenen;
}
}

void selectionsort(int arr[],int boyut){
int i,j,enkucuk;
for(i=0;i<boyut-1;i++){
    enkucuk=i;
    for(j=i+1;j<boyut;j++){
        if(arr[j]<arr[enkucuk])
            enkucuk=j;
        swap(&arr[enkucuk],&arr[i])
    }
}

}

void swap(int *x,int *y){

int degis=*x;
*x=*y;
*y= degis;
}

void bublesort(int arr[],int kapasite){
int i,j;

for(i=0;i<kapasite-1;i++){
    for(j=0;j<kapasite-1-i;j++){
        if(arr[j]>arr[j+1]){
            swap(&arr[j],&arr[j+1]);
        }
    }
}
}

void print(int arr[],int kapasite){
for(int i=0;i<kapasite;i++){
    printf("%d -",arr[i]);
}
}

int main()
{
    int arr[]={5,4,3,2,1};
    int boyut=sizeof(arr)/sizeof(arr[1]);
    print(arr,boyut);
    printf("\n");
    bublesort(arr,boyut);
    print(arr,boyut);
    return 0;
}

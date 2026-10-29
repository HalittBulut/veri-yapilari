#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;

};

void sonaekle(struct node* *yeni_ref,int yeni_veri){
struct node *yenidugum=(struct node*)malloc(sizeof(struct node));
struct node *sonuncu=*yeni_ref;

if(!yenidugum){
    fprintf(stderr,"bellek ayrilamadi\n");
    exit(1);
}

yenidugum->data=yeni_veri;
yenidugum->next=NULL;

if(*yeni_ref==NULL){
    *yeni_ref=yenidugum;
    return;
}
while(sonuncu->next!=NULL)
    sonuncu=sonuncu->next;

    sonuncu->next=yenidugum;
}

void basaekle(struct node**birinci_ref,int yeni_veri){

struct node *yenidugum=(struct node*)malloc(sizeof(struct node));

yenidugum->data=yeni_veri;
yenidugum->next=(*birinci_ref);
(*birinci_ref)=yenidugum;

}
void arayaekle(struct node*oncekidugum,int yeni_veri){

if(oncekidugum==NULL){
    printf("onceki dugum NULL olmamali!!!\n");
    return;
}
struct node* newnode=(struct node*)malloc(sizeof(struct node));
newnode->data=yeni_veri;
newnode->next=oncekidugum->next;
oncekidugum->next=newnode;

}

void sil(struct node**ilkref,int silinecek){
struct node *gezer=*ilkref;
struct node *onceki=NULL;

if(gezer!=NULL && gezer->data==silinecek){
    *ilkref=gezer->next;
    free(gezer);
    return;
}
while(gezer!=NULL && gezer->data!=silinecek){
    onceki=gezer;
    gezer=gezer->next;
}
    if(gezer==NULL){
        printf("silinecek eleman (%d) listede bulunamadi.\n",silinecek);
        return;
    }
        onceki->next=gezer->next;
    free(gezer);
}

void printlist(struct node *n){
    while(n!=NULL){
        printf("%d - ",n->data);
        n=n->next;

    }
}


void linearsearch(int arr[],int max,int aranan){
int i=0;
for(i;i<max;i++){
    if(arr[i]==aranan){
        printf("aranan eleman dizinin %d. indexinde bulundu",i+1);
        return ;
    }

}
 printf("bulunamadi");
}

void binarysearch(int arr[],int max,int aranan){
int low=0,mid=0;
int high=max-1;

while(low<=high){
    mid=(high+low)/2;
    if(arr[mid]==aranan){
        printf("aranan eleman dizinin %d. indexinde  bulundu",mid+1);
        return ;
    }
    if(arr[mid]>aranan){
        high=mid-1;
    }else{
    low=mid+1;
    }
}
}

int main()
{
    struct node*yeni=NULL;

    sonaekle(&yeni,5);
    sonaekle(&yeni,7);
    sonaekle(&yeni,8);
    basaekle(&yeni,1);
    arayaekle(yeni,111);
    printlist(yeni);
    printf("\n\n");
    sil(&yeni,1);
    printlist(yeni);

    int dizi[5]={1,2,3,4,5};
    int max=sizeof(dizi)/sizeof(dizi[0]);
    int aranan=1;
    linearsearch(dizi,max,aranan);
    aranan=2;
    binarysearch(dizi,max,aranan);


    return 0;
}

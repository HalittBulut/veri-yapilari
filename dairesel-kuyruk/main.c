#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define kapasite 6

int array[kapasite];
int on=0;
int arka=0;
int elemansayisi=0;

bool bosmu(){
return elemansayisi==0;
}

bool dolumu(){
return elemansayisi==kapasite;
}

int ekle(int veri){
if(dolumu()){
printf("kuyruk dolu");
return 0;
       }
       array[arka]=veri;
       arka++;
       if(arka==kapasite)arka=0;
       elemansayisi++;
       return 1;
}
int cikar(){
if(bosmu()){return 0;}
int data=array[on];
on++;
if(on==kapasite){
    elemansayisi--;
    return data;
}
}


int main()
{
    printf("Hello world!\n");
    return 0;
}

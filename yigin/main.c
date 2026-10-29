#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


    struct Yigin{
    int SP;
    unsigned kapasite;
    int *dizi;
    };

    struct Yigin*yiginolustur(unsigned kapasite){
        struct Yigin *neww=(struct Yigin*)malloc(sizeof(struct Yigin));
        neww->kapasite=kapasite;
        neww->SP=-1;
        neww->dizi=(int*)malloc(neww->kapasite*sizeof(int));
        return neww;
    };

    int dolumu(struct Yigin*yigin){
    return yigin->SP==yigin->kapasite-1;
    };

    int bosmu(struct Yigin *yigin){
    return yigin->SP==-1;
    };

    void ekle(struct Yigin *yigin,int data){
    if(dolumu(yigin))return;
    yigin->dizi[++yigin->SP]=data;
    printf("%d yigina basariyla eklendi.\n",data);
    };

    int al(struct Yigin*yigin,int data){
    if(bosmu(yigin))return INT_MIN;
    yigin->dizi[yigin->SP--];
    printf("%d elemaný yigindan cikartildi.\n",data);
    };

    void print(struct Yigin*yigin){
    if(bosmu(yigin)){
        printf("\nYigin bos.\n");return;
    }
    printf("\nYigindaki Elemanlar (Tepeden Asagiya):\n");
    printf("------ TEPE ------\n");
    for(int i=yigin->SP;i>=0;i--){
        printf("|    %d    |\n", yigin->dizi[i]);
    }
    printf("------ TABAN -----\n");
    }

int main()
{
    struct Yigin *yigin = yiginolustur(100);

    ekle(yigin, 10);
    ekle(yigin, 20);
    ekle(yigin, 30);
    ekle(yigin, 40);
    ekle(yigin, 50);



    print(yigin);
    return 0;
}

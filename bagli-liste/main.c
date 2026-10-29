#include <stdio.h>
#include <stdlib.h> // malloc icin gerekli

// Vagonumuzun (Dugum) yapisi
// Her dugum bir veri ve bir sonraki dugumu gosteren bir kanca (pointer) tutar
struct Dugum {
    int veri;                // Vagondaki yuk (veri)
    struct Dugum* sonraki;   // Bir sonraki vagona olan kanca
};

// Global bir isaretci (pointer) - Trenimizin lokomotifi (basa)
// Basta hic vagon yokken NULL'u (boslugu) gosterir
struct Dugum* bas = NULL;

/*
 basaEkle Fonksiyonunun Adimlari:
 1. Yeni vagonu (yeniDugum) olustur ve hafizadan yer al.
 2. Yeni vagonun verisini ata.
 3. Yeni vagonun kancasini (sonraki), su anki ilk vagona (bas) bagla.
 4. Lokomotifi (bas) artik bu yeni vagonu gosterecek sekilde guncelle.
*/

void basaEkle(int eklenecekVeri) {
    // 1. Yeni vagonu olustur
    struct Dugum* yeniDugum = (struct Dugum*)malloc(sizeof(struct Dugum));

    // 2. Yeni vagonun verisini ata
    yeniDugum->veri = eklenecekVeri;

    // 3. Yeni vagonun kancasini (sonraki), su anki ilk vagona (bas) bagla.
    // Eger liste bossa (bas == NULL), yeniDugum->sonraki de NULL olur, ki bu dogrudur.
    yeniDugum->sonraki = bas;

    // 4. Lokomotifi (bas) artik bu yeni vagonu gosterecek sekilde guncelle.
    bas = yeniDugum;

    printf("-> Basa eklendi: %d\n", eklenecekVeri);
}

// Trenin tum vagonlarini (listedeki dugumleri) sirayla gezip verilerini yazdiran fonksiyon
void listeyiYazdir() {
    if (bas == NULL) {
        printf("Liste (tren) su an bos.\n");
        return;
    }

    struct Dugum* gecici = bas; // En bastaki lokomotiften basla
    printf("Listenin Guncel Durumu (Lokomotiften Sona):\n");

    // Kancasi bos (NULL) olan son vagona gelene kadar ilerle
    while (gecici != NULL) {
        printf("%d -> ", gecici->veri); // Vagonun verisini yazdir
        gecici = gecici->sonraki;     // Bir sonraki vagona gec
    }
    printf("NULL (Son Vagon)\n"); // En son kancanin bos oldugunu belirt
}

// Ana Program
int main() {

    printf("Program basladi, liste bos.\n");
    listeyiYazdir(); // Bos listeyi yazdir

    printf("-----------------------------\n");

    basaEkle(10); // Basa 10 ekle. Liste: 10 -> NULL
    listeyiYazdir();

    printf("-----------------------------\n");

    basaEkle(20); // Basa 20 ekle. Liste: 20 -> 10 -> NULL
    listeyiYazdir();

    printf("-----------------------------\n");

    basaEkle(30); // Basa 30 ekle. Liste: 30 -> 20 -> 10 -> NULL
    listeyiYazdir();

    printf("-----------------------------\n");

    return 0;
}

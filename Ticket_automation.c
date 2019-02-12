/*
        SELMAN BURAK KARAGÖL
        18010011062
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <string.h>

int filmBoyutu,filmSaati,c,Adet[][2],ay,gun,izlenecek;
int SinemaBiletUcreti=16;

char filmTuru[9][40]=
    {

        "Drama,Komedi","Drama,Suc","Dram,Gerilim",
        "Dram,Gizem","Bilim kurgu,Gerilim","Uyarlama Film,Drama",
        "Aksiyon,Dram","Fantastik,Aksiyon","Fantastik,Bilim kurgu"

    };
    char film[9][40]=
    {
        " Forrest Gump","The Godfather","The Dark Knight ",
        " Esaretin Bedeli","Inception","Schindlers List ",
        " Fight Club","Lord of Rings","The Matrix "
    };

    double imdbPuani[9]= {8.8,9.2,9.0,
                          9.2,8.7,8.9,
                          8.8,8.9,8.6
                         };


    double filmSuresi[9]= {2.22,2.55,2.32,
                           2.22,2.28,3.15,
                           2.19,3.21,2.16
                          };

//********************************************************************************************************************************
int sehirBulundugu,sehirGidilecek;
    char Sehirler[6][40] = {"Ankara","Konya","Istanbul","Izmir","Antalya"};

   int ay1,gun1;
   char Aylar[12][40]={"Ocak","Subat","Mart","Nisan","Mayis","Haziran","Temmuz","Agustos","Eylul","Ekim","Kasim","Aralik"};
   char Gunler[7][40]={"Pazartesi","Sali","Carsamba","Persembe","Cuma","Cumartesi","Pazar"};
 int y;
 int UcakKisiSayisi[][2];
int UcakBiletiFiyati=144;
//*********************************************************************************************************************************
    int sehirBulundugu1,sehirGidilecek1;
   int ay2,gun2;
   int a;
int yhtKisiSayisi[][2];
double yhtBiletFiyati=67.50;
//*********************************************************************************************************************************
char isim[50],soyisim[50];
  int KartNumarasi,KartTarihiGUN,KartTarihiAY;
  int KartSifresi;

//**********************************************************************************************************************************
//GLOBAL DEGISKENLER YUKARDADIR
//**********************************************************************************************************************************



void AnaMenu();
    void BiletMenu();
            void SinemaBileti();
                 void tarihSecme();
                 void kisiSayiveYas();
                 void Boyut();
                 void saat();
                 void Salon();
                 void SinemaBiletiFisi();
            void UlasimBileti();
                  void ucakbileti();
                       void ucakTarih();
                       void UcakKisiSayisiveYas();
                       void UcakKoltuklari();
                       void UcakBiletiFisi();
                  void  YuksekHizliTrenBileti();
                       void yhtTarih();
                       void yhtkisilerveYas();
                       void yhtKoltuklari();
                       void yhtBiletiFisi();
    void BiletIptalMenu();

 void KartBilgileri();

 void CikisMenu();
    void CIKIS();

int BasamakSayisi(int sayi);

//*****************************************************************************************************************************
//FONKSIYON PROTOTIPLERI YUKARDADIR
//*****************************************************************************************************************************

int main()
{
   printf("LUTFEN! PROGRAMI TAM EKRAN MODUNDA KULLANINIZ. IYI EGLENCELER...");
    delay(3000);
    GeriSayim();

    AnaMenu();
}





void CikisMenu()
{

 int secim;
  system("CLS");

 printf(" ---------------------------------\n");
 printf("|  1-Bilet Iptal                  |\n");
 printf("|  2-Fis Bastir(Program Sonlanir) |\n");
 printf("|  3-Ana Menu                     |\n");
 printf("|  4-CIKIS                        |\n");
 printf(" ---------------------------------\n");

   printf("\nYapacaginiz Islemi Seciniz: ");
   scanf("%d",&secim);

  switch(secim)
  {
  case 1:
    system("CLS");
    BiletIptalMenu();
   break;

  case 2:

    if(c!=0)
    {
        system("CLS");
        SinemaBiletiFisi();
    }

    if(a!=0)
    {
        system("CLS");
        yhtBiletiFisi();
    }

    if(y!=0)
    {

       system("CLS");
        UcakBiletiFisi();
    }
   break;

  case 3:
    system("CLS");
     AnaMenu();
    break;

  case 4:
    CIKIS();
   break;

   default:
    CikisMenu();
  }

}
void BiletIptalMenu()
{
  system("CLS");

   int p=0;
   int u=0;
    int yapilacak;
    int yapilacak2;

   if(a==0 && c==0 && y==0)
 {
     printf("Bilet Kaydi Bulunmamaktadir.\n");

    printf("\n1-Bilet Al");
    printf("\n2-CIKIS");

      printf("\n Yapmak Istediginiz Islem: ");
      scanf("%d",&yapilacak);

    if(yapilacak==1)
    {
        BiletMenu();
    }
    else if(yapilacak==2)
    {
        CIKIS();
    }
    else
    {
        printf("Bulunmayan Bir Islem Sectiniz...");
    BiletIptalMenu();
    }

 }

    if(c!=0)
    {
        for(p=0;p<c;p++)
        {
          for(u=0;u<2;u++)
          {
             Adet[p][u]=0;
          }
        }
      c=0;
    }

   if(a!=0)
   {
        for(p=0;p<a;p++)
        {
          for(u=0;u<2;u++)
          {
             yhtKisiSayisi[p][u]=0;
          }
        }
      a=0;
    }
   if(y!=0)
   {
        for(p=0;p<y;p++)
        {
          for(u=0;u<2;u++)
          {
             UcakKisiSayisi[p][u]=0;
          }
        }
      y=0;
    }
  system("CLS");
  printf("Bilet Kaydiniz Silinmistir.Yapmak Istediginiz Islemi Seciniz");

    printf("\n1-Bilet Al");
    printf("\n2-CIKIS");

      printf("\n Yapmak Istediginiz Islem: ");
      scanf("%d",&yapilacak2);

    if(yapilacak2==1)
    {
        BiletMenu();
    }
    else if(yapilacak2==2)
    {
        CIKIS();
    }
    else
    {
        printf("Bulunmayan Bir Islem Sectiniz...");
       delay(1500);
       system("CLS");
     BiletIptalMenu();
    }

}


void Uc();
void iki();
void bir();
void GeriSayim();

void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}

time_t simdikiZaman;




void AnaMenu()
{

    int secim;

    printf("*************************\n");
    printf(" ANA MENUYE HOS GELDINIZ \n");
    printf("*************************\n");
    printf("*                       *\n");
    printf("*   1- BILET ALMA       *\n");
    printf("*   2- BILET IPTALI     *\n");
    printf("*   3- CIKIS            *\n");
    printf("*                       *\n");
    printf("*************************\n");

    printf("\nYAPACAGINIZ ISLEMI SECINIZ: ");
    scanf("%d",&secim);

    switch(secim)
    {
    case 1:
        BiletMenu();
        break;

    case 2:
        BiletIptalMenu();
        break;

    case 3:
        CIKIS();

    default:
        printf("UZGUNUZ!! Sectiginiz Islem Bulunmamaktadir.Ana Menuye Yonlendiriliyorsunuz...");
        delay(1500);
        system("CLS");
        AnaMenu();

    }

}
void BiletMenu()
{

    system("CLS");

   int secim;

   printf("***************************\n");
   printf(" BILET MENUYE HOSGELDINIZ  \n");
   printf("***************************\n");
   printf("*                         *\n");
   printf("*   1- SINEMA BILETI      *\n");
   printf("*   2- ULASIM BILETI      *\n");
   printf("*   3- BILET KAYDI SILME  *\n");
   printf("*   4- GERI(ANA MENU)     *\n");
   printf("*   5- CIKIS              *\n");
   printf("*                         *\n");
   printf("***************************\n");

    printf("YAPMAK ISTEDIGINIZ ISLEMI SECINIZ: ");
    scanf("%d",&secim);

    switch(secim)
    {
    case 1:
        system("CLS");
        SinemaBileti();
        break;

    case 2:
        system("CLS");
        UlasimBileti();
        break;

    case 3:
        system("CLS");
        BiletIptalMenu();
        break;

    case 4:
        system("CLS");
        AnaMenu();

    case 5:
        CIKIS();

    default:
        printf("UZGUNUZ!! Yapmak Istediginiz Islem Bulunmamamistir.Bilet Menusune Donduruluyorsunuz...");
        delay(1500);
        BiletMenu();

    }

}

//*******************************************************************************************************************************

void SinemaBileti()
{
    int i;



    for(i=0; i<9; i++)
    {
        printf("%d)",i+1);
        printf("\nFilm Adi : %s \n",film[i]);
        printf("Filmin Turu :  %s \n",filmTuru[i]);
        printf("IMDB Puani : %.1lf \n",imdbPuani[i]);
        printf("Film Suresi : %.1lf Saat \n",filmSuresi[i]);
        printf("\n");

    }
    printf(" -------------------------------\n");
    printf("| 10-) Bilet Menu(Geri)         |\n");
    printf("| 11-) Ana Menu                 |\n");
    printf("| 0-)  CIKIS                    |\n");
    printf(" -------------------------------\n");

   printf("\n\nBilet Ucreti 16 TL dir");
   printf("\n3D Secenegi Icin +3 TL Gozluk Parasi Alinacaktir");

    printf("\n IZLEMEK ISTEDIGINIZ FILM NUMARASI : ");
    scanf("%d",&izlenecek);
    system("CLS");
    if(0>izlenecek || izlenecek>11)
        SinemaBileti();
    if(izlenecek==10)
        BiletMenu();
    if(izlenecek==11)
        AnaMenu();
    if(izlenecek==0)
        CIKIS();

    printf("%d)---------------------------------",izlenecek);
    printf("\nFilm Adi : %s                     \n",film[izlenecek-1]);
    printf("Filmin Turu :  %s                   \n",filmTuru[izlenecek-1]);
    printf("IMDB Puani : %.1lf                  \n",imdbPuani[izlenecek-1]);
    printf("Film Suresi : %.1lf Saat            \n",filmSuresi[izlenecek-1]);
    printf("-----------------------------------");
    printf("\n");

    tarihSecme();
}

void tarihSecme()
{

    int i;

    time(&simdikiZaman);
   printf("\n\t\t\t\t---------Tarih----------\n\t\t\t\t%s",ctime(&simdikiZaman));

   for(i=0;i<12;i++)
   {
       printf("%d-) %s \n",i+1,Aylar[i]);
   }
    printf(" ----------------------------------\n");
    printf("| 13-) GERI (Sinema Bileti Menusu) |\n");
    printf("| 14-) Bilet Menu                  |\n");
    printf("| 15-) Ana Menu                    |\n");
    printf("| 0-)  CIKIS                       |\n");
    printf(" ----------------------------------\n");



    printf("\nTarih Giriniz(2019 Yili Icerisinde)\n");
    printf("\nAY(1-12): ");
    scanf("%d",&ay);

    if(0>ay || ay>15)
    {
        printf("Gecersiz Tarih\n");
        system("CLS");
        tarihSecme();
    }
    else
    {
          printf("\t\t*---------------------------*\n");
          printf("\t\t  Sectiginiz AY %d-) %s      \n",ay,Aylar[ay-1]);
          printf("\t\t*---------------------------*\n\n");
    }

    if(ay==0)
     {
      CIKIS();
     }
    if(ay==15)
      {
       system("CLS");
       AnaMenu();
      }

    if(ay==14)
    {
       system("CLS");
       BiletMenu();
    }

    if(ay==13)
    {
        system("CLS");
        SinemaBileti();
    }



    int GunBaslangic=ay*30;
    int GunBitis=GunBaslangic+30;
    int GunYazilacak;
    int g=0;

  //*************************************************
  //  printf("\t\t%s\n",Aylar[ay]);
    for(i=GunBaslangic;i<GunBitis;i++)
    {
      GunYazilacak=(i%7);
        printf("%d-) %s\t",g+1,Gunler[GunYazilacak]);
      g++;
      if(g%7==0)
      {
        printf("\n");
      }

    }
//*******************************************************
  printf("\n\nGun giriniz(1-30): ");
    scanf("%d",&gun);
  if(0>gun || gun>30)
    {
        printf("Gecersiz Tarih. Tarih Secme Isleminin Basina Donduruluyorsunuz...\n");
        delay(2000);
       system("CLS");
        tarihSecme();
    }
    int GunYazilacak_2=(GunBaslangic+gun)%7;

     if(GunYazilacak_2==0)
     {
         GunYazilacak_2 = 7;
     }

          printf("\t\t*---------------------------*\n");
          printf("\t\t Sectiginiz GUN  %d-) %s     \n",gun,Gunler[GunYazilacak_2-1]);
          printf("\t\t*---------------------------*\n\n");


    kisiSayiveYas();

}
//*******************************************************************************************
//KISI SAYISI ISTEME
void kisiSayiveYas()
{

    int izleyiciYasi=0;
    int i;

    printf(" -----------------------------------\n");
    printf("| 81-) GERI (Tarih Secim)           |\n");
    printf("| 82-) Sinema Bileti Menusu         |\n");
    printf("| 83-) Bilet Menu                   |\n");
    printf("| 84-) Ana Menu                     |\n");
    printf("| 0-)  CIKIS                        |\n");
    printf(" -----------------------------------\n");



    printf("\nKac Tane bilet alacaginizi giriniz(Min :1 - Max :80): ");
    scanf("%d",&c);

    if(0>c || c>84)
    {
        printf("Cok Kucuk Veya Cok Buyuk Bir Sayi Girdiniz!!");
        delay(1500);
        system("CLS");
        kisiSayiveYas();
    }


    if(c==0)
      CIKIS();
    if(c==84)
      {
       system("CLS");
       AnaMenu();
      }

    if(c==83)
    {
       system("CLS");
       BiletMenu();
    }

    if(c==82)
    {
        system("CLS");
        SinemaBileti();
    }
    if(c==81)
      {
        system("CLS");
        tarihSecme();
      }

   Adet[c][2];

    for(i=0; i<c; i++)
    {
        printf("\n%d. Kisinin Yasi : ",i+1);
        scanf("%d",&izleyiciYasi);

        if(izleyiciYasi<4)
        {
            printf("UZGUNUZ! 3 YASINDAN KUCUKLER SINEMA BILETI ALAMAMAKTADIR");
          delay(2000);
          system("CLS");
         kisiSayiveYas();
        }

        if((izleyiciYasi<15) & (izlenecek==2 || izlenecek==3 || izlenecek==5))
        {
            printf("UZGUNUZ! BU FILMI 15 YASINDAN KUCUKLER IZLEYEMEMEKTEDIR.");

        }
        else
        {
            Adet[i][1]=izleyiciYasi;
        }
    }

    Boyut();
}



void Boyut()
{

   system("CLS");

    printf("\n");
    printf(" 2D        3D\n");
    printf("-----  -  ------\n");
    printf("12.00  -  12.30\n");
    printf("15.00  -  15.30\n");
    printf("18.00  -  18.30\n");
    printf("21.00  -  21.30\n");

    printf("\n-----------------------------\n");
    printf("| 4-)  GERI(Bilet Miktari)     |\n");
    printf("| 5-)  Sinema Bileti Menusu    |\n");
    printf("| 6-)  Ana Menu                |\n");
    printf("| 0-)  CIKIS                   |\n");
    printf(" ------------------------------\n");


    printf("\nFilmi Izlemek Istediginiz Boyutu Girniz (2 Veya 3 Girlmelisiniz!): ");
    scanf("%d",&filmBoyutu);
 if(filmBoyutu<0 || filmBoyutu>6 || filmBoyutu==1)
    {
    Boyut();
    }

  if(filmBoyutu==4)
  {
     system("CLS");
      kisiSayiveYas();
  }
  if(filmBoyutu==5)
  {
     system("CLS");
      SinemaBileti();
  }
  if(filmBoyutu==6)
  {
     system("CLS");
      AnaMenu();
  }
  if(filmBoyutu==0)
  {
      CIKIS();
  }


saat();
}

void saat()
{

    if(filmBoyutu==2)
    {

        printf("\n1) 12.00\n");
        printf("2) 15.00\n");
        printf("3) 18.00\n");
        printf("4) 21.00\n");

    printf("\n-----------------------------\n");
    printf("| 5-)  GERI (Film Boyutu)      |\n");
    printf("| 6-)  Sinema Bileti Menusu    |\n");
    printf("| 7-)  Ana Menu                |\n");
    printf("| 0-)  CIKIS                   |\n");
    printf(" ------------------------------\n");

        printf("\nFilm Saati Seciniz:");
        scanf("%d",&filmSaati);
    }
    else if(filmBoyutu==3)
    {
        printf("1) 12.30\n");
        printf("2) 15.30\n");
        printf("3) 18.30\n");
        printf("4) 21.30\n");

    printf("\n-----------------------------\n");
    printf("| 5-)  GERI (Film Boyutu)      |\n");
    printf("| 6-)  Sinema Bileti Menusu    |\n");
    printf("| 7-)  Ana Menu                |\n");
    printf("| 0-)  CIKIS                   |\n");
    printf(" ------------------------------\n");

        printf("\nFilm Saati Seciniz:\n");
        scanf("%d",&filmSaati);
    }

  if(filmSaati<0 || filmSaati>7)
  {
      saat(filmBoyutu,c);
  }


  if(filmSaati==5)
  {
      system("CLS");
      Boyut();
  }
  if(filmSaati==6)
  {
      system("CLS");
      SinemaBileti();
  }
  if(filmSaati==7)
  {
      system("CLS");
      AnaMenu();
  }
  if(filmSaati==0)
  {
      CIKIS();
  }


 Salon();
}

//*****************************************************************************************************
void Salon()
{
    system("CLS");
    int koltuklar[8][10];
    int j,k,p;
    int u=0;

     for(j=0; j<8; j++)
      {
        for(k=0; k<10; k++)
        {

             koltuklar[j][k]=u+1;
           u++;
        }
    }

char merdiven[9]={"MERDIVEN"};

for(p=0;p<c;p++)
  {
//************************************************DIZIYI YAZDIRMA
    for(j=0; j<8; j++)
    {
        for(k=0; k<10; k++)
        {
            if(k==0)
            {
                printf("  %c\t",merdiven[j]);
            }

                printf("[%d]\t",koltuklar[j][k]);

        }
        printf("\n");
    }
   //****************************************************************
     printf("\n\n\t\t   -  -  -  -  -  P  E  R  D  E  -  -  -  -  -\n");

     int secilenKoltuk;


        printf("Koltuk Seciniz: ");
        scanf("%d",&secilenKoltuk);
  if(secilenKoltuk<1 || secilenKoltuk>80)
  {
      printf("UZGUNUZ!! Sectiginiz Koltuk Bulunmamaktadir");
      delay(1200);
      system("CLS");
      Salon();
  }
        Adet[p][1]= secilenKoltuk;
        system("CLS");

        for(j=0; j<8; j++)
        {
            for(k=0; k<10; k++)
            {

            if(p>0)
                 {
                   if(Adet[p][1]==Adet[p-1][1])
                    {
                      printf("UZGUNUZ!! Dolu Olan Bir Koltuk Sectiniz Tekrar Secmek Icin Yonlendiriliyorsunuz...\n");
                     delay(1500);

                     system("CLS");

                      Salon();
                    }
                 }

            if(Adet[p][1]==koltuklar[j][k])
                    {
                        koltuklar[j][k] =0;
                    }

            }
            printf("\n");

        }

    }


 KartBilgileri();
}


void SinemaBiletiFisi()
{
 //FILM BILGILERI

 int i;
  printf("-------SINEMA BILETI FISINIZ-------\n\n");

  printf("%d)---------------------------------",izlenecek);
    printf("\nFilm Adi : %s                     \n",film[izlenecek-1]);
    printf("Filmin Turu :  %s                   \n",filmTuru[izlenecek-1]);
    printf("IMDB Puani : %.1lf                  \n",imdbPuani[izlenecek-1]);
    printf("Film Suresi : %.1lf Saat            \n",filmSuresi[izlenecek-1]);
    printf("-----------------------------------");

   printf("\n\nFilm Boyutu: %d D",filmBoyutu);
   printf("\nTarih: %d.%d.2019\n",ay,gun);

    for(i=0;i<c;i++)
    {
        printf("%d. Kisinin Koltuk Numarasi %d\n",i+1,Adet[i][1]);
    }

   printf("\nToplam Ucret : %d(+gozluk) x %d = %d",SinemaBiletUcreti,c,(c*SinemaBiletUcreti+c*3));

 printf("\nKart Bilgileri");
 printf("\n---------------------------");
  printf("\nISIM: %s",isim);
  printf("\nSOYISIM: %s",soyisim);

  printf("\n\nKart Numarasi: %d",KartNumarasi);
  printf("\nGun/Ay: %d/%d",KartTarihiGUN,KartTarihiAY);

  printf("\nKart Sifresi: **%d",(KartSifresi%10));
  printf("\n-------------------------------------------------------------------\n");

delay(10000);
exit(0);

}




void UlasimBileti()
{
    int tasitSecim;
    printf("**********************************\n");
    printf("     ULASIM BILETI MENUSU         \n");
    printf("**********************************\n");
    printf("*  1- Ucak Bileti                *\n");
    printf("*  2- Yuksek Hizli Tren bileti   *\n");
    printf("*  3- GERI(Bilet Menu)           *\n");
    printf("*  4- Ana Menu                   *\n");
    printf("*  5- CIKIS                      *\n");
    printf("**********************************\n");

    printf("Yapmak Istediginiz Islemi Seciniz: ");
    scanf("%d",&tasitSecim);
    switch(tasitSecim)
    {
    case 1:
        ucakbileti();
        break;
    case 2:
        system("CLS");
        YuksekHizliTrenBileti();
        break;
    case 3:
        system("CLS");
        BiletMenu();
        break;
    case 4:
        system("CLS");
        AnaMenu();
        break;
    case 5:
        CIKIS();
        break;
    default:
        system("CLS");
        UlasimBileti();
    }
}

void ucakbileti()
{
    system("CLS");
    int i,imax;

    imax=strlen(Sehirler)-1;

    printf("-----Sehirler----\n");
    printf("---------------------\n");

    for(i=0; i<imax; i++)
    {
        printf("    %d- %s \n",i+1,Sehirler[i]);
    }
    printf("---------------------");
        printf("\n\nYuksek Ucak Bileti Fiyatlari Sabit ve %d TL dir.",UcakBiletiFiyati);

    printf("\nKalkis Sehri Seciniz(1-5): ");
    scanf("%d",&sehirBulundugu);
    printf("-- %s --",Sehirler[sehirBulundugu-1]);


    printf("\nGitmek Istediginiz Sehir(1-5):");
    scanf("%d",&sehirGidilecek);
    if(sehirBulundugu==sehirGidilecek)
    {
        printf("Ayni Sehire Sefer Bulunmamaktadir.Lutfen Tekrar Seciniz...");
        delay(1500);
    ucakbileti();
    }

    printf("-- %s --",Sehirler[sehirGidilecek-1]);
    ucakTarih();
}

void ucakTarih()
{
  int i;

   time(&simdikiZaman);
   printf("\n\t\t\t\t---------Tarih----------\n\t\t\t\t%s",ctime(&simdikiZaman));

   for(i=0;i<12;i++)
   {
       printf("\n%d-) %s ",i+1,Aylar[i]);
   }
   printf("\n");
    printf(" ----------------------------------\n");
    printf("| 13-) GERI (Sehir Secimi)         |\n");
    printf("| 14-) Bilet Menu                  |\n");
    printf("| 15-) Ana Menu                    |\n");
    printf("| 0-)  CIKIS                       |\n");
    printf(" ----------------------------------\n");



    printf("\nTarih Giriniz(2019 Yili Icerisinde)\n");
    printf("\nAY(1-12): ");
    scanf("%d",&ay1);

    if(0>ay1 || ay1>15)
    {
        printf("Gecersiz Tarih\n");
        system("CLS");
        ucakTarih();
    }
    else
    {
          printf("\t\t*---------------------------*\n");
          printf("\t\t  Sectiginiz AY %d-) %s      \n",ay1,Aylar[ay1-1]);
          printf("\t\t*---------------------------*\n\n");
    }

    if(ay1==0)
     {
      CIKIS();
     }
    if(ay1==15)
      {
       system("CLS");
       AnaMenu();
      }

    if(ay1==14)
    {
       system("CLS");
       BiletMenu();
    }

    if(ay1==13)
    {
        system("CLS");
        ucakbileti();
    }



    int GunBaslangic=(ay1-1)*30;

     int GunBitis=GunBaslangic+30;
    int GunYazilacak;
    int g=0;

  //**************************************************
    for(i=GunBaslangic;i<GunBitis;i++)
    {
      GunYazilacak=(i%7);
        printf("%d-) %s\t",g+1,Gunler[GunYazilacak]);
      g++;
      if(g%7==0)
      {
        printf("\n");
      }

    }
//*******************************************************
  printf("\n\nGun giriniz(1-30): ");
    scanf("%d",&gun1);
  if(0>gun1 || gun1>30)
    {
        printf("Gecersiz Tarih. Tarih Secme Isleminin Basina Donduruluyorsunuz...\n");
        delay(2000);
       system("CLS");
        ucakTarih();
    }

  int GunYazilacak_2=(GunBaslangic+gun1)%7;

     if(GunYazilacak_2==0)
     {
         GunYazilacak_2 = 7;
     }

          printf("\t\t*---------------------------*\n");
          printf("\t\t Sectiginiz GUN  %d-) %s     \n",gun1,Gunler[GunYazilacak_2-1]);
          printf("\t\t*---------------------------*\n\n");

UcakKisiSayisiveYas();
}


void UcakKisiSayisiveYas()
{
    int i;

    printf("Kac Tane bilet alacaginizi giriniz: ");
    scanf("%d",&y);
    int UcakKisiSayisi[y][2];

    for(i=0; i<y; i++)
    {
        printf("\n%d. Kisinin Yasi : ",i+1);
        scanf("%d",&UcakKisiSayisi[y][0]);
    }

    UcakKoltuklari();
}
//*******************************************************************

void UcakKoltuklari()
{
    int UcakKoltuklarDizisi[21][5];
    int j,k,p;
    int t=0;

     for(j=0; j<21; j++)
      {
        for(k=0; k<5; k++)
        {
       if(k!=2)
       {
          UcakKoltuklarDizisi[j][k]=t+1;
        t++;
       }
       else
          {
             UcakKoltuklarDizisi[j][k]= 32;
          }
        }
    }

for(p=0; p<y; p++)
  {

    //************************************************DIZIYI YAZDIRMA
    for(j=0; j<21; j++)
    {
        for(k=0; k<5; k++)
        {
            if(k!=2)
            {
                printf("[%d]",UcakKoltuklarDizisi[j][k]);
            }
            else
            {
                printf("%c",UcakKoltuklarDizisi[j][k]);
            }
        }
      printf("\n");
    }
   //****************************************************************
     int UcakSecilenKoltuk;


        printf("Koltuk Seciniz: ");
        scanf("%d",&UcakSecilenKoltuk);
      if(UcakSecilenKoltuk<1 || UcakSecilenKoltuk>84)
      {
       printf("UZGUNUZ!! Sectiginiz Koltuk Bulunmamaktadir");
             delay(1200);
             system("CLS");
             UcakKoltuklari();
      }

        UcakKisiSayisi[p][1]= UcakSecilenKoltuk;
        system("CLS");

        for(j=0; j<21; j++)
        {
            for(k=0; k<5; k++)
            {

            if(p>0)
                 {
                   if(UcakKisiSayisi[p][1]==UcakKisiSayisi[p-1][1])
                    {
                      printf("UZGUNUZ!! Dolu Olan Bir Koltuk Sectiniz. Tekrar Secmek Icin Yonlendiriliyorsunuz...\n");
                     delay(1500);

                     system("CLS");

                     UcakKoltuklari();
                    }
                 }

            if(UcakKisiSayisi[p][1]==UcakKoltuklarDizisi[j][k])
                    {
                        UcakKoltuklarDizisi[j][k] =0;
                    }

            }
            printf("\n");

        }

    }

  KartBilgileri();
}

 void UcakBiletiFisi()
 {

   int i;
   printf("-------UCAK BILETI FISINIZ-------\n");
     printf("Kalkis Sehri: %s",Sehirler[sehirBulundugu]);
     printf("\nVaris Sehri: %s",Sehirler[sehirGidilecek]);


     printf("\nTarih: %d.%d.2019\n",ay1,gun1);

    for(i=0;i<y;i++)
    {
        printf("%d. Kisinin Koltuk Numarasi %d\n",i+1,UcakKisiSayisi[i][1]);
    }
printf("Toplam Ucret: %d x %d = %d\n",UcakBiletiFiyati,y,(y*UcakBiletiFiyati));

printf("-------------------------------------");

 printf("\nKart Bilgileri");
 printf("\n---------------------------");
  printf("\nISIM: %s",isim);
  printf("\nSOYISIM: %s",soyisim);

  printf("\n\nKart Numarasi: %d",KartNumarasi);
  printf("\nGun/Ay: %d/%d",KartTarihiGUN,KartTarihiAY);

  printf("\nKart Sifresi: **%d",(KartSifresi%10));
  printf("\n-------------------------------------------------------------------\n");

delay(10000);
exit(0);

 }






void YuksekHizliTrenBileti()
{
    system("CLS");
    int i,imax;


    imax=strlen(Sehirler)-1;

    printf("-----Sehirler----\n");
    printf("---------------------\n");

    for(i=0; i<imax; i++)
    {
        printf("    %d- %s \n",i+1,Sehirler[i]);
    }
    printf("---------------------");

     printf("\n\nHizli Tren Bilet Fiyatlari Sabit ve %.2lf TL dir.",yhtBiletFiyati);

    printf("\nKalkis Sehri Seciniz(1-5): ");
    scanf("%d",&sehirBulundugu);
    printf("-- %s --",Sehirler[sehirBulundugu-1]);


    printf("\nGitmek Istediginiz Sehir(1-5):");
    scanf("%d",&sehirGidilecek);

    if(sehirBulundugu==sehirGidilecek1)
    {
        printf("Ayni Sehire Sefer Bulunmamaktadir");
     delay(1500);
     YuksekHizliTrenBileti();
    }

    printf("-- %s --",Sehirler[sehirGidilecek-1]);
    yhtTarih();
}

void yhtTarih()
{
  int i;

   time(&simdikiZaman);
   printf("\n\t\t\t\t---------Tarih----------\n\t\t\t\t%s",ctime(&simdikiZaman));

   for(i=0;i<12;i++)
   {
       printf("\n%d-) %s ",i+1,Aylar[i]);
   }
   printf("\n");
    printf(" ----------------------------------\n");
    printf("| 13-) GERI (Sehir Secimi)         |\n");
    printf("| 14-) Bilet Menu                  |\n");
    printf("| 15-) Ana Menu                    |\n");
    printf("| 0-)  CIKIS                       |\n");
    printf(" ----------------------------------\n");



    printf("\nTarih Giriniz(2019 Yili Icerisinde)\n");
    printf("\nAY(1-12): ");
    scanf("%d",&ay2);

    if(0>ay2 || ay2>15)
    {
        printf("Gecersiz Tarih\n");
        system("CLS");
        yhtTarih();
    }
    else
    {
          printf("\t\t*---------------------------*\n");
          printf("\t\t  Sectiginiz AY %d-) %s      \n",ay2,Aylar[ay2-1]);
          printf("\t\t*---------------------------*\n\n");
    }

    if(ay2==0)
     {
      CIKIS();
     }
    if(ay2==15)
      {
       system("CLS");
       AnaMenu();
      }

    if(ay2==14)
    {
       system("CLS");
       BiletMenu();
    }

    if(ay2==13)
    {
        system("CLS");
        YuksekHizliTrenBileti();
    }



    int GunBaslangic=ay2*30;
    int GunBitis=GunBaslangic+30;
    int GunYazilacak;
    int g=0;

  //*************************************************

    for(i=GunBaslangic;i<GunBitis;i++)
    {
      GunYazilacak=(i%7);
        printf("%d-) %s\t",g+1,Gunler[GunYazilacak]);
      g++;
      if(g%7==0)
      {
        printf("\n");
      }

    }
//*******************************************************
  printf("\n\nGun giriniz(1-30): ");
    scanf("%d",&gun2);
  if(0>gun2 || gun2>30)
    {
        printf("Gecersiz Tarih. Tarih Secme Isleminin Basina Donduruluyorsunuz...\n");
        delay(2000);
       system("CLS");
        yhtTarih();
    }

    int GunYazilacak_2=(GunBaslangic+gun2)%7;

     if(GunYazilacak_2==0)
     {
         GunYazilacak_2 = 7;
     }

          printf("\t\t*---------------------------*\n");
          printf("\t\t Sectiginiz GUN  %d-) %s     \n",gun2,Gunler[GunYazilacak_2-1]);
          printf("\t\t*---------------------------*\n\n");


    yhtKisiSayisiveYas();
}

void yhtKisiSayisiveYas()
{
    int i;

    printf("Kac Tane bilet alacaginizi giriniz: ");
    scanf("%d",&a);
    int yhtKisiSayisi[a][2];

    for(i=0; i<a; i++)
    {
        printf("\n%d. Kisinin Yasi : ",i+1);
        scanf("%d",&yhtKisiSayisi[a][0]);
    }


 yhtKoltuklari();
}
//*******************************************************************

void yhtKoltuklari()
{
   int yhtKoltuklarDizisi[21][5];
    int j,k,p;
    int t=0;

     for(j=0; j<21; j++)
      {
        for(k=0; k<5; k++)
        {
          if(k!=2)
          {
            yhtKoltuklarDizisi[j][k]=t+1;
           t++;
          }
        else
          {
             yhtKoltuklarDizisi[j][k]= 32;
          }

        }
    }

for(p=0; p<a; p++)
  {

    //************************************************DIZIYI YAZDIRMA
    for(j=0; j<21; j++)
    {
        for(k=0; k<5; k++)
        {
            if(k!=2)
            {
                printf("[%d]",yhtKoltuklarDizisi[j][k]);
            }
            else
            {
                printf("%c",yhtKoltuklarDizisi[j][k]);
            }

        }
        printf("\n");
    }
   //****************************************************************
     int yhtSecilenKoltuk;


        printf("Koltuk Seciniz: ");
        scanf("%d",&yhtSecilenKoltuk);
          if(yhtSecilenKoltuk<1 || yhtSecilenKoltuk>84)
          {
              printf("UZGUNUZ!! Sectiginiz Koltuk Bulunmamaktadir");
             delay(1200);
             system("CLS");
            yhtKoltuklari();
          }

        yhtKisiSayisi[p][1]= yhtSecilenKoltuk;
        system("CLS");

        for(j=0; j<21; j++)
        {
            for(k=0; k<5; k++)
            {

            if(p>0)
                 {
                   if(yhtKisiSayisi[p][1]==yhtKisiSayisi[p-1][1])
                    {
                      printf("UZGUNUZ!! Dolu Olan Bir Koltuk Sectiniz Tekrar Secmek Icin Yonlendiriliyorsunuz...\n");
                     delay(1500);

                     system("CLS");

                     yhtKoltuklari();
                    }
                 }

            if(yhtKisiSayisi[p][1]==yhtKoltuklarDizisi[j][k])
                    {
                        yhtKoltuklarDizisi[j][k] =0;
                    }

            }
            printf("\n");

        }

    }
 KartBilgileri();
 }

 void yhtBiletiFisi()
 {
  int i;
   printf("-------YUKSEK HIZLI TREN BILETI FISINIZ-------\n");
   printf("Kalkis Sehri: %s",Sehirler[sehirBulundugu1]);
     printf("\nVaris Sehri: %s",Sehirler[sehirGidilecek1]);


     printf("\nTarih: %d.%d.2019\n",ay2,gun2);

    for(i=0;i<a;i++)
    {
        printf("%d. Kisinin Koltuk Numarasi %d\n",i+1,yhtKisiSayisi[i][1]);
    }
 printf("Toplam Ucret: %.2lf x %d = %.2lf\n",yhtBiletFiyati,a,(a*yhtBiletFiyati));

 printf("\n-------------------------------------\n");

 printf("\nKart Bilgileri");
 printf("\n---------------------------");
  printf("\nISIM: %s",isim);
  printf("\nSOYISIM: %s",soyisim);

  printf("\n\nKart Numarasi: %d",KartNumarasi);
  printf("\nGun/Ay: %d/%d",KartTarihiGUN,KartTarihiAY);

  printf("\nKart Sifresi: **%d",(KartSifresi%10));
  printf("\n-------------------------------------------------------------------\n");

 delay(10000);
exit(0);
 }




 void CIKIS()
 {
     system("CLS");
        printf("\t\t ---HOSCAKALIN---");
        delay(1000);
        exit(0);
 }
 void Uc()
{
    int i,j;

    for(i=0;i<11;i++)
    {
     for(j=0;j<11;j++)
     {
        if((i==0 || i==5 || i==10) && (j<11)  || (j==10))
            printf("*");
        else
          printf(" ");
     }
     printf("\n");

    }

}
void iki()
{

    int i,j;

    for(i=0;i<11;i++)
    {
     for(j=0;j<11;j++)
     {
        if( (i==0)  || (i==5) && (0<j && j<10) || (i==10) && (j>0) || (j==10) && (i<5) || (j==0) && (i>5) )
            printf("*");
        else
          printf(" ");
     }
     printf("\n");
    }
}
void bir()
{
    int i,j;

    for(i=0;i<11;i++)
    {
     for(j=0;j<11;j++)
     {
        if( (j==5) || (i==0 && j<5) || (i==10)&&(0<j && j<10) )
            printf("*");
        else
          printf(" ");
     }
     printf("\n");
    }
}


void GeriSayim()
{
    int i,j;

   for(i=1;i<4;i++)
   {
       if(i==3)
       {
           system("CLS");
           bir();
           delay(700);
       }
       if(i==2)
       {
           system("CLS");
           iki();
           delay(700);
       }
       if(i==1)
       {
           system("CLS");
           Uc();
           delay(700);
       }

     }
   system("CLS");
}

void KartBilgileri()
{
  system("CLS");

    printf("\t\tKART BILGILERI\n");
    printf("ADINIZ: ");
    scanf("%s",isim);
    printf("SOYADINIZ: ");
    scanf("%s",soyisim);
   //16 HANE FAZLA OLACAGI ICIN 4 HANE KULLANDIM
    printf("\n\n4 Haneli Kart Numaraniz: ");
    scanf("%d",&KartNumarasi);



     if(BasamakSayisi(KartNumarasi)!=4)
     {
       printf("%d Haneli Bir Numara Girdiniz Lutfen Tekrar Girin...",BasamakSayisi(KartNumarasi));
       delay(2000);
       system("CLS");
         KartBilgileri();
     }

   printf("\nKart Tarihi: **/**\n");
   printf("\t     ");
   printf("Gun:");
   scanf("%d",&KartTarihiGUN);
   printf("\n\t     ");
   printf("Ay:");
   scanf("%d",&KartTarihiAY);

   if( (KartTarihiAY>12 || KartTarihiAY<1) || (KartTarihiGUN<1 || KartTarihiGUN>30) )
   {
        printf("Gecersiz Bir Tarih Girdiniz. Lutfen Tekrar Giriniz...");
       delay(1500);
       system("CLS");
       KartBilgileri();
   }


  printf("\n3 Haneli Kart Sifresi: "); scanf("%d",&KartSifresi);
    if(BasamakSayisi(KartSifresi)!=3)
    {
      printf("Gecersiz Bir Sifre Girdiniz. Lutfen Tekrar Giriniz...");
       delay(1500);
       system("CLS");
       KartBilgileri();
   }

CikisMenu();
}



int BasamakSayisi(int sayi)
{
  int basamakS=0;

     for(basamakS=1;sayi>=10;basamakS++)
     {
         sayi = sayi/10;
     }
  return basamakS;
}

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX_METIN 10000
#define MAX_KELIME 50

    char imla_Sonrasi_Bosluk(char x[])
    {
        int i,j,hata=-1;
        for(i=0;i<strlen(x);i++)
        {
            int uzunluk=strlen(x);
            if((x[i]=='.' || x[i]=='?' || x[i]=='!' || x[i]==',') && x[i+1]!=' ')
                {
                    hata++;
                    for(j=uzunluk;j>i;j--)
                    {
                        x[j+1]=x[j];
                    }
                     x[i+1]=' ';
                }
        }
        return hata;
    }

    char buyuk_Harf_Kontrol(char x[])
    {
        int i,j,hata=0;
        for(i=0;i<strlen(x);i++)
        {
            if(islower(x[1]) && (x[0]=='\t' || x[0]==' '))
            {
                x[1]=toupper(x[1]);
                hata++;
            }
            else if((islower(x[i+2]) && (x[i]=='.' || x[i]=='?' || x[i]=='!')))
            {
                x[i+2]=toupper(x[i+2]);
                hata++;
            }
        }
        return hata;
    }

    char gereksiz_Bosluk_Kontrol(char metin[])
    {
        int i,j,k,hata=0;
        for(i=0;i<strlen(metin);i++)
        {
            if(isspace(metin[i]) && isspace(metin[i+1]))
            {
                for(j=(i+2);j<strlen(metin);j++)
                {
                    if(metin[j]!=' ')
                    {
                        int f_bosluk=i+1;
                        for(k=j;k<=strlen(metin);k++)
                        {
                            metin[f_bosluk]=metin[k];
                            f_bosluk++;
                        }
                        hata++;
                        break;
                    }
                }

            }
            else if(metin[0]!='\t')
            {
                for(j=strlen(metin);j>=0;j--)
                {
                    metin[j+1]=metin[j];
                }
                metin[0]='\t';
                hata++;
            }
        }
        return hata;

    }


    char paragraf_Sonu_Nokta (char x[])
    {
        int i,j,hata=0;
        if(x[strlen(x)-1]!='.')
           {
               for(i=strlen(x);i>(strlen(x)-1);i--)
                {
                    x[i+1]=x[i];
                }
                x[i+1]='.';
                hata++;
           }
            return hata;
    }

    void parantez_Tirnak_Kontrol (char x[])
    {
        int i,j,k;
        for(i=0;i<=MAX_METIN;i++)
        {
            if(x[i]=='(')
            {
                int uzunluk=strlen(x),say=0;
                for(j=(i+1);j<=uzunluk;j++)
                {
                    if(x[j]=='(')
                    {
                        for(k=i;k<=j;k++)
                        {
                            if(x[k]==')')
                            {
                                    say++;
                            }
                        }
                        if(say==0 && x[i]!=' ')
                        {
                            x[i]=' ';
                        }
                    }
                }
            }
        }
        int uzunluk=strlen(x),say=0;
        for(i=uzunluk;i>=0;i--)
        {
            if(x[i]=='(')
            {
                for(j=i;j<=uzunluk;j++)
                {
                    if(x[j]==')')
                    {
                        say++;
                    }
                }
                if(say==0)
                {
                    x[i]=' ';
                }
            }
        }

        for(i=0;i<strlen(x);i++)
        {
            if(x[i]=='\"')
            {
                x[i]=' ';
            }
        }
    }

    int kac_Harf (char x[])
    {
        int i,harf=0;
        for(i=0;i<=strlen(x);i++)
        {
            if(isalpha(x[i]))
            {
                harf++;
            }
        }
        return harf;
    }

    int kac_Kelime (char x[])
    {
        int i,kelime=0;
        for(i=0;i<=strlen(x);i++)
        {
            if(isalpha(x[i]))
            {
                if(!isalpha(x[i+1]))
                {
                    kelime++;
                }
            }
        }
        return kelime;
    }

    void en_Uzun_Kelime (char metin[])
    {
        int i,j,max=0,sayac=0,maxi,karakter_sayisi=0,kullanma=0;
        char enuzunkelime[MAX_KELIME]={};
        char karsilastirma[MAX_KELIME]={};
        for(i=0;i<=strlen(metin);i++)
        {
            if(isalpha(metin[i]))
            {
                sayac++;
            }
            else
            {
                if(sayac>max)
                {
                    maxi=i;
                    max=sayac;
                }
                sayac=0;
            }

        }

        for(i=(maxi-max);i<maxi;i++)
        {
            enuzunkelime[karakter_sayisi]=metin[i];
            karakter_sayisi++;
        }
        karakter_sayisi=0;
        strupr(enuzunkelime);
        strupr(metin);
        for(i=0;i<=strlen(metin);i++)
        {
            if(metin[i]==enuzunkelime[0] && metin[i+(strlen(enuzunkelime)-1)]==enuzunkelime[strlen(enuzunkelime)-1])
            {
                for(j=i;j<(i+strlen(enuzunkelime));j++)
                {
                    karsilastirma[karakter_sayisi]=metin[j];
                    karakter_sayisi++;
                }
                if(strcmp(strupr(enuzunkelime),strupr(karsilastirma))==0)
                    {
                        kullanma++;
                    }
                karakter_sayisi=0;
            }
        }

        printf("\n%d harf ile en uzun kelime olan \"%s\", metin icinde %d defa kullanilmistir.\n",max,strupr(enuzunkelime),kullanma);

    }


    void Yazdir ( char metin[])
    {
        int i;
        printf("\n");
        for(i=0;i<MAX_METIN;i++)
        {
            if(metin[i]!='\0')
                printf("%c",metin[i]);
            else
                break;
        }
    }

    void bilgi(char metin[],int hata)
    {
        printf("\n\nMetin %d kelime, %d harf olusturulmus ve %d yazim hatasi bulunup, duzeltilmistir.\n",kac_Kelime(metin),kac_Harf(metin),hata);
    }


int main()
{
    char metin[MAX_METIN];
    int hata=0;

        gets(metin);

        hata+=paragraf_Sonu_Nokta(metin);
        hata+=imla_Sonrasi_Bosluk(metin);
        parantez_Tirnak_Kontrol(metin);
        hata+=gereksiz_Bosluk_Kontrol(metin);
        hata+=buyuk_Harf_Kontrol(metin);

        Yazdir(metin);
        bilgi(metin,hata);
        en_Uzun_Kelime(metin);


    return 0;

}








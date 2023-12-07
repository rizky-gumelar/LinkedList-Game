#include <iostream>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <iomanip>

using namespace std;

struct dll{
    string nama;
    int nilai;
    dll *next;
    dll *prev;
};

dll *head=NULL;
dll *tail=NULL;

int skor;

void tambahdepan()
{
    dll *baru;
    baru = new dll;
    cout << "Inputkan nama : ";
    cin >> baru->nama;
    baru->nilai = 0;
    baru->next=NULL;
    baru->prev=NULL;
    if(head==NULL)
    {
        head=baru;
        tail=baru;
        tail->next=head;
        head->prev=tail;
    }
    else
    {
        baru->next=head;
        head->prev=baru;
        head=baru;
        tail->next=head;
        head->prev=tail;
    }
}
void tambahbelakang()
{
    dll *baru;
    dll *bantu;
    baru = new dll;
    bantu=head;
    cout << " Inputkan nama : ";
    cin >> baru->nama;
    baru->nilai = 0;
    baru->next=NULL;
    baru->prev=NULL;
    if(head==NULL)
    {
        head=baru;
        tail=baru;
        tail->next=head;
        head->prev=tail;
    }
    else
    {
        tail->next=baru;
        head->prev=baru;
        baru->next=head;
        baru->prev=tail;
        tail=baru;

    }
}
void hapusdepan()
{
    dll *hapus;
    int nilai;
    if(head==NULL)
    {
        cout << "data masih kosong"<<endl;
    }
    else
    {
        if(head==tail)
        {
            hapus=head=tail;
            nilai=hapus->nilai;
            head=NULL;
            tail=NULL;
            delete hapus;
        }
        else
        {
            hapus=head;
            nilai=hapus->nilai;
            head=head->next;
            head->prev=tail;
            tail->next=head;
            delete hapus;
        }

    }

}
void hapusbelakang()
{
    dll *hapus;
    int nilai;
    if(head==NULL)
    {
        cout << "data masih kosong"<<endl;
    }
    else
    {
        if(head==tail)
        {
            hapus=head=tail;
            nilai=hapus->nilai;
            head=NULL;
            tail=NULL;
            delete hapus;
        }
        else
        {
            hapus=tail;
            nilai=hapus->nilai;
            tail=tail->prev;
            head->prev=tail;
            tail->next=head;
            delete hapus;
        }

    }

}
void hapustengah(string cari)
{
    dll *hapus;
    dll *bantu;
    bantu=head;
    string nama;
    int nilai;
    if(head==NULL)
    {
        cout << " Data Masih Kosong"<<endl;
    }
    else if(head==tail)
    {
        hapus=head=tail;
        nama=hapus->nama;
        nilai= hapus->nilai;
        head=NULL;
        tail=NULL;
        delete hapus;
    }
    else
    {
        do
        {
            if(bantu->next->nama==cari)
            {
                if(bantu->next==head)
                {
                    hapusdepan();
                }
                else if(bantu->next==tail)
                {
                    hapusbelakang();
                }
                else
                {
                    hapus=bantu->next;
                    nama=hapus->nama;
                    nilai=hapus->nilai;
                    bantu->next->next->prev=bantu;
                    bantu->next=bantu->next->next;
                    delete hapus;
                }
            }
            bantu=bantu->next;
        }while(bantu->next!=head);
    }
}

void caridata(int cari)
{
    dll *bantu;
    bantu=head;

    if(head==NULL)
    {
        cout << "Data Kosong"<<endl;
    }
    else
    {
        do
        {
            if(bantu->nilai==cari)
            {
                cout << "Data Ketemu"<<endl;
                break;
            }
            bantu=bantu->next;
        }while(bantu!=head);
    }
}

void tambahtengah(int cari)
{
    dll *baru;
    dll *bantu;
    baru = new dll;
    bantu=head;
    baru->next=NULL;
    baru->prev=NULL;
    if(head==NULL)
    {
        head=baru;
        tail=baru;
        tail->next=head;
        head->prev=tail;
    }
    else
    {
        do
        {
            if(bantu->nilai==cari)
            {
                if(bantu==head)
                {
                    tambahdepan();
                    break;
                }
                else if(bantu==tail)
                {
                    tambahbelakang();
                    break;
                }
                else
                {
                    cout << "inputkan nilainya : ";
                    cin >> baru->nilai;
                    baru->next=bantu->next;
                    bantu->next=baru;
                    baru->prev=bantu;
                    break;
                }

            }
            bantu=bantu->next;

        }while(bantu!=head);
    }
}
void tampildepan()
{
    dll *bantu;
    bantu=head;
    if(head!=NULL)
    {
        cout << " ===========================\n";
        cout << " | No | Nama Player | Skor |\n";
        cout << " ===========================\n";
        int no = 1;
        do
        {
            cout << " | " << setiosflags(ios::right) << setw(2) << no << " | ";
            cout << setiosflags(ios::left) << setw(11) << bantu->nama << " | ";
            cout << setiosflags(ios::left) << setw(4) << bantu->nilai << " | ";
            cout << "\n ---------------------------\n";
            no++;
            //cout << bantu->nilai<<endl;
            bantu=bantu->next;
        }
        while(bantu!=head);
    }
    else
    {
        cout << "Data Masih Kosong"<<endl;
    }

}

void tampilbelakang()
{
    dll *bantu;
    bantu=tail;
    if(head!=NULL)
    {
        do
        {
            cout << bantu->nilai<<endl;
            bantu=bantu->prev;
        }
        while(bantu!=tail);
    }
    else
    {
        cout << "Data Masih Kosong"<<endl;
    }

}

struct tnode
{
    int NilaiX,NilaiY;      /*Menyimpan Koordinat MAKANAN yang DIMAKAN oleh LAKON*/
    tnode *next;
};


void gotoxy(int x, int y)
{
    COORD coord;
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void delay()
{
    float a=1;
    do
    {
       a=a+0.1;
    }
    while(a<1700000);
}
using namespace std;

/*******************************************/
void bersihlayar()
{
    for(int a=0;a<80;a++)
    {
        for(int b=0;b<=24;b++)
        {
            gotoxy(a,b);cout<<" ";
        }
    }
}

void kotak(int b1, int k1, int b2, int k2)
{
    for(int x=k1; x<=k2; x++)
    {
        gotoxy(x,b1);printf("%c",196);
        gotoxy(x,b2);printf("%c",196);
    }
    for(int x=b1; x<=b2; x++)
    {
        gotoxy(k1,x);printf("%c",179);
        gotoxy(k2,x);printf("%c",179);
    }

    gotoxy(k2,b1);printf("%c",191);
    gotoxy(k1,b2);printf("%c",192);
    gotoxy(k1,b1);printf("%c",218);
    gotoxy(k2,b2);printf("%c",217);
}

int acak1()
{
    int x=rand();
    if(x<2)
        return (x%75)+4;
    else
        return (x%75);
}

int acak2()
{
    int x=rand();
    if((x%20) < 5)
        return (x%20)+5;
    else
        return (x%20);

}

int play(){
    int brs=12;
    int klm=40;
    int tb=1;
    int tk=1;
    float bmusuh=6,kmusuh=2;
    float bbmusuh,bkmusuh;
    float tambahan=0.2;
    int mbrs,mklm;

    char kalimat1[80]={"GAME SERANG HINDAR - IMPLEMENTASI TYPE DATA DINAMIS - SKOR : "};
    skor = 0;

    int bbrs,bklm;

    bersihlayar();
    srand(time(0));
    kotak(1,1,3,78);
    kotak(4,1,23,78);
    gotoxy(klm,brs);printf("%c",277);
    gotoxy(kmusuh,bmusuh);printf("%c",219);

    mbrs=acak2();
    mklm=acak1();
    gotoxy(mklm,mbrs);cout<<"*";

    char key;
    do
    {
    gotoxy((80-strlen(kalimat1))/2,2);cout<<kalimat1<< skor;

        if (kbhit()) key=getch();

        if(key=='K') klm--;
        if(key=='M') klm++;
        if(key=='H') brs--;
        if(key=='P') brs++;



        if(klm<2) klm=77;
        if(klm>77) klm=2;
        if(brs<5) brs=22;
        if(brs>22) brs=5;

        if((brs==mbrs) && (klm==mklm))
        {
            mbrs=acak2();
            mklm=acak1();
            gotoxy(mklm,mbrs);cout<<"*";
            skor=skor+10;
            /*tambahan=tambahan+0.1;*/
        }

        if(bmusuh<brs) bmusuh=bmusuh+tambahan;
        if(bmusuh>brs) bmusuh=bmusuh-tambahan;
        if(kmusuh<klm) kmusuh=kmusuh+tambahan;
        if(kmusuh>klm) kmusuh=kmusuh-tambahan;
        gotoxy(kmusuh,bmusuh);printf("%c",219);
        bbmusuh=bmusuh;
        bkmusuh=kmusuh;

        if((brs==int(bmusuh)) && (klm==int(kmusuh)))
        {
            gotoxy(60,22);cout<<"G A M E   O V E R";
            getch();
            system("cls");
            return 0;
        }

        bbrs=brs;
        bklm=klm;
        gotoxy(klm,brs);printf("%c",178);
        delay();
        gotoxy(bklm,bbrs);printf(" ");
        gotoxy(bkmusuh,bbmusuh);printf(" ");

    }
    while(key!=27);

}

void pilihPlayer(){
    dll *now;
    now = head;

    int pilih,cari;
    do
    {
        system("cls");
        cout<<"\n Player saat ini = "<< now->nama <<endl;
        cout<<" Skor            = "<< now->nilai <<endl;
        cout<<" ==================================="<<endl;
        cout<<" = 1. Mulai main                   ="<<endl;
        cout<<" = 2. Next Player                  ="<<endl;
        cout<<" = 3. Prev Player                  ="<<endl;
        cout<<" = 4. Kembali                      ="<<endl;
        cout<<" ==================================="<<endl;
        cout << endl << " Pilihan Anda [1-4] : ";
        cin >> pilih;


        switch(pilih)
        {
            case 1:
                play();
                now->nilai=now->nilai+skor;
                break;
            case 2:
                now=now->next;
                break;
            case 3:
                now=now->prev;
                break;
        }
    }while(pilih!=4);

}

void sortList(){

    dll *bantu, *bantu2;
    bantu = head;
    bantu2 = head->next;

    int temp;
    string tempname;

    if(head==NULL)
    {
        cout << " Data Kosong"<<endl;
    }
    else
    {
        do
        {
            do
            {
                if(bantu->nilai>bantu2->nilai)
                {
                    temp = bantu->nilai;
                    tempname = bantu->nama;
                    bantu->nilai = bantu2->nilai;
                    bantu->nama = bantu2->nama;
                    bantu2->nilai = temp;
                    bantu2->nama = tempname;
                }
                bantu2=bantu2->next;
            }while(bantu2!=tail);
            bantu=bantu->next;
        }while(bantu!=head);
    }


    }

int main()
{
    int pilih;
    string cari;
    do
    {
        system("cls");
        cout<<" ==================================="<<endl;
        cout<<" =        GAME SERANG HINDAR       ="<<endl;
        cout<<" ==================================="<<endl;
        cout<<" = 1. Main                         ="<<endl;
        cout<<" = 2. Buat Player Baru             ="<<endl;
        cout<<" = 3. Hapus Player Tertentu        ="<<endl;
        cout<<" = 4. Lihat Leaderboard            ="<<endl;
        cout<<" = 5. Keluar                       ="<<endl;
        cout<<" ==================================="<<endl;
        cout << endl << " Pilihan Anda [1-5] : ";
        cin >> pilih;

        switch(pilih)
        {
            case 1:
                if(head!=NULL){
                    pilihPlayer();
                }else{
                    //tambahbelakang();
                    cout << " Belum ada player. Silakan buat player baru";
                    getch();
                }
                break;
            case 2:
                tambahbelakang();
                cout << " Berhasil ditambah";
                getch();
                break;
            case 3:
                cout << " Hapus player = ";
                cin >> cari;
                hapustengah(cari);
                getch();
                break;
            case 4:
                if(head!=NULL){
                    sortList();
                    tampildepan();
                }else{
                    cout << " Tidak ada player\n";
                }
                cout << " klik untuk lanjut . . .";
                getch();
                break;
        }
    }while(pilih!=5);

    return 0;
}

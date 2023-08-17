#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

char input1[100],input2[100];
int bill; //n= bulan, ditentukan admin;
int n=1;
int nmin1=0;

struct
{
    char nama[100];
    char pass[100];
    char complain[10000];
    int paket;
    int tagih;
    int deposit;
    int aktif;
    int done;
}user;

struct 								
{
    char nama[100];
    int deposit;
}payment;

FILE *urusanbayar;
FILE *urusanbayar2;
FILE *userpunya;
FILE *userpunya2;
FILE *userread;

void pause()					
{
	system("pause");
}

int pay(char uname[100])
{
    system("cls");		
    int berapa;
    printf("Pembayaran:");
    pause();
    printf("masukan jumlah pembayaran: ");scanf("%d",&berapa);
        userread = fopen("./datauser.dat","rb");
        userpunya = fopen("./datauser2.dat","wb");
            while(fread(&user,sizeof(user),1,userread)==1)
            {
            if(strcmp(uname,user.nama)==0)
            {
                user.deposit=user.deposit+berapa;
                //user.done++;
            }
            fwrite(&user,sizeof(user),1,userpunya);
            }
        fclose(userpunya);fclose(userread);remove("./datauser.dat");rename("./datauser2.dat","./datauser.dat");
        printf("Pembayaran sudah kami terima. Terima Kasih ^_^\n");pause();return userpage(uname);
}

void menuadmin()
{
    system("cls");
    int pil;char inp[100];int tagih;
    printf("======== DasWasser Admin ========");
    printf("\n1. Tampilkan semua user\n2. Validasi User\n3. Set bulan ke...\n4. Hapus Akun\n5. Back\npilihan: ");scanf("%d",&pil);getchar();
    switch(pil)
    {
        case 1: 
        {//bagian ini sudah dihapus dan harus kalian isi lagi sesuai dengan file.exe
            userpunya = fopen("./datauser.dat", "rb");
            while(fread(&user,sizeof(user),1,userpunya)==1)
            {
            	printf("\n");
            	printf("Nama		 : %s\n",user.nama);
            	printf("Status		 : %s\n",user.aktif);
            	printf("Pesan		 : %s\n",user.complain);
            	printf("Sisa Tagihan : %s\n",user.tagih);
            	printf("Jenis Paket	 : %s\n",user.paket);
			}
			fclose(userpunya);
			pause();
			menuadmin();
			break;
        }
        case 2:
        {//bagian ini sudah dihapus dan harus kalian isi lagi sesuai dengan file.exe
            char valid[100];
            
            userpunya = fopen("./datauser.dat", "rb");
            while(fread(&user,sizeof(user),1,userpunya)==1)
            {
            	if (user.aktif==0)
            	{
            		printf("Nama	: %s\n",user.nama);
				}
			}
			fclose(userpunya);
			userpunya  = fopen("./datauser.dat", "rb+");
			userpunya2 = fopen("./datauser2.dat", "wb");
			printf("Siapa yang ingin di aktivasi? : ");gets(valid);
			while(fread(&user,sizeof(user),1,userpunya)==1);
			{
				if(strcmp(user.nama,valid)==0)
				{
					user.aktif=1;
					fwrite(&user,sizeof(user),1,userpunya2);
				}
				else fwrite(&user,sizeof(user),1,userpunya2);
			}
			fclose(userpunya);
			fclose(userpunya2);
			remove("./datauser.dat");
			rename("./datauser2.dat","./datauser.dat");
			menuadmin();
			break;
		}
        case 3:
        {
            printf("bulan ke: ");scanf("%d",&n);
            nmin1=n-1;
			menuadmin();break;
        }
        case 4:
		{//bagian ini sudah dihapus dan harus kalian isi lagi sesuai dengan file.exe
            char del[100];
            userpunya = fopen("./datauser.dat", "rb");
            while(fread(&user,sizeof(user),1,userpunya)==1);
            {
            	printf("Nama	: %s\n",user.nama);
			}
			fclose(userpunya);
			userpunya  = fopen("./datauser.dat", "rb");
			userpunya2 = fopen("./datauser2.dat", "wb");
			printf("Silahkan masukkan nama yang akan dihapus : ");gets(del);
			while(fread(&user,sizeof(user),1,userpunya)==1)
			{
				if(strcmp(user.nama,del)!=0)
				{
					fwrite(&user,sizeof(user),1,userpunya2);
				}
			}
			fclose(userpunya);
			fclose(userpunya2);
			remove("./datauser.dat");
			rename("./datauser2.dat","./datauser.dat");
			menuadmin();
			break;
		}
        case 5: 
        main(); break;
        default:
        {
            printf("salah mimin, -_-");menuadmin();break;
        }
    }
}

void regis()
{//bagian ini sudah dihapus dan harus kalian isi lagi sesuai dengan file.exe
	system("cls");
	userpunya = fopen("./datauser.dat", "ab");
	printf("Nama (akan digunakan saat login) : ");gets(user.nama);
	printf("Password                         : ");gets(user.pass);
	printf("\nPilih Paket : ");
	printf("\n 1) 10 m^3 per hari\n 2) 15 m^3 per hari\n 3) 30 m^3 per hari");
	printf("\nPilihan : ");scanf("%d",&user.paket);user.aktif=0;
	fwrite(&user,sizeof(user),1,userpunya);
	printf("\n\nTerima Kasih, mohon menunggu proses validasi dari kami\n");pause();
	fclose(userpunya);
	main();
}

void login_admin()
{
	printf("Nama		: ");gets(input1);
    printf("Password	: ");gets(input2);
    if(strcmp(input1,"admin")==0 && strcmp(input2,"admin")==0)
	{
	    fclose(userpunya);menuadmin();
	} else
    {
    	pause();
    	main();
    }
}

void login()
{//bagian ini sudah dihapus dan harus kalian isi lagi sesuai dengan file.exe
    system("cls");
    int i=0;
    int i1=0;
    char unm[100],psw[100];
    userpunya = fopen("./datauser.dat", "rb+"); 
    printf("Login\n");
    printf("Nama	 : ");gets(unm);
    printf("Password : ");gets(psw);
	while(fread(&user,sizeof(user),1,userpunya)==1)
	{
		if (strcmp(unm,user.nama)==0 && strcmp(psw,user.pass)==0 && user.aktif==1)
		{
			printf("\nLogin berhasil, selamat datang %s\n",unm);
			pause();
			system("cls");
			i1=1;
			fclose(userpunya);
			userpage(unm);
		}
	}
	if (i1==0)
	{
		printf("\nNama/Password salah, atau anda belum divalidasi oleh kami");
		pause();
		system("cls");
		main();
	}
}

int userpage(char pengguna[100])
{
    int tarif,pil;
    int bln;
    char inp[1000];
    system("cls");
    printf("--------DasWasser Dashboard---------\n");
    printf("Nama: %s\n",pengguna);
    //userread=fopen("./datauser2.dat","wb");
    userpunya=fopen("./datauser.dat","rb");
    while(fread(&user,sizeof(user),1,userpunya)==1)
    {
        if(strcmp(pengguna,user.nama)==0)
        {
            bln=user.done;
          printf("Jenis paket: %d\n",user.paket);
           switch(user.paket)
            {
             case 1: tarif=10000;printf("10 m^3 per hari\n"); break;
             case 2: tarif=15000;printf("15 m^3 per hari\n"); break;
             case 3: tarif=25000;printf("30 m^3 per hari\n"); break;
            }
           bill=user.deposit;
            //user.tagihan=bill;
        }
    }
    fclose (userpunya); 
    printf("Tarif anda: Rp %d per bulan\n",tarif);
    printf("Pada bulan ke %d ini, saldo anda : %d\n",n,bill-(tarif*n));
    printf("1. Bayar tagihan\n2. Kalkulator tagihan\n3. Pesan ke admin\n4. Ganti paket\n5. Kembali\n");
    scanf("%d",&pil);
    switch(pil)
    {
        case 1 :return pay(pengguna);break;
        case 2:
        {
            printf("Masukan bulan ke berapa ");scanf("%d",&bln);getchar();
            printf("\nTagihan anda pada bulan tersebut adalah: %d",bill+(tarif*abs(bln-n)));
            pause();
            return userpage(pengguna);
            break;
        }
        case 3:
        {//bagian ini sudah dihapus dan harus kalian isi lagi sesuai dengan file.exe
            printf("Masukkan pesan untuk kami : ");getchar();gets(&inp);
            userpunya = fopen("./datauser.dat", "rb+");
            userpunya2= fopen("./datauser2.dat", "wb");
            while(fread(&user,sizeof(user),1,userpunya)==1)
            {
            	if(strcmp(pengguna,user.nama)==0)
				{
				    gets(user.complain);
				    fwrite(&user,sizeof(user),1,userpunya2);
				}
				else fwrite (&user,sizeof(user),1,userpunya2);
			}
			remove("./datauser.dat");
			rename("./datauser2.dat","./datauser.dat");
			userpage(pengguna);
			break;
        }
        case 4:
        {//bagian ini sudah dihapus dan harus kalian isi lagi sesuai dengan file.exe
            int pkt;
        	printf("1)10 m^3 per hari\n2)15 m^3 per hari\n3)30 m^3 per hari\n\n");
   			printf("Pilihan Anda: ");scanf("%d",&pkt);
   			userpunya = fopen("./datauser.dat", "rb+");
			userpunya2 = fopen("./datauser2.dat", "wb");
            	while(fread(&user,sizeof(user),1,userpunya)==1)
				{
				    if(pkt!=user.paket)
				    {
					    user.paket=pkt;
						fwrite(&user, sizeof(user), 1, userpunya2);
			        }
					else fwrite(&user, sizeof(user), 1, userpunya2);
				}
			fclose(userpunya);
			fclose(userpunya2);
			remove("./datauser.dat");
			rename("./datauser2.dat","./datauser.dat");
			userpage(pengguna);
			break;
        }
        case 5:return main();
    }
}

int main()
{
    system("cls");
    int pil;
    printf("selamat datang di DasWasser!\n1. Registrasi\n2. Login\n3. Login admin\n4. Exit\nPilhan: ");
    scanf("%d",&pil);getchar();
    switch(pil)
    {
        case 1: regis();break;
        case 2: login();break;
        case 3: login_admin();break;
        case 4: return 0;break;
    }
}

//Standard Library C++
#include <iostream> //Untuk menampilkan perintah cin, cout, dan endl
#include <fstream> //Gabungan dari ofstream dan ifstream agar dapat menulis, membaca, membuat, serta menghapus file
#include <sstream> //Untuk menampilkan perintah stringstream
#include <conio.h> //Untuk menampilkan perintah getch dan system("cls")
#include <stdlib.h> //Untuk menampilkan perintah atoi (mengubah string menjadi integer) 

//Standard Library C++
using namespace std;

//Pendeklarasian untuk permisalan akses variabel rujukan file (variabel gobal)
fstream myFile;

//Prosedur atau Fungsi untuk menampilkan tampilan awal program
void intro()
{
    cout<<"=========================================================================="<<endl;
	cout<<"                      Program Pendataan Hewan Kurban                      "<<endl;
    cout<<"=========================================================================="<<endl;
}

//Prosedur atau Fungsi untuk menampilkan tampilan pilihan menu utama
void pilih_menu()
{
    cout<<"Silahkan Pilih Menu"<<endl;
    cout<<"[1] Masukkan Data"<<endl;
    cout<<"[2] Menambahkan Data"<<endl;
    cout<<"[3] Menampilkan Data"<<endl;
    cout<<"[4] Mengedit Data"<<endl;
    cout<<"[5] Menghapus Data"<<endl;
    cout<<"[6] Keluar"<<endl;
}

//Prosedur atau Fungsi untuk menampilkan tampilan pilihan hewan
void pilih_hewan()
{
    cout<<"[A] Sapi"<<endl;
    cout<<"[B] Kambing"<<endl;
    cout<<"\nMasukkan dengan Huruf Kapital !"<<endl;
}

//Prosedur atau Fungsi untuk menampilkan tampilan pilihan mode tampilan pada menu "Menampilkan Data"
void mode_tampilan()
{
    cout<<"[A] Searching (Pencarian)"<<endl;
    cout<<"[B] Sorting (Pengurutan)"<<endl;
    cout<<"\nMasukkan dengan Huruf Kapital"<<endl;
}

//Prosedur atau Fungsi untuk menampilkan tampilan pilihan cara pengurutan pada menu "Sorting"
void urutan()
{
    cout<<"[A] Ascending (Kecil ke Besar)"<<endl;
    cout<<"[B] Descending (Besar ke Kecil)"<<endl;
    cout<<"\nMasukkan dengan Huruf Kapital"<<endl;
}

//Prosedur atau Fungsi untuk menampilkan tampilan pilihan jenis objek sorting atau pengurutan
void jenis_sort()
{
    cout<<"[A] Nama"<<endl;
    cout<<"[B] Umur"<<endl;
    cout<<"\nMasukkan dengan Huruf Kapital [A / B]"<<endl;
}

//Prosedur atau Fungsi untuk menampilkan tampilan pilihan jenis objek searching atau pencarian
void jenis_search()
{
    cout<<"[A] Nama"<<endl;
    cout<<"[B] Harga"<<endl;
    cout<<"\nMasukkan dengan Huruf Kapital [A / B]"<<endl;
}

//Prosedur atau Fungsi untuk menampilkan tampilan pilihan objek penghapusan data pada menu "Menghapus Data"
void jenis_hapus()
{
    cout<<"[A] Hapus Isi File Eksternal"<<endl;
    cout<<"[B] Hapus File Eksternal"<<endl;
    cout<<"\nMasukkan dengan Huruf Kapital !"<<endl;
}

//Prosedur atau Fungsi untuk menampilkan tampilan pilihan cara penghapusan data 
void mode_hapus_isi()
{
    cout<<"[A] Secara Keseluruhan"<<endl;
    cout<<"[B] Salah Satu Data Saja"<<endl;
    cout<<"\nMasukkan dengan Huruf Kapital !"<<endl;
}

//Struct untuk menampung data pada Sapi
struct sapi
{
    string nama;
    int umur;
    float berat;
    int harga;
};

//Struct untuk menampung data pada Kambing
struct kambing
{
    string nama;
    int umur;
    float berat;
    int harga;
};

//Deklarasi Array di dalam Struct pada data Sapi dan Kambing (Variabel Global)
struct sapi Sapi[10];
struct kambing Kambing[10];

//Deklarasi Konstanta agar data yang ditampung di dalam Array tidak dapat diubah (data tidak bisa lebih dari 10)
//Walaupun batas sebenarnya 5 *sengaja dilebihkan agar pas penghitungan di bawah tidak berantakan
const int i = 10;

//Prosedur atau Fungsi untuk menampilkan menu "Masukkan Data"
void isi_file()
{
    //Pendeklarasian
    int i; //i = deklarasi untuk perulangan for
    int banyak_sapi, banyak_kambing;
    string pilihan;

    //Pemanggilan Fungsi atau Prosedur void pilih_hewan
    pilih_hewan();
    cout<<"Masukkan Pilihan Hewan [A/B] : ";
    cin>>pilihan;
    cout<<"=========================================================================="<<endl;

    //Percabangan if else untuk mengelompokkan kondisi yang telah dipilih user
    if (pilihan == "A")
    {
        cout<<"Masukkan Jumlah Data Sapi yang ingin dimasukkan : ";
        cin>>banyak_sapi;
        cout<<"=========================================================================="<<endl;

        //Perintah untuk membuka file txt dan menulisnya
        myFile.open("Data_Sapi.txt", ios::out);
        for (i = 0; i < banyak_sapi; i++)
        {
            //fflush(stdin) digunakan untuk menyimpan data yang telah diinputkan oleh user
            //pada program agar tidak terjadi hambatan pada saat dipanggil
            cout<<"Sapi Nomor "<<i+1<<endl;
            cout<<"Nama     : ";
            cin>>Sapi[i].nama;fflush(stdin);
            cout<<"Umur     : ";
            cin>>Sapi[i].umur;fflush(stdin);
            cout<<"Berat    : ";
            cin>>Sapi[i].berat;fflush(stdin);
            cout<<"Harga    : ";
            cin>>Sapi[i].harga;fflush(stdin);
            cout<<endl;

            //Perintah untuk menyimpan seluruh data yang telah tertulis ke dalam file txt
            myFile << Sapi[i].nama << "," << Sapi[i].umur << "," << Sapi[i].berat << "," << Sapi[i].harga << endl;
        }
        cout<<"=========================================================================="<<endl;
        cout<<"                          Data Berhasil Tersimpan                         "<<endl;
        cout<<"=========================================================================="<<endl;
    }
    else if (pilihan == "B")
    {
        cout<<"Masukkan Jumlah Data Kambing yang ingin dimasukkan : ";
        cin>>banyak_kambing;
        cout<<"=========================================================================="<<endl;

        //Perintah untuk membuka file txt dan menulisnya
        myFile.open("Data_Kambing.txt", ios::out);
        for (i = 0; i < banyak_kambing; i++)
        {
            //fflush(stdin) digunakan untuk menyimpan data yang telah diinputkan oleh user
            //pada program agar tidak terjadi hambatan pada saat dipanggil
            cout<<"Kambing Nomor "<<i+1<<endl;
            cout<<"Nama     : ";
            cin>>Kambing[i].nama;fflush(stdin);
            cout<<"Umur     : ";
            cin>>Kambing[i].umur;fflush(stdin);
            cout<<"Berat    : ";
            cin>>Kambing[i].berat;fflush(stdin);
            cout<<"Harga    : ";
            cin>>Kambing[i].harga;fflush(stdin);
            cout<<endl;

            //Perintah untuk menyimpan seluruh data yang telah tertulis ke dalam file txt
            myFile << Kambing[i].nama << "," << Kambing[i].umur << "," << Kambing[i].berat << "," << Kambing[i].harga << endl;
        }
        cout<<"=========================================================================="<<endl;
        cout<<"                          Data Berhasil Tersimpan                         "<<endl;
        cout<<"=========================================================================="<<endl;
    }
    else 
    {
        cout<<"=========================================================================="<<endl;
        cout<<"Mohon Maaf Data Hewan yang Anda Pilih Tidak Tersedia"<<endl;
        cout<<"=========================================================================="<<endl;
    }
    //Perintah untuk menutup file txt
    myFile.close();
    cout<<"Tekan Enter untuk Kembali ke Menu ";

    //Untuk memberi jeda pada program
    getch();

    //Untuk membersihkan atau menghapus hasil sebelumnya agar tidak penuh 
    //pada layar windows
    system("cls");
}

//Prosedur atau Fungsi untuk menampilkan menu "Menambahkan Data"
void tambah_isi_file()
{
    //Pendeklarasian
    int i; //i = deklarasi untuk perulangan for
    int ubah;
    string pilihan;
    ubah = 5;

    //Pemanggilan Fungsi atau Prosedur void pilih_hewan
    pilih_hewan();
    cout<<"Masukkan Pilihan Hewan [A/B] : ";
    cin>>pilihan;
    cout<<"=========================================================================="<<endl;

    //Percabangan if else untuk mengelompokkan kondisi yang telah dipilih user
    if (pilihan == "A")
    { 
        //Perintah untuk membuka file txt dan menulis sebuah tambahan data di urutan paling belakang 
        //pada data. Namun, data yang telah ditulis sebelumnya tidak akan terhapus
        myFile.open("Data_Sapi.txt", ios::app);
        for (i = 0; i < 5; i++)
        {
            //fflush(stdin) digunakan untuk menyimpan data yang telah diinputkan oleh user
            //pada program agar tidak terjadi hambatan pada saat dipanggil
            cout<<"Nama     : ";
            cin>>Sapi[i].nama;fflush(stdin);
            cout<<"Umur     : ";
            cin>>Sapi[i].umur;fflush(stdin);
            cout<<"Berat    : ";
            cin>>Sapi[i].berat;fflush(stdin);
            cout<<"Harga    : ";
            cin>>Sapi[i].harga;fflush(stdin);
            cout<<"=========================================================================="<<endl;
            cout<<"                         Data Berhasil Ditambahkan                        "<<endl;
            cout<<"=========================================================================="<<endl;

            //Perintah untuk menyimpan seluruh data yang telah tertulis ke dalam file txt
            myFile << Sapi[i].nama << "," << Sapi[i].umur << "," << Sapi[i].berat << "," << Sapi[i].harga << endl;
            
            break; //Perintah untuk memaksa perulangan berhenti jika kondisi tersebut cocok
        }  
        //Perintah untuk menutup file txt 
        myFile.close();
    }
    else if (pilihan == "B")
    {
        //Perintah untuk membuka file txt dan menulis sebuah tambahan data di urutan paling belakang 
        //pada data. Namun, data yang telah ditulis sebelumnya tidak akan terhapus
        myFile.open("Data_Kambing.txt", ios::app);
        for (i = 0; i < 5; i++)
        {
            //fflush(stdin) digunakan untuk menyimpan data yang telah diinputkan oleh user
            //pada program agar tidak terjadi hambatan pada saat dipanggil
            cout<<"Nama     : ";
            cin>>Kambing[i].nama;fflush(stdin);
            cout<<"Umur     : ";
            cin>>Kambing[i].umur;fflush(stdin);
            cout<<"Berat    : ";
            cin>>Kambing[i].berat;fflush(stdin);
            cout<<"Harga    : ";
            cin>>Kambing[i].harga;fflush(stdin);
            cout<<"=========================================================================="<<endl;
            cout<<"                         Data Berhasil Ditambahkan                        "<<endl;
            cout<<"=========================================================================="<<endl;

            //Perintah untuk menyimpan seluruh data yang telah tertulis ke dalam file txt
            myFile << Kambing[i].nama << "," << Kambing[i].umur << "," << Kambing[i].berat << "," << Kambing[i].harga << endl;
           
            break; //Perintah untuk memaksa perulangan berhenti jika kondisi tersebut cocok
        }
        //Perintah untuk menutup file txt
        myFile.close();
    }
    else 
    {
        cout<<"=========================================================================="<<endl;
        cout<<"Mohon Maaf Data Hewan yang Anda Pilih Tidak Tersedia"<<endl;
        cout<<"=========================================================================="<<endl;
    }
    //Perintah untuk menutup file txt
    myFile.close();
    cout<<"Tekan Enter untuk Kembali ke Menu ";

    //Untuk memberi jeda pada program
    getch();

    //Untuk membersihkan atau menghapus hasil sebelumnya agar tidak penuh 
    //pada layar windows
    system("cls");
}

//Prosedur atau Fungsi untuk menampilkan menu pilihan "Tampilkan Data Sapi"
void baca_file_sapi()
{
    //Pendeklarasian
    int i = 0; //i = deklarasi untuk perulangan for
    string umur, berat, harga;

    cout<<"--------------------------------------------------------------------------"<<endl;
    cout<<"                                 Data Sapi                                "<<endl;
    cout<<"--------------------------------------------------------------------------"<<endl;

    //Perintah untuk membuka file txt dan membacanya
    myFile.open("Data_Sapi.txt", ios::in);
    while (!myFile.eof())
    {
        //Perintah untuk membaca seluruh isi di dalam file txt
        getline(myFile, Sapi[i].nama, ',');
        getline(myFile, umur, ',');
        getline(myFile, berat, ',');
        getline(myFile, harga, '\n');
        
        //Perintah untuk membaca string dan menuliskan data ke dalam bentuk string
        stringstream umurString (umur);
        stringstream beratString (berat);
        stringstream hargaString (harga);

        //Perintah untuk memasukkan hasil dari stringstream tadi ke dalam array di dalam struct
        umurString >> Sapi[i].umur;
        beratString >> Sapi[i].berat;
        hargaString >> Sapi[i].harga;

        //Percabangan if yang digunakan sebagai pembatas agar pada saat dirun line paling akhir
        //di dalam file yang kosong tidak ikut terbaca
        if (myFile.eof())
        {
            break; //Perintah untuk memaksa perulangan berhenti jika kondisi tersebut cocok
        }
        cout<<"Sapi Nomor "<<i+1<<endl;
        cout<<"Nama     : "<<Sapi[i].nama<<endl;
        cout<<"Umur     : "<<Sapi[i].umur<<" Tahun"<<endl;
        cout<<"Berat    : "<<Sapi[i].berat<<" Kg"<<endl;
        cout<<"Harga    : Rp. "<<Sapi[i].harga<<endl;
        cout<<endl;
        i++;
    }
    cout<<"=========================================================================="<<endl;

    //Perintah untuk menutup file txt
    myFile.close();
}

//Prosedur atau Fungsi untuk menampilkan menu pilihan "Tampilkan Data Kambing"
void baca_file_kambing()
{
    //Pendeklarasian
    int i = 0; //i = deklarasi untuk perulangan for
    string umur, berat, harga;

    cout<<"--------------------------------------------------------------------------"<<endl;
    cout<<"                                Data Kambing                              "<<endl;
    cout<<"--------------------------------------------------------------------------"<<endl;
    
    //Perintah untuk membuka file txt dan membacanya
    myFile.open("Data_Kambing.txt", ios::in);
    while (!myFile.eof())
    {
        //Perintah untuk membaca seluruh isi di dalam file txt
        getline(myFile, Kambing[i].nama, ',');
        getline(myFile, umur, ',');
        getline(myFile, berat, ',');
        getline(myFile, harga, '\n');
        
        //Perintah untuk membaca string dan menuliskan data ke dalam bentuk string
        stringstream umurString (umur);
        stringstream beratString (berat);
        stringstream hargaString (harga);

        //Perintah untuk memasukkan hasil dari stringstream tadi ke dalam array di dalam struct
        umurString >> Kambing[i].umur;
        beratString >> Kambing[i].berat;
        hargaString >> Kambing[i].harga;

        //Percabangan if yang digunakan sebagai pembatas agar pada saat dirun line paling akhir
        //di dalam file yang kosong tidak ikut terbaca
        if (myFile.eof())
        {
            break; //Perintah untuk memaksa perulangan berhenti jika kondisi tersebut cocok
        }
        cout<<"Kambing Nomor "<<i+1<<endl;
        cout<<"Nama     : "<<Kambing[i].nama<<endl;
        cout<<"Umur     : "<<Kambing[i].umur<<" Tahun"<<endl;
        cout<<"Berat    : "<<Kambing[i].berat<<" Kg"<<endl;
        cout<<"Harga    : Rp. "<<Kambing[i].harga<<endl;
        cout<<endl;
        i++;
    }
    cout<<"=========================================================================="<<endl;

    //Perintah untuk menutup file txt
    myFile.close();
}

//Prosedur atau Fungsi untuk menghitung pengurutan harga sapi dengan menggunakan Bubble Sort
//sebelum melakukan searching dengan menggunakan "Interpolation Search" 
//agar data dapat terurut terlebih dahulu
void rumus_pengurutan_searching_harga_sapi()
{
    //Pendeklarasian
    int i, j; //i dan j = deklarasi untuk perulangan for
    int ubah, tukar;
    string umur, berat, harga;
    ubah = 5;

    //Perintah untuk membuka file txt
    myFile.open("Data_Sapi.txt");
    for (i = 0; i < 5; i++)
    {
        //Perintah untuk membaca seluruh isi di dalam file txt 
        getline(myFile, Sapi[i].nama, ',');
        getline(myFile, umur, ',');
        getline(myFile, berat, ',');
        getline(myFile, harga, '\n');
    }
    //Perintah untuk menutup file txt
    myFile.close();

    //Rumus Pengurutan Harga dengan menggunakan Bubble Sort 
    for (i = 0; i < 5; i++)
    {
        for(j = 0; j < 5 - i - 1; j++)
        {
            if(Sapi[j].harga > Sapi[j+1].harga)
            {
                tukar = Sapi[j].harga;
                Sapi[j].harga = Sapi[j+1].harga;
                Sapi[j+1].harga = tukar;
            }
        }
    }

    //Perintah untuk membuka file txt dan menghapus seluruh isi file, serta menuliskan kembali dengan
    //data baru
    myFile.open ("Data_Sapi.txt", ios::trunc | ios::out);
    for (i = 0; i < ubah; i++)
    {
        //Perintah untuk menyimpan seluruh data yang telah tertulis ke dalam file txt
        myFile << Sapi[i].nama << "," << Sapi[i].umur << "," << Sapi[i].berat << "," << Sapi[i].harga << endl;
    }
    cout<<"=========================================================================="<<endl;

    //Perintah untuk menutup file txt
    myFile.close();
}

//Prosedur atau Fungsi untuk menghitung pengurutan harga sapi dengan menggunakan Bubble Sort
//sebelum melakukan searching dengan menggunakan "Interpolation Search" 
//agar data dapat terurut terlebih dahulu
void rumus_pengurutan_searching_harga_kambing()
{
    //Pendeklarasian
    int i, j; //i dan j = deklarasi untuk perulangan for
    int ubah, tukar;
    string umur, berat, harga;
    ubah = 5;

    //Perintah untuk membuka file txt
    myFile.open("Data_Sapi.txt");
    for (i = 0; i < 5; i++)
    {
        //Perintah untuk membaca seluruh isi di dalam file txt 
        getline(myFile, Sapi[i].nama, ',');
        getline(myFile, umur, ',');
        getline(myFile, berat, ',');
        getline(myFile, harga, '\n');
    }
    //Perintah untuk menutup file txt
    myFile.close();

    //Rumus Pengurutan Harga dengan menggunakan Bubble Sort
    for (i = 0; i < 5; i++)
    {
        for(j = 0; j < 5 - i - 1; j++)
        {
            if(Kambing[j].harga > Kambing[j+1].harga)
            {
                tukar = Kambing[j].harga;
                Kambing[j].harga = Kambing[j+1].harga;
                Kambing[j+1].harga = tukar;
            }
        }
    }

    //Perintah untuk membuka file txt dan menghapus seluruh isi file, serta menuliskan kembali dengan
    //data baru
    myFile.open ("Data_Kambing.txt", ios::trunc | ios::out);
    for (i = 0; i < ubah; i++)
    {
        //Perintah untuk menyimpan seluruh data yang telah tertulis ke dalam file txt
        myFile << Kambing[i].nama << "," << Kambing[i].umur << "," << Kambing[i].berat << "," << Kambing[i].harga << endl;
    }
    cout<<"=========================================================================="<<endl;

    //Perintah untuk menutup file txt
    myFile.close();
}

//Prosedur atau Fungsi untuk menampilkan pilihan menu tampilan data secara "Searching"
void baca_file_searching()
{
    //Pendeklarasian
    int i = 0; //i = deklarasi untuk perulangan for
    string pilih, cara;

    cout<<"Silahkan Pilih Data Hewan yang ingin dicari"<<endl;
    pilih_hewan(); //Pemanggilan Fungsi atau Prosedur void pilih_hewan

    cout<<"Masukkan Pilihan Data [A/B] : ";
    cin>>pilih;
    cout<<"=========================================================================="<<endl;

    cout<<"Silahkan Pilih Cara Pencarian"<<endl;
    jenis_search(); //Pemanggilan Fungsi atau Prosedur void jenis_search

    cout<<"Lakukan Pencarian Berdasarkan ... ";
    cin>>cara;
    cout<<"=========================================================================="<<endl;

    if (pilih == "A" && cara == "A")
    {
        //Pendeklarasian
        int i; //i = deklarasi untuk perulangan for
        bool flag;
        string cari_data;
        string umur, berat, harga;
        
        cout<<"Masukkan Nama Sapi yang ingin Anda cari : ";
        cin>>cari_data;
        cout<<"=========================================================================="<<endl;

        //Perintah untuk membuka file txt
        myFile.open("Data_Sapi.txt");
        for (i = 0; i < 10; i++)
        {
            //Perintah untuk membaca seluruh isi di dalam file txt
            getline(myFile, Sapi[i].nama, ',');
            getline(myFile, umur, ',');
            getline(myFile, berat, ',');
            getline(myFile, harga, '\n');
            if (Sapi[i].nama == cari_data)
            {
                flag = true;
                break;
            }
        }
        if (flag == 1)
        {
            cout<<"Nama "<<cari_data<<" ditemukan pada Sapi nomor "<<i+1<<endl;
            cout<<"\nNama     : "<<Sapi[i].nama<<endl;
            cout<<"Umur     : "<<Sapi[i].umur<<" Tahun"<<endl;
            cout<<"Berat    : "<<Sapi[i].berat<<" Kg"<<endl;
            cout<<"Harga    : Rp. "<<Sapi[i].harga<<endl;
        }
        else
        {
            cout<<"=========================================================================="<<endl;
            cout<<"Mohon Maaf Nama Sapi yang Anda Cari Tidak Ada"<<endl;
        }
        cout<<"=========================================================================="<<endl;

        //Perintah untuk menutup file txt
        myFile.close();
    }
    else if (pilih == "A" && cara == "B")
    {
        //Pendeklarasian
        int cari_data, posisi, awal, akhir;
        string umur, berat, harga;
        bool berhenti = false;

        cout<<"Tuliskan Harga Tanpa Kata Rp ! [16000000]"<<endl;
        cout<<"Masukkan Harga Sapi yang ingin Anda cari : ";
        cin>>cari_data;
        cout<<"=========================================================================="<<endl; 
        awal = 0;  
        akhir = 5 - 1;  

        //Perintah untuk membuka file txt
        myFile.open("Data_Sapi.txt");
        for (i = 0; i < 10; i++)
        {
            //Perintah untuk membaca seluruh isi di dalam file txt
            getline(myFile, Sapi[i].nama, ',');
            getline(myFile, umur, ',');
            getline(myFile, berat, ',');
            getline(myFile, harga, '\n');
        }
        //Perintah untuk menutup file txt
        myFile.close();
        
        //Pemanggilan Fungsi atau Prosedur void rumus_pengurutan_searching_harga_sapi
        rumus_pengurutan_searching_harga_sapi();

        while(berhenti != true) 
        { 
            posisi = (((cari_data - Sapi[awal].harga) * (akhir - awal)) / (Sapi[akhir].harga - Sapi[awal].harga) + awal); 
            
            if(Sapi[posisi].harga == cari_data) 
            { 
                cout<<"Harga Sapi sebesar Rp. "<<cari_data<<" ditemukan pada Sapi nomor "<<posisi+1<<endl;
                cout<<"\nNama     : "<<Sapi[posisi].nama<<endl;
                cout<<"Umur     : "<<Sapi[posisi].umur<<" Tahun"<<endl;
                cout<<"Berat    : "<<Sapi[posisi].berat<<" Kg"<<endl;
                cout<<"Harga    : Rp. "<<Sapi[posisi].harga<<endl;
                berhenti = true; 
            }
            else if(Sapi[posisi].harga < cari_data) 
            { 
                awal = posisi + 1; 
            }
            else 
            { 
                cout<<"=========================================================================="<<endl;
                cout<<"Mohon Maaf Harga Sapi yang Anda Cari Tidak Ada"<<endl;
                berhenti = true; 
            } 
            cout<<"=========================================================================="<<endl;
        }
        //Perintah untuk menutup file txt
        myFile.close();
    }
    else if (pilih == "B" && cara == "A")
    {
        //Pendeklarasian
        int i; //i = deklarasi untuk perulangan for
        bool flag;
        string cari_data;
        string umur, berat, harga;
        
        cout<<"Masukkan Nama Kambing yang ingin Anda cari : ";
        cin>>cari_data;
        cout<<"=========================================================================="<<endl;

        //Perintah untuk membuka file txt
        myFile.open("Data_Kambing.txt");
        for (i = 0; i < 10; i++)
        {
            //Perintah untuk membaca seluruh isi di dalam file txt
            getline(myFile, Kambing[i].nama, ',');
            getline(myFile, umur, ',');
            getline(myFile, berat, ',');
            getline(myFile, harga, '\n');
            if (Kambing[i].nama == cari_data)
            {
                flag = true;
                break;
            }
        }
        if (flag == 1)
        {
            cout<<"Nama "<<cari_data<<" ditemukan pada Kambing nomor "<<i+1<<endl;
            cout<<"\nNama     : "<<Kambing[i].nama<<endl;
            cout<<"Umur     : "<<Kambing[i].umur<<" Tahun"<<endl;
            cout<<"Berat    : "<<Kambing[i].berat<<" Kg"<<endl;
            cout<<"Harga    : Rp. "<<Kambing[i].harga<<endl;
        }
        else
        {
            cout<<"=========================================================================="<<endl;
            cout<<"Mohon Maaf Nama Kambing yang Anda Cari Tidak Ada"<<endl;
        }
        cout<<"=========================================================================="<<endl;
    }
    else if (pilih == "B" && cara == "B")
    {
        int cari_data, posisi, awal, akhir;
        string umur, berat, harga;
        bool berhenti = false;

        cout<<"Tuliskan Harga Tanpa Kata Rp ! [16000000]"<<endl;
        cout<<"Masukkan Harga Kambing yang ingin Anda cari : ";
        cin>>cari_data;
        cout<<"=========================================================================="<<endl; 
        awal = 0;  
        akhir = 5 - 1;  

        //Perintah untuk membuka file txt
        myFile.open("Data_Sapi.txt");
        for (i = 0; i < 10; i++)
        {
            //Perintah untuk membaca seluruh isi di dalam file txt
            getline(myFile, Sapi[i].nama, ',');
            getline(myFile, umur, ',');
            getline(myFile, berat, ',');
            getline(myFile, harga, '\n');
        }
        //Perintah untuk menutup file txt
        myFile.close();

        //Pemanggilan Fungsi atau Prosedur void rumus_pengurutan_searching_harga_kambing
        rumus_pengurutan_searching_harga_kambing();

        while(berhenti != true) 
        { 
            posisi =(((cari_data - Kambing[awal].harga) * (akhir-awal)) / (Kambing[akhir].harga - Kambing[awal].harga) + awal); 
            
            if(Kambing[posisi].harga == cari_data) 
            { 
                cout<<"Harga Kambing sebesar Rp. "<<cari_data<<" ditemukan pada Kambing nomor "<<posisi+1<<endl;
                cout<<"\nNama     : "<<Kambing[posisi].nama<<endl;
                cout<<"Umur     : "<<Kambing[posisi].umur<<" Tahun"<<endl;
                cout<<"Berat    : "<<Kambing[posisi].berat<<" Kg"<<endl;
                cout<<"Harga    : Rp. "<<Kambing[posisi].harga<<endl;
                berhenti = true; 
            }
            else if(Kambing[posisi].harga < cari_data) 
            { 
                awal = posisi + 1; 
            }
            else 
            { 
                cout<<"=========================================================================="<<endl;
                cout<<"Mohon Maaf Harga Kambing yang Anda Cari Tidak Ada"<<endl;
                berhenti = true; 
            } 
            cout<<"=========================================================================="<<endl;
        } 
        //Perintah untuk menutup file txt
        myFile.close();
    }
    else 
    {
        cout<<"=========================================================================="<<endl;
        cout<<"Mohon Maaf Pilihan yang Anda Masukkan Tidak Tersedia"<<endl;
        cout<<"=========================================================================="<<endl;
    }
    cout<<"Tekan Enter untuk Kembali ke Menu ";

    //Untuk memberi jeda pada program
    getch();

    //Untuk membersihkan atau menghapus hasil sebelumnya agar tidak penuh 
    //pada layar windows
    system("cls");
}

//Prosedur atau Fungsi untuk menghitung rumus nama sapi dengan menggunakan Metode Bubble Sort
//dan secara Ascending
void rumus_bubble_sort_ASC_nama_sapi(int a, sapi Sapi[5])
{
    //Pendeklarasian
    int i, j, l; //i, j, l, dan a = deklarasi untuk perulangan for

    //temp digunakan sebagai tempat penyimpanan sementara saat proses menukar data berlangsung
    sapi temp;
    for (i = 0; i < a; i++)
    {
        for (j = i + 1; j < a; j++)
        {
            for (l = 0; l < 5; l++)
            {
                if (Sapi[i].nama[l] < Sapi[j].nama[l])
                {
                    break;
                }
                else if (Sapi[i].nama[l] > Sapi[j].nama[l])
                {
                    temp = Sapi[i];
                    Sapi[i] = Sapi[j];
                    Sapi[j] = temp;
                    break;
                }
            }
        }
    }
}

//Prosedur atau Fungsi untuk menghitung rumus nama kambing dengan menggunakan Metode Bubble Sort
//dan secara Ascending
void rumus_bubble_sort_ASC_nama_kambing(int a, kambing Kambing[5])
{
    //Pendeklarasian
    int i, j, l; //i, j, l, dan a = deklarasi untuk perulangan for
    
    //temp digunakan sebagai tempat penyimpanan sementara saat proses menukar data berlangsung
    kambing temp;
    for (i = 0; i < a; i++)
    {
        for (j = i + 1; j < a; j++)
        {
            for (l = 0; l < 5; l++)
            {
                if (Kambing[i].nama[l] < Kambing[j].nama[l])
                {
                    break;
                }
                else if (Kambing[i].nama[l] > Kambing[j].nama[l])
                {
                    temp = Kambing[i];
                    Kambing[i] = Kambing[j];
                    Kambing[j] = temp;
                    break;
                }
            }
        }
    }
}

//Prosedur atau Fungsi untuk menghitung rumus nama sapi dengan menggunakan Metode Bubble Sort
//dan secara Descending
void rumus_bubble_sort_DSC_nama_sapi(int a, sapi Sapi[5])
{
    //Pendeklarasian
    int i, j, l; //i, j, l, dan a = deklarasi untuk perulangan for

    //temp digunakan sebagai tempat penyimpanan sementara saat proses menukar data berlangsung
    sapi temp;
    for (i = 5; i > a; i--)
    {
        for (j = i - 1; j > a; j--)
        {
            for (l = 5; l > 0; l--)
            {
                if (Sapi[i].nama[l] > Sapi[j].nama[l])
                {
                    break;
                }
                else if (Sapi[i].nama[l] < Sapi[j].nama[l])
                {
                    temp = Sapi[i];
                    Sapi[i] = Sapi[j];
                    Sapi[j] = temp;
                    break;
                }
            }
        }
    }
}

//Prosedur atau Fungsi untuk menghitung rumus nama kambing dengan menggunakan Metode Bubble Sort
//dan secara Descending
void rumus_bubble_sort_DSC_nama_kambing(int a, kambing Kambing[5])
{
    //Pendeklarasian
    int i, j, l; 

    //temp digunakan sebagai tempat penyimpanan sementara saat proses menukar data berlangsung
    kambing temp;
    for (i = 5; i > a; i--)
    {
        for (j = i - 1; j > a; j--)
        {
            for (l = 5; l > 0; l--)
            {
                if (Kambing[i].nama[l] > Kambing[j].nama[l])
                {
                    break;
                }
                else if (Kambing[i].nama[l] < Kambing[j].nama[l])
                {
                    temp = Kambing[i];
                    Kambing[i] = Kambing[j];
                    Kambing[j] = temp;
                    break;
                }
            }
        }
    }
}

//Prosedur atau Fungsi untuk menampilkan pilihan menu tampilan data secara "Sorting"
void baca_file_sorting()
{
    //Pendeklarasian
    int i = 0; //i = deklarasi untuk perulangan for
    string pilih, cara, metode;

    cout<<"Silahkan Pilih Data Hewan yang ingin diurutkan"<<endl;
    pilih_hewan(); //Pemanggilan Fungsi atau Prosedur void pilih_hewan

    cout<<"Masukkan Pilihan Data [A/B] : ";
    cin>>pilih;
    cout<<"=========================================================================="<<endl;

    cout<<"Silahkan Pilih Cara Pengurutan"<<endl;
    jenis_sort(); //Pemanggilan Fungsi atau Prosedur void jenis_sort

    cout<<"Lakukan Pengurutan Berdasarkan ... ";
    cin>>cara;
    cout<<"=========================================================================="<<endl;

    cout<<"Silahkan Pilih Metode Pengurutan"<<endl;
    urutan(); //Pemanggilan Fungsi atau Prosedur void urutan

    cout<<"Masukkan Pilihan Metode : ";
    cin>>metode;
    cout<<"=========================================================================="<<endl;
    if (pilih == "A" && cara == "A" && metode == "A")
    {
        //Pendeklarasian
        int i; //i = deklarasi untuk perulangan for
        int ubah;
        char jumlah[5];
        string umur, berat, harga;

        cout<<"Masukkan Jumlah Data yang ingin diurut : ";
        cin>>jumlah;
        cout<<"=========================================================================="<<endl;

        //atoi untuk mengubah tipe data char ke dalam integer
        ubah = atoi (jumlah);

        //Perintah untuk membuka file txt
        myFile.open("Data_Sapi.txt");
        for (i = 0; i < 10; i++)
        {
            //Perintah untuk membaca seluruh isi di dalam file txt
            getline(myFile, Sapi[i].nama, ',');
            getline(myFile, umur, ',');
            getline(myFile, berat, ',');
            getline(myFile, harga, '\n');
        }
        //Perintah untuk menutup file txt
        myFile.close();

        //Pemanggilan Fungsi atau Prosedur void rumus_bubble_sort_ASC_nama_sapi
        rumus_bubble_sort_ASC_nama_sapi(ubah, Sapi);

        for (i = 0; i < ubah; i++)
        {
            cout<<"Sapi Nomor "<<i+1<<endl;
            cout<<"Nama     : "<<Sapi[i].nama<<endl;
            cout<<"Umur     : "<<Sapi[i].umur<<" Tahun"<<endl;
            cout<<"Berat    : "<<Sapi[i].berat<<" Kg"<<endl;
            cout<<"Harga    : Rp. "<<Sapi[i].harga<<endl;
            cout<<endl;
        }

        //Perintah untuk membuka file txt dan menghapus seluruh isi file, serta menuliskan kembali dengan
        //data baru
        myFile.open ("Data_Sapi.txt", ios::trunc | ios::out);
        for (i = 0; i < ubah; i++)
        {
            //Perintah untuk menyimpan seluruh data yang telah tertulis ke dalam file txt
            myFile << Sapi[i].nama << "," << Sapi[i].umur << "," << Sapi[i].berat << "," << Sapi[i].harga << endl;
        }
        cout<<"=========================================================================="<<endl;

        //Perintah untuk menutup file txt
        myFile.close();
    }
    else if (pilih == "A" && cara == "A" && metode == "B")
    {
        //Pendeklarasian
        int i; //i = deklarasi untuk perulangan for
        int ubah, urut;
        string umur, berat, harga;
        char jumlah[5];
        urut = 0;

        cout<<"Masukkan Jumlah Data yang ingin diurut : ";
        cin>>jumlah;
        cout<<"=========================================================================="<<endl;

        //atoi untuk mengubah tipe data char ke dalam integer
        ubah = atoi (jumlah);

        //Perintah untuk membuka file txt
        myFile.open("Data_Sapi.txt");
        for (i = 0; i < 10; i++)
        {
            //Perintah untuk membaca seluruh isi di dalam file txt
            getline(myFile, Sapi[i].nama, ',');
            getline(myFile, umur, ',');
            getline(myFile, berat, ',');
            getline(myFile, harga, '\n');
        }
        //Perintah untuk menutup file txt
        myFile.close();

        //Pemanggilan Fungsi atau Prosedur void rumus_bubble_sort_DSC_nama_sapi
        rumus_bubble_sort_DSC_nama_sapi(ubah, Sapi);

        for (i = ubah - 1; i > 0 - 1; i--)
        {
            cout<<"Sapi Nomor "<<urut+1<<endl;
            urut++;
            cout<<"Nama     : "<<Sapi[i].nama<<endl;
            cout<<"Umur     : "<<Sapi[i].umur<<" Tahun"<<endl;
            cout<<"Berat    : "<<Sapi[i].berat<<" Kg"<<endl;
            cout<<"Harga    : Rp. "<<Sapi[i].harga<<endl;
            cout<<endl;
        }
        
        //Perintah untuk membuka file txt dan menghapus seluruh isi file, serta menuliskan kembali dengan
        //data baru
        myFile.open ("Data_Sapi.txt", ios::trunc | ios::out);
        for (i = ubah - 1; i > 0 - 1; i--)
        {
            //Perintah untuk menyimpan seluruh data yang telah tertulis ke dalam file txt
            myFile << Sapi[i].nama << "," << Sapi[i].umur << "," << Sapi[i].berat << "," << Sapi[i].harga << endl;
        }
        cout<<"=========================================================================="<<endl;
        myFile.close();
    }
    else if (pilih == "A" && cara == "B" && metode == "A")
    {
        //Pendeklarasian
        int i, j; //i dan j = deklarasi untuk perulangan for
        int tukar, ubah;
        string umur, berat, harga;
        char jumlah[10];
        int ukuran = 10;

        cout<<"Masukkan Jumlah Sapi seluruhnya di dalam data : ";
        cin>>jumlah;
        cout<<"=========================================================================="<<endl;

        //atoi untuk mengubah tipe data char ke dalam integer
        ubah = atoi (jumlah);

        //Perintah untuk membuka file txt
        myFile.open("Data_Sapi.txt");
        for (i = 0; i < 10; i++)
        {
            //Perintah untuk membaca seluruh isi di dalam file txt
            getline(myFile, Sapi[i].nama, ',');
            getline(myFile, umur, ',');
            getline(myFile, berat, ',');
            getline(myFile, harga, '\n');
        }
        //Perintah untuk menutup file txt
        myFile.close();

        for (i = 0; i < 5; i++)
        {
            for(j = 0; j < 5 - i - 1; j++)
            {
                if(Sapi[j].umur > Sapi[j+1].umur)
                {
                    tukar = Sapi[j].umur;
                    Sapi[j].umur = Sapi[j+1].umur;
                    Sapi[j+1].umur = tukar;
                }
            }
        }
        for (i = 0; i < 5; i++)
        {
            cout<<"Sapi Nomor "<<i+1<<endl;
            cout<<"Nama     : "<<Sapi[i].nama<<endl;
            cout<<"Umur     : "<<Sapi[i].umur<<" Tahun"<<endl;
            cout<<"Berat    : "<<Sapi[i].berat<<" Kg"<<endl;
            cout<<"Harga    : Rp. "<<Sapi[i].harga<<endl;
            cout<<endl;
        }

        //Perintah untuk membuka file txt dan menghapus seluruh isi file, serta menuliskan kembali dengan
        //data baru
        myFile.open ("Data_Sapi.txt", ios::trunc | ios::out);
        for (i = 0; i < ubah; i++)
        {
            //Perintah untuk menyimpan seluruh data yang telah tertulis ke dalam file txt
            myFile << Sapi[i].nama << "," << Sapi[i].umur << "," << Sapi[i].berat << "," << Sapi[i].harga << endl;
        }
        cout<<"=========================================================================="<<endl;

        //Perintah untuk menutup file txt
        myFile.close();
    }
    else if (pilih == "A" && cara == "B" && metode == "B")
    {
        //Pendeklarasian
        int i, j; //i dan j = deklarasi untuk perulangan for
        int tukar, ubah, ukuran, urut;
        string umur, berat, harga;
        char jumlah[10];
        ukuran = 10;
        urut = 0;

        cout<<"Masukkan Jumlah Sapi seluruhnya di dalam data : ";
        cin>>jumlah;
        cout<<"=========================================================================="<<endl;

        //atoi untuk mengubah tipe data char ke dalam integer
        ubah = atoi (jumlah);

        //Perintah untuk membuka file txt
        myFile.open("Data_Sapi.txt");
        for (i = 0; i < 5; i++)
        {
            //Perintah untuk membaca seluruh isi di dalam file txt
            getline(myFile, Sapi[i].nama, ',');
            getline(myFile, umur, ',');
            getline(myFile, berat, ',');
            getline(myFile, harga, '\n');
        }
        //Perintah untuk menutup file txt
        myFile.close();

        for (i = 5; i > 0; i--)
        {
            for(j = 5; j > 0; j--)
            {
                if(Sapi[j].umur < Sapi[j-1].umur)
                {
                    tukar = Sapi[j].umur;
                    Sapi[j].umur = Sapi[j-1].umur;
                    Sapi[j-1].umur = tukar;
                }
            }
        }
        for (i = ubah - 1; i > 0 - 1; i--)
        {
            cout<<"Sapi Nomor "<<urut+1<<endl;
            urut++;
            cout<<"Nama     : "<<Sapi[i].nama<<endl;
            cout<<"Umur     : "<<Sapi[i].umur<<" Tahun"<<endl;
            cout<<"Berat    : "<<Sapi[i].berat<<" Kg"<<endl;
            cout<<"Harga    : Rp. "<<Sapi[i].harga<<endl;
            cout<<endl;
        }

        //Perintah untuk membuka file txt dan menghapus seluruh isi file, serta menuliskan kembali dengan
        //data baru
        myFile.open ("Data_Sapi.txt", ios::trunc | ios::out);
        for (i = ubah - 1; i > 0 - 1; i--)
        {
            //Perintah untuk menyimpan seluruh data yang telah tertulis ke dalam file txt
            myFile << Sapi[i].nama << "," << Sapi[i].umur << "," << Sapi[i].berat << "," << Sapi[i].harga << endl;
        }
        cout<<"=========================================================================="<<endl;

        //Perintah untuk membuka file txt
        myFile.close();
    }
    else if (pilih == "B" && cara == "A" && metode == "A")
    {
        //Pendeklarasian
        int i; //i = deklarasi untuk perulangan for
        int ubah;
        char jumlah[5];
        string umur, berat, harga;

        cout<<"Masukkan Jumlah Data yang ingin diurut : ";
        cin>>jumlah;
        cout<<"=========================================================================="<<endl;

        //atoi untuk mengubah tipe data char ke dalam integer
        ubah = atoi (jumlah);

        //Perintah untuk membuka file txt
        myFile.open("Data_Kambing.txt");
        for (i = 0; i < 10; i++)
        {
            //Perintah untuk membaca seluruh isi di dalam file txt
            getline(myFile, Kambing[i].nama, ',');
            getline(myFile, umur, ',');
            getline(myFile, berat, ',');
            getline(myFile, harga, '\n');
        }
        //Perintah untuk menutup file txt
        myFile.close();

        //Pemanggilan Fungsi atau Prosedur void rumus_bubble_sort_ASC_nama_kambing
        rumus_bubble_sort_ASC_nama_kambing(ubah, Kambing);

        for (i = 0; i < ubah; i++)
        {
            cout<<"Kambing Nomor "<<i+1<<endl;
            cout<<"Nama     : "<<Kambing[i].nama<<endl;
            cout<<"Umur     : "<<Kambing[i].umur<<" Tahun"<<endl;
            cout<<"Berat    : "<<Kambing[i].berat<<" Kg"<<endl;
            cout<<"Harga    : Rp. "<<Kambing[i].harga<<endl;
            cout<<endl;
        }

        //Perintah untuk membuka file txt dan menghapus seluruh isi file, serta menuliskan kembali dengan
        //data baru
        myFile.open ("Data_Kambing.txt", ios::trunc | ios::out);
        for (i = 0; i < ubah; i++)
        {
            //Perintah untuk menyimpan seluruh data yang telah tertulis ke dalam file txt
            myFile << Kambing[i].nama << "," << Kambing[i].umur << "," << Kambing[i].berat << "," << Kambing[i].harga << endl;
        }
        cout<<"=========================================================================="<<endl;

        //Perintah untuk menutup file txt
        myFile.close();
    }
    else if (pilih == "B" && cara == "A" && metode == "B")
    {
        //Pendeklarasian
        int i; //i = deklarasi untuk perulangan for
        int ubah, urut;
        string umur, berat, harga;
        char jumlah[5];
        urut = 0;

        cout<<"Masukkan Jumlah Data yang ingin diurut : ";
        cin>>jumlah;
        cout<<"=========================================================================="<<endl;

        //atoi untuk mengubah tipe data char ke dalam integer
        ubah = atoi (jumlah);

        //Perintah untuk membuka file txt
        myFile.open("Data_Kambing.txt");
        for (i = 0; i < 10; i++)
        {
            //Perintah untuk membaca seluruh isi di dalam file txt
            getline(myFile, Kambing[i].nama, ',');
            getline(myFile, umur, ',');
            getline(myFile, berat, ',');
            getline(myFile, harga, '\n');
        }
        //Perintah untuk menutup file txt
        myFile.close();

        //Pemanggilan Fungsi atau Prosedur void rumus_bubble_sort_DSC_nama_kambing
        rumus_bubble_sort_DSC_nama_kambing(ubah, Kambing);

        for (i = ubah - 1; i > 0 - 1; i--)
        {
            cout<<"Kambing Nomor "<<urut+1<<endl;
            urut++;
            cout<<"Nama     : "<<Kambing[i].nama<<endl;
            cout<<"Umur     : "<<Kambing[i].umur<<" Tahun"<<endl;
            cout<<"Berat    : "<<Kambing[i].berat<<" Kg"<<endl;
            cout<<"Harga    : Rp. "<<Kambing[i].harga<<endl;
            cout<<endl;
        }
        
        //Perintah untuk membuka file txt dan menghapus seluruh isi file, serta menuliskan kembali dengan
        //data baru
        myFile.open ("Data_Kambing.txt", ios::trunc | ios::out);
        for (i = ubah - 1; i > 0 - 1; i--)
        {
            //Perintah untuk menyimpan seluruh data yang telah tertulis ke dalam file txt
            myFile << Kambing[i].nama << "," << Kambing[i].umur << "," << Kambing[i].berat << "," << Kambing[i].harga << endl;
        }
        cout<<"=========================================================================="<<endl;

        //Perintah untuk menutup file txt
        myFile.close();
    }
    else if (pilih == "B" && cara == "B" && metode == "A")
    {
        //Pendeklarasian
        int i, j; //i dan j = deklarasi untuk perulangan for
        int tukar, ubah;
        string umur, berat, harga;
        char jumlah[10];
        int ukuran = 10;

        cout<<"Masukkan Jumlah Kambing seluruhnya di dalam data : ";
        cin>>jumlah;
        cout<<"=========================================================================="<<endl;

        //atoi untuk mengubah tipe data char ke dalam integer
        ubah = atoi (jumlah);

        //Perintah untuk membuka file txt
        myFile.open("Data_Kambing.txt");
        for (i = 0; i < 10; i++)
        {
            //Perintah untuk membaca seluruh isi di dalam file txt
            getline(myFile, Kambing[i].nama, ',');
            getline(myFile, umur, ',');
            getline(myFile, berat, ',');
            getline(myFile, harga, '\n');
        }

        //Perintah untuk menutup file txt
        myFile.close();

        for (i = 0; i < 5; i++)
        {
            for(j = 0; j < 5 - i - 1; j++)
            {
                if(Kambing[j].umur > Kambing[j+1].umur)
                {
                    tukar = Kambing[j].umur;
                    Kambing[j].umur = Kambing[j+1].umur;
                    Kambing[j+1].umur = tukar;
                }
            }
        }
        for (i = 0; i < 5; i++)
        {
            cout<<"Kambing Nomor "<<i+1<<endl;
            cout<<"Nama     : "<<Kambing[i].nama<<endl;
            cout<<"Umur     : "<<Kambing[i].umur<<" Tahun"<<endl;
            cout<<"Berat    : "<<Kambing[i].berat<<" Kg"<<endl;
            cout<<"Harga    : Rp. "<<Kambing[i].harga<<endl;
            cout<<endl;
        }

        //Perintah untuk membuka file txt dan menghapus seluruh isi file, serta menuliskan kembali dengan
        //data baru
        myFile.open ("Data_Kambing.txt", ios::trunc | ios::out);
        for (i = 0; i < ubah - 1; i++)
        {
            //Perintah untuk menyimpan seluruh data yang telah tertulis ke dalam file txt
            myFile << Kambing[i].nama << "," << Kambing[i].umur << "," << Kambing[i].berat << "," << Kambing[i].harga << endl;
        }
        cout<<"=========================================================================="<<endl;

        //Perintah untuk menutup file txt
        myFile.close();
    }
    else if (pilih == "B" && cara == "B" && metode == "B")
    {
        //Pendeklarasian
        int i, j; //i dan j = deklarasi untuk perulangan for
        int tukar, ubah;
        string umur, berat, harga;
        char jumlah[10];
        int ukuran = 10;
        int urut = 0;

        cout<<"Masukkan Jumlah Kambing seluruhnya di dalam data : ";
        cin>>jumlah;
        cout<<"=========================================================================="<<endl;

        //atoi untuk mengubah tipe data char ke dalam integer
        ubah = atoi (jumlah);

        //Perintah untuk membuka file txt
        myFile.open("Data_Kambing.txt");
        for (i = 0; i < 5; i++)
        {
            //Perintah untuk membaca seluruh isi di dalam file txt
            getline(myFile, Kambing[i].nama, ',');
            getline(myFile, umur, ',');
            getline(myFile, berat, ',');
            getline(myFile, harga, '\n');
        }
        //Perintah untuk menutup file txt
        myFile.close();

        for (i = 5; i > 0; i--)
        {
            for(j = 5; j > 0; j--)
            {
                if(Kambing[j].umur < Kambing[j-1].umur)
                {
                    tukar = Kambing[j].umur;
                    Kambing[j].umur = Kambing[j-1].umur;
                    Kambing[j-1].umur = tukar;
                }
            }
        }
        for (i = ubah - 1; i > 0 - 1; i--)
        {
            cout<<"Kambing Nomor "<<urut+1<<endl;
            urut++;
            cout<<"Nama     : "<<Kambing[i].nama<<endl;
            cout<<"Umur     : "<<Kambing[i].umur<<" Tahun"<<endl;
            cout<<"Berat    : "<<Kambing[i].berat<<" Kg"<<endl;
            cout<<"Harga    : Rp. "<<Kambing[i].harga<<endl;
            cout<<endl;
        }

        //Perintah untuk membuka file txt dan menghapus seluruh isi file, serta menuliskan kembali dengan
        //data baru
        myFile.open ("Data_Kambing.txt", ios::trunc | ios::out);
        for (i = ubah - 1; i > 0 - 1; i--)
        {
            //Perintah untuk menyimpan seluruh data yang telah tertulis ke dalam file txt
            myFile << Kambing[i].nama << "," << Kambing[i].umur << "," << Kambing[i].berat << "," << Kambing[i].harga << endl;
        }
        cout<<"=========================================================================="<<endl;

        //Perintah untuk menutup file txt
        myFile.close();
    }
    else 
    {
        cout<<"Mohon Maaf Pilihan yang Anda Masukkan Tidak Tersedia"<<endl;
        cout<<"=========================================================================="<<endl;
    }
    cout<<"Tekan Enter untuk Kembali ke Menu ";
    
    //Untuk memberi jeda pada program
    getch();

    //Untuk membersihkan atau menghapus hasil sebelumnya agar tidak penuh 
    //pada layar windows
    system("cls");
}

//Prosedur atau Fungsi untuk menampilkan pilihan menu utama "Menampilkan Data"
void baca_file_utama()
{
    //Pendeklarasian
    string mode, pilihan;

    cout<<"Silahkan Pilih Mode Tampilan Data"<<endl;
    mode_tampilan(); //Pemanggilan Fungsi atau Prosedur void mode_tampilan

    cout<<"Masukkan Pilihan Mode : ";
    cin>>mode;
    cout<<"=========================================================================="<<endl;
    if (mode == "A")
    {
         //Pemanggilan Fungsi atau Prosedur void baca_file_searching
        baca_file_searching();
    }
    else if (mode == "B")
    {
        //Pemanggilan Fungsi atau Prosedur void baca_file_sorting
        baca_file_sorting();
    }
    else 
    {
        cout<<"=========================================================================="<<endl;
        cout<<"Mohon Maaf Pilihan Mode yang Anda Masukkan Tidak Tersedia"<<endl;
        cout<<"=========================================================================="<<endl;
    }
    cout<<"Tekan Enter untuk Kembali ke Menu ";
    
    //Untuk memberi jeda pada program
    getch();

    //Untuk membersihkan atau menghapus hasil sebelumnya agar tidak penuh 
    //pada layar windows
    system("cls");
}

//Prosedur atau Fungsi untuk menampilkan pilihan menu utama "Mengedit Data"
void edit_file()
{
    //Pendeklarasian
    int i; //i = deklarasi untuk perulangan for
    int edit, ubah;
    string pilihan, nama_sapi, nama_kambing;
    string umur, berat, harga;
    char jumlah[10];

    pilih_hewan(); //Pemanggilan Fungsi atau Prosedur void pilih_hewan
    cout<<"Masukkan Pilihan Hewan [A/B] : ";
    cin>>pilihan;
    cout<<"=========================================================================="<<endl;
    if (pilihan == "A")
    {
        //Pemanggilan Fungsi atau Prosedur void baca_file_sapi
        baca_file_sapi();
        cout<<"Masukkan Jumlah Sapi seluruhnya di dalam data : ";
        cin>>jumlah;
        cout<<"=========================================================================="<<endl;
        cout<<"Masukkan Nama Sapi yang ingin diperbarui : ";
        cin>>nama_sapi;
        cout<<"--------------------------------------------------------------------------"<<endl;

        //atoi untuk mengubah tipe data char ke dalam integer
        ubah = atoi (jumlah);

        //Perintah untuk membuka file txt
        myFile.open("Data_Sapi.txt");
        for (i = 0; i < 10; i++)
        {
            //Perintah untuk membaca seluruh isi file txt
            getline(myFile, Sapi[i].nama, ',');
            getline(myFile, umur, ',');
            getline(myFile, berat, ',');
            getline(myFile, harga, '\n');
        }
        //Perintah untuk menutup file txt
        myFile.close();

        for (i = 0; i < 10; i++)
        {
            if (nama_sapi == Sapi[i].nama)
            {
                cout<<"Nama     : ";
                cin>>Sapi[i].nama;fflush(stdin);
                cout<<"Umur     : ";
                cin>>Sapi[i].umur;fflush(stdin);
                cout<<"Berat    : ";
                cin>>Sapi[i].berat;fflush(stdin);
                cout<<"Harga    : ";
                cin>>Sapi[i].harga;fflush(stdin);
                cout<<"=========================================================================="<<endl;
                cout<<"                          Data Berhasil Diperbarui                        "<<endl;
                cout<<"=========================================================================="<<endl;
            }
        }
        //Perintah untuk membuka file txt dan menghapus isi file, serta menuliskan kembali dengan
        //data baru
        myFile.open("Data_Sapi.txt", ios::trunc | ios::out);
        for (i = 0; i < ubah; i++)
        {
            //Perintah untuk menyimpan data ke dalam file txt
            myFile << Sapi[i].nama << "," << Sapi[i].umur << "," << Sapi[i].berat << "," << Sapi[i].harga << endl;
        }
        //Perintah untuk menutup file txt
        myFile.close();
    }
    else if (pilihan == "B")
    {
        //Pemanggilan Fungsi atau Prosedur void baca_file_kambing
        baca_file_kambing();
        cout<<"Masukkan Jumlah Kambing seluruhnya di dalam data : ";
        cin>>jumlah;
        cout<<"=========================================================================="<<endl;
        cout<<"Masukkan Nama Kambing yang ingin diperbarui : ";
        cin>>nama_kambing;
        cout<<"--------------------------------------------------------------------------"<<endl;

        //atoi untuk mengubah tipe data char ke dalam integer
        ubah = atoi (jumlah);

        //Perintag untuk membuka file txt
        myFile.open("Data_Kambing.txt");
        for (i = 0; i < 10; i++)
        {
            //Perintah untuk membaca seluruh isi file txt
            getline(myFile, Kambing[i].nama, ',');
            getline(myFile, umur, ',');
            getline(myFile, berat, ',');
            getline(myFile, harga, '\n');
        }
        //Perintah untuk menutup file txt
        myFile.close();

        for (i = 0; i < 10; i++)
        {
            if (nama_kambing == Kambing[i].nama)
            {
                cout<<"Nama     : ";
                cin>>Kambing[i].nama;fflush(stdin);
                cout<<"Umur     : ";
                cin>>Kambing[i].umur;fflush(stdin);
                cout<<"Berat    : ";
                cin>>Kambing[i].berat;fflush(stdin);
                cout<<"Harga    : ";
                cin>>Kambing[i].harga;fflush(stdin);
                cout<<"=========================================================================="<<endl;
                cout<<"                          Data Berhasil Diperbarui                        "<<endl;
                cout<<"=========================================================================="<<endl;
            }
        }
        //Perintah untuk membuka file txt dan menghapus isi file, serta menuliskan kembali dengan
        //data baru
        myFile.open("Data_Kambing.txt", ios::trunc | ios::out);
        for (i = 0; i < ubah; i++)
        {
            //Perintah untuk menyimpan data ke dalam file txt
            myFile << Kambing[i].nama << "," << Kambing[i].umur << "," << Kambing[i].berat << "," << Kambing[i].harga << endl;
        }
        //Perintah untuk menutup file txt
        myFile.close();
    } 
    else
    {
        cout<<"=========================================================================="<<endl;
        cout<<"Mohon Maaf Data Hewan yang Anda Pilih Tidak Tersedia"<<endl;
        cout<<"=========================================================================="<<endl;
    }
    cout<<"Tekan Enter untuk Kembali ke Menu ";
    
    //Untuk memberi jeda pada program
    getch();

    //Untuk membersihkan atau menghapus hasil sebelumnya agar tidak penuh 
    //pada layar windows
    system("cls");
}

//Prosedur atau Fungsi untuk menampilkan pilihan menu utama "Menghapus Data"
void hapus_file()
{
    //Pendeklarasian
    int i, j; //i dan j = deklarasi untuk perulangan for
    int status, ubah, ukuran;
    string pilihan, cara, jenis, nama_sapi, nama_kambing;
    string umur, berat, harga;
    char namafile[20];
    char jumlah[10];
    ukuran = 10;
    
    pilih_hewan(); //Pemanggilan Fungsi atau Prosedur void pilih_hewan
    cout<<"Masukkan Pilihan Hewan [A/B] : ";
    cin>>pilihan;
    cout<<"=========================================================================="<<endl;

    jenis_hapus(); //Pemanggilan Fungsi atau Prosedur void jenis_hapus
    cout<<"Masukkan Pilihan Cara Hapus [A/B] : ";
    cin>>cara;
    cout<<"=========================================================================="<<endl;

    if (pilihan == "A" && cara == "A")
    {
        mode_hapus_isi(); //Pemanggilan Fungsi atau Prosedur void mode_hapus_isi
        cout<<"Masukkan Pilihan Jenis Penghapusan Data [A/B] : ";
        cin>>jenis;
        cout<<"=========================================================================="<<endl;
        if (jenis == "A")
        {
            //Perintah untuk membuka file txt dan menuslikannya
            myFile.open("Data_Sapi.txt", ios::out);
            if (!myFile.is_open())
            {
                //Perintah untuk membuka file txt dan menghapus isi file tersebut
                myFile.open("Data_Sapi.txt", ios::trunc);
                myFile.close(); //Perintah untuk menutup file txt
            }       
            cout<<"Sukses... Seluruh Data Berhasil Terhapus"<<endl;
            cout<<"=========================================================================="<<endl;

            //Perintah untuk menutup file txt
            myFile.close();
        }
        else if (jenis == "B")
        {
            //Pemanggilan Fungsi atau Prosedur void baca_file_sapi
            baca_file_sapi();
            cout<<"Masukkan Jumlah Sapi seluruhnya di dalam data : ";
            cin>>jumlah;
            cout<<"=========================================================================="<<endl;
            cout<<"Masukkan Nama Sapi yang ingin dihapus : ";
            cin>>nama_sapi;
            cout<<"=========================================================================="<<endl;

            //atoi untuk mengubah tipe data char ke dalam integer
            ubah = atoi (jumlah);

            //Perintah untuk membuka file txt
            myFile.open("Data_Sapi.txt");
            for (i = 0; i < ukuran; i++)
            {
                //Perintah untuk membaca seluruh isi file txt
                getline(myFile, Sapi[i].nama, ',');
                getline(myFile, umur, ',');
                getline(myFile, berat, ',');
                getline(myFile, harga, '\n');
            }
            //Perintah untuk menutup file txt
            myFile.close();

            for (i = 0; i < ukuran; i++)
            {
                if (nama_sapi == Sapi[i].nama)
                {
                    for (int j = i; j < 10-1; j++)
                    {
                        Sapi[j].nama = Sapi[j+1].nama;
                        Sapi[j].umur = Sapi[j+1].umur;
                        Sapi[j].berat = Sapi[j+1].berat;
                        Sapi[j].harga = Sapi[j+1].harga;
                    }
                    ukuran--;
                    break;
                }
            }
            //Perintah untuk membuka file txt dan menghapus isi dari file tersebut, serta menuliskan kembali
            //dengan dta baru
            myFile.open("Data_Sapi.txt", ios::trunc | ios::out);
            for (i = 0; i < ubah - 1; i++)
            {
                //Perintah untuk menyimpan data ke dalam file txt
                myFile << Sapi[i].nama << "," << Sapi[i].umur << "," << Sapi[i].berat << "," << Sapi[i].harga << endl;
            }
            //Perintah untuk menutup file txt
            myFile.close();

            cout<<"Sukses... Data Berhasil Terhapus"<<endl;
            cout<<"=========================================================================="<<endl;
        }
    }
    else if (pilihan == "A" && cara == "B")
    {
        cout<<"Tuliskan Nama File Eksternal lengkap dengan formatnya"<<endl;
        cout<<"[Contoh : Biodata_Sapi.txt]"<<endl;
        cout<<"\nMasukkan Nama File Eksternal Sapi yang ingin dihapus : ";
        cin>>namafile;
        cout<<"=========================================================================="<<endl;
        status = remove(namafile);
        if (status == 0)
        {
            cout<<"Sukses... File Eksternal Berhasil Terhapus"<<endl;
        }
        else
        {
            cout<<"Mohon Maaf File Eksternal Tidak Dapat Ditemukan"<<endl;
        }
        cout<<"=========================================================================="<<endl;
    }
    else if (pilihan == "B" && cara == "A")
    {
        //Pemanggilan Fungsi atau Prosedur mode_hapus_isi
        mode_hapus_isi();
        cout<<"Masukkan Pilihan Jenis Penghapusan Data : ";
        cin>>jenis;
        cout<<"=========================================================================="<<endl;
        if (jenis == "A")
        {
            //Perintah untuk membuka file txt dan menuliskannya
            myFile.open("Data_Kambing.txt", ios::out);
            if (!myFile.is_open())
            {
                //Perintah untuk membuka file txt dan menghapus isi file tersebut
                myFile.open("Data_Kambing.txt", ios::trunc);
                myFile.close();
            }       
            cout<<"Sukses... Seluruh Data Berhasil Terhapus"<<endl;
            cout<<"=========================================================================="<<endl;
            myFile.close();
        }
        else if (jenis == "B")
        {
            //Pemanggilan Fungsi atau Prosedur void baca_file_kambing
            baca_file_kambing();
            cout<<"Masukkan Jumlah Kambing seluruhnya di dalam data : ";
            cin>>jumlah;
            cout<<"=========================================================================="<<endl;
            cout<<"Masukkan Nama Kambing yang ingin dihapus : ";
            cin>>nama_kambing;
            cout<<"=========================================================================="<<endl;

            //atoi untuk mengubah tipe data char ke dalam integer
            ubah = atoi (jumlah);

            myFile.open("Data_Kambing.txt");
            for (i = 0; i < ukuran; i++)
            {
                //Perintah untuk membaca seluruh isi file txt
                getline(myFile, Kambing[i].nama, ',');
                getline(myFile, umur, ',');
                getline(myFile, berat, ',');
                getline(myFile, harga, '\n');
            }
            //Perintah untuk menutup file txt
            myFile.close();

            for (i = 0; i < ukuran; i++)
            {
                if (nama_kambing == Kambing[i].nama)
                {
                    for (j = i; j < 10-1; j++)
                    {
                        Kambing[j].nama = Kambing[j+1].nama;
                        Kambing[j].umur = Kambing[j+1].umur;
                        Kambing[j].berat = Kambing[j+1].berat;
                        Kambing[j].harga = Kambing[j+1].harga;
                    }
                    ukuran--;
                    break;
                }
            }
            //Perintah untuk membuka file txt dan menghapus isi dari file tersebut, serta menuliskan kembali
            //dengan dta baru
            myFile.open("Data_Kambing.txt", ios::trunc | ios::out);
            for (i = 0; i < ubah - 1; i++)
            {
                //Perintah untuk menyimpan data ke dalam file txt
                myFile << Kambing[i].nama << "," << Kambing[i].umur << "," << Kambing[i].berat << "," << Kambing[i].harga << endl;
            }
            //Perintah untuk menutup file txt
            myFile.close();
            cout<<"Sukses... Data Berhasil Terhapus"<<endl;
            cout<<"=========================================================================="<<endl;
        }
    }
    else if (pilihan == "B" && cara == "B")
    {
        cout<<"Tuliskan Nama File Eksternal lengkap dengan formatnya"<<endl;
        cout<<"[Contoh : Biodata_Kambing.txt]"<<endl;
        cout<<"\nMasukkan Nama File Eksternal Kambing yang ingin dihapus : ";
        cin>>namafile;
        cout<<"=========================================================================="<<endl;
        status = remove(namafile);
        if (status == 0)
        {
            cout<<"Sukses... File Eksternal Berhasil Terhapus"<<endl;
        }
        else
        {
            cout<<"Mohon Maaf File Eksternal Tidak Dapat Ditemukan"<<endl;
        }
        cout<<"=========================================================================="<<endl;
    }
    cout<<"Tekan Enter untuk Kembali ke Menu ";
    
    //Untuk memberi jeda pada program
    getch();

    //Untuk membersihkan atau menghapus hasil sebelumnya agar tidak penuh 
    //pada layar windows
    system("cls");
}

int main()
{
    //Pendeklarasian
    int jawab;

    //Pemanggilan Fungsi atau Prosedur void intro
    intro();

    //Label yang digunakan sebagai tempat pengulangan menu ketika dipanggil dengan
    //menggunakan perintah goto
    kembali:

    //Pemanggilan Fungsi atau Prosedur void pilih_menu
    pilih_menu();
    cout<<"\nMasukkan Pilihan Menu [1, 2, 3, 4, 5 atau 6] : ";
    cin>>jawab;
    cout<<"=========================================================================="<<endl;
    if (jawab == 1)
    {
        //Pemanggilan Fungsi atau Prosedur void isi_file
        isi_file();

        //Perintah untuk melompat ke label "kembali" yang telah dideklarasikan di awal
        goto kembali;
    }
    else if (jawab == 2)
    {
        //Pemanggilan Fungsi atau Prosedur void tambah_isi_file
        tambah_isi_file();

        //Perintah untuk melompat ke label "kembali" yang telah dideklarasikan di awal
        goto kembali;
    }
    else if (jawab == 3)
    {
        //Pemanggilan Fungsi atau Prosedur void baca_file_utama
        baca_file_utama();

        //Perintah untuk melompat ke label "kembali" yang telah dideklarasikan di awal
        goto kembali;
    }
    else if (jawab == 4)
    {
        //Pemanggilan Fungsi atau Prosedur void edit_file
        edit_file();

        //Perintah untuk melompat ke label "kembali" yang telah dideklarasikan di awal
        goto kembali;
    }
    else if (jawab == 5)
    {
        //Pemanggilan Fungsi atau Prosedur void hapus_file
        hapus_file();

        //Perintah untuk melompat ke label "kembali" yang telah dideklarasikan di awal
        goto kembali;
    }
    else if (jawab == 6)
    {
        cout<<"                               Terima Kasih                               "<<endl;
        cout<<"==========================================================================";

        //Perintah untuk keluar dari program
        exit(0);
    }
    else 
    {
        cout<<"Mohon Maaf Pilihan Menu Tidak Tersedia"<<endl;
        cout<<"=========================================================================="<<endl;

        //Perintah untuk melompat ke label "kembali" yang telah dideklarasikan di awal
        goto kembali;
    }
    cout<<"=========================================================================="<<endl;
}
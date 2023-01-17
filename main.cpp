#include <iostream>
#include <iomanip>
using namespace std;

// array yang digunakan untuk menyimpan data penduduk
// setiap baris berisi [nama, alamat, status pajak, status pernikahan]
string penduduk[100][4] = {{"agus", "03/04", "ya", "menikah"},
                           {"ferguson", "05/01", "tidak", "belum kawin"},
                           {"levine", "03/01", "ya", "belum kawin"},
                           {"babatunde", "04/01", "ya", "menikah"},
                           {"june", "03/01", "ya", "menikah"},
                           {"alex", "03/04", "tidak", "belum kawin"},
                           {"einstein", "03/04", "ya", "menikah"}};

// fungsi untuk mencari data penduduk berdasarkan nama atau alamat
void searching(string bil[][4], int panjang, int value)
{
    string key;
    int no = 0;

    // jika value ==0, pencarian dilakukan berdasarkan nama
    // jika value ==1, pencarian dilakukan berdasarkan alamat
    if (value == 0)
    {
        cout << "masukkan nama penduduk: ";
        cin >> key;
    }
    else
    {
        cout << "masukkan alamat penduduk(rt/rw): ";
        cin >> key;
    }
    cout << "\n\n               Data Penduduk Yang Anda Cari               \n\n";
    cout << "===============================================================\n";
    cout << "No" << setw(15) << "Nama" << setw(15) << "Alamat" << setw(15) << "Pajak" << setw(15) << "Status" << setw(15) << endl;
    cout << "===============================================================\n";
    // looping untuk mengecek setiap baris dari array penduduk
    for (int i = 0; i < panjang; i++)
    {
        // jika data yang dicari ditemukan
        if (bil[i][value] == key)
        {
            // menampilkan data yang ditemukan
            cout << no << i + 1 << setw(15) << penduduk[i][0] << setw(15) << penduduk[i][1] << setw(15) << penduduk[i][2] << setw(15) << penduduk[i][3] << endl;
        }
    }
    cout << "===============================================================\n";
}
void bubbleSortAsc(string penduduk[0][4], int panjang)
{
    string temp;
    int pass;

    cout << endl;
    for (int i = 0; i < panjang; i++)
    {
        for (int j = i + 1; j < panjang; j++)
        {
            if (penduduk[j][0][0] < penduduk[i][0][0])
            {
                temp = penduduk[i][0];
                penduduk[i][0] = penduduk[j][0];
                penduduk[j][0] = temp;
            }
        }
        pass++;
    }
}
void isiPenduduk(string penduduk[][4], int size)
{
    cout << "berapa data penduduk yang akan dimasukkan: ";
    cin >> size;
    // looping untuk mengubah isi array penduduk
    for (int i = 0; i < size; i++)
    {
        int k = i + 1;
        cout << "masukkan nama penduduk ke-" << k << ": \t";
        cin >> penduduk[i][0];
        cout << "masukkan alamat penduduk ke-" << k << "(rt/rw): \t";
        cin >> penduduk[i][1];
        cout << "masukkan status pajak penduduk ke-" << k << "(ya/tidak): \t";
        cin >> penduduk[i][2];
        cout << "masukkan status penduduk ke-" << k << "(menikah/belum menikah): \t";
        cin >> penduduk[i][3];
    }
}
// fungsi untuk mengubah satu data penduduk
void ubahData(string penduduk[][4], int panjang)
{
    string key;
    cout << "masukkan nama penduduk: ";
    cin >> key;
    for (int i = 0; i < panjang; i++)
    {
        if (penduduk[i][0] == key)
        {
            cout << "----------------------" << endl;
            cout << "masukkan nama penduduk baru"
                 << ": \t";
            cin >> penduduk[i][0];
            cout << "masukkan alamat penduduk "
                 << "(rt/rw): \t";
            cin >> penduduk[i][1];
            cout << "masukkan status pajak penduduk "
                 << "(ya/tidak): \t";
            cin >> penduduk[i][2];
            cout << "masukkan status penduduk "
                 << "(menikah/belum menikah)\t";
            cin >> penduduk[i][3];
        }
    }
}
int masukData(string penduduk[][4], int panjang)
{
    int jumlah;
    cout << "jumlah data penduduk yang akan dimasukkan: ";
    cin >> jumlah;
    for (int i = 0; i < jumlah; i++)
    {
        cout << "----------------------" << endl;
        cout << "masukkan nama penduduk "
             << ": \t";
        cin >> penduduk[panjang][0];
        cout << "masukkan alamat penduduk "
             << "(rt/rw): \t";
        cin >> penduduk[panjang][1];
        cout << "masukkan status pajak penduduk "
             << "(ya/tidak): \t";
        cin >> penduduk[panjang][2];
        cout << "masukkan status penduduk "
             << "(menikah/belum menikah):\t";
        cin >> penduduk[panjang][3];
        panjang++;
    }
    return jumlah;
}
int main()
{
    string first, value;
    string ulang = "y";
    int panjangPenduduk = 7, pilihan, no = 0;

    cout << "apakah anda akan menggunakan data yang sudah ada?(y/n)";
    cin >> first;
    if (first == "n")
    {
        isiPenduduk(penduduk, panjangPenduduk);
    }
    bubbleSortAsc(penduduk, panjangPenduduk);
    do
    {
        cout << "============== <<MENU UTAMA>> ==============\n"
             << endl;
        cout << "\t 1. Ubah Data Penduduk\n";
        cout << "\t 2. Cari Penduduk\n";
        cout << "\t 3. Masukkan Data Penduduk baru\n";
        cout << "\t 4. Tampilkan Data semua Penduduk\n";
        cout << "\t 5. Keluar dari program\n"
             << endl;
        cout << "============================================" << endl;
        cout << endl;
        cout << "masukkan pilihan anda: ";
        cin >> pilihan;

        switch (pilihan)
        {

        case 1:
            cout << "============== <<Menu Ubah Data>> ==============\n\n";
            cout << "\t 1. ubah semua data penduduk" << endl;
            cout << "\t 2. ubah satu data penduduk" << endl;
            cout << "\t 3. kembali ke menu utama\n"
                 << endl;
            cout << "================================================\n";

            cout << "Masukan Pilihan: ";
            cin >> pilihan;

            switch (pilihan)
            {
            case 1:
                isiPenduduk(penduduk, panjangPenduduk);
                bubbleSortAsc(penduduk, panjangPenduduk);
                cout << "apakah anda ingin kembali ke menu utama?(y/n)";
                cin >> ulang;
                break;
            case 2:
                ubahData(penduduk, panjangPenduduk);
                bubbleSortAsc(penduduk, panjangPenduduk);
                cout << "apakah anda ingin kembali ke menu utama?(y/n)";
                cin >> ulang;
                break;
            case 3:

                break;
            default:
                cout << "input anda salah";
                break;
            }
            break;

        case 2:
            cout << "============ <<Menu cari penduduk>> =========== \n"
                 << endl;
            cout << " \t 1. Cari berdasarkan nama" << endl;
            cout << " \t 2. Cari berdasarkan alamat" << endl;
            cout << " \t 3. Kembali ke menu utama\n"
                 << endl;
            cout << "===============================================\n"
                 << "masukkan pilihan anda: ";
            cin >> pilihan;
            switch (pilihan)
            {
            case 1:
                searching(penduduk, panjangPenduduk, 0);
                cout << "apakah anda ingin kembali ke menu utama?(y/n)";
                cin >> ulang;
                break;
            case 2:
                searching(penduduk, panjangPenduduk, 1);
                cout << "apakah anda ingin kembali ke menu utama?(y/n)";
                cin >> ulang;
                break;
            case 3:

                break;
            default:
                cout << "input anda salah";
                break;
            }

            break;
        case 3:
            panjangPenduduk += masukData(penduduk, panjangPenduduk);
            bubbleSortAsc(penduduk, panjangPenduduk);
            cout << "apakah anda ingin kembali ke menu utama?(y/n)";
            cin >> ulang;
            break;
        case 4:
            cout << "\n\n               Daftar Data Penduduk               \n\n";
            cout << "===============================================================\n";
            cout << "No" << setw(15) << "Nama" << setw(15) << "Alamat" << setw(15) << "Pajak" << setw(15) << "Status" << setw(15) << endl;
            cout << "===============================================================\n";
            // looping untuk mengecek setiap baris dari array penduduk
            for (int i = 0; i < panjangPenduduk; i++)
            {

                cout << no << i + 1 << setw(15) << penduduk[i][0] << setw(15) << penduduk[i][1] << setw(15) << penduduk[i][2] << setw(15) << penduduk[i][3] << endl;
            }
            cout << "===============================================================\n";
            cout << "apakah anda ingin kembali ke menu utama?(y/n)";
            cin >> ulang;
            break;
        case 5:
            ulang = "n";
            break;
        default:
            cout << "input anda salah";
        }
    } while (ulang == "y");
    return 0;
}

#include <iostream>
using namespace std;
string penduduk[100][4] = {{"agus", "03/04", "ya", "menikah"},
                           {"ferguson", "05/01", "tidak", "belum kawin"},
                           {"levine", "03/01", "ya", "belum kawin"},
                           {"babatunde", "04/01", "ya", "menikah"},
                           {"june", "03/01", "ya", "menikah"},
                           {"alex", "03/04", "tidak", "belum kawin"},
                           {"einstein", "03/04", "ya", "menikah"}};

void searching(string bil[][4], int panjang, int value)
{
    string key;

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
    for (int i = 0; i < panjang; i++)
    {
        if (bil[i][value] == key)
        {
            cout << "----------------------" << endl;
            cout << "nama : " << bil[i][0] << endl;
            cout << "alamat: " << bil[i][1] << endl;
            cout << "pajak: " << bil[i][2] << endl;
            cout << "status: " << bil[i][3] << endl;
        }
    }
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
            cout << "masukkan nama penduduk : "
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
    int panjangPenduduk = 7, pilihan;

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
                cout << "apakah anda ingin kembali ke menu utama?(y/n)";
                cin >> ulang;
                break;
            case 2:
                ubahData(penduduk, panjangPenduduk);
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
            cout << "apakah anda ingin kembali ke menu utama?(y/n)";
            cin >> ulang;
            break;
        case 4:
            for (int i = 0; i < panjangPenduduk; i++)
            {
                cout << "+++++++++++++++++++++++++++++ \n";
                cout << "nama:\t" << penduduk[i][0] << endl;
                cout << "alamat:\t" << penduduk[i][1] << endl;
                cout << "pajak:\t" << penduduk[i][2] << endl;
                cout << "status:\t" << penduduk[i][3] << endl;
            }
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

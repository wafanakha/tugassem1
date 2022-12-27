#include <iostream>
using namespace std;

int searching(int bil[], int key, int panjang)
{

    for (int i = 0; i < panjang; i++)
    {
        if (bil[i][0] == key)
        {
            return i;
        }
    }
    return -1;
}

void bubbleSortAsc(string a[][4], int size)
{
    string temp;
    int pass;

    cout << endl;
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (a[j][0][0] < a[i][0][0])
            {
                temp = a[i][0];
                a[i][0] = a[j][0];
                a[j][0] = temp;
            }
        }
        pass++;
    }
}
void isiPenduduk(string penduduk[][4])
{

    int size;
    cout << "berapa data penduduk yang akan dimasukkan: ";
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        int k = i + 1;
        cout << "masukkan nama penduduk ke-" << k << ": \t";
        cin >> penduduk[i][0];
        cout << "masukkan alamat penduduk ke-" << k << ": \t";
        cin >> penduduk[i][1];
        cout << "masukkan status pajak penduduk ke-" << k << "(y/n): \t";
        cin >> penduduk[i][2];
        cout << "masukkan status penduduk ke-" << k << ": \t";
        cin >> penduduk[i][3];
    }
}
int main()
{
    string first;
    int size;
    string penduduk[7][4] = {{"agus", "03/04", "ya", "menikah"},
                             {"ferguson", "05/01", "tidak", "belum kawin"},
                             {"levine", "03/01", "ya", "belum kawin"},
                             {"babatunde", "04/01", "ya", "menikah"},
                             {"june", "03/01", "ya", "menikah"},
                             {"alex", "03/04", "tidak", "belum kawin"},
                             {"einstein", "03/04", "ya", "menikah"}};
    cout << "apakah anda akan menggunakan data yang sudah ada?(y/n)";
    cin >> first;
    if (first == "n")
    {
        isiPenduduk(penduduk);
    }
    bubbleSortAsc(penduduk, 7);
    for (int i = 0; i < 7; i++)
    {
        cout << "+++++++++++++++++++++++++++++ \n";
        cout << "nama:\t" << penduduk[i][0] << endl;
        cout << "alamat:\t" << penduduk[i][1] << endl;
        cout << "pajak:\t" << penduduk[i][2] << endl;
        cout << "status:\t" << penduduk[i][3] << endl;
    }

    return 0;
}

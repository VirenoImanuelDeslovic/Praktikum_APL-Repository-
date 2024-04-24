#include <iostream>
#include <string>
#include <limits>
using namespace std;

// Struct for item characteristics
struct Karakteristik {
    string tipe_item;
};

// Struct for game items
struct itemgame {
    string nama_item;
    string fungsi_item;
    int harga_item;
    Karakteristik karakteristik; // Nested struct karakteristik
};

// Function for login
int login(int batas_login = 0) {
    string username, password;
    cout<<"Selamat Datang Di Program Pendataan Item Mobile Legends: Bang Bang\n";
    while (batas_login < 3) {
        cout<<"Silahkan Login\n";
        cout << "Masukkan Nama: ";
        cin >> username;
        cout << "Masukkan Password: ";
        cin >> password;

        if (username == "vireno" && password == "109") {
            cout<<"Anda Berhasil Login\n";
            return true;
        } else {
            cout << "Username Atau Password Anda Tidak Valid!\n";
            return login(batas_login +1); // Recursive call
        }
    }
    if (batas_login == 3) {
        cout << "Anda Telah Mencapai Batas, Program Di Berhentikan";
        return 0;
    }
    return 0;
}

// Function to add item data
void menambahkan_data_item(itemgame mobile_legends[], int& jumlah_item) {
    if (jumlah_item < 20) {
        cout << "Masukkan Nama Item: ";
        cin.ignore();
        getline(cin, mobile_legends[jumlah_item].nama_item);
        cout << "Masukkan Fungsi Item: ";
        getline(cin, mobile_legends[jumlah_item].fungsi_item);
        do {
            cout << "Masukkan Harga Item: ";
            if (cin >> mobile_legends[jumlah_item].harga_item) {
                break;
            } else {
                cout << "Harga harus berupa bilangan bulat. Silakan coba lagi." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        } while (true);
        cin.ignore();
        cout<<"Attack/Defense/Magic/Movement"<<endl;
        cout<< "Masukkan Tipe Item: ";
        getline(cin, mobile_legends[jumlah_item].karakteristik.tipe_item);
        jumlah_item++;
        cout << "Data Item Berhasil Ditambahkan\n" << endl;
    } else {
        cout << "Penyimpanan Telah Penuh, Tidak Dapat Menambahkan Data Item!!!" << endl;
    }
}

// Function to display item data
void menampilkan_data_item(itemgame mobile_legends[], int jumlah_item){
    if (jumlah_item == 0){
        cout<<"Tidak ada item yang tersedia\n"<<endl;
    } else {
        for(int i = 0;  i < jumlah_item; ++i){
            cout<<"\n"<<endl;
            cout<< i + 1<<". Nama item: "<< mobile_legends[i].nama_item<<endl;
            cout<<"Fungsi Item: "<< mobile_legends[i].fungsi_item<<endl;
            cout<<"Harga item: "<< mobile_legends[i].harga_item <<" Gold"<<endl;
            cout<<"Tipe: "<< mobile_legends[i].karakteristik.tipe_item <<endl;
        }
    }
}

// Function to modify item data
void merubah_data_item(itemgame mobile_legends[], int jumlah_item, int index_item){
    if (jumlah_item == 0) {
        cout<<"Tidak ada item yang tersedia\n"<<endl;
    } else {
        cout<<"Masukkan index item yang ingin diubah: ";
        do {
            if (!(cin >> index_item)) {
                cout << "Inputan anda tidak valid, harus menggunakan angka : ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else {
                if (index_item >= 0 && index_item <= jumlah_item){
                    cout<<"Masukkan Nama Baru Item: ";
                    cin.ignore();
                    getline (cin, mobile_legends[index_item-1].nama_item);
                    cout<<"Masukkan Fungsi Baru Item: ";
                    getline(cin, mobile_legends[index_item-1].fungsi_item);
                    do {
                        cout << "Masukkan Harga Baru Item: ";
                        if (cin >> mobile_legends[index_item-1].harga_item) {
                            break;
                        } else {
                            cout << "Harga harus berupa bilangan bulat. Silakan coba lagi." << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        }
                    } while (true);
                    cin.ignore();
                    cout<<"Attack/Defense/Magic/Movement"<<endl;
                    cout<<"Masukkan Tipe Baru Item: ";
                    getline(cin, mobile_legends[index_item-1].karakteristik.tipe_item);
                    cout<<"item telah diupdate"<<endl;
                    break; // Exit loop after valid input
                } else{
                    cout<<"index yang anda input tidak valid"<<endl;
                }
            }
        } while (true);
    }    
}

// Function to delete item data
void hapus_data_item(itemgame mobile_legends[], int& jumlah_item, int index_item) {
    if (jumlah_item == 0) {
        cout << "Tidak ada item yang tersedia!" << endl;
    } else {
        do {
            cout << "Masukkan Index Item Yang Ingin Dihapus: ";
            if (!(cin >> index_item)) {
                cout << "Inputan anda tidak valid, harus menggunakan angka!" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else {
                if (index_item >= 1 && index_item <= jumlah_item) {
                    for (int i = index_item - 1; i < jumlah_item - 1; ++i) {
                        mobile_legends[i] = mobile_legends[i + 1];
                    }
                    jumlah_item--;
                    cout << "Data Item Telah Berhasil Dihapus." << endl;
                    break;
                } else {
                    cout << "Index Yang Anda Input Tidak Valid" << endl;
                }
            }
        } while (true);
    }
}

// selection sort
void sort_nama_item(itemgame mobile_legends[], int jumlah_item) {
    for (int i = 0; i < jumlah_item - 1; ++i) {
        int min_index = i;
        for (int j = i + 1; j < jumlah_item; ++j) {
            if (mobile_legends[j].nama_item < mobile_legends[min_index].nama_item) {
                min_index = j;
            }
        }
        if (min_index != i) {
            swap(mobile_legends[i], mobile_legends[min_index]);
        }
    }
}

// binary search
int search_nama_item(itemgame mobile_legends[], int jumlah_item, string nama_cari) {
    int low = 0;
    int high = jumlah_item - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (mobile_legends[mid].nama_item == nama_cari) {
            return mid;
        } else if (mobile_legends[mid].nama_item < nama_cari) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

void cari_nama_item(itemgame mobile_legends[], int jumlah_item){
    string nama_cari;
    cout << "Masukkan nama item yang ingin dicari: ";
    cin.ignore();
    getline(cin, nama_cari);
    sort_nama_item(mobile_legends, jumlah_item); // Sorting by name
    int hasil_cari = search_nama_item(mobile_legends, jumlah_item, nama_cari);
    if (hasil_cari != -1) {
        cout << "\n"<<endl;
        cout << "Item ditemukan pada indeks " << hasil_cari + 1 << endl;
        cout << "Nama item: " << mobile_legends[hasil_cari].nama_item << endl;
        cout << "Fungsi item: " << mobile_legends[hasil_cari].fungsi_item << endl;
        cout << "Harga item: " << mobile_legends[hasil_cari].harga_item << " Gold" << endl;
        cout << "Tipe: " << mobile_legends[hasil_cari].karakteristik.tipe_item << endl;
    } else {
        cout << "Item tidak ditemukan." << endl;
    }
    
}

// insertion sort
void sort_harga_item(itemgame mobile_legends[], int jumlah_item) {
    int i, j;
    for (i = 1; i < jumlah_item; ++i) {
        itemgame key = mobile_legends[i];
        j = i - 1;
        while (j >= 0 && mobile_legends[j].harga_item < key.harga_item) { // Ubah tanda '>' menjadi '<'
            mobile_legends[j + 1] = mobile_legends[j];
            j = j - 1;
        }
        mobile_legends[j + 1] = key;
    }
}

// interpolation search
int search_harga_item(itemgame mobile_legends[], int jumlah_item, int harga_cari) {
    int low = 0;
    int high = jumlah_item - 1;
    while (low <= high && harga_cari <= mobile_legends[low].harga_item && harga_cari >= mobile_legends[high].harga_item) {
        if (low == high) {
            if (mobile_legends[low].harga_item == harga_cari)
                return low;
            return -1;
        }
        int pos = low + (((double)(high - low) / (mobile_legends[high].harga_item - mobile_legends[low].harga_item)) * (harga_cari - mobile_legends[high].harga_item));
        if (mobile_legends[pos].harga_item == harga_cari)
            return pos;
        if (mobile_legends[pos].harga_item < harga_cari)
            high = pos - 1; // Kurangi pos karena urutan descending
        else
            low = pos + 1; // Tambahkan pos karena urutan descending
    }
    return -1;
}

void cari_harga_item (itemgame mobile_legends[], int jumlah_item){
    int harga_cari;
    cout << "Masukkan harga item yang ingin dicari: ";
    cin >> harga_cari;
    sort_harga_item(mobile_legends, jumlah_item); // Sorting by price
    int hasil_cari = search_harga_item(mobile_legends, jumlah_item, harga_cari);
    if (hasil_cari != -1) {
        cout << "\n"<<endl;
        cout << "Item ditemukan pada indeks " << hasil_cari + 1 << endl;
        cout << "Nama item: " << mobile_legends[hasil_cari].nama_item << endl;
        cout << "Fungsi item: " << mobile_legends[hasil_cari].fungsi_item << endl;
        cout << "Harga item: " << mobile_legends[hasil_cari].harga_item << " Gold" << endl;
        cout << "Tipe: " << mobile_legends[hasil_cari].karakteristik.tipe_item << endl;
    } else {
        cout << "Item dengan harga " << harga_cari << " tidak ditemukan." << endl;
    }
}

// Bubble sort
void sort_tipe_item(itemgame mobile_legends[], int jumlah_item) {
    for (int i = 0; i < jumlah_item - 1; ++i) {
        for (int j = 0; j < jumlah_item - i - 1; ++j) {
            if (mobile_legends[j].karakteristik.tipe_item > mobile_legends[j + 1].karakteristik.tipe_item) {
                swap(mobile_legends[j], mobile_legends[j + 1]);
            }
        }
    }
}

// Sequential search
int search_tipe_item(itemgame mobile_legends[], int jumlah_item, string tipe_cari) {
    for (int i = 0; i < jumlah_item; ++i) {
        if (mobile_legends[i].karakteristik.tipe_item == tipe_cari) {
            return i;
        }
    }
    return -1;
}

void cari_tipe_item(itemgame mobile_legends[], int jumlah_item){
    string tipe_cari;
    cout << "Masukkan tipe item yang ingin dicari: ";
    cin.ignore();
    getline(cin, tipe_cari);
    int hasil_cari = search_tipe_item(mobile_legends, jumlah_item, tipe_cari);
    if (hasil_cari != -1) {
        cout << "\n"<<endl;
        cout << "Item ditemukan pada indeks " << hasil_cari + 1 << endl;
        cout << "Nama item: " << mobile_legends[hasil_cari].nama_item << endl;
        cout << "Fungsi item: " << mobile_legends[hasil_cari].fungsi_item << endl;
        cout << "Harga item: " << mobile_legends[hasil_cari].harga_item << " Gold" << endl;
        cout << "Tipe: " << mobile_legends[hasil_cari].karakteristik.tipe_item << endl;
    } else {
        cout << "Item tidak ditemukan." << endl;
    }
}

// Main function
int main (){
    if (!login()) {
        return 0;
    }
    itemgame mobile_legends[20]{
        {"Winter Truncheon", "Tidak Bergerak Dan Tidak dapat Diserang", 1910, {"Magic"}},
        {"Blade of despair", "Meningkatkan Damage Jika Musuh Sekarat",3010, {"Attack"}},
        {"Immortality", "Hidup Kembali Setelah Mati", 2120, {"Defense"}},
    };
    int index_item, pilih, jumlah_item = 3;
    int* p_jumlah_item = &jumlah_item; // Pointer to jumlah_item variable
    int* p_index_item = &index_item; // Pointer to index_item variable
    
    do {
        cout<<"\n===Menu Utama===\n";
        cout<<"1. Tambahkan Data Item\n";
        cout<<"2. Tampilkan Data Item\n";
        cout<<"3. Ubah Data Item\n";
        cout<<"4. Hapus Data Item\n";
        cout<<"5. Cari Item berdasarkan Nama\n";
        cout<<"6. Cari Item berdasarkan Harga\n";
        cout<<"7. Cari Item Berdasarkan Tipe\n";
        cout<<"8. Log Out\n";
        cout<<"Silahkan Pilih Menu Yang Anda Inginkan(1/2/3/4/5/6/7/8): ";
        if (!(cin>>pilih)){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } 
        switch (pilih){
            case 1:{
                menambahkan_data_item(mobile_legends, *p_jumlah_item);
                break;
            }
            case 2:{
                menampilkan_data_item(mobile_legends, *p_jumlah_item);
                break;
            }
            case 3:{
                merubah_data_item(mobile_legends, *p_jumlah_item, *p_index_item);
                break;    
            }
            case 4:{
                hapus_data_item(mobile_legends, *p_jumlah_item, *p_index_item);
                break;
            }
            case 5:{
                cari_nama_item(mobile_legends, jumlah_item);
                break;
            }
            case 6:{
                cari_harga_item (mobile_legends, jumlah_item);
                break;
            }
            case 7:{
                cari_tipe_item(mobile_legends,jumlah_item);
                break;
            }
            case 8:{
                cout<<"Anda Berhasil Log Out."<<endl;
                cout<<"Terima Kasih Telah Berkunjung."<<endl;
                break;
            }
            default:{
                cout<<"Inputan Anda Tidak Valid!,Silahkan Pilih 1/2/3/4/5/6/7.\n";
            }
        }
    } while(pilih != 8);

    return 0;
}


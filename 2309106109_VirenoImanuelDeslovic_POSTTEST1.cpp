#include <iostream>
#include <string>
using namespace std;

int login() {
    string username, password;
    int login = 0;
    cout<<"selamat datang di program konveris suhu\n";
    while (login < 3) {
        cout<<"silahkan login\n";
        cout << "masukkan nama: ";
        cin >> username;
        cout << "masukkan password: ";
        cin >> password;

        if (username == "vireno" && password == "109") {
            cout << "selamat datang di program\n";
            return true;
        } else {
            cout << "username atau password anda tidak valid!\n";
            login++;
        }
    }
    if (login == 3) {
        cout << "anda telah mencapai batas, progam berhenti";
        return 0;
    }
    return 0;
}

int konversi() {
    string pilih_suhu, pilih_konversi;
    double celcius, kelvin, reamur, fahrenheit;

    cout << "\n";
    cout << "Silahkan pilih suhu yang ingin dikonversi\n";
    cout << "1. Celcius\n";
    cout << "2. Kelvin\n";
    cout << "3. Reamur\n";
    cout << "4. Fahrenheit\n";
    cout << "Pilih suhu sesuai angka: ";
    cin >> pilih_suhu;

    if (pilih_suhu == "1") {
        cout << "\n";
        cout << "silahkan pilih agar menjadi suhu yang diinginkan\n";
        cout << "1. Kelvin\n";
        cout << "2. Reamur\n";
        cout << "3. Fahrenheit\n";
        cout << "pilih suhu sesuai angka: ";
        cin >> pilih_konversi;
        if (pilih_konversi == "1") {
            cout << "masukkan nilai suhu: ";
            cin >> celcius;
            kelvin = celcius + 273.15;
            cout << celcius << " derajat celcius di konversi menjadi = " << kelvin << " derajat kelvin\n";
        } else if (pilih_konversi == "2") {
            cout << "masukkan nilai suhu: ";
            cin >> celcius;
            reamur = 4.0 / 5 * celcius;
            cout << celcius << " derajat celcius di konversi menjadi = " << reamur << " derajat reamur\n";
        } else if (pilih_konversi == "3") {
            cout << "masukkan nilai suhu: ";
            cin >> celcius;
            fahrenheit = (9.0 / 5 * celcius) + 32;
            cout << celcius << " derajat celcius di konversi menjadi = " << fahrenheit << " derajat fahrenheit\n";
        } else {
            cout << "inputan tidak valid";
        }
        return 0;
    } else if (pilih_suhu == "2") {
        cout << "\n";
        cout<<"silahkan pilih agar menjadi suhu yang diinginkan\n";
        cout<<"1. Celcius\n";
        cout<<"2. reamur\n";
        cout<<"3. Fahrenheit\n";
        cout<<"pilih suhu sesuai angka";
        cin>>pilih_konversi;
        if (pilih_konversi == "1"){
            cout<<"masukkan nilai suhu";
            cin>>kelvin;
            celcius = kelvin - 273.15;
            cout<<kelvin<<"derajat kelvin di konversi menjadi = "<< celcius<< "derajat celcius\n";
        } else if ( pilih_konversi == "2"){
            cout<<"masukkan nilai suhu";
            cin>>kelvin;
            reamur = 4 / 5 * ( kelvin - 273.15 );
            cout<<kelvin<<"derajat kelvin di konversi menjadi = "<< reamur<< "derajat reamur\n";
        } else if ( pilih_konversi == "3") {
            cout<<"masukkan nilai suhu";
            cin>>kelvin;
            fahrenheit = (kelvin * 9 / 5 ) - 459.67;
            cout<<fahrenheit<<"derajat fahrenheit di konversi menjadi = "<< fahrenheit<< "derajat fahrenheit\n";
        } else {
            cout<<"inputan tidak valid";
        }
        return 0;
    } else if (pilih_suhu == "3") {
        cout << "\n";
        cout << "silahkan pilih agar menjadi suhu yang diinginkan\n";
        cout << "1. celcius\n";
        cout << "2. kelvin\n";
        cout << "3. reamur\n";
        cout << "pilih suhu sesuai angka: ";
        cin >> pilih_konversi;
        if (pilih_konversi == "1") {
            cout << "masukkan nilai suhu: ";
            cin >> fahrenheit;
            celcius = 5.0 / 9 * (fahrenheit - 32);
            cout << fahrenheit << " derajat fahrenheit di konversi menjadi = " << celcius << " derajat celcius\n";
        } else if (pilih_konversi == "2") {
            cout << "masukkan nilai suhu: ";
            cin >> fahrenheit;
            kelvin = (fahrenheit + 459.67) * 5.0 / 9;
            cout << fahrenheit << " derajat fahrenheit di konversi menjadi = " << kelvin << " derajat kelvin\n";
        } else if (pilih_konversi == "3") {
            cout << "masukkan nilai suhu: ";
            cin >> fahrenheit;
            reamur = 4.0 / 9 * (fahrenheit - 32);
            cout << fahrenheit << " derajat fahrenheit di konversi menjadi = " << reamur << " derajat reamur\n";
        } else {
            cout << "inputan tidak valid";
        }
        return 0;
    } else if (pilih_suhu == "4") {
        cout << "\n";
        cout << "silahkan pilih agar menjadi suhu yang diinginkan\n";
        cout << "1. Celcius\n";
        cout << "2. reamur\n";
        cout << "3. Fahrenheit\n";
        cout << "pilih suhu sesuai angka: ";
        cin >> pilih_konversi;
        if (pilih_konversi == "1") {
            cout << "masukkan nilai suhu: ";
            cin >> kelvin;
            celcius = kelvin - 273.15;
            cout << kelvin << " derajat kelvin di konversi menjadi = " << celcius << " derajat celcius\n";
        } else if (pilih_konversi == "2") {
            cout << "masukkan nilai suhu: ";
            cin >> kelvin;
            reamur = 4.0 / 5 * (kelvin - 273.15);
            cout << kelvin << " derajat kelvin di konversi menjadi = " << reamur << " derajat reamur\n";
        } else if (pilih_konversi == "3") {
            cout << "masukkan nilai suhu: ";
            cin >> kelvin;
            fahrenheit = (kelvin * 9 / 5) - 459.67;
            cout << kelvin << " derajat kelvin di konversi menjadi = " << fahrenheit << " derajat fahrenheit\n";
        } else {
            cout << "inputan tidak valid";
        }
        return 0;
    }
}

int main() {
    string lanjut;
    if (!login()) {
        return 0;
    }
    do {
        konversi();
        cout << "\n";
        cout << "Apakah ingin melanjutkan program (silahkan tekan y/Y untuk lanjut): ";
        cin >> lanjut;
    } while (lanjut == "y" || lanjut == "Y");
    cout << "Terima kasih telah mencoba program ini\n";
}

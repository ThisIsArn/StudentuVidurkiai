#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

struct Studentas {
    string vardas;
    string pavarde;
    vector<int> namuDarbai;
    int egzaminas;
};

int main() {
    vector<Studentas> studentai;
    char darStudentas = 't';

    while (darStudentas == 't' || darStudentas == 'T') {
        Studentas studentas;
    
        cout << "Iveskite studento varda: ";
        cin >> studentas.vardas;

        cout << "Iveskite studento pavarde: ";
        cin >> studentas.pavarde;

        int pazymys;
        char pasirinkimas;

        do {
            cout << "Iveskite namu darbu pazymi: ";
           cin >> pazymys;

           studentas.namuDarbai.push_back(pazymys);

           cout << "Ar norite ivesti dar viena pazymi? (t/n): ";
           cin >> pasirinkimas;

        } while (pasirinkimas == 't' || pasirinkimas == 'T');
    
        cout << "Iveskite egzamino pazymi: ";
        cin >> studentas.egzaminas;

        studentai.push_back(studentas);

        cout << "Ar norite ivesti dar viena studenta? (t/n): ";
        cin >> darStudentas;
    }

    cout << "\nVardas          Pavarde         Galutinis (Vid.)     Galutinis (Med.)\n";
    cout << "--------------------------------------------------------------------\n";

    for (Studentas& studentas : studentai) {
        double suma = 0;

        for (int pazymys : studentas.namuDarbai) {
           suma += pazymys;
        }

        double vidurkis = suma / studentas.namuDarbai.size();

        sort(studentas.namuDarbai.begin(), studentas.namuDarbai.end());

        double mediana;
        int dydis = studentas.namuDarbai.size();

        if (dydis % 2 == 0) {
            mediana = (studentas.namuDarbai[dydis / 2 - 1] +
                       studentas.namuDarbai[dydis / 2]) / 2.0;
        }
        else {
            mediana = studentas.namuDarbai[dydis/2];
        }

        double galutinisVid = 0.5 * vidurkis + 0.5 * studentas.egzaminas;
        double galutinisMed = 0.5 * mediana + 0.5 * studentas.egzaminas;

        cout << left
             << setw(16) << studentas.vardas
             << setw(16) << studentas.pavarde
             << setw(20) << fixed << setprecision(2) << galutinisVid
             << galutinisMed << endl;
    }
    return 0;
}
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
    Studentas studentas;

    cout << "Iveskite studento varda: ";
    cin >> studentas.vardas;

    cout << "Iveskite studento pavarde: ";
    cin >> studentas.pavarde;

    int n;
    cout << "Kiek namu darbu pazymiu norite ivesti? ";
    cin >> n;

    cout << "Iveskite namu darbu pazymius: ";

    for (int i = 0; i < n; i++) {
        int pazymys;
        cin >> pazymys;
        studentas.namuDarbai.push_back(pazymys);
    }
    
    cout << "Iveskite egzamino pazymi: ";
    cin >> studentas.egzaminas;

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

    cout << "\nVardas          Pavarde         Galutinis (Vid.)     Galutinis (Med.)\n";
    cout << "--------------------------------------------------------------------\n";

    cout << left
         << setw(16) << studentas.vardas
         << setw(16) << studentas.pavarde
         << setw(20) << fixed << setprecision(2) << galutinisVid
         << galutinisMed << endl;
    
    return 0;
}
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

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
    double galutinis = 0.5 * vidurkis + 0.5 * studentas.egzaminas;

    cout << "\nVardas          Pavarde         Galutinis (Vid.)\n";
    cout << "------------------------------------------------\n";

    cout << left
         << setw(16) << studentas.vardas
         << setw(16) << studentas.pavarde
         << fixed << setprecision(2) << galutinis << endl;
    
    return 0;
}
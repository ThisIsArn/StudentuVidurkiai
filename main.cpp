#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <sstream>

using namespace std;

struct Studentas {
    string vardas;
    string pavarde;
    vector<int> namuDarbai;
    int egzaminas;
};

int main() {
    srand(time(nullptr));

    vector<Studentas> studentai;

    int duomenuBudas;

    cout << "Pasirinkite duomenu ivedimo buda:\n";
    cout << "1 - Ivesti studentus\n";
    cout << "2 - Nuskaityti studentus is failo\n";
    cout << "Pasirinkimas: ";
    cin >> duomenuBudas;

    if (duomenuBudas == 1) {
        char darStudentas = 't';

        while (darStudentas == 't' || darStudentas == 'T') {
            Studentas studentas;
    
            cout << "Iveskite studento varda: ";
            cin >> studentas.vardas;

            cout << "Iveskite studento pavarde: ";
            cin >> studentas.pavarde;

            int ivedimoBudas;

            cout << "\nPasirinkite pazymiu ivedimo buda:\n";
            cout << "1 - Ivesti pazymius ranka\n";
            cout << "2 - Generuoti pazymius atsitiktinai\n";
            cout << "Pasirinkimas: ";
            cin >> ivedimoBudas;

            if (ivedimoBudas == 1) {
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
            }
            else if (ivedimoBudas == 2) {
                int kiekis;

                cout << "Kiek namu darbu pazymiu sugeneruoti? ";
                cin >> kiekis;

                for (int i = 0; i < kiekis; i++) {
                    studentas.namuDarbai.push_back(rand() % 10 + 1);
                }

                studentas.egzaminas = rand() % 10 + 1;

                cout << "Sugeneruoti namu darbu pazymiai: ";

                for (int pazymys : studentas.namuDarbai) {
                    cout << pazymys << " ";
                }

                cout << "\nSugeneruotas egzamino pazymys: "
                     << studentas.egzaminas << endl;
            }
            studentai.push_back(studentas);

            cout << "Ar norite ivesti dar viena studenta? (t/n): ";
            cin >> darStudentas;
        }
    }
    else if (duomenuBudas == 2) {
        string failoPavadinimas;

        cout << "Iveskite failo pavadinima: ";
        cin >> failoPavadinimas;

        ifstream failas;
        failas.open(failoPavadinimas);

        while (!failas) {
            cout << "Nepavyko atidaryti failo. Bandykite dar karta: ";
            cin >> failoPavadinimas;

            failas.clear();
            failas.open(failoPavadinimas);
        }

        string antraste;
        getline(failas, antraste);

        stringstream ss(antraste);
        string stulpelis;
        int ndKiekis = 0;

        while (ss >> stulpelis) {
            if (stulpelis.substr(0, 2) == "ND") {
                ndKiekis++;
            }
        }

        Studentas studentas;

        while (failas >> studentas.vardas >> studentas.pavarde) {
            int pazymys;

            for (int i = 0; i < ndKiekis; i++) {
                failas >> pazymys;
                studentas.namuDarbai.push_back(pazymys);
            }

            failas >> studentas.egzaminas;

            studentai.push_back(studentas);

            studentas = Studentas();
        }

        failas.close();
    }

    sort(studentai.begin(), studentai.end(),
        [](const Studentas& a, const Studentas& b) {
            return a.pavarde < b.pavarde;
        });

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
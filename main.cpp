#include <iostream>

struct Studentas {
    int nd_kiekis,
    nd,
    vid,
    egz,
    galutinis;
    std::string vardas,
    pavarde;
};

int main () {
    std::cout << "Ivesk studento varda ir pavarde." << std::endl << "Jei jau pabaigiai vesti duomenis tiesiog spausk ENTER." << std::endl;
    std::string temp;
    Studentas A;
    while (true) {
        std::getline(std::cin, temp);
        if (!temp.empty())
        {
            int pos; // Tarpo pozicija, reikalinga tam, kad atskirti varda nuo pavardes
            pos = temp.find(" ");

            if (temp.length()>pos) { // Tikrinu ar yra ivestas vardas ir pavarde
                A.vardas = temp.substr(0,pos);
                A.pavarde = temp.substr(pos+1);
                std::cout << A.vardas << "-" << A.pavarde << std::endl;
            }
            else
                std::cout << "Kazkas netaip su tavo ivestais duomenimis!" << std::endl;
        }
        else
            break;
    }

return 0;
}

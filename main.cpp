#include "header.h"

int main () {
    vector<Studentas> A,vargsai;

    const int chosenInput = choiceOfInput(); // Pasirinkimas kaip vesti duomenis

    if (chosenInput == 1) { // Pasirinko ivesti duomenis paciam
        const int calculation = calculationChoice(); // Kaip skaiciuoti galutini pazymy
        addStudents(A,calculation);
        sortByName(A);
        printStudents(A,vargsai,calculation);
    }
    else if (chosenInput == 2) { // Pasirinko nuskaityti is failo
        readData(A,"kursiokai.txt");
        sortByName(A);
        printStudents(A,vargsai,3);
    }
    else { // Pasirinko generuoti
        string filename = "kursiokai.txt";
        generateStudents(filename, 10);
        readData(A,filename, true);
        vargsai = sortByMark(A);
        printStudents(A,vargsai,4,"vargsai.txt","kieti.txt");
    }

    return 0;
}
#include "header.h"

std::random_device rd;
std::mt19937 mt(rd());
std::uniform_int_distribution<int> range(0, 10);

int choiceOfInput () {
    cout << endl << "Kaip noretum ivesti duomenis?" << endl;
    cout << "1 - Ivesti rankiniu budu." << endl;
    cout << "2 - Nuskaityti is failo kursiokai.txt" << endl;
    cout << "3 - Sugeneruoti faila, ir nuskaityti duomenis is jo." << endl << endl;
    int choice;
    while(true){
        try {
            cin >> choice;
            if(cin.fail()){  
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                throw "Ivestas neskaicius, pabandyk dar karta: ";
            }
            else{
                if (choice < 1 or choice > 3)
                    throw wrongNumber;
                else
                    return choice;
            }
        }
        catch (string e) {
            cout << e;
        }
    }
}

int calculationChoice() {
    int tempNumber;
    cout << endl << "Kaip noretum skaiciuoti galutini pazymy?" << endl;
    cout << "1 - naudojant vidurki." << endl;
    cout << "2 - naudojant mediana." << endl << endl;

    while(true) {
        cin >> tempNumber;
        if (cin.fail()){
            cin.clear();
            cin.ignore(256, '\n');
            cout << "Gali ivesti tik skaiciu! Pabandyk dar karta: ";
        }
        else if (tempNumber < 1 or tempNumber > 2)
            cout << "Netinkamas skaicius! Pabandyk dar karta: ";
        else{
            return tempNumber;
        }
    }
}

inline bool isLetters(const string input) {
    for (size_t i = 0; i < input.size(); i++)
    {  if (! isalpha(input[i])) 
        return false;
    }
    return true;
}

inline void notNumber () {
    cout << "Gali ivesti tik skaiciu! Pabandyk dar karta: ";
    cin.clear();
    cin.ignore(256, '\n');
}

inline double average (vector<int> temp) {
    int sum = 0;
    for (int i = 0 ; i < temp.size() ; i++)
        sum += temp[i];

    return 1.0*sum/temp.size();
}

inline double median (vector<int> temp) {
    int n = temp.size();
    std::sort(temp.begin(),temp.end());

    if (n%2==0)
         return 1.0*(temp[n/2]+temp[n/2-1])/2;
    else
         return 1.0*(temp[n/2]);
}

void addStudents (vector<Studentas>& A, const int calculation) {
    int studentNumber = 0, check = 1, tempNumber;
    string tempString;
    while (check == 1){
        A.push_back(Studentas());
        cout << endl;
        cout << "Ivesk studento varda: ";
        cin >> tempString;
        while (!isLetters(tempString)) {
            cout << "Turi ivesti tik raides! Pabandyk dar karta: ";
            cin >> tempString;
        }
        A[studentNumber].SetVardas(tempString);

        cout << endl << "Ivesk studento pavarde: ";
        cin >> tempString;
        while (!isLetters(tempString)) {
            cout << "Turi ivesti tik raides! Pabandyk dar karta: ";
            cin >> tempString;
        }
        A[studentNumber].SetPavarde(tempString);

        cout << endl << "Kaip noretum ivesti studento namu darbus?" << endl;
        cout << "1 - rankiniu budu." << endl;
        cout << "2 - sugeneruoti atsitiktinius skaicius." << endl << endl;
        int homeworkInput;
        while (true) {
            cin >> tempNumber;
            if (cin.fail()){
                notNumber();
            }
            else if (tempNumber < 1 or tempNumber > 2) {
                cout << wrongNumber;
            }
            else{
                homeworkInput = tempNumber;
                break;
            }
        }

        vector<int> homeworkMark; // Namu darbu pazymiai
        if (homeworkInput == 1) { // Pasirinko ivesti rankiniu budu
            cout << endl << "Ivedinek skaicius 0-10, noredamas sustoti ivesk betkoki kita skaiciu." << endl;
            while(true) {
                cin >> tempNumber;
                if (cin.fail()){
                    notNumber();
                }
                else if (tempNumber >= 0 and tempNumber <= 10)
                    homeworkMark.push_back(tempNumber);
                else if (homeworkMark.size() < 1)
                    cout << "Turi buti bent vieno namu darbo pazymys!" << endl;
                else 
                    break;
            }
        }
        else { // Pasirinko generacija
            cout << endl << "Kiek skaiciu sugeneruoti?" << endl << endl;
            int n; // Kiek skaiciu bus generuojama
            while(true) {
                cin >> tempNumber;
                if (cin.fail()){
                    notNumber();
                }
                else if (tempNumber > 0){
                    n = tempNumber;
                    break;
                }  
                else 
                    cout << wrongNumber;
            }
            
            for (int i = 0 ; i < n ; i++) { // Skaiciu generacija
                homeworkMark.push_back(range(mt));
            }
            cout << endl << "Namu darbu pazymiai sekmingai sugeneruoti!" << endl;
        }

        int examMark;
        cout << endl << "Ivesk egzamino pazymy: ";
        while (true) {
            cin >> tempNumber;
            if (cin.fail()){
                notNumber();
            }
            else if (tempNumber < 0 or tempNumber > 10)
                cout << wrongNumber;
            else{
                examMark = tempNumber;
                break;
            }
        }

        if (calculation == 1) { // Pasirinko skaiciuoti naudojant vidurki
            A[studentNumber].SetGalutinis(0.4*average(homeworkMark)+0.6*examMark);
        }
        else {
            A[studentNumber].SetGalutinis(0.4*median(homeworkMark)+0.6*examMark);
        }

        cout << endl << "Noretum ivesti dar viena studenta?" << endl;
        cout << "1 - taip." << endl;
        cout << "2 - ne." << endl << endl;
        while (true) {
            cin >> tempNumber;
            if (cin.fail()){
                notNumber();
            }
            else if (tempNumber == 1)
                break;
            else if (tempNumber == 2){
                check = 0;
                break;
            }
            else
                cout << wrongNumber;
        }

        studentNumber++; // Ruosiamas nr kitam studentui
    }
}

void sortByName (vector<Studentas>& A) {
    for (int i=0;i<A.size();i++)
        for(int j=i;j<A.size();j++)
            if(strcmp(A[i].GetVardas().c_str(),A[j].GetVardas().c_str())>0) // Tikrina vardus
                std::swap(A[i],A[j]);
            else if (strcmp(A[i].GetVardas().c_str(),A[j].GetVardas().c_str())==0)
                if(strcmp(A[i].GetPavarde().c_str(),A[j].GetPavarde().c_str())>0)
                    std::swap(A[i],A[j]);
}

int involution (int number, int times) { // Kelimas laipsniu
    if (times!=0){
        int n=number;
        for (int i=1 ; i<times ; i++)
        n*=number;

        return n;
    }
    else return 1;
}

void generateStudents (const string filename, const int homeworks){
    cout << endl << "Kiek studentu noretum sugeneruoti?" << endl;
    cout << "1 - 10" << endl;
    cout << "2 - 100" << endl;
    cout << "3 - 1000" << endl;
    cout << "4 - 10000" << endl;
    cout << "5 - 100000" << endl << endl;

    int tempNumber;
    while (true) {
        cin >> tempNumber;
        if (cin.fail()){
            notNumber();
        }
        else if (tempNumber < 1 or tempNumber > 5) {
            cout << wrongNumber;
        }
        else{
            tempNumber = involution(10, tempNumber);
            break;
        }
    }

    ofstream toFile (filename); 
    for (int i = 0 ; i < tempNumber ; i++){
        toFile << "Vardas" << (i+1) << " " << "Pavarde" << (i+1);
        for (int i = 0 ; i < homeworks ; i++) { // Skaiciu generacija
            toFile << " " << range(mt);
        }
        toFile << endl;
    }
    toFile.close();
}

void printStudents (vector<Studentas>& A, vector<Studentas>& vargsai, const int printMethod, string poor, string cool){
    if (A.size()>0){ 
        int max_name=7, max_lastname=9; // Pradzioj zodziai Vardas ir Pavarde yra didziausi

        for (int i=0;i<A.size();i++){    // Randu ilgiausia varda ir pavarde
            if (max_name<A[i].GetVardas().length()+1)
                max_name=A[i].GetVardas().length()+1;
            if (max_lastname<A[i].GetPavarde().length()+1)
                max_lastname=A[i].GetPavarde().length()+1;
        }

        if (printMethod < 3){
            cout << std::left << std::setw(max_name+1) << endl << "Vardas" << std::setw(max_lastname+1) << "Pavarde" << std::setw(20);
            if (printMethod == 1)
                cout << "Galutinis (Vid.)" << endl;
            else
                cout << "Galutinis (Med.)" << endl;
            
            for (int i=0;i<max_name+max_lastname+20;i++)
            printf("-");
            cout << endl;
            for (int i = 0 ; i < A.size() ; i++)
            cout << std::left << std::setw(max_name+1) << A[i].GetVardas() << std::setw(max_lastname+1) <<  A[i].GetPavarde() << std::setw(20) << std::fixed << std::setprecision(2) << A[i].GetGalutinis() << endl;
        }
        else if (printMethod == 3){
            cout << std::left << std::setw(max_name+1) << endl << "Vardas" << std::setw(max_lastname+1) << "Pavarde" << std::setw(20) << "Galutinis (Vid.)" <<  std::setw(20) << "Galutinis (Mid.)" << endl;
            for (int i=0;i<max_name+max_lastname+37;i++)
            printf("-");
            cout << endl;
            for (int i = 0 ; i < A.size() ; i++)
            cout << std::left << std::setw(max_name+1) << A[i].GetVardas() << std::setw(max_lastname+1) <<  A[i].GetPavarde() << std::setw(20) << std::fixed << std::setprecision(2) << A[i].GetGalutinis() << std::setw(20) << std::fixed << std::setprecision(2) << A[i].GetGalutinis2() << endl;
        }
        else {
            ofstream vargsas (poor);
            ofstream kietas (cool);

            vector<Studentas>::size_type i = 0;
            while (i != vargsai.size()){
                vargsas << vargsai[i] << endl;
                i++;
            }
            i = 0;
            while (i != A.size()){
                kietas << A[i] << endl;
                i++;
            }

            vargsas.close();
            kietas.close();
        }
    }
}

inline bool fileExists (const string name) { //Tikrina ar failas egzistuoja
    ifstream f(name.c_str());
    return f.good();
}

void readData (vector<Studentas>& A, const string filename, bool skipCheck) {
    if(fileExists(filename)){
        string line,firstname,lastname;
        int studentNumber=0,tempNumber;

        ifstream inFile (filename);
        while(std::getline(inFile,line)){
            istringstream inLine (line);
            inLine >> firstname >> lastname;

            if ((isLetters(firstname) and isLetters(lastname)) or skipCheck){
                vector<int> mark;

                while(inLine >> tempNumber){
                    if (tempNumber >= 0 and tempNumber <= 10)
                        mark.push_back(tempNumber);
                }

                if (mark.size()>1) {
                    int examMark = mark.back(); // Paskutinis skaicius - egzamino pazymys
                    mark.erase(mark.end()-1);
                    A.push_back(Studentas());
                    A[studentNumber].SetVardas(firstname);
                    A[studentNumber].SetPavarde(lastname);
                    A[studentNumber].SetGalutinis(0.4*average(mark)+0.6*examMark);
                    A[studentNumber].SetGalutinis2(0.4*median(mark)+0.6*examMark);
                    studentNumber++;
                }

            }
        }

        if(A.size() == 0)
            cout << endl << "Failas tuscias, arba jame ivesti duomenys netinkami!" << endl;

        inFile.close();
    }
    else {
        cout << endl << "Tokio failo nera!" << endl;
    }
}

inline bool debt(const Studentas & i){
    return (i < 5);
}

vector<Studentas> sortByMark (vector<Studentas>& A){
    vector<Studentas>::iterator it = std::stable_partition(A.begin(), A.end(), debt);
    vector<Studentas> vargsai(it, A.end());
    A.erase(it, A.end());

    return vargsai;
}
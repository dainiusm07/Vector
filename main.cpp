#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <time.h>
#include <cmath>
#include <stdio.h>
#include <fstream>
#include <sstream>


struct Studentas {
    double galutinis=0; 
    double galutinis2=0; // Galutiniui saugot su mediana, kadangi skaitant is failo reikia isvesti 2 galutinius
    std::string vardas="0", // Irasiau skaicius i varda ir pavarde, kadangi taip paprasta patikrinti ar buvo faile irasyti ar ne 
    pavarde="0";
};

const std::string erroras = "Kazkas netaip su tavo ivestais duomenimis!";

bool all_letters(std::string input)
{
	for (int i = 0; i < input.length(); i++)
	{
           int uppercaseChar = toupper(input[i]); // Keicia i uppercase
            if (uppercaseChar < 'A' || uppercaseChar > 'Z') // Tikrina ar simbolis ne A-Z
            {
                if (uppercaseChar!=32) // Jei tai ne tarpas returnina false
                    return false;
            } 
	}
	return true;
};

bool is_digits(const std::string &str) // Tikrinimas ar vien tik skaiciai
{
    return std::all_of(str.begin(), str.end(), ::isdigit);
}

void convert_to_proper_format (std::string &text) {
    if(islower(text.at(0)))
        text.at(0) = toupper(text.at(0)); // Keicia pirma raide i uppercase
    for (int i=1;i<text.length();i++)
        if(isupper(text.at(i)))
            text.at(i) = tolower(text.at(i)); // Keicia likusiais i lowercase
}

void new_line () {
    std::cout<< std::endl;
};

double vidurkis (std::vector<int> temp_paz,int n){
    int sum=0;
    for (int i=0;i<n;i++)
        sum+=temp_paz[i];
    return 1.0*sum/n;
};

double mediana (std::vector<int> temp_paz,int n){
    for (int a=0;a<n-1;a++) // Rikiuoju skaicius didejimo tvarka
        for (int i=a+1;i<n;i++)
            if (temp_paz[i]<temp_paz[a])
                std::swap(temp_paz[i],temp_paz[a]);
    if (n%2==0)
         return 1.0*(temp_paz[n/2]+temp_paz[n/2-1])/2;
    else
         return 1.0*(temp_paz[n/2]);
};

void spausdinimas (int stud_nr,std::vector<Studentas> A,int vid_pasirinkimas) { 
    int max_vardas=7, max_pavarde=9; // Pradzioj zodziai Vardas ir Pavarde yra didziausi
    for (int i=0;i<=stud_nr;i++){    // Randu ilgiausia varda ir pavarde
        if (max_vardas<A[i].vardas.length()+1)
            max_vardas=A[i].vardas.length()+1;
        if (max_pavarde<A[i].pavarde.length()+1)
            max_pavarde=A[i].pavarde.length()+1;
    }
    printf("%*s", -max_vardas, "Vardas");
    printf("%*s", -max_pavarde, "Pavarde");

    int ilgis=20; // Cia bruksneliam spausdinti
    if (vid_pasirinkimas==1)
    printf("Galutinis (Vid.)\n");
    else if (vid_pasirinkimas==2)
    printf("Galutinis (Med.)\n");
    else{
       printf("Galutinis (Vid.) Galutinis (Med.)\n");
       ilgis=35;
    }

    for (int i=0;i<max_vardas+max_pavarde+ilgis;i++)
        printf("-");
    if (vid_pasirinkimas!=3) // Spausdinimas ivedus visa info rankomis
        for (int i=0;i<=stud_nr;i++){    //Spausdinu studentu info
            printf("\n%*s", -max_vardas, A[i].vardas.c_str()); //.c_str, nes kitaip printina pievas
            printf("%*s", -max_pavarde, A[i].pavarde.c_str());
            printf("%4.2f", A[i].galutinis);
        }
    else{    // Spausdinimas skaicius duomenis is failo
        int sk=0;
        while(sk!=stud_nr+1){
            if (all_letters(A[sk].vardas)==1 and all_letters(A[sk].pavarde)==1){
            printf("\n%*s", -max_vardas, A[sk].vardas.c_str()); //.c_str, nes kitaip printina pievas
            printf("%*s", -max_pavarde, A[sk].pavarde.c_str());
            printf("%-17.2f", A[sk].galutinis);
            printf("%-17.2f", A[sk].galutinis2);
            sk++;
            }
            else
                sk++;
        }
    }
}
void rikiavimas (std::vector<Studentas> A,int n){
    for (int i=0;i<=n;i++)
        for(int j=i;j<=n;j++)
            if(strcmp(A[i].vardas.c_str(),A[j].vardas.c_str())>0) // Tikrina vardus
                std::swap(A[i],A[j]);
            else if (strcmp(A[i].vardas.c_str(),A[j].vardas.c_str())==0)
                if(strcmp(A[i].pavarde.c_str(),A[j].pavarde.c_str())>0)
                    std::swap(A[i],A[j]);
            
    spausdinimas(n,A,3);
}

int main () {
    srand ( time ( NULL ));
    std::string temp;
    std::vector<Studentas> A;
    int stud_nr=-1; // Studento identifikacijos nr (-1 nes nera dar jokios stud, prasideda nuo 0)
    int ivedimo_pasirinkimas;
    new_line();

    std::cout << "Kaip noretum ivesti visus duomenis?\n1- Ivesti paciam\n2- Nuskaityti is failo kursiokai.txt" << std::endl;
    while (true){   // Laukiam kol pasirenka 1 arba 2
        std::cin>>temp;
        if (temp=="1"){
            ivedimo_pasirinkimas=1;
        break;
        }
        else if (temp=="2"){
            ivedimo_pasirinkimas=2;
        break;
        }
        else
        std::cout<< erroras << std::endl;
    }
    std::cin.ignore(); //  Kadangi i cin ieina ir \n tai reikia ignorint, nes getline susimauna tada, galit be sito pabandyt pamatysit :)

    if (ivedimo_pasirinkimas==1)
    {
        int vid_pasirinkimas;
        std::cout << "Kaip noretum skaiciuoti galutini pazymi?\n1- Naudojant vidurki\n2- Naudojant mediana" << std::endl;
        while (true){   // Laukiam kol pasirenka 1 arba 2
            std::cin>>temp;
            if (temp=="1"){
                vid_pasirinkimas=1;
            break;
            }
            else if (temp=="2"){
                vid_pasirinkimas=2;
            break;
            }
            else
            std::cout<< erroras << std::endl;
        }
        std::cin.ignore(); //  Kadangi i cin ieina ir \n tai reikia ignorint, nes getline susimauna tada, galit be sito pabandyt pamatysit :)

        while (true) {
            new_line();
            std::cout << "Ivesk " << stud_nr+2 <<" studento varda ir pavarde. (Vardenis Pavardenis)" << std::endl << "Jei jau pabaigiai vesti duomenis tiesiog spausk ENTER." << std::endl;

            std::getline(std::cin, temp);

            if (!temp.empty())
            {
                int pos = temp.find(" "); // Tarpo pozicija, reikalinga tam, kad atskirti varda nuo pavardes

                if (temp.length()-1>pos and all_letters(temp)==true) { // Tikrinu ar yra ivestas vardas ir pavarde ir nera skaiciu
                    A.push_back(Studentas()); // Pakeiciu array A dydi su kiekvienu tinkamu vardu ir pav
                    stud_nr++; // Paruosiamas nr studentui
                    A[stud_nr].vardas = temp.substr(0,pos);
                    convert_to_proper_format(A[stud_nr].vardas);
                    A[stud_nr].pavarde = temp.substr(pos+1);
                    A[stud_nr].pavarde = A[stud_nr].pavarde.substr(0,A[stud_nr].pavarde.find(" ")); // Palieka 2 pirmus zodzius jei iveda daugiau nei 2
                    convert_to_proper_format(A[stud_nr].pavarde);

                    new_line();
                    std::cout << "Kaip nori ivesti namu darbus rezultatus?\n1- Rankiniu budu\n2- Sugeneruoti automatiskai" << std::endl;
                    std::vector<int> pazymiai;
                    int sk=0; // Namu darbus kiekis
                    while(true){
                        std::cin>>temp;
                    if (temp=="1") {
                        new_line();
                        std::cout << "Ivedinek skaicius 1-10, noredamas sustoti ivesk betkoki kita skaiciu." << std::endl;
                        while(true){
                            std::cin>>temp;
                            if(is_digits(temp)==true)
                            {
                                int ivestis = std::stoi(temp);
                                if (ivestis>0 and ivestis<11){
                                    pazymiai.push_back(int());
                                    pazymiai[sk]=ivestis;
                                    sk++;
                                }
                                else {
                                    if (sk!=0)
                                        break;
                                    else
                                        std::cout << "Ivesk bent 1 skaiciu..." << std::endl;
                                }
                            } 
                            else
                                std::cout << erroras << std::endl;
                        }
                        break;
                    }
                    if (temp=="2"){
                    new_line();
                    std::cout << "Kiek skaiciu sugeneruoti?" << std::endl;
                    while(true){
                        std::cin>>temp;
                        if(is_digits(temp)==true)
                        {
                            int ivestis = std::stoi(temp);
                            if (ivestis>0){
                                for (int i=0;i<ivestis;i++){
                                    pazymiai.push_back(int());
                                    pazymiai[sk]=int(round(1+1.0*rand()/RAND_MAX*9));
                                    sk++;
                                }
                                break;
                            }
                            else {
                                if (sk!=0)
                                    break;
                                else
                                    std::cout << "Turi buti bent 1 pazymys..." << std::endl;
                            }
                        } 
                        else
                            std::cout << erroras << std::endl;
                    }
                    break;
                    }
                    else {
                        std::cin.ignore();
                        std::cin.clear();
                        std::cout << erroras << std::endl;}
                    
                    }
                    
                    new_line();
                    std::cout << "Dabar ivesk gauta egzamino pazymi " << std::endl;
                    int egz;
                    while(true){
                        std::string ivestis_string;
                        std::cin >> ivestis_string;
                        int ivestis;

                        if (is_digits(ivestis_string)==false){ // Tikrinu ar ten tik skaiciai, jei ne tai tiesiog i ivesti irasau netinkama skaiciu
                            ivestis=-1;
                        }
                        else
                        {
                            ivestis = std::stoi(ivestis_string); // Jei viskas ok string pavercia i int
                        }
                        

                        if (ivestis<0 or ivestis>10){ // Per mazas skaicius netinka, 0 kiek zinau cia jau tinka, bet daugiau 10 tai tikrai ne :D
                            std::cout << erroras << std::endl;
                        }
                        else
                        {
                            egz=ivestis;
                            break;
                        }
                    }

                    double vid;
                    if (vid_pasirinkimas==1)
                        vid=vidurkis(pazymiai,sk);
                    else
                        vid=mediana(pazymiai,sk);
                    

                    A[stud_nr].galutinis=1.0*(0.4*vid+0.6*egz);
                    std::cin.ignore();
                    std::cin.clear(); // Trinu visus cin, kad isvengti nesamoniu visokiu
                }
                else{
                    std::cout << erroras << std::endl;
                }
            }
            
            else{
                if (stud_nr==-1)
                    std::cout << "Irasyk duomenis bent apie 1 studenta!"<< std::endl;
                else{
                    spausdinimas(stud_nr,A,vid_pasirinkimas);
                    break;
                }       
            }
        }
    }
    else if (ivedimo_pasirinkimas==2)
    {
        std::string eilute;
        std::ifstream in_file ("kursiokai.txt");
        if (in_file.good()){
            while(std::getline(in_file,eilute)){  // Nuskaito po visa eilute txt faile
                A.push_back(Studentas());
                std::istringstream in_line(eilute); // Skaitymas is eilutes
                stud_nr++;

                in_line >> A[stud_nr].vardas >> A[stud_nr].pavarde;
                convert_to_proper_format(A[stud_nr].vardas);
                convert_to_proper_format(A[stud_nr].pavarde);

                int sk=0;
                std::vector<int> pazymiai;
                while(in_line>>temp){
                    if(is_digits(temp)){
                        int ivestis = std::stoi(temp);
                        if (ivestis>0 and ivestis<11){
                            pazymiai.push_back(int());
                            pazymiai[sk]=ivestis;
                            sk++;
                        }
                    }
                }

                in_line.end;

                int egz = 0;
                if (sk>0) // Cia nes gali buti, jog neives skaiciu visai ir tada gali iseit pazymiai[-1]
                    egz = pazymiai[sk-1]; // Paskutinis ivestas skaicius egzamino pazimys

                if (sk>1){
                    A[stud_nr].galutinis=1.0*(0.4*vidurkis(pazymiai,sk-1)+0.6*egz);
                    A[stud_nr].galutinis2=1.0*(0.4*mediana(pazymiai,sk-1)+0.6*egz);
                }
                else
                {
                    A[stud_nr].galutinis=1.0*(0.6*egz);
                    A[stud_nr].galutinis2=1.0*(0.6*egz);
                }
            }
            if (stud_nr>-1)
                rikiavimas(A,stud_nr); // Ten rikiuoju o isrikiaves siunciu iskart i spausdinima
            else
                std::cout << "Failas yra tuscias." << std::endl;
            
        }
        else
            std::cout << "Tokio failo nera." << std::endl;
        
        in_file.end;
    }

return 0;
}

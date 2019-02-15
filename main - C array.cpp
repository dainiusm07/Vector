#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <time.h>
#include <cmath>
#include <stdio.h>


struct Studentas {
    double galutinis;
    std::string vardas,
    pavarde;
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
double vidurkis (int* temp_paz,int n){
    int sum=0;
    for (int i=0;i<n;i++)
        sum+=temp_paz[i];
    return 1.0*sum/n;
};
double mediana (int* temp_paz,int n){
    for (int a=0;a<n-1;a++) // Rikiuoju skaicius didejimo tvarka
        for (int i=a+1;i<n;i++)
            if (temp_paz[i]<temp_paz[a])
                std::swap(temp_paz[i],temp_paz[a]);
    if (n%2==0)
         return 1.0*(temp_paz[n/2]+temp_paz[n/2-1])/2;
    else
         return 1.0*(temp_paz[n/2]);
};
int *new_array(int *dynamicArray, int &size, int newEntry)
{
   int *newArray = new int[size+1]; // Kuriu didesni masyva +1

   for(int i = 0; i < size; i++) // Kopijuoju viska is seno i nauja masyva
       newArray[i] = dynamicArray[i];
 
   newArray[size] = newEntry; // Ivedu nauja duota skaiciu i gala naujo masyvo
   size++;
   delete[] dynamicArray; // Trinu sena masyva

   return newArray;
}

int main () {
    srand ( time ( NULL ));
    std::string temp;
    std::vector<Studentas> A;
    int stud_nr=-1; // Studento identifikacijos nr (-1 nes nera dar jokio stud, prasideda nuo 0)
    int vid_pasirinkimas;
    new_line();
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
                int *pazymiai;
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
                                pazymiai=new_array(pazymiai,sk,ivestis);
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
                                int random = round(1+1.0*rand()/RAND_MAX*9);
                                pazymiai=new_array(pazymiai,sk,random);
                            }
                            std::cout << "Sugeneruoti skaiciai - ";
                            for (int i=0;i<sk;i++)
                                std::cout << pazymiai[i] << " ";
                            new_line();
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
                // Spausdinimas baigus ivedinet duomenis apie studentus
                int max_vardas=7, max_pavarde=9; // Pradzioj zodziai Vardas ir Pavarde yra didziausi
                for (int i=0;i<=stud_nr;i++){    // Randu ilgiausia varda ir pavarde
                    if (max_vardas<A[i].vardas.length()+1)
                        max_vardas=A[i].vardas.length()+1;
                    if (max_pavarde<A[i].pavarde.length()+1)
                        max_pavarde=A[i].pavarde.length()+1;
                }
                printf("%*s", -max_vardas, "Vardas");
                printf("%*s", -max_pavarde, "Pavarde");
                if (vid_pasirinkimas==1)
                printf("Galutinis (Vid.)\n");
                else
                printf("Galutinis (Med.)\n");

                for (int i=0;i<max_vardas+max_pavarde+20;i++)
                    printf("-");
                
                for (int i=0;i<=stud_nr;i++){    //Spausdinu studentu info
                    printf("\n%*s", -max_vardas, A[i].vardas.c_str()); //.c_str, nes kitaip printina pievas
                    printf("%*s", -max_pavarde, A[i].pavarde.c_str());
                    printf("%4.2f", A[i].galutinis);
                }
                break;
            }

                
        }

    }
return 0;
}

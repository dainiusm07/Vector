#include "header.h"

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
};

void convert_to_proper_format (std::string &text) {
    if(islower(text.at(0)))
        text.at(0) = toupper(text.at(0)); // Keicia pirma raide i uppercase
    for (int i=1;i<text.length();i++)
        if(isupper(text.at(i)))
            text.at(i) = tolower(text.at(i)); // Keicia likusiais i lowercase
};

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

void spausdinimas (int stud_nr,std::list<Studentas> A,int vid_pasirinkimas) {
    std::list<Studentas> :: iterator it;
    int max_vardas=7, max_pavarde=9; // Pradzioj zodziai Vardas ir Pavarde yra didziausi

    for (it = A.begin()++ ; it !=A.end(); it++){    // Randu ilgiausia varda ir pavarde
        if (max_vardas<it->vardas.length()+1)
            max_vardas=it->vardas.length()+1;
        if (max_pavarde<it->pavarde.length()+1)
            max_pavarde=it->pavarde.length()+1;
    }

    new_line();
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
        for (it = A.begin()++ ; it !=A.end(); it++){    //Spausdinu studentu info
            printf("\n%*s", -max_vardas, it->vardas.c_str()); //.c_str, nes kitaip printina pievas
            printf("%*s", -max_pavarde, it->pavarde.c_str());
            printf("%4.2f", it->galutinis);
        }
    else{    // Spausdinimas skaicius duomenis is failo
        for (it = A.begin()++ ; it !=A.end(); it++){    //Spausdinu studentu info
            printf("\n%*s", -max_vardas, it->vardas.c_str()); //.c_str, nes kitaip printina pievas
            printf("%*s", -max_pavarde, it->pavarde.c_str());
            printf("%-17.2f", it->galutinis);
            printf("%-17.2f", it->galutinis2);
        }
    }
}
void rikiavimas (std::list<Studentas> A,int n){
    std::list<Studentas> :: iterator it;
    std::list<Studentas> :: iterator it2;
    for (it = A.begin()++ ; it!=A.end(); it++)
        for(it2 = it++ ; it2!=A.end(); it2++)
            if(strcmp(it->vardas.c_str(),it2->vardas.c_str())>0) // Tikrina vardus
                std::swap(it,it2);
            else if (strcmp(it->vardas.c_str(),it2->vardas.c_str())==0)
                if(strcmp(it->pavarde.c_str(),it2->pavarde.c_str())>0)
                    std::swap(it,it2);
            
    spausdinimas(n,A,3);
}
void rusiavimas (std::list<Studentas>& A, std::list<Studentas>& vargsai){
    std::list<Studentas>::iterator itr = A.begin();
    Studentas temp;
    for (itr; itr != A.end(); itr++){
        if (itr -> galutinis < 5.0 && itr -> galutinis2< 5.0){
            temp.vardas = itr -> vardas;
            temp.pavarde = itr -> pavarde;
            temp.galutinis = itr -> galutinis;
            temp.galutinis2 = itr -> galutinis2;
            vargsai.push_back(temp);
            itr = A.erase(itr);
            itr--;
        }
    }
}
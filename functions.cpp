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

void spausdinimas (int stud_nr,std::deque<Studentas> A,int vid_pasirinkimas) {

    int max_vardas=7, max_pavarde=9; // Pradzioj zodziai Vardas ir Pavarde yra didziausi

    for (int i=0;i<=stud_nr;i++){    // Randu ilgiausia varda ir pavarde
        if (max_vardas<A[i].vardas.length()+1)
            max_vardas=A[i].vardas.length()+1;
        if (max_pavarde<A[i].pavarde.length()+1)
            max_pavarde=A[i].pavarde.length()+1;
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
        for (int i=0;i<=stud_nr;i++){    //Spausdinu studentu info
            printf("\n%*s", -max_vardas, A[i].vardas.c_str()); //.c_str, nes kitaip printina pievas
            printf("%*s", -max_pavarde, A[i].pavarde.c_str());
            printf("%4.2f", A[i].galutinis);
        }
    else{    // Spausdinimas skaicius duomenis is failo
        int sk=0;
        while(sk!=stud_nr+1){
            printf("\n%*s", -max_vardas, A[sk].vardas.c_str()); //.c_str, nes kitaip printina pievas
            printf("%*s", -max_pavarde, A[sk].pavarde.c_str());
            printf("%-17.2f", A[sk].galutinis);
            printf("%-17.2f", A[sk].galutinis2);
            sk++;
        }
    }
}
void rikiavimas (std::deque<Studentas> A,int n){
    for (int i=0;i<=n;i++)
        for(int j=i;j<=n;j++)
            if(strcmp(A[i].vardas.c_str(),A[j].vardas.c_str())>0) // Tikrina vardus
                std::swap(A[i],A[j]);
            else if (strcmp(A[i].vardas.c_str(),A[j].vardas.c_str())==0)
                if(strcmp(A[i].pavarde.c_str(),A[j].pavarde.c_str())>0)
                    std::swap(A[i],A[j]);
            
    spausdinimas(n,A,3);
}
/*void rusiavimas (std::vector<Studentas> &A,std::vector<Studentas> &kieti,std::vector<Studentas> &vargsai){
    int kiet_sk=0;
    int vargs_sk=0;
    for (int i=0;i<A.size();i++)
        if (A[i].galutinis>=5 or A[i].galutinis2>=5){
            kieti.push_back(Studentas());
            kieti[kiet_sk] = A[i];
            kiet_sk++;
        }
        else{
            vargsai.push_back(Studentas());
            vargsai[vargs_sk] = A[i];
            vargs_sk++;
        }
    A.clear();
}*/
void rusiavimas (std::deque<Studentas>& A, std::deque<Studentas>& vargsai){
    std::deque<Studentas>::size_type i = 0;
    while (i != A.size()) {
        if (A[i].galutinis < 5.0 && A[i].galutinis2 < 5.0) {
            vargsai.push_back(A[i]);
            A.erase(A.begin() + i);
        } else
            i++;
    }
}
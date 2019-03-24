# ifndef HEADER
# define HEADER

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
#include <limits>
#include <chrono>
#include <list>
#include <random>


struct Studentas {
    double galutinis=0; 
    double galutinis2=0; // Galutiniui saugot su mediana, kadangi skaitant is failo reikia isvesti 2 galutinius
    std::string vardas="0", // Irasiau skaicius i varda ir pavarde, kadangi taip paprasta patikrinti ar buvo faile irasyti ar ne 
    pavarde="0";
};

const std::string erroras = "Kazkas netaip su tavo ivestais duomenimis!";

bool all_letters(std::string);
bool is_digits(const std::string &str);
void convert_to_proper_format (std::string &text);
void new_line ();
double vidurkis (std::vector<int>, int);
double mediana (std::vector<int>, int);
void spausdinimas (int, std::list<Studentas>, int);
void rikiavimas (std::list<Studentas>, int);
void rusiavimas(std::list<Studentas>&, std::list<Studentas>&);

#endif


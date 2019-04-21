# ifndef HEADER
# define HEADER

#include "studentas.h"
#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <time.h>
#include <cmath>
#include <random>
#include <stdio.h>
#include <fstream>
#include <sstream>
#include <limits>
#include <chrono>


const std::string erroras = "Kazkas netaip su tavo ivestais duomenimis!";

bool all_letters(std::string);
bool is_digits(const std::string &str);
std::string convert_to_proper_format (std::string text);
void new_line ();
double vidurkis (std::vector<int>, int);
double mediana (std::vector<int>, int);
void spausdinimas (int, std::vector<Studentas>, int);
void rikiavimas (std::vector<Studentas>, int);
bool skola(const Studentas & i);
std::vector<Studentas> rusiavimas (std::vector<Studentas>&);

#endif


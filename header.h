# ifndef HEADER_H
# define HEADER_H

#include <iostream>
#include <limits>
#include <chrono>
#include <string>
#include <vector>
#include <random>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <fstream>
#include <sstream>
#include "vector.h"
#include "student.h"


using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::vector;
using std::ifstream;
using std::ofstream;
using std::istringstream;

template<class> class Vector;

const string wrongNumber = "Netinkamas skaicius! Pabandyk dar karta: ";

int choiceOfInput ();
int calculationChoice();
inline bool isLetters(const string);
inline void notNumber ();
inline double average (vector<int>);
inline double median (vector<int>);
void addStudents (Vector<Studentas>&, const int);
void sortByName (Vector<Studentas>&);
int involution (int, int);
void generateStudents (const string, const int);
void printStudents (Vector<Studentas>&,Vector<Studentas>&,  const int, string = "vargsai.txt", string = "kieti.txt");
inline bool fileExists (const string);
void readData (Vector<Studentas>&, const string, bool = false);
inline bool debt(const Studentas&);
Vector<Studentas> sortByMark (Vector<Studentas>&);


#endif
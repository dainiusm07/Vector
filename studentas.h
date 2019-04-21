# ifndef STUDENTAS_H
# define STUDENTAS_H

#include <string>

class Studentas{
    private:
    double galutinis;
    double galutinis2;
    std::string vardas="0",
    pavarde="0";
    public:
    Studentas () {}
    double GetGalutinis () const {return galutinis;}
    void SetGalutinis (double x) {galutinis = x;}
    double GetGalutinis2 () const {return galutinis2;}
    void SetGalutinis2 (double x) {galutinis2 = x;}
    std::string GetVardas () const {return vardas;}
    void SetVardas (std::string x) {vardas = x;}
    std::string GetPavarde () const {return pavarde;}
    void SetPavarde (std::string x) {pavarde = x;}
};

#endif
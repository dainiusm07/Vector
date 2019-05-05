# ifndef STUDENTAS_H
# define STUDENTAS_H

#include <string>
#include <iomanip>

class Zmogus {
    protected:
    std::string vardas = "0",
    pavarde = "0";
    public:
    std::string GetVardas () const {return vardas;}
    void SetVardas (std::string x) {vardas = x;}
    std::string GetPavarde () const {return pavarde;}
    void SetPavarde (std::string x) {pavarde = x;}
};

class Studentas : public Zmogus{
    private:
    double galutinis;
    double galutinis2;
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

    friend std::ostream& operator << (std::ostream& out, const Studentas& stud){
        out << stud.GetVardas() << " " << stud.GetPavarde() << " " << std::setprecision(3) << stud.GetGalutinis() << " " << stud.GetGalutinis2();
        return out;
    }
    friend bool operator == (const Studentas& stud, const Studentas& stud1){
        if (stud.GetVardas() == stud1.GetVardas() && stud.GetPavarde() == stud1.GetPavarde()
    && stud.GetGalutinis() == stud1.GetGalutinis() && stud.GetGalutinis2() == stud1.GetGalutinis2()){
            return 1;
        }
        else{
            return 0;
        }
    }
    friend bool operator != (const Studentas& stud, const Studentas& stud1){
        if (stud.GetVardas() == stud1.GetVardas() && stud.GetPavarde() == stud1.GetPavarde()
    && stud.GetGalutinis() == stud1.GetGalutinis() && stud.GetGalutinis2() == stud1.GetGalutinis2()){
            return 0;
        }
        else{
            return 1;
        }
    }
    friend bool operator <= (const Studentas& stud, int n){
        if (stud.GetGalutinis() <= n || stud.GetGalutinis2() <= n){
            return 1;
        }
        else{
            return 0;
        }
    }
    friend bool operator >= (const Studentas& stud, int n){
        if (stud.GetGalutinis() >= n || stud.GetGalutinis2() >= n){
            return 1;
        }
        else{
            return 0;
        }
    }
    friend bool operator > (const Studentas& stud, int n){
        if (stud.GetGalutinis() > n && stud.GetGalutinis2() > n){
            return 1;
        }
        else{
            return 0;
        }
    }
    friend bool operator < (const Studentas& stud, int n){
        if (stud.GetGalutinis() < n && stud.GetGalutinis2() < n){
            return 0;
        }
        else{
            return 1;
        }
    }
    Studentas& operator = (const Studentas& stud) {
        if (&stud == this)
            return *this;
        vardas = stud.GetVardas();
        pavarde = stud.GetPavarde();
        galutinis = stud.GetGalutinis();
        galutinis2 = stud.GetGalutinis2();

        return *this;
        }
};

#endif
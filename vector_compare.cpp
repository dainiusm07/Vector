#include "vector.h"

int main () {
    int size = 10000000;
    Vector <int> a(size,1);
    Vector <int> b(size,2);
    Vector <int> c;
    c = a + b;
    std::cout << "c = a + b rezultatas: " << c[100000] << std::endl; // Patikriname ar tikrai sudėjo

    a.push_back(100);

    std::cout << std::endl;
    std::cout <<"a.capacity(): " <<  a.capacity() << std::endl;
    std::cout <<"a.size(): " <<  a.size() << std::endl;
    Vector<int> v(4, 1);
    // std::cout << "v[5]:" << v[5]<< endl;
    // std::cout << "v.at(5):" <<v.at(5)<< endl;
    //Vector<int> h(9999999999999);

    a.shrink_to_fit();

    std::cout <<"po funkcijos shrink_to_fit: " << std::endl;
    std::cout <<"a.capacity(): " <<  a.capacity() << std::endl;
    std::cout <<"a.size(): " <<  a.size() << std::endl;



    return 0;
}
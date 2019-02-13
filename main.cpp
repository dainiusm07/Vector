#include <iostream>

int main () {
    std::cout << "Ivesk studento varda ir pavarde." << std::endl << "Jei jau pabaigiai vesti duomenis tiesiog spausk ENTER." << std::endl;
    std::string temp;
    while (true) {
        std::getline(std::cin, temp);
        if (!temp.empty())
        {
            std::cout << temp << std::endl;
        }
        else
            break;
    }

return 0;
}

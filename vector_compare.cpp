#include "vector.h"

int main () {
    cout << endl;
    //Orig
    vector<int> v1, v1_compare;
    v1.assign(100,2);

    cout << "-----------------------------" << endl;
    cout << "Originalus vectorius!" << endl << endl;
    cout << "!= testas" << endl;
    if (v1 != v1_compare)
        cout << "Vectoriai nelygus!" << endl << endl;
    else
        cout << "Vectoriai lygus!" << endl << endl;
    
    cout << "= testas" << endl;
    v1_compare = v1;
    if (v1 != v1_compare)
        cout << "Vectoriai nelygus!" << endl << endl;
    else
        cout << "Vectoriai lygus!" << endl << endl;
    
    cout << "size() testas" << endl;
    cout << v1.size() << endl << endl;

    cout << "front() testas" << endl;
    cout << v1.front() << endl << endl;

    cout << "resize(5) testas" << endl;
    v1.resize(5);
    cout << "Dabar size() rezultatas - " << v1.size() << endl << endl;

    v1.clear();
    v1_compare.clear();

    //Mano
    Vector<int> v2, v2_compare;
    v2.assign(100,2);

    cout << "-----------------------------" << endl;
    cout << "Mano vectorius!" << endl << endl;
    cout << "!= testas" << endl;
    if (v2 != v2_compare)
        cout << "Vectoriai nelygus!" << endl << endl;
    else
        cout << "Vectoriai lygus!" << endl << endl;
    
    cout << "= testas" << endl;
    v2_compare = v2;
    if (v2 != v2_compare)
        cout << "Vectoriai nelygus!" << endl << endl;
    else
        cout << "Vectoriai lygus!" << endl << endl;
    
    cout << "size() testas" << endl;
    cout << v2.size() << endl << endl;

    cout << "front() testas" << endl;
    cout << v2.front() << endl << endl;

    cout << "resize(5) testas" << endl;
    v2.resize(5);
    cout << "Dabar size() rezultatas - " << v2.size() << endl << endl;

    v2.clear();
    v2_compare.clear();

    return 0;
}
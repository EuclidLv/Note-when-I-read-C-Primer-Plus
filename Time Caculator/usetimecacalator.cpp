#include <iostream>
#include "timecaculator.h"

int main()
{
    using std::cout;
    using std::endl;
    Time aida(3, 25,26);
    Time tosca(2, 48,27);
    Time temp;

    cout << "Aida and tosca:\n";
    cout << aida << "; " << tosca << endl;
    temp = aida + tosca;
    cout << "Aida + Tosca: " << temp << endl;
    temp = aida * 1.17;
    cout << "Aida * 1.17" << temp << endl;
    cout << "10.0 * tosca" << 10.0 * tosca << endl;
    return 0;
}
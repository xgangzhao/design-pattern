#include "main.hpp"

void clientCode(Facade* facade) {
    cout << facade->operation() << endl;
}

int main() {
    Subsystem1* s1 = new Subsystem1();
    Subsystem2* s2 = new Subsystem2();
    Facade* facade = new Facade(s1, s2);

    clientCode(facade);

    delete facade;

    return 0;
}
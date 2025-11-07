#include "main.hpp"

void clientCode(const Target* target) {
    cout << target->request() << endl;
}

int main() {
    cout << "client: I can work just fine with the target objects: " << endl;
    Target* target = new Target();
    clientCode(target);
    cout << "\n" << endl;

    Adaptee* adaptee = new Adaptee();
    cout << "client: the adaptee class have a weird interface." << endl;
    cout << "adaptee: " << adaptee->specificRequest();
    cout << "\n" << endl;

    cout << "client: but i can work with it via the adapter: " << endl;
    Adapter* adapter = new Adapter(adaptee);
    clientCode(adapter);
    cout << "\n" << endl;

    delete target;
    delete adaptee;
    delete adapter;

    return 0;
}
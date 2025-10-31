#include "main.hpp"

using namespace std;

void clientCode(const Creator& creator) {
    cout << "Client: I'm not aware of the creator's class, but it still works.\n"
         << creator.someOperation() << endl; 
}

int main() {
    cout << "App: Launched with the ConcreteCreator1." << endl;
    Creator* creator1 = new ConcreteCreator1();
    clientCode(*creator1);
    delete creator1;
    cout << endl;

    cout << "App: Launched with the ConcreteCreator2." << endl;
    Creator* creator2 = new ConcreteCreator2();
    clientCode(*creator2);
    delete creator2;
    cout << endl;

    return 0;
}
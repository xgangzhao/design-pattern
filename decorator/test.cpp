#include "main.hpp"

void clientCode(Component* comp) {
    cout << "result: " << comp->operation() << endl;
}

int main() {
    Component* simple = new ConcreteComponent();
    cout << "client: I got a simple component:\n";
    clientCode(simple);
    cout << "\n" << endl;

    Component* dec1 = new ConcreteDecoratorA(simple);
    Component* dec2 = new ConcreteDecoratorB(dec1);
    cout << "client: now I got a decorated component:\n";
    clientCode(dec2);
    cout << "\n" << endl;

    delete simple;
    delete dec1;
    delete dec2;

    return 0;
}
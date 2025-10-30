#include "prototype.hpp"

void client(PrototypeFactory& factory) {
    cout << "Let's create a Prototype A" << endl;

    Prototype* proto = factory.CreatePrototype(Type::PROTOTYPE_1);
    proto->method(90);
    delete proto;
    proto = nullptr;

    cout << "\n";

    cout << "Lets create a Prototype B" << endl;
    proto = factory.CreatePrototype(Type::PROTOTYPE_2);
    proto->method(10);
    delete proto;
    proto = nullptr;
}

int main() {
    PrototypeFactory* factory = new PrototypeFactory();
    client(*factory);

    delete factory;

    return 0;
}
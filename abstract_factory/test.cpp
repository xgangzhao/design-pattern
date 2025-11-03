#include "main.hpp"

void clientCode(const AbstractFactory& factory) {
    const AbstractProductA* abs_pa = factory.createProductA();
    const AbstractProductB* abs_pb = factory.createProductB();

    cout << abs_pb->usefulFunctionB() << endl;
    cout << abs_pb->anotherUsefulFunctionB(*abs_pa) << endl;

    delete abs_pa;
    delete abs_pb;
}

int main() {
    cout << "client: testing client with the first factory type: " << endl;
    AbstractFactory* f1 = new ConcreteFactory1();
    clientCode(*f1);
    delete f1;

    cout << endl;

    cout << "client: testing client with the second factory type: " << endl;
    ConcreteFactory2* f2 = new ConcreteFactory2();
    clientCode(*f2);
    delete f2;

    return 0;
}
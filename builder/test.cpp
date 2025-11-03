#include "main.hpp"

void client_code(Director& di) {
    ConcreteBuilder1* builder = new ConcreteBuilder1;
    di.set_builder(builder);
    cout << "standard basic product: " << endl;
    di.buildMinimalViableProduct();

    Product1* p = builder->getProduct();
    p->listParts();
    delete p;

    cout << "standard full featured product: " << endl;
    di.buildFullFeatureProduct();
    p = builder->getProduct();
    p->listParts();
    delete p;


    cout << "custom product: " << endl;
    builder->producePartA();
    builder->producePartC();
    p = builder->getProduct();
    p->listParts();
    delete p;

    delete builder;
}

int main() {
    Director* di = new Director();
    client_code(*di);
    delete di;

    return 0;
}
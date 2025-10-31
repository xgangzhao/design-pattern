#include <iostream>

using namespace std;

class Product {
public:
    virtual ~Product() {}
    virtual string Operation() const = 0;
};

class ConcreteProduct1 : public Product {
public:
    string Operation() const override {
        return "result of ConcreteProduct1";
    }
};

class ConcreteProduct2 : public Product {
public:
    string Operation() const override {
        return "result of ConcreteProduct2";
    }
};

class Creator {
public:
    virtual ~Creator() {};
    virtual Product* factoryMethod() const = 0;

    string someOperation() const {
        Product* product = this->factoryMethod();
        string result = "Creator: the same creator's code has just worked with " + product->Operation();
        delete product;

        return result;
    }
};

class ConcreteCreator1 : public Creator {
public:
    Product* factoryMethod() const override {
        return new ConcreteProduct1();
    }
};

class ConcreteCreator2 : public Creator {
public:
    Product* factoryMethod() const override {
        return new ConcreteProduct2();
    }
};

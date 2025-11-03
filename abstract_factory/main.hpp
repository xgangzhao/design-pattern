#include <iostream>

using namespace std;

class AbstractProductA {
public:
    virtual ~AbstractProductA() {};
    virtual string usefulFunctionA() const = 0;
};

class AbstractProductB {
public:
    virtual ~AbstractProductB() {};
    virtual string usefulFunctionB() const = 0;
    virtual string anotherUsefulFunctionB(const AbstractProductA& pa) const = 0;
};

class ConcreteProductA1 : public AbstractProductA {
public:
    string usefulFunctionA() const override {
        return "result of the product A1";
    }
};

class ConcreteProductA2 : public AbstractProductA {
public:
    string usefulFunctionA() const override {
        return "result of the product A2";
    }
};

class ConcreteProductB1 : public AbstractProductB {
public:
    string usefulFunctionB() const override {
        return "result of the product B1";
    }

    string anotherUsefulFunctionB(const AbstractProductA& pa) const override {
        const string result = pa.usefulFunctionA();
        return "result of the B1 collaborating with (" + result + ")";
    }
};

class ConcreteProductB2 : public AbstractProductB {
public:
    string usefulFunctionB() const override {
        return "result of the product B2";
    }

    string anotherUsefulFunctionB(const AbstractProductA& pa) const override {
        const string result = pa.usefulFunctionA();
        return "result of the B2 collaborating with (" + result + ")";
    }
};

class AbstractFactory {
public:
    virtual ~AbstractFactory() {};
    virtual AbstractProductA* createProductA() const = 0;
    virtual AbstractProductB* createProductB() const = 0;
};

class ConcreteFactory1: public AbstractFactory {
public:
    AbstractProductA* createProductA() const override {
        return new ConcreteProductA1();
    }

    AbstractProductB* createProductB() const override {
        return new ConcreteProductB1();
    }
};

class ConcreteFactory2: public AbstractFactory {
public:
    AbstractProductA* createProductA() const override {
        return new ConcreteProductA2();
    }

    AbstractProductB* createProductB() const override {
        return new ConcreteProductB2();
    }
};

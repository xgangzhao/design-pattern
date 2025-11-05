#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Component {
public:
    virtual ~Component() {}
    virtual string operation() const = 0;
};

class ConcreteComponent : public Component {
public:
    string operation() const override {
        return "concrete component";
    }
};

class Decorator : public Component {
protected:
    Component* comp_;

public:
    Decorator(Component* comp) : comp_(comp) {}

    string operation() const override {
        return this->comp_->operation();
    }
};

class ConcreteDecoratorA : public Decorator {
public:
    ConcreteDecoratorA(Component* comp) : Decorator(comp) {}

    string operation() const override {
        return "concrete decorator A ( " + Decorator::operation() + " )";
    }
};

class ConcreteDecoratorB : public Decorator {
public:
    ConcreteDecoratorB(Component* comp) : Decorator(comp) {}

    string operation() const override {
        return "concrete decorator B ( " + Decorator::operation() + " )";
    }
};

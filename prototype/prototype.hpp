#include <iostream>
#include <unordered_map>
using namespace std;

/**
 * The example class that has cloning ability. We'll see how the values of field
 * with different types will be cloned.
 */

enum Type {
    PROTOTYPE_1 = 0,
    PROTOTYPE_2
};

class Prototype {
protected:
    string proto_name_;
    float  proto_field_;

public:
    Prototype() {}
    Prototype(string proto_name) : proto_name_(proto_name) {
    }
    virtual ~Prototype() {}
    virtual Prototype* clone() const = 0;
    virtual void method(float proto_field) {
        this->proto_field_ = proto_field;
        cout << "Call method from " << proto_name_ << " with field: "
             << proto_field << endl;
    }
};

/**
 * ConcretePrototypeA is a Sub-Class of Prototype and implement the Clone Method
 * In this example all data members of Prototype Class are in the Stack. If you
 * have pointers in your properties for ex: String* name_ ,you will need to
 * implement the Copy-Constructor to make sure you have a deep copy from the
 * clone method
 */
class ConcretePrototypeA : public Prototype {
private:
    float concrete_proto_field_;

public:
    ConcretePrototypeA(string name, float field) : Prototype(name), concrete_proto_field_(field) {
    }

    /**
     * Notice that Clone method return a Pointer to a new ConcretePrototypeA
     * replica. so, the client (who call the clone method) has the responsability
     * to free that memory. If you have smart pointer knowledge you may prefer to
     * use unique_pointer here.
     */
    Prototype* clone() const override {
        return new ConcretePrototypeA(*this);
    }
};

class ConcretePrototypeB : public Prototype {
private:
    float concrete_proto_field_;

public:
    ConcretePrototypeB(string name, float field) : Prototype(name), concrete_proto_field_(field) {
    }

    /**
     * Notice that Clone method return a Pointer to a new ConcretePrototypeB
     * replica. so, the client (who call the clone method) has the responsability
     * to free that memory. If you have smart pointer knowledge you may prefer to
     * use unique_pointer here.
     */
    Prototype* clone() const override {
        return new ConcretePrototypeB(*this);
    }
};

class PrototypeFactory {
private:
    unordered_map<Type, Prototype*, hash<int>> prototypes_;

public:
    PrototypeFactory() {
        prototypes_[Type::PROTOTYPE_1] = new ConcretePrototypeA("PROTOTYPE_1", 50.f);
        prototypes_[Type::PROTOTYPE_2] = new ConcretePrototypeB("PROTOTYPE_2", 60.f);
    }
    ~PrototypeFactory() {
        delete prototypes_[Type::PROTOTYPE_1];
        delete prototypes_[Type::PROTOTYPE_2];
    }

    Prototype* CreatePrototype(Type type) {
        return prototypes_[type]->clone();
    }
};

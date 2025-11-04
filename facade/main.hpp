#include <iostream>
#include <string>

using namespace std;

class Subsystem1 {
public:
    string operation1() const {
        return "subsystem1: ready!\n";
    }

    string operationN() const {
        return "subsystem2: go!\n";
    }
};


class Subsystem2 {
public:
    string operation1() const {
        return "subsystem2: get ready!\n";
    }

    string operationZ() const {
        return "subsystem2: fire!\n";
    }
};


class Facade {
protected:
    Subsystem1* sys1_;
    Subsystem2* sys2_;

public:
    Facade(Subsystem1* sys1 = nullptr, Subsystem2* sys2 = nullptr) {
        this->sys1_ = sys1 ?: new Subsystem1();
        this->sys2_ = sys2 ?: new Subsystem2();
    }

    ~Facade() {
        delete sys1_;
        delete sys2_;
    }

    string operation() {
        string res = "facade initializes subsystems: \n";
        res += this->sys1_->operation1();
        res += this->sys2_->operation1();
        res += "facade orders subsystems to perform the action: \n";
        res += this->sys1_->operationN();
        res += this->sys2_->operationZ();

        return res;
    }
};

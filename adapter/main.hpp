#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Target {
public:
    virtual ~Target() = default;

    virtual string request() const {
        return "target: the defautl target's behavior"; 
    }
};

class Adaptee {
public:
    string specificRequest() const {
        return ".eetpadA eht fo roivaheb laicepS";
    }
};

class Adapter : public Target {
private:
    Adaptee* adaptee_;

public:
    Adapter(Adaptee* adaptee) : adaptee_(adaptee) {} 

    string request() const override {
        string to_reverse = this->adaptee_->specificRequest();
        reverse(to_reverse.begin(), to_reverse.end());
        return "adapter: (translate) " + to_reverse;
    }
};

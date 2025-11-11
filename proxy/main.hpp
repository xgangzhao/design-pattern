#include <iostream>
#include <string>

using namespace std;

class Subject {
public:
    virtual void request() const = 0;
};

class RealSubject : public Subject {
public:
    void request() const override {
        cout << "realsubject: handlong request" << endl;
    }
};

class Proxy : public Subject {
private:
    RealSubject* real_subject;

    bool checkAccess() const {
        cout << "proxy: checking access prior to firing a real request" << endl;
        return true;
    }

    void logAccess() const {
        cout << "proxy: logging the time of request" << endl;
    }

public:
    Proxy(RealSubject* rs) : real_subject(new RealSubject(*rs)) {}

    ~Proxy() {
        delete real_subject;
    }

    void request() const override {
        if (this->checkAccess()) {
            this->real_subject->request();
            this->logAccess();
        }
    }
};

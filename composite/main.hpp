#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <list>

using namespace std;

class Component {
protected:
    Component* parent_;

public:
    virtual ~Component() {}
    void setParent(Component* parent) {
        this->parent_ = parent;
    }

    Component* getParent() const {
        return this->parent_;
    }

    virtual void add(Component* comp) {}
    virtual void remove(Component* comp) {}
    virtual bool isComposite() const {
        return false;
    }

    virtual string operation() const = 0;
};

class Leaf : public Component {
public:
    string operation() const override {
        return "leaf";
    }
};

class Composite : public Component {
protected:
    list<Component*> children_;

public:
    void add(Component* comp) override {
        this->children_.push_back(comp);
        comp->setParent(this);
    }

    void remove(Component* comp) override {
        children_.remove(comp);
        comp->setParent(nullptr);
    }

    bool isComposite() const override {
        return true;
    }

    string operation() const override {
        string res;
        for (auto* c : children_) {
            if (c == children_.back()) {
                res += c->operation();
            } else {
                res += c->operation() + "+";
            }
        }

        return "branch:( " + res + " )"; 
    }
};

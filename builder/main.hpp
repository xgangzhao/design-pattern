#include <iostream>
#include <vector>

using namespace std;

class Product1 {
public:
    vector<string> parts_;

    void listParts() const {
        cout << "product parts: " << endl;
        for (auto i = 0; i < parts_.size(); ++i) {
            if (parts_[i] == parts_.back()) {
                cout << parts_[i];
            } else {
                cout << parts_[i] << ", ";
            }
        }
        cout << endl;
    }
};

class Builder {
public:
    virtual ~Builder() {}
    virtual void producePartA() const = 0;
    virtual void producePartB() const = 0;
    virtual void producePartC() const = 0;
};

class ConcreteBuilder1 : public Builder {
private:
    Product1* product;

public:
    ConcreteBuilder1() {
        this->reset();
    }

    ~ConcreteBuilder1() {
        delete product;
    }
    
    void reset() {
        this->product = new Product1();
    }

    void producePartA() const override {
        this->product->parts_.push_back("parta1");
    }

    void producePartB() const override {
        this->product->parts_.push_back("partb1");
    }

    void producePartC() const override {
        this->product->parts_.push_back("partc1");
    }

    Product1* getProduct() {
        Product1* res = this->product;
        this->reset();
        return res; 
    }
};

class Director {
private:
    Builder* builder;

public:
    void set_builder(Builder* builder) {
        this->builder = builder;
    }

    void buildMinimalViableProduct() {
        this->builder->producePartA();
    }

    void buildFullFeatureProduct() {
        this->builder->producePartA();
        this->builder->producePartB();
        this->builder->producePartC();
    }
};

#include <iostream>

using namespace std;

class Singleton {
private:
    Singleton() {};
    ~Singleton() {};
    Singleton(const Singleton& other) = delete;
    const Singleton& operator=(const Singleton& other) = delete;


public:
    // Meyers' Singleton
    static Singleton& getInstance() {
        // >= c++ 11
        static Singleton instance;
        return instance;
    }
};

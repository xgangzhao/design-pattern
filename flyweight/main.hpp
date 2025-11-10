#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

struct SharedState {
    string brand_;
    string model_;
    string color_;

    SharedState(const std::string& brand, const std::string& model, const std::string& color) 
        : brand_(brand), model_(model), color_(color) {
    }

    friend ostream& operator<<(ostream& os, const SharedState& ss) {
        return os << "[ " << ss.brand_ << " , " << ss.model_ << " , " << ss.color_ << " ]"; 
    }
};

struct UniqueState {
    std::string owner_;
    std::string plates_;

    UniqueState(const std::string &owner, const std::string &plates)
        : owner_(owner), plates_(plates)
    {
    }

    friend std::ostream &operator<<(std::ostream &os, const UniqueState &us)
    {
        return os << "[ " << us.owner_ << " , " << us.plates_ << " ]";
    }
};

class Flyweight {
private:
    SharedState* shared_state_;

public:
    Flyweight(const SharedState* shared_state) : shared_state_(new SharedState(*shared_state)) {}

    Flyweight(const Flyweight& other) : shared_state_(new SharedState(*other.shared_state_)) {}

    ~Flyweight() {
        delete shared_state_;
    }

    SharedState* shared_state() const {
        return shared_state_;
    }

    void operation(const UniqueState& unique_state) const {
        cout << "Flyweight: Displaying shared (" << *shared_state_ << ") and unique (" << unique_state << ") state." << endl;
    }
};

class FlyweightFactory {
private:
    unordered_map<string, Flyweight> flyweights_;

    string getKey(const SharedState& ss) const {
        return ss.brand_ + "_" + ss.model_ + "_" + ss.color_;
    }

public:
    FlyweightFactory(initializer_list<SharedState> share_states) {
        for (const auto& ss : share_states) {
            this->flyweights_.insert(make_pair<string, Flyweight>(this->getKey(ss), Flyweight(&ss)));
        }
    }

    Flyweight GetFlyweight(const SharedState &shared_state)
    {
        std::string key = this->getKey(shared_state);
        if (this->flyweights_.find(key) == this->flyweights_.end())
        {
            std::cout << "FlyweightFactory: Can't find a flyweight, creating new one.\n";
            this->flyweights_.insert(std::make_pair(key, Flyweight(&shared_state)));
        }
        else
        {
            std::cout << "FlyweightFactory: Reusing existing flyweight.\n";
        }
        return this->flyweights_.at(key);
    }

    void ListFlyweights() const
    {
        size_t count = this->flyweights_.size();
        std::cout << "\nFlyweightFactory: I have " << count << " flyweights:\n";
        for (std::pair<std::string, Flyweight> pair : this->flyweights_)
        {
            std::cout << pair.first << "\n";
        }
    }
};

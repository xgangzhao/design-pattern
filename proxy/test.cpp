#include "main.hpp"

void clientCode(const Subject& sub) {
    sub.request();
}

int main() {
    cout << "client: executing the client code with a real subject: " << endl;
    RealSubject* rs = new RealSubject();
    clientCode(*rs);
    cout << endl;

    cout << "client: executing the same client code with a proxy: " << endl;
    Proxy* proxy = new Proxy(rs);
    clientCode(*proxy);

    delete rs;
    delete proxy;

    return 0;
}
#include "main.hpp"

void clientCode(Component* comp) {
    cout << "res: " << comp->operation();
}

void clientCode2(Component* comp1, Component* comp2) {
    if (comp1->isComposite()) {
        comp1->add(comp2);
    }
    cout << "res: " << comp1->operation();
}

int main() {
    Component* simple = new Leaf();
    cout << "client: I've got a simple component: " << endl;
    clientCode(simple);
    cout << endl;

    Component* tree = new Composite();
    Component* branch1 = new Composite();

    Component* leaf1 = new Leaf();
    Component* leaf2 = new Leaf();
    Component* leaf3 = new Leaf();

    branch1->add(leaf1);
    branch1->add(leaf2);
    Component* branch2 = new Composite();
    branch2->add(leaf3);
    tree->add(branch1);
    tree->add(branch2);

    cout << "client: Now i have got a composite tree: " << endl;
    clientCode(tree);
    cout << endl;

    cout << "client: i don't need to check the components classes even when managing the tree: " << endl;
    clientCode2(tree, simple);
    cout << endl;

    delete simple;
    delete tree;
    delete branch1;
    delete leaf1;
    delete leaf2;
    delete leaf3;
    delete branch2;

    return 0;
}
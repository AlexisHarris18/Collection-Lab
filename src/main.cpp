#include <iostream>
#include "Collection.h"
using namespace std;

void TestCollection();
void TestExceedSize();
void TestRemoveCollection();
bool checkCase(string name, bool condition);

int main()
{
    TestCollection();
    TestExceedSize();
    TestRemoveCollection();
    return 0;
}
void TestCollection() {
    Collection<int>one;
    one.add(2);
    one.add(4);
    checkCase("Adding 1", one[0] == 2);
    checkCase("Adding 2", one[1] == 4);
    checkCase("Check Size", one.size() == 2);
}
void TestExceedSize() {
    Collection<int> one;
    for (int i = 0; i < 100; i++) {
        one.add(i);
    }
    checkCase("Exceed Size 1", one[0] == 0);
    checkCase("Exceed Size 2", one[99] == 99);
    checkCase("Add Check Size", one.size() == 100);
}


void TestRemoveCollection() {
    Collection<int> one;
    one.add(19);
    one.add(9);
    one.add(2);
    one.add(8);

    checkCase("Original Size", one.size() == 4);
    one.removeEnd();
    one.removeEnd();
    checkCase("Remove 2 Size", one.size() == 2);
    checkCase("Check Data", one[1] == 9);
    bool exception_caught = true;
    try {
        one - 3;
        exception_caught = false;
    }
    catch (exception& a) {
        exception_caught = true;
    }
    checkCase("Exception Caught", exception_caught);
}
bool checkCase(string name, bool condition) {
    if (!condition) {
        cout << "Failed: " << name << endl;
    }
    else {
        cout << name << ": passed" << endl;
    }
    return condition;
}

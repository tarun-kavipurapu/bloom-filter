#include <iostream>
#include <fmt/core.h>
#include <cstring>
#include "bloom.cpp"

using namespace std;

int main()
{
    // Using fmt library for formatted output

    Bloom *bloom = new Bloom();

    bloom->insert("a");

    bloom->insert("b");
    bloom->insert("c");
    bloom->insert("d");
    bloom->insert("e");
    bloom->insert("f");
    cout << "isPresent?" << bloom->isPresent("a") << endl;
    cout << "isPresent?" << bloom->isPresent("b") << endl;
    cout << "isPresent?" << bloom->isPresent("c") << endl;
    cout << "isPresent?" << bloom->isPresent("d") << endl;
    cout << "isPresent?" << bloom->isPresent("e") << endl;
    cout << "isPresent?" << bloom->isPresent("f") << endl;
    cout << "isPresent?" << bloom->isPresent("g") << endl;
    cout << "isPresent?" << bloom->isPresent("h") << endl;
    return 0;
}

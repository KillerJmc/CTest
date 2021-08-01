#include <iostream>
#include <tools>
#include <functional>

using namespace basic_std;

int main() {
    auto add = [](auto a, auto b) { return a + b; };
    cout << add(1, 2) << endl;
}


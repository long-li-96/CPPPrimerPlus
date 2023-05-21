#include <iostream>

struct Values {
    int firstarg;
    int secondarg;
};

Values getValues() {
    Values values;
    values.firstarg = 5;
    values.secondarg = 10;
    return values;
}

int main() {
    Values values = getValues();
    std::cout << "x: " << values.firstarg << "\ny: " << values.secondarg << std::endl;
    return 0;
}

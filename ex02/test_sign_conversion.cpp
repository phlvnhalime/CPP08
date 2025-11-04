#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    size_t i = 2;  // unsigned
    auto it = vec.begin();
    
    // This causes a sign conversion warning:
    int value = it[i];  // i is unsigned (size_t), but iterator subscript expects signed type
    
    std::cout << value << std::endl;
    return 0;
}

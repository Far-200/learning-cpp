#include <iostream>

// Each function call creates a NEW stack frame
int add(int a, int b) {
    int result = a + b;  // 'result' lives in THIS frame
    return result;
}   // ← frame destroyed here, 'result' is GONE

int main() {
    int x = 10;   // lives in main's stack frame
    int y = 20;   // lives in main's stack frame

    int sum = add(x, y);  // new frame pushed for add()

    std::cout << sum << "\n";
    return 0;
}   // ← main's frame destroyed, x, y, sum gone
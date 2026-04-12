#include <iostream>
#include <string>

// ❌ BAD: This COPIES the entire string onto the stack (expensive!)
void print_bad(std::string name) {
    std::cout << name << "\n";
}

// ✅ GOOD: const reference — read-only, NO copy made, zero overhead
void print_good(const std::string& name) {
    std::cout << name << "\n";
    // name = "hacked";  // ← compiler ERROR: it's const. Safe! ✅
}

int main() {
    std::string player = "Farhaan";

    print_bad(player);   // string is COPIED → wasteful
    print_good(player);  // string is REFERENCED → free

    return 0;
}
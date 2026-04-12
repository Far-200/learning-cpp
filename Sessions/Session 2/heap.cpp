#include <iostream>
#include <memory>   // for smart pointers

int main() {

    // ─── OLD WAY (raw pointer) ───────────────────────────────
    // Asking the OS: "give me space for one int on the heap"
    int* raw_ptr = new int(42);
    std::cout << "Raw heap value: " << *raw_ptr << "\n";
    delete raw_ptr;      // YOU must clean up. Forget this → memory leak 🚰
    raw_ptr = nullptr;   // Safety: null it after delete

    // ─── MODERN WAY (smart pointer) ──────────────────────────
    // unique_ptr: "I own this memory. When I die, it dies with me."
    auto smart_ptr = std::make_unique<int>(99);
    std::cout << "Smart heap value: " << *smart_ptr << "\n";

    // No delete needed! When smart_ptr goes out of scope → auto cleanup ✅
    return 0;
}
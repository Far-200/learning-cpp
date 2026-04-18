//Loops in C++
#include <iostream>
#include <vector>
//using namespace std;

int main(){
    //FizzBuzz: Rite of Passage
     std::vector<int> numbers = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
                                  11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
                                  21, 22, 23, 24, 25, 26, 27, 28, 29, 30 };
    for(const auto& i : numbers){
        if(i % 3 == 0 && i % 5 == 0){
            std::cout << "FizzBuzz" << std::endl;
        }
        else if(i % 3 == 0){
            std::cout << "Fizz" << std::endl;
        }
        else if(i % 5 == 0){
            std::cout << "Buzz" << std::endl;
        }
        else{
            std::cout << i << std::endl;
        }
    }
    return 0;
}
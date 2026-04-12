// #include <iostream>

// int main() {
//     // Standard character output
//     std::cout << "Hello, World!" << std::endl;
//     return 0;
// // }

// #include <iostream>
// //To swap two numbers.
// using namespace std;
// int main(){
//     int a, b;
//     cout<<"Enter the first Number:"<<endl;
//     cin>>a;

//     cout<<"Enter the second Number: "<< endl;
//     std::cin>>b;

//     int temp = a;
//     a = b;
//     b = temp;
//     cout<<"After Swapping: "<<endl;
//     cout<<"First Number: " << a << endl;
//     cout<<"Second Number: " << b << endl;
// }

#include <iostream>
#include <iomanip>

using namespace std;
int main(){
    string player_name;
    cout<<"Enter Player Name: "<<endl;
    cin>>player_name;
    int player_level;
    cout<<"Enter Player Level: "<<endl;
    cin>>player_level;
    double health_percentage;
    cout<<"Enter your health percentage: "<<endl;
    cin>>health_percentage;
    bool combat_status;
    cout<<"Enter combat status (true/false): "<<endl;
    cin>>combat_status;
    cout<<"Player Name: "<< player_name << endl;
    cout<<"Player Level: "<< player_level << endl;
    cout<<"Health Percentage: "<< health_percentage << endl;
    cout<< boolalpha;
    cout<<"Combat Status: "<< combat_status << endl;
    return 0;
}
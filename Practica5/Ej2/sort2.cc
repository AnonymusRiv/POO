// Vector Sorting Example.
// By Zereo 04/22/13
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main()
{
    // Warning this type of initialization requires a C++11 Compiler
    vector<int> intVec = {56, 32, -43, 23, 12, 93, 132, -154};
    vector<string> stringVec = {"John", "Bob", "Joe", "Zack", "Randy"};

    // Sorting the int vector
    sort(intVec.begin(), intVec.end());

    for (vector<int>::size_type i = 0; i != intVec.size(); ++i){
        cout << intVec[i] << " ";
    }

    cout << endl;

    // Sorting the string vector
    sort(stringVec.begin(), stringVec.end());

    // Ranged Based loops. This requires a C++11 Compiler also
    // If you don't have a C++11 Compiler you can use a standard
    // for loop to print your vector.
    for (string &s : stringVec){
        cout << s << " ";
    }

    cout<<endl;
    return 0;
}
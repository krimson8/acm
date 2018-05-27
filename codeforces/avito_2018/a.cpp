// Antipalindrome
#include <iostream>
#include <string>

using namespace std;

int checker(string input) {
    int ans;
    if(input.length() == 1) 
        return 1;

    if (input == string(input.rbegin(), input.rend())) {
        ans = checker(input.substr(1, input.length()));
    }
    else {
        //cout << input <<  " is not palindrome" << endl;
        return input.length();
    }

    return ans;
}

int main() {
    string input;
    cin >> input;

    int ans = checker(input);
    if(ans > 1) 
        cout << ans << endl;
    else
        cout << "0" << endl;

    return 0;
}
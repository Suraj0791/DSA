#include <bits/stdc++.h>
using namespace std;


// string s = "hello";
// cout << s.length();   // 5
// cout << s.size();     // 5
// cout << s[0];         // 'h'
// s[1] = 'a';           // "hallo"


// char str[6] = "hello"; // occupies 6 bytes: 'h' 'e' 'l' 'l' 'o' '\0'

// char str2[5] = "hello"; // ERROR: no space for null terminator

// char str3[] = {'h','e','l','l','o'}; // NOT a C-string, no '\0'


// char name[100];
// cin >> name;  // Input stops at space or newline



int main(){


string s = "hello";
cout << s.length();   // 5
cout << s.size();     // 5
cout << s[0];         // 'h'
s[1] = 'a';           // "hallo"


int age;
string name;

cin >> age;
cin.ignore();        // This consumes the leftover '\n'
getline(cin, name);  // Now this reads the full line

//  Rule of Thumb
// ✅ Always use cin.ignore() before getline() if:

// You already used cin >> ... to take number or word input



}
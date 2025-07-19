char name[100];
cin >> name;  // Input stops at space or newline

🔴 Example:
Input: suraj sharma → name becomes "suraj" only!

✅ Input: using cin.getline() — ✔️ safe
cin.getline(name, 100);
🔹 Reads the entire line (with spaces), max 99 chars + null terminator \0.

📘 2. Input/Output with string (C++ STL)

string s;
cin >> s;
⛔ Stops at space or newline.  ✅ Input: single word

✅ Input: whole line (with spaces)
string s;
getline(cin, s);


⚠️ Common Gotcha:
string name;
cin >> name;
getline(cin, name); // This will read an empty line!

✔️ Fix:
cin.ignore();        // ignore the leftover newline
getline(cin, name);  // now it works

🔄 Rule of Thumb
✅ Always use cin.ignore() before getline() if:

You already used cin >> ... to take number or word input.





C. Comparing string
string a = "abc", b = "abc";
if (a == b) cout << "same"; // ✅ correct

✍️ 6. Competitive Patterns
📌 Read t test cases, each with a string
int t;
cin >> t;
cin.ignore();
while (t--) {
    string s;
    getline(cin, s);
    cout << s << endl;
}









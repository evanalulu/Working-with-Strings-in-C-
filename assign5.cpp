/*
 * File: assign5.cpp
 * --------------
 * Evana Pradhan
 *
 * Write your code for Assignment 5 (C++ Strings) in the places indicated
 * in this file.
 */

#include <iostream>
#include "util.h"

using namespace std;

// Prototypes
string capitalize(string s);
string removeCharacters(string str, string remove);
string addCommas(string s);

// Each of the three functions below must return (NOT PRINT) 
// a string.

// Problem 1
string capitalize(string s)
{
    s = toLowerCase(s);
    s[0] = toUpperCase(s[0]);
    return s;
}

// Problem 2
string removeCharacters(string str, string remove)
{
    string res;
    set<char> rem;
    for (char c:remove) {
        rem.insert(c);
    }

    bool foundAny;

    for (char c:str) {
        bool is_in = rem.find(c) != rem.end();
        if (!is_in) {
            res += c;
        } else {
            foundAny = true;
        }
    }

    if (!foundAny)
        return "Requested string 'remove' not found.";

    return res;
}

// Problem 3
string addCommas(string s)
{
    for (int i = s.size() - 3; i > 0; i -= 3)
        s.insert(i, ",");
    return s;
}

int main()
{    
    // Testing capitalize()
    cout << "Testing capitalize()..." << endl;
    cout << "viva LAS vegas" << ": " << capitalize("viva LAS vegas") << endl;
    cout << "hello WORLD" << ": " << capitalize("hello WORLD") << endl;
    cout << endl;

    // Testing removeCharacters()
    cout << "Testing removeCharacters()..." << endl;
    cout << "removeCharacters('counterrevolutionaries', 'aeiou')): " << removeCharacters("counterrevolutionaries", "aeiou") << endl;
    cout << "removeCharacters('hello', 'llo'): " << removeCharacters("hello", "llo") << endl;
    cout << "removeCharacters('asdfg', '45'): " << removeCharacters("asdfg", "45") << endl;
    cout << endl;

    // Testing addCommas()
    cout << "Testing addCommas()..." << endl;
    cout << "100: " << addCommas("100") << endl;
    cout << "1200: "<< addCommas("1200") << endl;
    cout << "100000: "<< addCommas("100000") << endl;
    cout << "12345678910: "<< addCommas("12345678910") << endl;

}
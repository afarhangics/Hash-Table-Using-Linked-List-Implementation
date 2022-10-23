// FIRST WE INCLUDE ALL THE THINGS WE PLAN TO USE HERE

// FOR printf
#include <stdio.h>

// FOR cout
#include <iostream>
#include<string>
#include <sstream>
using namespace std;

// OUR STUFF
#include "Person.h"
#include "Student.h"
#include "Employee.h"
#include "ChainedHashTable.h"

const int NUM_BINS = 5;
const int KEY_LENGTH = 8;

void printHashTable(string header, ChainedHashTable<Person> *hashTable);

// EXECUTION OF OUR PROGRAM STARTS HERE
int main() {
    ChainedHashTable<Person> *hashTable = new ChainedHashTable<Person>(NUM_BINS, KEY_LENGTH);

    hashTable->put(hashTable->generateKey(), new Student("George", "Harrison", 4.0));
    hashTable->put(hashTable->generateKey(), new Employee("Paul", "McCartney", 80000));
    hashTable->put(hashTable->generateKey(), new Employee("Ringo", "Starr", 40000));
    hashTable->put(hashTable->generateKey(), new Employee("Chuck", "Berry", 100000));
    hashTable->put(hashTable->generateKey(), new Student("Mick", "Jagger", 3.5));
    hashTable->put(hashTable->generateKey(), new Student("Jimi", "Hendrix", 3.6));
    hashTable->put(hashTable->generateKey(), new Employee("Roger", "Waters", 90000));
    
    string jlKey = hashTable->generateKey();
    hashTable->put(jlKey, new Student("John", "Lennon", 3.8));
    string cwKey = hashTable->generateKey();
    hashTable->put(cwKey, new Student("Charlie", "Watts", 3.1));
    string dgKey = hashTable->generateKey();
    hashTable->put(dgKey, new Employee("David", "Gilmour", 120000));
    
    // AND DISPLAY THE HASH TABLE
    printHashTable("After Adding 10 Items", hashTable);

    // NOW TRY GETTING A FEW
    Person *p = hashTable->get(jlKey);
    cout << endl << "get " << jlKey << ": " << p->toString() << endl;
    p = hashTable->get(cwKey);
    cout << "get " << cwKey << ": " << p->toString() << endl;
    p = hashTable->get(dgKey);
    cout << "get " << dgKey << ": " << p->toString() << endl;
    
    // NOW LET'S TRY REPLACING THE DATA IN THE ABOVE THREE
    hashTable->put(jlKey, new Student("Otis", "Redding", 3.5));
    hashTable->put(cwKey, new Student("Keith", "Richards", 3.1));
    hashTable->put(dgKey, new Student("Bill", "Withers", 3.4));
    
    // AND DISPLAY THE HASH TABLE
    printHashTable("\nAfter Changing 3 Items", hashTable);

    return 0;
}

void printHashTable(string header, ChainedHashTable<Person> *hashTable) {
    string text = hashTable->toString();
    cout << header << endl;
    cout << text;
}
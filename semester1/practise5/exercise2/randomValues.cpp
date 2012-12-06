/* 
 * File:   randomValues.cpp
 * Author: Johannes Wahl
 * 
 * Created on 6. Dezember 2012, 16:35
 */

#include "randomValues.h"
#include <iostream>
#include <cstdlib>
#include <algorithm>

using std::rand;
using std::cout;
using std::endl;
using std::sort;

randomValues::randomValues() : ivalues(), svalues(), builder(" "), target(' '), convert(0) {
}

void randomValues::fillint(int totalitems) {
    for (int i = 0; i < totalitems; i++) {
        int num = (rand() % 100) + 1;
        ivalues.push_back(num);
    }
};

void randomValues::fillstring(int totalitems) {
    for (int i = 0; i < totalitems; i++) {

        for (int ii = 0; ii < 5; ii++) {
            int num = (rand() % 90) + 65;
            target = num;
            builder += target;
        }
        svalues.push_back(builder);
        builder.clear();
    }
};

void const randomValues::printallint() {
    for (int i = 0; i < ivalues.size(); i++) {
        cout << "int Element " << i << ": " << ivalues.at(i) << endl;
    }
};

void randomValues::printallstring() {
    for (int i = 0; i < svalues.size(); i++) {
        cout << "string Element " << i << ": " << svalues.at(i) << endl;
    }
};

int randomValues::intSeqSearch(int lookingfor) {
    for (int i = 0; i <= ivalues.size(); ++i)
        if (lookingfor == ivalues.at(i)) return i;
    return -1;
};

int randomValues::intBinSearch(int lookingfor) {

    sort(ivalues.begin(), ivalues.end());

    int ui(0);
    int oi = ivalues.size();
    int mid(0);

    while (ui <= oi) {
        mid = ui + ((oi - ui) / 2); // somit int Überlauf vermeiden
        if (lookingfor == ivalues[mid]) return mid;
        if (lookingfor < ivalues[mid]) oi = mid;
        else ui = mid;
    }
    return -1;
}

int randomValues::stringSeqSearch(string slookingfor) {
    for (int i = 0; i <= svalues.size(); ++i)
        if (slookingfor == svalues.at(i)) return i;
    return -1;
}



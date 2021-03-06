/*  ___  
 * |__ \ 
 *    ) |
 *   / / 
 *  / /_ 
 * |____|
 *
 * Outputs a string backwards an characters sorted by value
 * 
 * Created on 24. November 2012, 12:22
 * 
 */

#include "Triple.h"
#include "myError.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//void backwards(string in) {
//    int length = in.length();
//    for (int i = length - 1; i >= 0; i--) {
//        cout << in[i]; //output string backwards
//    }
//}
//
//void sortieren(string in) {
//    vector<char> signs;
//    char temp('a');
//
//    for (int i = 0; i < in.length(); i++) {
//        temp = in[i];
//        signs.push_back(temp);
//    }
//
//    sort(signs.begin(), signs.end()); //sort vector by value
//
//    for (int i = 0; i < signs.size(); i++) {
//        cout << signs.at(i); //output sorted vector
//    }
//
//}

int main() {

    try {

        string input ="test";
        Triple neu;
        cout<<input<<endl;
        neu.backwards(input);
        neu.sortieren(input);
               
        return 0;
    } catch (exception &e) {
        cerr << e.what();
    } catch (...) {
        error("Unbekannter Fehler");
    }

}


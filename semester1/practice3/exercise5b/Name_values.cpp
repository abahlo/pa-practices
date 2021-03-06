/* 
 * File:   Name_values.cpp
 * 
 * Created on 11. November 2012, 12:03
 */

#include <iostream>
#include "Name_values.h"

Name_values::Name_values() : name(""), values(0) { }

Name_values::Name_values( string Name, vector<int> vValue ) : name(Name), values(vValue) { }

string Name_values::get_name( ) const {
    return name;
}

void Name_values::add_value( int value ){
    values.push_back(value);
}

void Name_values::print_all( ) const {
    cout << endl << name << ": ";
    double sum = 0.0;
    for(int i = 0; i < values.size(); i++ ) {
        cout << values.at(i);
        if(i + 1 != values.size()) {
            cout << ", ";
        }
        sum += values.at(i);
    }
    cout << endl << "Durchschnitt: ";
    if(values.size() > 0) {
        cout << sum/values.size();        
    } else {
        cout << "Nicht vorhanden.";
    }
}

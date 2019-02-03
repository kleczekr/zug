#ifndef WAGON_H
#define WAGON_H

#include<iostream>
#include<string>
#include<vector>
#include<stdexcept>

using namespace std;

enum class Feature {Bar, Restaurant, Couchette, Standard, Toilet};

const vector<string> feature_name {"Bar", "Restaurant", 
        "Couchette", "Standard", "Toilet"};

class Wagon {
    int masse;
    Feature einrichtung;
public:
    Wagon(const int&, const Feature&);
    Wagon(const int&);
    int get_mass() const;
    bool has_feature(Feature) const;
    ostream& print(ostream&) const;
};

ostream& operator<<(ostream&, const Wagon&);

#endif
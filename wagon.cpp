#include<iostream>
#include<string>
#include<vector>
#include<stdexcept>
#include "wagon.h"

using namespace std;

Wagon::Wagon(const int& a, const Feature& b): masse{a}, einrichtung{b} {
    if (masse < 5 || masse > 100) {
        throw runtime_error("Wrong mass");
    }
}

Wagon::Wagon(const int& a): masse{a}, einrichtung{Feature::Standard} {
    if (masse < 5 || masse > 100) {
        throw runtime_error("Wrong mass");
    }
}

int Wagon::get_mass() const {
    return masse;
}

bool Wagon::has_feature(Feature feat) const {
    if (einrichtung == feat) {
        return true;
    } else {
        return false;
    }
}

ostream& Wagon::print(ostream& o) const {
    o << "[mass: " << masse << " tons " << feature_name.at(static_cast<size_t>(einrichtung)) << "-wagon]";
    return o;
}

ostream& operator<<(ostream& o, const Wagon& w) {
    return w.print(o);
}
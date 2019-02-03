#include<iostream>
#include<string>
#include<vector>
#include<stdexcept>
#include "train.h"

using namespace std;

Train::Train(const int& a, const int& b, const vector<Wagon>& c): lokmasse{a}, 
        maximallast{b}, wagonliste{c} {
    if (lokmasse < 50 || lokmasse > 200 || maximallast < 200 || maximallast > 10000) {
        throw runtime_error("wrong mass");
    }
}

Train::Train(const int& a, const int& b): lokmasse{a}, maximallast{b}, wagonliste{} {
    if(lokmasse < 50 || lokmasse > 200 || maximallast < 200 || maximallast > 10000) {
        throw runtime_error("wrong mass");
    }
}

int Train::total_load() const {
    int sum_mass = lokmasse;
    for (int i = 0; i < wagonliste.size(); ++i) {
        sum_mass += wagonliste[i].get_mass();
    }
    return sum_mass;
}

bool Train::ready() const {
    // is the Train.total_load() valid? Should it just be total_load?
    if (total_load() <= maximallast) {
        int count{0};
        for (int i = 0; i < wagonliste.size(); ++i) {
            if (wagonliste[i].has_feature(Feature::Toilet)) {
                count = 0;
            } else {
                ++count;
            }
            if (count > 3) {
                return false;
            }
        }
        int bar{0};
        int restaurant{0};
        int couchette{0};
        int standard{0};
        int toilet{0};
        for (int i = 0; i < wagonliste.size(); ++i) {
            if (wagonliste[i].has_feature(Feature::Bar)) {
                ++bar;
            }
            if (wagonliste[i].has_feature(Feature::Restaurant)) {
                ++restaurant;
            }
            if (wagonliste[i].has_feature(Feature::Couchette)) {
                ++couchette;
            }
            if (wagonliste[i].has_feature(Feature::Standard)) {
                ++standard;
            }
            if (wagonliste[i].has_feature(Feature::Toilet)) {
                ++toilet;
            }
        }
        if (bar > 0 && restaurant > 0 && couchette > 0 && standard > 0 && toilet > 0) {
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

void Train::couple(vector<Wagon> wagvect) {
    for (int i = 0; i < wagvect.size(); ++i) {
        wagonliste.push_back(wagvect[i]);
    }
}

vector<Wagon> Train::uncouple(size_t from) {
    vector<Wagon> temp {};
    vector<Wagon> disconnected {};
    if (from < wagonliste.size()) {
        for (int i = from; i < wagonliste.size(); ++i) {
            disconnected.push_back(wagonliste[i]);
        }
        for (int i = 0; i < from; ++i) {
            temp.push_back(wagonliste[i]);
        }
        wagonliste = temp;
        return disconnected;
    } else {
        throw runtime_error("Fuck off");
    }
}

ostream& Train::print(ostream& o) const {
    // Train.total_load or total_load?
    o << "[" << total_load() << "/" << maximallast << " tons, ";
    if (ready()) {
        o << "ready {";
    } else {
        o << "not ready {";
    }
    for (int i = 0; i < wagonliste.size(); ++i) {
        if (i != (wagonliste.size()-1)) {
            o << wagonliste[i] << ", ";
        } else {
            o << wagonliste[i];
        }
    }
    o << "}]";
    return o;
}

ostream& operator<<(ostream& o, const Train& t) {
    return t.print(o);
}

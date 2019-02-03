#ifndef TRAIN_H
#define TRAIN_H

#include<iostream>
#include<string>
#include<vector>
#include<stdexcept>
#include "wagon.h"

using namespace std;

class Train {
    int lokmasse;
    int maximallast;
    vector<Wagon> wagonliste;
public:
    Train(const int&, const int&, const vector<Wagon>&);
    Train(const int&, const int&);
    int total_load() const;
    bool ready() const;
    void couple(vector<Wagon>);
    vector<Wagon> uncouple(size_t);
    ostream& print(ostream&) const;
};

ostream& operator<<(ostream&, const Train&);

#endif
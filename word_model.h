/*
   CSCI 262 Data Structures, Fall 2019, Project 4 - Markov

   Author: Lucas Henke

   Modified: 10/24/2019
*/
#ifndef _WORD_MODEL_H
#define _WORD_MODEL_H

#include "model.h"
#include <sstream>
#include <map>
#include <vector>

using namespace std;

class word_model : public markov_model {
public:
    virtual void initialize(string text, int order);

    virtual string generate(int size);

    map<string, vector<string>> word_map;

    int order;

    // Add any helper methods you want here

protected:
    // Add any variables you may need here
};

#endif

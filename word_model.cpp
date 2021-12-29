/*
   CSCI 262 Data Structures, Fall 2019, Project 4 - Markov

   Author: Lucas Henke

   Modified: 10/24/2019
*/

#include "word_model.h"

void word_model::initialize(string text, int order) {
    this->order = order;

    istringstream sin(text);

    string prev;

    string cur;

    bool first = true;

    while (!sin.eof()) {

        if (first) {

            prev = cur;

            first = false;

            continue;

        }

        string cur;

        sin >> cur;

        if (word_map.find(cur) == word_map.end()) {

            word_map[prev] = {};

            word_map[prev].push_back(cur);

        } else {

            word_map[prev].push_back(cur);

        }

        prev = cur;

    }
}


string word_model::generate(int size) {

    string seed = "";

    auto it = word_map.begin();

    advance(it, rand() % word_map.size());

    string str = it->first;

    seed += str;

    string result = "";

    for (int i = order; i < size-order; i++) {

        vector<string> word_vec = word_map[seed];

        string s = word_vec[rand() % word_vec.size()];

        result += " " + s;

        seed = s;

    }

    return result;

}

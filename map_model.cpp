/*
   CSCI 262 Data Structures, Fall 2019, Project 4 - Markov

   Author: Lucas Henke

   Modified: 10/24/2019
*/

#include "map_model.h"

int random_0_to_n(int map_size);

void map_model::initialize(string text, int order) {

    //create a n-order char map
    text += text[0];

    this->order = order;

    int i = 0;

    while (i < text.size()-order) {

        string prev = text.substr(i, order);

        char cur = text.at(i+order);

        if (char_map.find(prev) == char_map.end()) {

            char_map[prev] = {};

            char_map[prev].push_back(cur);

        } else {

            char_map[prev].push_back(cur);

        }

        i++;

    }

}

string map_model::generate(int size) {
    string seed = "";

    auto it = char_map.begin();

    advance(it, rand() % char_map.size());

    string str = it->first;

    seed += str;

    string result = "";

    for (int i = order; i < size-order; i++) {

        vector<char> char_vec = char_map[seed];

        char c = char_vec[rand() % char_vec.size()];

        string s(1, c);

        result += s;

        seed = seed.substr(1) + s;

    }

    return result;
}

int random_0_to_n(int map_size) {

    if (map_size == 0) {

        return 0;

    }

    return (rand() % map_size);

}

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "AdventOfCode.h"

using namespace std;

string INPUT = "input.txt";

int main() {

    int overlap_sections = get_sections(true);
    cout<<"Number of fully overlapping section "<<overlap_sections<<endl;

    int partial_overlap_sections = get_sections(false);
    cout<<"Number of partially overlapping section "<<partial_overlap_sections<<endl;

    return 0;
}

int get_sections(bool full_overlap) {

    ifstream input; 
    input.open(INPUT);
    int overlap = 0;
    for( string line; getline( input, line ); ) {

        istringstream ss(line);
        string pair;
        ss>>pair;

        int split = find_split(pair, ',');
        string first_section = pair.substr(0,split);
        string secon_section = pair.substr(split+1);

        bool is_overlapping = find_overlap(first_section,secon_section, full_overlap);
        if(is_overlapping) overlap++;

    }

    return overlap;
}

bool find_overlap(string first, string second, bool full_overlap) {

    int split_first  = find_split(first, '-');
    int split_second = find_split(second, '-');

    int first_min  = stoi(first.substr(0,split_first));
    int first_max  = stoi(first.substr(split_first+1));
    int second_min = stoi(second.substr(0,split_second));
    int second_max = stoi(second.substr(split_second+1));

    bool fully_overlapping = false;
    if(second_min>=first_min && second_max<=first_max) fully_overlapping = true;
    else if (first_min>=second_min && first_max<=second_max) fully_overlapping = true;

    bool partial_overlapping = false;
    if(second_min<=first_max && second_max>=first_max) partial_overlapping = true;
    else if(first_min<=second_max && first_max>=second_max) partial_overlapping = true;

    if(full_overlap) return fully_overlapping;
    else return partial_overlapping;

}

int find_split(string string_to_split, char delimiter) {

    int split = 0;
    for(int i = 0; i<string_to_split.length(); i++){
        char character = string_to_split[i];
        if(character==delimiter) break;
        else split++;
    }

    return split;
}

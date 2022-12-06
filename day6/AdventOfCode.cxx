#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "AdventOfCode.h"

using namespace std;

string INPUT = "input.txt";

int main() {

    cout<<"=== Running over case 4"<<endl;
    get_string(4);

    cout<<"=== Running over case 14"<<endl;
    get_string(14);

    return 0;
}


int get_marker(string line, int size_group){

    int first_marker = 0;
    for(int i = 0; i<line.length()-size_group-1; i++) {
        vector<char> four_group;
        for(int j = 0; j<size_group; j++) four_group.push_back(line[i+j]);
            int group_total_count = 0;
            for(int j = 0; j<size_group; j++) group_total_count += count(four_group.begin(),four_group.end(),four_group.at(j));
            if(group_total_count==size_group) {
                first_marker = i+size_group;
                break;
            } 
    }

    return first_marker;
}

void get_string(int size_group){

    ifstream input; 
    input.open(INPUT);
    for( string line; getline( input, line ); ) {
        int first_marker = get_marker(line, size_group);
        cout<<"First Marker for line "<<line<<endl;
        cout<<first_marker<<endl;
    }
}

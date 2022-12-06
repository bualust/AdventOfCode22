#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "AdventOfCode.h"

using namespace std;

string INPUT = "input.txt";

int main() {

    int first_marker = get_string(4);
    cout<<"First marker is "<<first_marker<<endl;

    int message_marker = get_string(14);
    cout<<"Start of message marker is "<<message_marker<<endl;

    return 0;
}


int get_string(int size_group){

    ifstream input; 
    input.open(INPUT);

    int first_marker = 0;
    for( string line; getline( input, line ); ) {

        for(int i = 0; i<line.length()-size_group-1; i++) {
            vector<char> four_group;
            for(int j = 0; j<size_group; j++) four_group.push_back(line[i+j]);
                int group_total_count = 0;
                for(int j = 0; j<size_group; j++) {
                    group_total_count += count(four_group.begin(),four_group.end(),four_group.at(j));
                }
                if(group_total_count==size_group) {
                    first_marker = i+size_group;
                    break;
                } 
        }

    }
    return first_marker;
}

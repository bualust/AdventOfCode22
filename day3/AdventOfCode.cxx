#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "AdventOfCode.h"

using namespace std;

string INPUT = "input.txt";

int main() {

    int priority_1 = get_priority(1);
    cout<<"First priority is "<<priority_1<<endl;

    int priority_2 = get_priority(2);
    cout<<"Second priority is "<<priority_2<<endl;

    return 0;
}

int get_priority(int which) {

    ifstream input; 
    input.open(INPUT);
    int total_prior= 0;
    int lines_count = 1;
    string first, second, third;
    for( string line; getline( input, line ); ) {

        istringstream ss(line);
        string rucksack;
        ss>>rucksack;

        int split = rucksack.length()/2;
        string first_compart = rucksack.substr(0,split);
        string secon_compart = rucksack.substr(split);

        vector<string> compartments = {first_compart,secon_compart};
        int priority_1 = common_priority(compartments);

        int priority_2 = 0;
        if(lines_count==1) {
            first = rucksack;
            lines_count++;
        } else if (lines_count==2) {
            second = rucksack;
            lines_count++;
        } else if (lines_count==3) {
            third = rucksack;
            vector<string> bunches = {first,second,third};
            priority_2 = common_priority(bunches);
            lines_count = 1;
        }

        if(which == 1) total_prior+=priority_1;
        if(which == 2) total_prior+=priority_2;
    }

    return total_prior;
}


int common_priority(vector<string> rucksacks) {

     vector<vector<bool>> occurancies;
     for(int i = 0; i < rucksacks.size()-1; i++) {
         vector<bool> occ(52,0);
         occurancies.push_back(occ);
     }

     int priority = 0;
     for(int i = 0; i < rucksacks.size(); i++) {
         string rucksack = rucksacks.at(i);
         for(int j=0;j<rucksack.length();j++){
             if(i==0) {
                occurancies[i][rucksack[j]-'A'] = true;
             } else if(i>0 && i<rucksacks.size()-1) {
                if (occurancies[i-1][rucksack[j] - 'A']) occurancies[i][rucksack[j]-'A'] = true;
             } else {
                if (occurancies[i-1][rucksack[j] - 'A']) {
                    priority = convert_priority(int(rucksack[j]));
                }
             }
         }
     }

     return priority;
}

int convert_priority(int ascii) {

    if(ascii>=97){
        return ascii-96;
    } else {
        return ascii-38;
    }

}

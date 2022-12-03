#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "AdventOfCode.h"

using namespace std;

string INPUT = "input.txt";

int main() {

    int priority_1 = get_priority_1();
    cout<<"First priority is "<<priority_1<<endl;

    int priority_2 = get_priority_2();
    cout<<"Second priority is "<<priority_2<<endl;

    return 0;
}

int get_priority_1() {

    ifstream input; 
    input.open(INPUT);
    int total_prior= 0;
    for( string line; getline( input, line ); ) {

        istringstream ss(line);
        string rucksack;
        ss>>rucksack;

        int split = rucksack.length()/2;
        string first_compart = rucksack.substr(0,split);
        string secon_compart = rucksack.substr(split);

        int priority = common_priority_1(first_compart,secon_compart);
        total_prior+=priority;
    }

    return total_prior;
}

int get_priority_2() {

    ifstream input; 
    input.open(INPUT);
    int total_prior = 0;
    int lines_count = 1;
    string first, second, third;
    for( string line; getline( input, line ); ) {

        istringstream ss(line);
        string rucksack;
        ss>>rucksack;

        if(lines_count==1) {
            first = rucksack;
            lines_count++;
        } else if (lines_count==2) {
            second = rucksack;
            lines_count++;
        } else if (lines_count==3) {
            third = rucksack;
            int priority = common_priority_2(first,second,third);
            total_prior+=priority;
            lines_count = 1;
        }
    }

    return total_prior;
}

int common_priority_2(string first, string second, string third) {

     vector<bool> occ(52,0);
     for(int i=0;i<first.length();i++){
         occ[first[i]-'A']=true;
     }

     vector<bool> occ2(52,0);
     for (int i = 0; i <second.length(); i++){
         if (occ[second[i] - 'A']) occ2[second[i]-'A']=true;
     }

     int priority = 0;
     for (int i = 0; i <third.length(); i++){
         if (occ2[third[i] - 'A']) {
             priority = convert_priority(int(third[i]));
         }
     }

     return priority;
}

int common_priority_1(string first, string second) {

     vector<bool> occ(52,0);
     for(int i=0;i<first.length();i++){
         occ[first[i]-'A']=true;
     }

     int priority = 0;
     for (int i = 0; i <second.length(); i++){
         if (occ[second[i] - 'A']) {
             priority = convert_priority(int(second[i]));
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

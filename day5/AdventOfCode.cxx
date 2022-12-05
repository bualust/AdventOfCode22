#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "AdventOfCode.h"

using namespace std;

string INPUT = "input.txt";

int main() {

    vector<vector<char>> piles = get_piles();
    string top_stack0 = operate_crane(piles,9000);
    cout<<"Top stack crates are "<<top_stack0<<endl;

    string top_stack1 = operate_crane(piles,9001);
    cout<<"Top stack crates are "<<top_stack1<<endl;
    return 0;
}

string operate_crane(vector<vector<char>> piles, int crane_number){

    ifstream input; 
    input.open(INPUT);

    for( string line; getline( input, line ); ) {

        if(line[0]!='m') continue;

        istringstream ss(line);
        string token;

        vector<string> line_split;
        while(std::getline(ss, token, ' ')) line_split.push_back(token);

        vector<char> *pile_from = &piles[stoi(line_split.at(3))-1];
        vector<char> *pile_to   = &piles[stoi(line_split.at(5))-1];

        int crates_to_move = stoi(line_split.at(1));
        if(crane_number==9000){
            for(int i = 1; i<=crates_to_move;i++){
                int pile_from_size = pile_from->size();
                char crate = pile_from->at(pile_from_size-1);
                pile_to->push_back(crate);
                pile_from->pop_back();
            }
        } else if(crane_number==9001){
            vector<char> crates_group = {pile_from->end()-crates_to_move,pile_from->end()};
            for(int i = 0; i<crates_group.size(); i++) {
                pile_to->push_back(crates_group[i]);
                pile_from->pop_back();
            }
        }

    }

    string top_stack;
    for(int i = 0; i < piles.size(); i++){
        vector<char> *pile = &piles[i];
        char top_crate = pile->at(pile->size()-1);
        top_stack.push_back(top_crate);
    }

    return top_stack;
}

int get_num_of_piles() {

    ifstream input; 
    input.open(INPUT);
    string first_line;
    getline( input, first_line );
    return (first_line.length()+1)/4;

}

vector<vector<char>> get_piles() {

    ifstream input; 
    input.open(INPUT);
    int num_of_piles = get_num_of_piles();
    vector<vector<char>> piles(num_of_piles);

    for( string line; getline( input, line ); ) {

        if(line[1]=='1') break;
        int piles_count = 1;
        for(int i = 0; i<line.length(); i++) {
            int crate_pos = 4*piles_count-3;
            if(i/crate_pos==1){
                if(int(line[i])!=32) piles[piles_count-1].push_back(line[i]);
                piles_count++;
            }
        }

    }

    for(int i = 0; i < piles.size(); i++){
        vector<char> *pile = &piles[i];
        reverse(pile->begin(),pile->end());
    }

    return piles;

}

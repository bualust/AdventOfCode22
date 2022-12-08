#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "AdventOfCode.h"

using namespace std;

string INPUT = "input.txt";

int main() {

    vector<vector<int>> forest = get_forest();
    int length = forest.size();
    int depth  = forest.at(0).size();
    int edges_trees = 2*(length-1)+2*(depth-1);
    int inner_trees = 0;
    int max_scenic_score = 0;
    for(int i = 1; i<length-1; i++){
        for(int j = 1; j<depth-1; j++){
            vector<int> is_visible_from_side = check_row(forest[i], forest[i][j], j); 
            vector<int> is_visible_from_vert = check_column(forest, forest[i][j], i, j); 
            if(is_visible_from_side.at(0) || is_visible_from_vert.at(0) ||
               is_visible_from_side.at(1) || is_visible_from_vert.at(1)) inner_trees++;
            int scenic_score = is_visible_from_side.at(2)*is_visible_from_vert.at(2)*is_visible_from_side.at(3)*is_visible_from_vert.at(3);
            if(scenic_score>max_scenic_score) max_scenic_score = scenic_score;
        }
    }

    cout<<"Trees at the edges  "<<edges_trees<<"\nTrees in the middles "<<inner_trees<<endl;
    int visible_trees = edges_trees+inner_trees;
    cout<<"Visible trees "<<visible_trees<<endl;
    cout<<"Max scenic score is "<<max_scenic_score<<endl;

    return 0;
}

vector<int> check_column(vector<vector<int>> forest, int tree, int col_index, int row_index) {

    vector<int> is_visible;
    int is_visible_up   = 1;
    int is_visible_down = 1;
    int view_up  = 0;
    int view_down= 0;
    for(int i = 0; i<forest.size(); i++){
        if(i==col_index) continue;
        if(i<col_index) {
            if(forest[i][row_index]>=tree) {
                view_up = col_index - i;
                is_visible_up   = 0;
            }
        } else {
            if(is_visible_down) view_down++;
            if(forest[i][row_index]>=tree) {
                is_visible_down = 0;
            }
        }
    }

    if(is_visible_up)  view_up   = col_index;

    is_visible.push_back(is_visible_up);
    is_visible.push_back(is_visible_down);
    is_visible.push_back(view_up);
    is_visible.push_back(view_down);
    return is_visible;
}

vector<int> check_row(vector<int> row, int tree, int row_index) {

    vector<int> is_visible;
    int is_visible_left  = 1;
    int is_visible_right = 1;
    int view_left  = 0;
    int view_right = 0;
    for(int i = 0; i<row.size(); i++){
        if(i==row_index) continue;
        if(i>row_index) {
            if(is_visible_right) view_right++;
            if(row.at(i)>=tree) {
                is_visible_right = 0;
            }
        } else {
            if(row.at(i)>=tree) {
                view_left = row_index-i;
                is_visible_left = 0;
            }
        }
    }

    if(is_visible_left)  view_left  = row_index;

    is_visible.push_back(is_visible_left);
    is_visible.push_back(is_visible_right);
    is_visible.push_back(view_left);
    is_visible.push_back(view_right);
    return is_visible;
}

vector<vector<int>> get_forest(){

    ifstream input; 
    input.open(INPUT);
    vector<vector<int>> forest;
    for( string line; getline( input, line ); ) {
        vector<int> row;
        for(int i = 0; i<line.length(); i++) row.push_back(line[i]-'0');
        forest.push_back(row);
    }

    return forest;
}


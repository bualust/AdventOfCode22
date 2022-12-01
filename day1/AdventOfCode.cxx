//Day1
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

vector<int> get_elves_cal();

int main() {

    vector<int> elves_cal = get_elves_cal();

    int number_of_elves = int(elves_cal.size());
    cerr<<"Number of elves is "<<number_of_elves<<endl;

    sort(elves_cal.begin(), elves_cal.end());
    int max_calories = elves_cal.at(number_of_elves-1);
    cerr<<"Max calories are "<<max_calories<<endl;

    int top_three = 0;
    for(int i = 0; i<3; i++){
        int index = number_of_elves-i-1;
        top_three+=elves_cal.at(index);
    }
    cerr<<"Top three elves calories "<<top_three<<endl;
    return 0;
}

vector<int> get_elves_cal(){

    vector<int> out_elves_cal;
    ifstream input; 
    input.open("input.txt");
    int calories = 0;
    for( string line; getline( input, line ); ) {
        if(!line.empty()) {
            calories+=stoi(line);
        } else {
            out_elves_cal.push_back(calories);
            calories=0;
        }
    }
    return out_elves_cal;
}

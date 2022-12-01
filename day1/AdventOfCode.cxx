//Day1
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

std::vector<int> get_helves_cal();

int main() {

    std::vector<int> helves_cal = get_helves_cal();

    int number_of_helves = int(helves_cal.size());
    std::cerr<<"Number of helves is "<<number_of_helves<<std::endl;

    int max_calories = helves_cal.at(0);
    for(int i = 0; i < int(helves_cal.size()); i++){
        if(helves_cal.at(i)>max_calories) max_calories=helves_cal.at(i);
    }
    std::cerr<<"Max calories are "<<max_calories<<std::endl;

    std::sort(helves_cal.begin(), helves_cal.end());
    int top_three = 0;
    for(int i = 0; i<3; i++){
        int index = number_of_helves-i-1;
        top_three+=helves_cal.at(index);
    }
    std::cerr<<"Top three helves calories "<<top_three<<std::endl;

    return 0;
}

std::vector<int> get_helves_cal(){

    std::vector<int> out_helves_cal;
    std::ifstream input; 
    input.open("input.txt");
    int calories = 0;
    for( std::string line; getline( input, line ); ) {
        if(!line.empty()) {
            std::stringstream ss(line);
            int new_calories;
            ss>>new_calories;
            calories+=new_calories;
        } else {
            out_helves_cal.push_back(calories);
            calories=0;
        }

    }

    return out_helves_cal;
}

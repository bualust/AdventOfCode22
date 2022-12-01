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

    std::sort(helves_cal.begin(), helves_cal.end());
    int max_calories = helves_cal.at(number_of_helves-1);
    std::cerr<<"Max calories are "<<max_calories<<std::endl;

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
            calories+=std::stoi(line);
        } else {
            out_helves_cal.push_back(calories);
            calories=0;
        }
    }
    return out_helves_cal;
}

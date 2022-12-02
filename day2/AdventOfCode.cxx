//Day1
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <array>

using namespace std;

map<int, array<string,2> > get_rounds();
int get_score_1(map<int, array<string,2> > rounds);
int get_score_2(map<int, array<string,2> > rounds);

int main() {

    map<int,array<string,2>> rounds = get_rounds();

    int score1 = get_score_1(rounds);
    cout<<"First score is "<<score1<<endl;

    int score2 = get_score_2(rounds);
    cout<<"Second score is "<<score2<<endl;

    return 0;
}

int get_score_2(map<int,array<string,2>> rounds) {

    int score = 0;
    for (const auto itr : rounds) {
        array<string,2> values = itr.second;
        string value1 = values[0];
        string value2 = values[1];

        //first the score for the round outcome (loose, draw, win)
        if(value2=="X") score+=0;
        else if(value2=="Y") score+=3;
        else if(value2=="Z") score+=6;

        //second the score for the choice (rock, paper, scissor)
        if(value2=="X"){
            if(value1 == "A") score+=3;
            else if(value1 == "B") score+=1;
            else if(value1 == "C") score+=2;
        } else if(value2=="Y") {
            if(value1 == "A") score+=1;
            else if(value1 == "B") score+=2;
            else if(value1 == "C") score+=3;
        } else if(value2=="Z") {
            if(value1 == "A") score+=2;
            else if(value1 == "B") score+=3;
            else if(value1 == "C") score+=1;
        }
    }

    return score;
}

int get_score_1(map<int,array<string,2>> rounds) {

    int score = 0;
    for (const auto itr : rounds) {
        array<string,2> values = itr.second;
        string value1 = values[0];
        string value2 = values[1];

        //first the score for the choice (rock, paper, scissor)
        if(value2=="X") score+=1;
        else if(value2=="Y") score+=2;
        else if(value2=="Z") score+=3;

        //remapping opponent to have same labelling
        if(value1 == "A") value1="X";
        else if(value1 == "B") value1="Y";
        else if(value1 == "C") value1="Z";

        //second the score for the round outcome (win, draw, loose)
        if(value1==value2) { score+=3;
        } else {
            if(value2=="X") {
                if(value1 == "Y") score+=0;
                if(value1 == "Z") score+=6;
            } else if(value2=="Y") {
                if(value1 == "X") score+=6;
                if(value1 == "Z") score+=0;
            } else if(value2=="Z") {
                if(value1 == "X") score+=0;
                if(value1 == "Y") score+=6;
            }
        }
    }

    return score;
}

map<int,array<string,2>> get_rounds() {
    
    ifstream input; 
    input.open("input.txt");
    map<int,array<string,2>> rounds;
    int index = 0;
    for( string line; getline( input, line); ) {
        istringstream ss(line);
        array<string,2> values;
        ss >> values[0]>> values[1];
        rounds[index] = values;
        index++;
    }

    return rounds;
}

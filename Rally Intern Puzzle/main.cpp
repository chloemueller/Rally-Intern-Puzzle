//
//  main.cpp
//  Rally Intern Puzzle
//
//  Created by Chloe Mueller on 1/12/18.
//  Copyright © 2018 Chloe Mueller. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;

ifstream in_file;
int con;    // number of people contemplating
int need;   // number of people needed
int current = 0;    // current number of runners
int out = 0;    // output number


int runnersNeeded() {
    char ch;
    while (in_file.get(ch)) {   // checking for end of file
        in_file.unget();
        
    in_file >> need >> con;
    
    if (need > current) {
        out += need - current;
    }
    current += con + (need - current);
    }
    
    return out;
}

int main() {
    // check for file error
    in_file.open("input.txt");
    if(in_file.fail()) {
        cout << "Error Opening File.";
        return 9;
    }
    runnersNeeded();
    cout << out << endl;
    in_file.close();
    return 0;
}

#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;


int main()
{
    ifstream InputFile("input.txt");
    string myText;
    map<char, char> defeatMap;
    defeatMap['A'] = 'B';
    defeatMap['B'] = 'C';
    defeatMap['C'] = 'A';

    map<char, char> winMap;
    winMap['B'] = 'A';
    winMap['C'] = 'B';
    winMap['A'] = 'C';

    map<char, int> pointsMap;
    pointsMap['A'] = 1;
    pointsMap['B'] = 2;
    pointsMap['C'] = 3;

    char opponent;
    char todo;
    int totalPoints = 0;
    while (getline (InputFile, myText)) {
        opponent = myText[0];
        todo = myText[2];

        if(todo == 'Y'){
            totalPoints += pointsMap[opponent] + 3;
        }

        if(todo == 'Z'){
            totalPoints += pointsMap[defeatMap[opponent]] + 6;
        }

        if(todo == 'X'){
            totalPoints += pointsMap[winMap[opponent]];
        }
   }

   cout<<totalPoints;
}
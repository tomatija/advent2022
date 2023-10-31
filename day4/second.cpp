

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    ifstream InputFile("input.txt");
    string myText;
    int firstMin;
    int firstMax;
    int secondMin;
    int secondMax;

    int numOfCompleteOverlap = 0;

    string first;
    string second;
    while (getline (InputFile, myText)) {
        first = myText.substr(0, myText.find(','));

        second = myText.substr(myText.find(',')+1, myText.length());

        firstMin = stoi(first.substr(0,first.find('-')));

        firstMax = stoi(first.substr(first.find('-')+1, first.length()));

        secondMin = stoi(second.substr(0,second.find('-')));

        secondMax = stoi(second.substr(second.find('-')+1, second.length()));
        
        if((firstMin >= secondMin && firstMin <= secondMax) || (firstMax >= secondMin && firstMax <= secondMax) || (secondMin >= firstMin && secondMin <= firstMax) || (secondMax >= firstMin && secondMax <= firstMax)){
            numOfCompleteOverlap ++;
        }
    }
    cout<<numOfCompleteOverlap;
}
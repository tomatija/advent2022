#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int value = 14;// 4 for first

bool containsAllUnique(char buffer[value]){
    for (unsigned i = 0; i < value; i++){
        for (unsigned k = i + 1; k < value; k++){
            if (buffer[i] == buffer[k]){
                return false;
            }
        }
    }
    return true;
}

void shiftDownAndAdd(char buffer[value], char newElement){
    for(int x = 1; x < value; x++){
        buffer[x - 1] = buffer[x];
    }
    buffer[value - 1] = newElement;
}

int main()
{
    ifstream InputFile("input.txt");
    string myText;

    char currentBuffer[value];
    bool start = true;
    int answer = value;
    while (getline (InputFile, myText)) {
        if(start){
            for(int x = 0; x < value; x++){
                currentBuffer[x] = myText[x];
            }
        }
        if(containsAllUnique(currentBuffer)){
            break;
        }
        for(int x = value; x < myText.length(); x++){
            shiftDownAndAdd(currentBuffer, myText[x]);
            answer++;
            if(containsAllUnique(currentBuffer)){
                break;
            }
        }
    }
    cout<<answer;
    return 0;
}
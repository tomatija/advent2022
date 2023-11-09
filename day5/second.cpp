#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

 vector<string> splitString(string inputString, string delimiter){
    vector<string> result;

    string tempString = "";
    while(inputString.length() > 0){
        if(inputString.find(delimiter, 0) != -1){
            tempString = inputString.substr(0, inputString.find(delimiter, 0));
            inputString = inputString.substr(inputString.find(delimiter, 0) + 1, inputString.length());
        }else{
            tempString = inputString.substr(0, inputString.length());
            inputString = "";
        }
        result.push_back(tempString);
    }
    return result;
}

class Stack{
    public:
        vector<string> crates;
    
        void addCrateToStack(string crate, bool setup){
            if(setup){
                crates.insert(crates.begin(), crate);
            }else{            
                crates.push_back(crate);
            }
        }

        string takeCrateFromStack(){
            string crateToReturn;
            if(!crates.empty()){
                crateToReturn = crates.back();
                crates.pop_back();
                return crateToReturn;
            }
            return NULL;
        }
};

vector<Stack> prepareStacks(){
    ifstream InputFile("input.txt");
    string myText;
    vector<Stack> stacks;
    string currentChar;
    int position;
    int stackIndex;
    bool stacksPrepared = false;

    while (getline (InputFile, myText)) {
        if(myText.at(1) == '1'){
            break;
        }
        if(!stacksPrepared){
            for(int i = 0; i < (myText.length() + 1)/4; i++){
                stacks.push_back(Stack());
            }
            stacksPrepared = true;
        }
        position = 0;
        stackIndex = 0;
        while(position <= myText.length()){
            currentChar = myText.substr(position, 3)[1];
            if(currentChar != " "){
                stacks[stackIndex].addCrateToStack(currentChar, true);
            }
            position += 4;
            stackIndex ++;
        }
    }
    return stacks;
}

void executeCrateMove(int startStack, int destinationStack, vector<Stack>& stacks, int numOfCrates){
    vector<string> poppedCrates;
    for(int i = 0; i < numOfCrates; i++){
        poppedCrates.push_back(stacks[startStack].takeCrateFromStack());
    }
    for(int i = 0; i < numOfCrates; i++){
        string crateToMove = poppedCrates.back();
        poppedCrates.pop_back();
        stacks[destinationStack].addCrateToStack(crateToMove, false);
    }

}

void printStacks(vector<Stack> stacks){
    for(int i = 0; i < stacks.size(); i++){
        if(stacks[i].crates.size() != 0){
            cout<<stacks[i].crates[stacks[i].crates.size() - 1];
        }

    }
}

void handleCrateMoving(vector<Stack>& stacks){
    ifstream InputFile("input.txt");
    string myText;

    vector<string> splitElements;
    bool readyToRead = false;
    while (getline (InputFile, myText)) {
        if(!readyToRead && myText.at(1) == '1'){
            readyToRead = true;
            continue;
        }
        if(readyToRead){
            splitElements = splitString(myText, " ");
            if(splitElements.size() > 0){
                executeCrateMove(stoi(splitElements[3]) - 1, stoi(splitElements[5]) - 1, stacks, stoi(splitElements[1]));
            }
        }
    }
}


int main()
{
    vector<Stack> stacks = prepareStacks();
    handleCrateMoving(stacks);
    printStacks(stacks);
}
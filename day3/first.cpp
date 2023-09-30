#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;


class Rugsack{
    public:
        vector<char> bag1; 
        vector<char> bag2;

        void placeItemsInBags(string items){
            for(int i = 0; i < items.size(); i++){
                if(i < items.size()/2){
                    bag1.push_back(items[i]);
                }else{
                    bag2.push_back(items[i]);
                }
            }
            sort(bag1.begin(), bag1.end());
            sort(bag2.begin(), bag2.end());
        }

        char getSameItemFromBags(){
            for(int i = 0; i < bag1.size(); i++){
                for(int j = 0; j < bag2.size(); j++){
                    if(bag1.at(i) == bag2.at(j)){
                        return bag1.at(i);
                    }
                }
            }
            return ' ';
        }

        int getItemPriorityValue(char item){
            int value;
            if (isLowerCase(item)){
                value = (int)item - (int)'A'- 32;
            }else{
                value = (int)item - (int)'A' + 26;
            }
            return value + 1;
        }
    private:
        bool isLowerCase(char item){
            if((int)item >= 97){
                return true;
            }
            return false;
        }
};

int main()
{
    ifstream InputFile("input.txt");
    string myText;

    Rugsack latest_sack;
    int priorityPoints = 0;
    char test;
    while (getline (InputFile, myText)) {
        latest_sack = Rugsack();
        
        latest_sack.placeItemsInBags(myText);
        
        test = latest_sack.getSameItemFromBags();
        priorityPoints += latest_sack.getItemPriorityValue(test);
    }

    cout<<priorityPoints;
}
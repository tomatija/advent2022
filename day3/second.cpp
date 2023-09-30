#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;


class Rugsack{
    public:
        vector<char> bags[3]; 

        void placeItemsInFirstEmptyBag(string items){
            int firstEmptyBagIndex = 0;
            for(int i = 0; i < 3; i++){
                if(bags[i].size() == 0){
                    firstEmptyBagIndex = i;
                    break;
                }
            }
            for(int i = 0; i < items.size(); i++){
                bags[firstEmptyBagIndex].push_back(items[i]);
            }
            sort(bags[firstEmptyBagIndex].begin(), bags[firstEmptyBagIndex].end());
        }

        char getSameItemFromBags(){
            vector<char> potentialSameItems;
            for(int i = 0; i < bags[0].size(); i++){
                for(int j = 0; j < bags[1].size(); j++){
                    if(bags[0].at(i) == bags[1].at(j)){
                        potentialSameItems.push_back(bags[0].at(i));
                    }
                }
            }
            for(int i = 0; i < bags[2].size(); i++){
                for(int j = 0; j < potentialSameItems.size(); j++){
                    if(bags[2].at(i) == potentialSameItems.at(j)){
                        return potentialSameItems.at(j);
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

    Rugsack latest_sack = Rugsack();
    int priorityPoints = 0;
    int groupIndexCheck = 0;
    while (getline (InputFile, myText)) {
        if(groupIndexCheck == 3){
            // do processing before creating new sack
            char sameItem = latest_sack.getSameItemFromBags();

            priorityPoints += latest_sack.getItemPriorityValue(sameItem);
            latest_sack = Rugsack();
            groupIndexCheck = 0;
        }

        latest_sack.placeItemsInFirstEmptyBag(myText);
        groupIndexCheck ++;
    }
    char sameItem = latest_sack.getSameItemFromBags();

    priorityPoints += latest_sack.getItemPriorityValue(sameItem);

    cout<<priorityPoints;
}
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;


int main()
{
   ifstream InputFile("input.txt");
   string myText;
   vector<int> calories;
   int tempCalories = 0;
   while (getline (InputFile, myText)) {
      if (myText == ""){
         calories.push_back(tempCalories);
         tempCalories = 0;
      }else{
         tempCalories += stoi( myText );
      }
   }
   sort(calories.begin(), calories.end(), greater<int>());
   int result = calories.at(0) + calories.at(1) + calories.at(2);
   cout<<result;
   InputFile.close();
   return 0;
}
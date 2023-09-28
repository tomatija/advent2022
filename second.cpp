#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
   ifstream InputFile("input.txt");
   string myText;
   int tempCalories = 0;
   int maxCalories = 0;
   while (getline (InputFile, myText)) {
      if (myText == ""){
         if (tempCalories > maxCalories){
            maxCalories = tempCalories;
         }
         tempCalories = 0;
      }else{
         tempCalories += stoi( myText );
      }
   }
   cout<<maxCalories;
   InputFile.close();
   return 0;
}
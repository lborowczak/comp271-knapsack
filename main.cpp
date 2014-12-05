#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

//global so that we can create vectors of storableItem s
//Structure that stores the information needed for each item
//doubles used so that we can accomodate fractions of a pound or cubic inch
struct storableItem {
    double volume;
    double weight;
    double price;
    string itemName;
    };

vector<storableItem> getItems();
//vector<storableItem> calculateBestItemVal(vector<storableItem> listOfItems, int maxWeight, int maxVol);
void printItems(vector<storableItem> items);
double getDouble(string request);
int main()
{
    double maxWeight, maxVol; //variable to store the maximum weight the backpack can hold and the maximum volume it can hold
    vector<storableItem> listOfItems, optimItems; //initial vector of all items and vector of the optimized items

    maxWeight=getDouble("What is the maximum weight that your backback can hold (in pounds)?"); //ask user how much weight the backpack can hold

    maxVol = getDouble("What is the volume of the backpack (in cubic inches)?");    //ask user what the volume of the backpack is

    listOfItems = getItems();  //get the list of items from the user
    cout << "Calculating items, please wait..." << endl;
    //optimItems = calculateBestItemsVal(listOfItems, maxWeight, maxVol);
    printItems(listOfItems);
    //printItems(optimItems);

    cout << "test" << endl;
    return 0;
}

vector<storableItem> getItems()
{
    vector<storableItem> items;
    string tempResponse = "", tempName;
    storableItem *tempItem;
    cout << "Please enter the information about your items:" << endl;

    while (tolower(tempResponse[0]) != 'y') //Keep asking for items until they respond that they are done adding items
    {
        tempItem = new storableItem;

        cout << "What is the name of the item?" << endl;
        getline(cin, tempName); //allows use of spaces in input
        tempItem->itemName = tempName;

        tempItem->weight = getDouble("How much does the item weigh (in pounds)?");  //ask for weight of item

        tempItem->volume = getDouble("How much space does the item take up (in cubic inches)?");    //ask for volume of item

        tempItem->price = getDouble("What is the price of the item (in dollars)?"); //ask user for the price of the item

        items.push_back(*tempItem);

        cout << "Are you done adding items (y/n)?" << endl;
        getline(cin, tempResponse);
    }
    return items;
}

vector<storableItem> calculateBestItemVal(vector<storableItem> items, int maxWeight, int maxVol)
{
    vector<storableItem>calculateBestItemVal;
    double totalWeight;
    while (totalWeight<maxWeight) //While loop to ensure maxweight isn't exceeded.
    {
        for(int i=0; i<=items.size(); i++) //For loop that going through each value(or item) in items until maxsize is reached
        {
            for(int w=0; w<=maxWeight; w++) //for loop that goes through each value weight until maxWeight is reached
            {
                for(int v=0; v<=maxVol; v++) //for loop that goes through each value voluem until maxVol is reached
                {
                    if(i==0||w==0||v==0) //if values at i, w or v equal zero, calculateBestItemVal equal zero
                    {
                        calculateBestItemVal[i][w][v]=0;
                    }
                    else if(items[i-1]weight) <= maxWeight||items[i-1]volume<=maxVol)//checks if previous weight and volume was less than/equal to maxWeight and maxVolume
                    {
                        //stores
                        calculateBestItemVal[i][w][v] = max(items[i-1]price + calculateBestItemVal[i-1][w-items[i-1].weight][v-items[i-1].volume], calculateBestItemVal[i-1][w][v]);//gets max value at and put thems into calculateBestItemVal

                        totalWeight += items[i].weight; //adds weight of item to total weight
                    }
                    else
                    {
                        calculateBestItemVal[i][w][v]=calculateBestItemVal[i-1][w][v];
                        totalWeight +=items[i].weight;
                    }
                }
            }
            return calculateBestItemVal[i][w][v];
        }
    }
}
void printItems(vector<storableItem> items)
{
    cout << "To spend the least amount of money, you should take the following items:" << endl;
    for (int i=0; i< items.size(); i++)
    {
        cout << "Item " << i+1 << ": " << items[0].itemName << endl;
    }
}

double getDouble(string request) //safely get double from input, from http://www.cplusplus.com/forum/articles/6046/
{
    string input;
    double tmpVal;
    bool valid=false;
    while (!valid)
    {
        cout << request << endl;
        getline(cin, input);
        stringstream converter(input);
        if (converter >> tmpVal)
            valid=true;
        else
        {
            cout << "That is not a valid number.  Please enter a valid number." << endl;
        }
    }
    return tmpVal;
}

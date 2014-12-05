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
vector<storableItem> calculateBestItemVal(vector<storableItem> items, double maxWeight, double maxVol);
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
    optimItems = calculateBestItemVal(listOfItems, maxWeight, maxVol);
    printItems(optimItems);
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

vector<storableItem> calculateBestItemVal(vector<storableItem> items, double maxWeight, double maxVol)
{
    vector<storableItem>bestItemVal;
    int numOfItems = items.size(), tmpIndex;
    double pricePercent[numOfItems], tmpMax, currWeight = 0, currVol = 0;

    for (int i=0; i < numOfItems; i++)
    {
        if (items[i].weight > maxWeight || items[i].volume > maxVol)    //if the item doesn't fit, don't consider it
            pricePercent[i] = -1.0;
        else
        {
            pricePercent[i] = (((items[i].weight / maxWeight) + (items[i].volume / maxVol)) / items[i].price);
        }
    }
    while (currWeight < maxWeight && currVol < maxVol)
    {
        tmpIndex = -1;
        tmpMax = 0xDFFFFFFF;
        for (int j=0; j < numOfItems; j++) //find the most efficient item
        {
            //if the price per percentage of space of the current item is lower than the previous one, and adding this item will not overfill the backpack, make it the new max
            if (pricePercent[j] < tmpMax && currWeight + items[j].weight <= maxWeight && currVol + items[j].volume <= maxVol && pricePercent[j] > 0)
            {
                tmpMax = pricePercent[j];
                tmpIndex = j;
            }
        }
        if (tmpIndex != -1) //if a minimum value was found, add the item to the vector of items to bring
        {
            bestItemVal.push_back(items[tmpIndex]); //add the item to the list of optimized values
            currVol += items[tmpIndex].volume; //update the current volume
            currWeight += items[tmpIndex].weight; //update the current weight
            pricePercent[tmpIndex] = -1; //make sure we don't add the same item again
        }
        else break;
    }
    return bestItemVal;
}
void printItems(vector<storableItem> items)
{
    cout << "To spend the least amount of money, you should take the following items:" << endl;
    for (int i=0; i < items.size(); i++)
    {
        cout << "Item " << i+1 << ": " << items[i].itemName << endl;
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
        if (converter >> tmpVal && tmpVal > 0)
            valid=true;
        else
        {
            cout << "That is not a valid number.  Please enter a valid number." << endl;
        }
    }
    return tmpVal;
}

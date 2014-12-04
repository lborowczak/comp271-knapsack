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

*
vector<storableItem> calculateBestItemVal(vector<storableItem> listOfItems, int maxWeight, int maxVol)
{
vector<storableItems>knapsack;
double totalWeight;
while (totalWeight<maxWeight) //While loop to ensure maxweight isn't exceeded. 
{
    for(int i=1; i<items.size(); i++) //For loop that going through each value(or item) in items until maxsize is reached
    {
       items[i]weight/items[i]vol = wvpct[i]; //divides weight by items to create wvpct
       items[i]price/wvpct[i]=itemsValue[i]; //divides price by wvpct to create itemsValue
        double greatest = itemValue[0];
        if(itemValue[i]>largest)//if statement if itemvalue at value i is greater than value at greatest
        {
            greatest=itemValue[i]; //greatest becomest item value at i
        }
        greatest = knapsack.push_back(i); //adds smallest to end of vector knapsack
        totalWeight +=item[i]weight;//adds weight of item i to total weight
    }
}
//if large number of items, add progress bar?
}
*/

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

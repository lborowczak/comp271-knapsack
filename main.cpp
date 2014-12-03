#include <iostream>
#include <vector>
#include <string>

using namespace std;

//global so that we can create vectors of storableItem s
//Structure that stores the information needed for each item
//doubles used so that we can accomodate fractions of a pound
struct storableItem {
    double volume;
    double weight;
    double price;
    string itemName;
    };

vector<storableItem> getItems();
//vector<storableItem> calculateBestItemVal(vector<storableItem> listOfItems, int maxWeight, int maxVol);
//void printItems(vector<storableItem> items);
int main()
{
    double maxWeight, maxVol; //variable to store the maximum weight the backpack can hold and the maximum volume it can hold
    vector<storableItem> listOfItems, optimItems; //initial vector of all items and vector of the optimized items

    cout << "What is the maximum weight that your backback can hold (in pounds)?" << endl; //ask user how much weight the backpack can hold
    cin >> maxWeight;

    cout << "What is the volume of the backpack (in cubic inches)?" << endl; //ask user what the volume of the backpack is
    cin >> maxVol;

    listOfItems = getItems();  //get the list of items from the user
    //optimItems = calculateBestItemsVal(listOfItems, maxWeight, maxVol);
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
        getline(cin, tempResponse); //fix input from previous use of cin so getline works
        tempItem = new storableItem;

        cout << "What is the name of the item?" << endl;
        getline(cin, tempName); //allows use of spaces in input
        tempItem->itemName = tempName;

        cout << "How much does the item weigh (in pounds)?" << endl;
        cin >> tempItem->weight;

        cout << "How much space does the item take up (in cubic inches)?" << endl;
        cin >> tempItem->volume;

        cout << "what is the price of the item (in dollars)?" << endl;
        cin >> tempItem->price;

        items.push_back(*tempItem);

        cout << "Are you done adding items (y/n)?" << endl;
        cin >> tempResponse;
    }
    return items;
}

/*
vector<storableItem> calculateBestItemVal(vector<storableItem> listOfItems, int maxWeight, int maxVol)
{



}

void printItems(vector<storableItem> items)
{

}

*/

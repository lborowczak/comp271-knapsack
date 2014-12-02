#include <iostream>
#include <vector>
#include <string>

using namespace std;

//global so that we can create vectors of storableItem s
//Structure that stores the information needed for each item
struct storableItem {
    int volume;
    int weight;
    double price;
    char *itemName;
    };

vector<storableItem> getItems();
//vector<storableItem> calculateBestItemVal(vector<storableItem> listOfItems, int maxWeight, int maxVol);
//void printItems(vector<storableItem> items);
int main()
{
    int maxWeight, maxVol; //variable to store the maximum weight the backpack can hold and the maximum volume it can hold
    vector<storableItem> listOfItems, optimItems; //initial vector of all items and optimized
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
    /*
    item entry loop goes here
    */
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

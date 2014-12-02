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

int main()
{
    int maxWeight, maxVol; //variable to store the maximum weight the backpack can hold and the maximum volume it can hold
    vector<storableItem> listOfItems; //initial vector of all items
    cout << "How many items do you want to take with you?" << endl;  //ask user how many items they will want to take
    cin >> numOfItems;
    cout << "What is the maximum weight that your backback can hold (in pounds)?" << endl; //ask user how much weight the backpack can hold
    cin >> maxWeight;
    cout << "What is the volume of the backpack (in cubic inches)?" << endl; //ask user what the volume of the backpack is
    cin >> maxVol;

    listOfItems = getItems();  //get the list of items from the user

    cout << "test" << endl;
    return 0;
}

vector<storableItem> getItems(int numOfItems)
{
    vector<storableItem> items;
    return items;
}

/*

*/

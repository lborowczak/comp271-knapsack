#include <iostream>
#include <vector>
#include <string>

using namespace std;

//global so that we can create vectors of storableItem s
//
struct storableItem {
    int area;
    int weight;
    double price;
    char *itemName;
    };

vector<storableItem> getItems(int numOfItems);

int main()
{
    int numOfItems; //variable to store the number of items the person needs to bring, the maximum weight the backpack can hold, and the maximum
    vector<storableItem> listOfItems; //initial vector of all items
    cout << "How many items do you want to take with you?" << endl;
    cin >> numOfItems;
    listOfItems = getItems(numOfItems);  //get the list of items

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

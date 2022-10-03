#ifndef ITEMLIST_H_INCLUDED
#define ITEMLIST_H_INCLUDED

#include <vector>
#include "Item.h"

class ItemList{
// Private Variables
private:
    vector<Item> itemList; // Declared vector

// Public Variables
public:
    ItemList(); //Constructor
    ~ItemList(); // Destructor
    void addItem(Item& obj);
    void printItem();
    void findItemID();
    void findItemName();
    void writeFile();
    void readFile(Item pobj, ItemList pitem);
    void sortID (void);
};

#endif // ITEMLIST_H_INCLUDED

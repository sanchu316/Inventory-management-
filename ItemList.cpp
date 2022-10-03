#include <iostream>
#include <fstream>
#include "ItemList.h"
#include "Item.h"

using namespace std;

//Constructor--Initial allocation of the class object
ItemList::ItemList()
{

}
//Destructor
ItemList::~ItemList()
{

}

//Dynamic memory allocation
void ItemList::addItem(Item& obj)
{
    itemList.push_back(obj);
}

//Function to print items calling Item class
void ItemList::printItem()
{
    for(int i=0; i<itemList.size(); ++i)
    {
        itemList[i].printItems();
    }
}

//To find by ID
void ItemList::findItemID()
{
    int id;

    cout<<"Enter the Item ID to be found: "<< endl;
    cin>>id;

    for(int i=0; i<itemList.size(); i++)
    {
        if(itemList[i].getId()==id)
        {
            cout<<"The Item details are: \n";
            itemList[i].printItems();
            break;
        }

        else if (i >= itemList.size() -1 && itemList[i].getId() != id)
        {
            cout<<"Error: Item not Found!"<<endl;
            break;
        }
    }
}

//To find by name
void ItemList::findItemName()
{
    string name;
    cout<<"Enter the name to be searched: "<<endl;
    getline(cin>>ws, name);

    for(int i=0; i<itemList.size();i++)
    {
        if(itemList[i].getName()==name)
        {
            cout<<"The Item details are: \n";
            itemList[i].printItems();
            break;
        }
        else if(i >= itemList.size() -1 && itemList[i].getName() != name)
        {
            cout<<"Error: Item not found!"<<endl;
            break;
        }
    }
}

//Writing to file
void ItemList::writeFile()
{
    ofstream myOut;
    myOut.open("InventoryList.txt", ios::app);
    for (int i=0; i<itemList.size(); ++i)
    {
        itemList[i].printFormattedItem(myOut);
    }
    myOut.close();
}

//Read all the details from the file
void ItemList::readFile(Item pobj, ItemList pitem)
{
    unsigned short tid;
    string tname;
    float tcost;
    int tquantity;

    ifstream myOut;
    myOut.open("InventoryList.txt", ios::in);
    if (!myOut.is_open())
    {
        cout<<"Error: File not found"<<endl;
    }
    else
    {
        for(;;)
        {
            myOut>>tid;
            pobj.setId(tid);
            myOut.ignore();
            getline(myOut, tname);
            pobj.setName(tname);
            myOut>>tcost;
            pobj.setCost(tcost);
            myOut>>tquantity;
            pobj.setQuantity(tquantity);

            if (myOut.good())
            {
                Item(tid, tname, tcost, tquantity);
                pitem.addItem(pobj);
            }
            else if(myOut.eof())
            {
                break;
            }
        }
    }
    myOut.close();
}
//Sort by ID Function
void ItemList::sortID (void)
{
    int MAX;
    int flag;
    Item obj;

    vector<Item>::iterator pos1, pos2, holder, counter;

    pos1=itemList.begin();
    pos2=itemList.end();

    for (int k=0; flag<itemList.size(); k++)
    {
        counter=pos1;
        MAX = 0;

        for (int i=0; i<(itemList.size()-flag); i++)
        {
            if(itemList[i].getId()>MAX)
            {
                MAX=itemList[i].getId();
                holder=counter;
            }
            ++counter;
        }
        obj.newItem(* holder);
        pos2--;
        (* holder).newItem(*pos2);
        (* pos2).newItem(obj);
        ++flag;
    }
}

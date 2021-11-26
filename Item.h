#ifndef ITEM_H
#define ITEM_H

#include <iostream>

using namespace std;

class Item
{
    int id;
    int userId;
    int date;
    string item;
    double amount;

public:
    int getId();
    int getUserId();
    int getDate();
    string getItem();
    double getAmount();
    void setId(int id);
    void setUserId(int userId);
    void setDate(int date);
    void setItem(string item);
    void setAmount(double amount);
    bool operator < (const Item& item);
};

#endif // ITEM_H

#include "Item.h"

int Item::getId() {
    return id;
}

int Item::getUserId() {
    return userId;
}

int Item::getDate() {
    return date;
}

string Item::getItem() {
    return item;
}

double Item::getAmount() {
    return amount;
}

void Item::setId(int id) {
    if (id > 0)
        this -> id = id;
}

void Item::setUserId(int userId) {
    this -> userId = userId;
}

void Item::setDate(int date) {
    this -> date = date;
}

void Item::setItem(string item) {
    this -> item = item;
}

void Item::setAmount(double amount) {
    this -> amount = amount;
}

bool Item::operator < (const Item& rhs) {
    return this -> date < rhs.date;
}

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

void Item::setId(int newId) {
    id = newId;
}

void Item::setUserId(int newUserId) {
    userId = newUserId;
}

void Item::setDate(int newDate) {
    date = newDate;
}

void Item::setItem(string newItem) {
    item = newItem;
}

void Item::setAmount(double newAmount) {
    amount = newAmount;
}

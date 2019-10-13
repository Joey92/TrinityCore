//
// Created by GLaDOS on 09.06.2019.
//

#include <World/World.h>
#include "Government.h"

uint32 Government::GetMoney() const {
    return _money;
}

Government::Government(const char* name) {
    _name = name;
    _money = 0;
    _incomeTax = 10;
    _salesTax = 19;
}

const char* Government::GetName() const {
    return _name;
}

int32 Government::Tax(int32 amount) {
    int32 taxed;
    if (amount > 0) {
        taxed = abs(round(amount * _incomeTax / 100));
    } else {
        taxed = abs(round(amount * _salesTax / 100));
    }

    _money += taxed;
    char strBuff[256];
    sprintf(strBuff, "Current funds of %s: %d", GetName(), GetMoney());
    sWorld->SendServerMessage(SERVER_MSG_STRING, strBuff);
    return taxed;
}

ObjectGuid Government::GetHead() {
    return _head;
}

void Government::SetHead(ObjectGuid newHead) {
    _head = newHead;
}

uint8 Government::GetSalesTax() {
    return _salesTax;
}

uint8 Government::GetIncomeTax() {
    return _incomeTax;
}

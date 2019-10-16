/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include <World/World.h>
#include "Government.h"

int32 Government::GetMoney() const {
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
    sprintf(strBuff, "Current funds of %s: %s", GetName(), GetFormattedMoney());
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

const char* Government::GetFormattedMoney() const {
    int32 money = GetMoney();

    int32 copper = money % 100;
    int32 silver = (money / 100) % 100;
    int32 gold = money / 10000;

    char strBuff[256];
    sprintf(strBuff, "Current funds of %dg %ds %dc", gold, silver, copper);

    return strBuff;
}

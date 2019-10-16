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

#ifndef TRINITYCORE_GOVERNMENT_H
#define TRINITYCORE_GOVERNMENT_H


#include <Define.h>
#include <Entities/Object/ObjectGuid.h>
#include <atomic>

class Government {

private:

    const char* _name;
    ObjectGuid _head;
    std::atomic<int32> _money;
    uint8 _incomeTax;
    uint8 _salesTax;

public:
    Government(const char* name);

    const char* GetName() const;

    int32 GetMoney() const;
    const char* GetFormattedMoney() const;

    // returns amount taxed
    int32 Tax(int32 amount);
    ObjectGuid GetHead();

    void SetHead(ObjectGuid newHead);

    uint8 GetSalesTax();
    uint8 GetIncomeTax();
};


#endif //TRINITYCORE_GOVERNMENT_H

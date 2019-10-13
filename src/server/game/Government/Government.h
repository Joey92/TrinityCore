//
// Created by GLaDOS on 09.06.2019.
//

#ifndef TRINITYCORE_GOVERNMENT_H
#define TRINITYCORE_GOVERNMENT_H


#include <Define.h>
#include <Entities/Object/ObjectGuid.h>
#include <atomic>

class Government {

private:

    const char* _name;
    ObjectGuid _head;
    std::atomic<uint32> _money;
    uint8 _incomeTax;
    uint8 _salesTax;

public:
    Government(const char* name);

    const char* GetName() const;

    uint32 GetMoney() const;

    // returns amount taxed
    int32 Tax(int32 amount);
    ObjectGuid GetHead();

    void SetHead(ObjectGuid newHead);

    uint8 GetSalesTax();
    uint8 GetIncomeTax();
};


#endif //TRINITYCORE_GOVERNMENT_H

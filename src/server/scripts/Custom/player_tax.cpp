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

#include "ScriptMgr.h"
#include "player.h"
#include <World/World.h>

class player_tax : public PlayerScript {

public:
    player_tax() : PlayerScript("player_tax") { }

    void OnMoneyChanged(Player *player, int32& amount) {
        const uint32 amountTaxed = player->GetCitizenship()->Tax(amount);

        char strBuff[256];
        sprintf(strBuff, "You pay %d in taxes to the %s", amountTaxed, player->GetCitizenship()->GetName());
        sWorld->SendServerMessage(SERVER_MSG_STRING, strBuff, player);

        if (amount > 0) {
            amount = amount - amountTaxed;
        } else {
            amount = amount + amountTaxed;
        }
        
    }
};

void AddSC_TaxingPlayerScript()
{
    new player_tax();
}

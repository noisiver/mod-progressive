#include "Chat.h"
#include "Config.h"
#include "Player.h"

#include "mod_progressive.h"

void Progressive::OnLogin(Player* player)
{
    ChatHandler(player->GetSession()).SendSysMessage(PatchTitle[PatchId]);

    if (PatchId < FALL_OF_THE_LICH_KING && !EnableDungeonFinder)
        ChatHandler(player->GetSession()).SendSysMessage("Note: The Dungeon Finder is not available in this patch.");
}

void Progressive::OnUpdateArea(Player* player, uint32 /*oldArea*/, uint32 newArea)
{
    if (player->IsGameMaster())
        return;

    if (PatchId < SECRETS_OF_ULDUAR)
    {
        if (newArea == AREA_ARGENT_TOURNAMENT_GROUNDS)
        {
            ChatHandler(player->GetSession()).SendSysMessage("The argent tournament grounds are currently unavailable.");
            player->TeleportTo(571, 8163.57f, 799.76f, 484.03f, 3.18f);
        }
    }
}

bool Progressive::OnUpdateFishingSkill(Player* /*player*/, int32 /*skill*/, int32 /*zone_skill*/, int32 chance, int32 roll)
{
    if (PatchId < SECRETS_OF_ULDUAR)
        if (chance < roll)
            return false;

    return true;
}

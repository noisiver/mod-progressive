#include "mod_progressive.h"

void Progressive::OnLogin(Player* player)
{
    ChatHandler(player->GetSession()).SendSysMessage(ProgressionPatchTitle[patchId]);

    if (patchId < FALL_OF_THE_LICH_KING)
        ChatHandler(player->GetSession()).SendSysMessage("Note: The Dungeon Finder is not available in this patch.");
}

bool Progressive::OnBeforeCriteriaProgress(Player* /*player*/, AchievementCriteriaEntry const* /*criteria*/)
{
    return patchId >= ECHOES_OF_DOOM;
}

bool Progressive::OnBeforeAchiComplete(Player* /*player*/, AchievementEntry const* /*achievement*/)
{
    return patchId >= ECHOES_OF_DOOM;
}

void Progressive::OnUpdateArea(Player* player, uint32 /*oldArea*/, uint32 newArea)
{
    if (player->IsGameMaster())
        return;

    if (patchId < CALL_OF_THE_CRUSADE)
    {
        if (newArea == ARGENT_TOURNAMENT_GROUNDS)
        {
            ChatHandler(player->GetSession()).SendSysMessage("The argent tournament grounds are currently unavailable.");
            player->TeleportTo(571, 8163.57f, 799.76f, 484.03f, 3.18f);
        }
    }
}

bool Progressive::ShouldBeRewardedWithMoneyInsteadOfExp(Player* player)
{
    if (patchId < STORMS_OF_AZEROTH)
        return false;

    return player->GetLevel() == sWorld->getIntConfig(CONFIG_MAX_PLAYER_LEVEL);
}

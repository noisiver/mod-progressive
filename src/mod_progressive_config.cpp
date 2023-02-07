#include "Config.h"
#include "OutdoorPvPMgr.h"

#include "mod_progressive.h"

void Progressive::OnAfterConfigLoad(bool reload)
{
    if (reload)
        return;

    PatchId = sConfigMgr->GetOption<int>("Progressive.Patch", ASSAULT_ON_THE_RUBY_SANCTUM);
    DualTalent = sConfigMgr->GetOption<bool>("Progressive.DualTalent", false);
    DungeonFinder = sConfigMgr->GetOption<bool>("Progressive.DungeonFinder", false);
    QuestPOI = sConfigMgr->GetOption<bool>("Progressive.QuestPOI", false);
    ShowPatchNotes = sConfigMgr->GetOption<bool>("Progressive.PatchNotes", false);

    // Health Regen
    sWorld->setBoolConfig(CONFIG_LOW_LEVEL_REGEN_BOOST, PatchId >= FALL_OF_THE_LICH_KING);

    // Auto accept
    sWorld->setBoolConfig(CONFIG_QUEST_IGNORE_AUTO_ACCEPT, PatchId < CALL_OF_THE_CRUSADE);

    // Dungeon Finder
    sWorld->setIntConfig(CONFIG_LFG_OPTIONSMASK, (PatchId < FALL_OF_THE_LICH_KING && !DungeonFinder ? 0 : 5));

    // Dual Talent Specialization
    sWorld->setIntConfig(CONFIG_MIN_DUALSPEC_LEVEL, (PatchId < SECRETS_OF_ULDUAR && !DualTalent ? 255 : 40));

    // Quests
    sWorld->setBoolConfig(CONFIG_QUEST_POI_ENABLED, !(PatchId < FALL_OF_THE_LICH_KING && !QuestPOI));

    // Tradable items
    sWorld->setBoolConfig(CONFIG_SET_BOP_ITEM_TRADEABLE, PatchId >= CALL_OF_THE_CRUSADE);

    // Arena
    if (PatchId == ECHOES_OF_DOOM)
        sWorld->setIntConfig(CONFIG_ARENA_SEASON_ID, 5);
    else if (PatchId == SECRETS_OF_ULDUAR)
        sWorld->setIntConfig(CONFIG_ARENA_SEASON_ID, 6);
    else if (PatchId == CALL_OF_THE_CRUSADE)
        sWorld->setIntConfig(CONFIG_ARENA_SEASON_ID, 7);
    else if (PatchId >= FALL_OF_THE_LICH_KING)
        sWorld->setIntConfig(CONFIG_ARENA_SEASON_ID, 8);
}

void Progressive::OnStartup()
{
    if (PatchId < FALL_OF_THE_LICH_KING && !QuestPOI)
    {
        if (CreatureQuestItemMap* cqi = const_cast<CreatureQuestItemMap*>(sObjectMgr->GetCreatureQuestItemMap()))
            cqi->clear();

        if (GameObjectQuestItemMap* gqi = const_cast<GameObjectQuestItemMap*>(sObjectMgr->GetGameObjectQuestItemMap()))
            gqi->clear();
    }
}

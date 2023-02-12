#include "Config.h"
#include "OutdoorPvPMgr.h"

#include "mod_progressive.h"

void Progressive::OnAfterConfigLoad(bool reload)
{
    if (reload)
        return;

    PatchId = sConfigMgr->GetOption<int>("Progressive.Patch", ASSAULT_ON_THE_RUBY_SANCTUM);
    EnableDualTalent = sConfigMgr->GetOption<bool>("Progressive.DualTalent.Enabled", false);
    EnableDungeonFinder = sConfigMgr->GetOption<bool>("Progressive.DungeonFinder.Enabled", false);
    EnableQuestPOI = sConfigMgr->GetOption<bool>("Progressive.QuestPOI.Enabled", false);
    EnabledIcecrownBuff = sConfigMgr->GetOption<int>("Progressive.IcecrownCitadel.Buff", 3);
    EnablePatchNotes = sConfigMgr->GetOption<bool>("Progressive.PatchNotes.Enabled", false);

    if (PatchId > ASSAULT_ON_THE_RUBY_SANCTUM)
        PatchId = ASSAULT_ON_THE_RUBY_SANCTUM;

    // Icecrown Citadel Buff
    if (PatchId >= ASSAULT_ON_THE_RUBY_SANCTUM)
    {
        if (EnabledIcecrownBuff > 0)
        {
            sWorld->setIntConfig(CONFIG_ICC_BUFF_ALLIANCE, SPELL_ICECROWN_CITADEL_30_A);
            sWorld->setIntConfig(CONFIG_ICC_BUFF_HORDE, SPELL_ICECROWN_CITADEL_30_H);
        }
        else
        {
            sWorld->setIntConfig(CONFIG_ICC_BUFF_ALLIANCE, SPELL_ICECROWN_CITADEL_25_A);
            sWorld->setIntConfig(CONFIG_ICC_BUFF_HORDE, SPELL_ICECROWN_CITADEL_25_H);
        }
    }
    else
    {
        if (EnabledIcecrownBuff > 2)
        {
            sWorld->setIntConfig(CONFIG_ICC_BUFF_ALLIANCE, SPELL_ICECROWN_CITADEL_20_A);
            sWorld->setIntConfig(CONFIG_ICC_BUFF_HORDE, SPELL_ICECROWN_CITADEL_20_H);
        }
        else if (EnabledIcecrownBuff > 1)
        {
            sWorld->setIntConfig(CONFIG_ICC_BUFF_ALLIANCE, SPELL_ICECROWN_CITADEL_15_A);
            sWorld->setIntConfig(CONFIG_ICC_BUFF_HORDE, SPELL_ICECROWN_CITADEL_15_H);
        }
        else if (EnabledIcecrownBuff > 0)
        {
            sWorld->setIntConfig(CONFIG_ICC_BUFF_ALLIANCE, SPELL_ICECROWN_CITADEL_10_A);
            sWorld->setIntConfig(CONFIG_ICC_BUFF_HORDE, SPELL_ICECROWN_CITADEL_10_H);
        }
        else
        {
            sWorld->setIntConfig(CONFIG_ICC_BUFF_HORDE, SPELL_ICECROWN_CITADEL_5_H);
            sWorld->setIntConfig(CONFIG_ICC_BUFF_ALLIANCE, SPELL_ICECROWN_CITADEL_5_A);
        }
    }

    // Health Regen
    sWorld->setBoolConfig(CONFIG_LOW_LEVEL_REGEN_BOOST, PatchId >= FALL_OF_THE_LICH_KING);

    // Auto accept
    sWorld->setBoolConfig(CONFIG_QUEST_IGNORE_AUTO_ACCEPT, PatchId < CALL_OF_THE_CRUSADE);

    // Dungeon Finder
    sWorld->setIntConfig(CONFIG_LFG_OPTIONSMASK, (PatchId < FALL_OF_THE_LICH_KING && !EnableDungeonFinder ? 0 : 5));

    // Dual Talent Specialization
    sWorld->setIntConfig(CONFIG_MIN_DUALSPEC_LEVEL, (PatchId < SECRETS_OF_ULDUAR && !EnableDualTalent ? 255 : 40));

    // Quests
    sWorld->setBoolConfig(CONFIG_QUEST_POI_ENABLED, !(PatchId < FALL_OF_THE_LICH_KING && !EnableQuestPOI));

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
    if (PatchId < FALL_OF_THE_LICH_KING && !EnableQuestPOI)
    {
        if (CreatureQuestItemMap* cqi = const_cast<CreatureQuestItemMap*>(sObjectMgr->GetCreatureQuestItemMap()))
            cqi->clear();

        if (GameObjectQuestItemMap* gqi = const_cast<GameObjectQuestItemMap*>(sObjectMgr->GetGameObjectQuestItemMap()))
            gqi->clear();
    }
}

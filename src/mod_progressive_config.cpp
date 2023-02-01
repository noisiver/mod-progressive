#include "mod_progressive.h"

void Progressive::UpdateConfigOptions()
{
    if (patchId < BEFORE_THE_STORM)
    {
        sWorld->setIntConfig(WorldIntConfigs::CONFIG_EXPANSION, EXPANSION_CLASSIC);
        sWorld->setIntConfig(WorldIntConfigs::CONFIG_MAX_PLAYER_LEVEL, 60);
    }
    else if (patchId < ECHOES_OF_DOOM)
    {
        sWorld->setIntConfig(WorldIntConfigs::CONFIG_EXPANSION, EXPANSION_THE_BURNING_CRUSADE);
        sWorld->setIntConfig(WorldIntConfigs::CONFIG_MAX_PLAYER_LEVEL, 70);
    }
    else
    {
        sWorld->setIntConfig(WorldIntConfigs::CONFIG_EXPANSION, EXPANSION_WRATH_OF_THE_LICH_KING);
        sWorld->setIntConfig(WorldIntConfigs::CONFIG_MAX_PLAYER_LEVEL, 80);
    }

    // Health Regen
    sWorld->setBoolConfig(WorldBoolConfigs::CONFIG_LOW_LEVEL_REGEN_BOOST, patchId >= FALL_OF_THE_LICH_KING);

    // Dungeon Finder
    sWorld->setIntConfig(WorldIntConfigs::CONFIG_LFG_OPTIONSMASK, (patchId < FALL_OF_THE_LICH_KING ? 0 : 5));

    // Dual Talent Specialization
    sWorld->setIntConfig(WorldIntConfigs::CONFIG_MIN_DUALSPEC_LEVEL, (patchId < SECRETS_OF_ULDUAR ? 255 : 40));

    // Quests
    sWorld->setBoolConfig(WorldBoolConfigs::CONFIG_OBJECT_QUEST_MARKERS, patchId >= THE_GODS_OF_ZUL_AMAN);
    sWorld->setBoolConfig(WorldBoolConfigs::CONFIG_OBJECT_SPARKLES, patchId >= THE_GODS_OF_ZUL_AMAN);
    sWorld->setBoolConfig(WorldBoolConfigs::CONFIG_QUEST_POI_ENABLED, patchId >= CALL_OF_THE_CRUSADE);

    // Weather
    sWorld->setBoolConfig(WorldBoolConfigs::CONFIG_WEATHER, patchId >= STORMS_OF_AZEROTH);

    // Wintergrasp
    sWorld->setIntConfig(WorldIntConfigs::CONFIG_WINTERGRASP_ENABLE, (patchId < ECHOES_OF_DOOM ? 2 : 1));

    // Arena
    sWorld->setBoolConfig(WorldBoolConfigs::CONFIG_ARENA_SEASON_IN_PROGRESS, patchId >= BEFORE_THE_STORM);

    if (patchId <= BEFORE_THE_STORM)
        sWorld->setIntConfig(WorldIntConfigs::CONFIG_ARENA_SEASON_ID, 1);
    else if (patchId == BLACK_TEMPLE)
        sWorld->setIntConfig(WorldIntConfigs::CONFIG_ARENA_SEASON_ID, 2);
    else if (patchId == THE_GODS_OF_ZUL_AMAN)
        sWorld->setIntConfig(WorldIntConfigs::CONFIG_ARENA_SEASON_ID, 3);
    else if (patchId == FURY_OF_THE_SUNWELL)
        sWorld->setIntConfig(WorldIntConfigs::CONFIG_ARENA_SEASON_ID, 4);
    else if (patchId == ECHOES_OF_DOOM)
        sWorld->setIntConfig(WorldIntConfigs::CONFIG_ARENA_SEASON_ID, 5);
    else if (patchId == SECRETS_OF_ULDUAR)
        sWorld->setIntConfig(WorldIntConfigs::CONFIG_ARENA_SEASON_ID, 6);
    else if (patchId == CALL_OF_THE_CRUSADE)
        sWorld->setIntConfig(WorldIntConfigs::CONFIG_ARENA_SEASON_ID, 7);
    else if (patchId >= FALL_OF_THE_LICH_KING)
        sWorld->setIntConfig(WorldIntConfigs::CONFIG_ARENA_SEASON_ID, 8);
}

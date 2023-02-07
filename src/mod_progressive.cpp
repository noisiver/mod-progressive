#include "Config.h"

#include "mod_progressive.h"

Progressive::Progressive() : DatabaseScript("ProgressiveDatabaseScript"), PlayerScript("ProgressivePlayerScript"), ServerScript("ProgressiveServerScript"), WorldScript("ProgressiveWorldScript") {}

// Patch 3.0
void AddSC_npc_archmage_landalock_progressive();

void Addmod_progressiveScripts()
{
    new Progressive();

    // Patch 3.0
    if (sConfigMgr->GetOption<int>("Progressive.Patch", ASSAULT_ON_THE_RUBY_SANCTUM) >= ECHOES_OF_DOOM)
        if (sConfigMgr->GetOption<int>("Progressive.Patch", ASSAULT_ON_THE_RUBY_SANCTUM) < FALL_OF_THE_LICH_KING)
            AddSC_npc_archmage_landalock_progressive();
}

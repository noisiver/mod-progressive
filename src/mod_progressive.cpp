#include "mod_progressive.h"

Progressive::Progressive() : PlayerScript("ProgressivePlayerScript"), WorldScript("ProgressiveWorldScript") {}

void Progressive::OnAfterConfigLoad(bool reload)
{
    if (reload)
        return;

    patchId = sConfigMgr->GetOption<int>("Progressive.Patch", ASSAULT_ON_THE_RUBY_SANCTUM);

    UpdateConfigOptions();
}

void Progressive::OnStartup()
{
    LOG_INFO("module", "Initializing data for {}", ProgressionPatchTitle[patchId]);

    if (patchId == ASSAULT_ON_THE_RUBY_SANCTUM)
        return;

    UpdateCreatures();
    AddDisables();
    UpdateGameObjects();
    UpdateItemTemplates();
    UpdateTrainerSpells();
    RemoveTransports();
    UpdateVendorItems();
    UpdateQuestRelations();
}

void Addmod_progressiveScripts()
{
    new Progressive();
}

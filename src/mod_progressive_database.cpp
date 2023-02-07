#include "DBUpdater.h"
#include "Config.h"

#include "mod_progressive.h"

void Progressive::OnAfterDatabasesLoaded(uint32 updateFlags)
{
    if (!DBUpdater<WorldDatabaseConnection>::IsEnabled(updateFlags))
        return;

    std::vector<std::string> PatchDatabaseDirectories = GetActivePatches();
    if (PatchDatabaseDirectories.empty())
        return;

    DBUpdater<WorldDatabaseConnection>::Update(WorldDatabase, &PatchDatabaseDirectories);
}

inline std::vector<std::string> Progressive::GetActivePatches()
{
    std::string PathToPatches = "/modules/mod-progressive/src/";
    std::vector<std::string> ActivePatches;
    PatchId = sConfigMgr->GetOption<int>("Progressive.Patch", ASSAULT_ON_THE_RUBY_SANCTUM);

    if (PatchId >= ECHOES_OF_DOOM)
        ActivePatches.push_back(PathToPatches + "patch_01-3_0/sql");

    if (PatchId >= SECRETS_OF_ULDUAR)
        ActivePatches.push_back(PathToPatches + "patch_02-3_1/sql");

    if (PatchId >= CALL_OF_THE_CRUSADE)
        ActivePatches.push_back(PathToPatches + "patch_03-3_2/sql");

    if (PatchId >= FALL_OF_THE_LICH_KING)
        ActivePatches.push_back(PathToPatches + "patch_04-3_3/sql");

    if (PatchId >= ASSAULT_ON_THE_RUBY_SANCTUM)
        ActivePatches.push_back(PathToPatches + "patch_05-3_3_5/sql");

    return ActivePatches;
}

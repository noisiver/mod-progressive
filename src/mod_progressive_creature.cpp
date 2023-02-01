#include "mod_progressive.h"

void Progressive::UpdateCreatures()
{
    RemoveCreatures();
    AddCreatures();
    UpdateCreatureTemplates();
}

void Progressive::RemoveCreatures()
{
    QueryResult result = WorldDatabase.Query("SELECT `guid` FROM `progressive_creature` WHERE {} NOT BETWEEN `min_patch` AND `max_patch`", patchId);

    if (!result)
        return;

    do
    {
        Field* fields = result->Fetch();
        uint32 guid = fields[0].Get<uint32>();

        sObjectMgr->DeleteCreatureData(guid);
    } while (result->NextRow());
}

void Progressive::AddCreatures()
{
    QueryResult result = WorldDatabase.Query("SELECT `guid`, `id1`, `map`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs` FROM `progressive_creature` WHERE {} BETWEEN `min_patch` AND `max_patch`", patchId);

    if (!result)
        return;

    do
    {
        Field* fields = result->Fetch();
        uint32 guid = fields[0].Get<uint32>();
        uint32 entry = fields[1].Get<uint32>();
        uint32 map = fields[2].Get<uint32>();
        float position_x = fields[3].Get<float>();
        float position_y = fields[4].Get<float>();
        float position_z = fields[5].Get<float>();
        float orientation = fields[6].Get<float>();
        uint32 spawntimesecs = fields[7].Get<uint32>();

        sObjectMgr->DeleteCreatureData(guid);
        sObjectMgr->AddCreData(entry, map, position_x, position_y, position_z, orientation, spawntimesecs);
    } while (result->NextRow());
}

void Progressive::UpdateCreatureTemplates()
{
    QueryResult result = WorldDatabase.Query("SELECT `entry`, `name`, `subname`, `minlevel`, `maxlevel` FROM `progressive_creature_template` t1 WHERE `patch`=(SELECT max(`patch`) FROM `progressive_creature_template` t2 WHERE t1.`entry`=t2.`entry` && `patch` <= {})", patchId);

    if (!result)
        return;

    do
    {
        Field* fields = result->Fetch();

        uint32 entry = fields[0].Get<uint32>();
        std::string name = fields[1].Get<std::string>();
        std::string subname = fields[2].Get<std::string>();
        uint8 minlevel = fields[3].Get<uint8>();
        uint8 maxlevel = fields[4].Get<uint8>();

        if (CreatureTemplate* c = const_cast<CreatureTemplate*>(sObjectMgr->GetCreatureTemplate(entry)))
        {
            c->Name = name;
            c->SubName = subname;
            c->minlevel = minlevel;
            c->maxlevel = maxlevel;
        }
    } while (result->NextRow());
}

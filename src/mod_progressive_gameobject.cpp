#include "mod_progressive.h"

void Progressive::UpdateGameObjects()
{
    RemoveGameObjects();
    AddGameObjects();
    UpdateGameObjectTemplates();
}

void Progressive::RemoveGameObjects()
{
    QueryResult result = WorldDatabase.Query("SELECT `guid` FROM `progressive_gameobject` WHERE {} NOT BETWEEN `min_patch` AND `max_patch`", patchId);

    if (!result)
        return;

    do
    {
        Field* fields = result->Fetch();
        uint32 guid = fields[0].Get<int32>();

        sObjectMgr->DeleteGOData(guid);
    } while (result->NextRow());
}

void Progressive::AddGameObjects()
{
    QueryResult result = WorldDatabase.Query("SELECT `guid`, `id`, `map`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state` FROM `progressive_gameobject` WHERE {} BETWEEN `min_patch` AND `max_patch`", patchId);

    if (!result)
        return;

    do
    {
        Field* fields = result->Fetch();
        uint32 guid = fields[0].Get<int32>();
        uint32 id = fields[1].Get<int32>();
        uint32 map = fields[2].Get<int32>();
        float position_x = fields[3].Get<float>();
        float position_y = fields[4].Get<float>();
        float position_z = fields[5].Get<float>();
        float orientation = fields[6].Get<float>();
        uint32 spawntimesecs = fields[7].Get<int32>();
        float rotation0 = fields[8].Get<float>();
        float rotation1 = fields[9].Get<float>();
        float rotation2 = fields[10].Get<float>();
        float rotation3 = fields[11].Get<float>();
        uint32 animprogress = fields[12].Get<uint32>();
        uint32 state = fields[13].Get<uint32>();

        sObjectMgr->DeleteGOData(guid);
        if (uint32 go = sObjectMgr->AddGOData(id, map, position_x, position_y, position_z, orientation, spawntimesecs, rotation0, rotation1, rotation2, rotation3))
        {
            if (GameObjectData* data = const_cast<GameObjectData*>(sObjectMgr->GetGOData(go)))
            {
                data->animprogress = animprogress;
                data->go_state = (GOState)state;
            }
        }
    } while (result->NextRow());
}

void Progressive::UpdateGameObjectTemplates()
{
    QueryResult result = WorldDatabase.Query("SELECT `entry`, `type`, `name` FROM `progressive_gameobject_template` t1 WHERE `patch`=(SELECT max(`patch`) FROM `progressive_gameobject_template` t2 WHERE t1.`entry`=t2.`entry` && `patch` <= {})", patchId);

    if (!result)
        return;

    do
    {
        Field* fields = result->Fetch();

        uint32 entry = fields[0].Get<uint32>();
        uint32 type = fields[1].Get<uint32>();
        std::string name = fields[2].Get<std::string>();

        if (GameObjectTemplate* go = const_cast<GameObjectTemplate*>(sObjectMgr->GetGameObjectTemplate(entry)))
        {
            go->name = name;
            go->type = type;
        }
    } while (result->NextRow());
}

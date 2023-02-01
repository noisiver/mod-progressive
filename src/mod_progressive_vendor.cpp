#include "mod_progressive.h"

void Progressive::UpdateVendorItems()
{
    RemoveVendorItems();
    AddVendorItems();
}

void Progressive::RemoveVendorItems()
{
    QueryResult result = WorldDatabase.Query("SELECT `entry`, `item` FROM `progressive_npc_vendor` WHERE {} NOT BETWEEN `min_patch` AND `max_patch`", patchId);

    if (!result)
        return;

    do
    {
        Field* fields = result->Fetch();
        uint32 entry = fields[0].Get<int32>();
        uint32 item = fields[1].Get<int32>();

        sObjectMgr->RemoveVendorItem(entry, item, false);
    } while (result->NextRow());
}

void Progressive::AddVendorItems()
{
    QueryResult result = WorldDatabase.Query("SELECT `entry`, `item`, `maxcount`, `incrtime`, `ExtendedCost` FROM `progressive_npc_vendor` WHERE {} BETWEEN `min_patch` AND `max_patch`", patchId);

    if (!result)
        return;

    do
    {
        Field* fields = result->Fetch();
        uint32 entry = fields[0].Get<int32>();
        uint32 item = fields[1].Get<int32>();
        uint32 maxcount = fields[2].Get<int32>();
        uint32 incrtime = fields[3].Get<int32>();
        uint32 extendedCost = fields[4].Get<int32>();

        sObjectMgr->AddVendorItem(entry, item, maxcount, incrtime, extendedCost, false);
        sObjectMgr->RemoveVendorItem(entry, item, false);
    } while (result->NextRow());
}

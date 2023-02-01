#include "mod_progressive.h"

void Progressive::UpdateItemTemplates()
{
    QueryResult result = WorldDatabase.Query("SELECT `entry`, `name`, `class`, `sublcass` FROM `progressive_item_template` t1 WHERE `patch`=(SELECT max(`patch`) FROM `progressive_item_template` t2 WHERE t1.`entry`=t2.`entry` && `patch` <= {})", patchId);

    if (!result)
        return;

    do
    {
        Field* fields = result->Fetch();

        uint32 entry = fields[0].Get<uint32>();
        std::string name = fields[1].Get<std::string>();
        uint32 itemclass = fields[2].Get<uint32>();
        uint32 subclass = fields[3].Get<uint32>();

        if (ItemTemplate* i = const_cast<ItemTemplate*>(sObjectMgr->GetItemTemplate(entry)))
        {
            i->Name1 = name;
            i->Class = itemclass;
            i->SubClass = subclass;
        }
    } while (result->NextRow());
}

#include "mod_progressive.h"

void Progressive::UpdateGossipOptions()
{
    RemoveGossipOptions();
}

void Progressive::RemoveGossipOptions()
{
    QueryResult result = WorldDatabase.Query("SELECT `MenuID`, `OptionID` FROM `progressive_gossip_menu_option` WHERE {} NOT BETWEEN `min_patch` AND `max_patch`", patchId);

    if (!result)
        return;

    do
    {
        Field* fields = result->Fetch();
        uint32 menu_id = fields[0].Get<uint32>();
        uint32 option_id = fields[1].Get<uint32>();

        RemoveGossipOption(menu_id, option_id);
    } while (result->NextRow());
}

void Progressive::RemoveGossipOption(uint32 menu_id, uint32 option_id)
{
    GossipMenuItemsMapBoundsNonConst pMenuItemBounds = sObjectMgr->GetGossipMenuItemsMapBoundsNonConst(menu_id);
    if (pMenuItemBounds.first == pMenuItemBounds.second)
        return;

    for (GossipMenuItemsContainer::iterator itr = pMenuItemBounds.first; itr != pMenuItemBounds.second; ++itr)
    {
        if ((*itr).second.OptionID != option_id)
            continue;

        Condition* cond = new Condition();
        cond->SourceType = CONDITION_SOURCE_TYPE_GOSSIP_MENU_OPTION;
        cond->SourceGroup = menu_id;
        cond->SourceEntry = option_id;
        cond->ConditionType = CONDITION_LEVEL;
        cond->ConditionValue1 = 255;
        cond->ConditionTarget = 0;

        (*itr).second.Conditions.push_back(cond);
    }
}

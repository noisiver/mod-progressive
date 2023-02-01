#include "mod_progressive.h"

void Progressive::UpdateQuestRelations()
{
    RemoveCreatureQuestStarter();
    AddCreatureQuestStarter();
    RemoveCreatureQuestEnder();
    AddCreatureQuestEnder();
    UpdateQuestTemplates();
    RemoveQuestItemTooltip();
}

void Progressive::RemoveCreatureQuestStarter()
{
    QueryResult result = WorldDatabase.Query("SELECT `id`, `quest` FROM `progressive_creature_queststarter` WHERE {} NOT BETWEEN `min_patch` AND `max_patch`", patchId);

    if (!result)
        return;

    do
    {
        Field* fields = result->Fetch();
        uint32 id = fields[0].Get<int32>();
        uint32 quest = fields[1].Get<int32>();

        RemoveQuestStartFromCreature(id, quest);
    } while (result->NextRow());
}

void Progressive::AddCreatureQuestStarter()
{
    QueryResult result = WorldDatabase.Query("SELECT `id`, `quest` FROM `progressive_creature_queststarter` WHERE {} BETWEEN `min_patch` AND `max_patch`", patchId);

    if (!result)
        return;

    do
    {
        Field* fields = result->Fetch();
        uint32 id = fields[0].Get<int32>();
        uint32 quest = fields[1].Get<int32>();

        AddQuestStartToCreature(id, quest);
    } while (result->NextRow());
}

void Progressive::RemoveCreatureQuestEnder()
{
    QueryResult result = WorldDatabase.Query("SELECT `id`, `quest` FROM `progressive_creature_questender` WHERE {} NOT BETWEEN `min_patch` AND `max_patch`", patchId);

    if (!result)
        return;

    do
    {
        Field* fields = result->Fetch();
        uint32 id = fields[0].Get<int32>();
        uint32 quest = fields[1].Get<int32>();

        RemoveQuestEndFromCreature(id, quest);
    } while (result->NextRow());
}

void Progressive::AddCreatureQuestEnder()
{
    QueryResult result = WorldDatabase.Query("SELECT `id`, `quest` FROM `progressive_creature_questender` WHERE {} BETWEEN `min_patch` AND `max_patch`", patchId);

    if (!result)
        return;

    do
    {
        Field* fields = result->Fetch();
        uint32 id = fields[0].Get<int32>();
        uint32 quest = fields[1].Get<int32>();

        AddQuestEndToCreature(id, quest);
    } while (result->NextRow());
}

void Progressive::RemoveQuestStartFromCreature(uint32 id, uint32 quest)
{
    QuestRelationBounds qr = sObjectMgr->GetCreatureQuestRelationBounds(id);
    for (QuestRelations::const_iterator i = qr.first; i != qr.second; ++i)
    {
        if (i->second == quest)
        {
            sObjectMgr->GetCreatureQuestInvolvedRelationMap()->erase(i);
            break;
        }
    }
}

void Progressive::AddQuestStartToCreature(uint32 id, uint32 quest)
{
    if (!sObjectMgr->GetQuestTemplate(quest))
        return;

    if (!sObjectMgr->GetCreatureTemplate(id))
        return;

    QuestRelationBounds qr = sObjectMgr->GetCreatureQuestRelationBounds(id);
    for (QuestRelations::const_iterator i = qr.first; i != qr.second; ++i)
    {
        if (i->second == quest)
            return;
    }

    sObjectMgr->GetCreatureQuestRelationMap()->insert(QuestRelations::value_type(id, quest));
}

void Progressive::RemoveQuestEndFromCreature(uint32 id, uint32 quest)
{
    QuestRelationBounds qr = sObjectMgr->GetCreatureQuestInvolvedRelationBounds(id);
    for (QuestRelations::const_iterator i = qr.first; i != qr.second; ++i)
    {
        if (i->second == quest)
        {
            sObjectMgr->GetCreatureQuestInvolvedRelationMap()->erase(i);
            break;
        }
    }
}

void Progressive::AddQuestEndToCreature(uint32 id, uint32 quest)
{
    if (!sObjectMgr->GetQuestTemplate(quest))
        return;

    if (!sObjectMgr->GetCreatureTemplate(id))
        return;

    QuestRelationBounds qr = sObjectMgr->GetCreatureQuestInvolvedRelationBounds(id);
    for (QuestRelations::const_iterator i = qr.first; i != qr.second; ++i)
    {
        if (i->second == quest)
            return;
    }

    sObjectMgr->GetCreatureQuestRelationMap()->insert(QuestRelations::value_type(id, quest));
}

void Progressive::UpdateQuestTemplates()
{
    QueryResult result = WorldDatabase.Query("SELECT `ID`, `LogTitle` FROM `progressive_quest_template` t1 WHERE `patch`=(SELECT max(`patch`) FROM `progressive_quest_template` t2 WHERE t1.`ID`=t2.`ID` && `patch` <= {})", patchId);

    if (!result)
        return;

    do
    {
        Field* fields = result->Fetch();
        uint32 id = fields[0].Get<int32>();
        std::string log_title = fields[1].Get<std::string>();

        if (Quest* quest = const_cast<Quest*>(sObjectMgr->GetQuestTemplate(id)))
        {
            if (QuestLocale* locale = const_cast<QuestLocale*>(sObjectMgr->GetQuestLocale(id)))
            {
                locale->Title[LOCALE_enUS] = log_title;
            }
        }
    } while (result->NextRow());
}

void Progressive::RemoveQuestItemTooltip()
{
    if (patchId >= CALL_OF_THE_CRUSADE)
        return;

    if (CreatureQuestItemMap* cqi = const_cast<CreatureQuestItemMap*>(sObjectMgr->GetCreatureQuestItemMap()))
        cqi->clear();

    if (GameObjectQuestItemMap* gqi = const_cast<GameObjectQuestItemMap*>(sObjectMgr->GetGameObjectQuestItemMap()))
        gqi->clear();
}

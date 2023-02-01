#include "mod_progressive.h"

void Progressive::UpdateTrainerSpells()
{
    RemoveTrainerSpells();
    AddTrainerSpells();
}

void Progressive::RemoveTrainerSpells()
{
    QueryResult result = WorldDatabase.Query("SELECT `ID`, `SpellID` FROM `progressive_npc_trainer` WHERE {} NOT BETWEEN `MinPatch` AND `MaxPatch`", patchId);

    if (!result)
        return;

    do
    {
        Field* fields = result->Fetch();
        uint32 id = fields[0].Get<int32>();
        uint32 spellId = fields[1].Get<int32>();

        RemoveTrainerSpell(id, spellId);
    } while (result->NextRow());
}

void Progressive::RemoveTrainerSpell(uint32 id, uint32 spellId)
{
    if (TrainerSpellData* trainerData = const_cast<TrainerSpellData*>(sObjectMgr->GetNpcTrainerSpells(id)))
    {
        for (TrainerSpellMap::const_iterator itr = trainerData->spellList.begin(); itr != trainerData->spellList.end(); ++itr)
        {
            TrainerSpell const* tSpell = &itr->second;
            if (tSpell->spell == spellId)
                trainerData->spellList.erase(itr);
        }
    }
}

void Progressive::AddTrainerSpells()
{
    QueryResult result = WorldDatabase.Query("SELECT `ID`, `SpellID`, `MoneyCost`, `ReqSkillLine`, `ReqSkillRank`, `ReqLevel` FROM `progressive_npc_trainer` WHERE {} BETWEEN `MinPatch` AND `MaxPatch`", patchId);

    if (!result)
        return;

    do
    {
        Field* fields = result->Fetch();
        uint32 id = fields[0].Get<uint32>();
        uint32 spellId = fields[1].Get<uint32>();
        uint32 moneyCost = fields[2].Get<uint32>();
        uint32 reqSkillLine = fields[3].Get<uint32>();
        uint32 reqSkillRank = fields[4].Get<uint32>();
        uint32 reqLevel = fields[5].Get<uint32>();

        sObjectMgr->AddSpellToTrainer(id, spellId, moneyCost, reqSkillLine, reqSkillRank, reqLevel, 0);
    } while (result->NextRow());
}

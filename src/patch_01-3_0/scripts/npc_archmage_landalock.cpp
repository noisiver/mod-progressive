#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "Player.h"

enum ArchmageLandalockQuests
{
    QUEST_PROOF_OF_DEMISE_INGVAR_THE_PLUNDERER   = 13245,
    QUEST_PROOF_OF_DEMISE_KERISTRASZA            = 13246,
    QUEST_PROOF_OF_DEMISE_LEY_GUARDIAN_EREGOS    = 13247,
    QUEST_PROOF_OF_DEMISE_KING_YMIRON            = 13248,
    QUEST_PROOF_OF_DEMISE_THE_PROPHET_THARON_JA  = 13249,
    QUEST_PROOF_OF_DEMISE_GAL_DARAH              = 13250,
    QUEST_PROOF_OF_DEMISE_MAL_GANIS              = 13251,
    QUEST_PROOF_OF_DEMISE_SJONNIR_THE_IRONSHAPER = 13252,
    QUEST_PROOF_OF_DEMISE_LOKEN                  = 13253,
    QUEST_PROOF_OF_DEMISE_ANUB_ARAK              = 13254,
    QUEST_PROOF_OF_DEMISE_HERALD_VOLAZJ          = 13255,
    QUEST_PROOF_OF_DEMISE_CYANIGOSA              = 13256
};

enum ArchmageLandalockImages
{
    NPC_INGVAR_THE_PLUNDERER_IMAGE               = 31584,
    NPC_KERISTRASZA_IMAGE                        = 31618,
    NPC_LEY_GUARDIAN_EREGOS_IMAGE                = 31619,
    NPC_KING_YMIRON_IMAGE                        = 31620,
    NPC_THE_PROPHET_THARON_JA_IMAGE              = 31621,
    NPC_GAL_DARAH_IMAGE                          = 31622,
    NPC_MAL_GANIS_IMAGE                          = 31623,
    NPC_SJONNIR_THE_IRONSHAPER_IMAGE             = 31624,
    NPC_LOKEN_IMAGE                              = 31625,
    NPC_ANUB_ARAK_IMAGE                          = 31626,
    NPC_HERALD_VOLAZJ_IMAGE                      = 31627,
    NPC_CYANIGOSA_IMAGE                          = 31629
};

class npc_archmage_landalock_progressive : public CreatureScript
{
public:
    npc_archmage_landalock_progressive() : CreatureScript("npc_archmage_landalock")
    {
    }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_archmage_landalock_progressiveAI(creature);
    }

    struct npc_archmage_landalock_progressiveAI : public ScriptedAI
    {
        npc_archmage_landalock_progressiveAI(Creature* creature) : ScriptedAI(creature)
        {
            _switchImageTimer = MINUTE * IN_MILLISECONDS;
            _summonGUID.Clear();
        }

        uint32 GetImageEntry(uint32 QuestId)
        {
            switch (QuestId)
            {
            case QUEST_PROOF_OF_DEMISE_INGVAR_THE_PLUNDERER:
                return NPC_INGVAR_THE_PLUNDERER_IMAGE;
            case QUEST_PROOF_OF_DEMISE_KERISTRASZA:
                return NPC_KERISTRASZA_IMAGE;
            case QUEST_PROOF_OF_DEMISE_LEY_GUARDIAN_EREGOS:
                return NPC_LEY_GUARDIAN_EREGOS_IMAGE;
            case QUEST_PROOF_OF_DEMISE_KING_YMIRON:
                return NPC_KING_YMIRON_IMAGE;
            case QUEST_PROOF_OF_DEMISE_THE_PROPHET_THARON_JA:
                return NPC_THE_PROPHET_THARON_JA_IMAGE;
            case QUEST_PROOF_OF_DEMISE_GAL_DARAH:
                return NPC_GAL_DARAH_IMAGE;
            case QUEST_PROOF_OF_DEMISE_MAL_GANIS:
                return NPC_MAL_GANIS_IMAGE;
            case QUEST_PROOF_OF_DEMISE_SJONNIR_THE_IRONSHAPER:
                return NPC_SJONNIR_THE_IRONSHAPER_IMAGE;
            case QUEST_PROOF_OF_DEMISE_LOKEN:
                return NPC_LOKEN_IMAGE;
            case QUEST_PROOF_OF_DEMISE_ANUB_ARAK:
                return NPC_ANUB_ARAK_IMAGE;
            case QUEST_PROOF_OF_DEMISE_HERALD_VOLAZJ:
                return NPC_HERALD_VOLAZJ_IMAGE;
            default: //case QUEST_PROOF_OF_DEMISE_CYANIGOSA:
                return NPC_CYANIGOSA_IMAGE;
            }
        }

        void JustSummoned(Creature* image) override
        {
            // xinef: screams like a baby
            if (image->GetEntry() != NPC_ANUB_ARAK_IMAGE)
                image->SetUnitMovementFlags(MOVEMENTFLAG_RIGHT);
            _summonGUID = image->GetGUID();
        }

        void UpdateAI(uint32 diff) override
        {
            ScriptedAI::UpdateAI(diff);

            _switchImageTimer += diff;
            if (_switchImageTimer > MINUTE * IN_MILLISECONDS)
            {
                _switchImageTimer = 0;
                QuestRelationBounds objectQR = sObjectMgr->GetCreatureQuestRelationBounds(me->GetEntry());
                for (QuestRelations::const_iterator i = objectQR.first; i != objectQR.second; ++i)
                {
                    uint32 questId = i->second;
                    Quest const* quest = sObjectMgr->GetQuestTemplate(questId);
                    if (!quest || !quest->IsDaily())
                        continue;

                    uint32 newEntry = GetImageEntry(questId);
                    if (_summonGUID.GetEntry() != newEntry)
                    {
                        if (Creature* image = ObjectAccessor::GetCreature(*me, _summonGUID))
                            image->DespawnOrUnsummon();

                        float z = 653.622f;
                        if (newEntry == NPC_KERISTRASZA_IMAGE || newEntry == NPC_CYANIGOSA_IMAGE)
                            z += 3.0f;
                        me->SummonCreature(newEntry, 5703.077f, 583.9757f, z, 3.926991f);
                    }
                }
            }
        }
    private:
        uint32 _switchImageTimer;
        ObjectGuid _summonGUID;
    };
};

void AddSC_npc_archmage_landalock_progressive()
{
    new npc_archmage_landalock_progressive();
}

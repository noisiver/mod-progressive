#ifndef MOD_PROGRESSION
#define MOD_PROGRESSION

#include "Chat.h"
#include "Config.h"
#include "Player.h"
#include "ScriptMgr.h"

#define ARGENT_TOURNAMENT_GROUNDS 4658

enum Patches
{
    WORLD_OF_WARCRAFT = 0,
    MYSTERIES_OF_MARAUDON,
    RUINS_OF_THE_DIRE_MAUL,
    THE_CALL_TO_WAR,
    BATTLEGROUNDS,
    ASSAULT_ON_BLACKWING_LAIR,
    RISE_OF_THE_BLOOD_GOD,
    DRAGONS_OF_NIGHTMARE,
    THE_GATES_OF_AHN_QIRAJ,
    STORMS_OF_AZEROTH,
    SHADOW_OF_THE_NECROPOLIS,
    DRUMS_OF_WAR,
    BEFORE_THE_STORM,
    BLACK_TEMPLE,
    VOICE_CHAT,
    THE_GODS_OF_ZUL_AMAN,
    FURY_OF_THE_SUNWELL,
    ECHOES_OF_DOOM,
    SECRETS_OF_ULDUAR,
    CALL_OF_THE_CRUSADE,
    FALL_OF_THE_LICH_KING,
    ASSAULT_ON_THE_RUBY_SANCTUM,
    MAX_PATCH
};

const std::string ProgressionPatchTitle[Patches::MAX_PATCH] = {
    "Patch 1.1: World of Warcraft",
    "Patch 1.2: Mysteries of Maraudon",
    "Patch 1.3: Ruins of the Dire Maul",
    "Patch 1.4: The Call to War",
    "Patch 1.5: Battlegrounds",
    "Patch 1.6: Assault on Blackwing Lair",
    "Patch 1.7: Rise of the Blood God",
    "Patch 1.8: Dragons of Nightmare",
    "Patch 1.9: The Gates of Ahn'Qiraj",
    "Patch 1.10: Storms of Azeroth",
    "Patch 1.11: Shadow of the Necropolis",
    "Patch 1.12: Drums of War",
    "Patch 2.0: Before the Storm",
    "Patch 2.1: Black Temple",
    "Patch 2.2: Voice Chat",
    "Patch 2.3: The Gods of Zul'Aman",
    "Patch 2.4: Fury of the Sunwell",
    "Patch 3.0: Echoes of Doom",
    "Patch 3.1: Secrets of Ulduar",
    "Patch 3.2: Call of the Crusade",
    "Patch 3.3: Fall of the Lich King",
    "Patch 3.3.5: Assault on the Ruby Sanctum"
};

class Progressive : public PlayerScript, WorldScript
{
public:
    Progressive();

    // PlayerScript
    void OnLogin(Player* /*player*/) override;
    bool OnBeforeCriteriaProgress(Player* /*player*/, AchievementCriteriaEntry const* /*criteria*/) override;
    bool OnBeforeAchiComplete(Player* /*player*/, AchievementEntry const* /*achievement*/) override;
    void OnUpdateArea(Player* player, uint32 /*oldArea*/, uint32 /*newArea*/) override;
    bool ShouldBeRewardedWithMoneyInsteadOfExp(Player* /*player*/) override;

    // WorldScript
    void OnAfterConfigLoad(bool reload) override;
    void OnStartup() override;

private:
    void UpdateConfigOptions();

    void UpdateCreatures();
    void RemoveCreatures();
    void AddCreatures();
    void UpdateCreatureTemplates();

    void AddDisables();

    void UpdateGameObjects();
    void RemoveGameObjects();
    void AddGameObjects();
    void UpdateGameObjectTemplates();

    void UpdateGossipOptions();
    void RemoveGossipOptions();
    void RemoveGossipOption(uint32 /*menu_id*/, uint32 /*option_id*/);

    void UpdateItemTemplates();

    void UpdateLootTables();
    void RemoveCreatureLootItems();
    void AddCreatureLootItems();

    void UpdateTrainerSpells();
    void RemoveTrainerSpells();
    void RemoveTrainerSpell(uint32 /*id*/, uint32 /*spellId*/);
    void AddTrainerSpells();

    void RemoveTransports();

    void UpdateQuestRelations();
    void RemoveCreatureQuestStarter();
    void AddCreatureQuestStarter();
    void RemoveCreatureQuestEnder();
    void AddCreatureQuestEnder();
    void UpdateQuestTemplates();
    void RemoveQuestStartFromCreature(uint32 /*id*/, uint32 /*quest*/);
    void AddQuestStartToCreature(uint32 /*id*/, uint32 /*quest*/);
    void RemoveQuestEndFromCreature(uint32 /*id*/, uint32 /*quest*/);
    void AddQuestEndToCreature(uint32 /*id*/, uint32 /*quest*/);
    void RemoveQuestItemTooltip();

    void UpdateVendorItems();
    void RemoveVendorItems();
    void AddVendorItems();

    int patchId = 21;
};

#endif

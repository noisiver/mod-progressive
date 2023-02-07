SET 
@Heroism  := 40752,
@Valor    := 40753,
@Conquest := 45624,
@Triumph  := 47241;

DELETE FROM `creature_loot_template` WHERE `Entry` IN (15928, 15931, 15932, 15936, 15952, 15953, 15954, 15956, 15989, 15990, 16011, 16028, 16060, 16061, 28860, 29249, 29268, 29278, 29324, 29373, 29417, 29448, 29615, 29701, 29718, 29932, 29940, 29955, 29991, 30061, 30397, 30398, 30510, 30529, 30530, 30532, 30540, 30748, 30774, 30788, 30807, 30810, 31125, 31211, 31212, 31215, 31311, 32313, 31349, 31350, 31360, 31362, 31367, 31368, 31370, 31381, 31384, 31386, 31456, 31463, 31464, 31465, 31469, 31506, 31507, 31508, 31509, 31510, 31511, 31512, 31533, 31536, 31537, 31538, 31558, 31559, 31560, 31610, 31611, 31612, 31656, 31673, 31679, 31722) AND `Item` IN (@Heroism, @Valor, @Conquest, @Triumph);
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `MinCount`, `MaxCount`, `Comment`) VALUES
-- Naxxramas
(15928, @Heroism, 1, 1, 'Thaddius - Emblem of Heroism'),
(15931, @Heroism, 1, 1, 'Grobbulus - Emblem of Heroism'),
(15932, @Heroism, 1, 1, 'Gluth - Emblem of Heroism'),
(15936, @Heroism, 1, 1, 'Heigan the Unclean - Emblem of Heroism'),
(15952, @Heroism, 1, 1, 'Maexxna - Emblem of Heroism'),
(15953, @Heroism, 1, 1, 'Grand Widow Faerlina - Emblem of Heroism'),
(15954, @Heroism, 1, 1, 'Noth the Plaguebringer - Emblem of Heroism'),
(15956, @Heroism, 1, 1, 'Anub\'Rekhan - Emblem of Heroism'),
(15989, @Heroism, 1, 1, 'Sapphiron - Emblem of Heroism'),
(15990, @Heroism, 2, 2, 'Kel\'Thuzad - Emblem of Heroism'),
(16011, @Heroism, 1, 1, 'Loatheb - Emblem of Heroism'),
(16028, @Heroism, 1, 1, 'Patchwerk - Emblem of Heroism'),
(16060, @Heroism, 1, 1, 'Gothik the Harvester - Emblem of Heroism'),
(16061, @Heroism, 1, 1, 'Instructor Razuvious - Emblem of Heroism'),
(29249, @Valor, 1, 1, 'Anub\'Rekhan (1) - Emblem of Valor'),
(29268, @Valor, 1, 1, 'Grand Widow Faerlina (1) - Emblem of Valor'),
(29278, @Valor, 1, 1, 'Maexxna (1) - Emblem of Valor'),
(29324, @Valor, 1, 1, 'Patchwerk (1) - Emblem of Valor'),
(29373, @Valor, 1, 1, 'Grobbulus (1) - Emblem of Valor'),
(29417, @Valor, 1, 1, 'Gluth (1) - Emblem of Valor'),
(29448, @Valor, 1, 1, 'Thaddius (1) - Emblem of Valor'),
(29615, @Valor, 1, 1, 'Noth the Plaguebringer (1) - Emblem of Valor'),
(29701, @Valor, 1, 1, 'Heigan the Unclean (1) - Emblem of Valor'),
(29718, @Valor, 1, 1, 'Loatheb (1) - Emblem of Valor'),
(29940, @Valor, 1, 1, 'Instructor Razuvious (1) - Emblem of Valor'),
(29955, @Valor, 1, 1, 'Gothik the Harvester (1) - Emblem of Valor'),
(29991, @Valor, 1, 1, 'Sapphiron (1) - Emblem of Valor'),
(30061, @Valor, 2, 2, 'Kel\'Thuzad (1) - Emblem of Valor'),
-- The Obsidian Sanctum
(28860, @Heroism, 3, 3, 'Sartharion - Emblem of Heroism'),
(31311, @Valor, 1, 1, 'Sartharion (1) - Emblem of Valor'),
-- Gundrak
(29932, @Heroism, 1, 1, 'Eck the Ferocious - Emblem of Heroism'),
(30530, @Heroism, 1, 1, 'Moorabi (1) - Emblem of Heroism'),
(31367, @Heroism, 1, 1, 'Drakkari Elemental (1) - Emblem of Heroism'),
(31368, @Heroism, 1, 1, 'Gal\'darah (1) - Emblem of Heroism'),
(31370, @Heroism, 1, 1, 'Slad\'ran (1) - Emblem of Heroism'),
-- The Nexus
(30397, @Heroism, 1, 1, 'Commander Kolurg (1) - Emblem of Heroism'),
(30398, @Heroism, 1, 1, 'Commander Stoutbeard (1) - Emblem of Heroism'),
(30510, @Heroism, 1, 1, 'Grand Magus Telestra (1) - Emblem of Heroism'),
(30529, @Heroism, 1, 1, 'Anomalus (1) - Emblem of Heroism'),
(30532, @Heroism, 1, 1, 'Ormorok the Tree-Shaper (1) - Emblem of Heroism'),
(30540, @Heroism, 1, 1, 'Keristrasza (1) - Emblem of Heroism'),
-- Utgarde Keep
(30748, @Heroism, 1, 1, 'Prince Keleseth (1) - Emblem of Heroism'),
(31656, @Heroism, 1, 1, 'Dalronn the Controller (1) - Emblem of Heroism'),
(31673, @Heroism, 1, 1, 'Ingvar the Plunderer (1) - Emblem of Heroism'),
(31679, @Heroism, 1, 1, 'Skarvald the Constructor (1) - Emblem of Heroism'),
-- Utgarde Pinnacle
(30774, @Heroism, 1, 1, 'Gortok Palehoof (1) - Emblem of Heroism'),
(30788, @Heroism, 1, 1, 'King Ymiron (1) - Emblem of Heroism'),
(30807, @Heroism, 1, 1, 'Skadi the Ruthless (1) - Emblem of Heroism'),
(30810, @Heroism, 1, 1, 'Svala Sorrowgrave (1) - Emblem of Heroism'),
-- Vault of Archavon
(31125, @Heroism, 2, 2, 'Archavon the Stone Watcher - Emblem of Heroism'),
(31722, @Valor, 2, 2, 'Archavon the Stone Watcher (1) - Emblem of Valor'),
-- The Culling of Stratholme
(31211, @Heroism, 1, 1, 'Meathook (1) - Emblem of Heroism'),
(31212, @Heroism, 1, 1, 'Salramm the Fleshcrafter (1) - Emblem of Heroism'),
(31215, @Heroism, 1, 1, 'Chrono-Lord Epoch (1) - Emblem of Heroism'),
(32313, @Heroism, 1, 1, 'Infinite Corruptor (1) - Emblem of Heroism'),
-- Drak'Tharon Keep
(31349, @Heroism, 1, 1, 'King Dred (1) - Emblem of Heroism'),
(31350, @Heroism, 1, 1, 'Novos the Summoner (1) - Emblem of Heroism'),
(31360, @Heroism, 1, 1, 'The Prophet Tharon\'ja (1) - Emblem of Heroism'),
(31362, @Heroism, 1, 1, 'Trollgore (1) - Emblem of Heroism'),
-- Halls of Stone
(31381, @Heroism, 1, 1, 'Krystallus (1) - Emblem of Heroism'),
(31384, @Heroism, 1, 1, 'Maiden of Grief (1) - Emblem of Heroism'),
(31386, @Heroism, 1, 1, 'Sjonnir The Ironshaper (1) - Emblem of Heroism'),
-- Ahn'kahet: The Old Kingdom
(31456, @Heroism, 1, 1, 'Elder Nadox (1) - Emblem of Heroism'),
(31463, @Heroism, 1, 1, 'Amanitar (1) - Emblem of Heroism'),
(31464, @Heroism, 1, 1, 'Herald Volazj (1) - Emblem of Heroism'),
(31465, @Heroism, 1, 1, 'Jedoga Shadowseeker (1) - Emblem of Heroism'),
(31469, @Heroism, 1, 1, 'Prince Taldaram (1) - Emblem of Heroism'),
-- The Violet Hold
(31506, @Heroism, 1, 1, 'Cyanigosa (1) - Emblem of Heroism'),
(31507, @Heroism, 1, 1, 'Erekem (1) - Emblem of Heroism'),
(31508, @Heroism, 1, 1, 'Ichoron (1) - Emblem of Heroism'),
(31509, @Heroism, 1, 1, 'Lavanthor (1) - Emblem of Heroism'),
(31510, @Heroism, 1, 1, 'Moragg (1) - Emblem of Heroism'),
(31511, @Heroism, 1, 1, 'Xevozz (1) - Emblem of Heroism'),
(31512, @Heroism, 1, 1, 'Zuramat the Obliterator (1) - Emblem of Heroism'),
-- Halls of Lightning
(31533, @Heroism, 1, 1, 'General Bjarngrim (1) - Emblem of Heroism'),
(31536, @Heroism, 1, 1, 'Volkhan (1) - Emblem of Heroism'),
(31537, @Heroism, 1, 1, 'Ionar (1) - Emblem of Heroism'),
(31538, @Heroism, 1, 1, 'Loken (1) - Emblem of Heroism'),
-- The Oculus
(31558, @Heroism, 1, 1, 'Drakos the Interrogator (1) - Emblem of Heroism'),
(31559, @Heroism, 1, 1, 'Varos Cloudstrider (1) - Emblem of Heroism'),
(31560, @Heroism, 1, 1, 'Mage-Lord Urom (1) - Emblem of Heroism'),
-- Azjol-Nerub
(31610, @Heroism, 1, 1, 'Anub\'arak (1) - Emblem of Heroism'),
(31611, @Heroism, 1, 1, 'Hadronox (1) - Emblem of Heroism'),
(31612, @Heroism, 1, 1, 'Krik\'thir the Gatewatcher (1) - Emblem of Heroism');

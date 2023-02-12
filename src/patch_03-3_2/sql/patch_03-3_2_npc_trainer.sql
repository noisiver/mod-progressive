UPDATE `npc_trainer` SET `MoneyCost`=40000, `ReqLevel`=20 WHERE `SpellID`=33388; -- Apprentice Riding
UPDATE `npc_trainer` SET `MoneyCost`=500000, `ReqLevel`=40 WHERE `SpellID`=33391; -- Journeyman Riding
UPDATE `npc_trainer` SET `MoneyCost`=2500000, `ReqLevel`=60 WHERE `SpellID`=34090; -- Expert Riding (3.2.0 = 600 gold, 3.2.2 = 250 gold)

DELETE FROM `npc_trainer` WHERE `ID`=200020 AND `SpellID` IN (13820, 23214);
DELETE FROM `npc_trainer` WHERE `ID`=200021 AND `SpellID` IN (34767, 34768);
DELETE FROM `npc_trainer` WHERE `ID`=200006 AND `SpellID`=33950;
DELETE FROM `npc_trainer` WHERE `ID`=200010 AND `SpellID` IN (1710, 23161);
DELETE FROM `npc_trainer` WHERE `ID`=200018 AND `SpellID` IN (66842, 66843, 66844);
INSERT INTO `npc_trainer` (`ID`, `SpellID`, `MoneyCost`, `ReqLevel`) VALUES
-- Paladin
(200020, 13820, 3500, 40), -- Summon Warhorse
(200020, 23214, 3500, 20), -- Charger
(200021, 34767, 3500, 40), -- Summon Charger
(200021, 34768, 3500, 20), -- Summon Warhorse
-- Druid
(200006, 33950, 34000, 60), -- Flight Form (Shapeshift)
-- Warlock
(200010, 1710, 10000, 20), -- Summon Felsteed
(200010, 23161, 100000, 40), -- Dreadsteed
-- Shaman
(200018, 66842, 700, 30), -- Call of the Elements
(200018, 66843, 700, 40), -- Call of the Ancestors
(200018, 66844, 700, 50); -- Call of the Spirits

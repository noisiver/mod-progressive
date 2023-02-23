UPDATE `npc_trainer` SET `MoneyCost`=350000, `ReqLevel`=30 WHERE `SpellID`=33388; -- Apprentice Riding
UPDATE `npc_trainer` SET `MoneyCost`=6000000, `ReqLevel`=60 WHERE `SpellID`=33391; -- Journeyman Riding
UPDATE `npc_trainer` SET `MoneyCost`=8000000, `ReqLevel`=70 WHERE `SpellID`=34090; -- Expert Riding

DELETE FROM npc_trainer WHERE ID=200006 AND SpellID=33950;
INSERT INTO `npc_trainer` (`ID`, `SpellID`, `MoneyCost`, `ReqLevel`) VALUES
-- Druid
(200006, 33950, 81000, 68); -- Flight Form (Shapeshift)

DELETE FROM `npc_trainer` WHERE `ID`=200020 AND `SpellID` IN (
    13820, -- Summon Warhorse
    23214 -- Charger
);

DELETE FROM `npc_trainer` WHERE `ID`=200021 AND `SpellID` IN (
    34767, -- Summon Charger
    34768 -- Summon Warhorse
);

DELETE FROM npc_trainer WHERE ID=200010 AND SpellID IN (
    1710, -- Summon Felsteed
    23161 -- Dreadsteed
);

DELETE FROM `npc_trainer` WHERE `ID`=200018 AND `SpellID` IN (
    66842, -- Call of the Elements
    66843, -- Call of the Ancestors
    66844 -- Call of the Spirits
);

DELETE FROM `npc_trainer` WHERE `ID`=202007 AND `SpellID`=10847; -- Artisan First Aid

DELETE FROM `npc_trainer` WHERE `ID`=202001 AND `SpellID` IN (
    18249, -- Artisan Fishing
    54083 -- Expert Fishing
);

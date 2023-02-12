DELETE FROM `npc_trainer` WHERE `ID`=202001 AND `SpellID` IN (18249, 54083);
DELETE FROM `npc_trainer` WHERE `ID`=202007 AND `SpellID`=10847;
INSERT INTO `npc_trainer` (`ID`, `SpellID`, `MoneyCost`, `ReqSkillLine`, `ReqSkillRank`, `ReqLevel`) VALUES
-- Fishing
(202001, 18249, 25000, 356, 200, 10), -- Artisan Fishing
(202001, 54083, 10000, 356, 125, 10), -- Expert Fishing
-- First Aid
(202007, 10847, 25000, 129, 200, 35); -- Artisan First Aid

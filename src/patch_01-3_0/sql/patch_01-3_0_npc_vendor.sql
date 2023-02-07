DELETE FROM `npc_vendor` WHERE `entry`=2626 AND `item`=16083;
DELETE FROM `npc_vendor` WHERE `entry` IN (2805, 13476) AND `item`=16084;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES
-- Old Man Heming <Fishing Supplies>
(2626, 16083), -- Expert Fishing - The Bass and You
-- Deneb Walker <Reagents>
(2805, 16084), -- Expert First Aid - Under Wraps
-- Balai Lok'Wein <Potions, Scrolls & Reagents>
(13476, 16084); -- Expert First Aid - Under Wraps

DELETE FROM `disables` WHERE `sourceType`=2 AND `entry` IN (249, 603, 631, 632, 649, 650, 658, 668, 724);
INSERT INTO `disables` (`sourceType`, `entry`, `flags`, `comment`) VALUES
(2, 249, 3, 'Onyxia\'s Lair'), -- Patch 3.2
(2, 603, 3, 'Ulduar'), -- Patch 3.1
(2, 631, 15, 'Icecrown Citadel'), -- Patch 3.3
(2, 632, 3, 'The Forge of Souls'), -- Patch 3.3
(2, 649, 15, 'Trial of The Crusader'), -- Patch 3.2
(2, 650, 3, 'Trial of the Champion'), -- Patch 3.2
(2, 658, 3, 'Pit of Saron'), -- Patch 3.3
(2, 668, 3, 'Halls of Reflection'), -- Patch 3.3
(2, 724, 15, 'The Ruby Sanctum'); -- Patch 3.3.5

DELETE FROM `disables` WHERE `sourceType`=3 AND `entry` IN (6, 30, 32);
INSERT INTO `disables` (`sourceType`, `entry`, `comment`) VALUES
(3, 6, 'All Arenas'), -- Patch 3.3
(3, 30, 'Isle of Conquest'), -- Patch 3.2
(3, 32, 'Random Battleground'); -- Patch 3.3

DELETE FROM `disables` WHERE `sourceType`=9 AND `entry` IN (26, 51, 54, 61, 63, 64);
INSERT INTO `disables` (`sourceType`, `entry`, `comment`) VALUES
(9, 26, 'Pilgrim\'s Bounty'), -- Patch 3.2
(9, 51, 'Day of the Dead'), -- Patch 3.2
(9, 54, 'Call to Arms: Isle of Conquest!'), -- Patch 3.2
(9, 61, 'Zalazane\'s Fall'), -- Patch 3.3.5
(9, 63, 'Kalu\'ak Fishing Derby (Turn-ins)'), -- Patch 3.3
(9, 64, 'Kalu\'ak Fishing Derby (Fishing Pools)'); -- Patch 3.3

DELETE FROM `disables` WHERE `sourceType`=9 AND `entry` IN (58, 59, 60);
INSERT INTO `disables` (`sourceType`, `entry`, `comment`) VALUES
(9, 58, 'Arena Season 6'), -- Patch 3.1
(9, 59, 'Arena Season 7'), -- Patch 3.2
(9, 60, 'Arena Season 8'); -- Patch 3.3

DELETE FROM `disables` WHERE `sourceType`=1 AND `entry` IN (14100, 14111);
INSERT INTO `disables` (`sourceType`, `entry`, `comment`) VALUES
(1, 14100, 'Relic of the Earthen Ring'), -- Patch 3.2
(1, 14111, 'Relic of the Earthen Ring'); -- Patch 3.2

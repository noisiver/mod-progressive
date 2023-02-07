DELETE FROM `disables` WHERE `sourceType`=2 AND `entry` IN (
    631, -- Icecrown Citadel
    632, -- The Forge of Souls
    658, -- Pit of Saron
    668 -- Halls of Reflection
);
DELETE FROM `disables` WHERE `sourceType`=9 AND `entry` IN (
    60, -- Arena Season 8
    63, -- Kalu'ak Fishing Derby (Turn-ins)
    64 -- Kalu'ak Fishing Derby (Fishing Pools)
);
DELETE FROM `disables` WHERE `sourceType`=3 AND `entry` IN (
    6, -- All Arenas
    32 -- Random Battleground
);

DELETE FROM `game_event_creature` WHERE `eventEntry`=58 AND `guid` IN (17676, 85159, 85160, 85208, 85217, 86928, 88160, 125691, 133917, 208493);
DELETE FROM `game_event_creature` WHERE `eventEntry`=59 AND `guid` IN (125693, 133920);
DELETE FROM `game_event_creature` WHERE `eventEntry`=60 AND `guid` IN (125689, 133919);
INSERT INTO `game_event_creature` (`eventEntry`, `guid`) VALUES
-- Arena Season 6
(58, 17676),
(58, 85159),
(58, 85160),
(58, 85208),
(58, 85217),
(58, 86928),
(58, 88160),
(58, 125691),
(58, 133917),
(58, 208493),
-- Arean Season 7
(59, 125693),
(59, 133920),
-- Arena Season 8
(60, 125689),
(60, 133919);

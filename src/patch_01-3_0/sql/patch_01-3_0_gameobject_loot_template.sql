SET 
@Heroism  := 40752,
@Valor    := 40753,
@Conquest := 45624,
@Triumph  := 47241;

DELETE FROM `gameobject_loot_template` WHERE `Entry` IN (24524, 24589, 25192, 25193, 26094, 26097, 26260) AND `Item` IN (@Heroism, @Valor, @Conquest, @Triumph);
INSERT INTO `gameobject_loot_template` (`Entry`, `Item`, `MinCount`, `MaxCount`, `Comment`) VALUES
-- The Oculus
(24524, @Heroism, 1, 1, 'Cache of Eregos - Emblem of Heroism'),
-- The Culling of Stratholme
(24589, @Heroism, 1, 1, 'Dark Runed Chest - Emblem of Heroism'),
-- Naxxramas
(25192, @Heroism, 1, 1, 'Four Horsemen Chest - Emblem of Heroism'),
(25193, @Valor, 1, 1, 'Four Horsemen Chest - Emblem of Valor'),
-- The Eye of Eternity
(26094, @Heroism, 2, 2, 'Alexstrasza\'s Gift - Emblem of Heroism'),
(26097, @Valor, 2, 2, 'Alexstrasza\'s Gift - Emblem of Valor'),
-- Halls of Stone
(26260, @Heroism, 1, 1, 'Tribunal Chest - Emblem of Heroism');

SET 
@Heroism  := 40752,
@Valor    := 40753,
@Conquest := 45624,
@Triumph  := 47241;

DELETE FROM `gameobject_loot_template` WHERE `Entry` IN (24524, 24589, 25192, 25193, 26094, 26097, 26260, 26929, 26946, 26955, 26956, 26959, 26960, 26961, 26962, 26963, 26967, 26974, 27030, 27061, 27068, 27073, 27074, 27078, 27079, 27080, 27081, 27085, 27086, 27335, 27356, 27414, 27416, 27417, 27498, 27503) AND `Item` IN (@Heroism, @Valor, @Conquest, @Triumph);
INSERT INTO `gameobject_loot_template` (`Entry`, `Item`, `Chance`, `MinCount`, `MaxCount`, `Comment`) VALUES
-- The Oculus
(24524, @Conquest, 100, 1, 1, 'Cache of Eregos - Emblem of Conquest'),
-- The Culling of Stratholme
(24589, @Conquest, 100, 1, 1, 'Dark Runed Chest - Emblem of Conquest'),
-- Naxxramas
(25192, @Conquest, 100, 1, 1, 'Four Horsemen Chest - Emblem of Conquest'),
(25193, @Conquest, 100, 1, 1, 'Four Horsemen Chest - Emblem of Conquest'),
-- The Eye of Eternity
(26094, @Conquest, 100, 2, 2, 'Alexstrasza\'s Gift - Emblem of Conquest'),
(26097, @Conquest, 100, 2, 2, 'Alexstrasza\'s Gift - Emblem of Conquest'),
-- Halls of Stone
(26260, @Conquest, 100, 1, 1, 'Tribunal Chest - Emblem of Conquest'),
-- Ulduar
(26929, @Conquest, 100, 1, 2, 'Cache of Living Stone - Emblem of Conquest'),
(26946, @Conquest, 100, 1, 1, 'Cache of Winter - Emblem of Conquest'),
(26955, @Conquest, 100, 1, 1, 'Cache of Storms - Emblem of Conquest'),
(26956, @Conquest, 100, 1, 1, 'Cache of Storms - Emblem of Conquest'),
(26959, @Conquest, 100, 2, 2, 'Freya\'s Gift - Emblem of Conquest'),
(26960, @Conquest, 100, 2, 2, 'Freya\'s Gift - Emblem of Conquest'),
(26961, @Conquest, 100, 1, 1, 'Freya\'s Gift - Emblem of Conquest'),
(26962, @Conquest, 100, 1, 1, 'Freya\'s Gift - Emblem of Conquest'),
(26963, @Conquest, 100, 1, 1, 'Cache of Innovation - Emblem of Conquest'),
(26967, @Conquest, 100, 1, 1, 'Cache of Innovation - Emblem of Conquest'),
(26974, @Conquest, 100, 2, 2, 'Gift of the Observer - Emblem of Conquest'),
(27030, @Conquest, 100, 1, 1, 'Gift of the Observer - Emblem of Conquest'),
(27061, @Conquest, 100, 1, 1, 'Cache of Living Stone - Emblem of Conquest'),
(27068, @Conquest, 100, 1, 1, 'Cache of Winter - Emblem of Conquest'),
(27073, @Conquest, 100, 1, 1, 'Cache of Storms - Emblem of Conquest'),
(27074, @Conquest, 100, 1, 1, 'Cache of Storms - Emblem of Conquest'),
(27078, @Conquest, 100, 3, 3, 'Freya\'s Gift - Emblem of Conquest'),
(27079, @Conquest, 100, 3, 3, 'Freya\'s Gift - Emblem of Conquest'),
(27080, @Conquest, 100, 3, 3, 'Freya\'s Gift - Emblem of Conquest'),
(27081, @Conquest, 100, 3, 3, 'Freya\'s Gift - Emblem of Conquest'),
(27085, @Conquest, 100, 1, 1, 'Cache of Innovation - Emblem of Conquest'),
(27086, @Conquest, 100, 1, 1, 'Cache of Innovation - Emblem of Conquest'),
-- Trial of the Crusader
(27335, @Triumph, 100, 3, 3, 'Champions\' Cache - Emblem of Triumph'),
(27356, @Triumph, 100, 3, 3, 'Champions\' Cache - Emblem of Triumph'),
(27498, @Triumph, 100, 3, 3, 'Champions\' Cache - Emblem of Triumph'),
(27503, @Triumph, 100, 3, 3, 'Champions\' Cache - Emblem of Triumph'),
-- Trial of the Champion
(27414, @Conquest, 100, 1, 1, 'Champion\'s Cache - Emblem of Conquest'),
(27416, @Conquest, 100, 1, 1, 'Eadric\'s Cache - Emblem of Conquest'),
(27417, @Conquest, 100, 1, 1, 'Confessor\'s Cache - Emblem of Conquest');

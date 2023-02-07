SET 
@Heroism  := 40752,
@Valor    := 40753,
@Conquest := 45624,
@Triumph  := 47241;

DELETE FROM `gameobject_loot_template` WHERE `Entry` IN (24524, 24589, 25192, 25193, 26094, 26097, 26260, 26929, 26946, 26955, 26956, 26959, 26960, 26961, 26962, 26963, 26967, 26974, 27030, 27061, 27068, 27073, 27074, 27078, 27079, 27080, 27081, 27085, 27086, 27335, 27356, 27414, 27416, 27417, 27498, 27503) AND `Item` IN (@Heroism, @Valor, @Conquest, @Triumph);
INSERT INTO `gameobject_loot_template` (`Entry`, `Item`, `Chance`, `MinCount`, `MaxCount`, `Comment`) VALUES
-- The Oculus
(24524, @Triumph, 100, 1, 1, 'Cache of Eregos - Emblem of Triumph'),
-- The Culling of Stratholme
(24589, @Triumph, 100, 1, 1, 'Dark Runed Chest - Emblem of Triumph'),
-- Naxxramas
(25192, @Triumph, 100, 1, 1, 'Four Horsemen Chest - Emblem of Triumph'),
(25193, @Triumph, 100, 1, 1, 'Four Horsemen Chest - Emblem of Triumph'),
-- The Eye of Eternity
(26094, @Triumph, 100, 2, 2, 'Alexstrasza\'s Gift - Emblem of Triumph'),
(26097, @Triumph, 100, 2, 2, 'Alexstrasza\'s Gift - Emblem of Triumph'),
-- Halls of Stone
(26260, @Triumph, 100, 1, 1, 'Tribunal Chest - Emblem of Triumph'),
-- Ulduar
(26929, @Triumph, 100, 1, 2, 'Cache of Living Stone - Emblem of Triumph'),
(26946, @Triumph, 100, 1, 1, 'Cache of Winter - Emblem of Triumph'),
(26955, @Triumph, 100, 1, 1, 'Cache of Storms - Emblem of Triumph'),
(26956, @Triumph, 100, 1, 1, 'Cache of Storms - Emblem of Triumph'),
(26959, @Triumph, 100, 2, 2, 'Freya\'s Gift - Emblem of Triumph'),
(26960, @Triumph, 100, 2, 2, 'Freya\'s Gift - Emblem of Triumph'),
(26961, @Triumph, 100, 1, 1, 'Freya\'s Gift - Emblem of Triumph'),
(26962, @Triumph, 100, 1, 1, 'Freya\'s Gift - Emblem of Triumph'),
(26963, @Triumph, 100, 1, 1, 'Cache of Innovation - Emblem of Triumph'),
(26967, @Triumph, 100, 1, 1, 'Cache of Innovation - Emblem of Triumph'),
(26974, @Triumph, 100, 2, 2, 'Gift of the Observer - Emblem of Triumph'),
(27030, @Triumph, 100, 1, 1, 'Gift of the Observer - Emblem of Triumph'),
(27061, @Triumph, 100, 1, 1, 'Cache of Living Stone - Emblem of Triumph'),
(27068, @Triumph, 100, 1, 1, 'Cache of Winter - Emblem of Triumph'),
(27073, @Triumph, 100, 1, 1, 'Cache of Storms - Emblem of Triumph'),
(27074, @Triumph, 100, 1, 1, 'Cache of Storms - Emblem of Triumph'),
(27078, @Triumph, 100, 3, 3, 'Freya\'s Gift - Emblem of Triumph'),
(27079, @Triumph, 100, 3, 3, 'Freya\'s Gift - Emblem of Triumph'),
(27080, @Triumph, 100, 3, 3, 'Freya\'s Gift - Emblem of Triumph'),
(27081, @Triumph, 100, 3, 3, 'Freya\'s Gift - Emblem of Triumph'),
(27085, @Triumph, 100, 1, 1, 'Cache of Innovation - Emblem of Triumph'),
(27086, @Triumph, 100, 1, 1, 'Cache of Innovation - Emblem of Triumph'),
-- Trial of the Crusader
(27335, @Triumph, 100, 3, 3, 'Champions\' Cache - Emblem of Triumph'),
(27356, @Triumph, 100, 3, 3, 'Champions\' Cache - Emblem of Triumph'),
(27498, @Triumph, 100, 3, 3, 'Champions\' Cache - Emblem of Triumph'),
(27503, @Triumph, 100, 3, 3, 'Champions\' Cache - Emblem of Triumph'),
-- Trial of the Champion
(27414, @Triumph, 100, 1, 1, 'Champion\'s Cache - Emblem of Triumph'),
(27416, @Triumph, 100, 1, 1, 'Eadric\'s Cache - Emblem of Triumph'),
(27417, @Triumph, 100, 1, 1, 'Confessor\'s Cache - Emblem of Triumph');

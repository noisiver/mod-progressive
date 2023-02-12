SET 
@Heroism  := 40752,
@Valor    := 40753,
@Conquest := 45624,
@Triumph  := 47241;

DELETE FROM `gameobject_loot_template` WHERE `Entry` IN (26929, 26946, 26955, 26956, 26959, 26960, 26961, 26962, 26963, 26967, 26974, 27030, 27061, 27068, 27073, 27074, 27078, 27079, 27080, 27081, 27085, 27086) AND `Item` IN (@Heroism, @Valor, @Conquest, @Triumph);
INSERT INTO `gameobject_loot_template` (`Entry`, `Item`, `MinCount`, `MaxCount`, `Comment`) VALUES
-- Ulduar
(26929, @Conquest, 1, 2, 'Cache of Living Stone - Emblem of Conquest'),
(26946, @Conquest, 1, 1, 'Cache of Winter - Emblem of Conquest'),
(26955, @Conquest, 1, 1, 'Cache of Storms - Emblem of Conquest'),
(26956, @Valor, 1, 1, 'Cache of Storms - Emblem of Valor'),
(26959, @Conquest, 2, 2, 'Freya\'s Gift - Emblem of Conquest'), -- ???
(26960, @Conquest, 2, 2, 'Freya\'s Gift - Emblem of Conquest'), -- ???
(26961, @Conquest, 1, 1, 'Freya\'s Gift - Emblem of Conquest'),
(26962, @Valor, 1, 1, 'Freya\'s Gift - Emblem of Valor'),
(26963, @Conquest, 1, 1, 'Cache of Innovation - Emblem of Conquest'),
(26967, @Conquest, 1, 1, 'Cache of Innovation - Emblem of Conquest'),
(26974, @Conquest, 2, 2, 'Gift of the Observer - Emblem of Conquest'),
(27030, @Valor, 1, 1, 'Gift of the Observer - Emblem of Valor'),
(27061, @Valor, 1, 1, 'Cache of Living Stone - Emblem of Valor'),
(27068, @Valor, 1, 1, 'Cache of Winter - Emblem of Valor'),
(27073, @Valor, 1, 1, 'Cache of Storms - Emblem of Valor'),
(27074, @Conquest, 1, 1, 'Cache of Storms - Emblem of Conquest'), -- ???
(27078, @Conquest, 3, 3, 'Freya\'s Gift - Emblem of Conquest'), -- ???
(27079, @Conquest, 3, 3, 'Freya\'s Gift - Emblem of Conquest'), -- ???
(27080, @Conquest, 3, 3, 'Freya\'s Gift - Emblem of Conquest'), -- ???
(27081, @Conquest, 3, 3, 'Freya\'s Gift - Emblem of Conquest'), -- ???
(27085, @Valor, 1, 1, 'Cache of Innovation - Emblem of Valor'),
(27086, @Valor, 1, 1, 'Cache of Innovation - Emblem of Valor');

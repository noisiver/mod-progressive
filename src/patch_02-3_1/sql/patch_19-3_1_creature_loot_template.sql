SET 
@Heroism  := 40752,
@Valor    := 40753,
@Conquest := 45624,
@Triumph  := 47241;

DELETE FROM `creature_loot_template` WHERE `Entry` IN (31125, 31722, 32857, 32867, 32927, 33118, 33186, 33190, 33271, 33288, 33293, 33449, 33515, 33692, 33693, 33694, 33724, 33885, 33955, 33993, 33994, 34175) AND `Item` IN (@Heroism, @Valor, @Conquest, @Triumph);
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `MinCount`, `MaxCount`, `Comment`) VALUES
-- Vault of Archavon
(33993, @Heroism, 2, 2, 'Emalon the Storm Watcher - Emblem of Conquest'),
(33994, @Conquest, 2, 2, 'Emalon the Storm Watcher (1) - Emblem of Conquest'),
-- Ulduar
(32857, @Valor, 1, 1, 'Stormcaller Brundir - Emblem of Valor'),
(32867, @Valor, 2, 2, 'Steelbreaker - Emblem of Valor'),
(32927, @Valor, 2, 2, 'Runemaster Molgeim - Emblem of Valor'),
(33118, @Valor, 1, 1, 'Ignis the Furnace Master - Emblem of Valor'),
(33186, @Valor, 1, 1, 'Razorscale - Emblem of Valor'),
(33190, @Conquest, 2, 2, 'Ignis the Furnace Master (1) - Emblem of Conquest'),
(33271, @Valor, 1, 1, 'General Vezax - Emblem of Valor'),
(33288, @Valor, 1, 1, 'Yogg-Saron - Emblem of Valor'),
(33293, @Valor, 1, 1, 'XT-002 Deconstructor - Emblem of Valor'),
(33449, @Conquest, 1, 1, 'General Vezax (1) - Emblem of Conquest'),
(33515, @Valor, 1, 1, 'Auriaya - Emblem of Valor'),
(33692, @Conquest, 2, 2, 'Runemaster Molgeim (1) - Emblem of Conquest'),
(33693, @Conquest, 2, 2, 'Steelbreaker (1) - Emblem of Conquest'),
(33694, @Conquest, 1, 1, 'Stormcaller Brundir (1) - Emblem of Conquest'),
(33724, @Conquest, 1, 1, 'Razorscale (1) - Emblem of Conquest'),
(33885, @Conquest, 1, 1, 'XT-002 Deconstructor (1) - Emblem of Conquest'),
(33955, @Conquest, 1, 1, 'Yogg-Saron (1) - Emblem of Conquest'),
(34175, @Conquest, 1, 1, 'Auriaya (1) - Emblem of Conquest');

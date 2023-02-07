SET 
@Heroism  := 40752,
@Valor    := 40753,
@Conquest := 45624,
@Triumph  := 47241;

DELETE FROM `reference_loot_template` WHERE `Entry`=34349 AND `Item` IN (@Heroism, @Valor, @Conquest, @Triumph);
INSERT INTO `reference_loot_template` (`Entry`, `Item`, `Chance`, `MinCount`, `MaxCount`, `Comment`) VALUES
-- Ulduar
(34349, @Triumph, 100, 1, 1, 'Emblem of Triumph');

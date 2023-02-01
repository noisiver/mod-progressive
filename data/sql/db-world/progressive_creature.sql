DROP TABLE IF EXISTS `progressive_creature`;
CREATE TABLE `progressive_creature` (
	`guid` INT(10) UNSIGNED NOT NULL COMMENT 'Global Unique Identifier',
	`id1` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT '0' COMMENT 'Creature Identifier',
	`map` SMALLINT(5) UNSIGNED NOT NULL DEFAULT '0' COMMENT 'Map Identifier',
	`position_x` FLOAT NOT NULL DEFAULT '0',
	`position_y` FLOAT NOT NULL DEFAULT '0',
	`position_z` FLOAT NOT NULL DEFAULT '0',
	`orientation` FLOAT NOT NULL DEFAULT '0',
	`spawntimesecs` INT(10) UNSIGNED NOT NULL DEFAULT '120',
    `min_patch` INT(3) UNSIGNED NOT NULL DEFAULT '0',
    `max_patch` INT(3) UNSIGNED NOT NULL DEFAULT '21',
	PRIMARY KEY (`guid`, `min_patch`, `max_patch`) USING BTREE,
	INDEX `idx_map` (`map`) USING BTREE,
	INDEX `idx_id` (`id1`) USING BTREE
)
COMMENT='Progressive Creature System'
COLLATE='utf8mb4_general_ci'
;

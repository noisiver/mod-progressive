DROP TABLE IF EXISTS `progressive_gameobject`;
CREATE TABLE `progressive_gameobject` (
	`guid` INT(10) UNSIGNED NOT NULL AUTO_INCREMENT COMMENT 'Global Unique Identifier',
	`id` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT '0' COMMENT 'Gameobject Identifier',
	`map` SMALLINT(5) UNSIGNED NOT NULL DEFAULT '0' COMMENT 'Map Identifier',
	`position_x` FLOAT NOT NULL DEFAULT '0',
	`position_y` FLOAT NOT NULL DEFAULT '0',
	`position_z` FLOAT NOT NULL DEFAULT '0',
	`orientation` FLOAT NOT NULL DEFAULT '0',
	`rotation0` FLOAT NOT NULL DEFAULT '0',
	`rotation1` FLOAT NOT NULL DEFAULT '0',
	`rotation2` FLOAT NOT NULL DEFAULT '0',
	`rotation3` FLOAT NOT NULL DEFAULT '0',
	`spawntimesecs` INT(11) NOT NULL DEFAULT '0',
	`animprogress` TINYINT(3) UNSIGNED NOT NULL DEFAULT '0',
	`state` TINYINT(3) UNSIGNED NOT NULL DEFAULT '0',
    `min_patch` INT(3) UNSIGNED NOT NULL DEFAULT '0',
    `max_patch` INT(3) UNSIGNED NOT NULL DEFAULT '21',
	PRIMARY KEY (`guid`) USING BTREE
)
COMMENT='Gameobject System'
COLLATE='utf8mb4_general_ci'
;

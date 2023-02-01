DROP TABLE IF EXISTS `progressive_gameobject_template`;
CREATE TABLE `progressive_gameobject_template` (
	`entry` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT '0',
	`type` TINYINT(3) UNSIGNED NOT NULL DEFAULT '0',
	`name` VARCHAR(100) NOT NULL DEFAULT '' COLLATE 'utf8mb4_general_ci',
	`patch` INT(3) UNSIGNED NOT NULL DEFAULT '0',
	PRIMARY KEY (`entry`, `patch`) USING BTREE,
	INDEX `idx_name` (`name`) USING BTREE
)
COMMENT='Gameobject System'
COLLATE='utf8mb4_general_ci'
ENGINE=MyISAM
ROW_FORMAT=FIXED
;

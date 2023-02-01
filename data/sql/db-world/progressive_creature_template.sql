DROP TABLE IF EXISTS `progressive_creature_template`;
CREATE TABLE `progressive_creature_template` (
	`entry` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT '0',
    `patch` INT(3) UNSIGNED NOT NULL DEFAULT '0',
	`name` CHAR(100) NOT NULL DEFAULT '0' COLLATE 'utf8mb4_general_ci',
	`subname` CHAR(100) NULL DEFAULT NULL COLLATE 'utf8mb4_general_ci',
	`minlevel` TINYINT(3) UNSIGNED NOT NULL DEFAULT '1',
	`maxlevel` TINYINT(3) UNSIGNED NOT NULL DEFAULT '1',
	PRIMARY KEY (`entry`, `patch`) USING BTREE,
	INDEX `idx_name` (`name`) USING BTREE
)
COMMENT='Progressive Creature System'
COLLATE='utf8mb4_general_ci'
;

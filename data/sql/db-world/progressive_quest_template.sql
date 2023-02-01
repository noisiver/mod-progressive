DROP TABLE IF EXISTS `progressive_quest_template`;
CREATE TABLE `progressive_quest_template` (
	`ID` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT '0',
	`LogTitle` TEXT NULL DEFAULT NULL COLLATE 'utf8mb4_general_ci',
	`Patch` INT(3) UNSIGNED NOT NULL DEFAULT '0',
	PRIMARY KEY (`ID`, `Patch`) USING BTREE
)
COMMENT='Quest System'
COLLATE='utf8mb4_general_ci'
ENGINE=MyISAM
;

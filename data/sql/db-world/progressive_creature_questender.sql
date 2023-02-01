DROP TABLE IF EXISTS `progressive_creature_questender`;
CREATE TABLE `progressive_creature_questender` (
	`id` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT '0' COMMENT 'Identifier',
	`quest` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT '0' COMMENT 'Quest Identifier',
    `min_patch` INT(3) UNSIGNED NOT NULL DEFAULT '0',
    `max_patch` INT(3) UNSIGNED NOT NULL DEFAULT '21',
	PRIMARY KEY (`id`, `quest`, `min_patch`, `max_patch`) USING BTREE
)
COMMENT='Progressive Creature Quest System'
COLLATE='utf8mb4_general_ci'
;

DROP TABLE IF EXISTS `progressive_gossip_menu_option`;
CREATE TABLE `progressive_gossip_menu_option` (
	`MenuID` SMALLINT(5) UNSIGNED NOT NULL DEFAULT '0',
	`OptionID` SMALLINT(5) UNSIGNED NOT NULL DEFAULT '0',
    `min_patch` INT(3) UNSIGNED NOT NULL DEFAULT '0',
    `max_patch` INT(3) UNSIGNED NOT NULL DEFAULT '21',
	PRIMARY KEY (`MenuID`, `OptionID`, `min_patch`, `max_patch`) USING BTREE
)
COMMENT='Progressive Creature System'
COLLATE='utf8mb4_general_ci'
;

INSERT INTO `progressive_gossip_menu_option` (`MenuID`, `OptionID`, `min_patch`, `max_patch`) VALUES
(401, 6, 15, 21),
(2144, 7, 15, 21),
(3519, 6, 15, 21);

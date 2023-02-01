DROP TABLE IF EXISTS `progressive_item_template`;
CREATE TABLE `progressive_item_template` (
	`entry` MEDIUMINT(7) UNSIGNED NOT NULL DEFAULT '0',
    `patch` INT(3) UNSIGNED NOT NULL DEFAULT '0',
	`name` VARCHAR(255) NOT NULL DEFAULT '' COLLATE 'utf8mb4_0900_ai_ci',
	`class` TINYINT(3) UNSIGNED NOT NULL DEFAULT '0',
	`subclass` TINYINT(3) UNSIGNED NOT NULL DEFAULT '0',
	PRIMARY KEY (`entry`, `patch`) USING BTREE,
	INDEX `idx_name` (`name`(250)) USING BTREE,
	INDEX `items_index` (`class`) USING BTREE
)
COMMENT='Item System'
COLLATE='utf8mb4_0900_ai_ci'
;

INSERT INTO `progressive_item_template` (`entry`, `patch`, `name`, `class`, `subclass`) VALUES
(50629, 0, 'Testing', 4, 1);

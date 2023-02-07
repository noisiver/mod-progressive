UPDATE `quest_template` SET `RewardItem1`=47241, `RewardAmount1`=2 WHERE `ID`=24788; -- Daily Heroic Random (1st)
UPDATE `quest_template` SET `RewardItem1`=0, `RewardAmount1`=0 WHERE `ID`=24789; -- Daily Heroic Random (Nth)
UPDATE `quest_template` SET `RewardItem1`=47241, `RewardAmount1`=1 WHERE `ID`=24790; -- Daily Normal Random (1st)

UPDATE `quest_template` SET `RewardItem1`=45624 WHERE `ID` IN (13245, 13246, 13247, 13248, 13249, 13250, 13251, 13252, 13253, 13254, 13255, 13256, 14199); -- Heroic Dungeon Dailies

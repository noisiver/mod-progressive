UPDATE `creature` SET `phaseMask`=16384 WHERE `id1` IN (
    33608, -- Alchemy
    33609, -- Blacksmithing
    33610, -- Enchanting
    33611, -- Engineering
    33612, -- Leatherworking
    33613, -- Tailoring
    33614, -- Jewelcrafting
    33616, -- Herbalism
    33617, -- Mining
    33618, -- Skinning
    33619, -- Cooking
    33621, -- First Aid
    33623, -- Fishing
    33963, -- Emblem of Conquest Quartermaster
    33964, -- Emblem of Conquest Quartermaster
    33993, -- Emalon the Storm Watcher
    34015, -- Tempest Warder
    34244, -- Jean Pierre Poulain <Argent Tournament Valiant>
    34765, -- Zelli Hotnozzle <Thunder Bluff Zeppelin Master>
    34955, -- Karg Skullgore <Battlemaster>
    34976, -- Ruk Warstomper <Battlemaster>
    34978, -- Mosha Starhorn <Battlemaster>
    34988, -- Landuen Moonclaw <Battlemaster>
    34991, -- Borim Goldhammer <Battlemaster>
    34997, -- Devin Fardale <Battlemaster>
    34998, -- Alison Devay <Battlemaster>
    35007, -- Lixa Felflinger <Battlemaster>
    35008, -- Sawemba <Battlemaster>
    35013, -- Koralon the Flame Watcher
    35017, -- Gorom Warfang <Isle of Conquest Battlemaster>
    35020, -- Deathscreamer Gura <Isle of Conquest Battlemaster>
    35021, -- Marog <Isle of Conquest Battlemaster>
    35023, -- Terrance Matterly <Isle of Conquest Battlemaster>
    35024, -- Dracien Flanning <Isle of Conquest Battlemaster>
    35025, -- Lynette Bracer <Isle of Conquest Battlemaster>
    35068, -- Gotura Fourwinds <The Earthen Ring>
    35073, -- Farseer Eannu <The Earthen Ring>
    35143, -- Flame Warder
    35281, -- Rukua <Paladin Trainer>
    35364, -- Slahtz <Experience Eliminator>
    35365, -- Behsten <Experience Eliminator>
    35494, -- Emblem of Triumph Quartermaster
    35495, -- Emblem of Triumph Quartermaster
    35587, -- Argent Peacekeeper
    35594, -- Brassbolt Mechawrench <Steam-Powered Auctioneer>
    35607, -- Reginald Arcfire <Steam-Powered Auctioneer>
    36217, -- Overseer Kraggosh
    36273, -- Bragor Bloodfist <Kor'kron Captain>
    36479, -- Archmage Mordent Evenshade <The Highborne>
    36481, -- Sentinel Stillbough
    36517, -- Aleric Hawkins <The Deathstalkers>
    37776, -- Apprentice Nelphi <Kirin Tor>
    37780, -- Dark Ranger Vorel
    37888, -- Frax Bucketdrop <Flight Master>
    37915, -- Timothy Cunningham <Bat Handler>
    37941, -- Emblem of Frost Quartermaster
    37942, -- Emblem of Frost Quartermaster
    37965, -- Argent Commander
    37967, -- Ebon Blade Commander
    38433, -- Toravon the Ice Watcher
    38482, -- Frost Warder
    39263, -- Disassembled Mechano-Tank
    39275, -- Gnomeregan Medic
    39349, -- Gnomeregan Trainee
    39368, -- Drill Sergeant Steamcrank
    39386, -- Pilot Muzzlesprock
    39396, -- 'Thunderflash'
    39675, -- Captain Tread Sparknozzle
    39711, -- Mechano-Tank Attack Target
    39715, -- Ejector Mechano-Tank
    39716, -- Scuttling Mechano-Tank
    39717 -- Shooting Mechano-Tank
);

UPDATE `creature` SET `id1`=5624, `equipment_id`=0 WHERE `id1`=36213; -- Kor'kron Overseer -> Undercity Guardian

UPDATE `creature` SET `phaseMask`=1 WHERE `id1` IN (
    36217, -- Overseer Kraggosh
    36273, -- Bragor Bloodfist <Kor'kron Captain>
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
    38482 -- Frost Warder
);

UPDATE `creature` SET `id1`=36213, `equipment_id`=1 WHERE `id1`=5624; -- Undercity Guardian -> Kor'kron Overseer

(define (problem Monster3)
    (:domain treasureHunt)
    (:objects
        loc1 loc2 loc3 loc4 loc5 loc6 loc7 loc8 loc9 ; caves
        blackGoblinAt3 blackGoblinAt5                ; monsters
        goldenNecklaceAt4 goldenNecklaceAt8          ; treasures
        movindSand                                   ; pits
        talariaSandals                               ; boots
        bowOfPeril spearOfLeonidas                   ; weapons
    )
    (:init
        (cave loc1)
        (cave loc2)
        (cave loc3)
        (cave loc4)
        (cave loc5)
        (cave loc6)
        (cave loc7)
        (cave loc8)
        (cave loc9)

        (hasSingleDoor loc1 loc5)
        (hasSingleDoor loc5 loc2)
        (hasSingleDoor loc5 loc7)
        (hasSingleDoor loc5 loc9)
        (hasSingleDoor loc6 loc8)
        (hasSingleDoor loc7 loc4)
        (hasSingleDoor loc8 loc7)

        (hasRoundDoor loc1 loc2)
        (hasRoundDoor loc2 loc3)
        (hasRoundDoor loc3 loc4)
        (hasRoundDoor loc5 loc6)

        ; cave loc1
        (playerAt loc1)

        ; cave loc2
        (weapon spearOfLeonidas)
        (weaponAt spearOfLeonidas loc2)

        ; cave loc3
        (monster blackGoblinAt3)
        (monsterAt blackGoblinAt3 loc3)

        ; cave loc4
        (weapon bowOfPeril)
        (weaponAt bowOfPeril loc4)
        (treasure goldenNecklaceAt4)
        (treasureAt goldenNecklaceAt4 loc4)

        ; cave loc5
        (monster blackGoblinAt5)
        (monsterAt blackGoblinAt5 loc5)

        ; cave loc6
        (boots talariaSandals)
        (bootsAt talariaSandals loc6)

        ; cave loc7
        (pit movindSand)
        (pitAt movindSand loc7)

        ; cave loc8
        (treasure goldenNecklaceAt8)
        (treasureAt goldenNecklaceAt8 loc8)
    )
    (:goal
        (and
            (playerAt loc1)
            (treasureCollected goldenNecklaceAt4)
            (treasureCollected goldenNecklaceAt8)
        )
    )
)
(define (problem Monster2)
    (:domain treasureHunt)
    (:objects
        loc1 loc2 loc3 loc4 loc5 loc6 loc7 loc8 loc9 ; caves
        blackGoblin                                  ; monsters
        goldenNecklace                               ; treasures
        movindSand                                   ; pits
        talariaSandals                               ; boots
        bowOfPeril                                   ; weapons
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
        (hasSingleDoor loc7 loc4)

        (hasRoundDoor loc1 loc2)
        (hasRoundDoor loc2 loc3)
        (hasRoundDoor loc3 loc4)
        (hasRoundDoor loc5 loc6)
        (hasRoundDoor loc6 loc8)

        (playerAt loc1)

        (monster blackGoblin)
        (monsterAt blackGoblin loc3)

        (treasure goldenNecklace)
        (treasureAt goldenNecklace loc4)

        (weapon bowOfPeril)
        (weaponAt bowOfPeril loc6)

        (pit movindSand)
        (pitAt movindSand loc7)

        (boots talariaSandals)
        (bootsAt talariaSandals loc8)

    )
    (:goal
        (and
            (playerAt loc1)
            (treasureCollected goldenNecklace)
        )
    )
)
(define (problem Monster3)
    (:domain treasureHunt)
    (:objects
        loc1 loc2 loc3 loc4 loc5 loc6 loc7 loc8 loc9 - cave
        blackGoblinAt3 blackGoblinAt5                - monster
        goldenNecklaceAt4 goldenNecklaceAt8          - treasure
        movindSand                                   - pit
        talariaSandals                               - boots
        bowOfPeril spearOfLeonidas                   - weapon
    )
    (:init
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

        (playerAt loc1)
        (weaponAt spearOfLeonidas loc2)
        (monsterAt blackGoblinAt3 loc3)
        (weaponAt bowOfPeril loc4)
        (treasureAt goldenNecklaceAt4 loc4)
        (monsterAt blackGoblinAt5 loc5)
        (bootsAt talariaSandals loc6)
        (pitAt movindSand loc7)
        (treasureAt goldenNecklaceAt8 loc8)
    )
    (:goal
        (and
            (playerAt loc1)
            (forall (?treasureInRound - treasure)
                (treasureCollected ?treasureInRound)
            )
        )
    )
)
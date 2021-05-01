(define (problem Monster2)
    (:domain treasureHunt)
    (:objects
        loc1 loc2 loc3 loc4 loc5 loc6 loc7 loc8 loc9 - cave
        blackGoblin                                  - monster
        goldenNecklace                               - treasure
        movindSand                                   - pit
        talariaSandals                               - boots
        bowOfPeril                                   - weapon
    )
    (:init
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
        (monsterAt blackGoblin loc3)
        (treasureAt goldenNecklace loc4)
        (weaponAt bowOfPeril loc6)
        (pitAt movindSand loc7)
        (bootsAt talariaSandals loc8)
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
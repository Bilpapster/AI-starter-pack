(define (problem Monster1)
    (:domain treasureHunt)
    (:objects
        loc1 loc2 loc3 loc4 loc5 loc6   - cave
        blackGoblin                     - monster
        goldenNecklace                  - treasure
        movingSand                      - pit

        ; placeholders 
        noWeaponInRound                 - weapon
        noBootsInRound                  - boots
    )
    (:init
        (hasSingleDoor loc1 loc5)
        (hasSingleDoor loc1 loc6)
        (hasSingleDoor loc5 loc4)
        (hasSingleDoor loc6 loc4)

        (hasRoundDoor loc1 loc2)
        (hasRoundDoor loc2 loc3)
        (hasRoundDoor loc3 loc4)

        (playerAt loc1)
        (monsterAt blackGoblin loc6)
        (pitAt movingSand loc5)
        (treasureAt goldenNecklace loc4)
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
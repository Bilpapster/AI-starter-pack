(define (problem Monster1)
    (:domain treasureHunt)
    (:objects
        loc1 loc2 loc3 loc4 loc5 loc6   ; caves
        aMonster                        ; monsters
        aTreasure                       ; treasures
        aPit                            ; pits

    )
    (:init
        (cave loc1)
        (cave loc2)
        (cave loc3)
        (cave loc4)
        (cave loc5)
        (cave loc6)

        (hasSingleDoor loc1 loc5)
        (hasSingleDoor loc1 loc6)
        (hasSingleDoor loc5 loc4)
        (hasSingleDoor loc6 loc4)

        (hasRoundDoor loc1 loc2)
        (hasRoundDoor loc2 loc3)
        (hasRoundDoor loc3 loc4)

        (playerAt loc1)

        (monster aMonster)
        (monsterAt aMonster loc6)

        (pit aPit)
        (pitAt aPit loc5)

        (treasure aTreasure)
        (treasureAt aTreasure loc4)
    )
    (:goal
        (and
            (playerAt loc1)
            (treasureCollected aTreasure)
        )
    )
)
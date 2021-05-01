(define (domain treasureHunt)
    (:requirements :strips
                   :negative-preconditions
                   :equality 
                   :disjunctive-preconditions)
                   
    (:predicates

        ; game entities
        (cave ?aCave)
        (monster ?aMonster)
        (weapon ?aWeapon)
        (pit ?aPit)
        (treasure ?aTreasure)
        (boots ?someBoots)

        ; connection between caves
        (hasSingleDoor ?caveStart ?caveDestination)
        (hasRoundDoor ?caveStart ?caveDestination)

        ; location of game objects
        (treasureAt ?aTreasure ?aCave)
        (weaponAt ?aWeapon ?aCave)
        (bootsAt ?someBoots ?aCave)
        (monsterAt ?aMonster ?aCave)
        (pitAt ?aPit ?aCave)
        (playerAt ?aCave)

        ; collection of game objects
        (treasureCollected ?aTreasure)
        (weaponAvailable ?aWeapon)
        (bootsAvailable ?someBoots)
    )

    (:action Move
        :parameters (?caveStart ?caveDestination ?aPit ?aMonster)
        :precondition (and 
                          (cave ?caveStart) (cave ?caveDestination) (pit ?aPit) (monster ?aMonster) 
                          (playerAt ?caveStart)
                          (or 
                              (hasSingleDoor ?caveStart ?caveDestination) 
                              (hasRoundDoor ?caveStart ?caveDestination) 
                              (hasRoundDoor ?caveDestination ?caveStart)
                          )
                          (not (monsterAt ?aMonster ?caveStart))
                          (not (pitAt ?aPit ?caveStart))
                      )
        :effect (and 
                    (playerAt ?caveDestination) 
                    (not (playerAt ?caveStart))
                )
    )

    (:action KillMonster
        :parameters (?aCave ?aMonster ?aWeapon)
        :precondition (and 
                          (cave ?aCave) (monster ?aMonster) (weapon ?aWeapon)
                          (playerAt ?aCave) (monsterAt ?aMonster ?aCave) 
                          (weaponAvailable ?aWeapon)
                      )
        :effect (and 
                    (not (monsterAt ?aMonster ?aCave)) 
                    (not (weaponAvailable ?aWeapon))
                )
    )

    (:action JumpOverPit
        :parameters (?aCave ?aPit ?someBoots)
        :precondition (and 
                          (cave ?aCave) (pit ?aPit) (boots ?someBoots)
                          (playerAt ?aCave) (pitAt ?aPit ?aCave) 
                          (bootsAvailable ?someBoots)
                      )
        :effect (and 
                    (not (pitAt ?aPit ?aCave)) 
                    (not (bootsAvailable ?someBoots))
                )
    )

    (:action CollectTreasure
        :parameters (?aCave ?aTreasure)
        :precondition (and 
                          (cave ?aCave) (treasure ?aTreasure)
                          (playerAt ?aCave) (treasureAt ?aTreasure ?aCave)
                      )
        :effect (and 
                    (treasureCollected ?aTreasure) 
                    (not (treasureAt ?aTreasure ?aCave))
                )
    )

    (:action CollectWeapon
        :parameters (?aCave ?aWeapon)
        :precondition (and 
                          (cave ?aCave) (weapon ?aWeapon)
                          (playerAt ?aCave) (weaponAt ?aWeapon ?aCave)
                      )
        :effect (and 
                    (weaponAvailable ?aWeapon) 
                    (not (weaponAt ?aWeapon ?aCave))
                )
    )

    (:action CollectBoots
        :parameters (?aCave ?someBoots)
        :precondition (and 
                          (cave ?aCave) (boots ?someBoots)
                          (playerAt ?aCave) (bootsAt ?someBoots ?aCave)
                      )
        :effect (and 
                    (bootsAvailable ?someBoots) 
                    (not (bootsAt ?someBoots ?aCave))
                )
    )
)
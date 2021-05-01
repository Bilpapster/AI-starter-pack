(define (domain treasureHunt)
    (:requirements :strips
                   :typing
                   :negative-preconditions
                   :equality 
                   :disjunctive-preconditions
                   :universal-preconditions)
    
    (:types
        cave - objects
        monster - object 
        weapon - object 
        pit - object 
        treasure - object
        boots - object
        
    )
                   
    (:predicates

        ; game entities
        ; (cave ?aCave)
        ; (monster ?aMonster)
        ; (weapon ?aWeapon)
        ; (pit ?aPit)
        ; (treasure ?aTreasure)
        ; (boots ?someBoots)

        ; connection between caves
        (hasSingleDoor ?caveStart - cave ?caveDestination - cave)
        (hasRoundDoor ?caveStart - cave ?caveDestination - cave)

        ; location of game objects
        (treasureAt ?aTreasure - treasure ?aCave - cave)
        (weaponAt ?aWeapon - weapon ?aCave - cave)
        (bootsAt ?someBoots - boots ?aCave - cave)
        (monsterAt ?aMonster - monster ?aCave - cave)
        (pitAt ?aPit - pit ?aCave - cave)
        (playerAt ?aCave - cave)

        ; collection of game objects
        (treasureCollected ?aTreasure - treasure)
        (weaponAvailable ?aWeapon - weapon)
        (bootsAvailable ?someBoots - boots)
    )

    (:action Move
        :parameters (?caveStart - cave ?caveDestination - cave)
        :precondition (and 
                          ;(cave ?caveStart) (cave ?caveDestination) (pit ?aPit) (monster ?aMonster) 
                          (playerAt ?caveStart)
                          (or 
                              (hasSingleDoor ?caveStart ?caveDestination) 
                              (hasRoundDoor ?caveStart ?caveDestination) 
                              (hasRoundDoor ?caveDestination ?caveStart)
                          )
                          (forall (?monsterInGame - monster)
                                (not (monsterAt ?monsterInGame ?caveStart))
                          )
                          (forall (?pitInGame - pit)
                                (not (pitAt ?pitInGame ?caveStart))
                          )
                      )
        :effect (and 
                    (playerAt ?caveDestination) 
                    (not (playerAt ?caveStart))
                )
    )

    (:action KillMonster
        :parameters (?aCave - cave ?aMonster - monster ?aWeapon - weapon)
        :precondition (and 
                          ;(cave ?aCave) (monster ?aMonster) (weapon ?aWeapon)
                          (playerAt ?aCave) (monsterAt ?aMonster ?aCave) 
                          (weaponAvailable ?aWeapon)
                      )
        :effect (and 
                    (not (monsterAt ?aMonster ?aCave)) 
                    (not (weaponAvailable ?aWeapon))
                )
    )

    (:action JumpOverPit
        :parameters (?aCave - cave ?aPit - pit ?someBoots - boots)
        :precondition (and 
                          ;(cave ?aCave) (pit ?aPit) (boots ?someBoots)
                          (playerAt ?aCave) (pitAt ?aPit ?aCave) 
                          (bootsAvailable ?someBoots)
                      )
        :effect (and 
                    (not (pitAt ?aPit ?aCave)) 
                    (not (bootsAvailable ?someBoots))
                )
    )

    (:action CollectTreasure
        :parameters (?aCave - cave ?aTreasure - treasure)
        :precondition (and 
                          ;(cave ?aCave) (treasure ?aTreasure)
                          (playerAt ?aCave) (treasureAt ?aTreasure ?aCave)
                      )
        :effect (and 
                    (treasureCollected ?aTreasure) 
                    (not (treasureAt ?aTreasure ?aCave))
                )
    )

    (:action CollectWeapon
        :parameters (?aCave - cave ?aWeapon - weapon)
        :precondition (and 
                          ;(cave ?aCave) (weapon ?aWeapon)
                          (playerAt ?aCave) (weaponAt ?aWeapon ?aCave)
                      )
        :effect (and 
                    (weaponAvailable ?aWeapon) 
                    (not (weaponAt ?aWeapon ?aCave))
                )
    )

    (:action CollectBoots
        :parameters (?aCave - cave ?someBoots - boots)
        :precondition (and 
                          ;(cave ?aCave) (boots ?someBoots)
                          (playerAt ?aCave) (bootsAt ?someBoots ?aCave)
                      )
        :effect (and 
                    (bootsAvailable ?someBoots) 
                    (not (bootsAt ?someBoots ?aCave))
                )
    )
)
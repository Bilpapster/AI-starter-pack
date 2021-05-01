(define (domain treasure-hunt)
    (:requirements :strips
                   :typing
                   :negative-preconditions
                   :universal-preconditions
                   :disjunctive-preconditions)
    
    (:types
        cave monster weapon pit treasure boots - object
    )
                   
    (:predicates

        ; connection between caves
        (has-single-door ?cave_start - cave ?cave_destination - cave)
        (has-round-door ?cave_start - cave ?cave_destination - cave)

        ; location of game objects
        (treasure-at ?a_treasure - treasure ?a_cave - cave)
        (weapon-at ?a_weapon - weapon ?a_cave - cave)
        (boots-at ?some_boots - boots ?a_cave - cave)
        (monster-at ?a_monster - monster ?a_cave - cave)
        (pit-at ?a_pit - pit ?a_cave - cave)
        (player-at ?a_cave - cave)

        ; collection of game objects
        (treasure-collected ?a_treasure - treasure)
        (weapon-available ?a_weapon - weapon)
        (boots-available ?some_boots - boots)
    )

    (:action move
        :parameters (?cave_start - cave ?cave_destination - cave)
        :precondition (and 
                          (player-at ?cave_start)
                          (or 
                              (has-single-door ?cave_start ?cave_destination) 
                              (has-round-door ?cave_start ?cave_destination) 
                              (has-round-door ?cave_destination ?cave_start)
                          )
                          (forall (?monsterInGame - monster)
                                (not (monster-at ?monsterInGame ?cave_start))
                          )
                          (forall (?pitInGame - pit)
                                (not (pit-at ?pitInGame ?cave_start))
                          )
                      )
        :effect (and 
                    (player-at ?cave_destination) 
                    (not (player-at ?cave_start))
                )
    )

    (:action kill-monster
        :parameters (?a_cave - cave ?a_monster - monster ?a_weapon - weapon)
        :precondition (and 
                          (player-at ?a_cave) (monster-at ?a_monster ?a_cave) 
                          (weapon-available ?a_weapon)
                      )
        :effect (and 
                    (not (monster-at ?a_monster ?a_cave)) 
                    (not (weapon-available ?a_weapon))
                )
    )

    (:action jump-over-pit
        :parameters (?a_cave - cave ?a_pit - pit ?some_boots - boots)
        :precondition (and 
                          (player-at ?a_cave) (pit-at ?a_pit ?a_cave) 
                          (boots-available ?some_boots)
                      )
        :effect (and 
                    (not (pit-at ?a_pit ?a_cave)) 
                    (not (boots-available ?some_boots))
                )
    )

    (:action collect-treasure
        :parameters (?a_cave - cave ?a_treasure - treasure)
        :precondition (and 
                          (player-at ?a_cave) (treasure-at ?a_treasure ?a_cave)
                      )
        :effect (and 
                    (treasure-collected ?a_treasure) 
                    (not (treasure-at ?a_treasure ?a_cave))
                )
    )

    (:action collect-weapon
        :parameters (?a_cave - cave ?a_weapon - weapon)
        :precondition (and 
                          (player-at ?a_cave) (weapon-at ?a_weapon ?a_cave)
                      )
        :effect (and 
                    (weapon-available ?a_weapon) 
                    (not (weapon-at ?a_weapon ?a_cave))
                )
    )

    (:action collect-boots
        :parameters (?a_cave - cave ?some_boots - boots)
        :precondition (and 
                          (player-at ?a_cave) (boots-at ?some_boots ?a_cave)
                      )
        :effect (and 
                    (boots-available ?some_boots) 
                    (not (boots-at ?some_boots ?a_cave))
                )
    )
)
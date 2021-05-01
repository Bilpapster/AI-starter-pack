(define (problem Monster3)
    (:domain treasure-hunt)
    (:objects
        loc1 loc2 loc3 loc4 loc5 loc6 loc7 loc8 loc9 - cave
        black_goblin1 black_goblin2                  - monster
        golden_necklace1 golden_necklace2            - treasure
        moving_sand                                  - pit
        talaria_sandals                              - boots
        bow_of_peril spear_of_leonidas               - weapon
    )
    (:init
        (has-single-door loc1 loc5)
        (has-single-door loc5 loc2)
        (has-single-door loc5 loc7)
        (has-single-door loc5 loc9)
        (has-single-door loc6 loc8)
        (has-single-door loc7 loc4)
        (has-single-door loc8 loc7)

        (has-round-door loc1 loc2)
        (has-round-door loc2 loc3)
        (has-round-door loc3 loc4)
        (has-round-door loc5 loc6)

        (player-at loc1)
        (weapon-at spear_of_leonidas loc2)
        (monster-at black_goblin1 loc3)
        (weapon-at bow_of_peril loc4)
        (treasure-at golden_necklace1 loc4)
        (monster-at black_goblin2 loc5)
        (boots-at talaria_sandals loc6)
        (pit-at moving_sand loc7)
        (treasure-at golden_necklace2 loc8)
    )
    (:goal
        (and
            (player-at loc1)
            (forall (?treasure_in_round - treasure)
                (treasure-collected ?treasure_in_round)
            )
        )
    )
)
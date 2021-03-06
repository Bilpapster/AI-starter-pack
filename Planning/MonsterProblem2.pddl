(define (problem Monster2)
    (:domain treasure-hunt)
    (:objects
        loc1 loc2 loc3 loc4 loc5 loc6 loc7 loc8 loc9 - cave
        black_goblin                                 - monster
        golden_necklace                              - treasure
        moving_sand                                  - pit
        talaria_sandals                              - boots
        bow_of_peril                                 - weapon
    )
    (:init
        (has-single-passage loc1 loc5)
        (has-single-passage loc5 loc2)
        (has-single-passage loc5 loc7)
        (has-single-passage loc5 loc9)
        (has-single-passage loc7 loc4)

        (has-round-passage loc1 loc2)
        (has-round-passage loc2 loc3)
        (has-round-passage loc3 loc4)
        (has-round-passage loc5 loc6)
        (has-round-passage loc6 loc8)

        (player-at loc1)
        (monster-at black_goblin loc3)
        (treasure-at golden_necklace loc4)
        (weapon-at bow_of_peril loc6)
        (pit-at moving_sand loc7)
        (boots-at talaria_sandals loc8)
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
(define (problem Monster1)
    (:domain treasure-hunt)
    (:objects
        loc1 loc2 loc3 loc4 loc5 loc6   - cave
        black_goblin                    - monster
        golden_necklace                 - treasure
        moving_sand                     - pit

        ; placeholders 
        no_weapon_in_round              - weapon
        no_boots_in_round               - boots
    )
    (:init
        (has-single-door loc1 loc5)
        (has-single-door loc1 loc6)
        (has-single-door loc5 loc4)
        (has-single-door loc6 loc4)

        (has-round-door loc1 loc2)
        (has-round-door loc2 loc3)
        (has-round-door loc3 loc4)

        (player-at loc1)
        (monster-at black_goblin loc6)
        (pit-at moving_sand loc5)
        (treasure-at golden_necklace loc4)
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
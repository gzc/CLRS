/*************************************************************************
    > File Name: weighted_activity_selection.h
    > Author: Nikolaus Fedurko (@B1Z0N)
    > Mail: 
    > Created Time: Wed 3 Aug 2019 02:16:46 PM CST
 ************************************************************************/
/*************************************************************************
    Weighted activity selection problem
    --------------------
    Given N activities where every activity is represented by 
    following three elements of it.
    
    1. Start Time
    2. Finish Time
    3. Weight or Value Associated

    Find the maximum weight subset of activities such 
    that no two of them in the subset overlap.

    Time complexity
    ---------------
    O(N*lg(N))

    Space complexity
    ----------------
    O(N)
    
*************************************************************************/
#include "weighted_activity_selection.h"

#include <vector>
#include <algorithm>
#include <ctime>

/**
 * Find the index of right-most 
 * non-overlaping activity
 * that is left to the query[ index ]
 * using binary search in O( lg(index) )
 */
int left_activity_bsearch( const std::vector<Activity>& quer, std::size_t index )
{
    int lo = 0, hi = index - 1;
    while ( lo <= hi ) {
        int mid = ( lo + hi ) / 2;

        // if it is non-overlaping
        if ( quer[ mid ].end <= quer[ index ].start ) {
            // if there are other non-overlaping activity
            // a bit to the right, then continue searching
            if ( quer[ mid + 1 ].end <= quer[ index ].start ) {
                lo = mid + 1;
            }
            // if it is right-most non-overlaping
            else {
                return mid;
            }
        }
        // if there are overlaps, in the middle
        // look to the left half
        else {
            hi = mid - 1;
        }
    }

    // if quer[ index ] has no non-overlaping activites
    // to the left of it
    return -1;
}

/**
 * Algorithm of solution
 */
int weighted_activity(const std::vector<std::time_t>& start, 
                      const std::vector<std::time_t>& end, 
                      const std::vector<std::size_t>& weight) {
    std::vector<Activity> quer;
    for ( std::size_t i = 0; i < start.size(); i++ ) {
        quer.push_back( { start[ i ], end[ i ], weight[ i ] } );
    }

    // sort by end in ascending order
    std::sort( std::begin( quer ), std::end( quer ), 
        [] (const Activity& fst, const Activity& snd)
        {
            return fst.end < snd.end;
        }
    );

    // sol[ i ] stores solution to first i + 1 activities
    std::vector<std::size_t> sol ( quer.size() );
    // first solution is just it's single weight
    sol[0] = quer[0].weight;

    // find all solutions
    for ( std::size_t i = 1; i < quer.size(); i++ ) {
        std::size_t weight_with_current = quer[i].weight;

        // j - index of the problem needed to solve if
        // we want to include our i index in solution
        int j = left_activity_bsearch( quer, i );

        // if there are consistent j on the left, 
        // add max_weight of it's solution
        if ( j != -1 ) {
            weight_with_current += sol[j];
        }

        // decide whether to include this i index into solution
        // depending on it's weights
        sol[ i ] = std::max( 
            sol[ i - 1 ],    // weight without current
            weight_with_current 
        );
    }

    // last index contains solution to whole problem
    return sol.back();  
}
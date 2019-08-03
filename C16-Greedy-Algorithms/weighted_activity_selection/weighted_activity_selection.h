/*************************************************************************
    > File Name: weighted_activity_selection.h
    > Author: Nikolaus Fedurko (@B1Z0N)
    > Mail: 
    > Created Time: Wed 3 Aug 2019 02:16:46 PM CST
 ************************************************************************/

#ifndef WEIGHTED_ACTIVITY_SELECTION_HPP
#define WEIGHTED_ACTIVITY_SELECTION_HPP

#include <ios>
#include <vector>
#include <algorithm>
#include <ctime>

/**
 * Struct for single activity data
 */
struct Activity
{
    std::time_t start;
    std::time_t end;
    std::size_t weight;
};


/**
 * Find the index of right-most 
 * non-overlaping activity
 * that is left to the query[ index ]
 * using binary search in O( lg(index) )
 */
int left_activity_bsearch( const std::vector<Activity>& quer, std::size_t index );

/**
 * Algorithm of solution
 */
int weighted_activity(const std::vector<std::time_t>& start, 
                      const std::vector<std::time_t>& end, 
                      const std::vector<std::size_t>& weight);

#endif  // WEIGHTED_ACTIVITY_SELECTION_HPP

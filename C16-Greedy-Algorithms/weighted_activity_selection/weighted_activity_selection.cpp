// solution to 16.1-5
// provided by B1Z0N

/**
 * Note about complexity. Main function is __solve().
 * C++'s std::sort is quicksort, that performs, in O( n * lg( n ) ) on the average
 * Solution function uses binary_search in O( lg( index ) ), while index is 1, 2, ... , n, 
 * so complexity is O( lg( 1 ) + lg( 2 ) + ... + lg( n ) ) = O( lg( n! ) )
 * lg( n! ) is O( n * lg( n )) because n * lg( n ) = lg( n^n ) and n^n is growing 
 * faster then n!, so let's sum up complexity including sorting and binary search inside
 * loop: O( n * lg( n ) + lg( n! ) ) = O( n * lg( n ) )
 * 
 * P. S. Pretty good result using dynamic programming, greedy approach to this problem
 * doesn't exist.
 */

#include <iostream>	// cin, cout
#include <ios>		// streamsize
#include <vector>	// vector
#include <fstream>	// ifstream
#include <limits>	// numeric_limits<streamsize>::max
#include <tuple>
#include <algorithm>


//------------------------------------------------------------------------------------------
// @Problem
// Suppose we have a set S = { a1, a2, ... , an };
// of n proposed activities that wish to use a resource, such as a lecture hall, which
// can serve only one activity at a time. Each activity ai has a start time si and a finish
// time fi , where ( 0 <= si < fi < inf ). If selected, activity ai takes place during the
// half-open time interval [ si, fi ). Activities ai and aj are compatible if the intervals
// [ si, fi ) and [ sj, fj ) do not overlap. That is, ai and aj are compatible if si >= fj
// or sj >= fi. Each activity has it's weight value W( ai ), W -function that  maps 
// activity i to some nonegative number. In the activity-selection problem, we wish 
// to select a compatible subset of intervals, so that 
// ( W( ak ) + W( aj ) + ... + W( am ) ) is maximal.
// 
// @Example
// You are given the table:
// ╔════════╦═══╦════╦═══╦═══╦═══╦════╗
// ║   i    ║ 1 ║ 2  ║ 3 ║ 4 ║ 5 ║ 6  ║
// ╠════════╬═══╬════╬═══╬═══╬═══╬════╣
// ║ start  ║ 4 ║  9 ║ 2 ║ 3 ║ 5 ║  7 ║
// ║ finish ║ 5 ║ 11 ║ 6 ║ 7 ║ 6 ║ 10 ║
// ║ weight ║ 4 ║  2 ║ 8 ║ 1 ║ 6 ║ 11 ║
// ╚════════╩═══╩════╩═══╩═══╩═══╩════╝
// 1. First of all, let's sort by end time in ascending order:
// ╔════════╦═══╦═══╦═══╦═══╦════╦════╗
// ║   i    ║ 1 ║ 2 ║ 3 ║ 4 ║ 5  ║ 6  ║
// ╠════════╬═══╬═══╬═══╬═══╬════╬════╣
// ║ start  ║ 4 ║ 2 ║ 5 ║ 3 ║  7 ║  9 ║
// ║ finish ║ 5 ║ 6 ║ 6 ║ 7 ║ 10 ║ 11 ║
// ║ weight ║ 4 ║ 8 ║ 6 ║ 1 ║ 11 ║  2 ║
// ╚════════╩═══╩═══╩═══╩═══╩════╩════╝
// 2. We should ask ouselves: "Should we include first activity?"
// Of course we should, it is +4 in weight.
// 3. Would it be better wih second activity or not?
// with second activity we should discard our selection of first 
// because they overlap. Let's do this, second activity is 8, 
// it is more than 4 in first activity.
// 4. Should we try it with 3rd? If we try it, then it overlaps
// with 2nd, we discard it, and include 1st, as it is consistent,
// finally our new weight will be 4 + 6 = 10 is bigger then 8, so
// we take 1st and 3rd.
// 5. With 4th we don't take it because 1 < 10
// 6. With 5th we take it because it doesn't overlap with 
// our previous selection(1 and 3), so we could plus it,
// finally 10 + 11 = 21
// 7. With 6th we don't take it because 10 + 2 = 12 < 21
// 8. At the end of the day, we took 1st, 3rd and 5th, 
// that is ANSWER: 21
//
// @Input format
// 6
// 4 5 4
// 9 11 2
// 2 6 8
// 3 7 1
// 5 6 6
// 7 10 11
//
// @Output
// 21
//
//--------------------------------------------------------------------------------------------


/**
 * Struct for single activity data
 */
struct Activity
{
	std::size_t start;
	std::size_t end;
	std::size_t weight;
};


/**
 * Class to solve activity selection problem
 */
class ActivityQuery
{
	std::vector<Activity> quer;
	mutable std::size_t max_weight;

	mutable bool calculated { false };

	void sort()
	{
		// sort by end in ascending order
		std::sort( std::begin( quer ), std::end( quer ), 
			[] (const Activity& fst, const Activity& snd)
			{
				return fst.end < snd.end;
			}
		);
	}
public:
	ActivityQuery( ) = default;

	ActivityQuery( std::vector<std::size_t> start, std::vector<std::size_t> end, std::vector<std::size_t> weight )
	{
		for( int i = 0; i < start.size(); i++ )
			quer.push_back( { start[i], end[i], weight[i] } );

		sort();
	}

	ActivityQuery( const std::vector<Activity>& actvt )
	: quer{ actvt } { sort(); }

	std::vector<Activity> get_activities() const
	{
		return quer;
	}

	/**
	 * Returns max_weight
	 * Calculated only first time, then just returns the result
	 */
	std::size_t solve( ) const
	{
		if( !calculated )
		{
			__solve();
			calculated = true;
		}

		return max_weight;
	}

private:
	void __solve() const;
};

std::ostream& operator<<( std::ostream& os, const ActivityQuery& aq );
std::istream& operator>>( std::istream& is, ActivityQuery& aq );


int main( int argc, char* argv[] )
{
	ActivityQuery actq { };
	std::cin >> actq;
	std::cout << actq << '\n';

	return 0;
}


/**
 * Algorithm of solution
 */
void ActivityQuery::__solve() const
{
	/**
	 * Lambda to find the index of right-most 
	 * non-overlaping activity
	 * that is left to the query[ index ]
	 * using binary search in O( lg(index) )
	 */
	static auto left_activity_bsearch {
		[this] ( std::size_t index ) -> int
		{
			std::size_t lo = 0, hi = index - 1;
			while( lo <= hi )
			{
				std::size_t mid = ( lo + hi ) / 2;

				if( quer[ mid ].end <= quer[ index ].start )
				// if it is non-overlaping
				{
					if( quer[ mid + 1 ].end <= quer[ index ].start )
					// if there are other non-overlaping activity
					// a bit to the right, then continue searching
						lo = mid + 1;
					else
					// if it is right-most non-overlaping
						return mid;
				}
				else
				// if there are overlaps, in the middle
				// look to the left half
					hi = mid - 1;
			}

			return -1;
			// if quer[ index ] has no non-overlaping activites
			// to the left of it
		}
	};

	std::vector<std::size_t> sol ( quer.size() );
	// sol[ i ] stores solution to first i + 1 activities

	sol[0] = quer[0].weight;
	// first solution is just it's single weight
	for( std::size_t i = 1; i < quer.size(); i++ )
	// find all solutions
	{
		std::size_t weight_with_current = quer[i].weight;
		int j = left_activity_bsearch( i );
		// j - index of the problem needed to solve if
		// we want to include our i index in solution

		if( j != -1 ) weight_with_current += sol[j];
		// if there are consistent j on the left, 
		// add max_weight of it's solution

		sol[ i ] = std::max( 
		// decide whether to include this i index into solution
		// depending on it's weights
			sol[ i - 1 ], 	 // weight without current
			weight_with_current 
		);
	}

	max_weight = sol.back();	
	// last index contains solution to whole problem
}

std::istream& operator>>( std::istream& is, ActivityQuery& aq )
{
	std::vector<Activity> actvts;
	Activity temp;

	std::size_t n;
	is >> n;

	while( n-- )
	{
		is >> temp.start >> temp.end >> temp.weight;
		actvts.push_back( temp );
	}

	aq = ActivityQuery { actvts };

	return is;
}

std::ostream& operator<<( std::ostream& os, const ActivityQuery& aq)
{
	return os << aq.solve();
}


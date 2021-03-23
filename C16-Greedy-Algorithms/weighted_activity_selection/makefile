test : test_weighted_activity_selection
		./test_weighted_activity_selection
test_weighted_activity_selection : test_weighted_activity_selection.o weighted_activity_selection.o
		g++ -o test_weighted_activity_selection test_weighted_activity_selection.o weighted_activity_selection.o
test_weighted_activity_selection.o : test_weighted_activity_selection.cpp
		g++ -c test_weighted_activity_selection.cpp
weighted_activity_selection.o : weighted_activity_selection.cpp
		g++ -c weighted_activity_selection.cpp

clean :
		rm test_weighted_activity_selection test_weighted_activity_selection.o weighted_activity_selection.o

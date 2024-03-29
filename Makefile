all: IntegerDivison KnightsTour NisSumofSquares NPointsFindRectangles NPointsFindSquares NQueens PermutationSequence ValidNumber

IntegerDivison:
	g++ -std=c++11 -o bin/integerdivision integerdivision.cpp

KnightsTour:
	g++ -std=c++11 -o bin/knightstour KnightsTour.cpp

NisSumofSquares:
	g++ -std=c++11 -o bin/nissumofsquares NisSumofSquares.cpp

NPointsFindRectangles:
	g++ -std=c++11 -o bin/npointsfindrectangles NPointsFindRectangles.cpp

NPointsFindSquares:
	g++ -std=c++11 -o bin/npointsfindsquares NPointsFindSquares.cpp

NQueens:
	g++ -std=c++11 -o bin/nqueens NQueens.cpp

PermutationSequence:
	g++ -std=c++11 -o bin/permutationsequence PermutationSequence.cpp

ValidNumber:
	g++ -std=c++11 -o bin/validnumber ValidNumber.cpp

clean:
	rm bin/*

all: part-1 part-2
	echo "part 1"
	./part-1
	echo "\npart 2"
	./part-2


part-1: part-1.cpp
	clang++ -l pthread --std=c++1z part-1.cpp -o part-1

part-2: part-2.cpp
	clang++ -l pthread --std=c++1z part-2.cpp -o part-2
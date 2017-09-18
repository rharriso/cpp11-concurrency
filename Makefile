
run-all: part-1
	echo
	./part-1
	echo


part-1:
	g++ -l pthread --std=c++17 part-1.cpp -o part-1

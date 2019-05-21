run:
	g++ -o test functions.cpp main.cpp header.h student.h vector.h
vector:
	g++ -o test vector_compare.cpp header.h vector.h
clean:
	rm -f *.txt test
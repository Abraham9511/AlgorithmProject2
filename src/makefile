main: main.o algorithm1.o Image.o
	g++ -g -Wall -std=c++11 main.cpp -o main
Image.o: Image.h
algorithm1.o: algorithm1.h algorithm2.h algorithm3.h algorithm4.h Image.h
algorithm2.o: algorithm2.h Image.h
algorithm3.o: algorithm3.h
algorithm4.o: algorithm4.h

.PHONY: clean
clean:
	rm *.o

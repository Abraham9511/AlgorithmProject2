cp: cp.o algorithm1.o Image.o, algorithm2.o algorithm4.o 
	g++ -g -Wall -std=c++11 cp.cpp algorithm1.o algorithm2.o algorithm4.o Image.o -o cp
Image.o: Image.h
	g++ -g -Wall -std=c++11 Image.cpp -o Image.o
algorithm1.o: algorithm1.h algorithm2.h algorithm4.h Image.h
	g++ -g -Wall -std=c++11 algorithm1.cpp algorithm2.o algorithm4.o Image.o -o algorithm1.o
algorithm2.o: algorithm2.h Image.h
	g++ -g -Wall -std=c++11 algorithm2.cpp Image.o -o algorithm2.o
#algorithm3.o: algorithm3.h
algorithm4.o: algorithm4.h
	g++ -g -Wall -std=c++11 algorithm4.cpp Image.o -o algorithm4.o

.PHONY: clean
clean:
	rm *.o

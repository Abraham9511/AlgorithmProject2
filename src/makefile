cp:
	g++ -g -Wall -std=c++11 cp.cpp algorithm1.cpp algorithm2.cpp algorithm3.cpp algorithm4.cpp Image.cpp -o cp

.PHONY: run
run:
	./cp -n 60000 -d 784 -f train-images.idx3-ubyte
.PHONY: clean
clean:
	rm cp

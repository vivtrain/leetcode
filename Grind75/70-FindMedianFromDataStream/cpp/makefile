UTIL_DIR = ../../Utility/cpp
INCLUDE_DIR = $(UTIL_DIR)/include
IMPL_DIR = $(INCLUDE_DIR)/impl
OBJ_DIR = $(IMPL_DIR)/obj
CPP = g++ -std=c++17 -g

run: test.cpp FindMedianFromDataStream.o
	$(CPP) $^ -o run -I$(INCLUDE_DIR)

FindMedianFromDataStream.o: FindMedianFromDataStream.cpp FindMedianFromDataStream.h
	$(CPP) -o $@ -c $< -I$(INCLUDE_DIR)

clean:
	rm -rf run *.o *.gch


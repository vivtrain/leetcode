UTIL_DIR = ../../Utility/cpp
INCLUDE_DIR = $(UTIL_DIR)/include
IMPL_DIR = $(UTIL_DIR)/include/impl
UTIL_OBJ_DIR = $(UTIL_DIR)/obj
CPP = g++ -std=c++11 -g

run: test.cpp TwoSumII.o
	$(CPP) $^ -o run -I$(INCLUDE_DIR)

TwoSumII.o: TwoSumII.cpp TwoSumII.h
	$(CPP) -o $@ -c $< -I$(INCLUDE_DIR)

clean:
	rm -rf run *.o *.gch


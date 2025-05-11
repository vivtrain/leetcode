UTIL_DIR = ../../Utility/cpp
INCLUDE_DIR = $(UTIL_DIR)/include
IMPL_DIR = $(UTIL_DIR)/include/impl
UTIL_OBJ_DIR = $(UTIL_DIR)/obj
CPP = g++ -std=c++11 -g

run: test.cpp ThreeSum.o
	$(CPP) $^ -o run -I$(INCLUDE_DIR)

ThreeSum.o: ThreeSum.cpp ThreeSum.h $(INCLUDE_DIR)/minMax.h
	$(CPP) -o $@ -c $< -I$(INCLUDE_DIR)

clean:
	rm -rf run *.o *.gch


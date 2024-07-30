UTIL_DIR = ../../Utility/cpp
INCLUDE_DIR = $(UTIL_DIR)/include
IMPL_DIR = $(UTIL_DIR)/include/impl
UTIL_OBJ_DIR = $(UTIL_DIR)/obj
CPP = g++ -std=c++11

run: test.cpp MergeTwoSortedLists.o $(UTIL_OBJ_DIR)/List.o
	$(CPP) $^ -o run -I$(INCLUDE_DIR)

$(UTIL_OBJ_DIR)/List.o: $(IMPL_DIR)/List.cpp
	$(CPP) -o $@ -c $^ -I$(INCLUDE_DIR)

MergeTwoSortedLists.o: MergeTwoSortedLists.h MergeTwoSortedLists.cpp 
	$(CPP) -c $^ -I$(INCLUDE_DIR)

clean:
	rm -rf run *.o *.gch


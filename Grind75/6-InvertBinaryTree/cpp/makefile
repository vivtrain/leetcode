UTIL_DIR = ../../Utility/cpp
INCLUDE_DIR = $(UTIL_DIR)/include
IMPL_DIR = $(UTIL_DIR)/include/impl
UTIL_OBJ_DIR = $(UTIL_DIR)/obj
CPP = g++ -std=c++11

run: test.cpp InvertBinaryTree.o $(UTIL_OBJ_DIR)/Tree.o
	$(CPP) $^ -o run -I$(INCLUDE_DIR)

$(UTIL_OBJ_DIR)/Tree.o: $(IMPL_DIR)/Tree.cpp
	$(CPP) -o $@ -c $^ -I$(INCLUDE_DIR)

InvertBinaryTree.o: InvertBinaryTree.h InvertBinaryTree.cpp 
	$(CPP) -c $^ -I$(INCLUDE_DIR)

clean:
	rm -rf run *.o *.gch


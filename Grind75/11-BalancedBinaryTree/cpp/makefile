UTIL_DIR = ../../Utility/cpp
INCLUDE_DIR = $(UTIL_DIR)/include
IMPL_DIR = $(UTIL_DIR)/include/impl
UTIL_OBJ_DIR = $(UTIL_DIR)/obj
CPP = g++ -std=c++11

run: BalancedBinaryTree.o $(UTIL_OBJ_DIR)/Tree.o test.cpp
	$(CPP) $^ -o run -I$(INCLUDE_DIR)

$(UTIL_OBJ_DIR)/Tree.o: $(IMPL_DIR)/Tree.cpp $(INCLUDE_DIR)/Tree.h 
	$(CPP) -o $@ -c $< -I$(INCLUDE_DIR)

BalancedBinaryTree.o: BalancedBinaryTree.h BalancedBinaryTree.cpp
	$(CPP) -c $^ -I$(INCLUDE_DIR)

clean:
	rm -rf run *.o *.gch


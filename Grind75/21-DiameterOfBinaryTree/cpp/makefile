UTIL_DIR = ../../Utility/cpp
INCLUDE_DIR = $(UTIL_DIR)/include
IMPL_DIR = $(UTIL_DIR)/include/impl
UTIL_OBJ_DIR = $(UTIL_DIR)/obj
CPP = g++ -std=c++11 -g

run: test.o DiameterOfBinaryTree.o $(UTIL_OBJ_DIR)/Tree.o
	$(CPP) $^ -o run -I$(INCLUDE_DIR)

test.o: test.cpp $(INCLUDE_DIR)/Time.h
	$(CPP) -o $@ -c $< -I$(INCLUDE_DIR)

$(UTIL_OBJ_DIR)/Tree.o: $(IMPL_DIR)/Tree.cpp $(INCLUDE_DIR)/Tree.h
	$(CPP) -o $@ -c $< -I$(INCLUDE_DIR)

DiameterOfBinaryTree.o: DiameterOfBinaryTree.cpp DiameterOfBinaryTree.h
	$(CPP) -o $@ -c $< -I$(INCLUDE_DIR)

clean:
	rm -rf run *.o *.gch


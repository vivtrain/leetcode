UTIL_DIR = ../../Utility/cpp
INCLUDE_DIR = $(UTIL_DIR)/include
IMPL_DIR = $(UTIL_DIR)/include/impl
UTIL_OBJ_DIR = $(UTIL_DIR)/obj
CPP = g++ -std=c++11 -g

run: test.cpp LevelOrderTraversal.o Tree.o
	$(CPP) $^ -o run -I$(INCLUDE_DIR)

Tree.o: $(IMPL_DIR)/Tree.cpp $(INCLUDE_DIR)/Tree.h
	$(CPP) -o $@ -c $< -I$(INCLUDE_DIR)

LevelOrderTraversal.o: LevelOrderTraversal.cpp LevelOrderTraversal.h
	$(CPP) -o $@ -c $< -I$(INCLUDE_DIR)

clean:
	rm -rf run *.o *.gch


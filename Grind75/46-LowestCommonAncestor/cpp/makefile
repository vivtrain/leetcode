UTIL_DIR = ../../Utility/cpp
INCLUDE_DIR = $(UTIL_DIR)/include
IMPL_DIR = $(INCLUDE_DIR)/impl
OBJ_DIR = $(IMPL_DIR)/obj
CPP = g++ -std=c++17 -g

run: test.cpp LowestCommonAncestor.o $(OBJ_DIR)/Tree.o
	$(CPP) $^ -o run -I$(INCLUDE_DIR)

LowestCommonAncestor.o: LowestCommonAncestor.cpp LowestCommonAncestor.h
	$(CPP) -o $@ -c $< -I$(INCLUDE_DIR)

$(OBJ_DIR)/Tree.o: $(IMPL_DIR)/Tree.cpp $(INCLUDE_DIR)/Tree.h
	$(CPP) -o $@ -c $< -I$(INCLUDE_DIR)

clean:
	rm -rf run *.o *.gch


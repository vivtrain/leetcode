UTIL_DIR = ../../Utility/cpp
INCLUDE_DIR = $(UTIL_DIR)/include
IMPL_DIR = $(UTIL_DIR)/include/impl
UTIL_OBJ_DIR = $(IMPL_DIR)/obj
CPP = g++ -std=c++17 -g

run: test.cpp ValidateBST.o $(UTIL_OBJ_DIR)/Tree.o
	$(CPP) $^ -o run -I$(INCLUDE_DIR)

ValidateBST.o: ValidateBST.cpp ValidateBST.h
	$(CPP) -o $@ -c $< -I$(INCLUDE_DIR)

$(UTIL_OBJ_DIR)/Tree.o: $(IMPL_DIR)/Tree.cpp $(INCLUDE_DIR)/Tree.h
	$(CPP) -o $@ -c $< -I$(INCLUDE_DIR)

clean:
	rm -rf run *.o *.gch


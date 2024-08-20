UTIL_DIR = ../../Utility/cpp
INCLUDE_DIR = $(UTIL_DIR)/include
IMPL_DIR = $(UTIL_DIR)/include/impl
UTIL_OBJ_DIR = $(UTIL_DIR)/obj
CPP = g++ -std=c++11 -g

run: test.cpp MiddleOfLinkedList.o $(UTIL_OBJ_DIR)/List.o
	$(CPP) $^ -o run -I$(INCLUDE_DIR)

MiddleOfLinkedList.o: MiddleOfLinkedList.cpp MiddleOfLinkedList.h
	$(CPP) -o $@ -c $< -I$(INCLUDE_DIR)

$(UTIL_OBJ_DIR)/List.o: $(IMPL_DIR)/List.cpp $(INCLUDE_DIR)/List.h
	$(CPP) -o $@ -c $< -I$(INCLUDE_DIR)

clean:
	rm -rf run *.o *.gch


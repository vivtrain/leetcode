UTIL_DIR = ../../Utility/cpp
CPP = g++

run: test.cpp InvertBinaryTree.o Tree.o
	$(CPP) $^ -o run

Tree.o: $(UTIL_DIR)/Tree.h $(UTIL_DIR)/Tree.cpp
	$(CPP) -c $^

InvertBinaryTree.o: InvertBinaryTree.h InvertBinaryTree.cpp 
	$(CPP) -c $^

clean:
	rm -rf run *.o *.gch


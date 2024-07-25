UTIL_DIR = ../../Utility/
CPP = g++

run: test.cpp LowestCommonAncestor.o Tree.o
	$(CPP) $^ -o run

Tree.o: $(UTIL_DIR)/Tree.h $(UTIL_DIR)/Tree.cpp
	$(CPP) -c $^

LowestCommonAncestor.o: LowestCommonAncestor.h LowestCommonAncestor.cpp 
	$(CPP) -c $^

clean:
	rm -rf run *.o *.gch


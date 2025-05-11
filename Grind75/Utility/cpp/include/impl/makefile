INCLUDE_DIR = ..
IMPL_DIR = .
CPP = g++ -std=c++11 -g

run: test.cpp obj/Tree.o obj/List.o
	$(CPP) $^ -o run -I$(INCLUDE_DIR)

obj/Tree.o: Tree.cpp $(INCLUDE_DIR)/Tree.h
	$(CPP) -o $@ -c $< -I$(INCLUDE_DIR)

obj/List.o: List.cpp $(INCLUDE_DIR)/List.h
	$(CPP) -o $@ -c $< -I$(INCLUDE_DIR)

clean:
	rm -rf run *.o *.gch


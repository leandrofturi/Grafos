OUT := g

run:
	g++ -c *.cpp
	g++ -o $(OUT) *.o
	rm *.o

teste:
	./$(OUT)

val:
	valgrind ./$(OUT)
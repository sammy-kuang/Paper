all: clean
	g++ *.cpp -o game.o -O1  -I include/ -L lib/ -lfreeimage -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -lstdc++
clean:
	rm -f game.o
run: all
	./game.o
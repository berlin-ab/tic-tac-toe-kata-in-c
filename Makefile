build:
	mkdir -p build/tic-tac-toe-game
	cp src/tic_tac_toe_game.h build/tic-tac-toe-game/tic_tac_toe_game.h
	gcc src/tic_tac_toe_game.c \
		-shared \
		-I build \
		-o build/tic-tac-toe-game/tic_tac_toe_game.so

clean:
	rm -rf build
	rm -rf build-test

build_test: clean build
	mkdir build-test;
	gcc test/tic_tac_toe_test.c build/tic-tac-toe-game/tic_tac_toe_game.so \
		-l cgreen \
		-I build/ \
		-o build-test/tic_tac_toe_test.o

test: build_test
	./build-test/tic_tac_toe_test.o
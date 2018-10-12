BUILD_DIR=build/
SOURCE_DIR=src/
TEST_SOURCE_DIR=test/
TEST_BUILD_DIR=build/

LIBRARY_COMPILER_OPTIONS=-shared \
		-Wall \
		-L $(BUILD_DIR) \
		-I $(BUILD_DIR) \

TEST_COMPILER_OPTIONS=-L $(BUILD_DIR) \
		-Wall \
		-I $(BUILD_DIR) \
		-l cgreen \
       
build:
	mkdir -p $(BUILD_DIR)/tic-tac-toe-game
	mkdir -p $(BUILD_DIR)/grid
	
	cp $(SOURCE_DIR)/game/tic_tac_toe_game.h $(BUILD_DIR)/tic-tac-toe-game/tic_tac_toe_game.h
	cp $(SOURCE_DIR)/game/grid.h $(BUILD_DIR)/tic-tac-toe-game/grid.h
	
	gcc $(SOURCE_DIR)/array-backed-grid/array_backed_grid.c $(LIBRARY_COMPILER_OPTIONS) -o $(BUILD_DIR)/libgrid.so
	gcc $(SOURCE_DIR)/game-core/tic_tac_toe_game.c $(LIBRARY_COMPILER_OPTIONS) -l grid -o $(BUILD_DIR)/tic-tac-toe-game/libtic_tac_toe_game.so

clean:
	rm -rf $(BUILD_DIR)
	rm -rf $(TEST_BUILD_DIR)

setup_test: clean build
	mkdir -p $(TEST_BUILD_DIR)	

build_test_game: setup_test 
	gcc test/tic_tac_toe_test.c $(BUILD_DIR)/tic-tac-toe-game/libtic_tac_toe_game.so \
		$(TEST_COMPILER_OPTIONS) \
		-o build-test/tic_tac_toe_test.o
		
build_test_grid: clean setup_test 
	gcc test/grid_test.c \
		-l grid \
		$(TEST_COMPILER_OPTIONS) \
		-o build-test/grid_test.o

test_grid: build_test_grid
	./build-test/grid_test.o

test_game: clean setup_test build_test_game
	./build-test/tic_tac_toe_test.o

test: clean setup_test test_game test_grid

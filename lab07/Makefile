COMPILE = g++
FLAGS = -std=c++11 -std=gnu++11 -g -W -Wall -Werror -pedantic -O3
MAIN = main.cpp
TEXT = words.txt
FILE = lab7.out
TEST_FILE = word_test.txt
OUTPUT_FILE = data.txt
PG_FILE = plot.pg
PLOT_FILE = lab7_plot.png

all: $(MAIN) $(TEXT)
	$(COMPILE) $(FLAGS) $(MAIN) -o $(FILE)
	
test: all
	./$(FILE)
	
plot: $(OUTPUT_FILE) $(PG_FILE)
	 ./$(PG_FILE) > $(PLOT_FILE)
	
clean:
	rm -f $(FILE) $(TEST_FILE) $(OUTPUT_FILE) $(PLOT_FILE)
	
final: clean test plot
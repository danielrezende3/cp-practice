CXX = clang++
CXXFLAGS = -std=c++20 -O2 -Wall -Wextra -Wshadow -DLOCAL
BIN = .build

.PHONY: a b c d e f clean

a b c d e f: %: $(BIN)/%
	./$(BIN)/$@ < $@.in > $@.out

a%: $(BIN)/a
	./$(BIN)/a < $@.in > $@.out

b%: $(BIN)/b
	./$(BIN)/b < $@.in > $@.out

c%: $(BIN)/c
	./$(BIN)/c < $@.in > $@.out

d%: $(BIN)/d
	./$(BIN)/d < $@.in > $@.out

e%: $(BIN)/e
	./$(BIN)/e < $@.in > $@.out

f%: $(BIN)/f
	./$(BIN)/f < $@.in > $@.out

$(BIN)/%: %.cpp
	mkdir -p $(BIN)
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	rm -rf $(BIN) *.out

CXX = clang++-22
CXXFLAGS = -std=c++20 -g -Wall -Wextra -Wshadow -DLOCAL
BIN = .build
INPUT_EXT = input
PROBLEMS = a b c d e f g h
ROOT_DIR = $(patsubst %/,%,$(dir $(abspath $(lastword $(MAKEFILE_LIST)))))
PCH_SCRIPT = $(ROOT_DIR)/scripts/setup_pch.sh
PCH_FLAGS = -I. -include-pch bits/stdc++.h.pch

.PHONY: $(PROBLEMS) pch clean

$(PROBLEMS): %: $(BIN)/%
	./$(BIN)/$@ < $@.$(INPUT_EXT) > $@.out

build-%: $(BIN)/%
	@:

pch:
	CXX="$(CXX)" CXXFLAGS="$(CXXFLAGS) -I." "$(PCH_SCRIPT)" "$(CURDIR)"

$(BIN)/%: %.cpp pch
	mkdir -p $(BIN)
	$(CXX) $(CXXFLAGS) $(PCH_FLAGS) $< -o $@

clean:
	rm -rf $(BIN) bits *.out

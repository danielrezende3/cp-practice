CXX = clang++-22
ROOT_DIR = $(patsubst %/,%,$(dir $(abspath $(lastword $(MAKEFILE_LIST)))))
COMPILE_FLAGS_FILE = $(ROOT_DIR)/compile_flags.txt
CXXFLAGS = $(shell cat "$(COMPILE_FLAGS_FILE)")
BIN = .build
INPUT_EXT = input
PROBLEMS = a b c d e f g h
PCH_SCRIPT = $(ROOT_DIR)/scripts/setup_pch.sh
PCH_FLAGS = -include-pch bits/stdc++.h.pch

.PHONY: $(PROBLEMS) pch clean

$(PROBLEMS): %: $(BIN)/%
	./$(BIN)/$@ < $@.$(INPUT_EXT) > $@.out

build-%: $(BIN)/%
	@:

pch:
	CXX="$(CXX)" CXXFLAGS="$(CXXFLAGS)" "$(PCH_SCRIPT)" "$(CURDIR)"

$(BIN)/%: %.cpp pch
	mkdir -p $(BIN)
	$(CXX) $(CXXFLAGS) $(PCH_FLAGS) $< -o $@

clean:
	rm -rf $(BIN) bits *.out

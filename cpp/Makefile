
CXX       = g++
CXXFLAGS  = -std=c++14 -O2 -Wall
LIBS      = -lgtest -lgtest_main
BUILD_DIR = build

ALL_TESTS := $(shell find test/ | grep \.cc$$)

test: algo_test
	./$(BUILD_DIR)/algo_test

algo_test: build_dir $(ALL_TESTS)
	$(CXX) $(CXXFLAGS) $(ALL_TESTS) $(LIBS) -o $(BUILD_DIR)/$@

build_dir: clean
	mkdir -p $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR)

.PHONY: test clean build_dir


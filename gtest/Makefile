gcc_options = -std=c++17 -Wall

hello_test: hello_test.cpp
	g++ $(gcc_options) -I ../third_party/googletest/googletest/include -I ../third_party/googletest/googlemock/include -L ../lib -lgtest_main -lgtest -lpthread $< -o $@

all.h.gch: all.h
	g++ $(gcc_options) -x c++-header -o $@ $<

test: hello_test
	./hello_test --gtest_output=xml:hello_test_result.xml

clean:
	rm -f ./hello_test
	rm -f ./hello_test_result.xml

.PHONY: test clean

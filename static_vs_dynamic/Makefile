shared_libfoo:
	g++ -Wall -Werror -c -fpic -o foo1.o foo1.cpp
	g++ -shared -o shared_foo/libfoo.so foo1.o

static_libfoo:
	g++ -Wall -Werror -c -o foo2.o foo2.cpp
	ar -crs lib/libfoo.a foo2.o

shared_libbar: shared_libfoo
	g++ -Wall -Werror -c -fpic -o bar.o bar.cpp
	g++ -shared -o shared_bar/libbar.so bar.o -L $(PWD)/shared_foo -l:libfoo.so

clean:
	rm -f *.o
	rm -f shared_foo/libfoo.so
	rm -f lib/libfoo.a
	rm -f shared_bar/libbar.so
	rm -f static_first
	rm -f static_last

exe_static_first: shared_libfoo shared_libbar static_libfoo
	g++ -Wall -Werror -o static_first main.cpp -L $(PWD)/lib -L $(PWD)/shared_bar -L $(PWD)/shared_foo -l:libbar.so -l:libfoo.a -l:libfoo.so
	LD_LIBRARY_PATH="$(PWD)/shared_bar:$(PWD)/shared_foo" ./static_first

exe_static_last: shared_libfoo shared_libbar static_libfoo
	g++ -Wall -Werror -o static_last main.cpp -L $(PWD)/lib -L $(PWD)/shared_bar -L $(PWD)/shared_foo -l:libbar.so -l:libfoo.so -l:libfoo.a
	LD_LIBRARY_PATH="$(PWD)/shared_bar:$(PWD)/shared_foo" ./static_last

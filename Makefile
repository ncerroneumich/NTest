CXX = g++
CXXFLAGS = -g -Ilibsrc -std=c++11
dyvar = LD_LIBRARY_PATH=./ # For dynamic compilation on linux
exe = main.cpp

.PHONY: all
all: app-dynamic app-static

libobj/static/NTest.o: libsrc/NTest.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

libobj/dynamic/NTest.o: libsrc/NTest.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c -fPIC -o $@ $<

lib/libntest.so: libobj/dynamic/NTest.o
	mkdir -p $(dir $@)
	$(CXX) -shared -o $@ $<

lib/libntest.a: libobj/static/NTest.o
	mkdir -p $(dir $@)
	ar rcs $@ $<

app-dynamic: $(exe) lib/libntest.so
	$(CXX) $(CXXFLAGS) -o $@ $< -Llib -l:libntest.so

app-static: $(exe) lib/libntest.a
	$(CXX) $(CXXFLAGS) -o $@ $< -Llib -l:libntest.a

.PHONY: run-static
run-static: app-static
	./app-static

.PHONY: run-dynamic
run-dynamic: app-dynamic
	$(dyvar) ./app-dynamic

.PHONY: clean
clean:
	rm -rf libobj lib
	rm -f app-dynamic
	rm -f app-static

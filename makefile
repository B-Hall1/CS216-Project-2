OBJECTS = Project2.o term.o SortingList.o Autocomplete.o magicString.o
HEADERS = term.h SortingList.h Autocomplete.h magicString.h

CS216PA2: $(OBJECTS)
	g++ $^ -o $@

%.o: %.cpp
	g++ -c $< -o $@

%.o: %.cpp $(HEADERS)
	g++ -c $< -o $a

clean:
	rm -i *.o CS216PA2

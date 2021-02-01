libpath= /usr/lib#change this variable to your system's library path
includepath=/usr/include#change this variable to your system's include path

lib/libEZLib.so: lib/EZLib.o
	g++ -shared -o lib/libEZLib.so lib/EZLib.o

lib/EZLib.o: lib/EZLib.cpp lib/preprocessor.hpp lib/EZLib
	g++ -fPIC -O -g -c -o lib/EZLib.o lib/EZLib.cpp

installer/EZModpacker: installer/EZModpacker.cpp installer/preprocessor.hpp
	g++ -o installer/EZModpacker installer/EZModpacker.cpp -lEZLib -lcurl

installinst: installer/EZModpacker
	mv installer/EZModpacker /usr/bin

installlib:
	mv lib/libEZLib.so ${libpath}/
	cp lib/EZLib ${includepath}/

uninstall:
	rm ${libpath}/libEZLib.so ${includepath}/EZModpacker/EZLib

clean:
	rm lib/EZLib.o
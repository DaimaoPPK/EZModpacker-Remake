libpath=/usr/lib#change this variable to your system's library path
includepath=/usr/include#change this variable to your system's include path
binpath=/usr/bin#change this variable to your system's binary path

lib/libEZLib.so: lib/EZLib.o
	g++ -shared -o lib/libEZLib.so lib/EZLib.o

lib/EZLib.o: lib/EZLib.cpp lib/preprocessor.hpp lib/EZLib
	g++ -fPIC -O -g -c -o lib/EZLib.o lib/EZLib.cpp

installer/EZInstaller: installer/EZInstaller.cpp installer/preprocessor.hpp

installinst: installer/EZInstaller
	mv installer/EZInstaller ${binpath}/

installlib:
	mv lib/libEZLib.so ${libpath}/
	cp lib/EZLib ${includepath}/

uninstall:
	rm ${libpath}/libEZLib.so ${includepath}/EZModpacker/EZLib ${binpath}/EZInstaller

clean:
	rm lib/EZLib.o

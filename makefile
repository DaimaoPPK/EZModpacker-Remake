bin/EZModpacker: EZModpacker.cpp headers/Def.h headers/EZModpacker.h
	mkdir bin
	g++ -o bin/EZModpacker EZModpacker.cpp -lcurl

install: bin/EZModpacker	
	mv bin/EZModpacker /usr/bin/

uninstall:
	rm /usr/bin/EZModpacker

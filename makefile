bin/EZModpacker: EZModpacker.cpp headers/Def.h headers/EZModpacker.h
	g++ -o bin/EZModpacker EZModpacker.cpp -lcurl

install: bin/EZModpacker
	mkdir bin
	mv bin/EZModpacker /usr/bin/

uninstall:
	rm /usr/bin/EZModpacker

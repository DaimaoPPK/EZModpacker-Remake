bin/EZModpacker: EZModpacker.cpp headers/Def.h headers/EZModpacker.h
	g++ -o bin/EZModpacker EZModpacker.cpp -lcurl

linuxinstall: bin/EZModpacker
	mv bin/EZModpacker /usr/bin/

linuxuninstall:
	rm /usr/bin/EZModpacker

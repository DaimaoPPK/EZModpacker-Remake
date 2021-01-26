EZModpacker: EZModpacker.cpp headers/Def.h headers/EZModpacker.h
	g++ -o EZModpacker EZModpacker.cpp -lcurl

install: EZModpacker	
	mv EZModpacker /usr/bin/

uninstall:
	rm /usr/bin/EZModpacker

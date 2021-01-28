EZModpacker: EZModpacker.cpp headers/Def.hpp headers/EZModpacker.hpp
	g++ -o EZModpacker EZModpacker.cpp -lcurl

install: EZModpacker	
	mv EZModpacker /usr/bin/

uninstall:
	rm /usr/bin/EZModpacker

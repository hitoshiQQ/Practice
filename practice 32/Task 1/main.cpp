#include <iostream>
#include <fstream>
#include "nlohmann/json.hpp"

int main() {
	nlohmann::json movie = {
		{"Name", "Lock, Stock and Two Smoking Barrels"},
		{"Countries", "United Kingdom, United States"},
		{"Year", 1998},
		{"Directed by", "Guy Ritchie"},
		{"Written by" , "Guy Ritchie"},
		{"Produced by", "Matthew Vaughn"},
		{"Narrated by", "Alan Ford"},
		{"Cinematography" , "Tim Maurice-Jones"},
		{"Edited by"  , "Niven Howie"},
		{"Music by"   , "David A.Hughes, John Murphy"},
		{"Starring"   ,
		          {
					  {"1",{"Jason Flemyng"   , "Tom"}},
					  {"2",{"Nick Moran"      , "Eddie"}},
					  {"3",{"Dexter Fletcher" , "Soap"}},
					  {"4",{"Jason Statham"   , "Bacon"}},
					  {"5",{"Steven Mackintosh" , "Winston"}},
					  {"6",{"Vinnie Jones"    , "Big Chris"}},
					  {"7",{"Stephen Marcus"  , "Nick \"the Greek\""}},
					  {"8",{"Sting (Gordon Matthew Thomas Sumner)" , "JD"}},
                  }
	    },
		{"Distributed by" , "PolyGram Filmed Entertainment (United Kingdom) , Gramercy Pictures(United States)"}
	};
	movie.push_back({ "Budget" , "800 000 - Pound's" });
	movie.push_back({ "Box office", "28 100 000 - Dollar's" });

	std::ofstream file("movie.json");
	if (file.is_open()) {
		file << movie.dump(4) << std::endl;
		file.flush();
		file.close();
		std::cout << "\n!Successfully!";
	}else {
		std::cerr << "\nERROR writing file!";
	}
	
	return 0;
}
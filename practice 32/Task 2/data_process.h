#pragma once
#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>


nlohmann::json DataRead() {
	std::ifstream file("base_movies.json");
	nlohmann::json data = nullptr;
	if (file.is_open()) {
		data = nlohmann::json::parse(file);
		file.close();
	}else {
		std::cout << "\nData file not founded!";
	}
	return data;
}

void SaveFilmsBase() {
	nlohmann::json base_movies{
		{
			{"Name", "Lock, Stock and Two Smoking Barrels"},
			{ "Countries", "United Kingdom, United States" },
			{ "Year", 1998 },
			{ "Directed by", "Guy Ritchie" },
			{ "Written by" , "Guy Ritchie" },
			{ "Produced by", "Matthew Vaughn" },
			{ "Cinematography" , "Tim Maurice-Jones" },
			{ "Edited by"  , "Niven Howie" },
			{ "Music by"   , "David A.Hughes, John Murphy" },
			{ "Distributed by" , "PolyGram Filmed Entertainment (United Kingdom) , Gramercy Pictures(United States)" },
			{ "Starring",
				  {
					  {"1",{"Jason Flemyng"   ,"Tom"}},
					  {"2",{"Nick Moran"      , "Eddie"}},
					  {"3",{"Dexter Fletcher" , "Soap"}},
					  {"4",{"Jason Statham"   , "Bacon"}},
					  {"5",{"Steven Mackintosh" , "Winston"}},
					  {"6",{"Vinnie Jones"    , "Big Chris"}},
					  {"7",{"Stephen Marcus"  , "Nick the Greek"}},
					  {"8",{"Sting (Gordon Matthew Thomas Sumner)" , "JD"}}
				  }
			}
		},
		{
			 {"Name", "Green Book"},
			 {"Countries", "United States"},
			 {"Year", 2018},
			 {"Directed by", "Peter Farrelly "},
			 {"Written by" , "Nick Vallelonga, Brian Hayes Currie, Peter Farrelly"},
			 {"Produced by", "Jim Burke, Brian Hayes Currie, Peter Farrelly, Nick Vallelonga, Charles B.Wessler"},
			 {"Cinematography" , "Sean Porter"},
			 {"Edited by"  , "	Patrick J. Don Vito"},
			 {"Music by"   , "	Kris Bowers"},
			 {"Distributed by" , "Universal Pictures"},
			 { "Starring",
				  {
					  {"1",{"Viggo Mortensen"   , "Tony Lip"}},
					  {"2",{"Mahershala Ali"    , "Dr. Don Shirley"}},
					  {"3",{"Linda Cardellini"  , "Dolores Venere"}},
				  }
			 }
		},
		{
			{"Name", "The Green Mile"},
			{"Countries", "United States"},
			{"Year", 1999},
			{"Directed by", "Frank Darabont"},
			{"Written by" , "Stephen King"},
			{"Produced by", "Frank Darabont, David Valdes"},
			{"Cinematography" , "Richard Francis-Bruce"},
			{"Edited by"  , "Patrick J. Don Vito"},
			{"Music by"   , "Thomas Newman"},
			{"Distributed by" , "Warner Bros(Select territories), Universal Pictures(through United International Pictures, select territories)"},
			{ "Starring",
				  {
					  {"1",{"Tom Hanks"   , "Paul Edgecomb"}},
					  {"2",{"David Morse"    , "Brutus Howell"}},
					  {"3",{"Bonnie Hunt"  , "Jan Edgecomb"}},
					  {"4",{"Michael Clarke Duncan"  , "John Coffey"}},
					  {"5",{"James Cromwell"  , "Warden Hal Moores"}},
					  {"6",{"Michael Jeter"  , "Eduard Delacroix"}},
					  {"7",{"Graham Greene"  , "Arlen Bitterbuck"}},
					  {"8",{"Doug Hutchison"  , "Percy Wetmore"}},
				  }
			}
		},
		{
			{"Name", "Interstellar"},
			{"Countries", "United Kingdom, United States"},
			{"Year", 2014},
			{"Directed by", "Christopher Nolan"},
			{"Written by" , "Jonathan Nolan, Christopher Nolan"},
			{"Produced by", "Emma Thomas, Christopher Nolan, Lynda Obst"},
			{"Cinematography" , "Hoyte van Hoytema"},
			{"Edited by"  , "Lee Smith"},
			{"Music by"   , "Hans Zimmer"},
			{"Distributed by" , "Paramount Pictures (North America), Warner Bros.Pictures(International)"},
			{"Starring",
				  {
					  {"1",{"Matthew McConaughey"   , "Joseph Cooper"}},
					  {"2",{"Anne Hathaway"    , "Dr. Amelia Brand"}},
					  {"3",{"Jessica Chastain"  , "Murphy Cooper"}},
					  {"4",{"Bill Irwin"  , "TARS"}},
					  {"5",{"Ellen Burstyn"  , "elderly Murph"}},
					  {"6",{"Michael Caine"  , "Professor John Brand"}},
				  }
			}
		},
		{
			{"Name", "Fight Club"},
			{"Countries", "United States"},
			{"Year", 1999},
			{"Directed by", "David Fincher"},
			{"Written by" , "Chuck Palahniuk"},
			{"Produced by", "Art Linson, Cean Chaffin, Ross Grayson Bell"},
			{"Cinematography" , "Jeff Cronenweth"},
			{"Edited by"  , "James Haygood"},
			{"Music by"   , "The Dust Brothers"},
			{"Distributed by" , "20th Century Fox"},
			{ "Starring" ,
				  {
					  {"1",{"Brad Pitt"   , "Tyler Durden"}},
					  {"2",{"Edward Norton"    , "the Narrator"}},
					  {"3",{"Helena Bonham Carter"  , "Marla Singer"}},
					  {"4",{"Meat Loaf"  , "Robert Paulson"}},
					  {"5",{"Jared Leto"  , "Angel Face"}},
				  }
			}
		}
	};

	std::ofstream file("base_movies.json");
	if (file.is_open()) {
		file << base_movies.dump(4) << std::endl;
		file.flush();
		file.close();
	}
}
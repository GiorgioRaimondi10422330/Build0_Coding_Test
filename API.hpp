#ifndef API_BUILD0_TEST
#define API_BUILD0_TEST

#include <iostream> //for cout
#include <utility>  //for pair
#include <iterator> //for reading all the map
#include <map>		//for map
#include <string>	//for string
#include <vector>   //for vector
#include <array>	//for array

namespace API_SPACE{

//Class containing the the configuration value
typedef std::array<std::string, 3> CONF_VALUE; 

typedef std::map<std::string ,CONF_VALUE> API_MAP;

class API{
public:
	//Default Constructor
	API(){};

	//Constructor
	API(std::vector<CONF_VALUE> & Val){
		for(int i=0;i<Val.size();i++)
			STORE.insert(make_pair(Val[i][0],Val[i]));
	}

	//Copy Constructor
	API(API &a):STORE(a.STORE){}

	//Equal Operator
	API & operator=(API &A){
		STORE=A.STORE;
	}

	//Get function for given ID
	std::vector<CONF_VALUE> GET(std::string & ID);

	//Post fuction for missing ID
	bool POST(std::string & ID,std::string & NAME, std::string & VALUE);

	//Put function to update VALUE for a given ID
	bool PUT(std::string & ID,std::string & NAME, std::string & VALUE);

	//Delete a configuration for a given ID
	bool DEL(std::string & ID);

	//Change ID configuaration for a given ID
	bool CHANGE_ID(std::string & ID, std::string & NEW_ID);

private:
	//API MAP STORING THE ELEMENT
	API_MAP STORE;

	//It verified that the ID is real in ID format
	int check_ID(std::string & IN, std::string & OUT);

};


}//end of namespace


#endif
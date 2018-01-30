#include "API.hpp"
namespace API_SPACE{

//Function for printing configuration value in JSON format
void Print_JSON(std::vector<CONF_VALUE> & CONF_LIST){
	for(int i=0; i<CONF_LIST.size();i++){
		std::cout<<std::endl;
		std::cout<<"{"<<std::endl;
		std::cout<<"\"id\": \""<<CONF_LIST[i][0]<<"\","<<std::endl;
		std::cout<<"\"name\": \""<<CONF_LIST[i][1]<<"\","<<std::endl;
		std::cout<<"\"value\": \""<<CONF_LIST[i][2]<<"\""<<std::endl;
		std::cout<<"}"<<std::endl;
	}
};

//Function that check if the ID is the correct format and erase the backslash
int API::check_ID(std::string & IN, std::string & OUT){
	int comparison;
	char backslash='\\';
	if(IN.substr(0,1).compare(&backslash)==0){
		comparison=0;
	} else if(IN.size()==1){
		comparison=1;
	} else{
		comparison=2;
		OUT=IN.substr(1,IN.size()-1);
	}
	return comparison;
}

//Return the Configuration value for a given ID
std::vector<CONF_VALUE> API::GET(std::string & ID){

	std::string short_ID;		//ID without backslash
	std::vector<CONF_VALUE> value;

	int check=check_ID(ID,short_ID);

	if(check==0){
		// The ID is not in ID format
		std::cout<<"The ID must start with a backslash"<<std::endl;
	}else if(check==1){
		// "ID"= "\"
		for(API_MAP::iterator it=STORE.begin(); it!=STORE.end(); it++){
			value.push_back(it->second);
		}
		if(value.size()==0){
			std::cout<<"The API doesn't contain any configuration"<<std::endl;
		}
	}else{
		// If the ID is in a general format
		API_MAP::iterator it=STORE.find(short_ID);
		if(it!=STORE.end())//If found
			value.push_back(it->second);
		else{
			std::cout<<"There is no value for the given ID"<<std::endl;
		}
	}

	//Printing Values
	if(value.size()>0)
		Print_JSON(value);

	return value;
}

// Add a new configuration value to the API
bool API::POST(std::string & ID,std::string & NAME, std::string & VALUE){
	std::string short_ID;
	bool worked=true;

	int check=check_ID(ID,short_ID);
	if(check<2){
		std::cout<<"The ID is not in the correct format"<<std::endl;
		worked=false;
	} else{
		CONF_VALUE value;
		value[0]=short_ID;
		value[1]=NAME;
		value[2]=VALUE;
		STORE.insert(std::make_pair(short_ID,value));
	}
	return worked;
}

//Modify the Configuration value for a given ID
bool API::PUT(std::string & ID,std::string & NAME, std::string & VALUE){
	std::string short_ID;
	bool worked=true;

	int check=check_ID(ID,short_ID);
	if(check<2){
		std::cout<<"The ID is not in the correct format"<<std::endl;
		worked=false;
	} else{		// general ID format
		API_MAP::iterator it=STORE.find(short_ID);
		if(it!=STORE.end()){
			CONF_VALUE value;
			value[0]=short_ID;
			value[1]=NAME;
			value[2]=VALUE;
			STORE[short_ID]=value;
		}
		else{
			std::cout<<"There is no value for the given ID"<<std::endl;
			worked=false;
		}
	}
	return worked;
}

bool API::DEL(std::string & ID){
	std::string short_ID;
	bool worked=true;

	int check=check_ID(ID,short_ID);
	if(check==0){
		// No ID format
		std::cout<<"The ID must start with a backslash"<<std::endl;
		worked=false;
	} else if(check==2){		// general ID format
		API_MAP::iterator it=STORE.find(short_ID);
		if(it!=STORE.end())
			STORE.erase(it);	//Delete the given ID
		else{
			std::cout<<"There is no value for the given ID"<<std::endl;
			worked=false;
		}
	}else{						//"ID"="\"
		STORE.clear();			//delete all the configuration
	}
	return worked;
}

// Change an ID already present in the file
bool API::CHANGE_ID(std::string & ID,std::string & NEW_ID){
	std::string short_ID;
	std::string new_short_ID;
	bool worked=true;

	if(check_ID(ID,short_ID)<2 || check_ID(NEW_ID, new_short_ID)<2){
		std::cout<<"One of the ID must start is not in the correct format"<<std::endl;
		worked=false;
	} else {		// general ID format
		API_MAP::iterator it=STORE.find(short_ID);
		if(it!=STORE.end()){ //Change the ID value
			CONF_VALUE new_Val=it->second;
			new_Val[0]=new_short_ID;
			STORE.erase(it);
			STORE.insert(std::make_pair(new_short_ID,new_Val));
		}
		else{
			std::cout<<"There is no value for the given ID"<<std::endl;
			worked=false;
		}
	}
	return worked;
}





}//end of namespace
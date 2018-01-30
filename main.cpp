#include "API.hpp"

using namespace API_SPACE;
using namespace std;

int main(int argc, char * argv[]){
	API myAPI;

	cout<<"---------- Testing -----------\n\n";
	cout<<"-----Get Test with EMPTY MAP-------\n";
	string backslash="\\";
	myAPI.GET(backslash);
	cout<<"\n";


	cout<<"-----POST Test---------------------\n";
	string ID="\\foo"; 
	string NAME="Foo_Config";
	string VALUE="Conf1";
	if(myAPI.POST(ID,NAME,VALUE))
		cout<<"First element correctly put inside the API\n\n";

	cout<<"-----POST Test 2-------------------\n";
	ID="\\pippo"; 
	NAME="Pippo_Config";
	VALUE="Conf2";
	if(myAPI.POST(ID,NAME,VALUE))
		cout<<"Second element correctly put inside the API\n\n";

	cout<<"-----Get Test with backslash-------\n";
	myAPI.GET(backslash);
	cout<<"\n";

	cout<<"-----Get Test with single request---\n";
	myAPI.GET(ID);
	cout<<"\n";

	cout<<"-----CopyConstructor for API--------\n";
	API API2(myAPI);

	cout<<"-----Put Test-----------------------\n";
	NAME="Pippo_Config_Changed";
	VALUE="Conf2_Changed";
	if(myAPI.PUT(ID,NAME,VALUE))
		myAPI.GET(backslash);
	cout<<"\n";

	cout<<"-----Change_ID Test-----------------------\n";
	string NEW_ID="\\pippo_ID_Changed";
	if(myAPI.CHANGE_ID(ID,NEW_ID)){
		myAPI.GET(backslash);
		ID=NEW_ID;
	}
	cout<<"\n";

	cout<<"-----Del Test-----------------------\n";
	if(myAPI.DEL(ID))
		myAPI.GET(backslash);
	cout<<"\n";

	cout<<"-----Full Del Test------------------\n";
	if(myAPI.DEL(backslash))
		myAPI.GET(backslash);
	cout<<"\n";

	cout<<"-----API2 Get-----------------------\n";
	API2.GET(backslash);

	cout<<"-----COPY Operator------------------\n";
	myAPI=API2;
	myAPI.GET(backslash);
return 0;
}
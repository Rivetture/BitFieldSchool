#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include <unordered_map>
#include <string>
using namespace std;

//This final homework assignment will teach you:
//Inheritance (polymorphism)
//Bit fields
//Refresher on overloading operators

//Three different ways of doing constants
//A bit of exceptions

//These constants can either be accessed by name "orange" or by "key_colors::orange" for clarity
//In VIM , 'm' command marks a spot with a letter, like m x to mark spot x
//Single quote followed by a letter jumps you back to the marked spot
//Record a macro a: qa
//enter commands
//q to end command
//Replay a macro a: @a
/*
   enum key_colors {
   red = 1,
   yellow = 2,
   green = 4,
   blue = 8,
   orange = 16,
   ultraviolet = 32,
   brown = 64,
   black = 128
   };

//The player can only have one of this list of bits set between JOB_THIEF and JOB_PSION
//Setting another bit in this range will clear all the other bits in the range set
const int JOB_THIEF  = 1;
const int JOB_RUNNER = 2;
const int JOB_WARLOCK = 4;
const int JOB_CHAPLAN = 8;
const int JOB_BERSERKER = 16;
const int JOB_GUERILLA = 32;
const int JOB_JUDOKA = 64;
const int JOB_ARMY = 128;
const int JOB_HACKER = 256;
const int JOB_MARTYR = 512;
const int JOB_CRUSADER = 1024;
const int JOB_TKD = 262144;
const int JOB_PSION = 524288;

const int JOB_ALL = 788479; //The sum of all bits above, for easy math

//Any or all of these can be set in addition to the above
const int JOB_ACTIVE = 2048;
const int JOB_FULL_HIDE = 4096;
const int JOB_TIRED = 8192;
const int JOB_BLOODY_KNIFE = 16384;
const int JOB_EXTRA1 =		65536;
const int JOB_EXTRA2 =		131072;

//This is the C way of doing constants
#define WEAP_HOOK				1
#define WEAP_THE_NAVARRO        2
#define WEAP_MEDIKIT			4
#define WEAP_SPANNER			8
#define WEAP_AXE				16
#define WEAP_SNIPER_RIFLE		32
#define WEAP_AUTO_RIFLE 		64
#define WEAP_SHOTGUN			128
#define WEAP_SUPER_SHOTGUN		256
#define WEAP_NAILGUN			512
#define WEAP_LIGHT_ASSAULT		1024
#define WEAP_GRENADE_LAUNCHER	2048
#define WEAP_FLAMETHROWER		4096
#define WEAP_ROCKET_LAUNCHER	8192
#define WEAP_INCENDIARY 		16384
#define WEAP_ASSAULT_CANNON 	32768
#define WEAP_LIGHTNING			65536
#define WEAP_DAEDALUS			131072
#define WEAP_TRANQ				262144
#define WEAP_RAILGUN			524288
#define WEAP_MAUSER 			1048576
#define WEAP_AIRFIST			2097152 
#define WEAP_LASERCANNON		4194304
#define WEAP_SNG				8388608
*/
typedef int64_t int64; //Here's an example of how to do a typedef

unordered_map<string,const int64_t>colors = {
	{"RED",1},
	{"YELLOW",2},
	{"GREEN",4},
	{"BLUE",8},
	{"ORANGE",16},
	{"ULTRAVIOLET",32},
	{"BROWN",64},
	{"BLACK",128}
};

unordered_map<string,const int64_t>joblist = {
	{"JOB_THIEF",1},
	{"JOB_RUNNER",2},
	{"JOB_WARLOCK",4},
	{"JOB_CHAPLAN",8},
	{"JOB_BERSERKER",16},
	{"JOB_GUERILLA",32},
	{"JOB_JUDOKA",64},
	{"JOB_ARMY",128},
	{"JOB_HACKER",256},
	{"JOB_MARTYR",512},
	{"JOB_CRUSADER",1024},
	{"JOB_TKD",262144},
	{"JOB_PSION",524288},

	{"JOB_ALL",788479},


	{"JOB_ACTIVE",2048},
	{"JOB_FULL_HIDE",4096},
	{"JOB_TIRED",8192},
	{"JOB_BLOODY_KNIFE",16384},
	{"JOB_EXTRA1",65536},
	{"JOB_EXTRA2",131072}
};


unordered_map<string,const int64_t>weaponlist = {
	{"WEAP_HOOK",1},
	{"WEAP_MEDIKIT",4},
	{"WEAP_SPANNER",8},
	{"WEAP_AXE",16},
	{"WEAP_SNIPER_RIFLE",32},
	{"WEAP_AUTO_RIFLE",64},
	{"WEAP_SHOTGUN",128},
	{"WEAP_SUPER_SHOTGUN",256},
	{"WEAP_NAILGUN",512},
	{"WEAP_LIGHT_ASSAULT",1024},
	{"WEAP_GRENADE_LAUNCHER",2048},
	{"WEAP_FLAMETHROWER",4096},
	{"WEAP_ROCKET_LAUNCHER",8192},
	{"WEAP_INCENDIARY",16384},
	{"WEAP_ASSAULT_CANNON",32768},
	{"WEAP_LIGHTNING",65536},
	{"WEAP_DAEDALUS",131072},
	{"WEAP_TRANQ",262144},
	{"WEAP_RAILGUN",524288},
	{"WEAP_MAUSER",1048576},
	{"WEAP_AIRFIST",2097152},
	{"WEAP_LASERCANNON",4194304},
	{"WEAP_SNG",8388608},

};

unordered_map<int64_t,string>weaponvalue = {
	{1,"WEAP_HOOK"},
	{4,"WEAP_MEDIKIT"},
	{8,"WEAP_SPANNER"},
	{16,"WEAP_AXE"},
	{32,"WEAP_SNIPER_RIFLE"},
	{64,"WEAP_AUTO_RIFLE"},
	{128,"WEAP_SHOTGUN"},
	{56,"WEAP_SUPER_SHOTGUN"},
	{512,"WEAP_NAILGUN"},
	{1024,"WEAP_LIGHT_ASSAULT"},
	{2048,"WEAP_GRENADE_LAUNCHER"},
	{4096,"WEAP_FLAMETHROWER"},
	{8192,"WEAP_ROCKET_LAUNCHER"},
	{16384,"WEAP_INCENDIARY"},
	{32768,"WEAP_ASSAULT_CANNON"},
	{65536,"WEAP_LIGHTNING"},
	{131072,"WEAP_DAEDALUS"},
	{262144,"WEAP_TRANQ"},
	{524288,"WEAP_RAILGUN"},
	{1048576,"WEAP_MAUSER"},
	{2097152,"WEAP_AIRFIST"},
	{4194304,"WEAP_LASERCANNON"},
	{8388608,"WEAP_SNG"},

};

class Bitfield {
	protected: //Protected, not private!!
		int64 datafield;
	public:
		Bitfield() : datafield(0) {}

		//YOU: Make this function virtual and see what happens in print_message...
		void foo() { cout << "My datafield is: " << datafield << "\n"; }

		//YOU: Set the passed in flag on datafield
		void operator+=(const int64 flag) {
			datafield = datafield|(flag);
		}

		//YOU: This function will clear the passed in flag
		void operator-=(const int64 flag) {
			datafield = datafield &(~flag);
		}

		//YOU: This function will return true if the passed in flag is set
		bool operator==(const int64 flag) {
			return datafield&(flag);
		}
};

class Job_Bitfield : public Bitfield {
	public:
		Job_Bitfield() : Bitfield() {}
		void foo() {
			if (datafield)
				cout << "I have a job!\n";
			else
				cout << "I do not have a job.\n";
		}
		/*
		   void operator+=(const int64 flag){
		   if(flag == 788479){
		   throw std::runtime_error("Cannot set flag JOB_ALL");
		   }
		   else if(flag >= 2048 && flag <= 131072){
		   datafield = flag;
		   }
		   else{
		   (datafield &= ~(joblist.at("JOB_ALL"))) = flag;
		   }
		   */


void operator+=(const int64 flag) {
	if(!(joblist.at("JOB_ALL") - flag > 0))
		throw runtime_error("Cannot set flag JOB_ALL");
	else if (flag >= joblist.at("JOB_ACTIVE") && flag <= joblist.at("JOB_EXTRA2"))
		datafield |= flag;
	else
		(datafield &= ~(joblist.at("JOB_ALL"))) |= flag;
}





//YOU: Override the += operator for this class so that it clears any existing jobs between 
// JOB_THIEF and JOB_PSION if a new bit in that range is set.
//You can use JOB_ALL to quickly test to see if a bit is in that range, and clear all such bits
// if you do get a match
//The other bits (JOB_ACTIVE through JOB_EXTRA2) should be left alone and can be independently set
//JOB_ALL cannot be set by the user. If he tries to, throw a runtime_exception with the string:
// "Cannot set flag JOB_ALL"
};

class Weapon_Bitfield : public Bitfield {
	public:
		Weapon_Bitfield() : Bitfield() {}
		int64 select_best_weapon() {
			//YOU: Return the highest bit set

			//If we have no weapon at all, throw an exception
			//Don't bother catching it, we'll let it kill the program
			if (!datafield)
				throw runtime_error("Cannot select best weapon when we don't have one!");
			else{
				int64 temp = 8388608;
				while(true){
					//cerr << temp;
					if(datafield & temp) return temp;
					else temp = temp/2;
				}

			}
		}
		void foo() {
			if (datafield >= 32) 
				cout << "I haz ranged weapon.\n";
			else if (datafield)
				cout << "I haz melee weapon.\n";
			else
				cout << "I no haz weapon.\n";
		}
};

//What will this print?
void print_message(Bitfield& b) {
	b.foo();
}
void uppercaseify(string& mystr){
	for(auto& c:mystr)
		c= toupper(c);
}
int main() {
	Bitfield keys;
	Job_Bitfield jobs;
	Weapon_Bitfield weapons;
	/*
	//Example code, can delete...
	keys.foo();
	jobs.foo();
	weapons += (WEAP_AXE);
	weapons += (WEAP_SNIPER_RIFLE); 
	weapons.foo();
	print_message(keys);
	print_message(jobs);
	print_message(weapons);
	keys+=(key_colors::red);
	keys-=(green);
	if (keys == red) cout << "Haz red.\n";
	weapons.select_best_weapon();
	*/
	//YOU: Write a main loop that will allow the user to set, clear, and test to see if certain flags are set
	// within the bitfields declared above. You'll need to keep track of three:
	//1) keys, which will hold the values from key_colors::red through black. 
	//2) jobs, which will hold the const ints for jobs, with special rules (you can only have one job)
	//3) weapons, which will allow the user to query what the best weapon he has is.
	string operation;
	string flag;
	while (cin){
		cin >> operation;
		uppercaseify(operation);
		if(cin.eof()){
			break;
		}
		if(!cin || operation == "QUIT"){
			throw runtime_error("Invalid Input");	
		}
		if(operation == "ADD"){
			cin >> flag;
			if(flag.substr(0,1) == "W"){
				if(flag.substr(0,4) == "WEAP"){
					weapons += weaponlist.at(flag); 		
				}
			}
			else if(flag.substr(0,1) == "J"){
				if(flag.substr(0,3) == "JOB"){
					jobs += joblist.at(flag); 		
				}
			}
			else{
				keys += colors.at(flag);
			}
		}
		else if(operation == "DELETE"){
			cin>> flag;
			if(flag.substr(0,1) == "W"){
				if(flag.substr(0,4) == "WEAP"){
					weapons -= weaponlist.at(flag);
				}
			}
			else if(flag.substr(0,1) == "J"){
				if(flag.substr(0,3) == "JOB"){
					jobs -= joblist.at(flag);
				}
			}
			else{
				keys -= colors.at(flag);
			}
		}
		else if(operation == "QUERY"){
			cin >> flag;
			if(flag.substr(0,1) == "W"){
				if(flag.substr(0,4) == "WEAP"){
					if(weapons == weaponlist.at(flag)){
						cout << "TRUE" << endl;
					}
					else{
						cout << "FALSE" << endl;
					}
				}
			}
			else if(flag.substr(0,1) == "J"){
				if(flag.substr(0,3) == "JOB"){
					if(jobs == joblist.at(flag)){
						cout<< "TRUE" << endl;
					}
					else{
						cout << "FALSE" << endl;
					}
				}
			}
			else{
				if(keys == colors.at(flag)){
					cout << "TRUE" << endl;
				}
				else{
					cout << "FALSE" << endl;
				}
			}
		}
		else if (operation == "SELECT"){
			cout << weaponvalue.at( weapons.select_best_weapon());

		}
	}
	return 0;
}
//SYNTAX: 
//"ADD <flagname>" will add the flag to the appropriate bitfield. (Example: "ADD RED" or "ADD WEAP_ROCKET_LAUNCHER" or "ADD JOB_PSION") (JOB_ALL cannot be set by the user)
//"DELETE <flagname>" removes the flag from the appropriate bitfield. (Example: "REMOVE ORANGE" will clear the orange flag from the keys bitfield.
//"QUERY <flagname>" will cout "TRUE" if the flag is set in the appropriate bitfield, or "FALSE" otherwise. (Example: "ADD JOB_PSION", "QUERY JOB_PSION" will print "TRUE" to the screen.) 
//"SELECT BEST WEAPON will cout the name of the highest bit set (Example: If the bits for the axe and rocket launcher have been set, it will print to the screen "WEAP_ROCKET_LAUNCHER".)
//On an invalid command (i.e. not one of the four possibilities above), throw a runtime_error with the string "Invalid Input", and let it kill the program

#include <fstream>
using namespace std;

class PIV_Hash
{
	private:
		unsigned int * values;
		unsigned int array_size;
		double to_be_populated;

		unsigned int number_of_values_present;
		unsigned int collision_counter;

	public:
		PIV_Hash(unsigned _number_of_values_to_be_stored, double _to_be_populated = 0.25);
		PIV_Hash(char * _file_name, double _to_be_populated = 0.25);
		PIV_Hash(PIV_Hash * _piv_hash, double _to_be_populated = 0.25);

		~PIV_Hash();

		bool add_Value(unsigned _value);
		bool find_Value(unsigned _value);
		bool write_to_Value(ifstream &_file_name);
		bool write_to_File(ofstream &_file_name);

		unsigned int get_Array_Size();
		unsigned int get_Number_of_Values_Present();


};
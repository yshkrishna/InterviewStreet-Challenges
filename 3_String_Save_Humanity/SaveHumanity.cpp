#include <fstream>
#include <iostream>
#include <sstream>
#include <boost/program_options.hpp>

#define ARGUMENT_ERROR -1
#define TBOUNDS_ERROR -2
#define FILEOPEN_ERROR -3

#define TMAX 10
#define TMIN 1

namespace bpo = boost::program_options;
using namespace std;

bool parse_arguments(int argc, char** argv, string& input_file)
{
	bpo::options_description cmdline_opts;
	bpo::options_description input_opts("input options");

	input_opts.add_options()
	("input,i",bpo::value<string>(&input_file), "Input file")
	("help,h","Custom help message");

	cmdline_opts.add(input_opts);

	try
  {
		bpo::variables_map var_map;
		bpo::store(
		  bpo::command_line_parser(argc,argv).
			options(cmdline_opts).
			run(),var_map
		);
		bpo::notify(var_map);

		if(var_map.count("help"))
		{
			cout << cmdline_opts << endl;
			return false;
		}
		return true;
	}

  catch(exception& e)
  {
		cout << e.what() << endl;
		return false;
	}
}
void solution(const string &patient_dna, const string &virus_dna)
{
	ostringstream oss;
	string comp;
	int error_counter;
	unsigned int virus_size = virus_dna.size();

	for(unsigned int i=0;i<=patient_dna.size()-virus_size;++i)
	{
		error_counter=0;
		comp = patient_dna.substr(i,virus_size);
		
		for(unsigned int j=0;j<virus_size;++j)
		{
			if(comp.at(j)!=virus_dna.at(j))
			{
				error_counter++;
			}

			if(error_counter > 1)
			{	
				break;
			}
		}

		if(error_counter<=1)
		{
			oss << i << " ";
		}
	}
	cout << oss.str() << endl;
}

int main(int argc, char** argv)
{
  // Parse the arguments passed to the program
  // obtain the input filename
	string input_file;
	if(! parse_arguments(argc, argv, input_file))
	{
		return ARGUMENT_ERROR;
	}
	
	string patient_dna;
	string virus_dna;

	// Executing using an input file
	if(!input_file.empty())
	{
    ifstream myfile(input_file.c_str());
    int cases;
    if(myfile.is_open())
    {
      myfile >> cases;
      if(cases>TMAX || cases <TMIN)
      {
        return TBOUNDS_ERROR;
      }

      while(myfile.good())
      {
        getline(myfile,patient_dna);
        if(!patient_dna.empty())
        {
          getline(myfile,virus_dna);
          solution(patient_dna,virus_dna);
        }
      } //end while
      myfile.close();
      return 0;
    } //end file open
    else
    {
      return FILEOPEN_ERROR;
    }
	} //end execute from input file

	// Executing using cin
	else
	{
		int i,cases;
		cin >> cases;

    if(cases > TMAX || cases < TMIN)
    {
      return TBOUNDS_ERROR;
    }

		for(i=0;i<cases;++i)
		{
			cin >> patient_dna;
			cin >> virus_dna;
			cin.ignore();
			solution(patient_dna,virus_dna);
		}
		return 0;
	}
}

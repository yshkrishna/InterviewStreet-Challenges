#include <fstream>
#include <iostream>
#include <sstream>

#define	INPUT_FILE "input.txt"

using namespace std;

void solution(const string &patient_dna, const string &virus_dna)
{
	ostringstream oss;
	string comp = "";
	int error_counter;
	virus_size = virus_dna.size();

	for(unsigned int i=0;i<=patient_dna.size()-virus_size;++i)
	{
		error_counter=0;
		comp = patient_dna.substr(i,virus_size));
		
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

int main()
{
	string patient_dna;
	string virus_dna;
	int i,n;

	cin >> n;
	
	for(i=0;i<n;i++)
	{
		cin >> patient_dna;
		cin >> virus_dna;
		cin.ignore();
		solution(patient_dna,virus_dna);
	}

	return 0;
}

#include <fstream>
#include <iostream>

#define	INPUT_FILE "input.txt"

using namespace std;

void solution(const string &patient_dna, const string &virus_dna)
{
	string comp = "";
	int error_counter;
	int number_of_matching=0;
	int first_position=0;

	for(unsigned int i=0;i<patient_dna.size()-virus_dna.size();++i)
	{
		error_counter=0;
		comp = patient_dna.substr(i,virus_dna.size());
		
		for(unsigned int j=0;j<virus_dna.size();++j)
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
		if(number_of_matching==0)
		{
			first_position=i;
		}
		if(error_counter<=1)
		{
			number_of_matching++;
		}
	}
	if(number_of_matching!=0)
	{
		cout<<first_position<<" "<<number_of_matching<<endl;
	}
	else
	{
		cout << endl;
	}
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

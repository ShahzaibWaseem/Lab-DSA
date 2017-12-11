// Including Libraries
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

class CSVRow {
	vector<string> m_data;							//private
public:
	size_t size() const {
		return m_data.size();
	}

	void readNextRow (istream& str) {
		string line;
		getline(str,line);
		stringstream lineStream(line);
		string cell;
		m_data.clear();

		while(getline(lineStream,cell,',')) {
			m_data.push_back(cell);
		}
	}

	vector<string> get_m_data(){					//getter for a private entity
		return m_data;
	}
};

int main(int argc, char** argv) {
	ifstream csv_file(argv[1]);						//tries to Open the csv_file with the Second Command-Line Argument

	//Task A
	cout << endl << "TASK A : csv_file Reading" << endl;	
	if (csv_file.is_open()) {						//Some Checks
		cout << "The file "<< argv[1] << " opened Successfully" << endl;
	}
	else{
		cout << "Failed to Open this csv_file" << endl;
		exit(1);
	}

    vector<vector<string> > matrix;					//Making a Matrix to read the whole of the csv_file

    while(!csv_file.eof()){							//Repeatedly calling the function to populate the matrix
    	CSVRow CSVRowObject;
    	CSVRowObject.readNextRow(csv_file);
    	matrix.push_back(CSVRowObject.get_m_data());
    }

    //Task B
    cout << endl << "TASK B : The Names of Schools with 0 Students Passed in 10th are : " << endl;
    for (int rows = 0; rows < matrix.size() ; ++rows)
    	if (matrix[rows][8] == "0")
    		cout << matrix[rows][1] << endl;

    //Task C
    cout << endl << "TASK C : Finding Large Schools" << endl;
    vector <int> LargeSchools;						//Used to insert all the Enrollments if they exceed 50
    int tempC;										//temporary Variable for TASK C
    double tempD;									//temporary Variable for TASK C
    double highest;									//to get the highest Dropout Rate
    string highestDropout;							//to get the highest Dropout School Name

    for (int rows = 0; rows < matrix.size(); rows++)
    {
    	stringstream enrollment(matrix[rows][6]);	//get a stringstream of enrollment column and then convert it into int
    	enrollment >> tempC;

    	stringstream Dropout(matrix[rows][12]);		//get a stringstream of Dropout column and then convert it into int
    	Dropout >> tempD;

    	if (tempC > 50){							//Condition Checking if Students Enrolled are greater than 50
    		LargeSchools.push_back(tempC);
    		if (highest < tempD){					//Dropout Conditions
    			highest = tempD;
    			highestDropout = matrix[rows][1];
    		}
    	}
    }

    double Percentage;								//Get the Percentage of large Schools
    //matrix Size - 1 : because the first column is mere title Column (with Strings only)
    cout << "LargeSchools Size : " << LargeSchools.size() << ", matrix Size - 1 : " << matrix.size() - 1 << endl ;
    Percentage = ((double)LargeSchools.size()/(double)(matrix.size() - 1)) * 100;

    //Task C Printing
    cout << "The Percentage is : " << Percentage << endl;
    
    //Task D Printing
    cout << endl << "TASK D : Dropout Rate" << endl;
    cout << highestDropout << " , " << highest << endl;
	
	//file closing
	csv_file.close();
	return 0;										//function exited Normally
}
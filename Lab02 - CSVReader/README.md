# Lab 2 : CSV File Handling

Use the following class in the code:
```cpp
class CSVRow {
vector<string> m_data;					//private

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

	vector<string> get_m_data(){			//getter for a private entity
		return m_data;
	}
};
```
# Tasks
1. Read the given .csv file into vector of strings (with the help of `CSVRow`). The Filename (.csv) should be specified at the command terminal using the command-line arguments.
2. Print the names of all the schools for which the number of Students passed in 10<sup>th</sup> Class Exam is ZERO.
3. Find the percentage of large schools with respect to Student Enrollment, assuming a school to be large if it had more than 50 Students in 9<sup>th</sup> (2012) as per Registration.
4. Among all large sized schools, print the name of the school with the highest % dropout.
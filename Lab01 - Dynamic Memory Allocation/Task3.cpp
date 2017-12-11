/*
* Name: M. Shahzaib Waseem
* Student #: 187330
*/

#include <iostream>
#include <string>

using namespace std;

/*
* Define a struct Area that has two private variable members;
* units of type string and area_value of type float.
*/
class Area
{
	private:
		string units;
		float areaValue;


	public:
		void setArea(float inputArea){
			areaValue = inputArea;
		}
		void setUnits(string inputUnits){
			units = inputUnits;
		}
		float getArea(){
			return areaValue;
		}
};

int main()
{
	float inputArea;
	string inputUnits;

	// Modify program to create a dynamic variable of type Area.
	Area* AreaObject = new Area;

	// Input from the keyboard the area_value and its units.
	cout << "Enter the Area Here : ";
	cin >> inputArea;
	cout << "Enter the units Here : ";
	cin >> inputUnits;

	AreaObject->setArea(inputArea);
	AreaObject->setUnits(inputUnits);

	// Compute one-half and one-quarter of the area and display the results
	AreaObject->setArea((AreaObject->getArea())/2);
	cout << "The Computed Area is : " << AreaObject->getArea();

	// Destroy the dynamic variable at the end
	delete AreaObject;
	return 0;
}
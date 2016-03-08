/*
	Albert, Brendan
	CS 150
	March 7, 2016

	IC10_AverageRainfall
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	int years, numberOfMonths;
	double totalInchesRain = 0.0, maxRainfall = -1000, minRainfall = 1000, monthlyAverage;
	bool errorOccurred;
	vector <string> monthNames = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
	vector <double> rainfallAmts;

	// Input validation do-while, year must be >= 1
	do
	{
		cout << "Please enter the number of years: ";
		cin >> years;
		errorOccurred = (years < 1 || cin.fail());
		if (errorOccurred)
		{
			cout << endl << "Error: number of years must be > 0." << endl;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}
	} while (errorOccurred);

	// To get this far, the user provided a valid number of years.

	// Declare a variable to temporarily store a rainfall amount, which will then be entered into a rainfall vector.
	double monthsRain;

	for (int year = 1; year <= years; year++)
	{
		cout << "Starting year number " << year << endl;
		for (int month = 0; month < monthNames.size(); month++)
		{
			do
			{
				cout << "Please enter the amount of rain for month " << monthNames.at(month) << ": ";
				cin >> monthsRain;
				errorOccurred = ( monthsRain < 0 || cin.fail() );
				if (errorOccurred)
				{
					cout << endl << "Error: please enter a NUMBER >= 0" << endl;
					cin.clear();
					cin.ignore(INT_MAX, '\n');
				}
			} while (errorOccurred);
			
			// Rain amount must have been valid, so time to add it to our rainfall vector.
			rainfallAmts.push_back(monthsRain);
			// Incease the total amount of rain by each month's rainfall.
			totalInchesRain += monthsRain;
			// If monthsRain is the smallest amount of rain seen so far, set minRainfall to monthsRain.
			minRainfall = monthsRain;
			// If monthsRain is the greatest amount of rain seen so far, set maxRainfall to monthsRain.
			maxRainfall = monthsRain;


		} // Closes month for loop
	} // Closes year for loop

	// 12 months in a year
	numberOfMonths = years * 12; 
	// The average monthly rainfall is the total amount of rain for all the years, divided by the number of months.
	monthlyAverage = totalInchesRain / numberOfMonths;
	// To calculate the standard deviation
	// To display a histogram which represents visually where rainfall occurs during a year.

	system("pause");
	return 0;
}
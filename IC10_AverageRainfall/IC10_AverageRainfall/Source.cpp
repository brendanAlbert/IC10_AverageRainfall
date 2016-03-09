/*
Albert, Brendan
CS 150
March 7, 2016

IC10_AverageRainfall
*/
#include <iomanip>
#include <iostream>
#include <math.h>
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
				errorOccurred = (monthsRain < 0 || cin.fail());
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
			if (monthsRain < minRainfall)
				minRainfall = monthsRain;
			// If monthsRain is the greatest amount of rain seen so far, set maxRainfall to monthsRain.
			if (monthsRain > maxRainfall)
				maxRainfall = monthsRain;


		} // Closes month for loop
	} // Closes year for loop

	// 12 months in a year
	numberOfMonths = years * 12;
	// The average monthly rainfall is the total amount of rain for all the years, divided by the number of months.
	monthlyAverage = totalInchesRain / numberOfMonths;


	cout << endl << "Over " << numberOfMonths << " months: " << endl
		<< "Total of " << setprecision(2) << fixed << totalInchesRain << ((totalInchesRain == 1) ? " inch of rain." : " inches of rain.") << endl
		<< "Average of " << monthlyAverage << ((monthlyAverage == 1) ? " inch per month!" : " inches per month!") << endl << endl
		<< "The minimum amount of rainfall was " << minRainfall << ((minRainfall == 1)? " inch.":" inches.") << endl
		<< "The maximum amount of rainfall was " << maxRainfall << ((maxRainfall == 1) ? " inch." : " inches.") << endl;

	// To calculate the standard deviation
	// Step 1: Sum all of the rainfall and divide by the number of months to get the mean.
	double mean = monthlyAverage;
	vector <double> meanSubtractedAmounts;
	vector <double> squaredSubtractedAmounts;
	double sumSquaredAmounts = 0.0;
	int index = 0;
	// Step 2: Subtract mean from each rainfall amount, square each difference, sum the squares.
	for (auto rainfallAmount : rainfallAmts)
	{
		meanSubtractedAmounts.push_back(rainfallAmount - mean);
		squaredSubtractedAmounts.push_back(pow(meanSubtractedAmounts.at(index), 2));
		sumSquaredAmounts += squaredSubtractedAmounts.at(index);
	}
	// Variance is the quotient of the sum of the squares and (number of months minus 1).
	double variance = sumSquaredAmounts / (numberOfMonths - 1);

	// Step 3: Standard Deviation(SD) = square root of variance
	double standardDeviation = sqrt(variance);
	double minSD = mean - standardDeviation;
	double maxSD = mean + standardDeviation;

	// Step 4: Population standard deviation, square root of ( sum of squares divided by number of Months )
	double populationSD = sqrt( sumSquaredAmounts / numberOfMonths );

	cout << endl << "The standard deviation of the rainfall is: " << standardDeviation << endl
		<< "The minimum standard deviation is        : " << minSD << endl
		<< "The maximum standard deviation is        : " << maxSD << endl
		<< "The population standard deviation is     : " << populationSD << endl << endl;
	/*
		Consider a set X of numbers 5,10,15,20,25

		Step 1:

		Mean = Sum of X values / N(Number of values)
		= (5+10+15+20+25)/5
		= 75 / 5
		Mean = 15

		Step 2:

		To find the variance,
		Subtract the mean from each of the values,
		5-15 = -10
		10-15 = -5
		15-15 = 0
		20 - 15 = 5
		25 - 15 = 10

		Now square all the answers you have got from subtraction.
		(-10)^2 = 100
		(-5)^2 = 25
		(0)^2 = 0
		(5)^2 = 25
		(10)^2 = 100

		Add all the squared numbers,
		100 + 25 + 0 + 25 + 100 = 250

		Divide the sum of squares by (n-1)
		250 / (5-1) = 250 / 4 = 62.5

		Hence variance = 62.5.

		Step 3:

		To find the standard deviation, find the square root of variance,
		sqrt(62.5) = 7.905

		Therefore, standard deviation is 7.905.
		Minimum SD = Mean - SD
		= 15 - 7.905

		Maximum SD = Mean + SD
		= 15 + 7.905
		= 22.906

		Step 4:

		To find the population standard deviation,
		Divide the sum of squares found in step 2 by n
		250 / 5 = 50
		Find the square root of 50, sqrt(50) = 7.07

	*/

	// To display a histogram which represents visually where rainfall occurs during a year.
	int monthCounter = 0;
	int numberAsterisks;

	cout << "---------------------------------" << endl
		<< "|    Rainfall Histogram         | " << endl
		<< "---------------------------------" << endl;

	for (int year = 1; year <= years; year++)
	{
		cout << "---------------------------------" << endl
			<<	"Year number: " << year << endl
			<< "---------------------------------" << endl;
		for (int month = 0; month < 12; month++)
		{
			cout << monthNames.at(month) << ": ";
			//numberAsterisks = 0;
			numberAsterisks = round(rainfallAmts.at(monthCounter));
			for (int asterisk = 0; asterisk < numberAsterisks; asterisk++)
			{
				cout << "*";
			}
			monthCounter++;
			cout << endl;
		}
	}
	cout << endl;

	system("pause");
	return 0;
}

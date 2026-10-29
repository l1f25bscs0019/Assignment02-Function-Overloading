
#include<iostream>
#include<fstream>
using namespace std;
double fare(double km, double ratePerKm = 40.0);
double fare(double km, double ratePerKm, bool peakHour);
double fare(double km, char vehicle);
double fare(double km, char vehicle, int promoPercent);
int main() {

	cout << "fare(10) = " << fare(10) << endl;
	cout << "fare(10, 30.0) = " << fare(10, 30.0) << endl;
	cout << "fare(10, 30.0, true) = " << fare(10, 30.0, true) << endl;
	cout << "fare(8, 'B') = " << fare(8, 'B') << endl;
	cout << "fare(8, 'C') = " << fare(8, 'C') << endl;
	cout << "fare(8, 'C', 10) = " << fare(8, 'C', 10) << endl;

	// ---- Part B: write your code below this line ----
	int rides;
	cout << "How many rides? ";
	cin >> rides;
	char vehicle;
	double km;
	int promopercent;
	double charge = 0.0;
	double totalcharge = 0;
	ofstream file("rides.txt");
	for (int i = 0; i < rides; i++) {
		cout << "Ride " << i + 1 << " vehicle(B / R / C), km, promo% : ";
		cin >> vehicle >> km >> promopercent;
		if (promopercent == 0) {
			charge=fare(km, vehicle);
		}
		else
			charge=fare(km, vehicle, promopercent);
		totalcharge += charge;
		file << "Ride " << i + 1 << " (" << vehicle << "), " << km << "km->Rs. "<<charge << endl;
	}
	file << "Total collected: Rs. " << totalcharge << endl;
	//fare(10, 40);
	// Error :'fare': ambiguous call to overloaded function
	// Reason: the compiler can't choose version beacuse firstly integer can't be promoted 
	// secondly integer can be converted both to char and double so compliler is confused 
	// between double fare(double km, double ratePerKm = 40.0)  and   double fare(double km, char vehicle) call
	// Fix 1 : you can write 40.0 instead of 40 in call
	// Fix 2: secondly if you want to prefer to char then write it properly like B C or R as program is related to them
	file.close();
	return 0;
}
double fare(double km, double ratePerKm) {
	return 100 + km * ratePerKm;
}
double fare(double km, double ratePerKm, bool peakHour) {
	double totalfare = fare(km, ratePerKm);
	if (peakHour == true) {
		double extra = totalfare * 0.2;
		totalfare += extra;
	}
	return totalfare;
}
double fare(double km, char vehicle) {
	if (vehicle == 'B') {
		return fare(km, 25.0);
	}
	else if (vehicle == 'R')
		return fare(km, 35.0);
	else if (vehicle == 'C') {
		return fare(km, 50.0);
	}
	else
		return 0;
}
double fare(double km, char vehicle, int promoPercent) {
	double amount=fare(km, vehicle);
	double minus = amount * (promoPercent / 100.0);
	amount -= minus;
	return amount;
}
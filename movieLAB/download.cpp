#include<iostream>
#include<iomanip>
#include<sstream>
#include<cstdio>
#include<string>
#include<vector>

using namespace std;

string doubleToString(double v, int precision = 6) {
    ostringstream out;
    out << setprecision(precision) << v;
    return out.str();
}

class Movie {

public:
    enum { REGULAR = 0,  NEW_RELEASE = 1,  CHILDRENS = 2 };
    Movie( string title, int priceCode ) {
        _title = title;
        _priceCode = priceCode;
    }

    int getPriceCode() {
        return _priceCode;
    }

    void setPriceCode( int arg ) {
        _priceCode = arg;
    }

    string getTitle() {
        return _title;
    }

    double getRentalPrice( int numDaysRented ) {

	double thisAmount = 0;
	return thisAmount;
    }

    double getCharges(int numDaysRented) {
        double charges = 0.0;
        switch( getMovie()->getPriceCode() ) {
            case Movie::REGULAR:
                charges += 2;
                if( numDaysRented > 2 )
                    charges += ( numDaysRented - 1 ) * 1.5;
                break;
            case Movie::NEW_RELEASE:
                charges += numDaysRented * 3;
                break;
            case Movie::CHILDRENS:
                charges += 1.5;
                if( numDaysRented > 3 )
                    charges += ( numDaysRented - 3 ) * 1.5;
                break;
        }
    }

private:                                                          
    string _title;
    int _priceCode;
};

class Rental {

public:
    Rental( Movie *movie, int daysRented ) {
        _movie = movie;
        _daysRented = daysRented;
    }

    int getDaysRented() {
        return _daysRented;
    }

    Movie *getMovie() {
        return _movie;
    }
    double getCharges() {
        return getMovie()->getCharges(getDaysRented());
    }

private:
    Movie *_movie;
    int _daysRented;
};

class Customer {

public:
     Customer( string name ) {
        _name = name;
    }

    void addRental( Rental *arg ) {
        _rentals.push_back( arg );
    }

    string getName() {
        return _name;
    }

    int getFrequentRenterPoints( Rental *rental ) {
	int frequentRenterPoints = 1;
	// add bonus for a two day new relase rental
	if( rental->getMovie()->getPriceCode() == Movie::NEW_RELEASE && rental->getDaysRented() > 1 )
	    frequentRenterPoints++;
	return frequentRenterPoints;
    }

    double getTotalCharges() {
         double totalCharges = 0.0;
         for (vector<Rental *> )
     }

    string statement() {
        double totalAmount = 0;
        int frequentRenterPoints = 0;
        string result = "Rental Record for " + getName() +"\n";
        for( auto thisRental:  _rentals ) {
            // determine amount for each rental

	    frequentRenterPoints += getFrequentRenterPoints( thisRental );

            // show figures for this rental
            result += "\t" + thisRental->getMovie()->getTitle() + "\t" + doubleToString( thisAmount ) + "\n";
	    totalAmount += thisAmount;
        }

        // add footer lines
        result += "Amount owed is " +  doubleToString( totalAmount ) + "\n";
        result +=  "You earned " + to_string(frequentRenterPoints) + " frequent renter points";
        return result;
    }

private:
    string _name;
    vector<Rental *> _rentals;
};

int main( int argc, char *argv[] ) 
{
    Customer *thisCustomer = new Customer( "John Smith" );
    Movie *movie1 = new Movie( "The Departed", Movie::REGULAR );
    Rental *rental = new Rental( movie1, 4 ); 
    thisCustomer->addRental( rental );

    Movie *movie2 = new Movie( "The Imitation Game", Movie::NEW_RELEASE );
    thisCustomer->addRental( new Rental( movie2, 2 ) );
    cout <<  thisCustomer->statement() << endl;
    return 0;
}

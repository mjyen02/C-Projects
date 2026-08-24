#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    int classSeat;
    int Flight;
    int passengersCount;
    int flightOne = 0;
    int flightTwo = 0;
    
    cout << "How many passengers will be flying? ";
    cin >> passengersCount;
    
    for (int i = 1; i <= passengersCount; i++)
    {
        cout << "What Flight would Passenger #" << i << " like to take (1-2)? ";
        cin >> Flight;
        switch (Flight)
        {
            case 1:
            {
                cout << "What Class Seat? (3-5 Available) ";
                cin >> classSeat;
                switch (classSeat)
                {
                    case 1:
                    {
                        cout << "No 1st Class Seating Available." << endl;
                        i--;
                        break;
                    }
                    case 2:
                    {
                        cout << "No 2nd Class Seating Avaialale." << endl;
                        i--;
                        break;
                    }
                    case 3:
                    {
                        cout << "Passenger #" << i << " has chosen 3rd Class in Flight #1 to Miami." << endl;
                        flightOne++;
                        break;
                    }
                    case 4:
                    {
                        cout << "Passenger #" << i << " has chosen 4th Class in Flight #1 to Miami." << endl;
                        flightOne++;
                        break;
                    }
                    case 5:
                    {
                        cout << "Passenger #" << i << " has chosen 5th Class in Flight #1 to Miami." << endl;
                        flightOne++;
                        break;
                    }
                    default:
                    {
                        cout << "Invalid Option, please repeat process." << endl;
                        i--;
                        break;
                    }
                }
            cout << endl;
            break;
            }
            
            case 2:
            {
                cout << "What Class Seat? (3-5 Available) ";
                cin >> classSeat;
                switch (classSeat)
                {
                    case 1:
                    {
                        cout << "No 1st Class Seating Available." << endl;
                        i--;
                        break;
                    }
                    case 2:
                    {
                        cout << "No 2nd Class Seating Avaialale." << endl;
                        i--;
                        break;
                    }
                    case 3:
                    {
                        cout << "Passenger #" << i << " has chosen 3rd Class in Flight #2 to Los Angeles." << endl;
                        flightTwo++;
                        break;
                    }
                    case 4:
                    {
                        cout << "Passenger #" << i << " has chosen 4th Class in Flight #2 to Los Angeles." << endl;
                        flightTwo++;
                        break;
                    }
                    case 5:
                    {
                        cout << "Passenger #" << i << " has chosen 5th Class in Flight #2 to Los Angeles." << endl;
                        flightTwo++;
                        break;
                    }
                    default:
                    {
                        cout << "Invalid Option, please repeat process." << endl;
                        i--;
                        break;
                    }
                }
            cout << endl;
            break;
            }
            
            default: 
            {
                cout << "Invalid Option, please try again." << endl;
                i--;
                break;
            }
        }
    }
    cout << "In Total, we have: " << flightOne << " passenger(s) to Miami, and " << flightTwo << " passenger(s) to Los Angeles." << endl;
    
    const double pi = atan(1)*4;
    double E;
    int k = 1;
    
    cout << "What is your value of Epsilon? ";
    cin >> E;
    
    if (E <= 1.6755)
    {
        cout << fixed << setprecision(14) << sqrt(k) * (sqrt(pi/(4-pi))) * ((pow(E,2)/4) - (pow(E,4)/64) + (pow(E,6)/768));
    } else if (E > 1.6755)
    {
        cout << fixed << setprecision(14) << sqrt(k) * (sqrt(2/(4-pi))) * (E - sqrt(pi/2) + 1/(2*E) + 1/(8*pow(E,3)) + 3/(16*pow(E,5)));
    }
    
    double sum1 = 0;
    double sum2 = 0;
    int x;
    int xn = 100;
    double n = 1;
    
    cout << "What value of x? ";
    cin >> x;
    
    for (int count = 0; count < xn; count++)
    {
        for (int add = 0; add <= count; add++)
        {
            sum1 = sum1*add;
            if (add == 0)
            {
                sum1 = 1;
            }
        } 
        
        sum2 = sum2 + (pow(x,count))/sum1;
        
        if (n < 1e-12)
        {
            break;
        }
    }
    cout << fixed << setprecision(8) << "e ^ " << x << " = " << sum2 << endl;
   return 0;
}


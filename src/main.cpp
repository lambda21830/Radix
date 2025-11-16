#include <cmath>
#include <cstdlib>

#include <chrono>
#include <iomanip>
#include <ios>
#include <iostream>
#include <limits>
#include <string>
#include <thread>

using namespace std;

// Text Colors
#define NC "\033[0m" // No Color
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"

string get_os()
{
#ifdef _WIN32
    return "Windows";
#elif __APPLE__ || __MACH__
    return "Apple";
#elif __linux__
    return "Linux";
#else
    return "Other";
#endif
}

void clear_buffer()
{
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void clear_screen()
{
    get_os() == "Windows" ? system("cls") : system("clear");
}

void press_a_key_to_continue()
{
    if (get_os() == "Windows")
    {
        system("pause");
        clear_screen();
    }

    else
    {
        cout << "Premi un tasto per continuare..." << flush;
        system("read -sn 1");
        clear_screen();
    }
}

void dots()
{
    this_thread::sleep_for(chrono::milliseconds(300));

    for (int i = 0; i < 3; i++)
    {
        cout << '.' << flush;
        this_thread::sleep_for(chrono::milliseconds(300));
    }

    cout << endl;
}

bool is_valid(double number, int max_iterations, int precision)
{
    return ((number >= 0) && (max_iterations > 0) && (precision >= 0));
}

void approximate_sqrt()
{
    // Inserimento dati
    double number;
    int max_iterations;
    int precision;

    cout << "Numero: ";
    cin >> number;
    cout << "Iterazioni max: ";
    cin >> max_iterations;
    cout << "Precisione: ";
    cin >> precision;
    cout << endl;

    // Controllo correttezza input
    if (is_valid(number, max_iterations, precision))
    {
        if (number == 0)
        {
            cout << GREEN << "Radice trovata!" << NC << endl;
            cout << "Risultato: " << fixed << setprecision(precision) << 0.0 << endl;
        }

        else
        {
            const double epsilon = pow(10, -precision);
            double esteem = number;
            double previous_esteem = 0;

            for (int i = 1; i <= max_iterations; i++)
            {
                // Calcolo stima
                previous_esteem = esteem;                  // Salvataggio esteem precedente per controllo precisione decimale
                esteem = (esteem + number / esteem) / 2.0; // Convergenza esteem alla radice quadrata vera

                // Visualizzazione dati attuali
                cout << "-- Iterazione " << i << " --" << endl;
                cout << "Stima attuale: " << esteem << "\n"
                     << endl;

                // Controllo precisione decimale
                if (abs(esteem - previous_esteem) < epsilon)
                {
                    cout << YELLOW << "Precisione desiderata raggiunta" << NC << endl;
                    break;
                }

                // Controllo iterazioni max
                if (i == max_iterations)
                    cout << YELLOW << "Iterazioni max raggiunte" << NC << endl;
            }

            // Visualizzazione radice quadrata
            cout << GREEN << "Radice trovata!" << NC << endl;
            cout << "Risultato: " << fixed << setprecision(precision) << esteem << endl;
        }
    }

    else
        cout << RED << "Errore: " << NC << "Input invalido" << endl;

    press_a_key_to_continue();
}

void menu()
{
    int option;

    do
    {
        cout << "Menu" << endl;
        cout << "1. Approssima radice quadrata di un numero" << endl;
        cout << "2. Esci" << endl;
        cout << "Seleziona un'opzione: ";
        cin >> option;

        clear_buffer();
        clear_screen();

        switch (option)
        {
        case 1:
            approximate_sqrt();
            break;

        case 2:
            cout << "Uscita in corso" << flush;
            dots();
            break;

        default:
            cerr << RED << "Errore: " << NC "Opzione invalida" << endl;
            press_a_key_to_continue();
            break;
        }
    } while (option != 2);
}

int main(int argc, char *argv[])
{
    if (get_os() == "Other")
    {
        cerr << RED << "Errore: " << NC << "Sistema operativo non supportato" << endl;
        return 1;
    }

    menu();

    return 0;
}
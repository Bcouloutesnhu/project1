
#include <iostream>  // For standard input-output
#include <cstdio>     // For printf
using namespace std;

// Class to manage Time
class Time {
public:
    int h1, h2, m1, m2, s1, s2; // h: hour, m: minute, s: second

    // Default constructor initializing 12-hour and 24-hour clocks
    Time() {
        h1 = 12; h2 = 0;
        m1 = 0;  m2 = 0;
        s1 = 0;  s2 = 0;
    }

    // Helper function to manage time (convert 60 seconds to 1 minute)
    void manageTime(int clockType = 1) {
        if (clockType == 1) {
            s1 %= 60; m1 += s1 / 60;
            m1 %= 60; h1 += m1 / 60;
            h1 %= 12; h1 = (h1 == 0) ? 12 : h1;
        }
        if (clockType == 2) {
            s2 %= 60; m2 += s2 / 60;
            m2 %= 60; h2 += m2 / 60;
            h2 %= 24;
        }
    }

    // Function to add 1 second to both clocks
    void addSecond() {
        s1++; s2++;
        manageTime(1);
        manageTime(2);
    }

    // Function to wait 1 second 
    void waitSecond() {
        addSecond();
    }

    // Function to add 1 minute to both clocks
    void addMinute() {
        m1++; m2++;
        manageTime(1);
        manageTime(2);
    }

    // Function to add 1 hour to both clocks
    void addHour() {
        h1++; h2++;
        manageTime(1);
        manageTime(2);
    }

    // Function to display both clocks
    void display() {
        printf("\nTime 1: %02d:%02d:%02d\n", h1, m1, s1);
        printf("Time 2: %02d:%02d:%02d\n\n", h2, m2, s2);
    }
};

int main() {
    Time t;
    int p, n, m, f = 1;

    // Main menu loop
    while (f > 0) {
        t.display();
        cout << "Press Button? (1:yes, 2:no): ";
        cin >> p;

        if (p == 1) {
            cout << "Choose option\n1. Add Time\n2. EXIT\nEnter 1 or 2: ";
            cin >> n;

            if (n == 1) {
                cout << "Choose option\n1. Add 1 hour\n2. Add 1 minute\n3. Add 1 second\nEnter 1 or 2 or 3: ";
                cin >> m;

                switch (m) {
                    case 1: t.addHour(); break;
                    case 2: t.addMinute(); break;
                    case 3: t.addSecond(); break;
                }
            }
            if (n == 2) {
                f = -1; // Exit the loop
                exit;
            }
        } else if (p == 2) {
            // Add one second and wait for a second 
            t.addSecond();
            t.waitSecond();
        }
    }
    return 0;
}

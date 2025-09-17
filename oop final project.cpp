#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct DailyLog {
    string date;
    string skinCondition;
    string productUsed;
    string productUsage;
    string progressPhoto;
};

string username, password;
vector<DailyLog> logs;

void signUp() {
    cout << "\n--- Sign Up ---\n";
    cout << "Create username: ";
    cin >> username;
    cout << "Create password: ";
    cin >> password;
    cout << "Sign up successful!\n";
}

bool login() {
    cout << "\n--- Login ---\n";
    string u, p;
    cout << "Enter username: ";
    cin >> u;
    cout << "Enter password: ";
    cin >> p;
    if (u == username && p == password) {
        cout << "Login successful!\n";
        return true;
    } else {
        cout << "Invalid credentials.\n";
        return false;
    }
}

class Skin {
public:
    virtual void checkSkinType(string problem1, string problem2) = 0;
};

class Analyzer : public Skin {
public:
    void checkSkinType(string problem1, string problem2) override {
        int dry = 0, oily = 0, sens = 0;

        if (problem1 == "dry" || problem2 == "dry")
            dry++;
        if (problem1 == "oily" || problem2 == "oily" || problem1 == "pimples" || problem2 == "pimples")
            oily++;
        if (problem1 == "itch" || problem2 == "itch")
            sens++;

        cout << "\nAnalyzing your skin type...\n";
        if (dry > oily && dry > sens)
            cout << "Your skin type is: Dry\n";
        else if (oily > dry && oily > sens)
            cout << "Your skin type is: Oily\n";
        else if (sens > dry && sens > oily)
            cout << "Your skin type is: Sensitive\n";
        else
            cout << "Your skin type is: Normal\n";
    }
};

class Routine {
public:
    void showRoutine(string type) {
        cout << "\n=== Personalized Skincare Routine ===\n";
        if (type == "Dry") {
            cout << "Morning: Gentle hydrating cleanser + Rich moisturizer + Sunscreen\n";
            cout << "Evening: Moisturizing cleanser + Hyaluronic acid serum + Night cream\n";
        }
        else if (type == "Oily") {
            cout << "Morning: Oil-control cleanser + Lightweight moisturizer + Matte sunscreen\n";
            cout << "Evening: Foaming cleanser + Salicylic acid toner + Oil-free gel cream\n";
        }
        else if (type == "Sensitive") {
            cout << "Morning: Fragrance-free cleanser + Calming moisturizer + Mineral sunscreen\n";
            cout << "Evening: Mild cleanser + Soothing serum (e.g. aloe vera) + Barrier cream\n";
        }
        else if (type == "Normal") {
            cout << "Morning: Gentle cleanser + Lightweight moisturizer + Sunscreen\n";
            cout << "Evening: Cleanser + Nourishing serum + Moisturizer\n";
        }
        else {
            cout << "Invalid input. Please enter Dry/Oily/Sensitive/Normal\n";
        }
    }
};

class Remedy {
public:
    void showRemedy(string type) {
        cout << "\n=== Recommendations ===\n";
        if (type == "Dry") {
            cout << "- Use a good moisturizer daily\n";
            cout << "- Drink more water\n";
            cout << "- Avoid hot water on face\n";
        }
        else if (type == "Oily") {
            cout << "- Use oil-free face wash\n";
            cout << "- Wash face twice a day\n";
            cout << "- Avoid heavy creams\n";
        }
        else if (type == "Sensitive") {
            cout << "- Use gentle fragrance-free products\n";
            cout << "- Avoid too much sun exposure\n";
            cout << "- Always patch test new products\n";
        }
        else if (type == "Normal") {
            cout << "- Maintain a simple routine\n";
            cout << "- Cleanse and moisturize daily\n";
            cout << "- Use sunscreen regularly\n";
        }
        else {
            cout << "- Invalid input, please enter Dry/Oily/Sensitive/Normal\n";
        }
    }
};

class Doctor {
public:
    void prescribe(string type) {
        cout << "\n=== Doctor's Prescription ===\n";
        if (type == "Dry") {
            cout << "Doctor Suggests:\n";
            cout << "- Hydrating Cream (e.g. Cetaphil / CeraVe)\n";
            cout << "- Vitamin E capsules (once a day)\n";
            cout << "- Drink at least 8 glasses of water daily\n";
            cout << "- Avoid very hot showers\n";
        }
        else if (type == "Oily") {
            cout << "Doctor Suggests:\n";
            cout << "- Oil-free Face Wash (e.g. Neutrogena)\n";
            cout << "- Use Salicylic Acid serum at night\n";
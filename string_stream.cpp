#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int main() {
    // 1. Parsing Comma Separated Values (CSV)
    cout << "Parsing CSV:\n";
    string csv = "10,20,30,40";
    stringstream ss(csv);
    string value;
    vector<int> numbers;
    while (getline(ss, value, ',')) { // Extract each value using ',' as delimiter
        numbers.push_back(stoi(value)); // Convert string to int and store in vector
    }
    for (int num : numbers) cout << num << " ";
    cout << "\n\n";

    // 2. Resetting/Reusing stringstream
    cout << "Resetting/Reusing stringstream:\n";
    stringstream s;
    s << "first use";
    string temp;
    s >> temp;
    cout << "First: " << temp << endl;

    s.clear();      // Clear any error flags (e.g., eof)
    s.str("");      // Clear the content
    s << "second use";
    s >> temp;
    cout << "Second: " << temp << "\n\n";

    // 3. Extracting Multiple Types from a string
    cout << "Extracting Multiple Types:\n";
    string mixed = "42 3.14 Hello";
    stringstream sm(mixed);
    int intVal;
    double dblVal;
    string word;
    sm >> intVal >> dblVal >> word; // Extract integer, double and string
    cout << "Integer: " << intVal << "\nDouble: " << dblVal << "\nString: " << word << "\n\n";

    // 4. Using stringstream to Build Strings Efficiently
    cout << "Using stringstream to Build Strings:\n";
    int a = 5, b = 10;
    stringstream builder;
    builder << "Sum of " << a << " and " << b << " is " << (a + b); // Concatenate without +
    string result = builder.str(); // Get the final string
    cout << result << "\n\n";

    // 5. Advanced: Competitive Programming - Split space-separated input
    cout << "Splitting Space-Separated Input:\n";
    string input = "100 200 300 400";
    stringstream cp(input);
    vector<int> arr;
    int num;
    while (cp >> num) arr.push_back(num); // Extract integers efficiently
    for (int i : arr) cout << i << " ";
    cout << "\n";

    return 0;
}

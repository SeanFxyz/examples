/*
 * Example usage of stringstreams by Sean Fitzgerald
 * smf166@humboldt.edu
 *
 * This code is released into the public domain.
 */

#include <iostream>
#include <string>
#include <sstream> // string stream library

using namespace std;

/*
 * The `istringstream` and `ostringstream` classes lets us read or write to
 * strings the same way we use streams like `cout` and `cin`.
 */

int main()
{
    // Create an ostringstream digits_sstream.
    ostringstream digits_ostream;

    // Let's make a string listing all the digits.
    for (int i = 0; i < 10; i++)
    {
        digits_ostream << i << ' ';
        // Note: unlike using the `+` operator to concatenate strings, here
        // we can output many different data types using the `<<` operator,
        // just like `cout`.
        // If `output` was a string, we'd have to convert i to a string
        // and concatenate it.
    }

    // We can get the contents as a normal string using the `str()` method.
    string output_str = digits_ostream.str();
    cout << "The digits: " << output_str << endl;



    // We can using an istringstream to read from a string just like like
    // we read from cin.
    cout << "Trying out istringstream..." << endl;

    // Say we have acquired a long string full of space-separated words:
    string word_source = "cargo daisy dog examine roam vainglorious";

    // Let's make an array to load these words into:
    string word_array[20]; // Make sure it's big enough to hold all the words!

    // Then, make an istringstream from our word source:
    istringstream word_istream(word_source);

    int i = 0;
    while (word_istream.eof() == false)
    {
        // By default, input streams read one word at a time.
        word_istream >> word_array[i]; // Reads one word into array position i

        cout << "Added word \"" << word_array[i] << "\" to array." << endl;
        i++;
    }
}

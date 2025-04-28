/******************************************************************************

Rebecca Fernandez's Local LLM Persistent Memory Prototype

Contacts
Email: rfernan2@ramapo.edu
LinkedIn: www.linkedin.com/in/rebeccafernandez935

*******************************************************************************/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Helper function to escape quotes in JSON strings
string escapeJson(const string& input) {
    string output;
    for (char c : input) {
        if (c == '\"') output += "\\\"";
        else output += c;
    }
    return output;
}

int main() {
    ofstream file("chat_history.json", ios::app); // Open in append mode
    if (!file.is_open()) {
        cerr << "Failed to open chat_history.json for writing." << endl;
        return 1;
    }

    cout << "Welcome to the Persistent Memory Chat Prototype (Live Append Version)!" << endl;
    cout << "Type 'exit' to end the session." << endl << endl;

    string userInput;
    while (true) {
        cout << "You: ";
        getline(cin, userInput);

        if (userInput == "exit") {
            break;
        }

        string botResponse = "Simulated response to: " + userInput;

        cout << "Bot: " << botResponse << endl;

        // Save interaction immediately
        file << "{ \"user\": \"" << escapeJson(userInput) << "\", \"bot\": \"" << escapeJson(botResponse) << "\" },\n";
    }

    file.close();
    cout << endl << "Session ended. Chat history saved live to 'chat_history.json'." << endl;

    return 0;
}

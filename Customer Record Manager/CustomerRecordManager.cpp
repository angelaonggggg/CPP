#include <vector>
#include <sstream>
#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Function to split string based on delimited and return a vector of tokens
vector<string> splitString(string str, string delimiter)
{
    vector <string> result;
    size_t pos = 0;
    string token;
    
    // Iterate over the string until delimiter is found
    while ((pos = str.find(delimiter))!= std::string::npos)
    {
        token = str.substr(0,pos);
        result.push_back(token);
        str.erase(0, pos+delimiter.length());
    }
    if (!str.empty())
        result.push_back(str);
    return(result);
}

// Template function to convert a string to a primitive data type
template<typename T>
T strToPrimitive(string input) {
    istringstream iss(input);
    T output;
    iss >> output;
    return output;
}

struct Address{
    bool isCondominium;
    string street, postalCode, unitNumber;
    int floorLevel;
};

struct Customer{
    string name, occupation;
    struct Address address;
    string toString()
    {
        // Format the string
        ostringstream oss;
        oss << setw(15) << left << "Name" << ": " << name << endl;
        oss << setw(15) << left << "Occupation" << ": " << occupation << endl;
        oss << setw(15) << left << "Address" << ": " << endl;
        if (address.isCondominium)
        {
            oss << "\tStreet : " << address.street << ", Postal : " << address.postalCode << endl;
        }
        else 
        {
            oss << "\tFloor  : " << address.floorLevel << ", Unit : " << address.unitNumber << endl;
            oss << "\tStreet : " << address.street << ", Postal : " << address.postalCode << endl;
        }
        return oss.str();
    }
};

typedef struct Customer CustomerType;

// Function to read and store customer records from a file
vector <CustomerType> readAndStoreCustomerRecords (string filename)
{
    string line = "";
    ifstream fin(filename);
vector<CustomerType> result;
    // ignore the first line
    fin.ignore(100, '\n');
    // Loop until the end of file
    while(!fin.eof()) 
    {
        CustomerType c;
        // reads a line of input from the file stream fin 
        // stores it in the string variable line
        getline(fin, line);
        vector<string> container = splitString(line, ",");
        
        c.name = container[0];
        c.occupation = container[1];
        c.address.isCondominium = strToPrimitive<string>(container[2]) == "TRUE"? true: false;
        if(c.address.isCondominium)
        {
            c.address.street = container[3];
            c.address.postalCode = container[4];
        }
        else 
        {
            c.address.street = container[3];
            c.address.postalCode = container[4];
            c.address.floorLevel = strToPrimitive<int>(container[5]);
            c.address.unitNumber = container[6];
        }
        // Add customer to result vector
        result.push_back(c);
    }
    return result;
}

int main() {
     string filename;
    bool fileExists = false;

    while (!fileExists) {
        // Prompt the user to input the filename
        cout << "Enter the filename: ";
        cin >> filename;

        // Check if the file exists
        ifstream file(filename);
        if (!file.is_open()) {
            cout << "File '" << filename << "' does not exist. Please try again." << endl;
            cout << endl;
        } 
        else {
            fileExists = true;
            file.close(); // Close the file stream

            cout << endl;
            vector<CustomerType> custRecs = readAndStoreCustomerRecords (filename);
            
            // this will print out Customer #1
            for (int i = 0; i < custRecs.size(); i++)
            {
                cout << "Customer #" << i+1 << endl;
                cout << custRecs[i].toString() << endl;
            }
        }
    }
    return 0;
}

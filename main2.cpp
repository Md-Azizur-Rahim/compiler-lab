#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

bool isKeyword(string word)
{
    if (word == "int" || word == "return" || word == "cout")
        return true;
    return false;
}

bool isOperator(string word)
{
    if (word == "=" || word == "+" || word == "-" ||
        word == "*" || word == "/" || word == "<<")

        return true;

    return false;
}

bool isNumber(string word)
{
    for (int i = 0; i < word.length(); i++)
    {
        if (word[i] < '0' || word[i] > '9')
            return false;
    }
    return true;
}

int main()
{
    ifstream file("code.txt");
    string line;

    if (!file)
    {
        cout << "File not found!\n";
        return 0;
    }

    cout << "File Content:\n\n";

    while (getline(file, line))
    {

        cout << line << endl;

        stringstream ss(line);
        string word;

        while (ss >> word)


        {

            if (isKeyword(word))
                cout << "Keyword: " << word << endl;


            else if (isOperator(word))
                cout << "Operator: " << word << endl;


            else if (isNumber(word))
                cout << "Number: " << word << endl;



            else if (word == "{" || word == "}" || word == "(" || word == ")" || word == ";")
                cout << "Symbol: " << word << endl;



            else
                cout << "Identifier: " << word << endl;


        }
    }

    file.close();
    return 0;
}

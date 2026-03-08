#include <iostream>
#include <string>
using namespace std;

void checknumeric(string s)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] < '0' || s[i] > '9')
        {
            cout << "Not numeric\n";
            return;
        }
    }

    if (s.length() > 0)
        cout << "Numeric constant......\n";
    else
        cout << "Not numeric........\n";
}

void checkoperator(string s)
{
    bool found = false;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '%' || s[i] == '=')
        {
            cout << "Operator: " << s[i] << endl;
            found = true;
        }
    }

    if (!found)
        cout << "No operator found.......\n";
}

void checkComment(string input)
{
    if (input.length() >= 2 && input[0] == '/' && input[1] == '/')
    {
        cout << "Single line comment.........\n";
    }
    else if (input.length() >= 4 &&
             input[0] == '/' && input[1] == '*' &&
             input[input.length() - 2] == '*' &&
             input[input.length() - 1] == '/')
    {
        cout << "Multi line comment......\n";
    }
    else
    {
        cout << "Not a comment......\n";
    }
}

void checkIdentifier(string s)
{
    if (s.length() == 0)
    {
        cout << "Not an Identifier\n";
        return;
    }


    if (!((s[0] >= 'A' && s[0] <= 'Z') ||
          (s[0] >= 'a' && s[0] <= 'z') ||
           s[0] == '_'))
    {
        cout << "Not an Identifier\n";
        return;
    }

    for (int i = 1; i < s.length(); i++)
    {
        if (!((s[i] >= 'A' && s[i] <= 'Z') ||
              (s[i] >= 'a' && s[i] <= 'z') ||
              (s[i] >= '0' && s[i] <= '9') ||
               s[i] == '_'))
        {
            cout << "Not an Identifier\n";
            return;
        }
    }

    cout << "Valid Identifier\n";
}

int main()
{
    string input;

    cout << "Enter your text: ";
    getline(cin, input);

    cout << "\n=== Check Results ===\n";

    checknumeric(input);
    checkoperator(input);
    checkComment(input);
     checkIdentifier(input);

    return 0;
}

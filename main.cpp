#include<iostream>
#include<string>
#include<vector>
#include<sstream>

using namespace std;

enum TokenType
{
    GET,
    SET,
    GO,
    EQUAL,
    VARIABLE,
    NUMERIC,
    END,
    INVALID
};

class Token
{
    private:
        TokenType type;
        string value;

    public:
        Token(TokenType typ, string val) : type(typ), value(val){};

        friend void parser(const vector<Token> &input_tokens);
};

bool isAlpha(const string &str)
{
    for (char ch : str)
    {
        if (!isalpha(ch))
        {
            return false;
        }
    }
    return true;
}

bool isNumeric(const string &str)
{
    for (char ch : str)
    {
        if (!isdigit(ch))
        {
            return false;
        }
    }
    return true;
}

vector<Token> lexer(string input)
{
    vector<Token> tokens;
    istringstream iss(input);
    string word;

    while(iss >> word)
    {
        if(word == "GET")
        {
            tokens.emplace_back(Token(GET, "GET"));
        }
        else if(word == "SET")
        {
            tokens.emplace_back(Token(SET, "SET"));
        }
        else if(word == "GO")
        {
            tokens.emplace_back(Token(GO, "GO"));
        }
        else if(isNumeric(word))
        {
            tokens.emplace_back(Token(NUMERIC, word));
        }
        else if(word == "END")
        {
            tokens.emplace_back(Token(END, "END"));
        }
        else if(word == "=")
        {
            tokens.emplace_back(Token(EQUAL, "="));
        }
        else if(isAlpha(word))
        {
            tokens.emplace_back(Token(VARIABLE, word));
        }
        else
        {
            tokens.emplace_back(Token(INVALID, word));
        }
    }

    return tokens;
}

int main()
{
    return 0;
}
#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<map>

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
        Token(TokenType type, string value) : type(type), value(value){};

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

map<string, int> variables;
bool interpreter_running = true;
void parser(const vector<Token> &input_tokens)
{
    for(auto itr = input_tokens.begin(); itr != input_tokens.end(); ++itr)
    {
        switch ((*itr).type)
        {
            case GET:
                if((*(itr + 1)).type == VARIABLE)
                {
                    cout << ": ";
                    string input_line;
                    getline(cin, input_line);
                    stringstream(input_line) >> variables[(*(itr + 1)).value];
                }
                
                break;

            case SET:
                if((*(itr + 1)).type == VARIABLE && (*(itr + 2)).type == EQUAL && (*(itr + 3)).type == NUMERIC)
                {
                    variables[(*(itr + 1)).value] = stoi((*(itr + 3)).value);
                }

                break;

            case GO:
                if((*(itr + 1)).type == VARIABLE)
                {
                    cout << variables[(*(itr + 1)).value] << endl;
                }

                break;
                
            case INVALID:
                break;

            case END:
                interpreter_running = false;

                break;

            default:
                break;
        }
    }
}

int main()
{
    while(interpreter_running)
    {
        string input;
        char ch;
        cout << ">>> ";

        while((ch = cin.get()) != '\n')
        {
            input += ch;
        }

        parser(lexer(input));
        input = "";
    }

    return 0;
}
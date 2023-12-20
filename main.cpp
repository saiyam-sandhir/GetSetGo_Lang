#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<map>
#include<getsetgo_tokens.h>

using namespace std;
using namespace GetSetGo_Tokens;

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
            tokens.emplace_back(Command(GET));
        }
        else if(word == "SET")
        {
            tokens.emplace_back(Command(SET));
        }
        else if(word == "GO")
        {
            tokens.emplace_back(Command(GO));
        }
        else if(word == "HURDLE")
        {
            tokens.emplace_back(Command(HURDLE));
        }
        else if(word == "NEXT_HURDLE")
        {
            tokens.emplace_back(Command(NEXT_HURDLE));
        }
        else if(word == "LAST_HURDLE")
        {
            tokens.emplace_back(Command(LAST_HURDLE));
        }
        else if(word == "SKIP_PRACTICE")
        {
            tokens.emplace_back(Command(SKIP_PRACTICE));
        }
        else if(word == "LAST_PRACTICE")
        {
            tokens.emplace_back(Command(STOP_PRACTICE));
        }
        else if(word == "END")
        {
            tokens.emplace_back(Command(END));
        }
        else if(is_identifier(word))
        {
            tokens.emplace_back(Identifier(word, VARIABLE));
        }
        else if(isNumericLiteral(word))
        {
            tokens.emplace_back(Literal(word, NUMERIC));
        }
        else if(isStringLiteral(word))
        {
            tokens.emplace_back(Literal(word, STRING));
        }
        else if(isCharLiteral(word))
        {
            tokens.emplace_back(Literal(word, CHAR));
        }
        else if(word == "+")
        {
            tokens.emplace_back(Operator('+', NUMERIC_OP));
        }
        else if(word == "-")
        {
            tokens.emplace_back(Operator('-', NUMERIC_OP));
        }
        else if(word == "*")
        {
            tokens.emplace_back(Operator('*', NUMERIC_OP));
        }
        else if(word == "/")
        {
            tokens.emplace_back(Operator('/', NUMERIC_OP));
        }
        else if(word == "%")
        {
            tokens.emplace_back(Operator('%', STRING_OP));
        }
        else if(word == "&")
        {
            tokens.emplace_back(Operator('&', BOOLEAN_OP));
        }
        else if(word == "|")
        {
            tokens.emplace_back(Operator('|', BOOLEAN_OP));
        }
        else if(word == "~")
        {
            tokens.emplace_back(Operator('~', BOOLEAN_OP));
        }
        else if(word == "...")
        {
            tokens.emplace_back(Delimiter(ELIPSES));
        }
        else if(word == "(")
        {
            tokens.emplace_back(Delimiter(LEFT_PAREN));
        }
        else if(word == ")")
        {
            tokens.emplace_back(Delimiter(RIGHT_PAREN));
        }
        else if(word == "#")
        {
            tokens.emplace_back(Delimiter(HASH_TAG));
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
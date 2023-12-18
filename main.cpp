#include<iostream>
#include<vector>

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

int main()
{
    return 0;
}
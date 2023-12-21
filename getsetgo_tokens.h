#ifndef GETSETGO_TOKENS_H
#define GETSETGO_TOKENS_H

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

namespace GetSetGo_Tokens
{
    enum TokenType
    {
        KEYWORD,
        IDENTIFIER,
        LITERAL,
        OPERATOR,
        DELIMITER,
        COMMENT
    };

    class Token
    {
    protected:
        TokenType m_token_type;

    public:
        friend ostream &operator<<(ostream &out, const Token &tk)
        {
            out << tk.m_token_type;
            return out;
        }
    };

    enum KeywordType
    {
        COMMAND,
        FOUL,           // false
        SCORE,          // true
        TEAMWORK,       // &&
        COLLABORATION,  // ||
        OPPOSITION      // !
    };

    class Keyword : public Token
    {
    private:
        KeywordType m_keyword_type;

    public:
        Keyword(KeywordType m_keyword_type) : m_keyword_type(m_keyword_type)
        {
            m_token_type = KEYWORD;
        }
    };

    enum CommandType
    {
        GET,           // for getting input from the user
        SET,           // for initializing a variable for a function
        GO,            // print
        HURDLE,        // if
        NEXT_HURDLE,   // else if
        LAST_HURDLE,   // else
        SKIP_PRACTICE, // continue
        STOP_PRACTICE, // break
        END            // close interpreter
    };

    class Command : public Token
    {
    private:
        CommandType m_cmd_type;

    public:
        Command(CommandType m_cmd_type) : m_cmd_type(m_cmd_type)
        {
            m_token_type = KEYWORD;
        }
    };

    enum IdentifierType
    {
        VARIABLE,
        FUNCTION
    };

    class Identifier : public Token
    {
    private:
        const string m_name;
        IdentifierType m_identifier_type;

    public:
        Identifier(const string &m_name, IdentifierType m_identifier_type) : m_name(m_name), m_identifier_type(m_identifier_type)
        {
            m_token_type = IDENTIFIER;
        }
    };

    bool is_identifier(const string &word)
    {
        if (!isalpha(word[0]) && word[0] != '_')
        {
            return false;
        }

        for (char c : word)
        {
            if (!isalnum(c) && c != '_')
            {
                return false;
            }
        }

        return true;
    }

    enum LiteralType
    {
        NUMERIC,
        STRING,
        CHAR,
        BOOLEAN
    };

    class Literal : public Token
    {
    private:
        LiteralType m_literal_type;
        string m_literal_value;

    public:
        Literal(const string &m_literal_value, LiteralType m_literal_type) : m_literal_value(m_literal_value), m_literal_type(m_literal_type)
        {
            m_token_type = LITERAL;
        }
    };

    bool isNumeric(const std::string &str)
    {
        for (char c : str)
        {
            if (!isdigit(c))
            {
                return false;
            }
        }
        return true;
    }

    bool isNumericLiteral(const string &word)
    {
        return isNumeric(word);
    }

    bool isStringLiteral(const string &word)
    {
        return (word.size() >= 2 && word[0] == '"' && word[word.length() - 1] == '"');
    }

    bool isCharLiteral(const string &word)
    {
        return (word.size() >= 3 && word[0] == '\'' && word[word.length() - 1] == '\'' && word[1] == word[word.length() - 2]);
    }

    enum OperatorType
    {
        NUMERIC_OP,
        STRING_OP,
        BOOLEAN_OP,
        GENERIC_OP
    };

    class Operator : public Token
    {
    private:
        OperatorType m_operator_type;
        char op;

    public:
        Operator(char op, OperatorType m_operator_type) : op(op), m_operator_type(m_operator_type)
        {
            m_token_type = OPERATOR;
        }
    };

    enum DelimiterType
    {
        ELIPSES,
        LEFT_PAREN,
        RIGHT_PAREN,
        HASH_TAG
    };

    class Delimiter : public Token
    {
    private:
        DelimiterType m_delimiter_type;

    public:
        Delimiter(DelimiterType m_delimiter_type) : m_delimiter_type(m_delimiter_type)
        {
            m_token_type = DELIMITER;
        }
    };

    class Comment : public Token
    {
    public:
        Comment()
        {
            m_token_type = COMMENT;
        }
    };
}

#endif
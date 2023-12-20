#ifndef GETSETGO_TOKENS_H
#define GETSETGO_TOKENS_H

namespace GetSetGo_Tokens
{
    enum TokenType
    {
        KEYWORD,
        COMMAND,
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
    };



    enum KeywordType
    {
        COMMAND,
        FOUL, //false
        SCORE, //true
        TEAMWORK, //&&
        COLLABORATION, //||
        OPPOSITION, //!
    };

    class Keyword : private Token
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
        GET, //for getting input from the user
        SET, //for initializing a variable for a function
        GO, //print
        HURDLE, //if
        NEXT_HURDLE, //else if
        LAST_HURDLE, //else
        SKIP_PRACTICE, //continue
        STOP_PRACTICE, //break
        END //close interpreter
    };

    class Command : private Token
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

    class Identifier : private Token
    {
        private:
            const string m_name, m_identifier_type;

        public:
            Identifier(string m_name, IdentifierType m_identifer_type) : m_name(m_name), m_identifier_type(m_identifier_type)
            {
                m_token_type = IDENTIFIER;
            }
    };

    bool is_identifier(string word)
    {
        if (!isalpha(word[0]) && word[0] != '_') 
        {
            return false;
        }

        bool is_func = false;
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

    class Literal : private Token
    {
        private:
            LiteralType m_literal_type;
            string m_literal_value;

        public:
            Literal(string m_literal_value, LiteralType m_literal_type) : m_literal_value(m_literal_value), m_literal_type(m_literal_type)
            {
                m_token_type = LITERAL;
            }
    };

    bool isNumericLiteral(string word)
    {
        if(isNumeric(word))
        {
            return true;
        }

        return false;
    }
    
    bool isStringLiteral(string word)
    {
        if(word[0] == '"' && word[-1] == '"')
        {
            return true;
        }

        return false;
    }

    bool isCharLiteral(string word)
    {
        if(word[0] == '\'' && word[-1] == '\'' && word[1] == word[-2])
        {
            return true;
        }

        return false;
    }



    enum OperatorType
    {
        NUMERIC_OP,
        STRING_OP,
        BOOLEAN_OP
    };

    class Operator : private Token
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

    class Delimiter : private Token
    {
        private:
            DelimiterType m_delimiter_type;

        public:
            Delimiter(DelimiterType m_delimiter_type) : m_delimiter_type(m_delimiter_type)
            {
                m_token_type = DELIMITER;
            }
    };


    class Comment : private Token
    {
        public:
            Comment()
            {
                m_token_type = COMMENT;
            }
    };
}

#endif
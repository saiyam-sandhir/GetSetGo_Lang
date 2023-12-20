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
            Keyword()
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
            Command()
            {
                m_token_type = KEYWORD;
            }
    };



    class Identifier : private Token
    {
        private:
            const char *m_name, *m_value;

        public:
            Identifier()
            {
                m_token_type = IDENTIFIER;
            }
    };



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

        public:
            Literal()
            {
                m_token_type = LITERAL;
            }
    };



    enum OperatorType
    {
        NUMERIC,
        STRING,
        BOOLEAN
    };

    class Operator : private Token
    {
        private:
            OperatorType m_operator_type;

        public:
            Operator()
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
            Delimiter()
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
# GetSetGo Programming Language

## Introduction

Hey there, welcome to the official documentation for GetSetGo, an early-stage programming language created by Saiyam Jain as an experimental project. GetSetGo is licensed under the MIT License, and it was developed to gain hands-on experience with C++, parsers, lexers, and interpreters.

### Motivation and Origin

My journey with GetSetGo began during my exploration of programming challenges on platforms like HackerRank. It was during this time that I encountered the fascinating concept of parsers, igniting the idea to embark on the creation of an experimental programming language.

The initial spark for building an interpreter came from a project involving the Morse code language. As I delved deeper into the concepts of lexers and parsers during this Morse code project, the decision was made to take on the challenge of creating a unique programming language from scratch.

The primary motivation behind GetSetGo is to serve as a personal learning tool, providing enthusiasts and learners alike with an opportunity to explore the intricacies of language design, parsing, and interpretation.

Feel free to delve into the documentation to discover the features, syntax, and capabilities of GetSetGo. Whether you're a programming novice or an experienced developer, I hope GetSetGo sparks your curiosity and provides valuable insights into the world of programming language implementation.

## Table of Contents

- [GetSetGo Programming Language](#getsetgo-programming-language)
  - [Introduction](#introduction)
    - [Motivation and Origin](#motivation-and-origin)
  - [Table of Contents](#table-of-contents)
  - [Getting Started](#getting-started)
    - [Overview](#overview)
  - [Language Basics](#language-basics)
    - [Tokens](#tokens)
    - [Variables](#variables)
    - [Input/Output](#inputoutput)
  - [Examples](#examples)
    - [Example 1: Simple Program](#example-1-simple-program)
    - [Example 2: User Input](#example-2-user-input)
  - [Contributing](#contributing)
  - [License](#license)

## Getting Started

The current version of GetSetGo is designed to run through a shell. You can execute GetSetGo scripts by entering commands interactively. For example:

```markdown
>>> SET my_variable = 10
>>> GO my_variable
10
>>> END
```

### Overview

GetSetGo is a simple programming language with a limited set of commands:

- `GET`: Input command to read user input.
- `SET`: Variable declaration command to assign values to variables.
- `GO`: Output command to print the value of variables.
- `END`: Termination command to exit the interpreter.

The current version of GetSetGo operates primarily through a shell, allowing you to interact with the interpreter through the command line.

## Language Basics

### Tokens

GetSetGo recognizes the following tokens:

- `GET`: Input command.
- `SET`: Variable assignment command.
- `GO`: Output command.
- `EQUAL`: Assignment operator.
- `VARIABLE`: Variable identifier.
- `NUMERIC`: Numeric value.
- `END`: Termination command.
- `INVALID`: Invalid token.

### Variables

Variables are used to store and manipulate data. They must start with an alphabetic character and can contain only alphabetic characters.

```markdown
>>> SET x = 10
>>> GO x
```

### Input/Output

Use `GET` for user input and `GO` for output:

```markdown
>>> GET X
: 5
>>> GO X
5
```

## Examples

### Example 1: Simple Program

```markdown
>>> SET y = 10
>>> GO y
10
```

### Example 2: User Input

```markdown
>>> GET x
: 10
>>> SET y = 6 GO x GO y
10
6
```

## Contributing

Feel welcomed to contribute to the GetSetGo Language! Contact me using the repository discussions.

## License

GetSetGo is licensed under the MIT License. Feel free to use, modify, and share the language!

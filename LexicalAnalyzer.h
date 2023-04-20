#include<fstream>

typedef std::ifstream READER;
typedef char CHAR_BUFF;
typedef int Signed_DEC;

struct AnalyzerData
{
    // List of keywords in c++17
    const char keywords[85][17] = { "auto","break","case","char","const","continue","default",
        "do","double","else","enum","extern","float","for","goto",
        "if","int","long","register","return","short","signed",
        "sizeof","static","struct","switch","typedef","union",
        "unsigned","void","volatile","while", "alignas", "decltype",
        "namespace", "struct", "alignof", "new", "and", "delete", "noexcept",
        "template", "and_eq", "not", "this", "asm", "not_eq", "thread_local",
        "dynamic_cast", "nullptr", "throw", "bitand", "operator", "true",
        "bitor", "or", "try", "bool", "explicit", "or_eq", "export", "private",
        "typeid", "protected", "typename", "catch", "false", "public", "char16_t",
        "reinterpret_cast", "using", "char32_t", "friend", "virtual", "class",
        "compl", "inline", "wchar_t", "constexpr", "const_cast", "static_assertxor",
        "mutable", "static_cast", "xor_eq", "std"};

    // Commonly used Arithmetic Operators
    const char operators[7] = "+-*/%=";
};

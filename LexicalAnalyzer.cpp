#include<stdio.h>   // For Printf
#include<string.h>  // For strcmp
#include"LexicalAnalyzer.h"    // For Keywords and Operators

const AnalyzerData Data;

extern "C" { 
    bool isKeyword(char[]);
    bool isOperator(char);
    void isAlphaNumeric(char, char (&)[15], int &, int &);
}

int main(int argc, char* argv[]) {
    /* Initializing Needed Variables */
    CHAR_BUFF character{}, buffer[15]{};
    READER lexical_file_obj;

    Signed_DEC count{ 1 }, jumper_index{ 0 };

    for (Signed_DEC arg_index = 1; arg_index < argc; arg_index++) {
        printf("\n\nAnalyzing File (%s)\n\n", argv[arg_index]);
        printf("Lexeme \t Token\n\n");

        /* open file*/
        lexical_file_obj.open(argv[arg_index], std::ios::in);

        /* check if the file is opened */
        if (lexical_file_obj.is_open()) {

            /* continue reading untill the end of file */
            while (!lexical_file_obj.eof()) {

                /* Read characters from file_obj */
                character = lexical_file_obj.get();

                if (isOperator(character))
                {
                    continue;
                }

                isAlphaNumeric(character, buffer, jumper_index, count);
            }
        }
        /* File obj is not created */
        else {
            printf("Could't open file\n");
        }

        /* close the lexical_file_obj */
        lexical_file_obj.close();
    }

    return 0;
}


bool isKeyword(char buffer[]) {

    /* looping through list of keywords */
    for (int key = 0; key < 85; ++key) {
        /* return 0 if both charaters are same */
        if (strcmp(Data.keywords[key], buffer) == 0) {
            return true;
        }
    }
    return false;
}

bool isOperator(char charStr) {
    /* check if the character is the operator (from list) */
    for (int character_index = 0; character_index < 6; ++character_index) {
        if (charStr == Data.operators[character_index]) {
            printf("(%c) \t is an operator. Mapped into a token <%c>\n", charStr, charStr);
            return true;
        }
    }

    return false;
}

void isAlphaNumeric(char charStr, char(&buff)[15], int& j_index, int& index) {
    /* check if the ASCII of character is match to numbers (check if the value is alphanumeric) */
    if (isalnum(charStr)) {
        buff[j_index++] = charStr;
    }

    /* check if the buffer is not empty + charcter is not null or newline */
    else if ((charStr == ' ' || charStr == '\n') && (j_index != 0))
    {
        /* reset buffer and jumper_index */
        buff[j_index++] = '\0';
        j_index = 0;

        /* if flag(Ture/False) */
        if (isKeyword(buff))
            printf("(%s) \t is a keyword.\n", buff);
        else {
            printf("(%s) \t is an identifier. Mapped into a token <id, %d>\n", buff, index);
            index++;
        }
    }
}


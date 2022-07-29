#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>


void morseEncode(char character, char *morseCharacter)
{
    switch(character)
    {
        case 'a':
        case 'A':
            strcpy(morseCharacter, ". -");
            break;
        case 'b':
        case 'B':
             strcpy(morseCharacter, "- . . .");
             break;
        case 'c':
        case 'C':
             strcpy(morseCharacter, "- . - .");
             break;
        case 'd':
        case 'D':
             strcpy(morseCharacter, "- . .");
             break;
        case 'e':
        case 'E':
             strcpy(morseCharacter, ".");
             break;
        case 'f':
        case 'F':
             strcpy(morseCharacter, ". . - .");
             break;
        case 'g':
        case 'G':
             strcpy(morseCharacter, "- - .");
             break;
        case 'h':
        case 'H':
            strcpy(morseCharacter, ". . . .");
            break;
        case 'i':
        case 'I':
            strcpy(morseCharacter, ". .");
            break;
        case 'j':
        case 'J':
            strcpy(morseCharacter, ". - - -");
            break;
        case 'k':
        case 'K':
            strcpy(morseCharacter, "- . -");
            break;
        case 'l':
        case 'L':
            strcpy(morseCharacter, ". - . .");
            break;
        case 'm':
        case 'M':
            strcpy(morseCharacter, "- -");
            break;
        case 'n':
        case 'N':
            strcpy(morseCharacter, "- .");
            break;
        case 'o':
        case 'O':
            strcpy(morseCharacter, "- - -");
            break;
        case 'p':
        case 'P':
            strcpy(morseCharacter, ". - - .");
            break;
        case 'q':
        case 'Q':
            strcpy(morseCharacter, "- - . -");
            break;
        case 'r':
        case 'R':
            strcpy(morseCharacter, ". - .");
            break;
        case 's':
        case 'S':
            strcpy(morseCharacter, ". . .");
            break;
        case 't':
        case 'T':
            strcpy(morseCharacter, "-");
            break;
        case 'u':
        case 'U':
            strcpy(morseCharacter, ". . -");
            break;
        case 'v':
        case 'V':
            strcpy(morseCharacter, ". . . -");
            break;
        case 'w':
        case 'W':
            strcpy(morseCharacter, ". - -");
            break;
        case 'x':
        case 'X':
            strcpy(morseCharacter, "- . . -");
            break;
        case 'y':
        case 'Y':
            strcpy(morseCharacter, "- . - -");
            break;
        case 'z':
        case 'Z':
            strcpy(morseCharacter, "- - . .");
            break;
        case '1':
            strcpy(morseCharacter, ". - - - -");
            break;
        case '2':
            strcpy(morseCharacter, ". . - - -");
            break;
        case '3':
            strcpy(morseCharacter, ". . . - -");
            break;
        case '4':
            strcpy(morseCharacter, ". . . . -");
            break;
        case '5':
            strcpy(morseCharacter, ". . . . .");
            break;
        case '6':
            strcpy(morseCharacter, "- . . . .");
            break;
        case '7':
            strcpy(morseCharacter, "- - . . .");
            break;
        case '8':
            strcpy(morseCharacter, "- - - . .");
            break;
        case '9':
            strcpy(morseCharacter, "- - - - .");
            break;
        case '0':
            strcpy(morseCharacter, "- - - - -");
            break;
        case '.':
            strcpy(morseCharacter, ". - . - . -");
            break;
        case ',':
            strcpy(morseCharacter, "- - . . - -");
            break;
        case '?':
            strcpy(morseCharacter, ". . - - . .");
            break;
        case '!':
            strcpy(morseCharacter, "- . - . - -");
            break;
        case ' ':
            strcpy(morseCharacter, "       ");
            break;
        default:{
            char ch[] = {character, '\0'};
            strcpy(morseCharacter, ch);
            break;
        }
    }
}

void morseCode(char *diary, char **string){
    if(diary == NULL)
        return;

    if(diary[0] == 0)
        return;

    size_t length = strlen(diary);
    char character[12];
    morseEncode(diary[0], character);
    size_t chLength = strlen(character) + 3;
    *string = malloc(chLength + 1);
    strcpy(*string, character);

    for(int i = 1; i < length; i++){
        if(diary[i-1] != ' ')
            strcat(*string, "   ");

        morseEncode(diary[i], character);
        chLength += strlen(character) + 3;
        *string = realloc(*string, chLength + 1);
        strcat(*string, character);
    }
}

char textEncode(char *character2){
    if(!strcmp(character2, ". -" ))
        return 'a';
    else if(!strcmp(character2, "- . . ." ))
        return 'b';
    else if(!strcmp(character2, "- . - ." ))
        return 'c';
    else if(!strcmp(character2, "- . ." ))
        return 'd';
    else if(!strcmp(character2, "." ))
        return 'e';
    else if(!strcmp(character2, ". . - ." ))
        return 'f';
    else if(!strcmp(character2, "- - ." ))
        return 'g';
    else if(!strcmp(character2, ". . . ." ))
        return 'h';
    else if(!strcmp(character2, ". ." ))
        return 'i';
    else if(!strcmp(character2, ". - - -" ))
        return 'j';
    else if(!strcmp(character2, "- . -" ))
        return 'k';
    else if(!strcmp(character2, ". - . ." ))
        return 'l';
    else if(!strcmp(character2, "- -" ))
        return 'm';
    else if(!strcmp(character2, "- ." ))
        return 'n';
    else if(!strcmp(character2, "- - -" ))
        return 'o';
    else if(!strcmp(character2, ". - - ." ))
        return 'p';
    else if(!strcmp(character2, "- - . -" ))
        return 'q';
    else if(!strcmp(character2, ". - ." ))
        return 'r';
    else if(!strcmp(character2, ". . ." ))
        return 's';
    else if(!strcmp(character2, "-" ))
        return 't';
    else if(!strcmp(character2, ". . -" ))
        return 'u';
    else if(!strcmp(character2, ". . . -" ))
        return 'v';
    else if(!strcmp(character2, ". - -" ))
        return 'w';
    else if(!strcmp(character2, "- . . -" ))
        return 'x';
    else if(!strcmp(character2, "- . - -" ))
        return 'y';
    else if(!strcmp(character2, "- - . ." ))
        return 'z';
    else if(!strcmp(character2, ". - - - -" ))
        return '1';
    else if(!strcmp(character2, ". . - - -" ))
        return '2';
    else if(!strcmp(character2, ". . . - -" ))
        return '3';
    else if(!strcmp(character2, ". . . . -" ))
        return '4';
    else if(!strcmp(character2, ". . . . ." ))
        return '5';
    else if(!strcmp(character2, "- . . . ." ))
        return '6';
    else if(!strcmp(character2, "- - . . ." ))
        return '7';
    else if(!strcmp(character2, "- - - . ." ))
        return '8';
    else if(!strcmp(character2, "- - - - ." ))
        return '9';
    else if(!strcmp(character2, "- - - - -" ))
        return '0';
    else if(!strcmp(character2, ". - . - . -" ))
        return '.';
    else if(!strcmp(character2, "- - . . - -" ))
        return ',';
    else if(!strcmp(character2, ". . - - . ." ))
        return '?';
    else if(!strcmp(character2, "- . - . - -" ))
        return '!';
    return ' ';
}

int sevenSpaces(char *string){
    if(strlen(string) < 7)
        return 0;

    for(int i = 0; i < 7; i++){
        if(string[i] != ' ')
            return 0;
    }
    return 1;
}

void textCode(char *diary, char **string){
    if(diary == NULL)
        return;

    if(diary[0] == 0)
        return;

    size_t length = strlen(diary);
    char morseCharacter[12];
    int j = 0;
    int k = 0;
    *string = malloc(1);

    for(int i = 0; i < length - 1; i++){
        if(sevenSpaces(diary + i)){
            j += 2;
            *string = realloc(*string, j);
            morseCharacter[k] = 0;
            (*string)[j - 2] = textEncode(morseCharacter);
            (*string)[j - 1] = ' ';
            i += 9;
            k = 0;
        }
        else if(i + 1 < length && i + 2 < length && diary[i] == ' ' && diary[i + 1] == ' ' && diary[i + 2] == ' '){
            j++;
            *string = realloc(*string, j);
            morseCharacter[k] = 0;
            (*string)[j - 1] = textEncode(morseCharacter);
            i += 2;
            k = 0;
        }
        else{
            morseCharacter[k] = diary[i];
            k++;
        }
    }

    *string = realloc(*string, j+2);
    morseCharacter[k] = 0;
    (*string)[j] = textEncode(morseCharacter);
    (*string)[j + 1] = 0;
}

void printMenu(){
    printf("Choose an option:\n\n");
    printf("   1.Write in diary\n");
    printf("   2.View diary\n");
    printf("   3.Search in diary\n\n");
    printf("Chosen option: ");
}

int main(){
    system("chcp 65001  > nul");
    int option;
    char *diary = malloc(301);
    FILE *fp;

    printMenu();
    option = getch();
    printf("%c", option);
    Sleep(500);

    while(1){
        if(option == '1'){
            system("cls");
            printf(" ♥♥ You can write in your diary now! ♥♥\n");
            fp = fopen("diary.txt", "a+");

            while(fgets(diary, 300, stdin)){
                diary[strlen(diary)-1] = 0;
                if(strcmp(diary, "EXIT") == 0)
                    exit(0);
                if(strcmp(diary, "BACK") == 0){
                    system("cls");
                    printMenu();
                    fclose(fp);
                    break;
                }

                if(diary[0] != '\0'){
                    char *string;
                    morseCode(diary, &string);
                    fprintf(fp, "%s\n", string);
                }
                else
                    fprintf(fp, "%s\n", diary);
            }
            fclose(fp);
        }
        else if(option == '2'){
            char option2[4], *text;
            system("cls");
            printf("This is your diary!\n\n");

            fp = fopen("diary.txt", "r");

            while(fgets(diary, 300, fp)){
                textCode(diary, &text);
                printf("%s\n", text);
                free(text);
            }

            printf("\n\nType 'BACK' to go back to the menu, or 'EXIT' to close the diary: ");
            scanf("%4s", option2);

            if (strcmp(option2, "BACK") == 0){
                system("cls");
                printMenu();
            }
            else if (strcmp(option2, "EXIT") == 0)
                exit(0);
            else{
                printf("[ERROR] invalid command.\n");
                Sleep(2000);
                printMenu();
            }
            fclose(fp);
        }
        else if(option == '3'){
            char word[20];
            char option3[4], *text;
            system("cls");
            printf("What word would you like to search in your diary?\n");

            fp = fopen("diary.txt", "r");
            int s = 0;
            scanf("%20s", word);
            printf("\n");

            while(fgets(diary, 300, fp)){
                textCode(diary, &text);
                if(strstr(text, word)){
                    printf(text);
                    printf("\n");
                    s = 1;
                }
            }
            if(!s)
                printf("Sentence not found.");

            printf("\n\nType 'BACK' to go back to the menu, or 'EXIT' to close the diary: ");
            scanf("%4s", option3);

            if (strcmp(option3, "BACK") == 0){
                system("cls");
                printMenu();
            }
            else if (strcmp(option3, "EXIT") == 0)
                exit(0);
            else{
                printf("[ERROR] invalid command.");
                Sleep(2000);
                printMenu();
            }
            fclose(fp);
        }
        else{
            printf("\nInvalid character:)\nTry again!");
            Sleep(2000);
            system("cls");
            printMenu();
        }
        option = getch();
        printf("%c",option);
        Sleep(500);
    }
}

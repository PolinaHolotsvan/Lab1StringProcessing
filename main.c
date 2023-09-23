#include <stdio.h>
#include <string.h>

int isVowel(char c) {
    char vowels[] = "aeiouAEIOU";
    for (int i = 0; i < strlen(vowels); i++) {
        if (c == vowels[i]) {
            return 1;
        }
    }
    return 0;
}

int isDuplicate(char word2[], long int pos) {
    FILE *dupFile;
    int check = 0;
    char word[30];

    dupFile = fopen("file.txt", "rb+");

    while (ftell(dupFile) != pos) {
        int result = fscanf(dupFile, "%[a-zA-Z]", word);
        if (result == 1) {
            if (strcmp(word, word2) == 0) check += 1;
        } else
            fseek(dupFile, 1, SEEK_CUR);
    }

    fclose(dupFile);

    return check;
}

void printVowelsOnly(char word[], long int pos) {
    int result = 1;

    for (int j = 0; j < strlen(word); j++) {
        if (isVowel(word[j]) == 0) result = 0;
    }

    if ((result == 1) && (isDuplicate(word, pos) == 1)) printf("%s\n", word);
}


int main() {
    FILE *file;
    char word[30];

    file = fopen("file.txt", "rb+");
    if (file == NULL) {
        printf("Error\n");
        return 1;
    }

    while ((!feof(file))) {
        int result = fscanf(file, "%[a-zA-Z]", word);
        if (result == 1)
            printVowelsOnly(word, ftell(file));
        else
            fseek(file, 1, SEEK_CUR);
    }

    fclose(file);

    return 0;
}
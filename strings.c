#include <stdio.h>
#include <string.h>

// characters are actually ASCII codes
int countLetters(char* name, size_t size) {
    int vowelCounter = 0;
    int consonantCounter = 0;

    for (int i = 0; i < size; i++) {
        char c = name[i];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            switch(c) {
                case 'a':
                case 'e':
                case 'i':
                case 'o':
                case 'u':
                case 'A':
                case 'E':
                case 'I':
                case 'O':
                case 'U':
                    vowelCounter++;
                    break;
                default:
                    consonantCounter++;
            }
        }
    }
    return vowelCounter;
}

void changeCase(char* name, size_t size) {
    printf("String before the conversion: %s\n", name);

    for (int i = 0; i <= size; i++) {
        if (name[i] >= 65 && name[i] <= 90) name[i] += 32;
        else if(name[i] >= 97 && name[i] <= 122) name[i] -= 32;
    }

    printf("String after the conversion: %s\n", name);
}

int main() {
    char name[] = "asdfg";
    int vowels = countLetters(name, strlen(name));
    printf("Number of vowels: %d\n", vowels);
    printf("Number of consonants: %d\n", strlen(name) - vowels);
    return 0;
}

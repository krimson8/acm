#include <stdio.h>
#include <string.h>

int main() {
    char input[200] = "\0";
    char output[200] = "\0";
    while(strcmp(input, "ENDOFINPUT") != 0) {
        input[0] = '\0';
        output[0] = '\0';
        fgets(input, 200, stdin);
        input[strcspn(input, "\n")] = 0;
        printf("%s\n", input);
        if(strcmp(input, "START") == 0 || strcmp(input, "END") != 0) {
            printf("SOHAI\n");
            continue;
        }

        else {
            for(int i = 0; i < strlen(input); i++) {
                if(input[i] == 32) output[i] = 32;
                else if(input[i] - 5 < 65)
                    output[i] = 90 - (65 - (input[i] - 5));
                else 
                    output[i] = input[i] - 5;
            }
        }
        output[strlen(input) + 1] = '\0';
        printf("%s\n", output);
    }

    return 0;
}
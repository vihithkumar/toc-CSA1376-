#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Function prototypes
bool parseS(const char *input, int *pos);
bool parseA(const char *input, int *pos);

// Function to parse 'S' non-terminal
bool parseS(const char *input, int *pos) {
    int start_pos = *pos;
    
    // Check for '0S0' pattern
    if (input[*pos] == '0') {
        (*pos)++;
        if (parseS(input, pos) && input[*pos] == '0') {
            (*pos)++;
            return true;
        }
        *pos = start_pos; // Backtrack
    }

    // Check for 'A' production
    if (parseA(input, pos)) {
        return true;
    }

    return false;
}

// Function to parse 'A' non-terminal
bool parseA(const char *input, int *pos) {
    // Check for '1A' pattern
    while (input[*pos] == '1') {
        (*pos)++;
    }

    // Handle e (empty string)
    return true;
}

// Function to check if the entire string is parsed
bool is_accepted_by_cfg(const char *input) {
    int pos = 0;
    if (parseS(input, &pos) && input[pos] == '\0') {
        return true;
    }
    return false;
}

int main() {
    char input[100];
    
    printf("Enter a string: ");
    scanf("%s", input);

    if (is_accepted_by_cfg(input)) {
        printf("The string is accepted by the CFG.\n");
    } else {
        printf("The string is rejected by the CFG.\n");
    }

    return 0;
}

#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_CONTENT_LENGTH 2000

void read_stats_methord_1(const char *filename) {
    FILE *ptr = fopen(filename, "r");

    if (ptr == NULL) {
        printf("Error occurred during opening file");
    } 
    else 
    {
        int num_line = 0;
        int num_charactor = 0;
        int ch;

        while ((ch = fgetc(ptr)) != EOF) {
            if (ch == '\n') {
                num_line++;
            }
            num_charactor++;
        }
        printf("The total number of lines are:%d \n", num_line);
        printf("The total number of characters are:%d \n", num_charactor);
        fclose(ptr);
    }
}

void read_stats_methord_2(){
 char choice;
    printf("Enter 'Y' for yes and 'N' for No: ");
    scanf(" %c", &choice); // add space before %c to consume any leading whitespace

     if (choice == 'N' || choice == 'n') {
        printf("Thank you for using our program :)\n");
    } 
     else if (choice == 'Y' || choice == 'y') {
        int line = 0;
        int character = 0;
        char c;

        printf("Enter your code below (press Ctrl+D to end input):\n");
        
        while ((c = getchar()) != EOF) {
            character++;
            if (c == '\n') {
                line++;
            }
        }
        
        printf("Total number of lines: %d\n", line);
        printf("Total number of characters: %d\n", character);
 
   }
   else {
            printf("Invalid choice. Please enter 'Y' or 'N'.\n");
        }
    
}


void from_file_detect_missing_semicolon(FILE *ptr) {
    char line[MAX_LINE_LENGTH];
    int line_numbers = 0;

    while (fgets(line, MAX_LINE_LENGTH, ptr) != NULL) 
    {
        line_numbers++;

        // Remove whitespace
        int lin = strlen(line);
        while (lin > 0 && (line[lin - 1] == ' ' || line[lin - 1] == '\t' || line[lin - 1] == '\n')) {
            line[--lin] = '\0';
        }

        // Check if the line starts with 
        if (strncmp(line, "#include", strlen("#include")) == 0) {
            continue; // Ignore header file inclusion
        }
        if (strncmp(line, "if", strlen("if")) == 0)
        {
            continue; // Ignore condition inclusion
        }
        if (strncmp(line, "else if", strlen("else if")) == 0)
        {
            continue; // Ignore condition inclusion
        }
        if (strncmp(line, "else", strlen("else")) == 0)
        {
            continue; // Ignore condition inclusion
        }
        if ( strncmp(line, "void", strlen("void")) == 0)
        {
            continue; // Ignore function inclusion
        }
        if (strncmp(line, "int main()", strlen("int main()")) == 0)
        {
            continue; // Ignore function inclusion
        }
        if (strncmp(line, "void main()", strlen("void main()")) == 0)
        {
            continue; // Ignore function inclusion
        }
        if (strncmp(line, "{", strlen("{")) == 0)
        {
            continue; 
        }
        if (strncmp(line, "}", strlen("}")) == 0)
        {
            continue; 
        }

        // Check if the line is empty or a comment
        if (strlen(line) == 0 || line[0] == '/' || line[0] == '\n')
        {
            continue;
        }
        
        // Check if the line does not end with a semicolon
        if (line[lin - 1] != ';') 
        {
            printf("There is a missing semicolon in line %d : %s \n ", line_numbers, line);
        }

    }
}

void from_terminal_detect_missing_semicolon() {
    char line[MAX_LINE_LENGTH];
    int line_numbers = 0;

    printf("Enter your code below: \n");

    while (fgets(line, MAX_LINE_LENGTH, stdin) != NULL)
     {
        line_numbers++;

        // Remove whitespace
        int lin = strlen(line);
        while (lin > 0 && (line[lin - 1] == ' ' || line[lin - 1] == '\t' || line[lin - 1] == '\n')) 
        {
            line[--lin] = '\0';
        }
         // Check if the line starts with 
        if (strncmp(line, "#include", strlen("#include")) == 0) {
            continue; // Ignore header file inclusion
        }
        if (strncmp(line, "if", strlen("if")) == 0)
        {
            continue; // Ignore condition inclusion
        }
        if (strncmp(line, "else if", strlen("else if")) == 0)
        {
            continue; // Ignore condition inclusion
        }
        if (strncmp(line, "else", strlen("else")) == 0)
        {
            continue; // Ignore condition inclusion
        }
        if ( strncmp(line, "void", strlen("void")) == 0)
        {
            continue; // Ignore function inclusion
        }
        if (strncmp(line, "int main()", strlen("int main()")) == 0)
        {
            continue; // Ignore function inclusion
        }
        if (strncmp(line, "void main()", strlen("void main()")) == 0)
        {
            continue; // Ignore function inclusion
        }
        if (strncmp(line, "{", strlen("{")) == 0) 
        {
            continue; 
        }
        if (strncmp(line, "}", strlen("}")) == 0)
        {
            continue; 
        }
        
        // Check if the line is empty or a comment
        if (strlen(line) == 0 || line[0] == '/' || line[0] == '\n') 
        {
            continue;
        }
        
        // Check if the line does not end with a semicolon
        if (line[lin - 1] != ';') 
        {
            printf("There is a missing semicolon in line %d : %s \n ", line_numbers, line);
        }

    }
    printf("If you wish to know the total number of lines and charactors in your code \n");
    read_stats_methord_2();
}

int main() {
    int choice;
    char filename[MAX_LINE_LENGTH];

    printf("Warning : This program can only detect missing semicolons \n");
    printf("Choose an option:\n");
    printf("1. Provide the name of a source code file\n");
    printf("2. Input code manually\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice > 2) 
    {
        printf("Invalid option");
    } 
    else if (choice == 1)      
    {
        printf("Enter the name of source code file:");
        scanf("%s", filename);

        FILE *ptr = fopen(filename, "r");
        if (ptr == NULL) {
            printf("Error occured: unable to open file %s \n", filename);
        } 
        else 
        {  
            from_file_detect_missing_semicolon(ptr);
            fclose(ptr);
            read_stats_methord_1(filename);
        }
    } 
    else 
    {
        from_terminal_detect_missing_semicolon();
       
    }

    return 0;
}

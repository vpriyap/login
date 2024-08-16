#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <string.h>  

#define ENTER 13
#define TAB 9
#define BCKSPC 8

struct user {
    char fullName[50];
    char email[50];
    char password[50];
    char username[50];
    char phone[50];
};

void takeinput(char ch[50]) {
    fgets(ch, 50, stdin);
    ch[strlen(ch) - 1] = '\0'; 
}

void generateUsername(char email[50], char username[50]) {
    int i;
    for (i = 0; i < strlen(email); i++) {
        if (email[i] == '@') break;
        username[i] = email[i];
    }
    username[i] = '\0';  // Correctly terminate the string
}

void takepassword(char pwd[50]) {
    int i = 0;
    char ch;
    while (1) {
        ch = getch();
        if (ch == ENTER || ch == TAB) {
            pwd[i] = '\0';
            break;
        } else if (ch == BCKSPC) {
            if (i > 0) {
                i--;
                printf("\b \b");
            }
        } else {
            pwd[i++] = ch;
            printf("*");
        }
    }
}

int main() {
    system("color 0b");
    int opt;
    int usrFound = 0;
    struct user user;
    char password2[50];
    char username[50], pword[50];

    printf("\n\t\t\t\t----------Welcome to authentication system----------");
    printf("\nPlease choose your operation");
    printf("\n1.Signup");
    printf("\n2.Login");
    printf("\n3.Exit");

    printf("\n\nYour choice:\t");
    scanf("%d", &opt);
    fgetc(stdin);  

    switch (opt) {
        case 1:
            system("cls");
            printf("\nEnter your full name:\t");
            takeinput(user.fullName);
            printf("Enter your email:\t");
            takeinput(user.email);
            printf("Enter your contact no:\t");
            takeinput(user.phone);
            printf("Enter your password:\t");
            takepassword(user.password);
            printf("\nConfirm your password:\t");
            takepassword(password2);

            if (!strcmp(user.password, password2)) {
                generateUsername(user.email, user.username);
                printf("\n\nUser registration success, Your username is %s", user.username);
            } else {
                printf("\n\nPasswords do not match");
                Beep(750, 300);
                
            }
            break;

        case 2:
            printf("\nEnter your username:\t");
            takeinput(username);
            printf("Enter your password:\t");
            takepassword(pword);

            // Since no file operation, just comparing with in-memory data
            if (!strcmp(user.username, username)) {
                if (!strcmp(user.password, pword)) {
                    system("cls");
                    printf("\n\t\t\t\t\t\tWelcome %s", user.fullName);
                    printf("\n\n|Full Name:\t%s", user.fullName);
                    printf("\n|Email:\t\t%s", user.email);
                    printf("\n|Username:\t%s", user.username);
                    printf("\n|Contact no.:\t%s", user.phone);
                    usrFound = 1;
                } else {
                    printf("\n\nInvalid Password!");
                }
            }

            if (!usrFound) {
                printf("\n\nUser not found!");
            }
            break;

        case 3:
            printf("\t\t\tBye Bye :)");
            break;

        default:
            printf("\nInvalid choice. Please try again.");
            break;
    }
    getch();
    return 0;
}

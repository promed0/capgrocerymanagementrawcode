#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <unistd.h> // for usleep function
#include <string.h>
#define MAX_PRODUCT_NAME 100

// Function Declarations
void setConsoleColor(int color);
void showLoadingScreen();
void setConsoleTextColor(int textColor);
void clearScreen();
void displayBackground();
void displayWelcomeMessage();
void userPanel();
void adminPanel();
void displayOptions();
void user_option();
void admin_option();
void displayItemTable();
void add_product();
void buy_product();
void payment_method();
void mBanking();
void bkash();
void nagad();
void rocket();
void card();
void cash();
void return_panel_option();
void src_item();

struct ProductList {
    int p_id;
    char p_name[50];
    float p_price;
};

//>>>>>>>>>>>>>>>>>>>> Loading Screen >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

// Function to set the console text color
void setConsoleColor(int color)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

// Function to simulate loading and display a loading bar
void showLoadingScreen()
{
    int loadPercent = 0;
    const int loadingBarWidth = 50;

    // Set text color to bright green
    setConsoleColor(10);
    printf("\n\n\n\n\n\n\n\n\n");
    // Loop to update loading bar and percentage
    for (loadPercent = 0; loadPercent <= 100; loadPercent+=5)
    {
        // Move cursor back to update the loading bar
        printf("\r");

        // Print the percentage
        printf("\t\t\t\tProject Loading, please wait...\t%d%%", loadPercent);

        // Sleep for a short duration to simulate loading time
        Sleep(50); // Adjust this value to speed up or slow down the loading simulation
    }

    // Reset text color to default
    setConsoleColor(7);


}
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< End <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

//<<<<<<<<<<<<<<<<<<<<<<< Welcome Screen<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<,

// Function to set the console text color
void setConsoleTextColor(int textColor)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, textColor);
}

// Function to clear the console screen
void clearScreen()
{
    system("cls");
}

// Function to display the background square design
void displayBackground()
{
    printf("\n\n\n\n");
    printf("\t\t\t#######################################\n");
    printf("\t\t\t#                                     #\n");
    printf("\t\t\t#                                     #\n");
    printf("\t\t\t#                                     #\n");
    printf("\t\t\t#                                     #\n");
    printf("\t\t\t#                                     #\n");
    printf("\t\t\t#                                     #\n");
    printf("\t\t\t#######################################\n\n");
}

// Function to display each word of the welcome message with a delay
void displayWelcomeMessage()
{
    const char* message = "\t\t\t\tWELCOME\n\n \t\t\t\t\t  TO\n \n\t\t\t\tGROCERY MANAGEMENT SYSTEM!! ";
    char word[50];
    int wordIndex = 0;
    int color = 9; // Starting color (bright blue)

    clearScreen();
    displayBackground();

    // Move cursor to the starting position for the text
    COORD pos = {10, 5}; // Adjust the position as needed
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

    // Iterate through the message and display each word
    for (int i = 0; message[i] != '\0'; i++)
    {
        if (message[i] != ' ')
        {
            word[wordIndex++] = message[i];
        }
        else
        {
            word[wordIndex] = '\0'; // Null terminate the word
            wordIndex = 0; // Reset word index

            // Set text color and display the word
            setConsoleTextColor(color);
            printf("%s ", word);
            fflush(stdout);

            // Delay for a short time
            usleep(200000); // 0.2 second delay

            // Change color for the next word
            color = (color + 1) % 16; // Cycling through available colors
        }
    }

    // Display the last word----------------------------------+--
    setConsoleTextColor(color);
    printf("\n%s\n\n\n", word);

}
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> End <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> Selection Panel <<<<<<<<<<<<<<<<<<<<<<<<




// Function to display the option screen
void displayOptions()
{
    setConsoleColor(7);
    printf("\n\t\t\t\tChoose Your Panel:\n");
    printf("\n\t\t\t\t1. User Panel\n");
    printf("\n\t\t\t\t2. Admin Panel\n");
    printf("\n\t\t\t\t3. Exit\n");

    //<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Taking Panel Choice <<<<<<<<<<<<<<<<<<<,,
    int choice;

    // Prompt user for choice
    printf("\n\t\t\t\tEnter your choice: ");
    scanf("%d", &choice);

    // Process choice using switch statement
    switch (choice)
    {
    case 1:
        printf("\n\t\t\tYou selected User Panel\n");
        //userPanel();// Call function for User Panel
        user_option();
        break;
    case 2:
        printf("\n\t\t\tYou selected Admin Panel\n");
        // Call function for Admin Panel
        adminPanel();
        admin_option();
        break;
    case 3:
        exit (0);

    default:
        printf("\n\t\t\tInvalid choice! Please enter a valid option.\n");
    }

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Ending Take Choice <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
    return;

}

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< End <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<


//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< User Panel<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
void userPanel()
{
    char username[50];
    char password[50];

    FILE *file=fopen("user_login.txt","r");


    // Prompt for username and password
    printf("\n\t\t\tEnter username: ");
    fscanf(file,"%s",&username);
    printf("\n\t\t\tEnter password: ");
    fscanf(file,"%s",&password);

    // Perform authentication (dummy check for demonstration)
    if (strcmp(username, "user") == 0 && strcmp(password, "user") == 0)
    {
        printf("\n\t\t\tWelcome, %s! You have successfully logged in!!\n\n", username);
        // Add User Panel functionalities here
        user_option();
        return;


    }
    else
    {
        printf("\n\t\t\tIncorrect username or password. Please try again.\n\n");
    }

    fclose(file);


}

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< End <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<


//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< User Option <<<<<<<<<<<<<<<<<<<<<<<<<<<

void user_option()
{
    int user_choice;
    clearScreen();
    printf("\t\t\tUser(s) Choice Bar:\n\n");
    printf("\t\t\t1.Show Item List\n");
    printf("\t\t\t2.Search Item\n");
    printf("\t\t\t3.Select & Buy Product \n");
    printf("\t\t\t4.Exit \n");

    printf("\n\n\t\t\tEnter Your Expectation:");
    scanf("%d",&user_choice);

    switch(user_choice)
    {

    case 1:

        displayItemTable(); // Show Table Function
        return_panel_option();
        break;

    case 2:
        clearScreen();
        struct ProductList p;
        printf("\t\t\tEnter Product ID:");
        scanf("%d",&p.p_id);
        src_item(p.p_id);
        return_panel_option();
        break;
    case 3:
        buy_product();
        break;


    case 4:
        return_panel_option();
        break;

    default:
        printf("\n\t\t\tInvalid choice! Please enter a valid option.\n");

    }
}

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< End <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

void src_item(int p_id)
{

     FILE *file = fopen("i_card.txt", "r"); // Open the file in read mode
    if (file == NULL) {
        printf("\t\t\tError opening file!\n");
        exit(1);
    }

    struct ProductList p;
    int found = 0;

    // Search for the student by roll number
    while (fscanf(file, "%d %s %f", &p.p_id, &p.p_name, &p.p_price) != EOF) {
        if (p.p_id == p_id) {
            printf("\t\t\tProduct Found:\n");
            printf("\t\t\tProduct ID  : %d\n", p.p_id);
            printf("\t\t\tProduct Name: %s\n", p.p_name);
            printf("\t\t\tPrice       : %.2f\n", p.p_price);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\t\t\tProduct ID %d not found.\n", p_id);
    }

    fclose(file); // Close the file

}

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Admin Panel<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
void adminPanel()
{
    FILE *file=fopen("admin_login.txt","r");
    char adminname[50];
    char password[50];

    // Prompt for username and password
    printf("\n\t\t\tEnter admin name: ");
    fscanf(file,"%s",&adminname);
    printf("\n\t\t\tEnter password: ");
    fscanf(file,"%s",&password);

    // Perform authentication (dummy check for demonstration)
    if (strcmp(adminname, "admin") == 0 && strcmp(password, "admin") == 0)
    {
        printf("\n\t\t\tWelcome, %s! You have successfully logged in!!\n", adminname);
        // Add User Panel functionalities here
        return;
    }
    else
    {
        printf("\n\t\t\tIncorrect username or password. Please try again.\n");
    }

    fclose(file);
}

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< End <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Admin Option <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

void admin_option()
{

    system("cls");
    int choice;
    printf("\n\t\t\tAdmin(s) Option:\n");


    printf("\n\t\t\t1. Add Product");
    printf("\n\t\t\t2. Display Product.");
    printf("\n\t\t\t3. Search Item");
    printf("\n\t\t\t4. Exit");
    //printf("\n\t\t\t0. Exit.\n");
    printf("\n\t\t\tEnter Your Expectation:");
    scanf("%d", &choice);
    // ... Your menu and switch case code ...
    switch (choice)
    {

    case 1:
        add_product();
        break;
    case 2:
        displayItemTable();
        return_panel_option();
        break;

    case 3:
        clearScreen();
         struct ProductList p;
        printf("\t\t\tEnter Product ID:");
        scanf("%d",&p.p_id);
        src_item(p.p_id);
        return_panel_option();
        break;


    case 4:
        return_panel_option();
        break;

    }


}

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< End <<<<<<<<<<<<<<<<<<<<<<<<<<<



//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Show Menu Table <<<<<<<<<<<<<<<<
// Function to display the item table
void displayItemTable()
{
    system("cls");
    printf("\n");

     FILE *file=fopen("i_card.txt","r");
    if(file==NULL){
        printf("Error opening file\n");
        exit(1);
    }
else{
    struct ProductList p;
    printf("\n\t\t\tAvailable Product List:\n");
    printf("\n\t\t\t+------------------------------------------------+\n");
    printf("\n\t\t\t|  Item Code  |    Item Name    |   Price(TK)    |\n");
    printf("\n\t\t\t+------------------------------------------------+\n");

     while (fscanf(file, "%d %s %f", &p.p_id, p.p_name, &p.p_price) != EOF) {
        printf("\t\t\t   %d            %s             %.2f\n", p.p_id, p.p_name, p.p_price);
    }
}
    fclose(file); // Close the file

    return;

}

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< End <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

// Define a structure to store student information


void add_product()
{
    int n;
    FILE *file=fopen("i_card.txt","w");
   if(file==NULL){
    printf("Error opening File");
    exit(1);
   }



    printf("\t\t\tTotal Number of Item You want to Include:");
    scanf("%d",&n);
    system("cls");
    struct ProductList p[n];
    printf("\n");
    printf("\n\t\t\t+---------------------------------------------+\n");
    printf("\n\t\t\t|  Item Code  |    Item Name    |   Price(TK) |\n");
    printf("\n\t\t\t+---------------------------------------------+\n");



    for(int i=1; i<=n; i++)
    {

        printf("\t\t\t    ");
        scanf("%d    %s    %f",&p[i].p_id,&p[i].p_name,&p[i].p_price);
        fprintf(file,"\t\t\t  %d              %s               %.2f      \n",p[i].p_id,p[i].p_name,p[i].p_price);


    }


    fclose(file);
    return;
}


void buy_product()
{
    system("cls");
    int n,i;
    FILE *file=fopen("i_card.txt","r");
    if(file==NULL){
        printf("Error opening file\n");
        exit(1);
    }

    struct ProductList p;
    printf("\n\t\t\tAvailable Product List:\n");
    printf("\n\t\t\t+---------------------------------------------+\n");
    printf("\n\t\t\t|  Item Code  |    Item Name    |    Price    |\n");
    printf("\n\t\t\t+---------------------------------------------+\n");

     while (fscanf(file, "%d %s %f", &p.p_id, &p.p_name, &p.p_price) != EOF) {
        printf("\t\t\t  %d             %s              %.2f\n", p.p_id, p.p_name, p.p_price);
    }

    fclose(file); // Close the file


    printf("\n\n");
    printf("\n\t\t\tHow Many Products Do You Want to Buy: ");
    scanf("%d", &n);

    // Dynamic allocation for arrays
    char (*i_name)[20] = malloc(n * sizeof(*i_name));
    float *price = malloc(n * sizeof(float));
    int *quantity = malloc(n * sizeof(int));

    if (i_name == NULL || price == NULL || quantity == NULL)
    {
        printf("\n\t\t\tMemory allocation failed.\n");
        return;
    }

    for (int i = 0; i < n; i++)
    {
        printf("\n\t\t\tEnter Product-%d Name: ", i + 1);
        scanf("%s", i_name[i]);
        printf("\n\t\t\tEnter Product Price: ");
        scanf("%f", &price[i]);
        printf("\n\t\t\tEnter Product Quantity: ");
        scanf("%d", &quantity[i]);
    }

    float total = 0;
    for (int i = 0; i < n; i++)
    {
        float mul = price[i] * quantity[i];
        printf("\n\t\t\t%s: %.2f * %d = %.2f", i_name[i], price[i], quantity[i], mul);
        total += mul;
    }

    printf("\n\t\t\tTotal Payable Amount: %.2f\n", total);

    // Free dynamically allocated memory
    free(i_name);
    free(price);
    free(quantity);

    int choice;

    printf("\n\t\t\tDo You Want to Go for Payment?\n\t\t\t1.Yes\n\t\t\t2.No");
    scanf("%d",&choice);
    clearScreen();
    if (choice == 1)
    {
        payment_method();
        clearScreen();
        printf("\n\t\t\tTRANSACTION SUCCESSFUL!!");
        exit(1);
    }
    else
    {
        clearScreen();
        printf("\n\t\t\tTRANSACTION FAILED!!\n");
    }

    return;
}

void payment_method()
{
    clearScreen();

    int choice;
    printf("\n\t\t\tWhich One Do You Prefer For Payment?\n\t\t\t1.mBanking\n\t\t\t2.Card\n\t\t\t3.Cash");
    printf("\n\t\t\tEnter Your Preferance:");
    scanf("%d",&choice);

    switch (choice)
    {

    case 1:
        clearScreen();

        mBanking();
        break;
    case 2:
        clearScreen();
        card();
        break;

    case 3:
        clearScreen();
        cash();
        break;

    default:
        printf("\n\t\t\tInvalid choice! Please enter a valid option.\n");
    }


    return;
}
void mBanking()
{
    int choice;
    printf("\n\t\t\tWhich One Do You Prefer For mBanking?\n\t\t\t1.Bkash\n\t\t\t2.Nagad\n\t\t\t3.Rocket");
    printf("\n\t\t\tEnter Your Preferance:");
    scanf("%d", &choice);



    switch (choice)
    {

    case 1:
        clearScreen();
        bkash();

        break;
    case 2:
        clearScreen();

        nagad();
        break;

    case 3:
        clearScreen();

        rocket();
        break;

    default:
        printf("Unauthorized Payment Option!!\n");

        return;
    }
}


void bkash()
{
    char choice;
    printf("\n\t\t\tDo you want to return to the Payment Method? (y/n): ");
    scanf(" %c", &choice);

    if (choice == 'y')
    {
        payment_method();
    }



    long int number;
    int amount,pin;
    printf("\n\t\t\tEnter Bkash Number(11-Digits):");
         scanf("%ld",&number);

    printf("\n\t\t\tEnter Amount:");
    scanf("%d",&amount);
    printf("\n\t\t\tEnter PIN(4-Digits):");

         scanf("%d",&pin);

    return;
}
//
void nagad()
{
    char choice;
    printf("\n\t\t\tDo you want to return to the Payment Method? (y/n): ");
    scanf(" %c", &choice);

    if (choice == 'y')
    {
        payment_method();
    }

    long int number;
    int amount,pin;
    printf("\n\t\t\tEnter Nagad Number(11-Digits):");
    scanf("%ld",&number);
    printf("\n\t\t\tEnter Amount:");
    scanf("%d",&amount);
    printf("\n\t\t\tEnter PIN(4-Digits):");
    scanf("%d",&pin);
    return;
}
//
void rocket()
{
    char choice;
    printf("\n\t\t\tDo you want to return to the Payment Method? (y/n): ");
    scanf(" %c", &choice);

    if (choice == 'y')
    {
        payment_method();
    }

    long int number;
    int amount,pin;
    printf("\n\t\t\tEnter Rocket Number(11-Digits):");
    scanf("%ld",&number);
    printf("\n\t\t\tEnter Amount:");
    scanf("%d",&amount);
    printf("\n\t\t\tEnter PIN(4-Digits):");
    scanf("%d",&pin);
    return;

}
//
void card()
{

    char choice;
    printf("\n\t\t\tDo you want to return to the Payment Method? (y/n): ");
    scanf(" %c", &choice);

    if (choice == 'y')
    {
        payment_method();
    }

    long int number;
    int amount,pin;
    printf("\n\t\t\tWelcome to Card Payment System!!\n");
    printf("\n\t\t\tEnter Card Number(16-Digits):");
    scanf("%ld",&number);
    printf("\n\t\t\tEnter Amount:");
    scanf("%d",&amount);
    printf("\n\t\t\tEnter PIN(4-Digits):");
    scanf("%d",&pin);
    return;

}
//
void cash()
{

    char choice;
    printf("\n\t\t\tDo you want to return to the Payment Method? (y/n): ");
    scanf(" %c", &choice);

    if (choice == 'y')
    {
        payment_method();
    }

    float cashAmount;
    printf("\n\t\t\tWelcome to Cash Payment System!!\n");
    printf("\n\t\t\tPlease Enter the Cash Amount: ");
    scanf("%f", &cashAmount);

}
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Return to Home <<<<<<<<<<<<<<<<<<
void return_panel_option()
{
    char choice;
    printf("\n\t\t\tDo you want to return to the main panel? (y/n): ");
    scanf(" %c", &choice);

    if (choice == 'y')
    {   system("cls");
        displayOptions();
    }
    else
    {
        exit(0);
    }
}



//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< End <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<



int main()
{
    showLoadingScreen(); // For showing Loading Screen

    system("cls");


    displayWelcomeMessage();// For Showing Welcome Screen

    system("cls");

    displayOptions(); // Display Panel options

    return 0;
}


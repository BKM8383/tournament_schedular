#include<stdio.h>
#include<stdlib.h>                                                              //header files
#include<string.h>
#include<conio.h>




int value,value1;
char garbage;
char garbage1[20];                                                            // global structure and variavle

struct team
{
    char name[20];
    char players_name[50][30];
    char date[20][30];
};





void create(int no_of_teams, struct team teams[]){                                           // create function
    FILE *fp;
    fp = fopen("team.txt", "w");


    for (int i = 0; i < no_of_teams; i++)                                                    // insert team names
    {
        printf("Enter name of team %d: ", i + 1);
        scanf(" %s", teams[i].name);
    }
    printf("\nList of teams:\n");                                                                 //printing team name
    for (int i = 0; i < no_of_teams; i++)
    {
        printf("%d. %s\n", i + 1, teams[i].name);
    }




    printf("\nPress y to modify team name or n to continue :");                                 //edit while creating
    scanf(" %c", &garbage);
    while (garbage!='n')
    {
        printf("\nEnter the position of the team whose name is to be modified :");
        scanf("%d",&value);
        printf("\nEnter the new name : ");
        scanf(" %s",&garbage1);
        printf("\n");
        strcpy(teams[value-1].name, garbage1);

        for (int i = 0; i < no_of_teams; i++)
    {
        printf("%d. %s\n", i + 1, teams[i].name);
    }
    printf("\nPress y to modify team name or n to continue :");                                 //edit while creating
    scanf(" %c", &garbage);
    
    }
    fprintf(fp,"Team names : \n\n");
    for (int i = 0; i < no_of_teams; i++)
    {
        fprintf(fp,"%d. %s\n", i + 1, teams[i].name);
    }

// made by bhupendra kumawat
// section koc dg



    
    printf("\nEnter the number of player in each team : ");                                              // insert team players name
    scanf("%d", &value);
    printf(" \n");

    for (int i = 0; i < no_of_teams; i++)
    {
        for (int j = 0; j < value; j++)
        {
            printf("Enter name of player %d of %s team: ", j + 1, teams[i].name);
            scanf(" %s", teams[i].players_name[j]);
        }
        printf("\n\n");
    }







    printf("\nList of players:\n");                                                                         // print team players name
    for (int i = 0; i < no_of_teams; i++)
    {
        printf("\n\nTeam %d. ( %s )\n", i + 1, teams[i].name);

        for (int j = 0; j < value; j++)
        {
            printf("%d. %s\n", j + 1, teams[i].players_name[j]);
        }
    }




        printf("\nPress y to modify team players name or n to continue :");                                 //edit while creating
    scanf(" %c", &garbage);
    while (garbage!='n')
    {
        printf("\nEnter the position of the team whose player name is to be modified :");
        scanf("%d",&value);
        printf("\nEnter the position of player whose name is to be modified :");
        scanf("%d",&value1);
        printf("\nEnter the new name : ");
        scanf(" %s",&garbage1);
        // printf("\n");
        strcpy(teams[value-1].players_name[value1-1], garbage1);

    for (int i = 0; i < no_of_teams; i++)
    {
        printf("\n\nTeam %d. ( %s )\n", i + 1, teams[i].name);

        for (int j = 0; j < value; j++)
        {
            printf("%d. %s\n", j + 1, teams[i].players_name[j]);
        }
    }
    printf("\nPress y to modify team player name or n to continue :");                                
    scanf(" %c", &garbage);
    
    }

    fprintf(fp," \n\nTeam players names : \n\n");

    for (int i = 0; i < no_of_teams; i++)
    {
        fprintf(fp,"\n\nTeam %d. ( %s )\n", i + 1, teams[i].name);

        for (int j = 0; j < value; j++)
        {
            fprintf(fp,"%d. %s\n", j + 1, teams[i].players_name[j]);
        }
    }


   int matches = no_of_teams * (no_of_teams - 1) / 2;
    int schedule[matches][2];
    int count = 0;
    for (int i = 0; i < no_of_teams - 1; i++) {
        for (int j = i + 1; j < no_of_teams; j++) {
            schedule[count][0] = i;
            schedule[count][1] = j;
            count++;
        }
    }
// made by bhupendra kumawat
// section koc dg
    // assign dates to matches
    printf("\nPlease enter the dates when the matches are to be played below -");
    for (int i = 0; i < matches; i++) {
        printf("\nEnter the date of match %d in format (dd/mm/yyyy) : ", i + 1);
        scanf(" %s", teams[schedule[i][0]].date[i]);
        strcpy(teams[schedule[i][1]].date[i], teams[schedule[i][0]].date[i]);
    }
    system("cls");
    // print tournament schedule
    printf("\n\nTournament Schedule:\n");
    for (int i = 0; i < matches; i++) {
        printf("\nMatch %d - %s vs %s on %s", i + 1, teams[schedule[i][0]].name, teams[schedule[i][1]].name, teams[schedule[i][0]].date[i]);
    }


    fprintf(fp,"\n\nTournament Schedule:\n");
    for (int i = 0; i < matches; i++) {
        fprintf(fp,"\nMatch %d - %s vs %s on %s", i + 1, teams[schedule[i][0]].name, teams[schedule[i][1]].name, teams[schedule[i][0]].date[i]);
    }
    fclose(fp);
}







void delete_data()
{

    FILE *f = fopen("team.txt", "w");                                                                        // delete entire doument
    fclose(f);
    system("cls");
    printf("\nAll data has been deleted.\n");
}














void display()
{
    char data[100][100];
    int count;
    FILE *f = fopen("team.txt" , "r");                                             
    char myString[100];
    fseek(f, 0, SEEK_END);
    if (ftell(f) == 0) {
        printf("\nFill is empty please insert first.");
    }
    else {
    fseek(f, 0, SEEK_SET);

    while(fgets(myString, 100, f))
    {
        count=count+1;
      printf("%s", myString);
    }    
   
    
}fclose(f);
}


void edit() {
    char line[100][100];
    FILE *fptr = NULL;
    char value[100], value1[100];
    int i = 0;
    int tot = 0;
    fptr = fopen("team.txt", "r+");
     fseek(fptr, 0, SEEK_END);
    if (ftell(fptr) == 0) {
        printf("\nFill is empty please insert first.");
        return;
    }
    fseek(fptr, 0, SEEK_SET);

    while (fgets(line[i], 100, fptr)) {
        line[i][strlen(line[i]) - 1] = '\0';
        i++;
    }
    tot = i;
    for (i = 0; i < tot; ++i) {
        printf(" %s\n", line[i]);
    }
    printf("\n\nWhat you want to edit :");
    scanf("%s", value1);
    printf("\n\nNew name :");
    scanf("%s", value);
    rewind(fptr);
    for (i = 0; i < tot; ++i) {
        char *pos = strstr(line[i], value1);
        if (pos != NULL) {
            int index = pos - line[i];
            char new_line[100];
            sprintf(new_line, "%.*s%s%s", index, line[i], value, pos + strlen(value1));
            strcpy(line[i], new_line);
        }
        fprintf(fptr, "%s\n", line[i]);
    }
    fclose(fptr);
    printf("\n\nSuccessfully updated the file!\n");
}










// banner function
void Banner()
{

    // welcome Banner
    system("cls");
    printf("\t\tWELCOME TO IPL CRICKET TOURNAMENT SCHEDULAR");
    printf("\nEnter your choise - ");
    printf("\n1 ) Create new schedule (Deletes any previous Records)");
    printf("\n2 ) Delete all data");
    printf("\n3 ) Display Information");
    printf("\n4 ) Edit Information");
    printf("\n5 ) Exit");

    printf("\nEnter : ");
    scanf("%d", &value);
// made by bhupendra kumawat
// section koc dg
    switch (value)
    {
    case 1:
    {
        // system("cls");
        int no_of_teams;
        printf("Enter the number of teams: ");
        scanf("%d", &no_of_teams);
        struct team teams[no_of_teams];
        create(no_of_teams, teams);
        break;
    }
    case 2:
        delete_data();
        break;
    case 3:
        display();
        break;
    case 4:
        edit();
        break;
    case 5:
        PRINTF("EXITING....");
        exit(1);
        break;
    default:{
        printf("\nInvalid input");
        break;
    }}
}










int main()                                                                                         //main function
{
    while (1)
    {
      Banner();
      printf("\n\nPress any key to go back to main menu");
      getch();
    }
    
    
    return 0;
}

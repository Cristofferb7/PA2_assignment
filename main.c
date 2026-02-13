/* COP 3502C PA2
This program is written by: Cristoffer Bohorquez*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ===================== CONSTANTS AND GLOBAL VARIABLES =====================

#define MAX_SCORES 5
#define MAX_STR 25

const float POSITION_BONUS[10] = {3.0, 5.0, 4.0, 6.0, 7.0, 2.0, 8.0, 1.0, 9.0, 1.5};

typedef struct Cat Cat;
typedef struct Rivals Rivals;

Cat *cats;
Rivals *rivals;
float bestPermScore;
int **tracker;

// ===================== STRUCTURE DEFINITIONS =====================

typedef struct Cat
{
    char *name;             // dynamically allocated cat name
    char *breed;            // dynamically allocated breed
    int scores[MAX_SCORES]; // array of size 5 representing trait scores
    int baseScore;          // sum of scores array
} Cat;

typedef struct Rivals
{
    Cat *cat1; // pointer to cat1
    Cat *cat2; // pointer to cat2
} Rivals;

// ===================== FUNCTION PROTOTYPES =====================

// Input functions
void readInput(int *n, int *c, int *r, int *totalCats);
void readCats(int totalCats);
void readRivals(int r, int totalCats);

// Memory management
char *allocateString(char *temp);

void freeMemory(int n, int c, int r);

// Required recursive functions (YOU MUST DESIGN THESE)
int countHighPerformersTraits(/* TODO: design parameters */);
int synergyBonusApplies(/* TODO: design parameters */);
int rivalPenaltyApplies(/* TODO: design parameters */);

// Scoring functions
float calculateTeamScore(int *perm, int teamStart, int teamSize, int r);
float calculatePermutationScore(int *perm, int n, int c, int r);

// Helper functions
int areRivals(Cat *cat1, Cat *cat2, int r);
int allDifferentBreeds(int *perm, int teamStart, int teamSize);

// Permutation functions
void generatePermutations(int *perm, int *used, int pos, int totalCats, int n, int c, int r);
void updateTracker(int *perm, int n, int c);

// Output functions
void printResults(int n, int c, int r);
int findBestTeam(int n, int c, int r);

// ===================== MAIN FUNCTION =====================

int main()
{
    int n, c, r, totalCats;

    // TODO: Read input

    // TODO: Initialize bestPermScore

    // TODO: Allocate tracker

    // TODO: Create permutation and used arrays

    // TODO: Generate permutations

    // TODO: Print results

    // TODO: Free memory

    return 0;
}

// ===================== INPUT FUNCTIONS =====================

void readInput(int *n, int *c, int *r, int *totalCats) // N = number of teams, C= number of cats, R = number of rivals
{
    // TODO: Read n and c
    printf("Enter number of teams , and number of cats in the team");
    scanf(" %d %d", n, c);

    // TODO: Calculate totalCats

    *totalCats = (*n) * (*c);

    // TODO: Allocate cats array

    cats = malloc((*totalCats) * sizeof(Cat));

    if (cats == NULL)
    {
        printf("cat array not allocated");
    }

    // before reading the rivals we need to read the function

    readCats(*totalCats);

    // TODO: Read r

    printf("\n Enter rival pairs: ");
    scanf("%d", r);
}

void readCats(int totalCats)
{
    char tempName[MAX_STR];
    char tempBreed[MAX_STR];

    // TODO: Read all cats
    for (int i = 0; i < totalCats; i++)
    {
        // TODO: Read name and breed

        scanf(" %s %s", &tempName, &tempBreed);

        // TODO: Allocate and store name
        cats[i].name = allocateString(tempName);

        // TODO: Allocate and store breed
        cats[i].breed = allocateString(tempBreed);

        // TODO: Initialize baseScore

        int baseScore = 0; //

        // TODO: Read scores and calculate baseScore
        for (int j = 0; j < MAX_SCORES; j++)
        {
            scanf(" %d", &cats[i].scores[j]);       // loops the cat score
            cats[i].baseScore += cats[i].scores[j]; // returns the sum to a base score
        }
    }
}

void readRivals(int r, int totalCats)
{
    char tempName1[MAX_STR];
    char tempName2[MAX_STR];

    // TODO: Handle r == 0 case

    if (r == 0)
    {
        rivals = NULL;
        return;
    }

    // TODO: Allocate rivals array

    rivals = malloc((r) * sizeof(Rivals));

    // TODO: Read rival pairs
    for (int i = 0; i < r; i++)
    {
        // TODO: Read names

        scanf(" %s %s ", tempName1, tempName2);

        // TODO: Find matching cats and store pointers

        for (int j = 0; j < totalCats; j++)
        {
            if (strcmp(tempName1, cats[j].name) == 0)
            {
                rivals[i].cat1 = &cats[j];
            }

            if (strcmp(tempName2, cats[j].name) == 0)
            {
                rivals[i].cat2 = &cats[j];
            }
        }
    }
}

// ===================== MEMORY MANAGEMENT =====================

char *allocateString(char *temp)
{
    // TODO: Allocate memory

    char *dest; // new pointer

    dest = malloc((strlen(temp) + 1) * sizeof(char)); // creating space for new ptr

    if (dest == NULL) // checking if its null
    {
        return NULL;
    }

    // TODO: Copy string
    strcpy(dest, temp); // copying the temp to dest pointer memory

    // TODO: Return pointer

    return dest; // returning new pointer to allocated string
}

void freeMemory(int n, int c, int r)
{
    int totalCats = n * c;

    // TODO: Free cat names and breeds

    // TODO: Free cats array

    // TODO: Free rivals array

    // TODO: Free tracker array
}

// ===================== REQUIRED RECURSIVE FUNCTIONS =====================
// NOTE: You must design the parameters for these functions yourself!

int countHighPerformersTraits(/* TODO: your parameters */)
{
    // TODO: Implement recursive function to count traits >= 90
}

int synergyBonusApplies(/* TODO: your parameters */)
{
    // TODO: Implement recursive function to check if all cats have at least one trait >= 85
}

int rivalPenaltyApplies(/* TODO: your parameters */)
{
    // TODO: Implement recursive function to count adjacent rival pairs
}

// =====================x` SCORING FUNCTIONS =====================

float calculateTeamScore(int *perm, int teamStart, int teamSize, int r)
{
    float score = 0.0;

    // TODO: Calculate average base score

    // TODO: Add high performer bonus

    // TODO: Add synergy bonus

    // TODO: Add breed diversity bonus or penalty

    // TODO: Add position bonuses

    // TODO: Subtract rival penalty

    return score;
}

float calculatePermutationScore(int *perm, int n, int c, int r)
{
    float totalScore = 0.0;

    // TODO: Calculate and sum scores for all teams

    return totalScore;
}

// ===================== HELPER FUNCTIONS =====================

int areRivals(Cat *cat1, Cat *cat2, int r)
{
    // TODO: Check if cat1 and cat2 are rivals
}

int allDifferentBreeds(int *perm, int teamStart, int teamSize)
{
    // TODO: Check if all cats in team have different breeds
    for (int i = 0; i < teamSize; i++)
    {
        for (int j = i+ 1; j < teamSize ; j++)
        {

            int catIndex1 = perm[teamStart + i];


            if (strcmp(cats[i].breed, cats[j].breed) == 0)
            {
                return 0;
            }
           

            
        }
        return 1;
        
    }
}

// ===================== PERMUTATION FUNCTIONS =====================

void generatePermutations(int *perm, int *used, int pos, int totalCats, int n, int c, int r)
{
    // TODO: Implement recursive permutation generation with backtracking
}

void updateTracker(int *perm, int n, int c)
{
    // TODO: Copy permutation to tracker
}

// ===================== OUTPUT FUNCTIONS =====================

void printResults(int n, int c, int r)
{
    // TODO: Print overall best score

    // TODO: Print each team and its score
    for (int team = 0; team < n; team++)
    {
        // TODO: Print team number and cat names

        // TODO: Print team score
    }

    // TODO: Print best candidate team
}

int findBestTeam(int n, int c, int r)
{
    // TODO: Find and return team with highest score
}
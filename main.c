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

int countHighPerformersTraits(int *perm, int teamStart, int teamSize, int currentPos)
{
    // TODO: Implement recursive function to count traits >= 90

    if (currentPos >= teamSize) // base case checking all cats in the team
    {
        return 0; // no cats
    }

    int catIndex = perm[teamStart + currentPos]; // looking up which cat in the array
    Cat *currentCat = &cats[catIndex];           // pointer to existing cats

    // count how many cats in the array are 90 =>
    int countForCat = 0;
    for (int i = 0; i < MAX_SCORES; i++)
    {
        if (currentCat->scores[i] >= 90) // checking the value
        {
            countForCat++; // add one in the count
        }

    }
    //recursive call to get the rest of the cats
    int countForRest = countHighPerformersTraits(perm, teamStart, teamSize, currentPos + 1);

    return countForCat + countForRest; //return cat count plus all the remaining
}

int synergyBonusApplies(int *perm, int teamStart, int teamSize, int currentPos)

{
    // TODO: Implement recursive function to check if all cats have at least one trait >= 85

    if (currentPos >= teamSize) // base case checking all cats in the team
    {
        return 1; // all cats passed the check
    }

    int catIndex = perm[teamStart + currentPos]; // looking up which cat in the array
    Cat *currentCat = &cats[catIndex];    // pointer to the current cat in the array

    // count how many cats in the array are 85 =>
    int hasHighTrait = 0;
    for (int i = 0; i < MAX_SCORES; i++)
    {
        if (currentCat->scores[i] >= 85) // checking the value
        {
            hasHighTrait = 1; // set it to one 
            break;
        }


    }
    if (!hasHighTrait)
    {
        return 0; //cat failed, synergy out.
    }
    
    //recursive call to get the rest of the cats
    return synergyBonusApplies(perm, teamStart, teamSize, currentPos + 1);


}

int rivalPenaltyApplies(int *perm, int teamStart, int teamSize, int currentPos, int r)
{
    // TODO: Implement recursive function to count adjacent rival pairs

      if (currentPos >= teamSize - 1) // base case checking all adjacent pairs
    {
        return 0; // no pairs to check
    }

    int catIndex1 = perm[teamStart + currentPos]; // looking up which cat in the array
    int catIndex2 = perm[teamStart + currentPos + 1]; // looking up which next  cat in the array
    Cat *cat1 = &cats[catIndex1];    // pointer to the current cat in the array
    Cat *cat2 = &cats[catIndex2];    // pointer to the next current cat in the array

    // count how many cats in the array 
    int penaltyForThisPair = 0;
    for (int i = 0; i < r; i++)
    {
        if (areRivals(cat1, cat2, r)) // are they rivals
        {
            penaltyForThisPair = 1; // set it to one 
        }

    }
    
    //recursive call to get the rest of the cats
    int penaltyForRest = rivalPenaltyApplies(perm, teamStart, teamSize, currentPos + 1, r);

    //return: this pair's pentaly + remaining 
    return penaltyForRest + penaltyForThisPair;
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

    if (rivals == NULL)
    {
        return 0;
    }

    // TODO: Check if cat1 and cat2 are rivals
    for (int i = 0; i < r; i++)
    {
        // Check if cat1 and cat2 match this rival pair
        // Could be (cat1, cat2) OR (cat2, cat1)
        if ((rivals[i].cat1 == cat1 && rivals[i].cat2 == cat2) || (rivals[i].cat1 == cat2 && rivals[i].cat2 == cat1))
        {
            return 1; // rivals
        }
    }
    return 0; // no rivals
}

int allDifferentBreeds(int *perm, int teamStart, int teamSize)
{
    // TODO: Check if all cats in team have different breeds
    // Compare all pairs of cats in team
    for (int i = 0; i < teamSize; i++)
    {
        for (int j = i + 1; j < teamSize; j++) // adding i+1 for comparing the next cat in the loop
        {
            //get the actual cat index from the permutation
            int catIndex1 = perm[teamStart + i];
            int catIndex2 = perm[teamStart + j];

            // comparing breeds
            if (strcmp(cats[catIndex1].breed, cats[catIndex2].breed) == 0)
            {
                return 0; // duplicate
            }
        }
        return 1; // no duplicates
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

// int recursiveFunction(parameters, int currentPos) {

// 1. BASE CASE - When to stop?
// if (currentPos >= limit) {
return 0; // or 1, or whatever makes sense
}

// 2. DO WORK - Handle the CURRENT item
int resultForCurrent = // do something with current item

    // 3. RECURSE - What about the REST?
    //int resultForRest = recursiveFunction(parameters, currentPos + 1);

// 4. COMBINE - Put them together
return resultForCurrent + resultForRest; // or AND them, or whatever
                                         //
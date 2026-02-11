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

    // TODO: Call readInput to get n, c, r, and totalCats

    // TODO: Call readCats to read all cat information

    // TODO: Call readRivals to read rival pairs

    // TODO: Initialize bestPermScore to a very low value (like -1e9)

    // TODO: Allocate tracker as 2D array (n rows x c columns)

    // TODO: Create permutation array of size totalCats

    // TODO: Create used array of size totalCats, initialize all to 0

    // TODO: Call generatePermutations to find best arrangement

    // TODO: Call printResults to display output

    // TODO: Free all dynamically allocated memory (perm, used, call freeMemory)

    return 0;
}

// ===================== INPUT FUNCTIONS =====================

void readInput(int *n, int *c, int *r, int *totalCats) // N = number of teams, C= number of cats, R = number of rivals
{
    // TODO: Read n and c from input
    printf("Enter number of teams , and number of cats in the team");
    scanf(" %d %d", n, c);

    // TODO: Calculate totalCats = n * c

    *totalCats = (*n) * (*c);

    // TODO: Allocate cats array with totalCats elements

    cats = malloc((*totalCats) * sizeof(Cat));

    if (cats == NULL)
    {
        printf("cat array not allocated");
    }

    // before reading the rivals we need to read the function

    readCats(*totalCats);

    // TODO: Read r (number of rival pairs)

    printf("\n Enter rival pairs: ");
    scanf("%d", r);
}

void readCats(int totalCats)
{
    char tempName[MAX_STR];
    char tempBreed[MAX_STR];

    // TODO: Loop through totalCats
    for (int i = 0; i < totalCats; i++)
    {
        // TODO: Read cat name and breed into temp arrays

        scanf(" %s %s", &tempName, &tempBreed);

        // TODO: Use allocateString to dynamically allocate and copy name
        cats[i].name = allocateString(tempName);

        // TODO: Use allocateString to dynamically allocate and copy breed
        cats[i].breed = allocateString(tempBreed);

        // TODO: Initialize baseScore to 0

        int baseScore = 0; //

        // TODO: Loop through MAX_SCORES to read 5 trait scores
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

    // TODO: If r == 0, set rivals to NULL and return

    if (r == 0)
    {
        rivals = NULL;
        return;
    }

    // TODO: Allocate rivals array with r elements

    rivals = malloc((r) * sizeof(Rivals));

    // TODO: Loop through r rival pairs
    for (int i = 0; i < r; i++)
    {
        // TODO: Read two cat names

        scanf(" %s %s ", tempName1, tempName2);

        // TODO: Search through cats array to find matching names

        for (int j = 0; j < totalCats; j++)
        {
            //  - When found, set rivals[i].cat1 and rivals[i].cat2
            if (strcmp(tempName1, cats[j].name) == 0)
            {
                //- Use pointers to the cats (e.g., &cats[j])

                rivals[i].cat1 = &cats[j];
            }
            //- Use pointers to the cats (e.g., &cats[j])

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
    // TODO: Allocate memory for strlen(temp) + 1 characters

    char *dest; // new pointer

    dest = malloc((strlen(temp) + 1) * sizeof(char)); // creating space for new ptr

    if (dest == NULL) // checking if its null
    {
        return NULL;
    }

    // TODO: Use strcpy to copy temp into allocated memory
    strcpy(dest, temp); // copying the temp to dest pointer memory

    // TODO: Return pointer to allocated string

    return dest; // returning new pointer to allocated string
}

void freeMemory(int n, int c, int r)
{
    int totalCats = n * c;

    // TODO: Loop through all cats and free name and breed

    // TODO: Free cats array

    // TODO: Free rivals array (if not NULL)

    // TODO: Free tracker 2D array (free each row, then the array itself)
}

// ===================== REQUIRED RECURSIVE FUNCTIONS =====================
// NOTE: You must design the parameters for these functions yourself!

int countHighPerformersTraits(/* TODO: your parameters */)
{
    // TODO: Base case - when should recursion stop?
    //       Hint: when you've checked all cats in the team

    // TODO: Recursive case:
    //       - Get current cat from permutation
    //       - Count how many of this cat's traits are >= 90
    //       - Recursively call for next position
    //       - Return sum of current count + recursive result
}

int synergyBonusApplies(/* TODO: your parameters */)
{
    // TODO: Base case - checked all cats successfully
    //       Return 1 (true) if reached end

    // TODO: Get current cat from permutation

    // TODO: Check if this cat has at least one trait >= 85
    //       If not, return 0 (false) - synergy broken

    // TODO: Recursive case - check next cat
    //       Return result of recursive call
}

int rivalPenaltyApplies(/* TODO: your parameters */)
{
    // TODO: Base case - checked all adjacent pairs
    //       Hint: when currentPos >= teamSize - 1

    // TODO: Get current cat and next cat (adjacent pair)

    // TODO: Check if these two cats are rivals using areRivals helper
    //       If yes, count = 1, else count = 0

    // TODO: Recursively check next pair
    //       Return current count + recursive result
}

// =====================x` SCORING FUNCTIONS =====================

float calculateTeamScore(int *perm, int teamStart, int teamSize, int r)
{
    float score = 0.0;

    // STEP 1: Calculate base score
    // TODO: Sum up baseScores of all cats in team
    // TODO: Divide by teamSize to get average

    // STEP 2: Add bonuses

    // TODO: High Performer Bonus
    //       Call countHighPerformersTraits, multiply by 5

    // TODO: Synergy Bonus
    //       If synergyBonusApplies returns true, add 30

    // TODO: Breed Diversity Bonus OR Duplicate Breed Penalty
    //       If allDifferentBreeds, add 10
    //       Else, subtract 15

    // TODO: Position Bonus
    //       For each cat in team:
    //       - Add cat.baseScore * (POSITION_BONUS[position] / 100.0)

    // STEP 3: Subtract penalties

    // TODO: Rival Penalty
    //       Call rivalPenaltyApplies to count adjacent rival pairs
    //       Subtract count * 25

    return score;
}

float calculatePermutationScore(int *perm, int n, int c, int r)
{
    float totalScore = 0.0;

    // TODO: Loop through each team (0 to n-1)
    //       - Calculate teamStart = team * c
    //       - Call calculateTeamScore for this team
    //       - Add to totalScore

    return totalScore;
}

// ===================== HELPER FUNCTIONS =====================

int areRivals(Cat *cat1, Cat *cat2, int r)
{
    // TODO: If rivals is NULL, return 0

    // TODO: Loop through all rival pairs
    //       Check if (cat1, cat2) or (cat2, cat1) match this pair
    //       If yes, return 1

    // TODO: If no match found, return 0
}

int allDifferentBreeds(int *perm, int teamStart, int teamSize)
{
    // TODO: Use nested loops to compare all pairs of cats in team
    //       If any two have same breed (use strcmp), return 0
    for (int i = 0; i < teamSize; i++)
    {
        for (int j = i+ 1; j < teamSize ; j++)
        {
            if (strcmp(cats[i].breed, cats[j].breed) == 0)
            {
                return 0;
            }
            
        }
        
    }
    


    // TODO: If all different, return 1
}

// ===================== PERMUTATION FUNCTIONS =====================

void generatePermutations(int *perm, int *used, int pos, int totalCats, int n, int c, int r)
{
    // TODO: Base case - complete permutation (pos == totalCats)
    //       - Calculate score using calculatePermutationScore
    //       - If score > bestPermScore:
    //         * Update bestPermScore
    //         * Call updateTracker to save this arrangement
    //       - Return

    // TODO: Recursive case - try each unused cat
    //       Loop i from 0 to totalCats-1:
    //       - If used[i] is 0:
    //         * Set used[i] = 1
    //         * Set perm[pos] = i
    //         * Recursively call with pos+1
    //         * Set used[i] = 0 (backtrack)
}

void updateTracker(int *perm, int n, int c)
{
    // TODO: Copy values from 1D perm array to 2D tracker array
    //       For each team and position:
    //       tracker[team][pos] = perm[team * c + pos]
}

// ===================== OUTPUT FUNCTIONS =====================

void printResults(int n, int c, int r)
{
    // TODO: Print "Best Teams Grouping score: %.2f\n" with bestPermScore

    // TODO: Loop through each team
    for (int team = 0; team < n; team++)
    {
        // TODO: Print "Team %d:" with team number (1-based)

        // TODO: Print all cat names in this team from tracker

        // TODO: Calculate this team's score and print it

        // TODO: Print newline
    }

    // TODO: Find best team using findBestTeam

    // TODO: Print "Best Candidate:" followed by cat names
}

int findBestTeam(int n, int c, int r)
{
    // TODO: Loop through all teams
    //       - Calculate score for each team
    //       - Track which team has highest score
    //       - If tie, choose first one (lower index)

    // TODO: Return index of best team
}
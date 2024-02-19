#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE(a) (sizeof(a) / sizeof((a)[0]))  // 26

/* Given Functions */
void shuffle_cases(int cases[], int cases_size);
void offer(int cases[], int cases_size, int initial_amount);
int remove_case_and_get_amount(int cases[], int cases_size, int index);

/* Your Functions */
int pick_case_index(int cases[], int cases_size);
bool get_decision(void);
int cases_average(int cases[], int cases_size, int initial_amount);
int cases_remaining(int cases[], int cases_size);
int get_last_remaining_case(int cases[], int cases_size);
void eliminate_cases(int cases[], int cases_size, int eliminated);

int main(void) {
  int cases[] = {
      // stores amount in each case
      0,     1,      5,      10,     25,     50,     75,     100,     200,
      300,   400,    500,    750,    1000,   5000,   10000,  25000,   50000,
      75000, 100000, 200000, 300000, 400000, 500000, 750000, 1000000,
  };
  int cases_size = ARRAY_SIZE(cases);  // number of total cases (26)

  shuffle_cases(cases, cases_size);  // cases are shuffled

  printf("First, pick a case to keep.\n");
  int initial_index = pick_case_index(cases, cases_size);
  int initial_amount =
      remove_case_and_get_amount(cases, cases_size, initial_index);
  printf("You picked %d, looks like a keeper.\n", initial_index + 1);

  // input: amount in each case, number of cases, number of cases to eliminate
  eliminate_cases(cases, cases_size, 6);

  // input: amount in each case, number of cases, number of cases to eliminate
  // output: off
  offer(cases, cases_size, initial_amount);

  eliminate_cases(cases, cases_size, 5);
  offer(cases, cases_size, initial_amount);

  eliminate_cases(cases, cases_size, 4);
  offer(cases, cases_size, initial_amount);

  eliminate_cases(cases, cases_size, 3);
  offer(cases, cases_size, initial_amount);

  eliminate_cases(cases, cases_size, 2);
  offer(cases, cases_size, initial_amount);

  // while there are more than 1 unopened cases (excluding the one you kept), it
  // wil always prompt user to eliminate 1 case at a time
  while (cases_remaining(cases, cases_size) > 1) {
    eliminate_cases(cases, cases_size, 1);
    offer(cases, cases_size, initial_amount);
  }

  int last_case = get_last_remaining_case(cases, cases_size);
  int last_amount = cases[last_case];
  printf("\nDo you want to swap your case with case %d?\n", last_case + 1);
  bool decision = get_decision();
  if (decision) {
    printf("\nYour initial case had $%d.\n", initial_amount);
    printf("You won $%d.\n", last_amount);
  } else {
    printf("\nThe last case had $%d.\n", last_amount);
    printf("You won $%d.\n", initial_amount);
  }

  return 0;
}

void shuffle_cases(int cases[], int cases_size) {
  srand(42);
  for (int shuffle = 0; shuffle < 100; ++shuffle) {
    for (int i = 0; i < cases_size; ++i) {
      int j = rand() % cases_size;
      int temp = cases[i];
      cases[i] = cases[j];
      cases[j] = temp;
    }
  }
}

// eliminates the 0-indexed case, returns the amount in the case they eliminated
int remove_case_and_get_amount(int cases[], int cases_size, int index) {
  int amount = cases[index];
  cases[index] = -1;
  return amount;
}

void offer(int cases[], int cases_size, int initial_amount) {
  int offer_amount = cases_average(cases, cases_size, initial_amount);
  printf("\nYour offer to quit now is $%d, deal or no deal?.\n", offer_amount);
  bool deal = get_decision();
  if (deal) {
    printf("\nYour case was worth: $%d\n", initial_amount);
    printf("You walked away with $%d.\n", offer_amount);
    exit(0);
  }
}

// functions to create
int pick_case_index(int cases[], int cases_size) {
  int caseIndex = 0;  // counting the case 0-index so i can print the case index
                      // instead of amount inside the cases
  printf("Eligible cases: ");
  for (int n = 0; n < cases_size; n++) {
    if (cases[n] != -1) {        // if the case amount isnt -1
      caseIndex = n + 1;         // prints 1-index
      printf("%d ", caseIndex);  // print the 1-index of the case
    }
  }
  printf("\n");
  int caseToEliminate;
  do {
    printf("Pick a case: ");
    scanf(" %d", &caseToEliminate);  // in 1-index
    caseToEliminate -= 1;            // converting from 1-index to 0-index
  } while (caseToEliminate < 0 || caseToEliminate > (cases_size - 1) ||
           cases[caseToEliminate] ==
               -1);  // repeats while caseToEliminate is less than 1 or greater
                     // than 26 or the amount in the case is -1
  return caseToEliminate;  // returns 0-index of selected case
}

bool get_decision(void) {
  int decision;
  do {
    printf("Decide now (0 for no, 1 for yes): ");
    scanf(" %d", &decision);
  } while (decision != 0 &&
           decision != 1);  // while decision is not 0 and decision is not 1
                            // (while decision is not <0 or 1>)
  return decision;
}

int cases_average(int cases[], int cases_size, int initial_amount) {
  int sum = initial_amount;  // adding initial amount to the case
  // REPLACE WITH CASES_REMAINING LATER?
  int noneliminatedCaseCounter =
      1;  // counting number of uneliminated cases (to calculate the avg)
  for (int n = 0; n < cases_size; n++) {  // repeating for all cases
    if (cases[n] != -1) {                 // if the case is still eligible
      sum += cases[n];
      noneliminatedCaseCounter++;
    }
  }
  int average = sum / noneliminatedCaseCounter;
  return average;
}

int cases_remaining(int cases[], int cases_size) {
  int casesRemaining = 0;
  for (int n = 0; n < cases_size; n++) {
    if (cases[n] != -1) {
      casesRemaining++;
    }
  }
  return casesRemaining;  // returns number of unopened cases
}

int get_last_remaining_case(int cases[], int cases_size) {
  int lastCase = 0;
  for (int n = 0; n < cases_size; n++) {
    if (cases[n] != -1) {  // if the case amount isn't -1, then it is unopened
      lastCase = n;        // storing the index of the unopened case
    }
  }
  return lastCase;
}

void eliminate_cases(int cases[], int cases_size, int eliminated) {
  printf("\nOpen %d case(s) to eliminate\n", eliminated);
  for (int n = 0; n < eliminated; n++) {
    // returns 0-index caseToEliminate
    int caseToEliminate = pick_case_index(cases, cases_size);
    // returns amount in 0-index case
    int amount = remove_case_and_get_amount(cases, cases_size, caseToEliminate);
    printf("Case %d is worth $%d, it's gone now.\n", (caseToEliminate + 1),
           amount);
  }
}

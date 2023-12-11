// main.c
#include <stdio.h>
#include "basketball_stats.h"

int main() {
    Team myTeam;
    initializeTeam(&myTeam);

    addPlayer(&myTeam, "Lebron James", 90, 42, 33);
    addPlayer(&myTeam, "Stephen Curry", 99, 40, 20);
    addPlayer(&myTeam, "kevin Durant", 78,50, 18);
    addPlayer(&myTeam, "Giannis Antetokounmpo", 80, 38, 15);
    addPlayer(&myTeam, "James harden", 50, 42, 26);

    printf("Original Team Stats:\n");
    displayTeamStats(&myTeam);

    printf("\nSorting players by points:\n");
    sortPlayersByPoints(&myTeam);
    displayTeamStats(&myTeam);

    printf("\nSorting players by assists:\n");
    sortPlayersByAssists(&myTeam);
    displayTeamStats(&myTeam);
}

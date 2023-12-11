// basketball_stats.c
#include "basketball_stats.h"
#include <stdio.h>

void initializeTeam(Team *team) {
    team->num_players = 0;
}

void addPlayer(Team *team, const char *name, int points, int assists, int rebounds) {
    if (team->num_players < MAX_PLAYERS) {
        Player newPlayer;
        snprintf(newPlayer.name, PLAYER_NAME_LENGTH, "%s", name);
        newPlayer.points = points;
        newPlayer.assists = assists;
        newPlayer.rebounds = rebounds;

        team->players[team->num_players++] = newPlayer;
    } else {
        printf("Team is full. Cannot add more players.\n");
    }
}

void displayPlayerStats(const Player *player) {
    printf("Player: %s\n", player->name);
    printf("Points: %d\n", player->points);
    printf("Assists: %d\n", player->assists);
    printf("Rebounds: %d\n", player->rebounds);
    printf("Efficiency: %.2f\n", calculatePlayerEfficiency(player));
}

void displayTeamStats(const Team *team) {
    printf("Team Stats:\n");
    for (int i = 0; i < team->num_players; i++) {
        printf("Player %d:\n", i + 1);
        displayPlayerStats(&team->players[i]);
        printf("\n");
    }
}

float calculatePlayerEfficiency(const Player *player) {
    // A simple efficiency metric (points + assists + rebounds)
    return (float)(player->points + player->assists + player->rebounds);
}

void sortPlayersByPoints(Team *team) {
    // Sort players based on points using bubble sort
    for (int i = 0; i < team->num_players - 1; i++) {
        for (int j = 0; j < team->num_players - i - 1; j++) {
            if (team->players[j].points < team->players[j + 1].points) {
                // Swap players
                Player temp = team->players[j];
                team->players[j] = team->players[j + 1];
                team->players[j + 1] = temp;
            }
        }
    }
}

void sortPlayersByAssists(Team *team) {
    // Sort players based on assists using bubble sort
    for (int i = 0; i < team->num_players - 1; i++) {
        for (int j = 0; j < team->num_players - i - 1; j++) {
            if (team->players[j].assists < team->players[j + 1].assists) {
                // Swap players
                Player temp = team->players[j];
                team->players[j] = team->players[j + 1];
                team->players[j + 1] = temp;
            }
        }
    }
}

void sortPlayersByRebounds(Team *team) {
    // Sort players based on rebounds using bubble sort
    for (int i = 0; i < team->num_players - 1; i++) {
        for (int j = 0; j < team->num_players - i - 1; j++) {
            if (team->players[j].rebounds < team->players[j + 1].rebounds) {
                // Swap players
                Player temp = team->players[j];
                team->players[j] = team->players[j + 1];
                team->players[j + 1] = temp;
            }
        }
    }
}

void findMostEfficientPlayer(const Team *team) {
    float maxEfficiency = -1;
    int index = -1;

    for (int i = 0; i < team->num_players; i++) {
        float efficiency = calculatePlayerEfficiency(&team->players[i]);
        if (efficiency > maxEfficiency) {
            maxEfficiency = efficiency;
            index = i;
        }
    }

    if (index != -1) {
        printf("Most efficient player:\n");
        displayPlayerStats(&team->players[index]);
    } else {
        printf("No players in the team.\n");
    }
}

void calculateTeamAverages(const Team *team) {
    float totalPoints = 0, totalAssists = 0, totalRebounds = 0;

    for (int i = 0; i < team->num_players; i++) {
        totalPoints += team->players[i].points;
        totalAssists += team->players[i].assists;
        totalRebounds += team->players[i].rebounds;
    }

    if (team->num_players > 0) {
        float avgPoints = totalPoints / team->num_players;
        float avgAssists = totalAssists / team->num_players;
        float avgRebounds = totalRebounds / team->num_players;

        printf("Team Averages:\n");
        printf("Average Points: %.2f\n", avgPoints);
        printf("Average Assists: %.2f\n", avgAssists);
        printf("Average Rebounds: %.2f\n", avgRebounds);
    } else {
        printf("No players in the team.\n");
    }
}


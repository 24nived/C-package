// basketball_stats.h
#ifndef BASKETBALL_STATS_H
#define BASKETBALL_STATS_H

#define MAX_PLAYERS 50
#define PLAYER_NAME_LENGTH 30

typedef struct {
    char name[PLAYER_NAME_LENGTH];
    int points;
    int assists;
    int rebounds;
} Player;

typedef struct {
    Player players[MAX_PLAYERS];
    int num_players;
} Team;

void initializeTeam(Team *team);
void addPlayer(Team *team, const char *name, int points, int assists, int rebounds);
void displayPlayerStats(const Player *player);
void displayTeamStats(const Team *team);
float calculatePlayerEfficiency(const Player *player);
void sortPlayersByPoints(Team *team);
void sortPlayersByAssists(Team *team);
void sortPlayersByRebounds(Team *team);
void findMostEfficientPlayer(const Team *team);
void calculateTeamAverages(const Team *team);

#endif

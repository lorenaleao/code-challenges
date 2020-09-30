#include <bits/stdc++.h>

using namespace std;

#define INF 200
#define endl '\n'
#define DEBUG 0

int next_player(int i, int n) {
    if(i == n-1) 
        return 0;
    else
        return i+1;
}

int check_winner(vector<vector<int>>& players_cards, int winner_idx) {
    for(int i = 0; i < winner_idx; i++) {
        for(int j = 0; j < players_cards[i].size()-1; j++) {
            if(players_cards[i][j] == 4) {
                return i;
            }
        }
    }

    return -1;
}

int check_winner_at_beg(vector<vector<int>>& players_cards, int player_holding_curinga) {
    for(int i = 0; i < players_cards.size(); i++) {
        for(int j = 0; j < players_cards[i].size()-1; j++) {

            if(DEBUG){
                cout << players_cards[i][j] << ' ' << player_holding_curinga << endl;
            }
            if(players_cards[i][j] == 4 and i != player_holding_curinga) {
                return i;
            }
        }
    }
    return -1;
}

int find_min(vector<int>& player_cards) {
    int min_quant = INF;
    int min_idx = -1;
    for(int i = 0; i < player_cards.size()-1; i++) {
        if(player_cards[i] != 0 and player_cards[i] < min_quant) {
            min_quant = player_cards[i];
            min_idx = i;
        }
    }

    return min_idx;
}

int main() {
    int n, k; cin >> n >> k;
    vector<vector<int>> players_cards(n, vector<int>(14));
    vector<priority_queue<pair<int, int> > > pq(n);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 4; j++) {
            char c;
            cin >> c;
            switch(c) {
                case 'A':
                    players_cards[i][0]++;
                    break;
                case '2':
                    players_cards[i][1]++;
                    break;
                case '3':
                    players_cards[i][2]++;
                    break;
                case '4':
                    players_cards[i][3]++;
                    break;
                case '5':
                    players_cards[i][4]++;
                    break;
                case '6':
                    players_cards[i][5]++;
                    break;
                case '7':
                    players_cards[i][6]++;
                    break;
                case '8':
                    players_cards[i][7]++;
                    break;
                case '9':
                    players_cards[i][8]++;
                    break;
                case 'D':
                    players_cards[i][9]++;
                    break;
                case 'Q':
                    players_cards[i][10]++;
                    break;
                case 'J':
                    players_cards[i][11]++;
                    break;
                case 'K':
                    players_cards[i][12]++;
                    break;
            }
        }
    }

   if(DEBUG) {
        for(int i = 0; i < players_cards.size(); i++) {
            for(int j = 0; j < players_cards[i].size(); j++) {
                // int quant = players_cards[i][j];
                // if(quant != 0)
                //     pq[i].emplace(players_cards[i][j], j);
                cout << players_cards[i][j] << ' ';
            }
            cout << endl;
        }
        cout << endl;
   }

    bool somebody_won = false;
    int winner = -1;
    
    
    bool posso_passar_curinga = false;
    
    int curr_player = k-1;
    int player_holding_curinga = curr_player;
    players_cards[player_holding_curinga][13] = 1; //curinga

    int initial_winner = check_winner_at_beg(players_cards, player_holding_curinga);
    if(initial_winner != -1) {
        somebody_won = true;
        winner = initial_winner;
    }
    

    while(!somebody_won) {
        int next = next_player(curr_player, n);
        if(DEBUG) cout << "curr_player: " << curr_player << endl;
        if(DEBUG) cout << "next_player: " << next << endl;
        if(DEBUG) cout << "player_holding_curinga: " << player_holding_curinga << endl;
        if(DEBUG) cout << "posso_passar_curinga: " << posso_passar_curinga << endl;
        if(player_holding_curinga == curr_player and posso_passar_curinga) {
            players_cards[curr_player][13] = 0;
            player_holding_curinga = next;
        } else {
            //pegando o tipo de carta que o jog. atual tem menos
            // int count = pq[curr_player].top().first;
            // int card = pq[curr_player].top().second;
            // pq[curr_player].pop();
            // pq[curr_player].emplace(count-1, card); //atualizando
            
            // int next = next_player(curr_player, n);
            // players_cards[next][card]++; //passando a carta pro prox. jogador
            // pq[next] = priority_queue<pair<int, int> >();
            int card = find_min(players_cards[curr_player]);
            if(DEBUG) cout << "min: " << card << endl;
            if (card != -1) {
                players_cards[curr_player][card]--;
                players_cards[next][card]++;

                if(players_cards[next][card] == 4) {
                    somebody_won = true;
                    winner = next;
                    // int another_winner = check_winner(players_cards, winner);
                    // if(another_winner != -1)
                    //     winner = another_winner;
                }
            }
        }
        curr_player = next;
        players_cards[player_holding_curinga][13]++;
        posso_passar_curinga = (players_cards[player_holding_curinga][13] == n+1);

        if(DEBUG) {
            for(int i = 0; i < players_cards.size(); i++) {
                for(int j = 0; j < players_cards[i].size(); j++) {
                    cout << players_cards[i][j] << ' ';
                }
                cout << endl;
            }
            cout << endl;
        }
    }

    // cout << "winner: ";
    cout << winner+1;
    return 0;
}
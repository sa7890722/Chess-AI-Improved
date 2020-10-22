#include <bits/stdc++.h>
#include "Moves.h"
using namespace std;

char board[8][9]={"RNBKQBNR", "PPPPPPPP", "________", "________", "________", "________", "pppppppp", "rnbkqbnr"};
int points[8][8]={{+8, 7, 6, 900, 19, 6, 7, 8}, {1, 1, 1, 1, 1, 1, 1, 1},
				{0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0},
				{-1, -1, -1, -1, -1, -1, -1, -1}, {-5, -4, -3, -90, -19, -6, -7, -8}};

int moveX = -1, moveY = -1;
int toX = -1, toY = -1;
long long best_states[15000000] = {0ll};
long long nodes[10] = {0};
int moov=0;
vector<pair<long long, long long>> order_moves;
long long best_move(int depth, int max_depth, int start_score, char state[8][9], int state_score[8][8], long long alpha, long long beta){
    ++moov;
    long long curr = 0;
    long long hash_value = 0;

    for(int i=0; i<8; ++i){
        for(int j=0; j<8; ++j){
            curr += state_score[i][j];
            if(state_score[i][j]==0) continue;
            hash_value += (i*i)+(j*j*j)+(((state_score[i][j])*i*j)^100007)+(i^j);
        }
    }
    //cout << hash_value << endl;
   	if(max_depth == 3 && depth >= 3){
        order_moves.push_back({curr, hash_value});
        //cout << curr << " " << hash_value << endl;
        return curr;
    }
    if(max_depth == 7 && depth >= 3 && best_states[hash_value]==0){
        return curr;
    }
    /*if(vr[hash_value]>=3 && depth!=0){
        return vr[hash_value];
    }*/
	if(depth == max_depth){
        //printf("Return value in the last node = %lld\n", current_score);
		return curr;
	}

    nodes[depth]++;
	// TURN OF THE PLAYER THAT MAXIMIZES THE SCORE :
	int mid[] = {0, 7, 1, 6, 2, 5, 3, 4};
	int mr[] = {0, 7, 1, 6, 2, 5, 3, 4};
	if(depth % 2 == 0){
        vector<pair<int, int>> temp[6];
        for(int i=0; i<8; ++i){
            for(int j=0; j<8; ++j){
                if(state[i][mr[j]] == 'P') temp[0].push_back({i, mr[j]});
                if(state[i][mr[j]] == 'R' || state[i][mr[j]] == 'N') temp[1].push_back({i, mr[j]});
                if(state[i][mr[j]] == 'B') temp[2].push_back({i, mr[j]});
                if(state[i][mr[j]] == 'Q') temp[3].push_back({i, mr[j]});
                if(state[i][mr[j]] == 'K') temp[4].push_back({i, mr[j]});
            }
        }
		//printf("Reached the maximizing player\n");
		long long ans = -1e8;
		for(int er=7; er>=0; --er){
			for(int j=0; j<8; ++j){
			    int i = er;
                //cout << i << " " << mid[j] << endl;
				if(isUpper(state[i][mid[j]]) && state_score[i][mid[j]]>0){
					vector<pair<int, int>> possible_moves = get_moves(i, mid[j], state);
					if(possible_moves.size() == 0) continue;
					for(auto u : possible_moves){
						int x = u.first, y = u.second;
						long long removed_points = state_score[x][y];
						char state_copy[8][9];
						int state_score_copy[8][8];
						for(int k=0; k<8; ++k){
							for(int io=0; io<9; ++io){
								if(io!=8) state_score_copy[k][io] = state_score[k][io];
								state_copy[k][io] = state[k][io];
							}
						}
						long long new_score = curr - state_score[x][y];
						if(depth >= 3 && new_score == start_score) continue;

						state_copy[x][y] = state_copy[i][mid[j]];
						state_copy[i][mid[j]] = '_';
						state_score_copy[x][y] = state_score_copy[i][mid[j]];
						state_score_copy[i][mid[j]] = 0;

						//long long res = best_move(depth+1, state_copy, state_score_copy, alpha, beta);
						long long res = best_move(depth+1, max_depth, start_score, state_copy, state_score_copy, alpha, beta);
						//printf("%lld\n", res);
						ans = max(ans, res);
						alpha = max(alpha, ans);
						if(beta <= alpha) break;
						if(depth == 0 && ans == res){
							printf("got the answer = %lld\n", ans);
							moveX = i;
							moveY = mid[j];
							toX = x;
							toY = y;
						}
					}
				}
			}
		}
		return ans;
	}


	else{

		long long ans = +1e8;
		vector<pair<int, int>> temp[6];
        for(int i=0; i<8; ++i){
            for(int j=0; j<8; ++j){
                if(state[i][mr[j]] == 'p') temp[0].push_back({i, mr[j]});
                if(state[i][mr[j]] == 'r' || state[i][mr[j]] == 'n') temp[1].push_back({i, mr[j]});
                if(state[i][mr[j]] == 'b') temp[2].push_back({i, mr[j]});
                if(state[i][mr[j]] == 'q') temp[3].push_back({i, mr[j]});
                if(state[i][mr[j]] == 'k') temp[4].push_back({i, mr[j]});
            }
        }
		//printf("Reached the minimizing player\n");
		for(int er=0; er<8; ++er){
			for(int j=0; j<8; ++j){
                int i = er;
				if(isLower(state[i][mid[j]]) && state_score[i][mid[j]]<0){
					vector<pair<int, int>> possible_moves = get_moves(i, mid[j], state);
					if(possible_moves.size() == 0) continue;
					for(auto u : possible_moves){
						int x = u.first, y = u.second;
						long long removed_points = state_score[x][y];
						char state_copy[8][9];
						int state_score_copy[8][8];
						for(int k=0; k<8; ++k){
							for(int io=0; io<9; ++io){
								if(io!=9) state_score_copy[k][io] = state_score[k][io];
								state_copy[k][io] = state[k][io];
							}
						}
						long long new_score = curr - state_score[x][y];
						if(depth >= 3 && new_score == start_score) continue;

						state_copy[x][y] = state_copy[i][mid[j]];
						state_copy[i][mid[j]] = '_';
						state_score_copy[x][y] = state_score_copy[i][mid[j]];
						state_score_copy[i][mid[j]] = 0;

						//long long res = best_move(depth+1, state_copy, state_score_copy, alpha, beta);
						long long res = best_move(depth+1, max_depth, start_score, state_copy, state_score_copy, alpha, beta);
						ans = min(ans, res);
						beta = min(res, beta);
						if(beta <= alpha) break;
					}
				}
			}
		}
		return ans;

	}

}

int main(){

	printf("Oh my dear friend lets start the game of chess.\n");
	for(int i=0; i<8; ++i){
		for(int j=0; j<8; ++j){
			printf("%c", board[i][j]);
		}
		printf("\n");
	}

	printf("\n");
	printf("\n");
	printf("_______________________________\n");
	for(int i=0; i<8; ++i){
		for(int j=0; j<8; ++j){
			printf(" %c |", board[i][j]);
		}

		printf("\n");
		printf("_______________________________\n");
	}
	printf("\n");
	printf("\n");


	int turn = 0;
	int counter = 50;
	while(true){


		if(turn == 0){
			string from, to;
			cin >> from >> to;
			int fromX = int(from[0])-'0';
			int fromY = int(from[1])-'0';
			int totheX = int(to[0])-'0';
			int totheY = int(to[1])-'0';
			vector<pair<int, int>> valid_moves = get_moves(fromX, fromY, board);
			int ok = 0;
			for(auto u: valid_moves){
				if(u.first == totheX && u.second == totheY) ok=1;
				printf("%d %d\n", u.first, u.second);
			}
			if(ok == 0){
				printf("Try Again\n");
				continue;
			}
			board[totheX][totheY] = board[fromX][fromY];
			board[fromX][fromY] = '_';
			points[totheX][totheY] = points[fromX][fromY];
			points[fromX][fromY] = 0;
			turn ^= 1;
		}

		else{
			//long long res = best_move(0, board, points, -1e9, +1e9);
			long long current_score = 0;
			for(int i=0; i<8; ++i){
                for(int j=0; j<8; ++j){
                    current_score += points[i][j];
                }
			}
			moov=0;
			int dpth = 3;
			long long res = best_move(0, dpth, current_score, board, points, -1e9, +1e9);
			sort(order_moves.rbegin(), order_moves.rend());
			//cout << order_moves.size() << endl;
            int counter = 0;
            for(auto x:order_moves){
                ++counter;
                if(counter >= (order_moves.size())/2) break;
                best_states[x.second] = x.first;
               // cout << x.first << " " << x.second << endl;
            }
           // cout << counter << endl;
            cout << endl;

            cout << endl;
            cout << endl;


            for(int i=0; i<10; ++i){
                cout << nodes[i] << " ";
                nodes[i]=0;
            }
            cout << endl;


            cout << endl;
            cout << endl;
            cout << endl;


            moov = 0;
           	dpth = 7;
            res = best_move(0, dpth, current_score, board, points, -1e9, +1e9);
            for(auto x:order_moves){
                best_states[x.second] = 0ll;
            }
            order_moves.clear();


			cout << endl;

            cout << endl;
            cout << endl;


            for(int i=0; i<10; ++i){
                cout << nodes[i] << " ";
                nodes[i]=0;
            }
            cout << endl;


            cout << endl;
            cout << endl;
            cout << endl;



			printf("The evaluated best move is : %d\n", res);
			cout << moov << endl;
			board[toX][toY] = board[moveX][moveY];
			board[moveX][moveY] = '_';
			points[toX][toY] = points[moveX][moveY];
			points[moveX][moveY] = 0;
			turn ^= 1;
		}

		/*for(int i=0; i<8; ++i){
			for(int j=0; j<8; ++j){
				printf("%d\t", points[i][j]);
			}
			printf("\n\n");
		}*/

		printf("\n");
		printf("\n");
		printf("_______________________________\n");
		for(int i=0; i<8; ++i){
			for(int j=0; j<8; ++j){
				printf(" %c |", board[i][j]);
			}

			printf("\n");
			printf("_______________________________\n");
		}
		printf("\n");
		printf("\n");

		--counter;
		if(counter == 0) break;
	}


	return 0;
}

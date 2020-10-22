#include <bits/stdc++.h>
using namespace std;

bool isLower(char c){
	if(c >= 'a' && c <= 'z') return true;
	else return false;
}

bool isUpper(char c){
	if(c >= 'A' && c <= 'Z') return true;
	else return false;
}

vector<pair<int, int>> get_moves(int i, int j, char state[8][9]){
	
	vector<pair<int, int>> set_of_moves;
	/*if(state[i][j] == '_' || isLower(state[i][j])){
		printf("Try making the move again");
		return set_of_moves;
	}*/

	// MAKE UP THE MOVES FOR THE KING
	if(state[i][j] == 'K'){

		/*
			i+1, j
			i, j+1
			i-1, j
			i, j-1
			i+1, j+1
			i-1, j-1
			i+1, j-1
			i-1, j+1
		*/



		if(i+1<8 && (state[i+1][j] == '_' || isLower(state[i+1][j]))){
			set_of_moves.push_back({i+1, j});
		}
		if(i+1<8 && j+1<8 && (state[i+1][j+1] == '_' || isLower(state[i+1][j+1]))){
			set_of_moves.push_back({i+1, j+1});
		}
		if(j+1<8 && (state[i][j+1] == '_' || isLower(state[i][j+1]))){
			set_of_moves.push_back({i, j+1});
		}
		if(j-1>=0 && (state[i][j-1] == '_' || isLower(state[i][j-1]))){
			set_of_moves.push_back({i, j-1});
		}
		if(i-1>=0 && (state[i-1][j] == '_' || isLower(state[i-1][j]))){
			set_of_moves.push_back({i-1, j});
		}
		if(i+1<8 && j-1>=0 && (state[i+1][j-1] == '_' || isLower(state[i+1][j-1]))){
			set_of_moves.push_back({i+1, j-1});
		}
		if(i-1>=0 && j-1>=0 && (state[i-1][j-1] == '_' || isLower(state[i-1][j-1]))){
			set_of_moves.push_back({i-1, j-1});
		}
		if(i-1>=0 && j+1<8 && (state[i-1][j+1] == '_' || isLower(state[i-1][j+1]))){
			set_of_moves.push_back({i-1, j+1});
		}
		return set_of_moves;
	}


	if(state[i][j] == 'k'){

		/*
			i+1, j
			i, j+1
			i-1, j
			i, j-1
			i+1, j+1
			i-1, j-1
			i+1, j-1
			i-1, j+1
		*/



		if(i+1<8 && (state[i+1][j] == '_' || isUpper(state[i+1][j]))){
			set_of_moves.push_back({i+1, j});
		}
		if(i+1<8 && j+1<8 && (state[i+1][j+1] == '_' || isUpper(state[i+1][j+1]))){
			set_of_moves.push_back({i+1, j+1});
		}
		if(j+1<8 && (state[i][j+1] == '_' || isUpper(state[i][j+1]))){
			set_of_moves.push_back({i, j+1});
		}
		if(j-1>=0 && (state[i][j-1] == '_' || isUpper(state[i][j-1]))){
			set_of_moves.push_back({i, j-1});
		}
		if(i-1>=0 && (state[i-1][j] == '_' || isUpper(state[i-1][j]))){
			set_of_moves.push_back({i-1, j});
		}
		if(i+1<8 && j-1>=0 && (state[i+1][j-1] == '_' || isUpper(state[i+1][j-1]))){
			set_of_moves.push_back({i+1, j-1});
		}
		if(i-1>=0 && j-1>=0 && (state[i-1][j-1] == '_' || isUpper(state[i-1][j-1]))){
			set_of_moves.push_back({i-1, j-1});
		}
		if(i-1>=0 && j+1<8 && (state[i-1][j+1] == '_' || isUpper(state[i-1][j+1]))){
			set_of_moves.push_back({i-1, j+1});
		}
		return set_of_moves;
	}


	if(state[i][j] == 'N'){
		/*
			i+2, j-1,
			i+2, j+1, 
			i+1, j-2,
			i+1, j+2,
			i-2, j+1,
			i-2, j-1,
			i-1, j+2, 
			i-1, j-2. 
		*/

		if(i+2<8 && j-1>=0 && (state[i+2][j-1] == '_' || isLower(state[i+2][j-1]))){
			set_of_moves.push_back({i+2, j-1});
		}
		if(i+2<8 && j+1<8 && (state[i+2][j+1]  == '_' || isLower(state[i+2][j+1]))){
			set_of_moves.push_back({i+2, j+1});
		}
		if(i+1<8 && j-2>=0 && (state[i+1][j-2]  == '_' || isLower(state[i+1][j-2]))){
			set_of_moves.push_back({i+1, j-2});
		}
		if(i+1<8 && j+2<8 && (state[i+1][j+2]  == '_' || isLower(state[i+1][j+2]))){
			set_of_moves.push_back({i+1, j+2});
		}
		if(i-2>=0 && j+1<8 && (state[i-2][j+1]  == '_' || isLower(state[i-2][j+1]))){
			set_of_moves.push_back({i-2, j+1});
		}
		if(i-2>=0 && j-1>=0 && (state[i-2][j-1]  == '_' || isLower(state[i-2][j-1]))){
			set_of_moves.push_back({i-2, j-1});
		}
		if(i-1>=0 && j+2<8 && (state[i-1][j+2]  == '_' || isLower(state[i-1][j+2]))){
			set_of_moves.push_back({i-1, j+2});
		}
		if(i-1>=0 && j-2>=0 && (state[i-1][j-2]  == '_' || isLower(state[i-1][j-2]))){
			set_of_moves.push_back({i-1, j-2});
		}
		return set_of_moves;
	}

	if(state[i][j] == 'n'){
		/*
			i+2, j-1,
			i+2, j+1, 
			i+1, j-2,
			i+1, j+2,
			i-2, j+1,
			i-2, j-1,
			i-1, j+2, 
			i-1, j-2. 
		*/

		if(i+2<8 && j-1>=0 && (state[i+2][j-1] == '_' || isUpper(state[i+2][j-1]))){
			set_of_moves.push_back({i+2, j-1});
		}
		if(i+2<8 && j+1<8 && (state[i+2][j+1]  == '_' || isUpper(state[i+2][j+1]))){
			set_of_moves.push_back({i+2, j+1});
		}
		if(i+1<8 && j-2>=0 && (state[i+1][j-2]  == '_' || isUpper(state[i+1][j-2]))){
			set_of_moves.push_back({i+1, j-2});
		}
		if(i+1<8 && j+2<8 && (state[i+1][j+2]  == '_' || isUpper(state[i+1][j+2]))){
			set_of_moves.push_back({i+1, j+2});
		}
		if(i-2>=0 && j+1<8 && (state[i-2][j+1]  == '_' || isUpper(state[i-2][j+1]))){
			set_of_moves.push_back({i-2, j+1});
		}
		if(i-2>=0 && j-1>=0 && (state[i-2][j-1]  == '_' || isUpper(state[i-2][j-1]))){
			set_of_moves.push_back({i-2, j-1});
		}
		if(i-1>=0 && j+2<8 && (state[i-1][j+2]  == '_' || isUpper(state[i-1][j+2]))){
			set_of_moves.push_back({i-1, j+2});
		}
		if(i-1>=0 && j-2>=0 && (state[i-1][j-2]  == '_' || isUpper(state[i-1][j-2]))){
			set_of_moves.push_back({i-1, j-2});
		}
		return set_of_moves;
	}


	if(state[i][j] == 'P'){

		/*
			i+1, j
			i+2, j
			i+1, j+1
			i+1, j-1
		*/

		if(i+1<8 && state[i+1][j] == '_'){
			set_of_moves.push_back({i+1, j});
		}

		if(i==1 && i+2<8 && state[i+1][j] == '_' && state[i+2][j] == '_'){
			set_of_moves.push_back({i+2, j});
		}

		if(i+1<8 && j+1<8 && isLower(state[i+1][j+1])){
			set_of_moves.push_back({i+1, j+1});
		}

		if(i+1<8 && j-1>=0  && isLower(state[i+1][j-1])){
			set_of_moves.push_back({i+1, j-1});
		}
		return set_of_moves;
	}

	if(state[i][j] == 'p'){

		/*
			i+1, j
			i+2, j
			i+1, j+1
			i+1, j-1
		*/

		if(i-1>=0 && state[i-1][j] == '_'){
			set_of_moves.push_back({i-1, j});
		}

		if(i==6 && i-2>=0 && state[i-1][j] == '_' && state[i-2][j] == '_'){
			set_of_moves.push_back({i-2, j});
		}

		if(i-1>=0 && j-1>=0 && isUpper(state[i-1][j-1])){
			set_of_moves.push_back({i-1, j-1});
		}

		if(i-1>=0 && j+1<8  && isUpper(state[i-1][j+1])){
			set_of_moves.push_back({i-1, j+1});
		}
		return set_of_moves;
	}

	if(state[i][j] == 'B'){
		/* all diagonals can be traversed until a piece is reached */

		int x=i, y=j;
		while(x+1<8 && y+1<8){
			++x, ++y;
			if(state[x][y] == '_'){
				set_of_moves.push_back({x, y});
			}

			else if(isLower(state[x][y])){
				set_of_moves.push_back({x, y});
				break;
			}

			else{
				break;
			}
		}

		x=i, y=j;
		while(x-1>=0 && y+1<8){
			--x, ++y;
			if(state[x][y] == '_'){
				set_of_moves.push_back({x, y});
			}

			else if(isLower(state[x][y])){
				set_of_moves.push_back({x, y});
				break;
			}

			else{
				break;
			}
		}

		x=i, y=j;
		while(x+1<8 && y-1>=0){
			++x, --y;
			if(state[x][y] == '_'){
				set_of_moves.push_back({x, y});
			}

			else if(isLower(state[x][y])){
				set_of_moves.push_back({x, y});
				break;
			}

			else{
				break;
			}
		}

		x=i, y=j;
		while(x-1>=0 && y-1>=0){
			--x, --y;
			if(state[x][y] == '_'){
				set_of_moves.push_back({x, y});
			}

			else if(isLower(state[x][y])){
				set_of_moves.push_back({x, y});
				break;
			}

			else{
				break;
			}
		}

		return set_of_moves;
	}


	if(state[i][j] == 'b'){
		/* all diagonals can be traversed unitl a piece is reached */

		int x=i, y=j;
		while(x+1<8 && y+1<8){
			++x, ++y;
			if(state[x][y] == '_'){
				set_of_moves.push_back({x, y});
			}

			else if(isUpper(state[x][y])){
				set_of_moves.push_back({x, y});
				break;
			}

			else{
				break;
			}
		}

		x=i, y=j;
		while(x-1>=0 && y+1<8){
			--x, ++y;
			if(state[x][y] == '_'){
				set_of_moves.push_back({x, y});
			}

			else if(isUpper(state[x][y])){
				set_of_moves.push_back({x, y});
				break;
			}

			else{
				break;
			}
		}

		x=i, y=j;
		while(x+1<8 && y-1>=0){
			++x, --y;
			if(state[x][y] == '_'){
				set_of_moves.push_back({x, y});
			}

			else if(isUpper(state[x][y])){
				set_of_moves.push_back({x, y});
				break;
			}

			else{
				break;
			}
		}

		x=i, y=j;
		while(x-1>=0 && y-1>=0){
			--x, --y;
			if(state[x][y] == '_'){
				set_of_moves.push_back({x, y});
			}

			else if(isUpper(state[x][y])){
				set_of_moves.push_back({x, y});
				break;
			}

			else{
				break;
			}
		}

		return set_of_moves;
	}



	if(state[i][j] == 'R'){

		/*
			all horizontal and vertical rows can be traversed until encountered by a piece.
		*/

		int x=i, y=j;

		x=i, y=j;
		while(x+1<8){
			++x;
			if(state[x][y] == '_'){
				set_of_moves.push_back({x, y});
			}

			else if(isLower(state[x][y])){
				set_of_moves.push_back({x, y});
				break;
			}

			else{
				break;
			}
		}

		x=i, y=j;
		while(x-1>=0){
			--x;
			if(state[x][y] == '_'){
				set_of_moves.push_back({x, y});
			}

			else if(isLower(state[x][y])){
				set_of_moves.push_back({x, y});
				break;
			}
			else{
				break;
			}
		}

		x=i, y=j;
		while(y-1>=0){
			--y;
			if(state[x][y] == '_'){
				set_of_moves.push_back({x, y});
			}

			else if(isLower(state[x][y])){
				set_of_moves.push_back({x, y});
				break;
			}

			else{
				break;
			}
		}

		x=i, y=j;
		while(y+1<8){
			++y;
			if(state[x][y] == '_'){
				set_of_moves.push_back({x, y});
			}

			else if(isLower(state[x][y])){
				set_of_moves.push_back({x, y});
				break;
			}

			else{
				break;
			}
		}

		return set_of_moves;
	}


	if(state[i][j] == 'r'){

		/*
			all horizontal and vertical rows can be traversed until encountered by a piece.
		*/

		int x=i, y=j;

		x=i, y=j;
		while(x+1<8){
			++x;
			if(state[x][y] == '_'){
				set_of_moves.push_back({x, y});
			}

			else if(isUpper(state[x][y])){
				set_of_moves.push_back({x, y});
				break;
			}

			else{
				break;
			}
		}

		x=i, y=j;
		while(x-1>=0){
			--x;
			if(state[x][y] == '_'){
				set_of_moves.push_back({x, y});
			}

			else if(isUpper(state[x][y])){
				set_of_moves.push_back({x, y});
				break;
			}

			else{
				break;
			}
		}

		x=i, y=j;
		while(y-1>=0){
			--y;
			if(state[x][y] == '_'){
				set_of_moves.push_back({x, y});
			}

			else if(isUpper(state[x][y])){
				set_of_moves.push_back({x, y});
				break;
			}

			else{
				break;
			}
		}

		x=i, y=j;
		while(y+1<8){
			++y;
			if(state[x][y] == '_'){
				set_of_moves.push_back({x, y});
			}

			else if(isUpper(state[x][y])){
				set_of_moves.push_back({x, y});
				break;
			}

			else{
				break;
			}
		}

		return set_of_moves;
	}


	if(state[i][j] == 'Q'){

		/*
			Can traverse through all diagonal, horizontal and vertical lines on the board until encountered by a piece.
			Can be formed by the combination of the rook and the bishop.
		*/

		int x=i, y=j;

		while(x+1<8 && y+1<8){
			++x, ++y;
			if(state[x][y] == '_'){
				set_of_moves.push_back({x, y});
			}

			else if(isLower(state[x][y])){
				set_of_moves.push_back({x, y});
				break;
			}

			else{
				break;
			}
		}

		x=i, y=j;
		while(x-1>=0 && y+1<8){
			--x, ++y;
			if(state[x][y] == '_'){
				set_of_moves.push_back({x, y});
			}

			else if(isLower(state[x][y])){
				set_of_moves.push_back({x, y});
				break;
			}

			else{
				break;
			}
		}

		x=i, y=j;
		while(x+1<8 && y-1>=0){
			++x, --y;
			if(state[x][y] == '_'){
				set_of_moves.push_back({x, y});
			}

			else if(isLower(state[x][y])){
				set_of_moves.push_back({x, y});
				break;
			}

			else{
				break;
			}
		}

		x=i, y=j;
		while(x-1>=0 && y-1>=0){
			--x, --y;
			if(state[x][y] == '_'){
				set_of_moves.push_back({x, y});
			}

			else if(isLower(state[x][y])){
				set_of_moves.push_back({x, y});
				break;
			}

			else{
				break;
			}
		}

		x=i, y=j;
		while(x+1<8){
			++x;
			if(state[x][y] == '_'){
				set_of_moves.push_back({x, y});
			}

			else if(isLower(state[x][y])){
				set_of_moves.push_back({x, y});
				break;
			}

			else{
				break;
			}
		}

		x=i, y=j;
		while(x-1>=0){
			--x;
			if(state[x][y] == '_'){
				set_of_moves.push_back({x, y});
			}

			else if(isLower(state[x][y])){
				set_of_moves.push_back({x, y});
				break;
			}

			else{
				break;
			}
		}

		x=i, y=j;
		while(y-1>=0){
			--y;
			if(state[x][y] == '_'){
				set_of_moves.push_back({x, y});
			}

			else if(isLower(state[x][y])){
				set_of_moves.push_back({x, y});
				break;
			}

			else{
				break;
			}
		}

		x=i, y=j;
		while(y+1<8){
			++y;
			if(state[x][y] == '_'){
				set_of_moves.push_back({x, y});
			}

			else if(isLower(state[x][y])){
				set_of_moves.push_back({x, y});
				break;
			}

			else{
				break;
			}
		}

		return set_of_moves;
	}




	if(state[i][j] == 'q'){

		/*
			Can traverse through all diagonal, horizontal and vertical lines on the board until encountered by a piece.
			Can be formed by the combination of the rook and the bishop.
		*/

		int x=i, y=j;

		while(x+1<8 && y+1<8){
			++x, ++y;
			if(state[x][y] == '_'){
				set_of_moves.push_back({x, y});
			}

			else if(isUpper(state[x][y])){
				set_of_moves.push_back({x, y});
				break;
			}

			else{
				break;
			}
		}

		x=i, y=j;
		while(x-1>=0 && y+1<8){
			--x, ++y;
			if(state[x][y] == '_'){
				set_of_moves.push_back({x, y});
			}

			else if(isUpper(state[x][y])){
				set_of_moves.push_back({x, y});
				break;
			}

			else{
				break;
			}
		}

		x=i, y=j;
		while(x+1<8 && y-1>=0){
			++x, --y;
			if(state[x][y] == '_'){
				set_of_moves.push_back({x, y});
			}

			else if(isUpper(state[x][y])){
				set_of_moves.push_back({x, y});
				break;
			}

			else{
				break;
			}
		}

		x=i, y=j;
		while(x-1>=0 && y-1>=0){
			--x, --y;
			if(state[x][y] == '_'){
				set_of_moves.push_back({x, y});
			}

			else if(isUpper(state[x][y])){
				set_of_moves.push_back({x, y});
				break;
			}

			else{
				break;
			}
		}

		x=i, y=j;
		while(x+1<8){
			++x;
			if(state[x][y] == '_'){
				set_of_moves.push_back({x, y});
			}

			else if(isUpper(state[x][y])){
				set_of_moves.push_back({x, y});
				break;
			}

			else{
				break;
			}
		}

		x=i, y=j;
		while(x-1>=0){
			--x;
			if(state[x][y] == '_'){
				set_of_moves.push_back({x, y});
			}

			else if(isUpper(state[x][y])){
				set_of_moves.push_back({x, y});
				break;
			}

			else{
				break;
			}
		}

		x=i, y=j;
		while(y-1>=0){
			--y;
			if(state[x][y] == '_'){
				set_of_moves.push_back({x, y});
			}

			else if(isUpper(state[x][y])){
				set_of_moves.push_back({x, y});
				break;
			}

			else{
				break;
			}
		}

		x=i, y=j;
		while(y+1<8){
			++y;
			if(state[x][y] == '_'){
				set_of_moves.push_back({x, y});
			}

			else if(isUpper(state[x][y])){
				set_of_moves.push_back({x, y});
				break;
			}

			else{
				break;
			}
		}

		return set_of_moves;
	}
}
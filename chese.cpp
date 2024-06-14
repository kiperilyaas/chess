#include<iostream>

using namespace std;
const short R = 8;
const short C = 8;
string field[R][C];
string field_color[R][C];
string figure_w[16];
string figure_b[16];

void move_user(int line_field_figure, char column_field_figure, int line_field_pos, char column_field_pos);



const string KING_B = "♔";
const string QUEEN_B = "♕";
const string ROOC_B = "♖";
const string BISHOP_B = "♗";
const string KNIGHT_B = "♘";
const string PAWN_B = "♙";

const string KING_W = "♚";
const string QUEEN_W = "♛";
const string ROOC_W = "♜";
const string BISHOP_W = "♝";
const string KNIGHT_W = "♞";
const string PAWN_W = "♟︎";


void fill_field(){
     field[0][0] = ROOC_B;
     field[0][1] = KNIGHT_B;
     field[0][2] = BISHOP_B;
     field[0][3] = QUEEN_B;
     field[0][4] = KING_B;
     field[0][5] = BISHOP_B;
     field[0][6] = KNIGHT_B;
     field[0][7] = ROOC_B;

     field[1][0] = PAWN_B;
     field[1][1] = PAWN_B;
     field[1][2] = PAWN_B;
     field[1][3] = PAWN_B;
     field[1][4] = PAWN_B;
     field[1][5] = PAWN_B;
     field[1][6] = PAWN_B;
     field[1][7] = PAWN_B;

     field_color[0][0] = "Rb";
     field_color[0][1] = "Kb";
     field_color[0][2] = "Bb";
     field_color[0][3] = "Qb";
     field_color[0][4] = "Kib";
     field_color[0][5] = "Bb";
     field_color[0][6] = "Kb";
     field_color[0][7] = "Rb";
     field[1][0] = "Pb";
     field[1][1] = "Pb";
     field[1][2] = "Pb";
     field[1][3] = "Pb";
     field[1][4] = "Pb";
     field[1][5] = "Pb";
     field[1][6] = "Pb";
     field[1][7] = "Pb";

     for(int i = 2; i < 6; i++){
          for(int j = 0; j < 8; j++){
               field[i][j] = ' ';
          }
     }

     for(int i = 2; i < 6; i++){
          for(int j = 0; j < 8; j++){
               field_color[i][j] = 'e';
          }
     }


     for(int i = 0; i < 8; i++){
          field[6][i] = PAWN_W;
     }

     field[7][0] = ROOC_W;
     field[7][1] = KNIGHT_W;
     field[7][2] = BISHOP_W;
     field[7][3] = QUEEN_W;
     field[7][4] = KING_W;
     field[7][5] = BISHOP_W;
     field[7][6] = KNIGHT_W;
     field[7][7] = ROOC_W;

     for(int j = 0 ; j < 8; j++){
          field_color[6][j] = "Pw";
     }
     field_color[7][0] = "Rw";
     field_color[7][1] = "Kw";
     field_color[7][2] = "Bw";
     field_color[7][3] = "Qw";
     field_color[7][4] = "KiW";
     field_color[7][5] = "Bw";
     field_color[7][6] = "Kw";
     field_color[7][7] = "Rw";
}

void show_field(){
     system("clear");
     cout << "  A B C D E F G H" << endl;
     cout << " ┌─┬─┬─┬─┬─┬─┬─┬─┐" << endl;

     for(int i = 0; i < 8; i++){
          cout << 8 - i << "│";
          for(int j = 0; j < 8; j++){
               cout << field[i][j] << "│";
          }
          if(i != 7)
               cout << 8 - i << endl <<" ├─┼─┼─┼─┼─┼─┼─┼─┤" << endl;
          else cout << endl;
     }

     cout << " └─┴─┴─┴─┴─┴─┴─┴─┘" << endl;
     cout << "  A B C D E F G H" << endl;
}

void game_with_PC(){
     bool userWin = false;
     bool pcWin = false;
     int line_field_figure;
     int line_field_pos;
     char column_field_figure;
     char column_field_pos;

     while(!userWin && !pcWin){
          system("clear");
          show_field();

          cout << "\nUser move\n";
          cout << "Enter your figure, line of field: "; cin >> line_field_figure;
          while(line_field_figure < 1 || line_field_figure > 8){
               cout << "This number isn't valid, rewrite number (1-8)";
               cin >> line_field_figure;
          }    

          cout << "Enter columnt of field: "; cin >> column_field_figure;
          while(column_field_figure > 'H' || column_field_figure < 'A'){
               cout << "This letter isn't valid, rewrite letter (A-H)";
               cin >> column_field_figure;
          }
          if(field[line_field_figure][column_field_figure] == " "){
               cout << "this space is empty, rewrite...";
               system("sleep(4)");
               continue;
          }

          cout << "\nEnter position which you wont go";
          cout << "Enter position number: ";cin >> line_field_pos;
          while(line_field_pos < 1 || line_field_pos > 8){
               cout << "This number isn't valid, rewrite number (1-8)";
               cin >> line_field_pos;
          }
          cout << "Enter position letter: "; cin >> column_field_pos;
          while(column_field_pos < 'A' || column_field_pos > 'H'){
               cout << "This number isn't valid, rewrite letter (A-H)";
               cin >> column_field_pos;
          }
          while(field_color[line_field_pos][column_field_pos] == "W"){
               cout << "This space is occupate of your figure, rewrite...";
               system("sleep(4)");
               continue;
          }

          move_user(line_field_figure,column_field_figure, line_field_pos, column_field_pos);

     }
}

void which_figure(int xS, char yS, int xF, char yF){
     string figure = field[xS][yS];
     if(figure == KNIGHT_B){
          
     }
}

void move_user(int line_field_figure, char column_field_figure, int line_field_pos, char column_field_pos){
     which_figure(line_field_figure,column_field_figure,line_field_pos,column_field_pos);
}



int main(){
     

     fill_field();
     //show_field(field);

     int option = 1;
     do {
          cout << "1. Game with PC" << endl;
          cout << "2. Game with your friend" << endl;
          cout << "0. Exit" << endl;
          cout << "Your option?: ";cin >> option;

          switch(option){
               case 0: return 0;
               case 1: game_with_PC();
          }
     }while (option != 0);


     return 0;
}
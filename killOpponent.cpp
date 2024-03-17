#include<iostream>
#include<string>
#include<ctime>
using namespace std;

class Player;

class GameBoard {
private:
   string theBoard[10][10];
   string boardValue;
   int boardSize;
    
public:
    GameBoard(){}

    GameBoard(int boardS){
        boardSize=boardS;
    }

       ~ GameBoard(){
    }


    void makeBoard(string boardV){
       boardValue=boardV;
             for(int i=0;i<boardSize;i++){
      for(int j=0;j<boardSize;j++){
        if(j==0){
            boardValue="$";
        }
        else if(j==(boardSize-1)){
             boardValue="&";
        }
         else{
            boardValue=boardV;
        }
        theBoard[i][j]=boardValue;
      }
    }
    }

    void getBoard(){
         for(int i=0;i<boardSize;i++){
      for(int j=0;j<boardSize;j++){
        cout<<theBoard[i][j]<<" ";
      }
      cout<<endl;
   }
    }
};


class Player{
    private:
     








    public:

    int stepWalk(){
      srand(time(0));
      return rand()%7;
    }

    int step=stepWalk();

    void showStep(){
      cout<<step<<endl;
    }













};









int main(){

     GameBoard g1(10);
     g1.makeBoard("_");
     g1.getBoard();

     Player p1;
     p1.stepWalk();
     cout<<p1.step<<endl;





    return 0;
}
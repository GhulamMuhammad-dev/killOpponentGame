// #include<iostream>
// #include<string>
// #include<ctime>
// #include<cstdlib>
// #include<vector>


// int randomNum(){
//     srand(time(0));
//     int random=(rand()+1)%7;
//     return random;
// }

// int AIrandomNum(){
//     srand(time(0));
//     int random=(rand()+1)%11;
//     return random;
// }






// using namespace std;

// int main(){

// bool gameOver=false;
// int numb;
// const int row=10;
// const int column=10;
// char userPress;
// bool playerTurn=true;
// int whichRow;






// char gameBoard[row][column];

// for(int i=0;i<row;i++){
//     for(int j=0;j<column;j++){
//         if(j==0){
//              gameBoard[i][j]='$';
//         }
//         else if(j==column-1){
//              gameBoard[i][j]='&';
//         }
//         else{
//         gameBoard[i][j]='_';
//         }
//     }
// }









// do{
   

// cout<<"Press p to roll"<<endl;
// cin>>userPress;

// if(playerTurn){
// if(userPress=='p'){
//     int ranNum=randomNum();
//     cout<<"Select row"<<endl;
//     cin>>whichRow;

//     gameBoard[whichRow][ranNum]='$';


// for(int i=0;i<row;i++){
//     for(int j=0;j<column;j++){
//        if(i==whichRow && j==ranNum){
//         gameBoard[whichRow][ranNum]='$';
//        }
//     }
//     cout<<endl;
// }

// for(int i=0;i<row;i++){
//     for(int j=0;j<column;j++){
//        cout<<gameBoard[i][j]<<" ";
//     }
//     cout<<endl;
// }


// playerTurn=false;
// }
// }




// if(!playerTurn){



// for(int i=row-1;i<0;i--){
//     for(int j=column-1;j<0;j--){
//        if(i==randomNum() && j==AIrandomNum()){
//         gameBoard[randomNum()][AIrandomNum()]='&';
//        }
//     }
// }

// for(int i=0;i<row;i++){
//     for(int j=0;j<column;j++){
//        cout<<gameBoard[i][j]<<" ";
//     }
//     cout<<endl;
// }

// playerTurn=true;


// }

//  system("CLS");
// }while(!gameOver);














//     return 0;
// }


#include<iostream>
#include<string>
#include<ctime>

using namespace std;

int randomNum(){
    srand(time(0));
    int random=(rand()+1)%7;
    return random;
}

int main(){


   char track[20];

   for(int i=0;i<20;i++){
    track[i]='-';
   }

   for(int i=0;i<20;i++){
    cout<<track[i]<<" ";
   }










    return 0;
}
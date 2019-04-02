#include <iostream>
#include <string>
#include <cmath>
#include "MinesweeperBoard.h"
#include "MSBoardTextView.h"
#include <ctime>



using namespace std;

int main()
{
    srand( time ( NULL ) ) ;
    MinesweeperBoard gameboard ( 7 , 9 , easy ) ;
    MSBoardTextView view ( gameboard );
   // view.display();



    return 0;
}
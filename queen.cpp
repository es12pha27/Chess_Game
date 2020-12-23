#include "queen.h"
#include "game.h"
extern Game *game;
Queen::Queen(QString team,QGraphicsItem *parent):Piece(team,parent)
{
    name="D";
    //se inicializa poniendo su imagen
    setImage();
}
/*Se encarga de colocar la imagen al objeto mediante Qpixmap*/

void Queen::setImage()
{
    if(side == "WHITE")
        setPixmap(QPixmap(":/img/img/queen_w.png"));
    else
        setPixmap(QPixmap(":/img/img/queen_b.png"));
}

/*Se encarga de como se mueve la pieza*/

void Queen::move()
{

    location.clear();
    int row = this->getCurrentCell()->rowLoc;
    int col = this->getCurrentCell()->colLoc;
    QString team = this->getSide();
    //For up

     for(int i = row-1,j = col; i >= 1 ; i--) {
       if(game->collection[i][j]->getPieceColor() == team ) {
           break;
       }
       else
       {
           location.append(game->collection[i][j]);
           if(CellSetup(location.last()))
               break;
        }
    }

     //For Down

      for(int i = row+1,j = col; i <= 8 ; i++) {
        if(game->collection[i][j]->getPieceColor() == team ) {
            break;
        }
        else
        {
            location.append(game->collection[i][j]);
            if(CellSetup(location.last())){
                break;
            }
        }
     }
      //For Right

       for(int i = row,j = col+1; j <= 8 ; j++)
       {
             if(game->collection[i][j]->getPieceColor() == team ) {
                 break;
             }
             else
             {
                 location.append(game->collection[i][j]);
                 if(CellSetup(location.last()))
                     break;
              }

      }
      //For left

       for(int i = row,j = col-1; j >= 1 ; j--) {
         if(game->collection[i][j]->getPieceColor() == team ) {
             break;
         }
         else
         {
             location.append(game->collection[i][j]);
             if(CellSetup(location.last()))
                break;
         }
        }
       //For upper right

        for(int i = row-1,j = col+1; i >= 1 && j <= 8; i--,j++) {
          if(game->collection[i][j]->getPieceColor() == team ) {
              break;

          }
          else
          {
              location.append(game->collection[i][j]);
              if(CellSetup(location.last())){
                  break;
              }
          }
       }

        //For upper Left

         for(int i = row-1,j = col-1; i >= 1 && j >=1; i--,j--) {
           if(game->collection[i][j]->getPieceColor() == team ) {
               break;

           }
           else
           {
               location.append(game->collection[i][j]);
               if(CellSetup(location.last()) ){
                   break;
               }
           }
        }

          //For downward right

           for(int i = row+1,j = col+1; i <= 8 && j <= 8; i++,j++) {
             if(game->collection[i][j]->getPieceColor() == team ) {
                 break;

             }
             else
             {
                 location.append(game->collection[i][j]);
                 if(CellSetup(location.last())){
                     break;
                 }
             }
          }

           //For downward left

            for(int i = row+1,j = col-1; i <= 8 && j >= 1; i++,j--) {
              if(game->collection[i][j]->getPieceColor() == team ) {
                  break;

              }
              else
              {
                  location.append(game->collection[i][j]);
                  if(CellSetup(location.last())){
                      break;
                  }

              }
           }

}

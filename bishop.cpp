#include "bishop.h"

#include <QDebug>
#include "core.h"
extern Core *core;
Bishop::Bishop(QString team,QGraphicsItem *parent):ChessPiece(team,parent)
{
    name="A";
    //se inicializa poniendo su imagen
    setImage();
}
/*Se encarga de colocar la imagen al objeto mediante Qpixmap*/
void Bishop::setImage()
{
    if(side == "WHITE")
        setPixmap(QPixmap(":/img/img/bishop_w.png"));
    else
        setPixmap(QPixmap(":/img/img/bishop_b.png"));
}
/*Se encarga de como se mueve la pieza*/
void Bishop::move()
{
    location.clear();
    int row = this->getCurrentCell()->rowLoc;
    int col = this->getCurrentCell()->colLoc;
    QString team = this->getSide();
    //Diagonal izq arriba

     for(int i = row-1,j = col-1; i >= 1 && j >=1; i--,j--) {
       if(core->collection[i][j]->getChessPieceColor() == team ) {
           break;

       }
       else
       {
           location.append(core->collection[i][j]);
           if(CellSetup(location.last()) ){
               break;
           }
       }
    }
     //Diagonal derecha arriba
      for(int i = row-1,j = col+1; i >= 1 && j <= 8; i--,j++) {
        if(core->collection[i][j]->getChessPieceColor() == team ) {
            break;

        }
        else
        {
            location.append(core->collection[i][j]);
            if(CellSetup(location.last())){
                break;
            }
        }
     }
      //Diagonal derecha abajo
       for(int i = row+1,j = col+1; i <= 8 && j <= 8; i++,j++) {
         if(core->collection[i][j]->getChessPieceColor() == team ) {
             break;
         }
         else
         {location.append(core->collection[i][j]);
             if(CellSetup(location.last())){
                 break;
             }
         }
      }
       //Diagonal izq abajo

        for(int i = row+1,j = col-1; i <= 8 && j >= 1; i++,j--) {
          if(core->collection[i][j]->getChessPieceColor() == team ) {
              break;
          }
          else
          {
              location.append(core->collection[i][j]);
              if(CellSetup(location.last())){
                  break;
              }

          }
       }


}

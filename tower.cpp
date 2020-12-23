#include "tower.h"
#include "core.h"
extern Core *core;
Tower::Tower(QString team,QGraphicsItem *parent):ChessPiece(team,parent)
{
    name="T";
    //se inicializa poniendo su imagen
    setImage();
}

/*Se encarga de colocar la imagen al objeto mediante Qpixmap*/

void Tower::setImage()
{
    if(side == "WHITE")
        setPixmap(QPixmap(":/img/img/tower_w.png"));
    else
        setPixmap(QPixmap(":/img/img/tower_b.png"));
}
/*Se encarga de como se mueve la pieza*/

void Tower::move()
{
    location.clear();
    int row = this->getCurrentCell()->rowLoc;
    int col = this->getCurrentCell()->colLoc;
    QString team = this->getSide();
    //AArriba

     for(int i = row-1,j = col; i >= 1 ; i--) {
       if(core->collection[i][j]->getChessPieceColor() == team ) {
           break;
       }
       else
       {
           location.append(core->collection[i][j]);
           if(CellSetup(location.last()))
               break;
        }
    }

     //Abajo

      for(int i = row+1,j = col; i <= 8 ; i++) {
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

      //Izq

       for(int i = row,j = col-1; j >= 1 ; j--) {
         if(core->collection[i][j]->getChessPieceColor() == team ) {
             break;
         }
         else
         {
             location.append(core->collection[i][j]);
             if(CellSetup(location.last()))
                break;
         }
        }
       //Der

        for(int i = row,j = col+1; j <= 8 ; j++)
        {
              if(core->collection[i][j]->getChessPieceColor() == team ) {
                  break;
              }
              else
              {
                  location.append(core->collection[i][j]);
                  if(CellSetup(location.last()))
                      break;
               }

       }
}



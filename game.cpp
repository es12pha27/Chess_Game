#include "game.h"
#include "button.h"
#include <QPixmap>
#include "king.h"
#include <QDebug>
#include <QColor>
#include <iostream>
#include <QMessageBox>


Game::Game(QWidget *parent ):QGraphicsView(parent)
{

    //construyendo la escena
    chessScene = new QGraphicsScene();
    chessSceneWhite = new QGraphicsScene();
    //layout

    chessScene->setSceneRect(0,0,1566,900);
    QMessageBox msbx;
    //costruyendo la vista
    setMinimumSize(1366,700);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setScene(chessScene);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(QColor(234,96,45));
    setBackgroundBrush(brush);
    pieceToMove = NULL;



    Turn= new  QGraphicsRectItem();
    Turn->setRect(0,0,300,40);
    Turn->setPos(width()/2,0);
    QBrush brush2;
    brush2.setStyle(Qt::SolidPattern);
    brush2.setColor(QColor(255,255,255));
    Turn->setBrush(brush2);


    // muestra el check (jaque) como aviso
    QFont font( "Newyork", 12 );
    font.setStyleHint( QFont::SansSerif );
    font.setWeight( QFont::Bold );

    check = new QGraphicsTextItem();
    check->setPos(chessScene->width(),chessScene->height()/2);
    check->setZValue(4);
    check->setDefaultTextColor(Qt::white);
    check->setFont(QFont(font));
    check->setPlainText("¡POSIBLE JAQUE , HAY  UN \n POSIBLE \n JAQUE MATE!");
    check->setVisible(false);
    setTurn("WHITE");



    textTurn= new QGraphicsTextItem();
    textTurn->setPos((width()/2)-100,0);
    textTurn->setZValue(4);
    textTurn->setDefaultTextColor(Qt::white);
    textTurn->setFont(font);
    textTurn->setPlainText("TURNO");
    textTurn->setVisible(true);
    aggregateToScene( textTurn);




     newItem=new QTableWidgetItem();
     // para que los elementos no sean editables
     newItem->setFlags(newItem->flags() & (~Qt::ItemIsEditable));
     newItem->setTextColor(Qt::gray); // color de los items
     tableWidget = new QTableWidget(this);
     tableWidget->setRowCount(50);
     tableWidget->setColumnCount(2);

     hlabels << "Blancas" << "Negras" ;
     tableWidget->setHorizontalHeaderLabels(hlabels);
     tableWidget->move(width()+82,height()/2);


     // Número con digitos tipo LCD
          num = new QLCDNumber();
         num->setDigitCount(8);

          // Formato tiempo
          time = new QTime;
          time->setHMS(0,0,0,0);

          // Creamos el temporizador
          timer = new QTimer(this);

          // Realizamos la conexión para que el método(Slot) showTime sea llamado cada segundo
          connect(timer, SIGNAL(timeout()), this, SLOT(showTime()));

          // Iniciamos los segundos con valor 0
          seconds=0;

          // relacionamos los botones con sus respectivac acciones (Slots)
          connect(startButton,SIGNAL(clicked()),this,SLOT(startTime()));
          connect(stopButton,SIGNAL(clicked()),this,SLOT(stopTime()));
          connect(resetButton,SIGNAL(clicked()),this,SLOT(resetTime()));
          connect(finishButton,SIGNAL(clicked()),this,SLOT(finish()));

          // convertimos el formato tiempo a cadena(horas,min,sec) y le damos estilos (color, fondo)
          QString text = time->toString("hh:mm:ss");
          num->display(text);
          num->setStyleSheet("* { background-color:rgb(128,64,0);color:rgb(255,255,255);}}");
          num->setSegmentStyle(QLCDNumber::Filled);

          num->setParent(this);
          num->move(width()-400,0);
          setWindowTitle(tr("Chess"));



}

//muestra e inicializa el board
void Game::showBoard()
{
    chess = new Board();
    chess->initializeBoard(width()/2-280,50);


}

//dibuja el cuadro que contendra a las piezas blancas muertas
void Game::displayDeadWhite()
{
    int SHIFT = 50;
    int j = 0;
    int k = 0;
    for(size_t i = 0,n = whiteDead.size(); i<n; i++) {
            if(j == 4){
                k++;
                j = 0;
            }
            whiteDead[i]->setPos(40+SHIFT*j++,65+SHIFT*2*k);
    }

}

//dibuja el cuadro que contendra a las piezas negras muertas
void Game::displayDeadBlack()
{
    int SHIFT = 50;
    int j = 0;
    int k = 0;
    for(size_t i = 0,n = blackDead.size(); i<n; i++) {
        if(j == 4){
            k++;
            j = 0;
        }
        blackDead[i]->setPos(40+SHIFT*j++,500+SHIFT*2*k);

    }
}

//verifica si se ha acabado el juego
void Game::placeInDeadPlace(Piece *piece)
{
    if(piece->getSide() == "WHITE") {
        whiteDead.append(piece);
        King *g = dynamic_cast <King *>(piece);
        if(g){

            check->setPlainText("ganador Negro");
            QMessageBox Msgbox;
            Msgbox.setWindowTitle("¡Equipo ganador!");
            Msgbox.setText("¡Equipo Negro!");
            Msgbox.exec();
            gameOver();
        }
        displayDeadWhite();
    }
    else{
        blackDead.append(piece);
        King *g = dynamic_cast <King *>(piece);
        if(g){
            check->setPlainText("ganador Blanco");
            QMessageBox Msgbox;
            Msgbox.setWindowTitle("¡Equipo ganador!");
            Msgbox.setText("¡Equipo Blanco!");
            Msgbox.exec();

            gameOver();
        }
        displayDeadBlack();
    }
    piecesIngame.removeAll(piece);
}

//agrega un item a la escena
void Game::aggregateToScene(QGraphicsItem *item)
{
    chessScene->addItem(item);
}

//elimina un dterminado item de la escena
void Game::deleteToScene(QGraphicsItem *item)
{
    chessScene->removeItem(item);

}

//devuelve el turno actual
QString Game::getTurn()
{
    return turn;
}

//cambiamos el turno
void Game::setTurn(QString value)
{
    turn = value;
}

//para cambiar de turno
void Game::changeTurn()
{

    resetTime();
    if(getTurn() =="WHITE"){
        setTurn("BLACK");
        QBrush brush2;
        brush2.setStyle(Qt::SolidPattern);
        brush2.setColor(QColor(0,0,0));
        Turn->setBrush(brush2);
    }
    else{
        setTurn("WHITE");
        QBrush brush2;
        brush2.setStyle(Qt::SolidPattern);
        brush2.setColor(QColor(255,255,255));
        Turn->setBrush(brush2);
    }
    //frameTurn->setPlainText("Turn : " + getTurn());
}

//para empezar el juego, agregamos lo necesario
void Game::start()
{
    for(size_t i =0, n = listG.size(); i < n; i++)
            deleteToScene(listG[i]);

    //aggregateToScene(frameTurn);

    QFont font( "Newyork", 12 );
    font.setStyleHint( QFont::SansSerif );
    font.setWeight( QFont::Bold );

    aggregateToScene(Turn);
    //lugar para las piezas blancas muertas
    QGraphicsTextItem* whitePiece = new QGraphicsTextItem();

    whitePiece->setPos(35,10);
    whitePiece->setZValue(1);
    whitePiece->setDefaultTextColor(Qt::white);
    whitePiece->setPlainText("PIEZAS BLANCAS CAPTURADAS");
     whitePiece->setFont(font);
    aggregateToScene(whitePiece);

    //lugar para las piezas blancas muertas
    QGraphicsTextItem *blackPiece = new QGraphicsTextItem();
    blackPiece->setPos(35,chessScene->height()/2);
    blackPiece->setZValue(1);
    blackPiece->setDefaultTextColor(Qt::white);
    blackPiece->setFont(font);
    blackPiece->setPlainText("PIEZAS NEGRAS CAPTURADAS");
    aggregateToScene(blackPiece);
    aggregateToScene(check);
    chess->addPieces();

}

//dibujamos el frame que contendra los muertos
void Game::displayDeadsFrame(int x, int y)
{
    deadHolder = new QGraphicsRectItem(x,y,30,90);
    QBrush brush;
    brush.setColor(QColor(234,215,15));
    brush.setStyle(Qt::SolidPattern);
    deadHolder->setBrush(brush);
    aggregateToScene(deadHolder);
}

//para dibujar el menu
void Game::displayMainMenu()
{
    //boton para jugar
    Button * jugar = new Button("Comenzar");
    uint16_t jXPos = 70;
    uint16_t jYPos = 350;
    jugar->setPos(jXPos,jYPos);
    connect(jugar,SIGNAL(clicked()) , this , SLOT(start()));
    aggregateToScene(jugar);
    listG.append(jugar);
    /*Button * timeR = new Button("Time");
    jXPos = 70;
     jYPos = 550;
    timeR ->setPos(jXPos,jYPos);
    connect(timeR,SIGNAL(clicked()),this,SLOT(startTime()));
    aggregateToScene(timeR);
    listG.append(timeR);*/
     showBoard();

}

//se ejecuta cuando alguno gane, reseteando el juego
void Game::gameOver(){
    check->setVisible(false);
    setTurn("WHITE");
    piecesIngame.clear();
    whiteDead.clear();
    blackDead.clear();
    chess->reset();
    tableWidget->clearContents();
    rowCountb=0;
    colCountb=1;
    rowCountw=0;
    colCountw=0;

}

//eliminamos absolutamente todo lo que este en la escena
void Game::removeAll(){
    QList<QGraphicsItem*> itemsList = chessScene->items();
    for(size_t i = 0, n = itemsList.size();i<n;i++) {
        if(itemsList[i]!=check)
          deleteToScene(itemsList[i]);
    }
}
void Game::startTime()
{
    // habilitamos y deshabilitamos los botones según la lógica de inicio
    /*startButton->setDisabled(1);
    stopButton->setEnabled(1);
    resetButton->setEnabled(1);
    finishButton->setEnabled(1);*/

    // iniciamos el cronómetro en milisegundos y llenamos la tabla
    start();
    timer->start(1000);
}
void Game::stopTime()
{
     // habilitamos y deshabilitamos los botones según la lógica de pausa
     /*stopButton->setDisabled(1);
     startButton->setEnabled(1);
     resetButton->setEnabled(1);
     finishButton->setDisabled(1);*/

     // detenemos el cronómetro
     timer->stop();
}

// Para reiniciar el cronómetro
void Game::resetTime()
{
    // ponemos el tiempo en blanco y lo convertimos a cadena para mostrarlo
    time->setHMS(0,0,0);
    QString text = time->toString("hh:mm:ss");
    num->display(text);

    // volvemos  a poner los segundos a 0 y habilitamos y deshabilitamos los botones según la lógica de reinicio
    seconds=0;
    /*stopButton->setDisabled(1);
    startButton->setEnabled(1);*/

    // detenemos el tiempo


    // limpiamos el texto que se generó en las etiquetas Right-Wrong

}

// Para mostrar el tiempo con el formato correcto
void Game::showTime()
{
    // incrementamos los segundos de 1 en 1 y lo agregamos el tiempo
    QTime newtime;
    seconds = seconds + 1;
    newtime = time->addSecs(seconds);

    // convertimos el tiempo a cadena para mostrar
    QString text = newtime.toString("hh:mm:ss");
    num->display(text);
}

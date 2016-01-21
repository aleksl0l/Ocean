#ifndef DRAWING_SCENE_H
#define DRAWING_SCENE_H

#include <QWidget>
#include <QPainter>
#include <QTimer>
#include <QTime>
#include <QDebug>
#include <QVector>

#include "predators.h"
#include "victims.h"
#include "fish.h"

struct Point
{
    int x, y;
    Point(int _x=0, int _y=0):x(_x), y(_y){}
};

struct AREA{
    unsigned char who;
    AREA():who(0){}
};

class Drawing_Scene : public QWidget
{
    Q_OBJECT
public:
    explicit Drawing_Scene(QWidget *parent = 0);
    ~Drawing_Scene();

protected:
    void paintEvent(QPaintEvent *);
signals:
    void fieldNotChanged(bool ok);
    void Stat(QString, QString);
private slots:
    void DrawGrid(QPainter &p);
    void DrawScene(QPainter &p);
    void Generation(QPainter &p);
    void InitField(QPainter &p);
    Point RandomCellAr1(Point p, int who);
    void SetInterval(int msec);
public slots:
    void ChangeFieldSize(const int &size);
    void startGame();
    void stopGame();
    void clear();


private:
    int SizeField;
    int **Field;
    QTimer *timer;
    QVector<Predators> predators;
    //Predators *predators;
    QVector<Victims> victims;
    //Victims *victims;
    AREA **area; //0 - не занято, 1 - занято хищником, 2 - занято жертвой
};

#endif // DRAWING_SCENE_H

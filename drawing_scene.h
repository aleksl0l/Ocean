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

class Drawing_Scene : public QWidget
{
    Q_OBJECT
public:
    explicit Drawing_Scene(QWidget *parent = 0);
    ~Drawing_Scene();

protected:
    void paintEvent(QPaintEvent *);

private slots:
    void DrawGrid(QPainter &p);
    void DrawScene(QPainter &p);
    void Generation(QPainter &p);
    void InitField(QPainter &p);
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
    unsigned char **area; //0 - не занято, 1 - занято хищником, 2 - занято жертвой
};

#endif // DRAWING_SCENE_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include<QMainWindow>
#include<QMouseEvent>
#include<QKeyEvent>
#include<QPainter>
#include<QPixmap>
#include<QLabel>
#include<QSound>
#include<QPropertyAnimation>
//#include<QtWidgets>

class MainWindow:public QMainWindow{
	Q_OBJECT
	public:
		MainWindow(QWidget *parent = 0);
	protected:
		void mouseMoveEvent(QMouseEvent *event);
		void mousePressEvent(QMouseEvent *event);
		void keyPressEvent(QKeyEvent *event);
		void paintEvent(QPaintEvent *event);
		void timerEvent(QTimerEvent *event);
	private:
		int x;
		int y;
		int time;
		int timerID;
		QPixmap move_pic;
		QLabel *move_1;
		QImage img;
		QString key;
		QPropertyAnimation *animation;
};
#endif


//printf("hello world!");
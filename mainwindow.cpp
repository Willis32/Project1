#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent){
	setFixedSize(780, 780);
	setMouseTracking(true);
	time = 10;
	timerID = startTimer(1000);// 1 sec timer
	move_1 = new QLabel (this);
	move_pic.load("./dataset/circlel.jpg");
	move_pic = move_pic.scaled (move_1->size(), Qt::KeepAspectRatio);
	move_1->setPixmap (move_pic);
	img.load("./dataset/circle2.jpg");
}

void MainWindow::mouseMoveEvent (QMouseEvent *event) {
	x = event->x();
	y = event->y();
	update();//call paintEvent
}

void MainWindow::mousePressEvent (QMouseEvent *event) {
	if(event -> button() == Qt::LeftButton) {
		key = "mouse left button";
		QSound::play("./dataset/pika.wav");
		update();//call
	}
}

void MainWindow::keyPressEvent (QKeyEvent *event) {
	if (event->key() == Qt::Key_Left){ 
		key = "left arrow key";
		update();//call paintEvent
	}
	else if(event->key()== Qt::Key_Right){
		key = "right arrow key";
		update();//call paintEvent
	}
	else if(event->key()== Qt::Key_Up){
		key = "up arrow key";
		update();//call paintEvent
	}
	else if(event->key()== Qt::Key_Down){
		key = "down arrow key";
		update();//call paintEvent
	}
}

void MainWindow::paintEvent(QPaintEvent *event) {
	QPainter painter(this);
	QFont font;
	QPen pen;
	painter.setRenderHint (QPainter::Antialiasing, true);
	painter.drawImage(10, 10, img); //show inage "img"
	if(time == 8) {
		animation = new QPropertyAnimation(move_1, "pos");
		animation->setDuration(500);
		animation->setStartValue(QPoint (10, 50));
		animation->setEndValue(QPoint (500, 50));
		animation->start();
	}
	font.setPointSize (20);
	painter.setFont(font);
	pen.setColor(Qt::black);
	painter.setPen(pen);
	painter.drawText(10,100, QString("X: %1 Y: %2").arg(x).arg(y));
	painter.drawText(280,100, QString("time: %1").arg(time));
	painter.drawText(350,100, QString("key: %1").arg(key));
}

void MainWindow::timerEvent (QTimerEvent *event) {
	if(event->timerId()== timerID && timerID != 0) {
		time = (time == 0)? 10 : time - 1;
		update();
	}
}

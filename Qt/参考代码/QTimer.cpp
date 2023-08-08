QTimer::singleShot(0, [this]() {
	QMessageBox::information(this, "", "Hello");
	});

QTimer::singleShot(500, Qt::TimerType::PreciseTimer, this, SLOT(fn()));

QTimer* timer = new QTimer;
connect(timer, SIGNAL(timeout()), this, SLOT(fn()));
timer->start(1000);
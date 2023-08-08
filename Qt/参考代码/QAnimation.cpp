QPushButton* button = new QPushButton("走起", this);
QPropertyAnimation* anim = new QPropertyAnimation(button, "geometry", this);
anim->setDuration(1000);
anim->setStartValue(QRect(0, 0, 100, 50));
anim->setEndValue(QRect(100, 100, 100, 50));
connect(anim, &QPropertyAnimation::finished, [anim]() {
	auto start = anim->startValue();
	auto end = anim->endValue();
	anim->setStartValue(end);
	anim->setEndValue(start);
	anim->start();
	});
anim->start();


//--------------------------------


QPushButton* button = new QPushButton("走起", this);
QStateMachine* machine = new QStateMachine(this);
QPropertyAnimation* anim = new QPropertyAnimation(button, "geometry", this);
anim->setDuration(1000);

QState* state1 = new QState(machine);
QState* state2 = new QState(machine);

state1->assignProperty(button, "geometry", QRect(0, 0, 100, 50));
state2->assignProperty(button, "geometry", QRect(300, 300, 100, 50));

QSignalTransition* transition1 = state1->addTransition(button, SIGNAL(clicked()), state2);
transition1->addAnimation(anim);

auto transition2 = state2->addTransition(button, SIGNAL(clicked()), state1);
transition2->addAnimation(anim);

machine->setInitialState(state1);
machine->start();